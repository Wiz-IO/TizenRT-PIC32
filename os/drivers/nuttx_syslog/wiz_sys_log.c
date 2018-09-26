/****************************************************************************
 * drivers/syslog/note_driver.c
 *
 *   Copyright (C) 2016 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <sys/types.h>
#include <sched.h>
#include <assert.h>
#include <errno.h>

//#include <tinyara/sched_note.h>
#include <fs/fs.h>

#if defined(CONFIG_SCHED_INSTRUMENTATION_BUFFER) && \
    defined(CONFIG_DRIVER_NOTE)

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

static ssize_t note_read(FAR struct file *filep, FAR char *buffer,
                 size_t buflen);

/****************************************************************************
 * Private Data
 ****************************************************************************/

static const struct file_operations note_fops =
{
  0,             /* open */
  0,             /* close */
  note_read,     /* read */
  0,             /* write */
  0,             /* seek */
  0              /* ioctl */
#ifndef CONFIG_DISABLE_POLL
  , 0            /* poll */
#endif
#ifndef CONFIG_DISABLE_PSEUDOFS_OPERATIONS
  , 0            /* unlink */
#endif
};

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: note_read
 ****************************************************************************/

static ssize_t note_read(FAR struct file *filep, FAR char *buffer,
                         size_t buflen)
{
  ssize_t notelen;
  ssize_t retlen ;

  DEBUGASSERT(filep != 0 && buffer != NULL && buflen > 0);

  /* Then loop, adding as many notes as possible to the user buffer. */

  retlen = 0;
  sched_lock();
  do
    {
     /* Get the next note (removing it from the buffer) */

     notelen = sched_note_get((FAR uint8_t *)buffer, buflen);
     if (notelen < 0)
       {
         /* We were unable to read the next note, probably because it will
          * not fit into the user buffer.
          */

         if (retlen == 0)
           {
             /* If nothing was read then report the error.  Otherwise,
              * just silently drop the note.
              */

             retlen = notelen;
           }

         break;
       }

      /* Update pointers from the note that was transferred */

      retlen += notelen;
      buffer += notelen;
      buflen -= notelen;

      /* Will the next note fit?  There is a race here and even if the next
       * note will fit, it may fail still when sched_note_get() is called.
       *
       * It won't fit (or an error occurred).  Return what we have without
       * trying to get the next note (which would cause it to be deleted).
       */

      notelen = sched_note_size();
    }
  while (notelen > 0 && notelen <= buflen);

  sched_unlock();
  return retlen;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: note_register
 *
 * Description:
 *   Register a serial driver at /dev/note that can be used by an
 *   application to read data from the circular not buffer.
 *
 * Input Parameters:
 *   None.
 *
 * Returned Value:
 *   Zero is returned if the circular buffer is empty.  Otherwise, a negated
 *   errno value is returned.
 *
 ****************************************************************************/

int note_register(void)
{
  return register_driver("/dev/note", &note_fops, 0666, NULL);
}

#endif /* CONFIG_SCHED_INSTRUMENTATION_BUFFER && CONFIG_DRIVER_NOTE *//****************************************************************************
 * drivers/syslog/ramlog.c
 *
 *   Copyright (C) 2012, 2016-2017 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <sys/types.h>
#include <sys/ioctl.h>

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <poll.h>
#include <errno.h>
#include <assert.h>
#include <debug.h>

#include <tinyara/arch.h>
#include <tinyara/kmalloc.h>
#include <tinyara/semaphore.h>
#include <tinyara/fs/fs.h>
#include <tinyara/syslog/ramlog.h>

#include <tinyara/irq.h>

#ifdef CONFIG_RAMLOG

/****************************************************************************
 * Private Types
 ****************************************************************************/

struct ramlog_dev_s
{
#ifndef CONFIG_RAMLOG_NONBLOCKING
  volatile uint8_t  rl_nwaiters;     /* Number of threads waiting for data */
#endif
  volatile uint16_t rl_head;         /* The head index (where data is added) */
  volatile uint16_t rl_tail;         /* The tail index (where data is removed) */
  sem_t             rl_exclsem;      /* Enforces mutually exclusive access */
#ifndef CONFIG_RAMLOG_NONBLOCKING
  sem_t             rl_waitsem;      /* Used to wait for data */
#endif
  size_t            rl_bufsize;      /* Size of the RAM buffer */
  FAR char         *rl_buffer;       /* Circular RAM buffer */

  /* The following is a list if poll structures of threads waiting for
   * driver events. The 'struct pollfd' reference for each open is also
   * retained in the f_priv field of the 'struct file'.
   */

#ifndef CONFIG_DISABLE_POLL
  FAR struct pollfd *rl_fds[CONFIG_RAMLOG_NPOLLWAITERS];
#endif
};

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/* Syslog channel methods */

#ifdef CONFIG_RAMLOG_SYSLOG
static int ramlog_flush(void);
#endif

/* Helper functions */

#ifndef CONFIG_DISABLE_POLL
static void ramlog_pollnotify(FAR struct ramlog_dev_s *priv,
                              pollevent_t eventset);
#endif
static ssize_t ramlog_addchar(FAR struct ramlog_dev_s *priv, char ch);

/* Character driver methods */

static ssize_t ramlog_read(FAR struct file *filep, FAR char *buffer,
                           size_t buflen);
static ssize_t ramlog_write(FAR struct file *filep, FAR const char *buffer,
                            size_t buflen);
#ifndef CONFIG_DISABLE_POLL
static int     ramlog_poll(FAR struct file *filep, FAR struct pollfd *fds,
                           bool setup);
#endif

/****************************************************************************
 * Private Data
 ****************************************************************************/

#ifdef CONFIG_RAMLOG_SYSLOG
static const struct syslog_channel_s g_ramlog_syslog_channel =
{
#ifdef CONFIG_SYSLOG_WRITE
  syslog_default_write,
#endif
  ramlog_putc,
  ramlog_putc,
  ramlog_flush
};
#endif

/****************************************************************************
 * Private Data
 ****************************************************************************/

static const struct file_operations g_ramlogfops =
{
  NULL,         /* open */
  NULL,         /* close */
  ramlog_read,  /* read */
  ramlog_write, /* write */
  NULL,         /* seek */
  NULL          /* ioctl */
#ifndef CONFIG_DISABLE_POLL
  , ramlog_poll /* poll */
#endif
#ifndef CONFIG_DISABLE_PSEUDOFS_OPERATIONS
  , NULL        /* unlink */
#endif
};

/* This is the pre-allocated buffer used for the console RAM log and/or
 * for the syslogging function.
 */

#if defined(CONFIG_RAMLOG_CONSOLE) || defined(CONFIG_RAMLOG_SYSLOG)
static char g_sysbuffer[CONFIG_RAMLOG_BUFSIZE];

/* This is the device structure for the console or syslogging function.  It
 * must be statically initialized because the RAMLOG ramlog_putc function
 * could be called before the driver initialization logic executes.
 */

static struct ramlog_dev_s g_sysdev =
{
#ifndef CONFIG_RAMLOG_NONBLOCKING
  0,                             /* rl_nwaiters */
#endif
  0,                             /* rl_head */
  0,                             /* rl_tail */
  SEM_INITIALIZER(1),            /* rl_exclsem */
#ifndef CONFIG_RAMLOG_NONBLOCKING
  SEM_INITIALIZER(0),            /* rl_waitsem */
#endif
  CONFIG_RAMLOG_BUFSIZE,         /* rl_bufsize */
  g_sysbuffer                    /* rl_buffer */
};
#endif

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: ramlog_flush
 ****************************************************************************/

#ifdef CONFIG_RAMLOG_SYSLOG
static int ramlog_flush(void)
{
  return OK;
}
#endif

/****************************************************************************
 * Name: ramlog_pollnotify
 ****************************************************************************/

#ifndef CONFIG_DISABLE_POLL
static void ramlog_pollnotify(FAR struct ramlog_dev_s *priv,
                              pollevent_t eventset)
{
  FAR struct pollfd *fds;
  irqstate_t flags;
  int i;

  /* This function may be called from an interrupt handler */

  for (i = 0; i < CONFIG_RAMLOG_NPOLLWAITERS; i++)
    {
      flags = enter_critical_section();
      fds = priv->rl_fds[i];
      if (fds)
        {
          fds->revents |= (fds->events & eventset);
          if (fds->revents != 0)
            {
              nxsem_post(fds->sem);
            }
        }
      leave_critical_section(flags);
    }
}
#else
#  define ramlog_pollnotify(priv,event)
#endif

/****************************************************************************
 * Name: ramlog_addchar
 ****************************************************************************/

static int ramlog_addchar(FAR struct ramlog_dev_s *priv, char ch)
{
  irqstate_t flags;
  size_t nexthead;

  /* Disable interrupts (in case we are NOT called from interrupt handler) */

  flags = enter_critical_section();

  /* Calculate the write index AFTER the next byte is written */

  nexthead = priv->rl_head + 1;
  if (nexthead >= priv->rl_bufsize)
    {
      nexthead = 0;
    }

  /* Would the next write overflow the circular buffer? */

  if (nexthead == priv->rl_tail)
    {
      /* Yes... Return an indication that nothing was saved in the buffer. */

      leave_critical_section(flags);
      return -EBUSY;
    }

  /* No... copy the byte and re-enable interrupts */

  priv->rl_buffer[priv->rl_head] = ch;
  priv->rl_head = nexthead;
  leave_critical_section(flags);
  return OK;
}

/****************************************************************************
 * Name: ramlog_read
 ****************************************************************************/

static ssize_t ramlog_read(FAR struct file *filep, FAR char *buffer, size_t len)
{
  FAR struct inode *inode = filep->f_inode;
  FAR struct ramlog_dev_s *priv;
  ssize_t nread;
  char ch;
  int ret;

  /* Some sanity checking */

  DEBUGASSERT(inode && inode->i_private);
  priv = (FAR struct ramlog_dev_s *)inode->i_private;

  /* If the circular buffer is empty, then wait for something to be written
   * to it.  This function may NOT be called from an interrupt handler.
   */

  DEBUGASSERT(!up_interrupt_context());

  /* Get exclusive access to the rl_tail index */

  ret = nxsem_wait(&priv->rl_exclsem);
  if (ret < 0)
    {
      return ret;
    }

  /* Loop until something is read */

  for (nread = 0; (size_t)nread < len; )
    {
      /* Get the next byte from the buffer */

      if (priv->rl_head == priv->rl_tail)
        {
          /* The circular buffer is empty. */

#ifdef CONFIG_RAMLOG_NONBLOCKING
          /* Return what we have (with zero mean the end-of-file) */

          break;
#else
          /* Did we read anything? */

          if (nread > 0)
            {
              /* Yes.. re-enable interrupts and the break out to return what
               * we have.
               */

              break;
            }

          /* If the driver was opened with O_NONBLOCK option, then don't wait.
           * Re-enable interrupts and return EGAIN.
           */

          if (filep->f_oflags & O_NONBLOCK)
            {
              nread = -EAGAIN;
              break;
            }

          /* Otherwise, wait for something to be written to the circular
           * buffer. Increment the number of waiters so that the ramlog_write()
           * will not that it needs to post the semaphore to wake us up.
           */

          sched_lock();
          priv->rl_nwaiters++;
          nxsem_post(&priv->rl_exclsem);

          /* We may now be pre-empted!  But that should be okay because we
           * have already incremented nwaiters.  Pre-emptions is disabled
           * but will be re-enabled while we are waiting.
           */

          ret = nxsem_wait(&priv->rl_waitsem);

          /* Interrupts will be disabled when we return.  So the decrementing
           * rl_nwaiters here is safe.
           */

          priv->rl_nwaiters--;
          sched_unlock();

          /* Did we successfully get the rl_waitsem? */

          if (ret >= 0)
            {
              /* Yes... then retake the mutual exclusion semaphore */

              ret = nxsem_wait(&priv->rl_exclsem);
            }

          /* Was the semaphore wait successful? Did we successful re-take the
           * mutual exclusion semaphore?
           */

          if (ret < 0)
            {
              /* No.. One of the two nxsem_wait's failed. */
              /* Were we awakened by a signal?  Did we read anything before
               * we received the signal?
               */

              if (ret != -EINTR || nread >= 0)
                {
                  /* Yes.. return the error. */

                  nread = ret;
                }

              /* Break out to return what we have.  Note, we can't exactly
               * "break" out because whichever error occurred, we do not hold
               * the exclusion semaphore.
               */

              goto errout_without_sem;
            }
#endif /* CONFIG_RAMLOG_NONBLOCKING */
        }
      else
        {
          /* The circular buffer is not empty, get the next byte from the
           * tail index.
           */

          ch = priv->rl_buffer[priv->rl_tail];

          /* Increment the tail index and re-enable interrupts */

          if (++priv->rl_tail >= priv->rl_bufsize)
            {
              priv->rl_tail = 0;
            }

          /* Add the character to the user buffer */

          buffer[nread] = ch;
          nread++;
        }
    }

  /* Relinquish the mutual exclusion semaphore */

  nxsem_post(&priv->rl_exclsem);

  /* Notify all poll/select waiters that they can write to the FIFO */

#ifndef CONFIG_RAMLOG_NONBLOCKING
errout_without_sem:
#endif

#ifndef CONFIG_DISABLE_POLL
  if (nread > 0)
    {
      ramlog_pollnotify(priv, POLLOUT);
    }
#endif

  /* Return the number of characters actually read */

  return nread;
}

/****************************************************************************
 * Name: ramlog_write
 ****************************************************************************/

static ssize_t ramlog_write(FAR struct file *filep, FAR const char *buffer, size_t len)
{
  FAR struct inode *inode = filep->f_inode;
  FAR struct ramlog_dev_s *priv;
  ssize_t nwritten;
  char ch;
  int ret;

  /* Some sanity checking */

  DEBUGASSERT(inode && inode->i_private);
  priv = (FAR struct ramlog_dev_s *)inode->i_private;

  /* Loop until all of the bytes have been written.  This function may be
   * called from an interrupt handler!  Semaphores cannot be used!
   *
   * The write logic only needs to modify the rl_head index.  Therefore,
   * there is a difference in the way that rl_head and rl_tail are protected:
   * rl_tail is protected with a semaphore; rl_tail is protected by disabling
   * interrupts.
   */

  for (nwritten = 0; (size_t)nwritten < len; nwritten++)
    {
      /* Get the next character to output */

      ch = buffer[nwritten];

      /* Ignore carriage returns */

#ifdef CONFIG_RAMLOG_CRLF
      if (ch == '\r')
        {
          continue;
        }

      /* Pre-pend a carriage before a linefeed */

      if (ch == '\n')
        {
          ret = ramlog_addchar(priv, '\r');
          if (ret < 0)
            {
              /* The buffer is full and nothing was saved. Break out of the
               * loop to return the number of bytes written up to this point.
               * The data to be written is dropped on the floor.
               */

              break;
            }
        }
#endif

      /* Then output the character */

      ret = ramlog_addchar(priv, ch);
      if (ret < 0)
        {
          /* The buffer is full and nothing was saved. Break out of the
           * loop to return the number of bytes written up to this point.
           * The data to be written is dropped on the floor.
           */

          break;
        }
    }

  /* Was anything written? */

#if !defined(CONFIG_RAMLOG_NONBLOCKING) || !defined(CONFIG_DISABLE_POLL)
  if (nwritten > 0)
    {
      irqstate_t flags;
#ifndef CONFIG_RAMLOG_NONBLOCKING
      int i;
#endif

      /* Are there threads waiting for read data? */

      flags = enter_critical_section();
#ifndef CONFIG_RAMLOG_NONBLOCKING
      for (i = 0; i < priv->rl_nwaiters; i++)
        {
          /* Yes.. Notify all of the waiting readers that more data is available */

          nxsem_post(&priv->rl_waitsem);
        }
#endif

      /* Notify all poll/select waiters that they can write to the FIFO */

      ramlog_pollnotify(priv, POLLIN);
      leave_critical_section(flags);
    }
#endif

  /* We always have to return the number of bytes requested and NOT the
   * number of bytes that were actually written.  Otherwise, callers
   * will think that this is a short write and probably retry (causing
   */

  return len;
}

/****************************************************************************
 * Name: ramlog_poll
 ****************************************************************************/

#ifndef CONFIG_DISABLE_POLL
int ramlog_poll(FAR struct file *filep, FAR struct pollfd *fds, bool setup)
{
  FAR struct inode *inode = filep->f_inode;
  FAR struct ramlog_dev_s *priv;
  pollevent_t eventset;
  size_t ndx;
  int ret;
  int i;

  /* Some sanity checking */

  DEBUGASSERT(inode && inode->i_private);
  priv = (FAR struct ramlog_dev_s *)inode->i_private;

  /* Get exclusive access to the poll structures */

  ret = nxsem_wait(&priv->rl_exclsem);
  if (ret < 0)
    {
      return ret;
    }

  /* Are we setting up the poll?  Or tearing it down? */

  if (setup)
    {
      /* This is a request to set up the poll.  Find an available
       * slot for the poll structure reference
       */

      for (i = 0; i < CONFIG_RAMLOG_NPOLLWAITERS; i++)
        {
          /* Find an available slot */

          if (!priv->rl_fds[i])
            {
              /* Bind the poll structure and this slot */

              priv->rl_fds[i] = fds;
              fds->priv       = &priv->rl_fds[i];
              break;
            }
        }

      if (i >= CONFIG_RAMLOG_NPOLLWAITERS)
        {
          fds->priv    = NULL;
          ret          = -EBUSY;
          goto errout;
        }

      /* Should immediately notify on any of the requested events?
       * First, check if the xmit buffer is full.
       */

      eventset = 0;

      ndx = priv->rl_head + 1;
      if (ndx >= priv->rl_bufsize)
        {
          ndx = 0;
        }

      if (ndx != priv->rl_tail)
       {
         eventset |= POLLOUT;
       }

      /* Check if the receive buffer is empty */

      if (priv->rl_head != priv->rl_tail)
       {
         eventset |= POLLIN;
       }

      if (eventset)
        {
          ramlog_pollnotify(priv, eventset);
        }

    }
  else if (fds->priv)
    {
      /* This is a request to tear down the poll. */

      struct pollfd **slot = (struct pollfd **)fds->priv;

#ifdef CONFIG_DEBUG_FEATURES
      if (!slot)
        {
          ret = -EIO;
          goto errout;
        }
#endif

      /* Remove all memory of the poll setup */

      *slot      = NULL;
      fds->priv  = NULL;
    }

errout:
  nxsem_post(&priv->rl_exclsem);
  return ret;
}
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: ramlog_register
 *
 * Description:
 *   Create the RAM logging device and register it at the specified path.
 *
 ****************************************************************************/

#if !defined(CONFIG_RAMLOG_CONSOLE) && !defined(CONFIG_RAMLOG_SYSLOG)
int ramlog_register(FAR const char *devpath, FAR char *buffer, size_t buflen)
{
  FAR struct ramlog_dev_s *priv;
  int ret = -ENOMEM;

  /* Sanity checking */

  DEBUGASSERT(devpath && buffer && buflen > 1);

  /* Allocate a RAM logging device structure */

  priv = (struct ramlog_dev_s *)kmm_zalloc(sizeof(struct ramlog_dev_s));
  if (priv != NULL)
    {
      /* Initialize the non-zero values in the RAM logging device structure */

      nxsem_init(&priv->rl_exclsem, 0, 1);
#ifndef CONFIG_RAMLOG_NONBLOCKING
      nxsem_init(&priv->rl_waitsem, 0, 0);

      /* The rl_waitsem semaphore is used for signaling and, hence, should
       * not have priority inheritance enabled.
       */

      nxsem_setprotocol(&priv->rl_waitsem, SEM_PRIO_NONE);
#endif

      priv->rl_bufsize = buflen;
      priv->rl_buffer  = buffer;

      /* Register the character driver */

      ret = register_driver(devpath, &g_ramlogfops, 0666, priv);
      if (ret < 0)
        {
          kmm_free(priv);
        }
    }

  return ret;
}
#endif

/****************************************************************************
 * Name: ramlog_consoleinit
 *
 * Description:
 *   Use a pre-allocated RAM logging device and register it at /dev/console
 *
 ****************************************************************************/

#ifdef CONFIG_RAMLOG_CONSOLE
int ramlog_consoleinit(void)
{
  FAR struct ramlog_dev_s *priv = &g_sysdev;

  /* Register the console character driver */

  return register_driver("/dev/console", &g_ramlogfops, 0666, priv);
}
#endif

/****************************************************************************
 * Name: ramlog_syslog_channel
 *
 * Description:
 *   Use a pre-allocated RAM logging device and register it at the path
 *   specified by CONFIG_RAMLOG_SYSLOG
 *
 *   If CONFIG_RAMLOG_CONSOLE is also defined, then this functionality is
 *   performed when ramlog_consoleinit() is called.
 *
 ****************************************************************************/

#ifdef CONFIG_RAMLOG_SYSLOG
int ramlog_syslog_channel(void)
{
  int ret;

  /* Register the syslog character driver */

  ret = register_driver(CONFIG_SYSLOG_DEVPATH, &g_ramlogfops, 0666, &g_sysdev);
  if (ret < 0)
    {
      return ret;
    }

  /* Use the RAMLOG as the SYSLOG channel */

  return syslog_channel(&g_ramlog_syslog_channel);
}
#endif

/****************************************************************************
 * Name: ramlog_putc
 *
 * Description:
 *   This is the low-level system logging interface.
 *
 ****************************************************************************/

#if defined(CONFIG_RAMLOG_CONSOLE) || defined(CONFIG_RAMLOG_SYSLOG)
int ramlog_putc(int ch)
{
  FAR struct ramlog_dev_s *priv = &g_sysdev;
  int ret;

#ifdef CONFIG_RAMLOG_CRLF
  /* Ignore carriage returns.  But return success. */

  if (ch == '\r')
    {
      return ch;
    }

  /* Pre-pend a newline with a carriage return */

  if (ch == '\n')
    {
      ret = ramlog_addchar(priv, '\r');
      if (ret < 0)
        {
          /* The buffer is full and nothing was saved. */

          return ret;
        }
    }
#endif

  /* Add the character to the RAMLOG */

  ret = ramlog_addchar(priv, ch);
  if (ret < 0)
    {
      /* ramlog_addchar() failed */

      return ret;
    }

  /* Return the character added on success */

  return ch;
}
#endif

#endif /* CONFIG_RAMLOG */
/****************************************************************************
 * drivers/syslog/syslog_channel.c
 *
 *   Copyright (C) 2016 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <sys/types.h>
#include <assert.h>
#include <errno.h>

#include <tinyara/syslog/syslog.h>

#ifdef CONFIG_RAMLOG_SYSLOG
#  include <tinyara/syslog/ramlog.h>
#elif defined(CONFIG_ARCH_LOWPUTC)
#  include <tinyara/arch.h>
#endif

#include "syslog.h"

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

#if defined(CONFIG_ARCH_LOWPUTC)
#  define HAVE_LOWPUTC
#elif !defined(CONFIG_RAMLOG_SYSLOG)
#  define NEED_LOWPUTC
#endif

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

#ifdef NEED_LOWPUTC
static int syslog_default_putc(int ch);
#endif
static int syslog_default_flush(void);

/****************************************************************************
 * Public Data
 ****************************************************************************/

#if defined(CONFIG_RAMLOG_SYSLOG)
const struct syslog_channel_s g_default_channel =
{
#ifdef CONFIG_SYSLOG_WRITE
  syslog_default_write,
#endif
  ramlog_putc,
  ramlog_putc,
  syslog_default_flush
};
#elif defined(HAVE_LOWPUTC)
const struct syslog_channel_s g_default_channel =
{
#ifdef CONFIG_SYSLOG_WRITE
  syslog_default_write,
#endif
  up_putc,
  up_putc,
  syslog_default_flush
};
#else
const struct syslog_channel_s g_default_channel =
{
#ifdef CONFIG_SYSLOG_WRITE
  syslog_default_write,
#endif
  syslog_default_putc,
  syslog_default_putc,
  syslog_default_flush
};
#endif

/* This is the current syslog channel in use */

FAR const struct syslog_channel_s *g_syslog_channel = &g_default_channel;

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: syslog_default_putc and syslog_default_flush
 *
 * Description:
 *   Dummy, no-nothing channel interface methods
 *
 ****************************************************************************/

#ifdef NEED_LOWPUTC
static int syslog_default_putc(int ch)
{
  return ch;
}
#endif

static int syslog_default_flush(void)
{
  return OK;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: syslog_channel
 *
 * Description:
 *   Configure the SYSLOGging function to use the provided channel to
 *   generate SYSLOG output.
 *
 * Input Parameters:
 *   channel - Provides the interface to the channel to be used.
 *
 * Returned Value:
 *   Zero (OK)is returned on  success.  A negated errno value is returned
 *   on any failure.
 *
 ****************************************************************************/

int syslog_channel(FAR const struct syslog_channel_s *channel)
{
  DEBUGASSERT(channel != NULL);

  if (channel != NULL)
    {
      DEBUGASSERT(channel->sc_putc != NULL && channel->sc_force != NULL &&
                  channel->sc_flush != NULL);

      g_syslog_channel = channel;
      return OK;
    }

  return -EINVAL;
}
/****************************************************************************
 * drivers/syslog/syslog_chardev.c
 *
 *   Copyright (C) 2016 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <sys/types.h>
#include <stdbool.h>
#include <string.h>
#include <poll.h>
#include <errno.h>

#include <tinyara/fs/fs.h>
#include <tinyara/syslog/syslog.h>

#include "syslog.h"

#ifdef CONFIG_SYSLOG_CHARDEV

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

static ssize_t syslog_chardev_write(FAR struct file *filep,
                                    FAR const char *buffer, size_t buflen);

/****************************************************************************
 * Private Data
 ****************************************************************************/

static const struct file_operations syslog_fops =
{
  NULL,          /* open */
  NULL,          /* close */
  NULL,          /* read */
  syslog_chardev_write, /* write */
  NULL,          /* seek */
  NULL           /* ioctl */
#ifndef CONFIG_DISABLE_POLL
  , NULL         /* poll */
#endif
#ifndef CONFIG_DISABLE_PSEUDOFS_OPERATIONS
  , NULL         /* unlink */
#endif
};

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: syslog_chardev_write
 ****************************************************************************/

static ssize_t syslog_chardev_write(FAR struct file *filep,
                                    FAR const char *buffer, size_t len)
{
  return syslog_write(buffer, len);
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: syslog_register
 *
 * Description:
 *   Register a simple character driver at /dev/syslog whose write() method
 *   will transfer data to the SYSLOG device.  This can be useful if, for
 *   example, you want to redirect the output of a program to the SYSLOG.
 *
 *   NOTE that unlike other syslog output, this data is unformatted raw
 *   byte output with no time-stamping or any other SYSLOG features
 *   supported.
 *
 ****************************************************************************/

void syslog_register(void)
{
  (void)register_driver("/dev/syslog", &syslog_fops, 0222, NULL);
}

#endif /* CONFIG_SYSLOG_CHARDEV */
/****************************************************************************
 * drivers/syslog/syslog_console.c
 *
 *   Copyright (C) 2015 Pierre-noel Bouteville. All rights reserved.
 *   Author: Pierre-noel Bouteville <pnb990@gmail.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <sys/types.h>
#include <errno.h>
#include <debug.h>

#include <tinyara/arch.h>
#include <tinyara/fs/fs.h>
#include <tinyara/syslog/syslog.h>

#include "syslog.h"

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

static ssize_t syslog_console_read(FAR struct file *filep, FAR char *buffer,
                                   size_t buflen);
static ssize_t syslog_console_write(FAR struct file *filep,
                                    FAR const char *buffer, size_t buflen);
static int     syslog_console_ioctl(FAR struct file *filep, int cmd,
                                    unsigned long arg);

/****************************************************************************
 * Private Data
 ****************************************************************************/

static const struct file_operations g_consoleops =
{
  0,                    /* open */
  0,                    /* close */
  syslog_console_read,  /* read */
  syslog_console_write, /* write */
  0,                    /* seek */
  syslog_console_ioctl  /* ioctl */
#ifndef CONFIG_DISABLE_POLL
  , 0                   /* poll */
#endif
};

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: syslog_console_ioctl
 ****************************************************************************/

static int syslog_console_ioctl(FAR struct file *filep, int cmd,
                                unsigned long arg)
{
  return -ENOTTY;
}

/****************************************************************************
 * Name: syslog_console_read
 ****************************************************************************/

static ssize_t syslog_console_read(FAR struct file *filep, FAR char *buffer,
                                   size_t buflen)
{
  return 0;
}

/****************************************************************************
 * Name: syslog_console_write
 ****************************************************************************/

static ssize_t syslog_console_write(FAR struct file *filep,
                                    FAR const char *buffer, size_t buflen)
{
  return syslog_write(buffer, buflen);
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: syslog_console_init
 ****************************************************************************/

void syslog_console_init(void)
{
  (void)register_driver("/dev/console", &g_consoleops, 0666, NULL);
}
/****************************************************************************
 * drivers/syslog/syslog_consolechannel.c
 *
 *   Copyright (C) 2016 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <sys/stat.h>
#include <fcntl.h>

#include <tinyara/arch.h>
#include <tinyara/syslog/syslog.h>

#include "syslog.h"

#ifdef CONFIG_SYSLOG_CONSOLE

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#undef HAVE_LOWPUTC
#if defined(CONFIG_ARCH_LOWPUTC)
#  define HAVE_LOWPUTC 1
#endif

#define OPEN_FLAGS (O_WRONLY)
#define OPEN_MODE  (S_IROTH | S_IRGRP | S_IRUSR | S_IWUSR)

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/* SYSLOG channel methods */

#ifndef HAVE_LOWPUTC
static int syslog_console_force(int ch);
#endif

/****************************************************************************
 * Private Data
 ****************************************************************************/

/* This structure describes the SYSLOG channel */

static const struct syslog_channel_s g_syslog_console_channel =
{
#ifdef CONFIG_SYSLOG_WRITE
  syslog_dev_write,
#endif
  syslog_dev_putc,
#ifdef HAVE_LOWPUTC
  up_putc,
#else
  syslog_console_force,
#endif
  syslog_dev_flush,
};

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: syslog_console_force
 *
 * Description:
 *   A dummy FORCE method
 *
 ****************************************************************************/

#ifndef HAVE_LOWPUTC
static int syslog_console_force(int ch)
{
  return ch;
}
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: syslog_console_channel
 *
 * Description:
 *   Configure to use the character device (or file) at /dev/console as the
 *   SYSLOG channel.
 *
 *   This tiny function is simply a wrapper around syslog_dev_initialize()
 *   and syslog_channel().  It calls syslog_dev_initialize() to configure
 *   the character device at /dev/console then calls syslog_channel() to
 *   use that device as the SYSLOG output channel.
 *
 *   NOTE interrupt level SYSLOG output will be lost in the general case
 *   unless the interrupt buffer is used.  As a special case:  If the serial
 *   console is used and the architecture provides up_putc(), the interrupt
 *   level output will be directed to up_putc() is the interrupt buffer is
 *   disabled.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   Zero (OK) is returned on success; a negated errno value is returned on
 *   any failure.
 *
 ****************************************************************************/

int syslog_console_channel(void)
{
  int ret;

  /* Initialize the character driver interface */

  ret = syslog_dev_initialize("/dev/console", OPEN_FLAGS, OPEN_MODE);
  if (ret < 0)
    {
      return ret;
    }

  /* Use the character driver as the SYSLOG channel */

  return syslog_channel(&g_syslog_console_channel);
}

#endif /* CONFIG_SYSLOG_CONSOLE */
/****************************************************************************
 * drivers/syslog/syslog_devchannel.c
 *
 *   Copyright (C) 2016 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <sys/stat.h>
#include <fcntl.h>

#include <tinyara/syslog/syslog.h>

#include "syslog.h"

#ifdef CONFIG_SYSLOG_CHAR

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define OPEN_FLAGS (O_WRONLY)
#define OPEN_MODE  (S_IROTH | S_IRGRP | S_IRUSR | S_IWUSR)

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/* SYSLOG channel methods */

#ifdef CONFIG_SYSLOG_CHAR_CRLF
static int syslog_devchan_putc(int ch);
#endif
static int syslog_devchan_force(int ch);

/****************************************************************************
 * Private Data
 ****************************************************************************/

/* This structure describes the SYSLOG channel */

static const struct syslog_channel_s g_syslog_dev_channel =
{
#ifdef CONFIG_SYSLOG_WRITE
  syslog_dev_write,
#endif
#ifdef CONFIG_SYSLOG_CHAR_CRLF
  syslog_devchan_putc,
#else
  syslog_dev_putc,
#endif
  syslog_devchan_force,
  syslog_dev_flush,
};

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: syslog_devchan_putc
 *
 * Description:
 *   A front-end to syslog_dev_putc that does LF -> CR-LF expansion
 *
 ****************************************************************************/

#ifdef CONFIG_SYSLOG_CHAR_CRLF
static int syslog_devchan_putc(int ch)
{
  int ret;

  /* Check for a linefeed */

  if (ch == '\n')
    {
      /* Pre-pend a carriage return */

      ret = syslog_dev_putc('\r');
      if (ret < 0)
        {
          return ret;
        }
    }

  /* Output the provided character */

  return syslog_dev_putc(ch);
}
#endif

/****************************************************************************
 * Name: syslog_devchan_force
 *
 * Description:
 *   A dummy FORCE method
 *
 ****************************************************************************/

static int syslog_devchan_force(int ch)
{
  return ch;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: syslog_dev_channel
 *
 * Description:
 *   Configure to use the character device at CONFIG_SYSLOG_DEVPATH as the
 *   SYSLOG channel.
 *
 *   This tiny function is simply a wrapper around syslog_dev_initialize()
 *   and syslog_channel().  It calls syslog_dev_initialize() to configure
 *   the character device at CONFIG_SYSLOG_DEVPATH then calls
 *   syslog_channel() to use that device as the SYSLOG output channel.
 *
 *   NOTE interrupt level SYSLOG output will be lost in this case unless
 *   the interrupt buffer is used.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   Zero (OK) is returned on success; a negated errno value is returned on
 *   any failure.
 *
 ****************************************************************************/

int syslog_dev_channel(void)
{
  int ret;

  /* Initialize the character driver interface */

  ret = syslog_dev_initialize(CONFIG_SYSLOG_DEVPATH, OPEN_FLAGS, OPEN_MODE);
  if (ret < 0)
    {
      return ret;
    }

  /* Use the character driver as the SYSLOG channel */

  return syslog_channel(&g_syslog_dev_channel);
}

#endif /* CONFIG_SYSLOG_CHAR */
/****************************************************************************
 * drivers/syslog/syslog_device.c
 *
 *   Copyright (C) 2012, 2016-2017 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <sys/types.h>

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sched.h>
#include <fcntl.h>
#include <semaphore.h>
#include <errno.h>
#include <assert.h>

#include <tinyara/arch.h>
#include <tinyara/kmalloc.h>
#include <tinyara/fs/fs.h>
#include <tinyara/syslog/syslog.h>

#include "syslog.h"

#if CONFIG_NFILE_DESCRIPTORS > 0

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Open the device/file write-only, try to create (file) it if it doesn't
 * exist, if the file that already exists, then append the new log data to
 * end of the file.
 */

#define SYSLOG_OFLAGS (O_WRONLY | O_CREAT | O_APPEND)

/* An invalid thread ID */

#define NO_HOLDER     ((pid_t)-1)

/****************************************************************************
 * Private Types
 ****************************************************************************/

/* This enumeration represents the state of the SYSLOG device interface */

enum syslog_dev_state
{
  SYSLOG_UNINITIALIZED = 0, /* SYSLOG has not been initialized */
  SYSLOG_INITIALIZING,      /* SYSLOG is being initialized */
  SYSLOG_REOPEN,            /* SYSLOG open failed... try again later */
  SYSLOG_FAILURE,           /* SYSLOG open failed... don't try again */
  SYSLOG_OPENED,            /* SYSLOG device is open and ready to use */
};

/* This structure contains all SYSLOGing state information */

struct syslog_dev_s
{
  uint8_t      sl_state;    /* See enum syslog_dev_state */
  uint8_t      sl_oflags;   /* Saved open mode (for re-open) */
  uint16_t     sl_mode;     /* Saved open flags (for re-open) */
  sem_t        sl_sem;      /* Enforces mutually exclusive access */
  pid_t        sl_holder;   /* PID of the thread that holds the semaphore */
  struct file  sl_file;     /* The syslog file structure */
  FAR char    *sl_devpath;  /* Full path to the character device */
};

/****************************************************************************
 * Private Data
 ****************************************************************************/

/* This is the device structure for the console or syslogging function. */

static struct syslog_dev_s g_syslog_dev;
static const uint8_t g_syscrlf[2] =
{
  '\r', '\n'
};

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: syslog_dev_takesem
 *
 * Description:
 *   Write to the syslog device
 *
 ****************************************************************************/

static inline int syslog_dev_takesem(void)
{
  pid_t me = getpid();
  int ret;

  /* Does this thread already hold the semaphore?  That could happen if
   * we were called recursively, i.e., if the logic kicked off by
   * file_write() where to generate more debug output.  Return an
   * error in that case.
   */

  if (g_syslog_dev.sl_holder == me)
    {
      /* Return an error (instead of deadlocking) */

      return -EWOULDBLOCK;
    }

  /* Either the semaphore is available or is currently held by another
   * thread.  Wait for it to become available.
   */

  ret = nxsem_wait(&g_syslog_dev.sl_sem);
  if (ret < 0)
    {
      return ret;
    }

  /* We hold the semaphore.  We can safely mark ourself as the holder
   * of the semaphore.
   */

  g_syslog_dev.sl_holder = me;
  return OK;
}

/****************************************************************************
 * Name: syslog_dev_givesem
 *
 * Description:
 *   Write to the syslog device
 *
 ****************************************************************************/

static inline void syslog_dev_givesem(void)
{
#ifdef CONFIG_DEBUG_ASSERTIONS
  pid_t me = getpid();
  DEBUGASSERT(g_syslog_dev.sl_holder == me);
#endif

  /* Relinquish the semaphore */

  g_syslog_dev.sl_holder = NO_HOLDER;
  nxsem_post(&g_syslog_dev.sl_sem);
}

/****************************************************************************
 * Name: syslog_dev_outputready
 *
 * Description:
 * Ignore any output:
 *
 * (1) Before the SYSLOG device has been initialized.  This could happen
 *     from debug output that occurs early in the boot sequence before
 *     syslog_dev_initialize() is called (SYSLOG_UNINITIALIZED).
 * (2) While the device is being initialized.  The case could happen if
 *     debug output is generated while syslog_dev_initialize() executes
 *     (SYSLOG_INITIALIZING).
 * (3) While we are generating SYSLOG output.  The case could happen if
 *     debug output is generated while syslog_dev_putc() executes
 *     (This case is actually handled inside of syslog_semtake()).
 * (4) Any debug output generated from interrupt handlers.  A disadvantage
 *     of using the generic character device for the SYSLOG is that it
 *     cannot handle debug output generated from interrupt level handlers.
 * (5) Any debug output generated from the IDLE loop.  The character
 *     driver interface is blocking and the IDLE thread is not permitted
 *     to block.
 * (6) If an irrecoverable failure occurred during initialization.  In
 *     this case, we won't ever bother to try again (ever).
 *
 * NOTE: That the third case is different.  It applies only to the thread
 * that currently holds the sl_sem sempaphore.  Other threads should wait.
 * that is why that case is handled in syslog_semtake().
 *
 * Input Parameters:
 *   ch - The character to add to the SYSLOG (must be positive).
 *
 * Returned Value:
 *   On success, the character is echoed back to the caller.  A negated
 *   errno value is returned on any failure.
 *
 ****************************************************************************/

static int syslog_dev_outputready(void)
{
  int ret;

  /* Cases (4) and (5) */

  if (up_interrupt_context() || getpid() == 0)
    {
      return -ENOSYS;
    }

  /* We can save checks in the usual case:  That after the SYSLOG device
   * has been successfully opened.
   */

  if (g_syslog_dev.sl_state != SYSLOG_OPENED)
    {
      /* Case (1) and (2) */

      if (g_syslog_dev.sl_state == SYSLOG_UNINITIALIZED ||
          g_syslog_dev.sl_state == SYSLOG_INITIALIZING)
       {
         return -EAGAIN; /* Can't access the SYSLOG now... maybe next time? */
       }

      /* Case (6) */

      if (g_syslog_dev.sl_state == SYSLOG_FAILURE)
        {
          return -ENXIO;  /* There is no SYSLOG device */
        }

      /* syslog_dev_initialize() is called as soon as enough of the operating
       * system is in place to support the open operation... but it is
       * possible that the SYSLOG device is not yet registered at that time.
       * In this case, we know that the system is sufficiently initialized
       * to support an attempt to re-open the SYSLOG device.
       *
       * NOTE that the scheduler is locked.  That is because we do not have
       * fully initialized semaphore capability until the SYSLOG device is
       * successfully initialized
       */

      sched_lock();
      if (g_syslog_dev.sl_state == SYSLOG_REOPEN)
        {
          /* Try again to initialize the device.  We may do this repeatedly
           * because the log device might be something that was not ready
           * the first time that syslog_dev_initializee() was called (such as a
           * USB serial device that has not yet been connected or a file in
           * an NFS mounted file system that has not yet been mounted).
           */

          DEBUGASSERT(g_syslog_dev.sl_devpath != NULL);
          ret = syslog_dev_initialize(g_syslog_dev.sl_devpath,
                                      (int)g_syslog_dev.sl_oflags,
                                      (int)g_syslog_dev.sl_mode);
          if (ret < 0)
            {
              sched_unlock();
              return ret;
            }
        }

      sched_unlock();
      DEBUGASSERT(g_syslog_dev.sl_state == SYSLOG_OPENED);
    }

  return OK;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: syslog_dev_initialize
 *
 * Description:
 *   Initialize to use the character device (or file) at
 *   CONFIG_SYSLOG_DEVPATH as the SYSLOG sink.
 *
 *   One power up, the SYSLOG facility is non-existent or limited to very
 *   low-level output.  This function may be called later in the
 *   intialization sequence after full driver support has been initialized.
 *   (via syslog_initialize())  It installs the configured SYSLOG drivers
 *   and enables full SYSLOGing capability.
 *
 *   NOTE that this implementation excludes using a network connection as
 *   SYSLOG device.  That would be a good extension.
 *
 * Input Parameters:
 *   devpath - The full path to the character device to be used.
 *   oflags  - File open flags
 *   mode    - File open mode (only if oflags include O_CREAT)
 *
 * Returned Value:
 *   Zero (OK) is returned on success; a negated errno value is returned on
 *   any failure.
 *
 ****************************************************************************/

int syslog_dev_initialize(FAR const char *devpath, int oflags, int mode)
{
  int fd;
  int ret;

  /* At this point, the only expected states are SYSLOG_UNINITIALIZED or
   * SYSLOG_REOPEN..  Not SYSLOG_INITIALIZING, SYSLOG_FAILURE, SYSLOG_OPENED.
   */

  DEBUGASSERT(g_syslog_dev.sl_state == SYSLOG_UNINITIALIZED ||
              g_syslog_dev.sl_state == SYSLOG_REOPEN);

  /* Save the path to the device in case we have to re-open it.
   * If we get here and sl_devpath is not equal to NULL, that is a clue
   * that we will are re-openingthe file.
   */

  if (g_syslog_dev.sl_state == SYSLOG_REOPEN)
    {
      /* Re-opening: Then we should already have a copy of the path to the
       * device.
       */

      DEBUGASSERT(g_syslog_dev.sl_devpath != NULL &&
                  strcmp(g_syslog_dev.sl_devpath, devpath) == 0);
    }
  else
    {
      /* Initializing.  Copy the device path so that we can use it if we
       * have to re-open the file.
       */

      DEBUGASSERT(g_syslog_dev.sl_devpath == NULL);
      g_syslog_dev.sl_oflags  = oflags;
      g_syslog_dev.sl_mode    = mode;
      g_syslog_dev.sl_devpath = strdup(devpath);
      DEBUGASSERT(g_syslog_dev.sl_devpath != NULL);
    }

  g_syslog_dev.sl_state = SYSLOG_INITIALIZING;

  /* Open the device driver. */

  fd = open(devpath, oflags, mode);
  if (fd < 0)
    {
       int errcode = get_errno();
       DEBUGASSERT(errcode > 0);

      /* We failed to open the file. Perhaps it does exist?  Perhaps it
       * exists, but is not ready because it depends on insertion of a
       * removable device?
       *
       * In any case we will attempt to re-open the device repeatedly.
       * The assumption is that the device path is valid but that the
       * driver has not yet been registered or a removable device has
       * not yet been installed.
       */

      g_syslog_dev.sl_state = SYSLOG_REOPEN;
      return -errcode;
    }

  /* Detach the file descriptor from the file structure.  The file
   * descriptor is a task-specific concept.  Detaching the file
   * descriptor allows us to use the device on all threads in all tasks.
   */

  ret = file_detach(fd, &g_syslog_dev.sl_file);
  if (ret < 0)
    {
      /* This should not happen and means that something very bad has
       * occurred.
       */

      g_syslog_dev.sl_state = SYSLOG_FAILURE;
      close(fd);
      return ret;
    }

  /* The SYSLOG device is open and ready for writing. */

  nxsem_init(&g_syslog_dev.sl_sem, 0, 1);
  g_syslog_dev.sl_holder = NO_HOLDER;
  g_syslog_dev.sl_state  = SYSLOG_OPENED;
  return OK;
}

/****************************************************************************
 * Name: syslog_dev_uninitialize
 *
 * Description:
 *   Called to disable the last device/file channel in preparation to use
 *   a different SYSLOG device. Currently only used for CONFIG_SYSLOG_FILE.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   Zero (OK) is returned on success; a negated errno value is returned on
 *   any failure.
 *
 * Assumptions:
 *   The caller has already switched the SYSLOG source to some safe channel
 *   (the default channel).
 *
 ****************************************************************************/

#ifdef CONFIG_SYSLOG_FILE /* Currently only used in this configuration */
int syslog_dev_uninitialize(void)
{
  /* Attempt to flush any buffered data */

  sched_lock();
  (void)syslog_dev_flush();

  /* Close the detached file instance */

  (void)file_close_detached(&g_syslog_dev.sl_file);

  /* Free the device path */

  if (g_syslog_dev.sl_devpath != NULL)
    {
      kmm_free(g_syslog_dev.sl_devpath);
    }

  /* Destroy the semaphore */

  nxsem_destroy(&g_syslog_dev.sl_sem);

  /* Reset the state structure */

  memset(&g_syslog_dev, 0, sizeof(struct syslog_dev_s));
  sched_unlock();
  return OK;
}
#endif /* CONFIG_SYSLOG_FILE */

/****************************************************************************
 * Name: syslog_dev_write
 *
 * Description:
 *   This is the low-level, multile byte, system logging interface provided
 *   for the character driver interface.
 *
 * Input Parameters:
 *   buffer - The buffer containing the data to be output
 *   buflen - The number of bytes in the buffer
 *
 * Returned Value:
 *   On success, the character is echoed back to the caller. A negated errno
 *   value is returned on any failure.
 *
 ****************************************************************************/

ssize_t syslog_dev_write(FAR const char *buffer, size_t buflen)
{
  FAR const char *endptr;
  ssize_t nwritten;
  size_t writelen;
  size_t remaining;
  int ret;

  /* Check if the system is ready to do output operations */

  ret = syslog_dev_outputready();
  if (ret < 0)
    {
      return ret;
    }

  /* The syslog device is ready for writing */

  ret = syslog_dev_takesem();
  if (ret < 0)
    {
      /* We probably already hold the semaphore and were probably
       * re-entered by the logic kicked off by file_write().
       * We might also have been interrupted by a signal.  Either
       * way, we are outta here.
       */

      return ret;
    }

  /* Loop until we have output all characters */

  for (endptr = buffer, remaining = buflen;
       remaining > 0;
       endptr++, remaining--)
    {
      /* Check for carriage return or line feed */

      if (*endptr == '\r' || *endptr == '\n')
        {
          /* Check for pre-formatted CR-LF sequence */

          if (remaining > 1 &&
              ((endptr[0] == '\r' && endptr[1] == '\n') ||
               (endptr[0] == '\n' && endptr[1] == '\r')))
            {
              /* Just skip over pre-formatted CR-LF or LF-CR sequence */

              endptr++;
              remaining--;
            }
          else
            {
              /* Write everything up to the position of the special
               * character.
               *
               * - buffer points to next byte to output.
               * - endptr points to the special character.
               */

               writelen = (size_t)((uintptr_t)endptr - (uintptr_t)buffer);
               if (writelen > 0)
                {
                  nwritten = file_write(&g_syslog_dev.sl_file, buffer, writelen);
                  if (nwritten < 0)
                    {
                      ret = (int)nwritten;
                      goto errout_with_sem;
                    }
                }

              /* Ignore the carriage return, but for the linefeed, output
               * both a carriage return and a linefeed.
               */

              if (*endptr == '\n')
                {
                  nwritten = file_write(&g_syslog_dev.sl_file, g_syscrlf, 2);
                  if (nwritten < 0)
                    {
                      ret = (int)nwritten;
                      goto errout_with_sem;
                    }
                }

              /* Adjust pointers */

               writelen++;         /* Skip the special character */
               buffer += writelen; /* Points past the special character */
            }
        }
    }

  /* Write any unterminated data at the end of the buffer.
   *
   * - buffer points to next byte to output.
   * - endptr points to the end of the buffer plus 1.
   */

  writelen = (size_t)((uintptr_t)endptr - (uintptr_t)buffer);
  if (writelen > 0)
    {
      nwritten = file_write(&g_syslog_dev.sl_file, buffer, writelen);
      if (nwritten < 0)
        {
          ret = (int)nwritten;
          goto errout_with_sem;
        }
    }

  syslog_dev_givesem();
  return buflen;

errout_with_sem:
  syslog_dev_givesem();
  return ret;
}

/****************************************************************************
 * Name: syslog_dev_putc
 *
 * Description:
 *   This is the low-level, single character, system logging interface
 *   provided for the character driver interface.
 *
 * Input Parameters:
 *   ch - The character to add to the SYSLOG (must be positive).
 *
 * Returned Value:
 *   On success, the character is echoed back to the caller.  Minus one
 *   is returned on any failure with the errno set correctly.
 *
 ****************************************************************************/

int syslog_dev_putc(int ch)
{
  ssize_t nbytes;
  uint8_t uch;
  int ret;

  /* Check if the system is ready to do output operations */

  ret = syslog_dev_outputready();
  if (ret < 0)
    {
      return ret;
    }

  /* Ignore carriage returns */

  if (ch == '\r')
    {
      return ch;
    }

  /* The syslog device is ready for writing and we have something of
   * value to write.
   */

  ret = syslog_dev_takesem();
  if (ret < 0)
    {
      /* We probably already hold the semaphore and were probably
       * re-entered by the logic kicked off by file_write().
       * We might also have been interrupted by a signal.  Either
       * way, we are outta here.
       */

      return ret;
    }

  /* Pre-pend a newline with a carriage return. */

  if (ch == '\n')
    {
      /* Write the CR-LF sequence */

      nbytes = file_write(&g_syslog_dev.sl_file, g_syscrlf, 2);

      /* Synchronize the file when each CR-LF is encountered (i.e.,
       * implements line buffering always).
       */

#ifndef CONFIG_DISABLE_MOUNTPOINT
      if (nbytes > 0)
        {
          (void)syslog_dev_flush();
        }
#endif
    }
  else
    {
      /* Write the non-newline character (and don't flush) */

      uch = (uint8_t)ch;
      nbytes = file_write(&g_syslog_dev.sl_file, &uch, 1);
    }

  syslog_dev_givesem();

  /* Check if the write was successful.  If not, nbytes will be
   * a negated errno value.
   */

  if (nbytes < 0)
    {
      return (int)nbytes;
    }

  return ch;
}

/****************************************************************************
 * Name: syslog_dev_flush
 *
 * Description:
 *   Flush any buffer data in the file system to media.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   Zero (OK) on success; a negated errno value is returned on any failure.
 *
 ****************************************************************************/

int syslog_dev_flush(void)
{
#if defined(CONFIG_SYSLOG_FILE) && !defined(CONFIG_DISABLE_MOUNTPOINT)
  /* Ignore return value, always return success.  file_fsync() could fail
   * because the file is not open, the inode is not a mountpoint, or the
   * mountpoint does not support the sync() method.
   */

  (void)file_fsync(&g_syslog_dev.sl_file);
#endif

  return OK;
}

#endif /* CONFIG_NFILE_DESCRIPTORS > 0 */
/****************************************************************************
 * drivers/syslog/syslog_emergtream.c
 *
 *   Copyright (C) 2016-2017 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <errno.h>

#include <tinyara/syslog/syslog.h>
#include <tinyara/streams.h>

#include "syslog.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: emergstream_putc
 ****************************************************************************/

static void emergstream_putc(FAR struct lib_outstream_s *this, int ch)
{
  int ret;

  /* Try writing until the write was successful or until an irrecoverable
   * error occurs.
   */

  do
    {
      /* Write the character to the supported logging device.  On failure,
       * syslog_putc returns EOF with the errno value set;
       */

      ret = syslog_force(ch);
      if (ret != EOF)
        {
          this->nput++;
          return;
        }

      /* The special errno value -EINTR means that syslog_putc() was
       * awakened by a signal.  This is not a real error and must be
       * ignored in this context.
       */
    }
  while (errno == -EINTR);
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: emergstream
 *
 * Description:
 *   Initializes a stream for use with the configured emergency syslog
 *   interface.  Only accessible from with the OS SYSLOG logic.
 *
 * Input Parameters:
 *   stream - User allocated, uninitialized instance of struct
 *            lib_outstream_s to be initialized.
 *
 * Returned Value:
 *   None (User allocated instance initialized).
 *
 ****************************************************************************/

void emergstream(FAR struct lib_outstream_s *stream)
{
  stream->put   = emergstream_putc;
  stream->flush = lib_noflush;
  stream->nput  = 0;
}
/****************************************************************************
 * drivers/syslog/syslog_filechannel.c
 *
 *   Copyright (C) 2016 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <sys/stat.h>
#include <sched.h>
#include <fcntl.h>

#include <tinyara/syslog/syslog.h>

#include "syslog.h"

#ifdef CONFIG_SYSLOG_FILE

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define OPEN_FLAGS (O_WRONLY | O_CREAT | O_APPEND)
#define OPEN_MODE  (S_IROTH | S_IRGRP | S_IRUSR | S_IWUSR)

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/* SYSLOG channel methods */

static int syslog_file_force(int ch);

/****************************************************************************
 * Private Data
 ****************************************************************************/

/* This structure describes the SYSLOG channel */

static const struct syslog_channel_s g_syslog_file_channel =
{
#ifdef CONFIG_SYSLOG_WRITE
  syslog_dev_write,
#endif
  syslog_dev_putc,
  syslog_file_force,
  syslog_dev_flush,
};

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: syslog_file_force
 *
 * Description:
 *   A dummy FORCE method
 *
 ****************************************************************************/

static int syslog_file_force(int ch)
{
  return ch;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: syslog_file_channel
 *
 * Description:
 *   Configure to use a file in a mounted file system at 'devpath' as the
 *   SYSLOG channel.
 *
 *   This tiny function is simply a wrapper around syslog_dev_initialize()
 *   and syslog_channel().  It calls syslog_dev_initialize() to configure
 *   the character file at 'devpath then calls syslog_channel() to use that
 *   device as the SYSLOG output channel.
 *
 *   File SYSLOG channels differ from other SYSLOG channels in that they
 *   cannot be established until after fully booting and mounting the target
 *   file system.  This function would need to be called from board-specific
 *   bring-up logic AFTER mounting the file system containing 'devpath'.
 *
 *   SYSLOG data generated prior to calling syslog_file_channel will, of
 *   course, not be included in the file.
 *
 *   NOTE interrupt level SYSLOG output will be lost in this case unless
 *   the interrupt buffer is used.
 *
 * Input Parameters:
 *   devpath - The full path to the file to be used for SYSLOG output.
 *     This may be an existing file or not.  If the file exists,
 *     syslog_file_channel() will append new SYSLOG data to the end of the
 *     file.  If it does not, then syslog_file_channel() will create the
 *     file.
 *
 * Returned Value:
 *   Zero (OK) is returned on success; a negated errno value is returned on
 *   any failure.
 *
 ****************************************************************************/

int syslog_file_channel(FAR const char *devpath)
{
  FAR const struct syslog_channel_s *saved_channel;
  int ret;

  /* Reset the default SYSLOG channel so that we can safely modify the
   * SYSLOG device.  This is an atomic operation and we should be safe
   * after the default channel has been selected.
   *
   * We disable pre-emption only so that we are not suspended and a lot of
   * important debug output is lost while we futz with the channels.
   */

  sched_lock();
  saved_channel = g_syslog_channel;
  ret = syslog_channel(&g_default_channel);
  if (ret < 0)
    {
      goto errout_with_lock;
    }

  /* Uninitialize any driver interface that may have been in place */

  ret = syslog_dev_uninitialize();
  if (ret < 0)
    {
      /* Nothing fatal has happened yet, we can restore the last channel
       * since it was not uninitialized (was it?)
       */

      (void)syslog_channel(saved_channel);
      goto errout_with_lock;
    }

  /* Then initialize the file interface */

  ret = syslog_dev_initialize(devpath, OPEN_FLAGS, OPEN_MODE);
  if (ret < 0)
    {
      /* We should still be able to back-up and re-initialized everything */

      (void)syslog_initialize(SYSLOG_INIT_EARLY);
      (void)syslog_initialize(SYSLOG_INIT_LATE);
      goto errout_with_lock;
    }

  /* Use the file as the SYSLOG channel. If this fails we are pretty much
   * screwed.
   */

  ret = syslog_channel(&g_syslog_file_channel);

errout_with_lock:
  sched_unlock();
  return ret;
}

#endif /* CONFIG_SYSLOG_FILE */
/****************************************************************************
 * drivers/syslog/syslog_flush.c
 *
 *   Copyright (C) 2016 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <stdbool.h>
#include <assert.h>

#include <tinyara/syslog/syslog.h>

#include "syslog.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: syslog_flush
 *
 * Description:
 *   This is called by system crash-handling logic.  It must flush any
 *   buffered data to the SYSLOG device.
 *
 *   Interrupts are disabled at the time of the crash and this logic must
 *   perform the flush using low-level, non-interrupt driven logic.
 *
 *   REVISIT:  There is an implementation problem in that if a character
 *   driver is the underlying device, then there is no mechanism to flush
 *   the data buffered in the driver with interrupts disabled.
 *
 *   Currently, this function on (a) dumps the interrupt buffer (if the
 *   SYSLOG interrupt buffer is enabled), and (b) only the SYSLOG interface
 *   supports supports the 'sc_force()' method.
 *
 * Input Parameters:
 *   ch - The character to add to the SYSLOG (must be positive).
 *
 * Returned Value:
 *   Zero (OK)is returned on  success.  A negated errno value is returned
 *   on any failure.
 *
 ****************************************************************************/

int syslog_flush(void)
{
  DEBUGASSERT(g_syslog_channel != NULL);

#ifdef CONFIG_SYSLOG_INTBUFFER
  /* Flush any characters that may have been added to the interrupt
   * buffer.
   */

  (void)syslog_flush_intbuffer(g_syslog_channel, true);
#endif

#if 0
  /* Then flush all of the buffered output to the SYSLOG device */

  DEBUGASSERT(g_syslog_channel->sc_flush != NULL);
  return g_syslog_channel->sc_flush();
#else
  return 0;
#endif
}
/****************************************************************************
 * drivers/syslog/syslog_force.c
 *
 *   Copyright (C) 2016-2017 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <sys/types.h>
#include <stdbool.h>
#include <assert.h>

#include <tinyara/syslog/syslog.h>

#include "syslog.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: syslog_force
 *
 * Description:
 *   This is the low-level system logging interface.  This version forces
 *   the output and is only used in emergency situations (e.g., in assertion
 *   handling).
 *
 * Input Parameters:
 *   ch - The character to add to the SYSLOG (must be positive).
 *
 * Returned Value:
 *   On success, the character is echoed back to the caller. A negated errno
 *   value is returned on any failure.
 *
 ****************************************************************************/

int syslog_force(int ch)
{
  DEBUGASSERT(g_syslog_channel != NULL && g_syslog_channel->sc_force != NULL);

#ifdef CONFIG_SYSLOG_INTBUFFER
  /* Flush any characters that may have been added to the interrupt
   * buffer through the emergency channel
   */

  (void)syslog_flush_intbuffer(g_syslog_channel, true);
#endif

  /* Then send the character to the emergency channel */

  return g_syslog_channel->sc_force(ch);
}
/****************************************************************************
 * drivers/syslog/syslog_initialize.c
 *
 *   Copyright (C) 2016 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <stdio.h>

#include <tinyara/syslog/ramlog.h>
#include <tinyara/syslog/syslog.h>

#include "syslog.h"

#ifndef CONFIG_ARCH_SYSLOG

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: syslog_initialize
 *
 * Description:
 *   One power up, the SYSLOG facility is non-existent or limited to very
 *   low-level output.  This function is called later in the initialization
 *   sequence after full driver support has been initialized.  It installs
 *   the configured SYSLOG drivers and enables full SYSLOGing capability.
 *
 *   This function performs these basic operations:
 *
 *   - Initialize the SYSLOG device
 *   - Call syslog_channel() to begin using that device.
 *
 *   If CONFIG_ARCH_SYSLOG is selected, then the architecture-specifica
 *   logic will provide its own SYSLOG device initialize which must include
 *   as a minimum a call to syslog_channel() to use the device.
 *
 * Input Parameters:
 *   phase - One of {SYSLOG_INIT_EARLY, SYSLOG_INIT_LATE}
 *
 * Returned Value:
 *   Zero (OK) is returned on success; a negated errno value is returned on
 *   any failure.
 *
 ****************************************************************************/

int syslog_initialize(enum syslog_init_e phase)
{
  int ret = OK;

#if defined(CONFIG_SYSLOG_CHAR)
  if (phase == SYSLOG_INIT_LATE)
    {
      /* Enable use of a character device as the SYSLOG device */

      ret = syslog_dev_channel();
    }

#elif defined(CONFIG_RAMLOG_SYSLOG)
  if (phase == SYSLOG_INIT_EARLY)
    {
      /* Use the RAMLOG as the SYSLOG device */

      ret = ramlog_syslog_channel();
    }

#elif defined(CONFIG_SYSLOG_CONSOLE)
  if (phase == SYSLOG_INIT_LATE)
    {
      /* Use the console device as the SYSLOG device */

      ret = syslog_console_channel();
    }

#endif

  return ret;
}

#endif /* CONFIG_ARCH_SYSLOG */
/****************************************************************************
 * drivers/syslog/syslog_intbuffer.c
 *
 *   Copyright (C) 2016 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/
/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <errno.h>

#include <tinyara/syslog/syslog.h>
#include <tinyara/irq.h>

#include "syslog.h"

#ifdef CONFIG_SYSLOG_INTBUFFER

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Extend the size of the interrupt buffer so that a "[truncated]\n"
 * indication can be append to the end.
 *
 * The usable capacity of the interrupt buffer is (CONFIG_SYSLOG_INTBUFSIZE - 1).
 */

#define SYSLOG_BUFOVERRUN_MESSAGE  "[truncated]\n"
#define SYSLOG_BUFOVERRUN_SIZE     13

#if CONFIG_SYSLOG_INTBUFSIZE > (65535 - SYSLOG_BUFOVERRUN_SIZE)
#  undef  CONFIG_SYSLOG_INTBUFSIZE
#  define CONFIG_SYSLOG_INTBUFSIZE (65535 - SYSLOG_BUFOVERRUN_SIZE)
#  define SYSLOG_INTBUFSIZE        65535
#else
#  define SYSLOG_INTBUFSIZE \
     (CONFIG_SYSLOG_INTBUFSIZE + SYSLOG_BUFOVERRUN_SIZE)
#endif

#define USABLE_INTBUFSIZE          (CONFIG_SYSLOG_INTBUFSIZE - 1)

/****************************************************************************
 * Private Types
 ****************************************************************************/

/* This structure encapsulates the interrupt buffer state */

struct g_syslog_intbuffer_s
{
  volatile uint16_t si_inndx;
  volatile uint16_t si_outndx;
  uint8_t si_buffer[SYSLOG_INTBUFSIZE];
};

/****************************************************************************
 * Private Data
 ****************************************************************************/

static struct g_syslog_intbuffer_s g_syslog_intbuffer;
static const char g_overrun_msg[SYSLOG_BUFOVERRUN_SIZE] = SYSLOG_BUFOVERRUN_MESSAGE;

/****************************************************************************
 * Private Data
 ****************************************************************************/

/****************************************************************************
 * Name: syslog_remove_intbuffer
 *
 * Description:
 *   Extract any characters that may have been added to the interrupt buffer
 *   to the SYSLOG device.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   On success, the extracted character is returned.  EOF is returned if
 *   the interrupt buffer is empty.
 *
 * Assumptions:
 *   Interrupts may or may not be disabled.
 *
 ****************************************************************************/

int syslog_remove_intbuffer(void)
{
  irqstate_t flags;
  uint32_t outndx;
  int ret = EOF;

  /* Extraction of the character and adjustment of the circular buffer
   * indices must be performed in a critical section to protect from
   * concurrent modification from interrupt handlers.
   */

  flags = enter_critical_section();

  /* Check if the interrupt buffer? is empty */

  outndx = (uint32_t)g_syslog_intbuffer.si_outndx;
  if (outndx != (uint32_t)g_syslog_intbuffer.si_inndx)
    {
      /* Not empty.. Take the next character from the interrupt buffer */

      ret = g_syslog_intbuffer.si_buffer[outndx];

      /* Increment the OUT index, handling wrap-around */

      if (++outndx >= SYSLOG_INTBUFSIZE)
        {
          outndx -= SYSLOG_INTBUFSIZE;
        }

      g_syslog_intbuffer.si_outndx = (uint16_t)outndx;
    }

  leave_critical_section(flags);

  /* Now we can send the extracted character to the SYSLOG device */

  return ret;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: syslog_add_intbuffer
 *
 * Description:
 *   Add one more character to the interrupt buffer.  In the event of
 *   buffer overlowed, the character will be dropped.  The indication
 *   "[truncated]\n" will be appended to the end of the interrupt buffer.
 *
 * Input Parameters:
 *   ch - The character to add to the interrupt buffer (must be positive).
 *
 * Returned Value:
 *   Zero success, the character is echoed back to the caller.  A negated
 *   errno value is returned on any failure.
 *
 * Assumptions:
 *   - Called either from (1) interrupt handling logic with interrupts
 *     disabled or from an IDLE thread with interrupts enabled.
 *   - Requires caution because there may be an interrupted execution of
 *     syslog_flush_intbuffer():  Only the outndx can be modified.
 *
 ****************************************************************************/

int syslog_add_intbuffer(int ch)
{
  irqstate_t flags;
  uint32_t inndx;
  uint32_t outndx;
  uint32_t endndx;
  unsigned int inuse;
  int ret;
  int i;

  /* Disable concurrent modification from interrupt handling logic */

  flags = enter_critical_section();

  /* How much space is left in the intbuffer? */

  inndx  = (uint32_t)g_syslog_intbuffer.si_inndx;
  outndx = (uint32_t)g_syslog_intbuffer.si_outndx;

  endndx = inndx;
  if (endndx < outndx)
    {
      endndx += SYSLOG_INTBUFSIZE;
    }

  inuse = (unsigned int)(endndx - outndx);

  /* Is there space for another character (reserving space for the overrun
   * message)?
   */

  if (inuse == USABLE_INTBUFSIZE)
    {
      /* Copy the truncated message one character at a time, handing index
       * wrap-around on each character.
       */

      for (i = 0; i < SYSLOG_BUFOVERRUN_SIZE; i++)
        {
          /* Copy one character */

          g_syslog_intbuffer.si_buffer[inndx] = (uint8_t)g_overrun_msg[i];

          /* Increment the IN index, handling wrap-around */

          if (++inndx >= SYSLOG_INTBUFSIZE)
            {
              inndx -= SYSLOG_INTBUFSIZE;
            }

          DEBUGASSERT(inndx != outndx);
        }

      g_syslog_intbuffer.si_inndx = (uint16_t)inndx;
      ret = -ENOSPC;
    }
  else if (inuse < USABLE_INTBUFSIZE)
    {
       /* Copy one character */

       g_syslog_intbuffer.si_buffer[inndx] = (uint8_t)ch;

       /* Increment the IN index, handling wrap-around */

       if (++inndx >= SYSLOG_INTBUFSIZE)
         {
           inndx -= SYSLOG_INTBUFSIZE;
         }

      g_syslog_intbuffer.si_inndx = (uint16_t)inndx;
      ret = OK;
    }
  else
    {
      /* This character goes to the bit bucket.  We have already copied
       * the overrun message so there is nothing else to do.
       */

      ret = -ENOSPC;
    }

  leave_critical_section(flags);
  return ret;
}

/****************************************************************************
 * Name: syslog_flush_intbuffer
 *
 * Description:
 *   Flush any characters that may have been added to the interrupt buffer
 *   to the SYSLOG device.
 *
 * Input Parameters:
 *   channel - The syslog channel to use in performing the flush operation.
 *   force   - Use the force() method of the channel vs. the putc() method.
 *
 * Returned Value:
 *   On success, the character is echoed back to the caller.  A negated
 *   errno value is returned on any failure.
 *
 * Assumptions:
 *   Interrupts may or may not be disabled.
 *
 ****************************************************************************/

int syslog_flush_intbuffer(FAR const struct syslog_channel_s *channel,
                           bool force)
{
  syslog_putc_t putfunc;
  int ch;
  int ret = OK;

  /* Select which putc function to use for this flush */

  putfunc = force ? channel->sc_putc : channel->sc_force;

  /* This logic is performed with the scheduler disabled to protect from
   * concurrent modification by other tasks.
   */

  sched_lock();
  do
    {
      /* Transfer one character to time.  This is inefficient, but is
       * done in this way to: (1) Deal with concurrent modification of
       * the interrupt buffer from interrupt activity, (2) Avoid keeper
       * interrupts disabled for a long time, and (3) to handler
       * wraparound of the circular buffer indices.
       */

      ch = syslog_remove_intbuffer();
      if (ch != EOF)
        {
          ret = putfunc(ch);
        }
    }
  while (ch != EOF && ret >= 0);

  sched_unlock();
  return ret;
}

#endif /* CONFIG_SYSLOG_INTBUFFER */
/****************************************************************************
 * drivers/syslog/syslog_putc.c
 *
 *   Copyright (C) 2016 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <sys/types.h>
#include <assert.h>
#include <errno.h>

#include <tinyara/arch.h>
#include <tinyara/sched.h>
#include <tinyara/syslog/syslog.h>

#include "syslog.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: syslog_putc
 *
 * Description:
 *   This is the low-level system logging interface.
 *
 * Input Parameters:
 *   ch - The character to add to the SYSLOG (must be positive).
 *
 * Returned Value:
 *   On success, the character is echoed back to the caller.  A negated
 *   errno value is returned on any failure.
 *
 ****************************************************************************/

int syslog_putc(int ch)
{
  DEBUGASSERT(g_syslog_channel != NULL);

  /* Is this an attempt to do SYSLOG output from an interrupt handler? */

  if (up_interrupt_context() || sched_idletask())
    {
#if defined(CONFIG_SYSLOG_INTBUFFER)
      /* Buffer the character in the interrupt buffer.  The interrupt buffer
       * will be flushed before the next normal, non-interrupt SYSLOG output.
       */

      return syslog_add_intbuffer(ch);
#else
      /* Force the character to the SYSLOG device immediately (if possible).
       * This means that the interrupt data may not be in synchronization
       * with output data that may have been buffered by sc_putc().
       */

      DEBUGASSERT(g_syslog_channel->sc_force != NULL);

      return g_syslog_channel->sc_force(ch);
#endif
    }
  else
    {
      DEBUGASSERT(g_syslog_channel->sc_putc != NULL);

#ifdef CONFIG_SYSLOG_INTBUFFER
      /* Flush any characters that may have been added to the interrupt
       * buffer.
       */

      (void)syslog_flush_intbuffer(g_syslog_channel, false);
#endif

      return g_syslog_channel->sc_putc(ch);
    }
}
/****************************************************************************
 * drivers/syslog/syslog_stream.c
 *
 *   Copyright (C) 2012, 2016-2017 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <errno.h>

#include <tinyara/streams.h>
#include <tinyara/mm/iob.h>
#include <tinyara/syslog/syslog.h>

#include "syslog.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: syslogstream_flush
 ****************************************************************************/

#ifdef CONFIG_SYSLOG_BUFFER
static int syslogstream_flush(FAR struct lib_syslogstream_s *stream)
{
  FAR struct iob_s *iob;
  int ret = OK;

  DEBUGASSERT(stream != NULL);
  iob = stream->iob;

  /* Do we have an IO buffer? Is there anything buffered? */

  if (iob != NULL && iob->io_len > 0)
    {
      /* Yes write the buffered data */

      do
        {
          ssize_t nbytes = syslog_write((FAR const char *)iob->io_data,
                                        (size_t)iob->io_len);
          if (nbytes < 0)
            {
              ret = (int)nbytes;
            }
          else
            {
              iob->io_len = 0;
              ret = OK;
            }
        }
      while (ret == -EINTR);
    }

  return ret;
}
#endif

/****************************************************************************
 * Name: syslogstream_addchar
 ****************************************************************************/

#ifdef CONFIG_SYSLOG_BUFFER
static void syslogstream_addchar(FAR struct lib_syslogstream_s *stream, int ch)
{
  FAR struct iob_s *iob = stream->iob;

  /* Add the incoming character to the buffer */

  iob->io_data[iob->io_len] = ch;
  iob->io_len++;

  /* Increment the total number of bytes buffered. */

  stream->public.nput++;

  /* Is the buffer full? */

  if (iob->io_len >= CONFIG_IOB_BUFSIZE)
    {
      /* Yes.. then flush the buffer */

      syslogstream_flush(stream);
    }
}
#endif

/****************************************************************************
 * Name: syslogstream_putc
 ****************************************************************************/

static void syslogstream_putc(FAR struct lib_outstream_s *this, int ch)
{
  /* Discard carriage returns */

  if (ch != '\r')
    {
#ifdef CONFIG_SYSLOG_BUFFER
      FAR struct lib_syslogstream_s *stream =
        (FAR struct lib_syslogstream_s *)this;

      DEBUGASSERT(stream != NULL);

      /* Do we have an IO buffer? */

      if (stream->iob != NULL)
        {
          /* Is this a linefeed? */

          if (ch == '\n')
            {
              /* Yes... pre-pend carriage return */

              syslogstream_addchar(stream, '\r');
            }

          /* Add the incoming character to the buffer */

          syslogstream_addchar(stream, ch);
        }
      else
#endif
        {
          int ret;

          /* Try writing until the write was successful or until an
           * irrecoverable error occurs.
           */

          do
            {
              /* Write the character to the supported logging device.  On
               * failure, syslog_putc returns EOF with the errno value set;
               */

              ret = syslog_putc(ch);
              if (ret >= 0)
                {
                  this->nput++;
                  return;
                }

              /* The special return value -EINTR means that syslog_putc() was
               * awakened by a signal.  This is not a real error and must be
               * ignored in this context.
               */
            }
          while (ret == -EINTR);
        }
    }
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: syslogstream_create
 *
 * Description:
 *   Initializes a stream for use with the configured syslog interface.
 *   Only accessible from with the OS SYSLOG logic.
 *
 * Input Parameters:
 *   stream - User allocated, uninitialized instance of struct
 *            lib_lowoutstream_s to be initialized.
 *
 * Returned Value:
 *   None (User allocated instance initialized).
 *
 ****************************************************************************/

void syslogstream_create(FAR struct lib_syslogstream_s *stream)
{
#ifdef CONFIG_SYSLOG_BUFFER
  FAR struct iob_s *iob;
#endif

  DEBUGASSERT(stream != NULL);

  /* Initialize the common fields */

  stream->public.put   = syslogstream_putc;
  stream->public.flush = lib_noflush;
  stream->public.nput  = 0;

#ifdef CONFIG_SYSLOG_BUFFER
  /* Allocate an IOB */

  iob                  = iob_alloc(true);
  stream->iob          = iob;

  if (iob != NULL)
    {
      /* Initialize the IOB */

      iob->io_len      = 0;
      iob->io_offset   = 0;
      iob->io_pktlen   = 0;
    }
#endif
}

/****************************************************************************
 * Name: syslogstream_destroy
 *
 * Description:
 *   Free resources held by the syslog stream.
 *
 * Input Parameters:
 *   stream - User allocated, uninitialized instance of struct
 *            lib_lowoutstream_s to be initialized.
 *
 * Returned Value:
 *   None (Resources freed).
 *
 ****************************************************************************/

#ifdef CONFIG_SYSLOG_BUFFER
void syslogstream_destroy(FAR struct lib_syslogstream_s *stream)
{
  DEBUGASSERT(stream != NULL);

  /* Verify that there is an IOB attached (there should be) */

  if (stream->iob != NULL)
    {
      /* Flush the output buffered in the IOB */

      syslogstream_flush(stream);

      /* Free the IOB */

      iob_free(stream->iob);
      stream->iob = NULL;
    }
}
#endif
/****************************************************************************
 * drivers/syslog/syslog_write.c
 *
 *   Copyright (C) 2017 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <sys/types.h>

#include <tinyara/arch.h>
#include <tinyara/sched.h>
#include <tinyara/syslog/syslog.h>

#include "syslog.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: syslog_default_write
 *
 * Description:
 *   This provides a default write method for syslog devices that do not
 *   support multiple byte writes  This functions simply loops, outputting
 *   one cahracter at a time.
 *
 * Input Parameters:
 *   buffer - The buffer containing the data to be output
 *   buflen - The number of bytes in the buffer
 *
 * Returned Value:
 *   On success, the number of characters written is returned.  A negated
 *   errno value is returned on any failure.
 *
 ****************************************************************************/

ssize_t syslog_default_write(FAR const char *buffer, size_t buflen)
{
  size_t nwritten;
  int ret;

  for (nwritten = 0; nwritten < buflen; nwritten++)
    {
      int ch = *buffer++;
      ret = syslog_putc(ch);
      UNUSED(ret);
    }

  return buflen;
}

/****************************************************************************
 * Name: syslog_write
 *
 * Description:
 *   This is the low-level, multiple character, system logging interface.
 *
 * Input Parameters:
 *   buffer - The buffer containing the data to be output
 *   buflen - The number of bytes in the buffer
 *
 * Returned Value:
 *   On success, the number of characters written is returned.  A negated
 *   errno value is returned on any failure.
 *
 ****************************************************************************/

ssize_t syslog_write(FAR const char *buffer, size_t buflen)
{
#ifdef CONFIG_SYSLOG_WRITE
  if (!up_interrupt_context() && !sched_idletask())
    {
#ifdef CONFIG_SYSLOG_INTBUFFER
      /* Flush any characters that may have been added to the interrupt
       * buffer.
       */

      (void)syslog_flush_intbuffer(g_syslog_channel, false);
#endif

      return g_syslog_channel->sc_write(buffer, buflen);
    }
  else
#endif
    {
      return syslog_default_write(buffer, buflen);
    }
}
/****************************************************************************
 * drivers/syslog/vsyslog.c
 *
 *   Copyright (C) 2007-2009, 2011-2014, 2016-2017 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <stdio.h>
#include <syslog.h>
#include <errno.h>

#include <tinyara/init.h>
#include <tinyara/arch.h>
#include <tinyara/clock.h>
#include <tinyara/streams.h>
#include <tinyara/syslog/syslog.h>

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: nx_vsyslog
 *
 * Description:
 *   nx_vsyslog() handles the system logging system calls. It is functionally
 *   equivalent to vsyslog() except that (1) the per-process priority
 *   filtering has already been performed and the va_list parameter is
 *   passed by reference.  That is because the va_list is a structure in
 *   some compilers and passing of structures in the NuttX sycalls does
 *   not work.
 *
 ****************************************************************************/

int nx_vsyslog(int priority, FAR const IPTR char *fmt, FAR va_list *ap)
{
  struct lib_syslogstream_s stream;
  int ret;

#ifdef CONFIG_SYSLOG_TIMESTAMP
  struct timespec ts;

  /* Get the current time.  Since debug output may be generated very early
   * in the start-up sequence, hardware timer support may not yet be
   * available.
   */

  ret = -EAGAIN;
  if (OSINIT_HW_READY())
    {
#if defined(CONFIG_SYSLOG_TIMESTAMP_REALTIME)
      /* Use CLOCK_REALTIME if so configured */

      ret = clock_gettime(CLOCK_REALTIME, &ts);

#elif defined(CONFIG_CLOCK_MONOTONIC)
      /* Prefer monotonic when enabled, as it can be synchronized to
       * RTC with clock_resynchronize.
       */

      ret = clock_gettime(CLOCK_MONOTONIC, &ts);

#else
      /* Otherwise, fall back to the system timer */

      ret = clock_systimespec(&ts);
#endif
    }

  if (ret < 0)
    {
      /* Timer hardware is not available, or clock function failed */

      ts.tv_sec  = 0;
      ts.tv_nsec = 0;
    }
#endif

  /* Wrap the low-level output in a stream object and let lib_vsprintf
   * do the work.  NOTE that emergency priority output is handled
   * differently.. it will use the SYSLOG emergency stream.
   */

  if (priority == LOG_EMERG)
    {
      /* Use the SYSLOG emergency stream */

      emergstream(&stream.public);
    }
  else
    {
      /* Use the normal SYSLOG stream */

      syslogstream_create(&stream);
    }

#if defined(CONFIG_SYSLOG_TIMESTAMP)
  /* Pre-pend the message with the current time, if available */

  (void)lib_sprintf(&stream.public, "[%5d.%06d] ",
                    ts.tv_sec, ts.tv_nsec/1000);
#endif

#if defined(CONFIG_SYSLOG_PREFIX)
  /* Pre-pend the prefix, if available */

  ret = lib_sprintf(&stream.public, "%s", CONFIG_SYSLOG_PREFIX_STRING);
#else
  ret = 0;
#endif

  /* Generate the output */

  ret += lib_vsprintf(&stream.public, fmt, *ap);

#ifdef CONFIG_SYSLOG_BUFFER
  /* Flush and destroy the syslog stream buffer */

  if (priority != LOG_EMERG)
    {
      syslogstream_destroy(&stream);
    }
#endif

  return ret;
}
