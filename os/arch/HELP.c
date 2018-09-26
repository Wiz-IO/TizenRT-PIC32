//PIC32MZ2048EFM100
//-nostartfiles -nostdlib -nodefaultlibs -mnewlib-libc 
//-fno-short-double <------
// #ifndef __LANGUAGE_ASSEMBLY__

#include <tinyara/config.h>
#include <tinyara/streams.h>
#include <tinyara/arch.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>
#include <signal.h>



FAR struct task_tcb_s *task_vforksetup(start_t retaddr){}//, size_t *argsize
pid_t task_vforkstart(FAR struct task_tcb_s *child){}
void task_vforkabort(FAR struct task_tcb_s *child, int errcode){}


void syslog_flush(){}



void sinfo(const char * f, ...){}
void serr(const char * f, ...){}
void svcerr(const char * f, ...){}




