#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/TIZEN.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/TIZEN.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=lib/libc/aio/wiz_aio.c lib/libc/audio/lib_buffer.c lib/libc/dirent/wiz_dirent.c lib/libc/fixedmath/wiz_fixedmath.c lib/libc/inttypes/wiz_inttipes.c lib/libc/libgen/wiz_libgen.c lib/libc/locale/wiz_locale.c lib/libc/math/fpclassify.c lib/libc/misc/wiz_misc.c lib/libc/mqueue/wiz_mqueue.c lib/libc/net/wiz_net.c lib/libc/pthread/wiz_pthread.c lib/libc/queue/wiz_queue.c lib/libc/sched/wiz_sched.c lib/libc/semaphore/wiz_semaphore.c lib/libc/signal/wiz_signal.c lib/libc/stdio/wiz_stdio.c lib/libc/stdlib/wiz_stdlib.c lib/libc/string/wiz_string.c lib/libc/syslog/wiz_syslog.c lib/libc/termios/wiz_termios.c lib/libc/time/wiz_time.c lib/libc/unistd/wiz_unistd.c lib/libc/wchar/wiz_wchar.c lib/libc/wctype/wiz_wctype.c lib/libc/wqueue/wiz_wqueue.c lib/libxx/libxx_newlib_impure.c os/arch/board/curiosity/pic32mz_boot.c os/arch/board/curiosity/pic32mz_userleds.c os/arch/board/curiosity/pic32mz_autoleds.c os/arch/board/curiosity/pic32mz_bringup.c os/arch/board/curiosity/pic32mz_buttons.c os/arch/board/curiosity/pic32mz_nsh.c os/arch/board/curiosity/pic32mz_spi.c os/arch/mips/src/common/up_allocateheap.c os/arch/mips/src/common/up_createstack.c os/arch/mips/src/common/up_etherstub.c os/arch/mips/src/common/up_exit.c os/arch/mips/src/common/up_idle.c os/arch/mips/src/common/up_initialize.c os/arch/mips/src/common/up_interruptcontext.c os/arch/mips/src/common/up_lowputs.c os/arch/mips/src/common/up_mdelay.c os/arch/mips/src/common/up_modifyreg16.c os/arch/mips/src/common/up_modifyreg32.c os/arch/mips/src/common/up_modifyreg8.c os/arch/mips/src/common/up_puts.c os/arch/mips/src/common/up_releasestack.c os/arch/mips/src/common/up_stackframe.c os/arch/mips/src/common/up_udelay.c os/arch/mips/src/common/up_usestack.c os/arch/mips/src/mips32/up_assert.c os/arch/mips/src/mips32/up_blocktask.c os/arch/mips/src/mips32/up_copystate.c os/arch/mips/src/mips32/up_doirq.c os/arch/mips/src/mips32/up_dumpstate.c os/arch/mips/src/mips32/up_initialstate.c os/arch/mips/src/mips32/up_irq.c os/arch/mips/src/mips32/up_releasepending.c os/arch/mips/src/mips32/up_reprioritizertr.c os/arch/mips/src/mips32/up_schedulesigaction.c os/arch/mips/src/mips32/up_sigdeliver.c os/arch/mips/src/mips32/up_swint0.c os/arch/mips/src/mips32/up_unblocktask.c os/arch/mips/src/mips32/up_vfork.c os/arch/mips/src/mips32/up_syscall0.S os/arch/mips/src/mips32/vfork.S os/arch/mips/src/pic32mz/pic32mz-decodeirq.c os/arch/mips/src/pic32mz/pic32mz-ethernet.c os/arch/mips/src/pic32mz/pic32mz-exception.c os/arch/mips/src/pic32mz/pic32mz-gpio.c os/arch/mips/src/pic32mz/pic32mz-gpioirq.c os/arch/mips/src/pic32mz/pic32mz-irq.c os/arch/mips/src/pic32mz/pic32mz-lowconsole.c os/arch/mips/src/pic32mz/pic32mz-lowinit.c os/arch/mips/src/pic32mz/pic32mz-serial.c os/arch/mips/src/pic32mz/pic32mz-spi.c os/arch/mips/src/pic32mz/pic32mz-timerisr.c os/arch/mips/src/pic32mz/crt0.S os/drivers/bch/bch.c os/drivers/serial/lowconsole.c os/drivers/serial/serial.c os/drivers/serial/serialirq.c os/drivers/syslog/ramlog.c os/drivers/syslog/syslog_console.c os/fs/aio/fs_aio.c os/fs/dirent/fs_dirent.c os/fs/driver/block/fs_block.c os/fs/driver/block/ramdisk.c os/fs/inode/fs_inode.c os/fs/mount/fs_mount.c os/fs/vfs/vfs.c os/fs/fs_initialize.c os/kernel/clock/clock.c os/kernel/clock/clock_abstime2ticks.c os/kernel/clock/clock_dow.c os/kernel/clock/clock_getres.c os/kernel/clock/clock_gettime.c os/kernel/clock/clock_gettimeofday.c os/kernel/clock/clock_initialize.c os/kernel/clock/clock_settime.c os/kernel/clock/clock_systimer.c os/kernel/clock/clock_systimespec.c os/kernel/clock/clock_ticks2time.c os/kernel/clock/clock_time2ticks.c os/kernel/debug/sysdbg.c os/kernel/environ/env_clearenv.c os/kernel/environ/env_dup.c os/kernel/environ/env_findvar.c os/kernel/environ/env_getenv.c os/kernel/environ/env_getenvironptr.c os/kernel/environ/env_putenv.c os/kernel/environ/env_release.c os/kernel/environ/env_removevar.c os/kernel/environ/env_setenv.c os/kernel/environ/env_unsetenv.c os/kernel/errno/errno_get.c os/kernel/errno/errno_getptr.c os/kernel/errno/errno_set.c os/kernel/group/group_addrenv.c os/kernel/group/group_childstatus.c os/kernel/group/group_create.c os/kernel/group/group_find.c os/kernel/group/group_foreachchild.c os/kernel/group/group_free.c os/kernel/group/group_join.c os/kernel/group/group_killchildren.c os/kernel/group/group_leave.c os/kernel/group/group_malloc.c os/kernel/group/group_setupidlefiles.c os/kernel/group/group_setupstreams.c os/kernel/group/group_setuptaskfiles.c os/kernel/group/group_signal.c os/kernel/group/group_zalloc.c os/kernel/init/os_bringup.c os/kernel/init/os_start.c os/kernel/irq/irq_attach.c os/kernel/irq/irq_dispatch.c os/kernel/irq/irq_info.c os/kernel/irq/irq_initialize.c os/kernel/irq/irq_unexpectedisr.c os/kernel/paging/pg_miss.c os/kernel/paging/pg_worker.c os/kernel/pthread/pthread_cancel.c os/kernel/pthread/pthread_cleanup.c os/kernel/pthread/pthread_completejoin.c os/kernel/pthread/pthread_condbroadcast.c os/kernel/pthread/pthread_condsignal.c os/kernel/pthread/pthread_condtimedwait.c os/kernel/pthread/pthread_condwait.c os/kernel/pthread/pthread_create.c os/kernel/pthread/pthread_detach.c os/kernel/pthread/pthread_exit.c os/kernel/pthread/pthread_findjoininfo.c os/kernel/pthread/pthread_getschedparam.c os/kernel/pthread/pthread_getspecific.c os/kernel/pthread/pthread_initialize.c os/kernel/pthread/pthread_join.c os/kernel/pthread/pthread_keycreate.c os/kernel/pthread/pthread_keydelete.c os/kernel/pthread/pthread_keydestroy.c os/kernel/pthread/pthread_kill.c os/kernel/pthread/pthread_mutex.c os/kernel/pthread/pthread_mutexconsistent.c os/kernel/pthread/pthread_mutexdestroy.c os/kernel/pthread/pthread_mutexinconsistent.c os/kernel/pthread/pthread_mutexinit.c os/kernel/pthread/pthread_mutexlock.c os/kernel/pthread/pthread_mutextrylock.c os/kernel/pthread/pthread_mutexunlock.c os/kernel/pthread/pthread_release.c os/kernel/pthread/pthread_setschedparam.c os/kernel/pthread/pthread_setschedprio.c os/kernel/pthread/pthread_setspecific.c os/kernel/pthread/pthread_sigmask.c os/kernel/pthread/pthread_tryjoin_np.c os/kernel/sched/sched_addblocked.c os/kernel/sched/sched_addprioritized.c os/kernel/sched/sched_addreadytorun.c os/kernel/sched/sched_cpuload.c os/kernel/sched/sched_foreach.c os/kernel/sched/sched_free.c os/kernel/sched/sched_garbage.c os/kernel/sched/sched_getfiles.c os/kernel/sched/sched_getparam.c os/kernel/sched/sched_getscheduler.c os/kernel/sched/sched_getsockets.c os/kernel/sched/sched_getstreams.c os/kernel/sched/sched_gettcb.c os/kernel/sched/sched_lock.c os/kernel/sched/sched_lockcount.c os/kernel/sched/sched_mergepending.c os/kernel/sched/sched_processtimer.c os/kernel/sched/sched_releasetcb.c os/kernel/sched/sched_removeblocked.c os/kernel/sched/sched_removereadytorun.c os/kernel/sched/sched_reprioritize.c os/kernel/sched/sched_rrgetinterval.c os/kernel/sched/sched_self.c os/kernel/sched/sched_setparam.c os/kernel/sched/sched_setpriority.c os/kernel/sched/sched_setscheduler.c os/kernel/sched/sched_timerexpiration.c os/kernel/sched/sched_unlock.c os/kernel/sched/sched_verifytcb.c os/kernel/sched/sched_wait.c os/kernel/sched/sched_waitid.c os/kernel/sched/sched_waitpid.c os/kernel/sched/sched_yield.c os/kernel/semaphore/sem_destroy.c os/kernel/semaphore/sem_holder.c os/kernel/semaphore/sem_initialize.c os/kernel/semaphore/sem_post.c os/kernel/semaphore/sem_recover.c os/kernel/semaphore/sem_reset.c os/kernel/semaphore/sem_setprotocol.c os/kernel/semaphore/sem_tickwait.c os/kernel/semaphore/sem_timedwait.c os/kernel/semaphore/sem_trywait.c os/kernel/semaphore/sem_wait.c os/kernel/semaphore/sem_waitirq.c os/kernel/signal/sig_action.c os/kernel/signal/sig_allocatependingsigaction.c os/kernel/signal/sig_cleanup.c os/kernel/signal/sig_deliver.c os/kernel/signal/sig_dispatch.c os/kernel/signal/sig_findaction.c os/kernel/signal/sig_initialize.c os/kernel/signal/sig_is_handler_registered.c os/kernel/signal/sig_kill.c os/kernel/signal/sig_lowest.c os/kernel/signal/sig_mqnotempty.c os/kernel/signal/sig_nanosleep.c os/kernel/signal/sig_pause.c os/kernel/signal/sig_pending.c os/kernel/signal/sig_procmask.c os/kernel/signal/sig_queue.c os/kernel/signal/sig_releasependingsigaction.c os/kernel/signal/sig_releasependingsignal.c os/kernel/signal/sig_removependingsignal.c os/kernel/signal/sig_sethandler.c os/kernel/signal/sig_suspend.c os/kernel/signal/sig_timedwait.c os/kernel/signal/sig_unmaskpendingsignal.c os/kernel/signal/sig_waitinfo.c os/kernel/task/exit.c os/kernel/task/task_activate.c os/kernel/task/task_atexit.c os/kernel/task/task_cancelpt.c os/kernel/task/task_create.c os/kernel/task/task_delete.c os/kernel/task/task_execv.c os/kernel/task/task_exit.c os/kernel/task/task_exithook.c os/kernel/task/task_getgroup.c os/kernel/task/task_getpid.c os/kernel/task/task_init.c os/kernel/task/task_onexit.c os/kernel/task/task_prctl.c os/kernel/task/task_recover.c os/kernel/task/task_reparent.c os/kernel/task/task_restart.c os/kernel/task/task_setcancelstate.c os/kernel/task/task_setcanceltype.c os/kernel/task/task_setup.c os/kernel/task/task_start.c os/kernel/task/task_starthook.c os/kernel/task/task_terminate.c os/kernel/task/task_testcancel.c os/kernel/task/task_vfork.c os/kernel/timer/timer_create.c os/kernel/timer/timer_delete.c os/kernel/timer/timer_getoverrun.c os/kernel/timer/timer_gettime.c os/kernel/timer/timer_initialize.c os/kernel/timer/timer_release.c os/kernel/timer/timer_settime.c os/kernel/wdog/wd_cancel.c os/kernel/wdog/wd_create.c os/kernel/wdog/wd_delete.c os/kernel/wdog/wd_gettime.c os/kernel/wdog/wd_initialize.c os/kernel/wdog/wd_recover.c os/kernel/wdog/wd_start.c os/mm/kmm_heap/kmm.c os/mm/mm_heap/mm_heap.c os/mm/umm_heap/umm.c main.c os/arch/HELP.c sys_config.c os/drivers/dev_null.c os/drivers/dev_zero.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/lib/libc/aio/wiz_aio.o ${OBJECTDIR}/lib/libc/audio/lib_buffer.o ${OBJECTDIR}/lib/libc/dirent/wiz_dirent.o ${OBJECTDIR}/lib/libc/fixedmath/wiz_fixedmath.o ${OBJECTDIR}/lib/libc/inttypes/wiz_inttipes.o ${OBJECTDIR}/lib/libc/libgen/wiz_libgen.o ${OBJECTDIR}/lib/libc/locale/wiz_locale.o ${OBJECTDIR}/lib/libc/math/fpclassify.o ${OBJECTDIR}/lib/libc/misc/wiz_misc.o ${OBJECTDIR}/lib/libc/mqueue/wiz_mqueue.o ${OBJECTDIR}/lib/libc/net/wiz_net.o ${OBJECTDIR}/lib/libc/pthread/wiz_pthread.o ${OBJECTDIR}/lib/libc/queue/wiz_queue.o ${OBJECTDIR}/lib/libc/sched/wiz_sched.o ${OBJECTDIR}/lib/libc/semaphore/wiz_semaphore.o ${OBJECTDIR}/lib/libc/signal/wiz_signal.o ${OBJECTDIR}/lib/libc/stdio/wiz_stdio.o ${OBJECTDIR}/lib/libc/stdlib/wiz_stdlib.o ${OBJECTDIR}/lib/libc/string/wiz_string.o ${OBJECTDIR}/lib/libc/syslog/wiz_syslog.o ${OBJECTDIR}/lib/libc/termios/wiz_termios.o ${OBJECTDIR}/lib/libc/time/wiz_time.o ${OBJECTDIR}/lib/libc/unistd/wiz_unistd.o ${OBJECTDIR}/lib/libc/wchar/wiz_wchar.o ${OBJECTDIR}/lib/libc/wctype/wiz_wctype.o ${OBJECTDIR}/lib/libc/wqueue/wiz_wqueue.o ${OBJECTDIR}/lib/libxx/libxx_newlib_impure.o ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_boot.o ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_userleds.o ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_autoleds.o ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_bringup.o ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_buttons.o ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_nsh.o ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_spi.o ${OBJECTDIR}/os/arch/mips/src/common/up_allocateheap.o ${OBJECTDIR}/os/arch/mips/src/common/up_createstack.o ${OBJECTDIR}/os/arch/mips/src/common/up_etherstub.o ${OBJECTDIR}/os/arch/mips/src/common/up_exit.o ${OBJECTDIR}/os/arch/mips/src/common/up_idle.o ${OBJECTDIR}/os/arch/mips/src/common/up_initialize.o ${OBJECTDIR}/os/arch/mips/src/common/up_interruptcontext.o ${OBJECTDIR}/os/arch/mips/src/common/up_lowputs.o ${OBJECTDIR}/os/arch/mips/src/common/up_mdelay.o ${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg16.o ${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg32.o ${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg8.o ${OBJECTDIR}/os/arch/mips/src/common/up_puts.o ${OBJECTDIR}/os/arch/mips/src/common/up_releasestack.o ${OBJECTDIR}/os/arch/mips/src/common/up_stackframe.o ${OBJECTDIR}/os/arch/mips/src/common/up_udelay.o ${OBJECTDIR}/os/arch/mips/src/common/up_usestack.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_assert.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_blocktask.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_copystate.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_doirq.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_dumpstate.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_initialstate.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_irq.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_releasepending.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_reprioritizertr.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_schedulesigaction.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_sigdeliver.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_swint0.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_unblocktask.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_vfork.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_syscall0.o ${OBJECTDIR}/os/arch/mips/src/mips32/vfork.o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-decodeirq.o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-ethernet.o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-exception.o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpio.o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpioirq.o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-irq.o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowconsole.o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowinit.o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-serial.o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-spi.o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-timerisr.o ${OBJECTDIR}/os/arch/mips/src/pic32mz/crt0.o ${OBJECTDIR}/os/drivers/bch/bch.o ${OBJECTDIR}/os/drivers/serial/lowconsole.o ${OBJECTDIR}/os/drivers/serial/serial.o ${OBJECTDIR}/os/drivers/serial/serialirq.o ${OBJECTDIR}/os/drivers/syslog/ramlog.o ${OBJECTDIR}/os/drivers/syslog/syslog_console.o ${OBJECTDIR}/os/fs/aio/fs_aio.o ${OBJECTDIR}/os/fs/dirent/fs_dirent.o ${OBJECTDIR}/os/fs/driver/block/fs_block.o ${OBJECTDIR}/os/fs/driver/block/ramdisk.o ${OBJECTDIR}/os/fs/inode/fs_inode.o ${OBJECTDIR}/os/fs/mount/fs_mount.o ${OBJECTDIR}/os/fs/vfs/vfs.o ${OBJECTDIR}/os/fs/fs_initialize.o ${OBJECTDIR}/os/kernel/clock/clock.o ${OBJECTDIR}/os/kernel/clock/clock_abstime2ticks.o ${OBJECTDIR}/os/kernel/clock/clock_dow.o ${OBJECTDIR}/os/kernel/clock/clock_getres.o ${OBJECTDIR}/os/kernel/clock/clock_gettime.o ${OBJECTDIR}/os/kernel/clock/clock_gettimeofday.o ${OBJECTDIR}/os/kernel/clock/clock_initialize.o ${OBJECTDIR}/os/kernel/clock/clock_settime.o ${OBJECTDIR}/os/kernel/clock/clock_systimer.o ${OBJECTDIR}/os/kernel/clock/clock_systimespec.o ${OBJECTDIR}/os/kernel/clock/clock_ticks2time.o ${OBJECTDIR}/os/kernel/clock/clock_time2ticks.o ${OBJECTDIR}/os/kernel/debug/sysdbg.o ${OBJECTDIR}/os/kernel/environ/env_clearenv.o ${OBJECTDIR}/os/kernel/environ/env_dup.o ${OBJECTDIR}/os/kernel/environ/env_findvar.o ${OBJECTDIR}/os/kernel/environ/env_getenv.o ${OBJECTDIR}/os/kernel/environ/env_getenvironptr.o ${OBJECTDIR}/os/kernel/environ/env_putenv.o ${OBJECTDIR}/os/kernel/environ/env_release.o ${OBJECTDIR}/os/kernel/environ/env_removevar.o ${OBJECTDIR}/os/kernel/environ/env_setenv.o ${OBJECTDIR}/os/kernel/environ/env_unsetenv.o ${OBJECTDIR}/os/kernel/errno/errno_get.o ${OBJECTDIR}/os/kernel/errno/errno_getptr.o ${OBJECTDIR}/os/kernel/errno/errno_set.o ${OBJECTDIR}/os/kernel/group/group_addrenv.o ${OBJECTDIR}/os/kernel/group/group_childstatus.o ${OBJECTDIR}/os/kernel/group/group_create.o ${OBJECTDIR}/os/kernel/group/group_find.o ${OBJECTDIR}/os/kernel/group/group_foreachchild.o ${OBJECTDIR}/os/kernel/group/group_free.o ${OBJECTDIR}/os/kernel/group/group_join.o ${OBJECTDIR}/os/kernel/group/group_killchildren.o ${OBJECTDIR}/os/kernel/group/group_leave.o ${OBJECTDIR}/os/kernel/group/group_malloc.o ${OBJECTDIR}/os/kernel/group/group_setupidlefiles.o ${OBJECTDIR}/os/kernel/group/group_setupstreams.o ${OBJECTDIR}/os/kernel/group/group_setuptaskfiles.o ${OBJECTDIR}/os/kernel/group/group_signal.o ${OBJECTDIR}/os/kernel/group/group_zalloc.o ${OBJECTDIR}/os/kernel/init/os_bringup.o ${OBJECTDIR}/os/kernel/init/os_start.o ${OBJECTDIR}/os/kernel/irq/irq_attach.o ${OBJECTDIR}/os/kernel/irq/irq_dispatch.o ${OBJECTDIR}/os/kernel/irq/irq_info.o ${OBJECTDIR}/os/kernel/irq/irq_initialize.o ${OBJECTDIR}/os/kernel/irq/irq_unexpectedisr.o ${OBJECTDIR}/os/kernel/paging/pg_miss.o ${OBJECTDIR}/os/kernel/paging/pg_worker.o ${OBJECTDIR}/os/kernel/pthread/pthread_cancel.o ${OBJECTDIR}/os/kernel/pthread/pthread_cleanup.o ${OBJECTDIR}/os/kernel/pthread/pthread_completejoin.o ${OBJECTDIR}/os/kernel/pthread/pthread_condbroadcast.o ${OBJECTDIR}/os/kernel/pthread/pthread_condsignal.o ${OBJECTDIR}/os/kernel/pthread/pthread_condtimedwait.o ${OBJECTDIR}/os/kernel/pthread/pthread_condwait.o ${OBJECTDIR}/os/kernel/pthread/pthread_create.o ${OBJECTDIR}/os/kernel/pthread/pthread_detach.o ${OBJECTDIR}/os/kernel/pthread/pthread_exit.o ${OBJECTDIR}/os/kernel/pthread/pthread_findjoininfo.o ${OBJECTDIR}/os/kernel/pthread/pthread_getschedparam.o ${OBJECTDIR}/os/kernel/pthread/pthread_getspecific.o ${OBJECTDIR}/os/kernel/pthread/pthread_initialize.o ${OBJECTDIR}/os/kernel/pthread/pthread_join.o ${OBJECTDIR}/os/kernel/pthread/pthread_keycreate.o ${OBJECTDIR}/os/kernel/pthread/pthread_keydelete.o ${OBJECTDIR}/os/kernel/pthread/pthread_keydestroy.o ${OBJECTDIR}/os/kernel/pthread/pthread_kill.o ${OBJECTDIR}/os/kernel/pthread/pthread_mutex.o ${OBJECTDIR}/os/kernel/pthread/pthread_mutexconsistent.o ${OBJECTDIR}/os/kernel/pthread/pthread_mutexdestroy.o ${OBJECTDIR}/os/kernel/pthread/pthread_mutexinconsistent.o ${OBJECTDIR}/os/kernel/pthread/pthread_mutexinit.o ${OBJECTDIR}/os/kernel/pthread/pthread_mutexlock.o ${OBJECTDIR}/os/kernel/pthread/pthread_mutextrylock.o ${OBJECTDIR}/os/kernel/pthread/pthread_mutexunlock.o ${OBJECTDIR}/os/kernel/pthread/pthread_release.o ${OBJECTDIR}/os/kernel/pthread/pthread_setschedparam.o ${OBJECTDIR}/os/kernel/pthread/pthread_setschedprio.o ${OBJECTDIR}/os/kernel/pthread/pthread_setspecific.o ${OBJECTDIR}/os/kernel/pthread/pthread_sigmask.o ${OBJECTDIR}/os/kernel/pthread/pthread_tryjoin_np.o ${OBJECTDIR}/os/kernel/sched/sched_addblocked.o ${OBJECTDIR}/os/kernel/sched/sched_addprioritized.o ${OBJECTDIR}/os/kernel/sched/sched_addreadytorun.o ${OBJECTDIR}/os/kernel/sched/sched_cpuload.o ${OBJECTDIR}/os/kernel/sched/sched_foreach.o ${OBJECTDIR}/os/kernel/sched/sched_free.o ${OBJECTDIR}/os/kernel/sched/sched_garbage.o ${OBJECTDIR}/os/kernel/sched/sched_getfiles.o ${OBJECTDIR}/os/kernel/sched/sched_getparam.o ${OBJECTDIR}/os/kernel/sched/sched_getscheduler.o ${OBJECTDIR}/os/kernel/sched/sched_getsockets.o ${OBJECTDIR}/os/kernel/sched/sched_getstreams.o ${OBJECTDIR}/os/kernel/sched/sched_gettcb.o ${OBJECTDIR}/os/kernel/sched/sched_lock.o ${OBJECTDIR}/os/kernel/sched/sched_lockcount.o ${OBJECTDIR}/os/kernel/sched/sched_mergepending.o ${OBJECTDIR}/os/kernel/sched/sched_processtimer.o ${OBJECTDIR}/os/kernel/sched/sched_releasetcb.o ${OBJECTDIR}/os/kernel/sched/sched_removeblocked.o ${OBJECTDIR}/os/kernel/sched/sched_removereadytorun.o ${OBJECTDIR}/os/kernel/sched/sched_reprioritize.o ${OBJECTDIR}/os/kernel/sched/sched_rrgetinterval.o ${OBJECTDIR}/os/kernel/sched/sched_self.o ${OBJECTDIR}/os/kernel/sched/sched_setparam.o ${OBJECTDIR}/os/kernel/sched/sched_setpriority.o ${OBJECTDIR}/os/kernel/sched/sched_setscheduler.o ${OBJECTDIR}/os/kernel/sched/sched_timerexpiration.o ${OBJECTDIR}/os/kernel/sched/sched_unlock.o ${OBJECTDIR}/os/kernel/sched/sched_verifytcb.o ${OBJECTDIR}/os/kernel/sched/sched_wait.o ${OBJECTDIR}/os/kernel/sched/sched_waitid.o ${OBJECTDIR}/os/kernel/sched/sched_waitpid.o ${OBJECTDIR}/os/kernel/sched/sched_yield.o ${OBJECTDIR}/os/kernel/semaphore/sem_destroy.o ${OBJECTDIR}/os/kernel/semaphore/sem_holder.o ${OBJECTDIR}/os/kernel/semaphore/sem_initialize.o ${OBJECTDIR}/os/kernel/semaphore/sem_post.o ${OBJECTDIR}/os/kernel/semaphore/sem_recover.o ${OBJECTDIR}/os/kernel/semaphore/sem_reset.o ${OBJECTDIR}/os/kernel/semaphore/sem_setprotocol.o ${OBJECTDIR}/os/kernel/semaphore/sem_tickwait.o ${OBJECTDIR}/os/kernel/semaphore/sem_timedwait.o ${OBJECTDIR}/os/kernel/semaphore/sem_trywait.o ${OBJECTDIR}/os/kernel/semaphore/sem_wait.o ${OBJECTDIR}/os/kernel/semaphore/sem_waitirq.o ${OBJECTDIR}/os/kernel/signal/sig_action.o ${OBJECTDIR}/os/kernel/signal/sig_allocatependingsigaction.o ${OBJECTDIR}/os/kernel/signal/sig_cleanup.o ${OBJECTDIR}/os/kernel/signal/sig_deliver.o ${OBJECTDIR}/os/kernel/signal/sig_dispatch.o ${OBJECTDIR}/os/kernel/signal/sig_findaction.o ${OBJECTDIR}/os/kernel/signal/sig_initialize.o ${OBJECTDIR}/os/kernel/signal/sig_is_handler_registered.o ${OBJECTDIR}/os/kernel/signal/sig_kill.o ${OBJECTDIR}/os/kernel/signal/sig_lowest.o ${OBJECTDIR}/os/kernel/signal/sig_mqnotempty.o ${OBJECTDIR}/os/kernel/signal/sig_nanosleep.o ${OBJECTDIR}/os/kernel/signal/sig_pause.o ${OBJECTDIR}/os/kernel/signal/sig_pending.o ${OBJECTDIR}/os/kernel/signal/sig_procmask.o ${OBJECTDIR}/os/kernel/signal/sig_queue.o ${OBJECTDIR}/os/kernel/signal/sig_releasependingsigaction.o ${OBJECTDIR}/os/kernel/signal/sig_releasependingsignal.o ${OBJECTDIR}/os/kernel/signal/sig_removependingsignal.o ${OBJECTDIR}/os/kernel/signal/sig_sethandler.o ${OBJECTDIR}/os/kernel/signal/sig_suspend.o ${OBJECTDIR}/os/kernel/signal/sig_timedwait.o ${OBJECTDIR}/os/kernel/signal/sig_unmaskpendingsignal.o ${OBJECTDIR}/os/kernel/signal/sig_waitinfo.o ${OBJECTDIR}/os/kernel/task/exit.o ${OBJECTDIR}/os/kernel/task/task_activate.o ${OBJECTDIR}/os/kernel/task/task_atexit.o ${OBJECTDIR}/os/kernel/task/task_cancelpt.o ${OBJECTDIR}/os/kernel/task/task_create.o ${OBJECTDIR}/os/kernel/task/task_delete.o ${OBJECTDIR}/os/kernel/task/task_execv.o ${OBJECTDIR}/os/kernel/task/task_exit.o ${OBJECTDIR}/os/kernel/task/task_exithook.o ${OBJECTDIR}/os/kernel/task/task_getgroup.o ${OBJECTDIR}/os/kernel/task/task_getpid.o ${OBJECTDIR}/os/kernel/task/task_init.o ${OBJECTDIR}/os/kernel/task/task_onexit.o ${OBJECTDIR}/os/kernel/task/task_prctl.o ${OBJECTDIR}/os/kernel/task/task_recover.o ${OBJECTDIR}/os/kernel/task/task_reparent.o ${OBJECTDIR}/os/kernel/task/task_restart.o ${OBJECTDIR}/os/kernel/task/task_setcancelstate.o ${OBJECTDIR}/os/kernel/task/task_setcanceltype.o ${OBJECTDIR}/os/kernel/task/task_setup.o ${OBJECTDIR}/os/kernel/task/task_start.o ${OBJECTDIR}/os/kernel/task/task_starthook.o ${OBJECTDIR}/os/kernel/task/task_terminate.o ${OBJECTDIR}/os/kernel/task/task_testcancel.o ${OBJECTDIR}/os/kernel/task/task_vfork.o ${OBJECTDIR}/os/kernel/timer/timer_create.o ${OBJECTDIR}/os/kernel/timer/timer_delete.o ${OBJECTDIR}/os/kernel/timer/timer_getoverrun.o ${OBJECTDIR}/os/kernel/timer/timer_gettime.o ${OBJECTDIR}/os/kernel/timer/timer_initialize.o ${OBJECTDIR}/os/kernel/timer/timer_release.o ${OBJECTDIR}/os/kernel/timer/timer_settime.o ${OBJECTDIR}/os/kernel/wdog/wd_cancel.o ${OBJECTDIR}/os/kernel/wdog/wd_create.o ${OBJECTDIR}/os/kernel/wdog/wd_delete.o ${OBJECTDIR}/os/kernel/wdog/wd_gettime.o ${OBJECTDIR}/os/kernel/wdog/wd_initialize.o ${OBJECTDIR}/os/kernel/wdog/wd_recover.o ${OBJECTDIR}/os/kernel/wdog/wd_start.o ${OBJECTDIR}/os/mm/kmm_heap/kmm.o ${OBJECTDIR}/os/mm/mm_heap/mm_heap.o ${OBJECTDIR}/os/mm/umm_heap/umm.o ${OBJECTDIR}/main.o ${OBJECTDIR}/os/arch/HELP.o ${OBJECTDIR}/sys_config.o ${OBJECTDIR}/os/drivers/dev_null.o ${OBJECTDIR}/os/drivers/dev_zero.o
POSSIBLE_DEPFILES=${OBJECTDIR}/lib/libc/aio/wiz_aio.o.d ${OBJECTDIR}/lib/libc/audio/lib_buffer.o.d ${OBJECTDIR}/lib/libc/dirent/wiz_dirent.o.d ${OBJECTDIR}/lib/libc/fixedmath/wiz_fixedmath.o.d ${OBJECTDIR}/lib/libc/inttypes/wiz_inttipes.o.d ${OBJECTDIR}/lib/libc/libgen/wiz_libgen.o.d ${OBJECTDIR}/lib/libc/locale/wiz_locale.o.d ${OBJECTDIR}/lib/libc/math/fpclassify.o.d ${OBJECTDIR}/lib/libc/misc/wiz_misc.o.d ${OBJECTDIR}/lib/libc/mqueue/wiz_mqueue.o.d ${OBJECTDIR}/lib/libc/net/wiz_net.o.d ${OBJECTDIR}/lib/libc/pthread/wiz_pthread.o.d ${OBJECTDIR}/lib/libc/queue/wiz_queue.o.d ${OBJECTDIR}/lib/libc/sched/wiz_sched.o.d ${OBJECTDIR}/lib/libc/semaphore/wiz_semaphore.o.d ${OBJECTDIR}/lib/libc/signal/wiz_signal.o.d ${OBJECTDIR}/lib/libc/stdio/wiz_stdio.o.d ${OBJECTDIR}/lib/libc/stdlib/wiz_stdlib.o.d ${OBJECTDIR}/lib/libc/string/wiz_string.o.d ${OBJECTDIR}/lib/libc/syslog/wiz_syslog.o.d ${OBJECTDIR}/lib/libc/termios/wiz_termios.o.d ${OBJECTDIR}/lib/libc/time/wiz_time.o.d ${OBJECTDIR}/lib/libc/unistd/wiz_unistd.o.d ${OBJECTDIR}/lib/libc/wchar/wiz_wchar.o.d ${OBJECTDIR}/lib/libc/wctype/wiz_wctype.o.d ${OBJECTDIR}/lib/libc/wqueue/wiz_wqueue.o.d ${OBJECTDIR}/lib/libxx/libxx_newlib_impure.o.d ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_boot.o.d ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_userleds.o.d ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_autoleds.o.d ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_bringup.o.d ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_buttons.o.d ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_nsh.o.d ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_spi.o.d ${OBJECTDIR}/os/arch/mips/src/common/up_allocateheap.o.d ${OBJECTDIR}/os/arch/mips/src/common/up_createstack.o.d ${OBJECTDIR}/os/arch/mips/src/common/up_etherstub.o.d ${OBJECTDIR}/os/arch/mips/src/common/up_exit.o.d ${OBJECTDIR}/os/arch/mips/src/common/up_idle.o.d ${OBJECTDIR}/os/arch/mips/src/common/up_initialize.o.d ${OBJECTDIR}/os/arch/mips/src/common/up_interruptcontext.o.d ${OBJECTDIR}/os/arch/mips/src/common/up_lowputs.o.d ${OBJECTDIR}/os/arch/mips/src/common/up_mdelay.o.d ${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg16.o.d ${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg32.o.d ${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg8.o.d ${OBJECTDIR}/os/arch/mips/src/common/up_puts.o.d ${OBJECTDIR}/os/arch/mips/src/common/up_releasestack.o.d ${OBJECTDIR}/os/arch/mips/src/common/up_stackframe.o.d ${OBJECTDIR}/os/arch/mips/src/common/up_udelay.o.d ${OBJECTDIR}/os/arch/mips/src/common/up_usestack.o.d ${OBJECTDIR}/os/arch/mips/src/mips32/up_assert.o.d ${OBJECTDIR}/os/arch/mips/src/mips32/up_blocktask.o.d ${OBJECTDIR}/os/arch/mips/src/mips32/up_copystate.o.d ${OBJECTDIR}/os/arch/mips/src/mips32/up_doirq.o.d ${OBJECTDIR}/os/arch/mips/src/mips32/up_dumpstate.o.d ${OBJECTDIR}/os/arch/mips/src/mips32/up_initialstate.o.d ${OBJECTDIR}/os/arch/mips/src/mips32/up_irq.o.d ${OBJECTDIR}/os/arch/mips/src/mips32/up_releasepending.o.d ${OBJECTDIR}/os/arch/mips/src/mips32/up_reprioritizertr.o.d ${OBJECTDIR}/os/arch/mips/src/mips32/up_schedulesigaction.o.d ${OBJECTDIR}/os/arch/mips/src/mips32/up_sigdeliver.o.d ${OBJECTDIR}/os/arch/mips/src/mips32/up_swint0.o.d ${OBJECTDIR}/os/arch/mips/src/mips32/up_unblocktask.o.d ${OBJECTDIR}/os/arch/mips/src/mips32/up_vfork.o.d ${OBJECTDIR}/os/arch/mips/src/mips32/up_syscall0.o.d ${OBJECTDIR}/os/arch/mips/src/mips32/vfork.o.d ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-decodeirq.o.d ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-ethernet.o.d ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-exception.o.d ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpio.o.d ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpioirq.o.d ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-irq.o.d ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowconsole.o.d ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowinit.o.d ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-serial.o.d ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-spi.o.d ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-timerisr.o.d ${OBJECTDIR}/os/arch/mips/src/pic32mz/crt0.o.d ${OBJECTDIR}/os/drivers/bch/bch.o.d ${OBJECTDIR}/os/drivers/serial/lowconsole.o.d ${OBJECTDIR}/os/drivers/serial/serial.o.d ${OBJECTDIR}/os/drivers/serial/serialirq.o.d ${OBJECTDIR}/os/drivers/syslog/ramlog.o.d ${OBJECTDIR}/os/drivers/syslog/syslog_console.o.d ${OBJECTDIR}/os/fs/aio/fs_aio.o.d ${OBJECTDIR}/os/fs/dirent/fs_dirent.o.d ${OBJECTDIR}/os/fs/driver/block/fs_block.o.d ${OBJECTDIR}/os/fs/driver/block/ramdisk.o.d ${OBJECTDIR}/os/fs/inode/fs_inode.o.d ${OBJECTDIR}/os/fs/mount/fs_mount.o.d ${OBJECTDIR}/os/fs/vfs/vfs.o.d ${OBJECTDIR}/os/fs/fs_initialize.o.d ${OBJECTDIR}/os/kernel/clock/clock.o.d ${OBJECTDIR}/os/kernel/clock/clock_abstime2ticks.o.d ${OBJECTDIR}/os/kernel/clock/clock_dow.o.d ${OBJECTDIR}/os/kernel/clock/clock_getres.o.d ${OBJECTDIR}/os/kernel/clock/clock_gettime.o.d ${OBJECTDIR}/os/kernel/clock/clock_gettimeofday.o.d ${OBJECTDIR}/os/kernel/clock/clock_initialize.o.d ${OBJECTDIR}/os/kernel/clock/clock_settime.o.d ${OBJECTDIR}/os/kernel/clock/clock_systimer.o.d ${OBJECTDIR}/os/kernel/clock/clock_systimespec.o.d ${OBJECTDIR}/os/kernel/clock/clock_ticks2time.o.d ${OBJECTDIR}/os/kernel/clock/clock_time2ticks.o.d ${OBJECTDIR}/os/kernel/debug/sysdbg.o.d ${OBJECTDIR}/os/kernel/environ/env_clearenv.o.d ${OBJECTDIR}/os/kernel/environ/env_dup.o.d ${OBJECTDIR}/os/kernel/environ/env_findvar.o.d ${OBJECTDIR}/os/kernel/environ/env_getenv.o.d ${OBJECTDIR}/os/kernel/environ/env_getenvironptr.o.d ${OBJECTDIR}/os/kernel/environ/env_putenv.o.d ${OBJECTDIR}/os/kernel/environ/env_release.o.d ${OBJECTDIR}/os/kernel/environ/env_removevar.o.d ${OBJECTDIR}/os/kernel/environ/env_setenv.o.d ${OBJECTDIR}/os/kernel/environ/env_unsetenv.o.d ${OBJECTDIR}/os/kernel/errno/errno_get.o.d ${OBJECTDIR}/os/kernel/errno/errno_getptr.o.d ${OBJECTDIR}/os/kernel/errno/errno_set.o.d ${OBJECTDIR}/os/kernel/group/group_addrenv.o.d ${OBJECTDIR}/os/kernel/group/group_childstatus.o.d ${OBJECTDIR}/os/kernel/group/group_create.o.d ${OBJECTDIR}/os/kernel/group/group_find.o.d ${OBJECTDIR}/os/kernel/group/group_foreachchild.o.d ${OBJECTDIR}/os/kernel/group/group_free.o.d ${OBJECTDIR}/os/kernel/group/group_join.o.d ${OBJECTDIR}/os/kernel/group/group_killchildren.o.d ${OBJECTDIR}/os/kernel/group/group_leave.o.d ${OBJECTDIR}/os/kernel/group/group_malloc.o.d ${OBJECTDIR}/os/kernel/group/group_setupidlefiles.o.d ${OBJECTDIR}/os/kernel/group/group_setupstreams.o.d ${OBJECTDIR}/os/kernel/group/group_setuptaskfiles.o.d ${OBJECTDIR}/os/kernel/group/group_signal.o.d ${OBJECTDIR}/os/kernel/group/group_zalloc.o.d ${OBJECTDIR}/os/kernel/init/os_bringup.o.d ${OBJECTDIR}/os/kernel/init/os_start.o.d ${OBJECTDIR}/os/kernel/irq/irq_attach.o.d ${OBJECTDIR}/os/kernel/irq/irq_dispatch.o.d ${OBJECTDIR}/os/kernel/irq/irq_info.o.d ${OBJECTDIR}/os/kernel/irq/irq_initialize.o.d ${OBJECTDIR}/os/kernel/irq/irq_unexpectedisr.o.d ${OBJECTDIR}/os/kernel/paging/pg_miss.o.d ${OBJECTDIR}/os/kernel/paging/pg_worker.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_cancel.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_cleanup.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_completejoin.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_condbroadcast.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_condsignal.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_condtimedwait.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_condwait.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_create.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_detach.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_exit.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_findjoininfo.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_getschedparam.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_getspecific.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_initialize.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_join.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_keycreate.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_keydelete.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_keydestroy.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_kill.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_mutex.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_mutexconsistent.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_mutexdestroy.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_mutexinconsistent.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_mutexinit.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_mutexlock.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_mutextrylock.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_mutexunlock.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_release.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_setschedparam.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_setschedprio.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_setspecific.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_sigmask.o.d ${OBJECTDIR}/os/kernel/pthread/pthread_tryjoin_np.o.d ${OBJECTDIR}/os/kernel/sched/sched_addblocked.o.d ${OBJECTDIR}/os/kernel/sched/sched_addprioritized.o.d ${OBJECTDIR}/os/kernel/sched/sched_addreadytorun.o.d ${OBJECTDIR}/os/kernel/sched/sched_cpuload.o.d ${OBJECTDIR}/os/kernel/sched/sched_foreach.o.d ${OBJECTDIR}/os/kernel/sched/sched_free.o.d ${OBJECTDIR}/os/kernel/sched/sched_garbage.o.d ${OBJECTDIR}/os/kernel/sched/sched_getfiles.o.d ${OBJECTDIR}/os/kernel/sched/sched_getparam.o.d ${OBJECTDIR}/os/kernel/sched/sched_getscheduler.o.d ${OBJECTDIR}/os/kernel/sched/sched_getsockets.o.d ${OBJECTDIR}/os/kernel/sched/sched_getstreams.o.d ${OBJECTDIR}/os/kernel/sched/sched_gettcb.o.d ${OBJECTDIR}/os/kernel/sched/sched_lock.o.d ${OBJECTDIR}/os/kernel/sched/sched_lockcount.o.d ${OBJECTDIR}/os/kernel/sched/sched_mergepending.o.d ${OBJECTDIR}/os/kernel/sched/sched_processtimer.o.d ${OBJECTDIR}/os/kernel/sched/sched_releasetcb.o.d ${OBJECTDIR}/os/kernel/sched/sched_removeblocked.o.d ${OBJECTDIR}/os/kernel/sched/sched_removereadytorun.o.d ${OBJECTDIR}/os/kernel/sched/sched_reprioritize.o.d ${OBJECTDIR}/os/kernel/sched/sched_rrgetinterval.o.d ${OBJECTDIR}/os/kernel/sched/sched_self.o.d ${OBJECTDIR}/os/kernel/sched/sched_setparam.o.d ${OBJECTDIR}/os/kernel/sched/sched_setpriority.o.d ${OBJECTDIR}/os/kernel/sched/sched_setscheduler.o.d ${OBJECTDIR}/os/kernel/sched/sched_timerexpiration.o.d ${OBJECTDIR}/os/kernel/sched/sched_unlock.o.d ${OBJECTDIR}/os/kernel/sched/sched_verifytcb.o.d ${OBJECTDIR}/os/kernel/sched/sched_wait.o.d ${OBJECTDIR}/os/kernel/sched/sched_waitid.o.d ${OBJECTDIR}/os/kernel/sched/sched_waitpid.o.d ${OBJECTDIR}/os/kernel/sched/sched_yield.o.d ${OBJECTDIR}/os/kernel/semaphore/sem_destroy.o.d ${OBJECTDIR}/os/kernel/semaphore/sem_holder.o.d ${OBJECTDIR}/os/kernel/semaphore/sem_initialize.o.d ${OBJECTDIR}/os/kernel/semaphore/sem_post.o.d ${OBJECTDIR}/os/kernel/semaphore/sem_recover.o.d ${OBJECTDIR}/os/kernel/semaphore/sem_reset.o.d ${OBJECTDIR}/os/kernel/semaphore/sem_setprotocol.o.d ${OBJECTDIR}/os/kernel/semaphore/sem_tickwait.o.d ${OBJECTDIR}/os/kernel/semaphore/sem_timedwait.o.d ${OBJECTDIR}/os/kernel/semaphore/sem_trywait.o.d ${OBJECTDIR}/os/kernel/semaphore/sem_wait.o.d ${OBJECTDIR}/os/kernel/semaphore/sem_waitirq.o.d ${OBJECTDIR}/os/kernel/signal/sig_action.o.d ${OBJECTDIR}/os/kernel/signal/sig_allocatependingsigaction.o.d ${OBJECTDIR}/os/kernel/signal/sig_cleanup.o.d ${OBJECTDIR}/os/kernel/signal/sig_deliver.o.d ${OBJECTDIR}/os/kernel/signal/sig_dispatch.o.d ${OBJECTDIR}/os/kernel/signal/sig_findaction.o.d ${OBJECTDIR}/os/kernel/signal/sig_initialize.o.d ${OBJECTDIR}/os/kernel/signal/sig_is_handler_registered.o.d ${OBJECTDIR}/os/kernel/signal/sig_kill.o.d ${OBJECTDIR}/os/kernel/signal/sig_lowest.o.d ${OBJECTDIR}/os/kernel/signal/sig_mqnotempty.o.d ${OBJECTDIR}/os/kernel/signal/sig_nanosleep.o.d ${OBJECTDIR}/os/kernel/signal/sig_pause.o.d ${OBJECTDIR}/os/kernel/signal/sig_pending.o.d ${OBJECTDIR}/os/kernel/signal/sig_procmask.o.d ${OBJECTDIR}/os/kernel/signal/sig_queue.o.d ${OBJECTDIR}/os/kernel/signal/sig_releasependingsigaction.o.d ${OBJECTDIR}/os/kernel/signal/sig_releasependingsignal.o.d ${OBJECTDIR}/os/kernel/signal/sig_removependingsignal.o.d ${OBJECTDIR}/os/kernel/signal/sig_sethandler.o.d ${OBJECTDIR}/os/kernel/signal/sig_suspend.o.d ${OBJECTDIR}/os/kernel/signal/sig_timedwait.o.d ${OBJECTDIR}/os/kernel/signal/sig_unmaskpendingsignal.o.d ${OBJECTDIR}/os/kernel/signal/sig_waitinfo.o.d ${OBJECTDIR}/os/kernel/task/exit.o.d ${OBJECTDIR}/os/kernel/task/task_activate.o.d ${OBJECTDIR}/os/kernel/task/task_atexit.o.d ${OBJECTDIR}/os/kernel/task/task_cancelpt.o.d ${OBJECTDIR}/os/kernel/task/task_create.o.d ${OBJECTDIR}/os/kernel/task/task_delete.o.d ${OBJECTDIR}/os/kernel/task/task_execv.o.d ${OBJECTDIR}/os/kernel/task/task_exit.o.d ${OBJECTDIR}/os/kernel/task/task_exithook.o.d ${OBJECTDIR}/os/kernel/task/task_getgroup.o.d ${OBJECTDIR}/os/kernel/task/task_getpid.o.d ${OBJECTDIR}/os/kernel/task/task_init.o.d ${OBJECTDIR}/os/kernel/task/task_onexit.o.d ${OBJECTDIR}/os/kernel/task/task_prctl.o.d ${OBJECTDIR}/os/kernel/task/task_recover.o.d ${OBJECTDIR}/os/kernel/task/task_reparent.o.d ${OBJECTDIR}/os/kernel/task/task_restart.o.d ${OBJECTDIR}/os/kernel/task/task_setcancelstate.o.d ${OBJECTDIR}/os/kernel/task/task_setcanceltype.o.d ${OBJECTDIR}/os/kernel/task/task_setup.o.d ${OBJECTDIR}/os/kernel/task/task_start.o.d ${OBJECTDIR}/os/kernel/task/task_starthook.o.d ${OBJECTDIR}/os/kernel/task/task_terminate.o.d ${OBJECTDIR}/os/kernel/task/task_testcancel.o.d ${OBJECTDIR}/os/kernel/task/task_vfork.o.d ${OBJECTDIR}/os/kernel/timer/timer_create.o.d ${OBJECTDIR}/os/kernel/timer/timer_delete.o.d ${OBJECTDIR}/os/kernel/timer/timer_getoverrun.o.d ${OBJECTDIR}/os/kernel/timer/timer_gettime.o.d ${OBJECTDIR}/os/kernel/timer/timer_initialize.o.d ${OBJECTDIR}/os/kernel/timer/timer_release.o.d ${OBJECTDIR}/os/kernel/timer/timer_settime.o.d ${OBJECTDIR}/os/kernel/wdog/wd_cancel.o.d ${OBJECTDIR}/os/kernel/wdog/wd_create.o.d ${OBJECTDIR}/os/kernel/wdog/wd_delete.o.d ${OBJECTDIR}/os/kernel/wdog/wd_gettime.o.d ${OBJECTDIR}/os/kernel/wdog/wd_initialize.o.d ${OBJECTDIR}/os/kernel/wdog/wd_recover.o.d ${OBJECTDIR}/os/kernel/wdog/wd_start.o.d ${OBJECTDIR}/os/mm/kmm_heap/kmm.o.d ${OBJECTDIR}/os/mm/mm_heap/mm_heap.o.d ${OBJECTDIR}/os/mm/umm_heap/umm.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/os/arch/HELP.o.d ${OBJECTDIR}/sys_config.o.d ${OBJECTDIR}/os/drivers/dev_null.o.d ${OBJECTDIR}/os/drivers/dev_zero.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/lib/libc/aio/wiz_aio.o ${OBJECTDIR}/lib/libc/audio/lib_buffer.o ${OBJECTDIR}/lib/libc/dirent/wiz_dirent.o ${OBJECTDIR}/lib/libc/fixedmath/wiz_fixedmath.o ${OBJECTDIR}/lib/libc/inttypes/wiz_inttipes.o ${OBJECTDIR}/lib/libc/libgen/wiz_libgen.o ${OBJECTDIR}/lib/libc/locale/wiz_locale.o ${OBJECTDIR}/lib/libc/math/fpclassify.o ${OBJECTDIR}/lib/libc/misc/wiz_misc.o ${OBJECTDIR}/lib/libc/mqueue/wiz_mqueue.o ${OBJECTDIR}/lib/libc/net/wiz_net.o ${OBJECTDIR}/lib/libc/pthread/wiz_pthread.o ${OBJECTDIR}/lib/libc/queue/wiz_queue.o ${OBJECTDIR}/lib/libc/sched/wiz_sched.o ${OBJECTDIR}/lib/libc/semaphore/wiz_semaphore.o ${OBJECTDIR}/lib/libc/signal/wiz_signal.o ${OBJECTDIR}/lib/libc/stdio/wiz_stdio.o ${OBJECTDIR}/lib/libc/stdlib/wiz_stdlib.o ${OBJECTDIR}/lib/libc/string/wiz_string.o ${OBJECTDIR}/lib/libc/syslog/wiz_syslog.o ${OBJECTDIR}/lib/libc/termios/wiz_termios.o ${OBJECTDIR}/lib/libc/time/wiz_time.o ${OBJECTDIR}/lib/libc/unistd/wiz_unistd.o ${OBJECTDIR}/lib/libc/wchar/wiz_wchar.o ${OBJECTDIR}/lib/libc/wctype/wiz_wctype.o ${OBJECTDIR}/lib/libc/wqueue/wiz_wqueue.o ${OBJECTDIR}/lib/libxx/libxx_newlib_impure.o ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_boot.o ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_userleds.o ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_autoleds.o ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_bringup.o ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_buttons.o ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_nsh.o ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_spi.o ${OBJECTDIR}/os/arch/mips/src/common/up_allocateheap.o ${OBJECTDIR}/os/arch/mips/src/common/up_createstack.o ${OBJECTDIR}/os/arch/mips/src/common/up_etherstub.o ${OBJECTDIR}/os/arch/mips/src/common/up_exit.o ${OBJECTDIR}/os/arch/mips/src/common/up_idle.o ${OBJECTDIR}/os/arch/mips/src/common/up_initialize.o ${OBJECTDIR}/os/arch/mips/src/common/up_interruptcontext.o ${OBJECTDIR}/os/arch/mips/src/common/up_lowputs.o ${OBJECTDIR}/os/arch/mips/src/common/up_mdelay.o ${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg16.o ${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg32.o ${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg8.o ${OBJECTDIR}/os/arch/mips/src/common/up_puts.o ${OBJECTDIR}/os/arch/mips/src/common/up_releasestack.o ${OBJECTDIR}/os/arch/mips/src/common/up_stackframe.o ${OBJECTDIR}/os/arch/mips/src/common/up_udelay.o ${OBJECTDIR}/os/arch/mips/src/common/up_usestack.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_assert.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_blocktask.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_copystate.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_doirq.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_dumpstate.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_initialstate.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_irq.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_releasepending.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_reprioritizertr.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_schedulesigaction.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_sigdeliver.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_swint0.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_unblocktask.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_vfork.o ${OBJECTDIR}/os/arch/mips/src/mips32/up_syscall0.o ${OBJECTDIR}/os/arch/mips/src/mips32/vfork.o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-decodeirq.o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-ethernet.o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-exception.o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpio.o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpioirq.o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-irq.o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowconsole.o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowinit.o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-serial.o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-spi.o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-timerisr.o ${OBJECTDIR}/os/arch/mips/src/pic32mz/crt0.o ${OBJECTDIR}/os/drivers/bch/bch.o ${OBJECTDIR}/os/drivers/serial/lowconsole.o ${OBJECTDIR}/os/drivers/serial/serial.o ${OBJECTDIR}/os/drivers/serial/serialirq.o ${OBJECTDIR}/os/drivers/syslog/ramlog.o ${OBJECTDIR}/os/drivers/syslog/syslog_console.o ${OBJECTDIR}/os/fs/aio/fs_aio.o ${OBJECTDIR}/os/fs/dirent/fs_dirent.o ${OBJECTDIR}/os/fs/driver/block/fs_block.o ${OBJECTDIR}/os/fs/driver/block/ramdisk.o ${OBJECTDIR}/os/fs/inode/fs_inode.o ${OBJECTDIR}/os/fs/mount/fs_mount.o ${OBJECTDIR}/os/fs/vfs/vfs.o ${OBJECTDIR}/os/fs/fs_initialize.o ${OBJECTDIR}/os/kernel/clock/clock.o ${OBJECTDIR}/os/kernel/clock/clock_abstime2ticks.o ${OBJECTDIR}/os/kernel/clock/clock_dow.o ${OBJECTDIR}/os/kernel/clock/clock_getres.o ${OBJECTDIR}/os/kernel/clock/clock_gettime.o ${OBJECTDIR}/os/kernel/clock/clock_gettimeofday.o ${OBJECTDIR}/os/kernel/clock/clock_initialize.o ${OBJECTDIR}/os/kernel/clock/clock_settime.o ${OBJECTDIR}/os/kernel/clock/clock_systimer.o ${OBJECTDIR}/os/kernel/clock/clock_systimespec.o ${OBJECTDIR}/os/kernel/clock/clock_ticks2time.o ${OBJECTDIR}/os/kernel/clock/clock_time2ticks.o ${OBJECTDIR}/os/kernel/debug/sysdbg.o ${OBJECTDIR}/os/kernel/environ/env_clearenv.o ${OBJECTDIR}/os/kernel/environ/env_dup.o ${OBJECTDIR}/os/kernel/environ/env_findvar.o ${OBJECTDIR}/os/kernel/environ/env_getenv.o ${OBJECTDIR}/os/kernel/environ/env_getenvironptr.o ${OBJECTDIR}/os/kernel/environ/env_putenv.o ${OBJECTDIR}/os/kernel/environ/env_release.o ${OBJECTDIR}/os/kernel/environ/env_removevar.o ${OBJECTDIR}/os/kernel/environ/env_setenv.o ${OBJECTDIR}/os/kernel/environ/env_unsetenv.o ${OBJECTDIR}/os/kernel/errno/errno_get.o ${OBJECTDIR}/os/kernel/errno/errno_getptr.o ${OBJECTDIR}/os/kernel/errno/errno_set.o ${OBJECTDIR}/os/kernel/group/group_addrenv.o ${OBJECTDIR}/os/kernel/group/group_childstatus.o ${OBJECTDIR}/os/kernel/group/group_create.o ${OBJECTDIR}/os/kernel/group/group_find.o ${OBJECTDIR}/os/kernel/group/group_foreachchild.o ${OBJECTDIR}/os/kernel/group/group_free.o ${OBJECTDIR}/os/kernel/group/group_join.o ${OBJECTDIR}/os/kernel/group/group_killchildren.o ${OBJECTDIR}/os/kernel/group/group_leave.o ${OBJECTDIR}/os/kernel/group/group_malloc.o ${OBJECTDIR}/os/kernel/group/group_setupidlefiles.o ${OBJECTDIR}/os/kernel/group/group_setupstreams.o ${OBJECTDIR}/os/kernel/group/group_setuptaskfiles.o ${OBJECTDIR}/os/kernel/group/group_signal.o ${OBJECTDIR}/os/kernel/group/group_zalloc.o ${OBJECTDIR}/os/kernel/init/os_bringup.o ${OBJECTDIR}/os/kernel/init/os_start.o ${OBJECTDIR}/os/kernel/irq/irq_attach.o ${OBJECTDIR}/os/kernel/irq/irq_dispatch.o ${OBJECTDIR}/os/kernel/irq/irq_info.o ${OBJECTDIR}/os/kernel/irq/irq_initialize.o ${OBJECTDIR}/os/kernel/irq/irq_unexpectedisr.o ${OBJECTDIR}/os/kernel/paging/pg_miss.o ${OBJECTDIR}/os/kernel/paging/pg_worker.o ${OBJECTDIR}/os/kernel/pthread/pthread_cancel.o ${OBJECTDIR}/os/kernel/pthread/pthread_cleanup.o ${OBJECTDIR}/os/kernel/pthread/pthread_completejoin.o ${OBJECTDIR}/os/kernel/pthread/pthread_condbroadcast.o ${OBJECTDIR}/os/kernel/pthread/pthread_condsignal.o ${OBJECTDIR}/os/kernel/pthread/pthread_condtimedwait.o ${OBJECTDIR}/os/kernel/pthread/pthread_condwait.o ${OBJECTDIR}/os/kernel/pthread/pthread_create.o ${OBJECTDIR}/os/kernel/pthread/pthread_detach.o ${OBJECTDIR}/os/kernel/pthread/pthread_exit.o ${OBJECTDIR}/os/kernel/pthread/pthread_findjoininfo.o ${OBJECTDIR}/os/kernel/pthread/pthread_getschedparam.o ${OBJECTDIR}/os/kernel/pthread/pthread_getspecific.o ${OBJECTDIR}/os/kernel/pthread/pthread_initialize.o ${OBJECTDIR}/os/kernel/pthread/pthread_join.o ${OBJECTDIR}/os/kernel/pthread/pthread_keycreate.o ${OBJECTDIR}/os/kernel/pthread/pthread_keydelete.o ${OBJECTDIR}/os/kernel/pthread/pthread_keydestroy.o ${OBJECTDIR}/os/kernel/pthread/pthread_kill.o ${OBJECTDIR}/os/kernel/pthread/pthread_mutex.o ${OBJECTDIR}/os/kernel/pthread/pthread_mutexconsistent.o ${OBJECTDIR}/os/kernel/pthread/pthread_mutexdestroy.o ${OBJECTDIR}/os/kernel/pthread/pthread_mutexinconsistent.o ${OBJECTDIR}/os/kernel/pthread/pthread_mutexinit.o ${OBJECTDIR}/os/kernel/pthread/pthread_mutexlock.o ${OBJECTDIR}/os/kernel/pthread/pthread_mutextrylock.o ${OBJECTDIR}/os/kernel/pthread/pthread_mutexunlock.o ${OBJECTDIR}/os/kernel/pthread/pthread_release.o ${OBJECTDIR}/os/kernel/pthread/pthread_setschedparam.o ${OBJECTDIR}/os/kernel/pthread/pthread_setschedprio.o ${OBJECTDIR}/os/kernel/pthread/pthread_setspecific.o ${OBJECTDIR}/os/kernel/pthread/pthread_sigmask.o ${OBJECTDIR}/os/kernel/pthread/pthread_tryjoin_np.o ${OBJECTDIR}/os/kernel/sched/sched_addblocked.o ${OBJECTDIR}/os/kernel/sched/sched_addprioritized.o ${OBJECTDIR}/os/kernel/sched/sched_addreadytorun.o ${OBJECTDIR}/os/kernel/sched/sched_cpuload.o ${OBJECTDIR}/os/kernel/sched/sched_foreach.o ${OBJECTDIR}/os/kernel/sched/sched_free.o ${OBJECTDIR}/os/kernel/sched/sched_garbage.o ${OBJECTDIR}/os/kernel/sched/sched_getfiles.o ${OBJECTDIR}/os/kernel/sched/sched_getparam.o ${OBJECTDIR}/os/kernel/sched/sched_getscheduler.o ${OBJECTDIR}/os/kernel/sched/sched_getsockets.o ${OBJECTDIR}/os/kernel/sched/sched_getstreams.o ${OBJECTDIR}/os/kernel/sched/sched_gettcb.o ${OBJECTDIR}/os/kernel/sched/sched_lock.o ${OBJECTDIR}/os/kernel/sched/sched_lockcount.o ${OBJECTDIR}/os/kernel/sched/sched_mergepending.o ${OBJECTDIR}/os/kernel/sched/sched_processtimer.o ${OBJECTDIR}/os/kernel/sched/sched_releasetcb.o ${OBJECTDIR}/os/kernel/sched/sched_removeblocked.o ${OBJECTDIR}/os/kernel/sched/sched_removereadytorun.o ${OBJECTDIR}/os/kernel/sched/sched_reprioritize.o ${OBJECTDIR}/os/kernel/sched/sched_rrgetinterval.o ${OBJECTDIR}/os/kernel/sched/sched_self.o ${OBJECTDIR}/os/kernel/sched/sched_setparam.o ${OBJECTDIR}/os/kernel/sched/sched_setpriority.o ${OBJECTDIR}/os/kernel/sched/sched_setscheduler.o ${OBJECTDIR}/os/kernel/sched/sched_timerexpiration.o ${OBJECTDIR}/os/kernel/sched/sched_unlock.o ${OBJECTDIR}/os/kernel/sched/sched_verifytcb.o ${OBJECTDIR}/os/kernel/sched/sched_wait.o ${OBJECTDIR}/os/kernel/sched/sched_waitid.o ${OBJECTDIR}/os/kernel/sched/sched_waitpid.o ${OBJECTDIR}/os/kernel/sched/sched_yield.o ${OBJECTDIR}/os/kernel/semaphore/sem_destroy.o ${OBJECTDIR}/os/kernel/semaphore/sem_holder.o ${OBJECTDIR}/os/kernel/semaphore/sem_initialize.o ${OBJECTDIR}/os/kernel/semaphore/sem_post.o ${OBJECTDIR}/os/kernel/semaphore/sem_recover.o ${OBJECTDIR}/os/kernel/semaphore/sem_reset.o ${OBJECTDIR}/os/kernel/semaphore/sem_setprotocol.o ${OBJECTDIR}/os/kernel/semaphore/sem_tickwait.o ${OBJECTDIR}/os/kernel/semaphore/sem_timedwait.o ${OBJECTDIR}/os/kernel/semaphore/sem_trywait.o ${OBJECTDIR}/os/kernel/semaphore/sem_wait.o ${OBJECTDIR}/os/kernel/semaphore/sem_waitirq.o ${OBJECTDIR}/os/kernel/signal/sig_action.o ${OBJECTDIR}/os/kernel/signal/sig_allocatependingsigaction.o ${OBJECTDIR}/os/kernel/signal/sig_cleanup.o ${OBJECTDIR}/os/kernel/signal/sig_deliver.o ${OBJECTDIR}/os/kernel/signal/sig_dispatch.o ${OBJECTDIR}/os/kernel/signal/sig_findaction.o ${OBJECTDIR}/os/kernel/signal/sig_initialize.o ${OBJECTDIR}/os/kernel/signal/sig_is_handler_registered.o ${OBJECTDIR}/os/kernel/signal/sig_kill.o ${OBJECTDIR}/os/kernel/signal/sig_lowest.o ${OBJECTDIR}/os/kernel/signal/sig_mqnotempty.o ${OBJECTDIR}/os/kernel/signal/sig_nanosleep.o ${OBJECTDIR}/os/kernel/signal/sig_pause.o ${OBJECTDIR}/os/kernel/signal/sig_pending.o ${OBJECTDIR}/os/kernel/signal/sig_procmask.o ${OBJECTDIR}/os/kernel/signal/sig_queue.o ${OBJECTDIR}/os/kernel/signal/sig_releasependingsigaction.o ${OBJECTDIR}/os/kernel/signal/sig_releasependingsignal.o ${OBJECTDIR}/os/kernel/signal/sig_removependingsignal.o ${OBJECTDIR}/os/kernel/signal/sig_sethandler.o ${OBJECTDIR}/os/kernel/signal/sig_suspend.o ${OBJECTDIR}/os/kernel/signal/sig_timedwait.o ${OBJECTDIR}/os/kernel/signal/sig_unmaskpendingsignal.o ${OBJECTDIR}/os/kernel/signal/sig_waitinfo.o ${OBJECTDIR}/os/kernel/task/exit.o ${OBJECTDIR}/os/kernel/task/task_activate.o ${OBJECTDIR}/os/kernel/task/task_atexit.o ${OBJECTDIR}/os/kernel/task/task_cancelpt.o ${OBJECTDIR}/os/kernel/task/task_create.o ${OBJECTDIR}/os/kernel/task/task_delete.o ${OBJECTDIR}/os/kernel/task/task_execv.o ${OBJECTDIR}/os/kernel/task/task_exit.o ${OBJECTDIR}/os/kernel/task/task_exithook.o ${OBJECTDIR}/os/kernel/task/task_getgroup.o ${OBJECTDIR}/os/kernel/task/task_getpid.o ${OBJECTDIR}/os/kernel/task/task_init.o ${OBJECTDIR}/os/kernel/task/task_onexit.o ${OBJECTDIR}/os/kernel/task/task_prctl.o ${OBJECTDIR}/os/kernel/task/task_recover.o ${OBJECTDIR}/os/kernel/task/task_reparent.o ${OBJECTDIR}/os/kernel/task/task_restart.o ${OBJECTDIR}/os/kernel/task/task_setcancelstate.o ${OBJECTDIR}/os/kernel/task/task_setcanceltype.o ${OBJECTDIR}/os/kernel/task/task_setup.o ${OBJECTDIR}/os/kernel/task/task_start.o ${OBJECTDIR}/os/kernel/task/task_starthook.o ${OBJECTDIR}/os/kernel/task/task_terminate.o ${OBJECTDIR}/os/kernel/task/task_testcancel.o ${OBJECTDIR}/os/kernel/task/task_vfork.o ${OBJECTDIR}/os/kernel/timer/timer_create.o ${OBJECTDIR}/os/kernel/timer/timer_delete.o ${OBJECTDIR}/os/kernel/timer/timer_getoverrun.o ${OBJECTDIR}/os/kernel/timer/timer_gettime.o ${OBJECTDIR}/os/kernel/timer/timer_initialize.o ${OBJECTDIR}/os/kernel/timer/timer_release.o ${OBJECTDIR}/os/kernel/timer/timer_settime.o ${OBJECTDIR}/os/kernel/wdog/wd_cancel.o ${OBJECTDIR}/os/kernel/wdog/wd_create.o ${OBJECTDIR}/os/kernel/wdog/wd_delete.o ${OBJECTDIR}/os/kernel/wdog/wd_gettime.o ${OBJECTDIR}/os/kernel/wdog/wd_initialize.o ${OBJECTDIR}/os/kernel/wdog/wd_recover.o ${OBJECTDIR}/os/kernel/wdog/wd_start.o ${OBJECTDIR}/os/mm/kmm_heap/kmm.o ${OBJECTDIR}/os/mm/mm_heap/mm_heap.o ${OBJECTDIR}/os/mm/umm_heap/umm.o ${OBJECTDIR}/main.o ${OBJECTDIR}/os/arch/HELP.o ${OBJECTDIR}/sys_config.o ${OBJECTDIR}/os/drivers/dev_null.o ${OBJECTDIR}/os/drivers/dev_zero.o

# Source Files
SOURCEFILES=lib/libc/aio/wiz_aio.c lib/libc/audio/lib_buffer.c lib/libc/dirent/wiz_dirent.c lib/libc/fixedmath/wiz_fixedmath.c lib/libc/inttypes/wiz_inttipes.c lib/libc/libgen/wiz_libgen.c lib/libc/locale/wiz_locale.c lib/libc/math/fpclassify.c lib/libc/misc/wiz_misc.c lib/libc/mqueue/wiz_mqueue.c lib/libc/net/wiz_net.c lib/libc/pthread/wiz_pthread.c lib/libc/queue/wiz_queue.c lib/libc/sched/wiz_sched.c lib/libc/semaphore/wiz_semaphore.c lib/libc/signal/wiz_signal.c lib/libc/stdio/wiz_stdio.c lib/libc/stdlib/wiz_stdlib.c lib/libc/string/wiz_string.c lib/libc/syslog/wiz_syslog.c lib/libc/termios/wiz_termios.c lib/libc/time/wiz_time.c lib/libc/unistd/wiz_unistd.c lib/libc/wchar/wiz_wchar.c lib/libc/wctype/wiz_wctype.c lib/libc/wqueue/wiz_wqueue.c lib/libxx/libxx_newlib_impure.c os/arch/board/curiosity/pic32mz_boot.c os/arch/board/curiosity/pic32mz_userleds.c os/arch/board/curiosity/pic32mz_autoleds.c os/arch/board/curiosity/pic32mz_bringup.c os/arch/board/curiosity/pic32mz_buttons.c os/arch/board/curiosity/pic32mz_nsh.c os/arch/board/curiosity/pic32mz_spi.c os/arch/mips/src/common/up_allocateheap.c os/arch/mips/src/common/up_createstack.c os/arch/mips/src/common/up_etherstub.c os/arch/mips/src/common/up_exit.c os/arch/mips/src/common/up_idle.c os/arch/mips/src/common/up_initialize.c os/arch/mips/src/common/up_interruptcontext.c os/arch/mips/src/common/up_lowputs.c os/arch/mips/src/common/up_mdelay.c os/arch/mips/src/common/up_modifyreg16.c os/arch/mips/src/common/up_modifyreg32.c os/arch/mips/src/common/up_modifyreg8.c os/arch/mips/src/common/up_puts.c os/arch/mips/src/common/up_releasestack.c os/arch/mips/src/common/up_stackframe.c os/arch/mips/src/common/up_udelay.c os/arch/mips/src/common/up_usestack.c os/arch/mips/src/mips32/up_assert.c os/arch/mips/src/mips32/up_blocktask.c os/arch/mips/src/mips32/up_copystate.c os/arch/mips/src/mips32/up_doirq.c os/arch/mips/src/mips32/up_dumpstate.c os/arch/mips/src/mips32/up_initialstate.c os/arch/mips/src/mips32/up_irq.c os/arch/mips/src/mips32/up_releasepending.c os/arch/mips/src/mips32/up_reprioritizertr.c os/arch/mips/src/mips32/up_schedulesigaction.c os/arch/mips/src/mips32/up_sigdeliver.c os/arch/mips/src/mips32/up_swint0.c os/arch/mips/src/mips32/up_unblocktask.c os/arch/mips/src/mips32/up_vfork.c os/arch/mips/src/mips32/up_syscall0.S os/arch/mips/src/mips32/vfork.S os/arch/mips/src/pic32mz/pic32mz-decodeirq.c os/arch/mips/src/pic32mz/pic32mz-ethernet.c os/arch/mips/src/pic32mz/pic32mz-exception.c os/arch/mips/src/pic32mz/pic32mz-gpio.c os/arch/mips/src/pic32mz/pic32mz-gpioirq.c os/arch/mips/src/pic32mz/pic32mz-irq.c os/arch/mips/src/pic32mz/pic32mz-lowconsole.c os/arch/mips/src/pic32mz/pic32mz-lowinit.c os/arch/mips/src/pic32mz/pic32mz-serial.c os/arch/mips/src/pic32mz/pic32mz-spi.c os/arch/mips/src/pic32mz/pic32mz-timerisr.c os/arch/mips/src/pic32mz/crt0.S os/drivers/bch/bch.c os/drivers/serial/lowconsole.c os/drivers/serial/serial.c os/drivers/serial/serialirq.c os/drivers/syslog/ramlog.c os/drivers/syslog/syslog_console.c os/fs/aio/fs_aio.c os/fs/dirent/fs_dirent.c os/fs/driver/block/fs_block.c os/fs/driver/block/ramdisk.c os/fs/inode/fs_inode.c os/fs/mount/fs_mount.c os/fs/vfs/vfs.c os/fs/fs_initialize.c os/kernel/clock/clock.c os/kernel/clock/clock_abstime2ticks.c os/kernel/clock/clock_dow.c os/kernel/clock/clock_getres.c os/kernel/clock/clock_gettime.c os/kernel/clock/clock_gettimeofday.c os/kernel/clock/clock_initialize.c os/kernel/clock/clock_settime.c os/kernel/clock/clock_systimer.c os/kernel/clock/clock_systimespec.c os/kernel/clock/clock_ticks2time.c os/kernel/clock/clock_time2ticks.c os/kernel/debug/sysdbg.c os/kernel/environ/env_clearenv.c os/kernel/environ/env_dup.c os/kernel/environ/env_findvar.c os/kernel/environ/env_getenv.c os/kernel/environ/env_getenvironptr.c os/kernel/environ/env_putenv.c os/kernel/environ/env_release.c os/kernel/environ/env_removevar.c os/kernel/environ/env_setenv.c os/kernel/environ/env_unsetenv.c os/kernel/errno/errno_get.c os/kernel/errno/errno_getptr.c os/kernel/errno/errno_set.c os/kernel/group/group_addrenv.c os/kernel/group/group_childstatus.c os/kernel/group/group_create.c os/kernel/group/group_find.c os/kernel/group/group_foreachchild.c os/kernel/group/group_free.c os/kernel/group/group_join.c os/kernel/group/group_killchildren.c os/kernel/group/group_leave.c os/kernel/group/group_malloc.c os/kernel/group/group_setupidlefiles.c os/kernel/group/group_setupstreams.c os/kernel/group/group_setuptaskfiles.c os/kernel/group/group_signal.c os/kernel/group/group_zalloc.c os/kernel/init/os_bringup.c os/kernel/init/os_start.c os/kernel/irq/irq_attach.c os/kernel/irq/irq_dispatch.c os/kernel/irq/irq_info.c os/kernel/irq/irq_initialize.c os/kernel/irq/irq_unexpectedisr.c os/kernel/paging/pg_miss.c os/kernel/paging/pg_worker.c os/kernel/pthread/pthread_cancel.c os/kernel/pthread/pthread_cleanup.c os/kernel/pthread/pthread_completejoin.c os/kernel/pthread/pthread_condbroadcast.c os/kernel/pthread/pthread_condsignal.c os/kernel/pthread/pthread_condtimedwait.c os/kernel/pthread/pthread_condwait.c os/kernel/pthread/pthread_create.c os/kernel/pthread/pthread_detach.c os/kernel/pthread/pthread_exit.c os/kernel/pthread/pthread_findjoininfo.c os/kernel/pthread/pthread_getschedparam.c os/kernel/pthread/pthread_getspecific.c os/kernel/pthread/pthread_initialize.c os/kernel/pthread/pthread_join.c os/kernel/pthread/pthread_keycreate.c os/kernel/pthread/pthread_keydelete.c os/kernel/pthread/pthread_keydestroy.c os/kernel/pthread/pthread_kill.c os/kernel/pthread/pthread_mutex.c os/kernel/pthread/pthread_mutexconsistent.c os/kernel/pthread/pthread_mutexdestroy.c os/kernel/pthread/pthread_mutexinconsistent.c os/kernel/pthread/pthread_mutexinit.c os/kernel/pthread/pthread_mutexlock.c os/kernel/pthread/pthread_mutextrylock.c os/kernel/pthread/pthread_mutexunlock.c os/kernel/pthread/pthread_release.c os/kernel/pthread/pthread_setschedparam.c os/kernel/pthread/pthread_setschedprio.c os/kernel/pthread/pthread_setspecific.c os/kernel/pthread/pthread_sigmask.c os/kernel/pthread/pthread_tryjoin_np.c os/kernel/sched/sched_addblocked.c os/kernel/sched/sched_addprioritized.c os/kernel/sched/sched_addreadytorun.c os/kernel/sched/sched_cpuload.c os/kernel/sched/sched_foreach.c os/kernel/sched/sched_free.c os/kernel/sched/sched_garbage.c os/kernel/sched/sched_getfiles.c os/kernel/sched/sched_getparam.c os/kernel/sched/sched_getscheduler.c os/kernel/sched/sched_getsockets.c os/kernel/sched/sched_getstreams.c os/kernel/sched/sched_gettcb.c os/kernel/sched/sched_lock.c os/kernel/sched/sched_lockcount.c os/kernel/sched/sched_mergepending.c os/kernel/sched/sched_processtimer.c os/kernel/sched/sched_releasetcb.c os/kernel/sched/sched_removeblocked.c os/kernel/sched/sched_removereadytorun.c os/kernel/sched/sched_reprioritize.c os/kernel/sched/sched_rrgetinterval.c os/kernel/sched/sched_self.c os/kernel/sched/sched_setparam.c os/kernel/sched/sched_setpriority.c os/kernel/sched/sched_setscheduler.c os/kernel/sched/sched_timerexpiration.c os/kernel/sched/sched_unlock.c os/kernel/sched/sched_verifytcb.c os/kernel/sched/sched_wait.c os/kernel/sched/sched_waitid.c os/kernel/sched/sched_waitpid.c os/kernel/sched/sched_yield.c os/kernel/semaphore/sem_destroy.c os/kernel/semaphore/sem_holder.c os/kernel/semaphore/sem_initialize.c os/kernel/semaphore/sem_post.c os/kernel/semaphore/sem_recover.c os/kernel/semaphore/sem_reset.c os/kernel/semaphore/sem_setprotocol.c os/kernel/semaphore/sem_tickwait.c os/kernel/semaphore/sem_timedwait.c os/kernel/semaphore/sem_trywait.c os/kernel/semaphore/sem_wait.c os/kernel/semaphore/sem_waitirq.c os/kernel/signal/sig_action.c os/kernel/signal/sig_allocatependingsigaction.c os/kernel/signal/sig_cleanup.c os/kernel/signal/sig_deliver.c os/kernel/signal/sig_dispatch.c os/kernel/signal/sig_findaction.c os/kernel/signal/sig_initialize.c os/kernel/signal/sig_is_handler_registered.c os/kernel/signal/sig_kill.c os/kernel/signal/sig_lowest.c os/kernel/signal/sig_mqnotempty.c os/kernel/signal/sig_nanosleep.c os/kernel/signal/sig_pause.c os/kernel/signal/sig_pending.c os/kernel/signal/sig_procmask.c os/kernel/signal/sig_queue.c os/kernel/signal/sig_releasependingsigaction.c os/kernel/signal/sig_releasependingsignal.c os/kernel/signal/sig_removependingsignal.c os/kernel/signal/sig_sethandler.c os/kernel/signal/sig_suspend.c os/kernel/signal/sig_timedwait.c os/kernel/signal/sig_unmaskpendingsignal.c os/kernel/signal/sig_waitinfo.c os/kernel/task/exit.c os/kernel/task/task_activate.c os/kernel/task/task_atexit.c os/kernel/task/task_cancelpt.c os/kernel/task/task_create.c os/kernel/task/task_delete.c os/kernel/task/task_execv.c os/kernel/task/task_exit.c os/kernel/task/task_exithook.c os/kernel/task/task_getgroup.c os/kernel/task/task_getpid.c os/kernel/task/task_init.c os/kernel/task/task_onexit.c os/kernel/task/task_prctl.c os/kernel/task/task_recover.c os/kernel/task/task_reparent.c os/kernel/task/task_restart.c os/kernel/task/task_setcancelstate.c os/kernel/task/task_setcanceltype.c os/kernel/task/task_setup.c os/kernel/task/task_start.c os/kernel/task/task_starthook.c os/kernel/task/task_terminate.c os/kernel/task/task_testcancel.c os/kernel/task/task_vfork.c os/kernel/timer/timer_create.c os/kernel/timer/timer_delete.c os/kernel/timer/timer_getoverrun.c os/kernel/timer/timer_gettime.c os/kernel/timer/timer_initialize.c os/kernel/timer/timer_release.c os/kernel/timer/timer_settime.c os/kernel/wdog/wd_cancel.c os/kernel/wdog/wd_create.c os/kernel/wdog/wd_delete.c os/kernel/wdog/wd_gettime.c os/kernel/wdog/wd_initialize.c os/kernel/wdog/wd_recover.c os/kernel/wdog/wd_start.c os/mm/kmm_heap/kmm.c os/mm/mm_heap/mm_heap.c os/mm/umm_heap/umm.c main.c os/arch/HELP.c sys_config.c os/drivers/dev_null.c os/drivers/dev_zero.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/TIZEN.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MZ2048EFM100
MP_LINKER_FILE_OPTION=,--script="os\arch\board\curiosity\linker\WizIO_p32MZ2048EFM100.ld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/os/arch/mips/src/mips32/up_syscall0.o: os/arch/mips/src/mips32/up_syscall0.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_syscall0.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_syscall0.o 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_syscall0.o.ok ${OBJECTDIR}/os/arch/mips/src/mips32/up_syscall0.o.err 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_syscall0.o.d" "${OBJECTDIR}/os/arch/mips/src/mips32/up_syscall0.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"os" -I"os/include" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_syscall0.o.d"  -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_syscall0.o os/arch/mips/src/mips32/up_syscall0.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/os/arch/mips/src/mips32/up_syscall0.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1
	
${OBJECTDIR}/os/arch/mips/src/mips32/vfork.o: os/arch/mips/src/mips32/vfork.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/vfork.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/vfork.o 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/vfork.o.ok ${OBJECTDIR}/os/arch/mips/src/mips32/vfork.o.err 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/vfork.o.d" "${OBJECTDIR}/os/arch/mips/src/mips32/vfork.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"os" -I"os/include" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/vfork.o.d"  -o ${OBJECTDIR}/os/arch/mips/src/mips32/vfork.o os/arch/mips/src/mips32/vfork.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/os/arch/mips/src/mips32/vfork.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1
	
${OBJECTDIR}/os/arch/mips/src/pic32mz/crt0.o: os/arch/mips/src/pic32mz/crt0.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/pic32mz" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/crt0.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/crt0.o 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/crt0.o.ok ${OBJECTDIR}/os/arch/mips/src/pic32mz/crt0.o.err 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/pic32mz/crt0.o.d" "${OBJECTDIR}/os/arch/mips/src/pic32mz/crt0.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"os" -I"os/include" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/pic32mz/crt0.o.d"  -o ${OBJECTDIR}/os/arch/mips/src/pic32mz/crt0.o os/arch/mips/src/pic32mz/crt0.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/os/arch/mips/src/pic32mz/crt0.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1
	
else
${OBJECTDIR}/os/arch/mips/src/mips32/up_syscall0.o: os/arch/mips/src/mips32/up_syscall0.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_syscall0.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_syscall0.o 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_syscall0.o.ok ${OBJECTDIR}/os/arch/mips/src/mips32/up_syscall0.o.err 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_syscall0.o.d" "${OBJECTDIR}/os/arch/mips/src/mips32/up_syscall0.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"os" -I"os/include" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_syscall0.o.d"  -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_syscall0.o os/arch/mips/src/mips32/up_syscall0.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/os/arch/mips/src/mips32/up_syscall0.o.asm.d",--gdwarf-2
	
${OBJECTDIR}/os/arch/mips/src/mips32/vfork.o: os/arch/mips/src/mips32/vfork.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/vfork.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/vfork.o 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/vfork.o.ok ${OBJECTDIR}/os/arch/mips/src/mips32/vfork.o.err 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/vfork.o.d" "${OBJECTDIR}/os/arch/mips/src/mips32/vfork.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"os" -I"os/include" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/vfork.o.d"  -o ${OBJECTDIR}/os/arch/mips/src/mips32/vfork.o os/arch/mips/src/mips32/vfork.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/os/arch/mips/src/mips32/vfork.o.asm.d",--gdwarf-2
	
${OBJECTDIR}/os/arch/mips/src/pic32mz/crt0.o: os/arch/mips/src/pic32mz/crt0.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/pic32mz" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/crt0.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/crt0.o 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/crt0.o.ok ${OBJECTDIR}/os/arch/mips/src/pic32mz/crt0.o.err 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/pic32mz/crt0.o.d" "${OBJECTDIR}/os/arch/mips/src/pic32mz/crt0.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"os" -I"os/include" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/pic32mz/crt0.o.d"  -o ${OBJECTDIR}/os/arch/mips/src/pic32mz/crt0.o os/arch/mips/src/pic32mz/crt0.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/os/arch/mips/src/pic32mz/crt0.o.asm.d",--gdwarf-2
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/lib/libc/aio/wiz_aio.o: lib/libc/aio/wiz_aio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/aio" 
	@${RM} ${OBJECTDIR}/lib/libc/aio/wiz_aio.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/aio/wiz_aio.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/aio/wiz_aio.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/aio/wiz_aio.o.d" -o ${OBJECTDIR}/lib/libc/aio/wiz_aio.o lib/libc/aio/wiz_aio.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/audio/lib_buffer.o: lib/libc/audio/lib_buffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/audio" 
	@${RM} ${OBJECTDIR}/lib/libc/audio/lib_buffer.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/audio/lib_buffer.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/audio/lib_buffer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/audio/lib_buffer.o.d" -o ${OBJECTDIR}/lib/libc/audio/lib_buffer.o lib/libc/audio/lib_buffer.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/dirent/wiz_dirent.o: lib/libc/dirent/wiz_dirent.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/dirent" 
	@${RM} ${OBJECTDIR}/lib/libc/dirent/wiz_dirent.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/dirent/wiz_dirent.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/dirent/wiz_dirent.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/dirent/wiz_dirent.o.d" -o ${OBJECTDIR}/lib/libc/dirent/wiz_dirent.o lib/libc/dirent/wiz_dirent.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/fixedmath/wiz_fixedmath.o: lib/libc/fixedmath/wiz_fixedmath.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/fixedmath" 
	@${RM} ${OBJECTDIR}/lib/libc/fixedmath/wiz_fixedmath.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/fixedmath/wiz_fixedmath.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/fixedmath/wiz_fixedmath.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/fixedmath/wiz_fixedmath.o.d" -o ${OBJECTDIR}/lib/libc/fixedmath/wiz_fixedmath.o lib/libc/fixedmath/wiz_fixedmath.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/inttypes/wiz_inttipes.o: lib/libc/inttypes/wiz_inttipes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/inttypes" 
	@${RM} ${OBJECTDIR}/lib/libc/inttypes/wiz_inttipes.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/inttypes/wiz_inttipes.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/inttypes/wiz_inttipes.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/inttypes/wiz_inttipes.o.d" -o ${OBJECTDIR}/lib/libc/inttypes/wiz_inttipes.o lib/libc/inttypes/wiz_inttipes.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/libgen/wiz_libgen.o: lib/libc/libgen/wiz_libgen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/libgen" 
	@${RM} ${OBJECTDIR}/lib/libc/libgen/wiz_libgen.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/libgen/wiz_libgen.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/libgen/wiz_libgen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/libgen/wiz_libgen.o.d" -o ${OBJECTDIR}/lib/libc/libgen/wiz_libgen.o lib/libc/libgen/wiz_libgen.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/locale/wiz_locale.o: lib/libc/locale/wiz_locale.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/locale" 
	@${RM} ${OBJECTDIR}/lib/libc/locale/wiz_locale.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/locale/wiz_locale.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/locale/wiz_locale.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/locale/wiz_locale.o.d" -o ${OBJECTDIR}/lib/libc/locale/wiz_locale.o lib/libc/locale/wiz_locale.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/math/fpclassify.o: lib/libc/math/fpclassify.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/math" 
	@${RM} ${OBJECTDIR}/lib/libc/math/fpclassify.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/math/fpclassify.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/math/fpclassify.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/math/fpclassify.o.d" -o ${OBJECTDIR}/lib/libc/math/fpclassify.o lib/libc/math/fpclassify.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/misc/wiz_misc.o: lib/libc/misc/wiz_misc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/misc" 
	@${RM} ${OBJECTDIR}/lib/libc/misc/wiz_misc.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/misc/wiz_misc.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/misc/wiz_misc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/misc/wiz_misc.o.d" -o ${OBJECTDIR}/lib/libc/misc/wiz_misc.o lib/libc/misc/wiz_misc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/mqueue/wiz_mqueue.o: lib/libc/mqueue/wiz_mqueue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/mqueue" 
	@${RM} ${OBJECTDIR}/lib/libc/mqueue/wiz_mqueue.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/mqueue/wiz_mqueue.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/mqueue/wiz_mqueue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/mqueue/wiz_mqueue.o.d" -o ${OBJECTDIR}/lib/libc/mqueue/wiz_mqueue.o lib/libc/mqueue/wiz_mqueue.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/net/wiz_net.o: lib/libc/net/wiz_net.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/net" 
	@${RM} ${OBJECTDIR}/lib/libc/net/wiz_net.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/net/wiz_net.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/net/wiz_net.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/net/wiz_net.o.d" -o ${OBJECTDIR}/lib/libc/net/wiz_net.o lib/libc/net/wiz_net.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/pthread/wiz_pthread.o: lib/libc/pthread/wiz_pthread.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/pthread" 
	@${RM} ${OBJECTDIR}/lib/libc/pthread/wiz_pthread.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/pthread/wiz_pthread.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/pthread/wiz_pthread.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/pthread/wiz_pthread.o.d" -o ${OBJECTDIR}/lib/libc/pthread/wiz_pthread.o lib/libc/pthread/wiz_pthread.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/queue/wiz_queue.o: lib/libc/queue/wiz_queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/queue" 
	@${RM} ${OBJECTDIR}/lib/libc/queue/wiz_queue.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/queue/wiz_queue.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/queue/wiz_queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/queue/wiz_queue.o.d" -o ${OBJECTDIR}/lib/libc/queue/wiz_queue.o lib/libc/queue/wiz_queue.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/sched/wiz_sched.o: lib/libc/sched/wiz_sched.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/sched" 
	@${RM} ${OBJECTDIR}/lib/libc/sched/wiz_sched.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/sched/wiz_sched.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/sched/wiz_sched.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/sched/wiz_sched.o.d" -o ${OBJECTDIR}/lib/libc/sched/wiz_sched.o lib/libc/sched/wiz_sched.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/semaphore/wiz_semaphore.o: lib/libc/semaphore/wiz_semaphore.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/semaphore" 
	@${RM} ${OBJECTDIR}/lib/libc/semaphore/wiz_semaphore.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/semaphore/wiz_semaphore.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/semaphore/wiz_semaphore.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/semaphore/wiz_semaphore.o.d" -o ${OBJECTDIR}/lib/libc/semaphore/wiz_semaphore.o lib/libc/semaphore/wiz_semaphore.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/signal/wiz_signal.o: lib/libc/signal/wiz_signal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/signal" 
	@${RM} ${OBJECTDIR}/lib/libc/signal/wiz_signal.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/signal/wiz_signal.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/signal/wiz_signal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/signal/wiz_signal.o.d" -o ${OBJECTDIR}/lib/libc/signal/wiz_signal.o lib/libc/signal/wiz_signal.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/stdio/wiz_stdio.o: lib/libc/stdio/wiz_stdio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/stdio" 
	@${RM} ${OBJECTDIR}/lib/libc/stdio/wiz_stdio.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/stdio/wiz_stdio.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/stdio/wiz_stdio.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/stdio/wiz_stdio.o.d" -o ${OBJECTDIR}/lib/libc/stdio/wiz_stdio.o lib/libc/stdio/wiz_stdio.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/stdlib/wiz_stdlib.o: lib/libc/stdlib/wiz_stdlib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/stdlib" 
	@${RM} ${OBJECTDIR}/lib/libc/stdlib/wiz_stdlib.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/stdlib/wiz_stdlib.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/stdlib/wiz_stdlib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/stdlib/wiz_stdlib.o.d" -o ${OBJECTDIR}/lib/libc/stdlib/wiz_stdlib.o lib/libc/stdlib/wiz_stdlib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/string/wiz_string.o: lib/libc/string/wiz_string.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/string" 
	@${RM} ${OBJECTDIR}/lib/libc/string/wiz_string.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/string/wiz_string.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/string/wiz_string.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/string/wiz_string.o.d" -o ${OBJECTDIR}/lib/libc/string/wiz_string.o lib/libc/string/wiz_string.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/syslog/wiz_syslog.o: lib/libc/syslog/wiz_syslog.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/syslog" 
	@${RM} ${OBJECTDIR}/lib/libc/syslog/wiz_syslog.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/syslog/wiz_syslog.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/syslog/wiz_syslog.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/syslog/wiz_syslog.o.d" -o ${OBJECTDIR}/lib/libc/syslog/wiz_syslog.o lib/libc/syslog/wiz_syslog.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/termios/wiz_termios.o: lib/libc/termios/wiz_termios.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/termios" 
	@${RM} ${OBJECTDIR}/lib/libc/termios/wiz_termios.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/termios/wiz_termios.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/termios/wiz_termios.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/termios/wiz_termios.o.d" -o ${OBJECTDIR}/lib/libc/termios/wiz_termios.o lib/libc/termios/wiz_termios.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/time/wiz_time.o: lib/libc/time/wiz_time.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/time" 
	@${RM} ${OBJECTDIR}/lib/libc/time/wiz_time.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/time/wiz_time.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/time/wiz_time.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/time/wiz_time.o.d" -o ${OBJECTDIR}/lib/libc/time/wiz_time.o lib/libc/time/wiz_time.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/unistd/wiz_unistd.o: lib/libc/unistd/wiz_unistd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/unistd" 
	@${RM} ${OBJECTDIR}/lib/libc/unistd/wiz_unistd.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/unistd/wiz_unistd.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/unistd/wiz_unistd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/unistd/wiz_unistd.o.d" -o ${OBJECTDIR}/lib/libc/unistd/wiz_unistd.o lib/libc/unistd/wiz_unistd.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/wchar/wiz_wchar.o: lib/libc/wchar/wiz_wchar.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/wchar" 
	@${RM} ${OBJECTDIR}/lib/libc/wchar/wiz_wchar.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/wchar/wiz_wchar.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/wchar/wiz_wchar.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/wchar/wiz_wchar.o.d" -o ${OBJECTDIR}/lib/libc/wchar/wiz_wchar.o lib/libc/wchar/wiz_wchar.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/wctype/wiz_wctype.o: lib/libc/wctype/wiz_wctype.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/wctype" 
	@${RM} ${OBJECTDIR}/lib/libc/wctype/wiz_wctype.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/wctype/wiz_wctype.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/wctype/wiz_wctype.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/wctype/wiz_wctype.o.d" -o ${OBJECTDIR}/lib/libc/wctype/wiz_wctype.o lib/libc/wctype/wiz_wctype.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/wqueue/wiz_wqueue.o: lib/libc/wqueue/wiz_wqueue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/wqueue" 
	@${RM} ${OBJECTDIR}/lib/libc/wqueue/wiz_wqueue.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/wqueue/wiz_wqueue.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/wqueue/wiz_wqueue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/wqueue/wiz_wqueue.o.d" -o ${OBJECTDIR}/lib/libc/wqueue/wiz_wqueue.o lib/libc/wqueue/wiz_wqueue.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libxx/libxx_newlib_impure.o: lib/libxx/libxx_newlib_impure.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libxx" 
	@${RM} ${OBJECTDIR}/lib/libxx/libxx_newlib_impure.o.d 
	@${RM} ${OBJECTDIR}/lib/libxx/libxx_newlib_impure.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libxx/libxx_newlib_impure.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libxx/libxx_newlib_impure.o.d" -o ${OBJECTDIR}/lib/libxx/libxx_newlib_impure.o lib/libxx/libxx_newlib_impure.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/board/curiosity/pic32mz_boot.o: os/arch/board/curiosity/pic32mz_boot.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/board/curiosity" 
	@${RM} ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_boot.o.d 
	@${RM} ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_boot.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/board/curiosity/pic32mz_boot.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/board/curiosity/pic32mz_boot.o.d" -o ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_boot.o os/arch/board/curiosity/pic32mz_boot.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/board/curiosity/pic32mz_userleds.o: os/arch/board/curiosity/pic32mz_userleds.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/board/curiosity" 
	@${RM} ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_userleds.o.d 
	@${RM} ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_userleds.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/board/curiosity/pic32mz_userleds.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/board/curiosity/pic32mz_userleds.o.d" -o ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_userleds.o os/arch/board/curiosity/pic32mz_userleds.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/board/curiosity/pic32mz_autoleds.o: os/arch/board/curiosity/pic32mz_autoleds.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/board/curiosity" 
	@${RM} ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_autoleds.o.d 
	@${RM} ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_autoleds.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/board/curiosity/pic32mz_autoleds.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/board/curiosity/pic32mz_autoleds.o.d" -o ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_autoleds.o os/arch/board/curiosity/pic32mz_autoleds.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/board/curiosity/pic32mz_bringup.o: os/arch/board/curiosity/pic32mz_bringup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/board/curiosity" 
	@${RM} ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_bringup.o.d 
	@${RM} ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_bringup.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/board/curiosity/pic32mz_bringup.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/board/curiosity/pic32mz_bringup.o.d" -o ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_bringup.o os/arch/board/curiosity/pic32mz_bringup.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/board/curiosity/pic32mz_buttons.o: os/arch/board/curiosity/pic32mz_buttons.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/board/curiosity" 
	@${RM} ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_buttons.o.d 
	@${RM} ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_buttons.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/board/curiosity/pic32mz_buttons.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/board/curiosity/pic32mz_buttons.o.d" -o ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_buttons.o os/arch/board/curiosity/pic32mz_buttons.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/board/curiosity/pic32mz_nsh.o: os/arch/board/curiosity/pic32mz_nsh.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/board/curiosity" 
	@${RM} ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_nsh.o.d 
	@${RM} ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_nsh.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/board/curiosity/pic32mz_nsh.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/board/curiosity/pic32mz_nsh.o.d" -o ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_nsh.o os/arch/board/curiosity/pic32mz_nsh.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/board/curiosity/pic32mz_spi.o: os/arch/board/curiosity/pic32mz_spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/board/curiosity" 
	@${RM} ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_spi.o.d 
	@${RM} ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_spi.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/board/curiosity/pic32mz_spi.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/board/curiosity/pic32mz_spi.o.d" -o ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_spi.o os/arch/board/curiosity/pic32mz_spi.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_allocateheap.o: os/arch/mips/src/common/up_allocateheap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_allocateheap.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_allocateheap.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_allocateheap.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_allocateheap.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_allocateheap.o os/arch/mips/src/common/up_allocateheap.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_createstack.o: os/arch/mips/src/common/up_createstack.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_createstack.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_createstack.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_createstack.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_createstack.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_createstack.o os/arch/mips/src/common/up_createstack.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_etherstub.o: os/arch/mips/src/common/up_etherstub.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_etherstub.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_etherstub.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_etherstub.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_etherstub.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_etherstub.o os/arch/mips/src/common/up_etherstub.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_exit.o: os/arch/mips/src/common/up_exit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_exit.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_exit.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_exit.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_exit.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_exit.o os/arch/mips/src/common/up_exit.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_idle.o: os/arch/mips/src/common/up_idle.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_idle.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_idle.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_idle.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_idle.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_idle.o os/arch/mips/src/common/up_idle.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_initialize.o: os/arch/mips/src/common/up_initialize.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_initialize.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_initialize.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_initialize.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_initialize.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_initialize.o os/arch/mips/src/common/up_initialize.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_interruptcontext.o: os/arch/mips/src/common/up_interruptcontext.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_interruptcontext.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_interruptcontext.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_interruptcontext.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_interruptcontext.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_interruptcontext.o os/arch/mips/src/common/up_interruptcontext.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_lowputs.o: os/arch/mips/src/common/up_lowputs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_lowputs.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_lowputs.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_lowputs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_lowputs.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_lowputs.o os/arch/mips/src/common/up_lowputs.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_mdelay.o: os/arch/mips/src/common/up_mdelay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_mdelay.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_mdelay.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_mdelay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_mdelay.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_mdelay.o os/arch/mips/src/common/up_mdelay.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg16.o: os/arch/mips/src/common/up_modifyreg16.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg16.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg16.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg16.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg16.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg16.o os/arch/mips/src/common/up_modifyreg16.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg32.o: os/arch/mips/src/common/up_modifyreg32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg32.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg32.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg32.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg32.o os/arch/mips/src/common/up_modifyreg32.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg8.o: os/arch/mips/src/common/up_modifyreg8.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg8.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg8.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg8.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg8.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg8.o os/arch/mips/src/common/up_modifyreg8.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_puts.o: os/arch/mips/src/common/up_puts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_puts.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_puts.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_puts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_puts.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_puts.o os/arch/mips/src/common/up_puts.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_releasestack.o: os/arch/mips/src/common/up_releasestack.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_releasestack.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_releasestack.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_releasestack.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_releasestack.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_releasestack.o os/arch/mips/src/common/up_releasestack.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_stackframe.o: os/arch/mips/src/common/up_stackframe.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_stackframe.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_stackframe.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_stackframe.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_stackframe.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_stackframe.o os/arch/mips/src/common/up_stackframe.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_udelay.o: os/arch/mips/src/common/up_udelay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_udelay.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_udelay.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_udelay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_udelay.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_udelay.o os/arch/mips/src/common/up_udelay.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_usestack.o: os/arch/mips/src/common/up_usestack.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_usestack.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_usestack.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_usestack.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_usestack.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_usestack.o os/arch/mips/src/common/up_usestack.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/mips32/up_assert.o: os/arch/mips/src/mips32/up_assert.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_assert.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_assert.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_assert.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_assert.o.d" -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_assert.o os/arch/mips/src/mips32/up_assert.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/mips32/up_blocktask.o: os/arch/mips/src/mips32/up_blocktask.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_blocktask.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_blocktask.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_blocktask.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_blocktask.o.d" -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_blocktask.o os/arch/mips/src/mips32/up_blocktask.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/mips32/up_copystate.o: os/arch/mips/src/mips32/up_copystate.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_copystate.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_copystate.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_copystate.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_copystate.o.d" -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_copystate.o os/arch/mips/src/mips32/up_copystate.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/mips32/up_doirq.o: os/arch/mips/src/mips32/up_doirq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_doirq.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_doirq.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_doirq.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_doirq.o.d" -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_doirq.o os/arch/mips/src/mips32/up_doirq.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/mips32/up_dumpstate.o: os/arch/mips/src/mips32/up_dumpstate.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_dumpstate.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_dumpstate.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_dumpstate.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_dumpstate.o.d" -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_dumpstate.o os/arch/mips/src/mips32/up_dumpstate.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/mips32/up_initialstate.o: os/arch/mips/src/mips32/up_initialstate.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_initialstate.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_initialstate.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_initialstate.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_initialstate.o.d" -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_initialstate.o os/arch/mips/src/mips32/up_initialstate.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/mips32/up_irq.o: os/arch/mips/src/mips32/up_irq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_irq.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_irq.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_irq.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_irq.o.d" -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_irq.o os/arch/mips/src/mips32/up_irq.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/mips32/up_releasepending.o: os/arch/mips/src/mips32/up_releasepending.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_releasepending.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_releasepending.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_releasepending.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_releasepending.o.d" -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_releasepending.o os/arch/mips/src/mips32/up_releasepending.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/mips32/up_reprioritizertr.o: os/arch/mips/src/mips32/up_reprioritizertr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_reprioritizertr.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_reprioritizertr.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_reprioritizertr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_reprioritizertr.o.d" -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_reprioritizertr.o os/arch/mips/src/mips32/up_reprioritizertr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/mips32/up_schedulesigaction.o: os/arch/mips/src/mips32/up_schedulesigaction.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_schedulesigaction.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_schedulesigaction.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_schedulesigaction.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_schedulesigaction.o.d" -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_schedulesigaction.o os/arch/mips/src/mips32/up_schedulesigaction.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/mips32/up_sigdeliver.o: os/arch/mips/src/mips32/up_sigdeliver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_sigdeliver.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_sigdeliver.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_sigdeliver.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_sigdeliver.o.d" -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_sigdeliver.o os/arch/mips/src/mips32/up_sigdeliver.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/mips32/up_swint0.o: os/arch/mips/src/mips32/up_swint0.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_swint0.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_swint0.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_swint0.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_swint0.o.d" -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_swint0.o os/arch/mips/src/mips32/up_swint0.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/mips32/up_unblocktask.o: os/arch/mips/src/mips32/up_unblocktask.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_unblocktask.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_unblocktask.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_unblocktask.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_unblocktask.o.d" -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_unblocktask.o os/arch/mips/src/mips32/up_unblocktask.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/mips32/up_vfork.o: os/arch/mips/src/mips32/up_vfork.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_vfork.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_vfork.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_vfork.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_vfork.o.d" -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_vfork.o os/arch/mips/src/mips32/up_vfork.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-decodeirq.o: os/arch/mips/src/pic32mz/pic32mz-decodeirq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/pic32mz" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-decodeirq.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-decodeirq.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-decodeirq.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-decodeirq.o.d" -o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-decodeirq.o os/arch/mips/src/pic32mz/pic32mz-decodeirq.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-ethernet.o: os/arch/mips/src/pic32mz/pic32mz-ethernet.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/pic32mz" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-ethernet.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-ethernet.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-ethernet.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-ethernet.o.d" -o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-ethernet.o os/arch/mips/src/pic32mz/pic32mz-ethernet.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-exception.o: os/arch/mips/src/pic32mz/pic32mz-exception.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/pic32mz" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-exception.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-exception.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-exception.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-exception.o.d" -o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-exception.o os/arch/mips/src/pic32mz/pic32mz-exception.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpio.o: os/arch/mips/src/pic32mz/pic32mz-gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/pic32mz" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpio.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpio.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpio.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpio.o.d" -o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpio.o os/arch/mips/src/pic32mz/pic32mz-gpio.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpioirq.o: os/arch/mips/src/pic32mz/pic32mz-gpioirq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/pic32mz" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpioirq.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpioirq.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpioirq.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpioirq.o.d" -o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpioirq.o os/arch/mips/src/pic32mz/pic32mz-gpioirq.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-irq.o: os/arch/mips/src/pic32mz/pic32mz-irq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/pic32mz" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-irq.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-irq.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-irq.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-irq.o.d" -o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-irq.o os/arch/mips/src/pic32mz/pic32mz-irq.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowconsole.o: os/arch/mips/src/pic32mz/pic32mz-lowconsole.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/pic32mz" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowconsole.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowconsole.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowconsole.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowconsole.o.d" -o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowconsole.o os/arch/mips/src/pic32mz/pic32mz-lowconsole.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowinit.o: os/arch/mips/src/pic32mz/pic32mz-lowinit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/pic32mz" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowinit.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowinit.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowinit.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowinit.o.d" -o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowinit.o os/arch/mips/src/pic32mz/pic32mz-lowinit.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-serial.o: os/arch/mips/src/pic32mz/pic32mz-serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/pic32mz" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-serial.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-serial.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-serial.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-serial.o.d" -o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-serial.o os/arch/mips/src/pic32mz/pic32mz-serial.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-spi.o: os/arch/mips/src/pic32mz/pic32mz-spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/pic32mz" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-spi.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-spi.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-spi.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-spi.o.d" -o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-spi.o os/arch/mips/src/pic32mz/pic32mz-spi.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-timerisr.o: os/arch/mips/src/pic32mz/pic32mz-timerisr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/pic32mz" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-timerisr.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-timerisr.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-timerisr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-timerisr.o.d" -o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-timerisr.o os/arch/mips/src/pic32mz/pic32mz-timerisr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/drivers/bch/bch.o: os/drivers/bch/bch.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/drivers/bch" 
	@${RM} ${OBJECTDIR}/os/drivers/bch/bch.o.d 
	@${RM} ${OBJECTDIR}/os/drivers/bch/bch.o 
	@${FIXDEPS} "${OBJECTDIR}/os/drivers/bch/bch.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/drivers/bch/bch.o.d" -o ${OBJECTDIR}/os/drivers/bch/bch.o os/drivers/bch/bch.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/drivers/serial/lowconsole.o: os/drivers/serial/lowconsole.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/drivers/serial" 
	@${RM} ${OBJECTDIR}/os/drivers/serial/lowconsole.o.d 
	@${RM} ${OBJECTDIR}/os/drivers/serial/lowconsole.o 
	@${FIXDEPS} "${OBJECTDIR}/os/drivers/serial/lowconsole.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/drivers/serial/lowconsole.o.d" -o ${OBJECTDIR}/os/drivers/serial/lowconsole.o os/drivers/serial/lowconsole.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/drivers/serial/serial.o: os/drivers/serial/serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/drivers/serial" 
	@${RM} ${OBJECTDIR}/os/drivers/serial/serial.o.d 
	@${RM} ${OBJECTDIR}/os/drivers/serial/serial.o 
	@${FIXDEPS} "${OBJECTDIR}/os/drivers/serial/serial.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/drivers/serial/serial.o.d" -o ${OBJECTDIR}/os/drivers/serial/serial.o os/drivers/serial/serial.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/drivers/serial/serialirq.o: os/drivers/serial/serialirq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/drivers/serial" 
	@${RM} ${OBJECTDIR}/os/drivers/serial/serialirq.o.d 
	@${RM} ${OBJECTDIR}/os/drivers/serial/serialirq.o 
	@${FIXDEPS} "${OBJECTDIR}/os/drivers/serial/serialirq.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/drivers/serial/serialirq.o.d" -o ${OBJECTDIR}/os/drivers/serial/serialirq.o os/drivers/serial/serialirq.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/drivers/syslog/ramlog.o: os/drivers/syslog/ramlog.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/drivers/syslog" 
	@${RM} ${OBJECTDIR}/os/drivers/syslog/ramlog.o.d 
	@${RM} ${OBJECTDIR}/os/drivers/syslog/ramlog.o 
	@${FIXDEPS} "${OBJECTDIR}/os/drivers/syslog/ramlog.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/drivers/syslog/ramlog.o.d" -o ${OBJECTDIR}/os/drivers/syslog/ramlog.o os/drivers/syslog/ramlog.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/drivers/syslog/syslog_console.o: os/drivers/syslog/syslog_console.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/drivers/syslog" 
	@${RM} ${OBJECTDIR}/os/drivers/syslog/syslog_console.o.d 
	@${RM} ${OBJECTDIR}/os/drivers/syslog/syslog_console.o 
	@${FIXDEPS} "${OBJECTDIR}/os/drivers/syslog/syslog_console.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/drivers/syslog/syslog_console.o.d" -o ${OBJECTDIR}/os/drivers/syslog/syslog_console.o os/drivers/syslog/syslog_console.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/fs/aio/fs_aio.o: os/fs/aio/fs_aio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/fs/aio" 
	@${RM} ${OBJECTDIR}/os/fs/aio/fs_aio.o.d 
	@${RM} ${OBJECTDIR}/os/fs/aio/fs_aio.o 
	@${FIXDEPS} "${OBJECTDIR}/os/fs/aio/fs_aio.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/fs/aio/fs_aio.o.d" -o ${OBJECTDIR}/os/fs/aio/fs_aio.o os/fs/aio/fs_aio.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/fs/dirent/fs_dirent.o: os/fs/dirent/fs_dirent.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/fs/dirent" 
	@${RM} ${OBJECTDIR}/os/fs/dirent/fs_dirent.o.d 
	@${RM} ${OBJECTDIR}/os/fs/dirent/fs_dirent.o 
	@${FIXDEPS} "${OBJECTDIR}/os/fs/dirent/fs_dirent.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/fs/dirent/fs_dirent.o.d" -o ${OBJECTDIR}/os/fs/dirent/fs_dirent.o os/fs/dirent/fs_dirent.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/fs/driver/block/fs_block.o: os/fs/driver/block/fs_block.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/fs/driver/block" 
	@${RM} ${OBJECTDIR}/os/fs/driver/block/fs_block.o.d 
	@${RM} ${OBJECTDIR}/os/fs/driver/block/fs_block.o 
	@${FIXDEPS} "${OBJECTDIR}/os/fs/driver/block/fs_block.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/fs/driver/block/fs_block.o.d" -o ${OBJECTDIR}/os/fs/driver/block/fs_block.o os/fs/driver/block/fs_block.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/fs/driver/block/ramdisk.o: os/fs/driver/block/ramdisk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/fs/driver/block" 
	@${RM} ${OBJECTDIR}/os/fs/driver/block/ramdisk.o.d 
	@${RM} ${OBJECTDIR}/os/fs/driver/block/ramdisk.o 
	@${FIXDEPS} "${OBJECTDIR}/os/fs/driver/block/ramdisk.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/fs/driver/block/ramdisk.o.d" -o ${OBJECTDIR}/os/fs/driver/block/ramdisk.o os/fs/driver/block/ramdisk.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/fs/inode/fs_inode.o: os/fs/inode/fs_inode.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/fs/inode" 
	@${RM} ${OBJECTDIR}/os/fs/inode/fs_inode.o.d 
	@${RM} ${OBJECTDIR}/os/fs/inode/fs_inode.o 
	@${FIXDEPS} "${OBJECTDIR}/os/fs/inode/fs_inode.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/fs/inode/fs_inode.o.d" -o ${OBJECTDIR}/os/fs/inode/fs_inode.o os/fs/inode/fs_inode.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/fs/mount/fs_mount.o: os/fs/mount/fs_mount.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/fs/mount" 
	@${RM} ${OBJECTDIR}/os/fs/mount/fs_mount.o.d 
	@${RM} ${OBJECTDIR}/os/fs/mount/fs_mount.o 
	@${FIXDEPS} "${OBJECTDIR}/os/fs/mount/fs_mount.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/fs/mount/fs_mount.o.d" -o ${OBJECTDIR}/os/fs/mount/fs_mount.o os/fs/mount/fs_mount.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/fs/vfs/vfs.o: os/fs/vfs/vfs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/fs/vfs" 
	@${RM} ${OBJECTDIR}/os/fs/vfs/vfs.o.d 
	@${RM} ${OBJECTDIR}/os/fs/vfs/vfs.o 
	@${FIXDEPS} "${OBJECTDIR}/os/fs/vfs/vfs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/fs/vfs/vfs.o.d" -o ${OBJECTDIR}/os/fs/vfs/vfs.o os/fs/vfs/vfs.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/fs/fs_initialize.o: os/fs/fs_initialize.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/fs" 
	@${RM} ${OBJECTDIR}/os/fs/fs_initialize.o.d 
	@${RM} ${OBJECTDIR}/os/fs/fs_initialize.o 
	@${FIXDEPS} "${OBJECTDIR}/os/fs/fs_initialize.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/fs/fs_initialize.o.d" -o ${OBJECTDIR}/os/fs/fs_initialize.o os/fs/fs_initialize.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/clock/clock.o: os/kernel/clock/clock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/clock" 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/clock/clock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/clock/clock.o.d" -o ${OBJECTDIR}/os/kernel/clock/clock.o os/kernel/clock/clock.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/clock/clock_abstime2ticks.o: os/kernel/clock/clock_abstime2ticks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/clock" 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_abstime2ticks.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_abstime2ticks.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/clock/clock_abstime2ticks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/clock/clock_abstime2ticks.o.d" -o ${OBJECTDIR}/os/kernel/clock/clock_abstime2ticks.o os/kernel/clock/clock_abstime2ticks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/clock/clock_dow.o: os/kernel/clock/clock_dow.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/clock" 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_dow.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_dow.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/clock/clock_dow.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/clock/clock_dow.o.d" -o ${OBJECTDIR}/os/kernel/clock/clock_dow.o os/kernel/clock/clock_dow.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/clock/clock_getres.o: os/kernel/clock/clock_getres.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/clock" 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_getres.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_getres.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/clock/clock_getres.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/clock/clock_getres.o.d" -o ${OBJECTDIR}/os/kernel/clock/clock_getres.o os/kernel/clock/clock_getres.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/clock/clock_gettime.o: os/kernel/clock/clock_gettime.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/clock" 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_gettime.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_gettime.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/clock/clock_gettime.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/clock/clock_gettime.o.d" -o ${OBJECTDIR}/os/kernel/clock/clock_gettime.o os/kernel/clock/clock_gettime.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/clock/clock_gettimeofday.o: os/kernel/clock/clock_gettimeofday.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/clock" 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_gettimeofday.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_gettimeofday.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/clock/clock_gettimeofday.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/clock/clock_gettimeofday.o.d" -o ${OBJECTDIR}/os/kernel/clock/clock_gettimeofday.o os/kernel/clock/clock_gettimeofday.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/clock/clock_initialize.o: os/kernel/clock/clock_initialize.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/clock" 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_initialize.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_initialize.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/clock/clock_initialize.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/clock/clock_initialize.o.d" -o ${OBJECTDIR}/os/kernel/clock/clock_initialize.o os/kernel/clock/clock_initialize.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/clock/clock_settime.o: os/kernel/clock/clock_settime.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/clock" 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_settime.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_settime.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/clock/clock_settime.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/clock/clock_settime.o.d" -o ${OBJECTDIR}/os/kernel/clock/clock_settime.o os/kernel/clock/clock_settime.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/clock/clock_systimer.o: os/kernel/clock/clock_systimer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/clock" 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_systimer.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_systimer.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/clock/clock_systimer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/clock/clock_systimer.o.d" -o ${OBJECTDIR}/os/kernel/clock/clock_systimer.o os/kernel/clock/clock_systimer.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/clock/clock_systimespec.o: os/kernel/clock/clock_systimespec.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/clock" 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_systimespec.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_systimespec.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/clock/clock_systimespec.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/clock/clock_systimespec.o.d" -o ${OBJECTDIR}/os/kernel/clock/clock_systimespec.o os/kernel/clock/clock_systimespec.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/clock/clock_ticks2time.o: os/kernel/clock/clock_ticks2time.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/clock" 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_ticks2time.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_ticks2time.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/clock/clock_ticks2time.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/clock/clock_ticks2time.o.d" -o ${OBJECTDIR}/os/kernel/clock/clock_ticks2time.o os/kernel/clock/clock_ticks2time.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/clock/clock_time2ticks.o: os/kernel/clock/clock_time2ticks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/clock" 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_time2ticks.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_time2ticks.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/clock/clock_time2ticks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/clock/clock_time2ticks.o.d" -o ${OBJECTDIR}/os/kernel/clock/clock_time2ticks.o os/kernel/clock/clock_time2ticks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/debug/sysdbg.o: os/kernel/debug/sysdbg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/debug" 
	@${RM} ${OBJECTDIR}/os/kernel/debug/sysdbg.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/debug/sysdbg.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/debug/sysdbg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/debug/sysdbg.o.d" -o ${OBJECTDIR}/os/kernel/debug/sysdbg.o os/kernel/debug/sysdbg.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/environ/env_clearenv.o: os/kernel/environ/env_clearenv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/environ" 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_clearenv.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_clearenv.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/environ/env_clearenv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/environ/env_clearenv.o.d" -o ${OBJECTDIR}/os/kernel/environ/env_clearenv.o os/kernel/environ/env_clearenv.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/environ/env_dup.o: os/kernel/environ/env_dup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/environ" 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_dup.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_dup.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/environ/env_dup.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/environ/env_dup.o.d" -o ${OBJECTDIR}/os/kernel/environ/env_dup.o os/kernel/environ/env_dup.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/environ/env_findvar.o: os/kernel/environ/env_findvar.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/environ" 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_findvar.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_findvar.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/environ/env_findvar.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/environ/env_findvar.o.d" -o ${OBJECTDIR}/os/kernel/environ/env_findvar.o os/kernel/environ/env_findvar.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/environ/env_getenv.o: os/kernel/environ/env_getenv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/environ" 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_getenv.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_getenv.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/environ/env_getenv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/environ/env_getenv.o.d" -o ${OBJECTDIR}/os/kernel/environ/env_getenv.o os/kernel/environ/env_getenv.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/environ/env_getenvironptr.o: os/kernel/environ/env_getenvironptr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/environ" 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_getenvironptr.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_getenvironptr.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/environ/env_getenvironptr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/environ/env_getenvironptr.o.d" -o ${OBJECTDIR}/os/kernel/environ/env_getenvironptr.o os/kernel/environ/env_getenvironptr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/environ/env_putenv.o: os/kernel/environ/env_putenv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/environ" 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_putenv.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_putenv.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/environ/env_putenv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/environ/env_putenv.o.d" -o ${OBJECTDIR}/os/kernel/environ/env_putenv.o os/kernel/environ/env_putenv.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/environ/env_release.o: os/kernel/environ/env_release.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/environ" 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_release.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_release.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/environ/env_release.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/environ/env_release.o.d" -o ${OBJECTDIR}/os/kernel/environ/env_release.o os/kernel/environ/env_release.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/environ/env_removevar.o: os/kernel/environ/env_removevar.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/environ" 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_removevar.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_removevar.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/environ/env_removevar.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/environ/env_removevar.o.d" -o ${OBJECTDIR}/os/kernel/environ/env_removevar.o os/kernel/environ/env_removevar.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/environ/env_setenv.o: os/kernel/environ/env_setenv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/environ" 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_setenv.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_setenv.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/environ/env_setenv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/environ/env_setenv.o.d" -o ${OBJECTDIR}/os/kernel/environ/env_setenv.o os/kernel/environ/env_setenv.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/environ/env_unsetenv.o: os/kernel/environ/env_unsetenv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/environ" 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_unsetenv.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_unsetenv.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/environ/env_unsetenv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/environ/env_unsetenv.o.d" -o ${OBJECTDIR}/os/kernel/environ/env_unsetenv.o os/kernel/environ/env_unsetenv.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/errno/errno_get.o: os/kernel/errno/errno_get.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/errno" 
	@${RM} ${OBJECTDIR}/os/kernel/errno/errno_get.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/errno/errno_get.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/errno/errno_get.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/errno/errno_get.o.d" -o ${OBJECTDIR}/os/kernel/errno/errno_get.o os/kernel/errno/errno_get.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/errno/errno_getptr.o: os/kernel/errno/errno_getptr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/errno" 
	@${RM} ${OBJECTDIR}/os/kernel/errno/errno_getptr.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/errno/errno_getptr.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/errno/errno_getptr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/errno/errno_getptr.o.d" -o ${OBJECTDIR}/os/kernel/errno/errno_getptr.o os/kernel/errno/errno_getptr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/errno/errno_set.o: os/kernel/errno/errno_set.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/errno" 
	@${RM} ${OBJECTDIR}/os/kernel/errno/errno_set.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/errno/errno_set.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/errno/errno_set.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/errno/errno_set.o.d" -o ${OBJECTDIR}/os/kernel/errno/errno_set.o os/kernel/errno/errno_set.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_addrenv.o: os/kernel/group/group_addrenv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_addrenv.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_addrenv.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_addrenv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_addrenv.o.d" -o ${OBJECTDIR}/os/kernel/group/group_addrenv.o os/kernel/group/group_addrenv.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_childstatus.o: os/kernel/group/group_childstatus.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_childstatus.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_childstatus.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_childstatus.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_childstatus.o.d" -o ${OBJECTDIR}/os/kernel/group/group_childstatus.o os/kernel/group/group_childstatus.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_create.o: os/kernel/group/group_create.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_create.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_create.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_create.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_create.o.d" -o ${OBJECTDIR}/os/kernel/group/group_create.o os/kernel/group/group_create.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_find.o: os/kernel/group/group_find.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_find.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_find.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_find.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_find.o.d" -o ${OBJECTDIR}/os/kernel/group/group_find.o os/kernel/group/group_find.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_foreachchild.o: os/kernel/group/group_foreachchild.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_foreachchild.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_foreachchild.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_foreachchild.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_foreachchild.o.d" -o ${OBJECTDIR}/os/kernel/group/group_foreachchild.o os/kernel/group/group_foreachchild.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_free.o: os/kernel/group/group_free.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_free.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_free.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_free.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_free.o.d" -o ${OBJECTDIR}/os/kernel/group/group_free.o os/kernel/group/group_free.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_join.o: os/kernel/group/group_join.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_join.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_join.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_join.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_join.o.d" -o ${OBJECTDIR}/os/kernel/group/group_join.o os/kernel/group/group_join.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_killchildren.o: os/kernel/group/group_killchildren.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_killchildren.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_killchildren.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_killchildren.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_killchildren.o.d" -o ${OBJECTDIR}/os/kernel/group/group_killchildren.o os/kernel/group/group_killchildren.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_leave.o: os/kernel/group/group_leave.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_leave.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_leave.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_leave.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_leave.o.d" -o ${OBJECTDIR}/os/kernel/group/group_leave.o os/kernel/group/group_leave.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_malloc.o: os/kernel/group/group_malloc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_malloc.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_malloc.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_malloc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_malloc.o.d" -o ${OBJECTDIR}/os/kernel/group/group_malloc.o os/kernel/group/group_malloc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_setupidlefiles.o: os/kernel/group/group_setupidlefiles.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_setupidlefiles.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_setupidlefiles.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_setupidlefiles.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_setupidlefiles.o.d" -o ${OBJECTDIR}/os/kernel/group/group_setupidlefiles.o os/kernel/group/group_setupidlefiles.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_setupstreams.o: os/kernel/group/group_setupstreams.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_setupstreams.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_setupstreams.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_setupstreams.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_setupstreams.o.d" -o ${OBJECTDIR}/os/kernel/group/group_setupstreams.o os/kernel/group/group_setupstreams.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_setuptaskfiles.o: os/kernel/group/group_setuptaskfiles.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_setuptaskfiles.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_setuptaskfiles.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_setuptaskfiles.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_setuptaskfiles.o.d" -o ${OBJECTDIR}/os/kernel/group/group_setuptaskfiles.o os/kernel/group/group_setuptaskfiles.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_signal.o: os/kernel/group/group_signal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_signal.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_signal.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_signal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_signal.o.d" -o ${OBJECTDIR}/os/kernel/group/group_signal.o os/kernel/group/group_signal.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_zalloc.o: os/kernel/group/group_zalloc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_zalloc.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_zalloc.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_zalloc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_zalloc.o.d" -o ${OBJECTDIR}/os/kernel/group/group_zalloc.o os/kernel/group/group_zalloc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/init/os_bringup.o: os/kernel/init/os_bringup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/init" 
	@${RM} ${OBJECTDIR}/os/kernel/init/os_bringup.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/init/os_bringup.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/init/os_bringup.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/init/os_bringup.o.d" -o ${OBJECTDIR}/os/kernel/init/os_bringup.o os/kernel/init/os_bringup.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/init/os_start.o: os/kernel/init/os_start.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/init" 
	@${RM} ${OBJECTDIR}/os/kernel/init/os_start.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/init/os_start.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/init/os_start.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/init/os_start.o.d" -o ${OBJECTDIR}/os/kernel/init/os_start.o os/kernel/init/os_start.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/irq/irq_attach.o: os/kernel/irq/irq_attach.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/irq" 
	@${RM} ${OBJECTDIR}/os/kernel/irq/irq_attach.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/irq/irq_attach.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/irq/irq_attach.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/irq/irq_attach.o.d" -o ${OBJECTDIR}/os/kernel/irq/irq_attach.o os/kernel/irq/irq_attach.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/irq/irq_dispatch.o: os/kernel/irq/irq_dispatch.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/irq" 
	@${RM} ${OBJECTDIR}/os/kernel/irq/irq_dispatch.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/irq/irq_dispatch.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/irq/irq_dispatch.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/irq/irq_dispatch.o.d" -o ${OBJECTDIR}/os/kernel/irq/irq_dispatch.o os/kernel/irq/irq_dispatch.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/irq/irq_info.o: os/kernel/irq/irq_info.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/irq" 
	@${RM} ${OBJECTDIR}/os/kernel/irq/irq_info.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/irq/irq_info.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/irq/irq_info.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/irq/irq_info.o.d" -o ${OBJECTDIR}/os/kernel/irq/irq_info.o os/kernel/irq/irq_info.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/irq/irq_initialize.o: os/kernel/irq/irq_initialize.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/irq" 
	@${RM} ${OBJECTDIR}/os/kernel/irq/irq_initialize.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/irq/irq_initialize.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/irq/irq_initialize.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/irq/irq_initialize.o.d" -o ${OBJECTDIR}/os/kernel/irq/irq_initialize.o os/kernel/irq/irq_initialize.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/irq/irq_unexpectedisr.o: os/kernel/irq/irq_unexpectedisr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/irq" 
	@${RM} ${OBJECTDIR}/os/kernel/irq/irq_unexpectedisr.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/irq/irq_unexpectedisr.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/irq/irq_unexpectedisr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/irq/irq_unexpectedisr.o.d" -o ${OBJECTDIR}/os/kernel/irq/irq_unexpectedisr.o os/kernel/irq/irq_unexpectedisr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/paging/pg_miss.o: os/kernel/paging/pg_miss.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/paging" 
	@${RM} ${OBJECTDIR}/os/kernel/paging/pg_miss.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/paging/pg_miss.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/paging/pg_miss.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/paging/pg_miss.o.d" -o ${OBJECTDIR}/os/kernel/paging/pg_miss.o os/kernel/paging/pg_miss.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/paging/pg_worker.o: os/kernel/paging/pg_worker.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/paging" 
	@${RM} ${OBJECTDIR}/os/kernel/paging/pg_worker.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/paging/pg_worker.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/paging/pg_worker.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/paging/pg_worker.o.d" -o ${OBJECTDIR}/os/kernel/paging/pg_worker.o os/kernel/paging/pg_worker.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_cancel.o: os/kernel/pthread/pthread_cancel.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_cancel.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_cancel.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_cancel.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_cancel.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_cancel.o os/kernel/pthread/pthread_cancel.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_cleanup.o: os/kernel/pthread/pthread_cleanup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_cleanup.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_cleanup.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_cleanup.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_cleanup.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_cleanup.o os/kernel/pthread/pthread_cleanup.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_completejoin.o: os/kernel/pthread/pthread_completejoin.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_completejoin.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_completejoin.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_completejoin.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_completejoin.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_completejoin.o os/kernel/pthread/pthread_completejoin.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_condbroadcast.o: os/kernel/pthread/pthread_condbroadcast.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_condbroadcast.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_condbroadcast.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_condbroadcast.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_condbroadcast.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_condbroadcast.o os/kernel/pthread/pthread_condbroadcast.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_condsignal.o: os/kernel/pthread/pthread_condsignal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_condsignal.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_condsignal.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_condsignal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_condsignal.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_condsignal.o os/kernel/pthread/pthread_condsignal.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_condtimedwait.o: os/kernel/pthread/pthread_condtimedwait.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_condtimedwait.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_condtimedwait.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_condtimedwait.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_condtimedwait.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_condtimedwait.o os/kernel/pthread/pthread_condtimedwait.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_condwait.o: os/kernel/pthread/pthread_condwait.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_condwait.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_condwait.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_condwait.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_condwait.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_condwait.o os/kernel/pthread/pthread_condwait.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_create.o: os/kernel/pthread/pthread_create.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_create.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_create.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_create.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_create.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_create.o os/kernel/pthread/pthread_create.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_detach.o: os/kernel/pthread/pthread_detach.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_detach.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_detach.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_detach.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_detach.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_detach.o os/kernel/pthread/pthread_detach.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_exit.o: os/kernel/pthread/pthread_exit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_exit.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_exit.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_exit.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_exit.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_exit.o os/kernel/pthread/pthread_exit.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_findjoininfo.o: os/kernel/pthread/pthread_findjoininfo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_findjoininfo.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_findjoininfo.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_findjoininfo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_findjoininfo.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_findjoininfo.o os/kernel/pthread/pthread_findjoininfo.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_getschedparam.o: os/kernel/pthread/pthread_getschedparam.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_getschedparam.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_getschedparam.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_getschedparam.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_getschedparam.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_getschedparam.o os/kernel/pthread/pthread_getschedparam.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_getspecific.o: os/kernel/pthread/pthread_getspecific.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_getspecific.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_getspecific.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_getspecific.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_getspecific.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_getspecific.o os/kernel/pthread/pthread_getspecific.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_initialize.o: os/kernel/pthread/pthread_initialize.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_initialize.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_initialize.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_initialize.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_initialize.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_initialize.o os/kernel/pthread/pthread_initialize.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_join.o: os/kernel/pthread/pthread_join.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_join.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_join.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_join.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_join.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_join.o os/kernel/pthread/pthread_join.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_keycreate.o: os/kernel/pthread/pthread_keycreate.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_keycreate.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_keycreate.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_keycreate.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_keycreate.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_keycreate.o os/kernel/pthread/pthread_keycreate.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_keydelete.o: os/kernel/pthread/pthread_keydelete.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_keydelete.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_keydelete.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_keydelete.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_keydelete.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_keydelete.o os/kernel/pthread/pthread_keydelete.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_keydestroy.o: os/kernel/pthread/pthread_keydestroy.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_keydestroy.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_keydestroy.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_keydestroy.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_keydestroy.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_keydestroy.o os/kernel/pthread/pthread_keydestroy.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_kill.o: os/kernel/pthread/pthread_kill.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_kill.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_kill.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_kill.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_kill.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_kill.o os/kernel/pthread/pthread_kill.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_mutex.o: os/kernel/pthread/pthread_mutex.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutex.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutex.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_mutex.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_mutex.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_mutex.o os/kernel/pthread/pthread_mutex.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_mutexconsistent.o: os/kernel/pthread/pthread_mutexconsistent.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutexconsistent.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutexconsistent.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_mutexconsistent.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_mutexconsistent.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_mutexconsistent.o os/kernel/pthread/pthread_mutexconsistent.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_mutexdestroy.o: os/kernel/pthread/pthread_mutexdestroy.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutexdestroy.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutexdestroy.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_mutexdestroy.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_mutexdestroy.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_mutexdestroy.o os/kernel/pthread/pthread_mutexdestroy.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_mutexinconsistent.o: os/kernel/pthread/pthread_mutexinconsistent.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutexinconsistent.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutexinconsistent.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_mutexinconsistent.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_mutexinconsistent.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_mutexinconsistent.o os/kernel/pthread/pthread_mutexinconsistent.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_mutexinit.o: os/kernel/pthread/pthread_mutexinit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutexinit.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutexinit.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_mutexinit.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_mutexinit.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_mutexinit.o os/kernel/pthread/pthread_mutexinit.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_mutexlock.o: os/kernel/pthread/pthread_mutexlock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutexlock.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutexlock.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_mutexlock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_mutexlock.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_mutexlock.o os/kernel/pthread/pthread_mutexlock.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_mutextrylock.o: os/kernel/pthread/pthread_mutextrylock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutextrylock.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutextrylock.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_mutextrylock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_mutextrylock.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_mutextrylock.o os/kernel/pthread/pthread_mutextrylock.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_mutexunlock.o: os/kernel/pthread/pthread_mutexunlock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutexunlock.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutexunlock.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_mutexunlock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_mutexunlock.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_mutexunlock.o os/kernel/pthread/pthread_mutexunlock.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_release.o: os/kernel/pthread/pthread_release.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_release.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_release.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_release.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_release.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_release.o os/kernel/pthread/pthread_release.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_setschedparam.o: os/kernel/pthread/pthread_setschedparam.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_setschedparam.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_setschedparam.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_setschedparam.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_setschedparam.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_setschedparam.o os/kernel/pthread/pthread_setschedparam.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_setschedprio.o: os/kernel/pthread/pthread_setschedprio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_setschedprio.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_setschedprio.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_setschedprio.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_setschedprio.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_setschedprio.o os/kernel/pthread/pthread_setschedprio.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_setspecific.o: os/kernel/pthread/pthread_setspecific.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_setspecific.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_setspecific.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_setspecific.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_setspecific.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_setspecific.o os/kernel/pthread/pthread_setspecific.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_sigmask.o: os/kernel/pthread/pthread_sigmask.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_sigmask.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_sigmask.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_sigmask.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_sigmask.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_sigmask.o os/kernel/pthread/pthread_sigmask.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_tryjoin_np.o: os/kernel/pthread/pthread_tryjoin_np.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_tryjoin_np.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_tryjoin_np.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_tryjoin_np.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_tryjoin_np.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_tryjoin_np.o os/kernel/pthread/pthread_tryjoin_np.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_addblocked.o: os/kernel/sched/sched_addblocked.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_addblocked.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_addblocked.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_addblocked.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_addblocked.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_addblocked.o os/kernel/sched/sched_addblocked.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_addprioritized.o: os/kernel/sched/sched_addprioritized.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_addprioritized.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_addprioritized.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_addprioritized.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_addprioritized.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_addprioritized.o os/kernel/sched/sched_addprioritized.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_addreadytorun.o: os/kernel/sched/sched_addreadytorun.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_addreadytorun.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_addreadytorun.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_addreadytorun.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_addreadytorun.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_addreadytorun.o os/kernel/sched/sched_addreadytorun.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_cpuload.o: os/kernel/sched/sched_cpuload.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_cpuload.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_cpuload.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_cpuload.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_cpuload.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_cpuload.o os/kernel/sched/sched_cpuload.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_foreach.o: os/kernel/sched/sched_foreach.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_foreach.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_foreach.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_foreach.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_foreach.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_foreach.o os/kernel/sched/sched_foreach.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_free.o: os/kernel/sched/sched_free.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_free.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_free.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_free.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_free.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_free.o os/kernel/sched/sched_free.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_garbage.o: os/kernel/sched/sched_garbage.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_garbage.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_garbage.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_garbage.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_garbage.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_garbage.o os/kernel/sched/sched_garbage.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_getfiles.o: os/kernel/sched/sched_getfiles.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_getfiles.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_getfiles.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_getfiles.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_getfiles.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_getfiles.o os/kernel/sched/sched_getfiles.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_getparam.o: os/kernel/sched/sched_getparam.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_getparam.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_getparam.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_getparam.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_getparam.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_getparam.o os/kernel/sched/sched_getparam.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_getscheduler.o: os/kernel/sched/sched_getscheduler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_getscheduler.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_getscheduler.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_getscheduler.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_getscheduler.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_getscheduler.o os/kernel/sched/sched_getscheduler.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_getsockets.o: os/kernel/sched/sched_getsockets.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_getsockets.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_getsockets.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_getsockets.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_getsockets.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_getsockets.o os/kernel/sched/sched_getsockets.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_getstreams.o: os/kernel/sched/sched_getstreams.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_getstreams.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_getstreams.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_getstreams.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_getstreams.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_getstreams.o os/kernel/sched/sched_getstreams.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_gettcb.o: os/kernel/sched/sched_gettcb.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_gettcb.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_gettcb.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_gettcb.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_gettcb.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_gettcb.o os/kernel/sched/sched_gettcb.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_lock.o: os/kernel/sched/sched_lock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_lock.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_lock.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_lock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_lock.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_lock.o os/kernel/sched/sched_lock.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_lockcount.o: os/kernel/sched/sched_lockcount.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_lockcount.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_lockcount.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_lockcount.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_lockcount.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_lockcount.o os/kernel/sched/sched_lockcount.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_mergepending.o: os/kernel/sched/sched_mergepending.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_mergepending.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_mergepending.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_mergepending.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_mergepending.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_mergepending.o os/kernel/sched/sched_mergepending.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_processtimer.o: os/kernel/sched/sched_processtimer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_processtimer.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_processtimer.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_processtimer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_processtimer.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_processtimer.o os/kernel/sched/sched_processtimer.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_releasetcb.o: os/kernel/sched/sched_releasetcb.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_releasetcb.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_releasetcb.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_releasetcb.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_releasetcb.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_releasetcb.o os/kernel/sched/sched_releasetcb.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_removeblocked.o: os/kernel/sched/sched_removeblocked.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_removeblocked.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_removeblocked.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_removeblocked.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_removeblocked.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_removeblocked.o os/kernel/sched/sched_removeblocked.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_removereadytorun.o: os/kernel/sched/sched_removereadytorun.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_removereadytorun.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_removereadytorun.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_removereadytorun.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_removereadytorun.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_removereadytorun.o os/kernel/sched/sched_removereadytorun.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_reprioritize.o: os/kernel/sched/sched_reprioritize.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_reprioritize.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_reprioritize.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_reprioritize.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_reprioritize.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_reprioritize.o os/kernel/sched/sched_reprioritize.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_rrgetinterval.o: os/kernel/sched/sched_rrgetinterval.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_rrgetinterval.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_rrgetinterval.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_rrgetinterval.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_rrgetinterval.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_rrgetinterval.o os/kernel/sched/sched_rrgetinterval.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_self.o: os/kernel/sched/sched_self.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_self.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_self.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_self.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_self.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_self.o os/kernel/sched/sched_self.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_setparam.o: os/kernel/sched/sched_setparam.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_setparam.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_setparam.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_setparam.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_setparam.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_setparam.o os/kernel/sched/sched_setparam.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_setpriority.o: os/kernel/sched/sched_setpriority.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_setpriority.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_setpriority.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_setpriority.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_setpriority.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_setpriority.o os/kernel/sched/sched_setpriority.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_setscheduler.o: os/kernel/sched/sched_setscheduler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_setscheduler.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_setscheduler.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_setscheduler.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_setscheduler.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_setscheduler.o os/kernel/sched/sched_setscheduler.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_timerexpiration.o: os/kernel/sched/sched_timerexpiration.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_timerexpiration.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_timerexpiration.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_timerexpiration.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_timerexpiration.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_timerexpiration.o os/kernel/sched/sched_timerexpiration.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_unlock.o: os/kernel/sched/sched_unlock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_unlock.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_unlock.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_unlock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_unlock.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_unlock.o os/kernel/sched/sched_unlock.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_verifytcb.o: os/kernel/sched/sched_verifytcb.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_verifytcb.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_verifytcb.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_verifytcb.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_verifytcb.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_verifytcb.o os/kernel/sched/sched_verifytcb.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_wait.o: os/kernel/sched/sched_wait.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_wait.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_wait.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_wait.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_wait.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_wait.o os/kernel/sched/sched_wait.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_waitid.o: os/kernel/sched/sched_waitid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_waitid.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_waitid.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_waitid.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_waitid.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_waitid.o os/kernel/sched/sched_waitid.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_waitpid.o: os/kernel/sched/sched_waitpid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_waitpid.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_waitpid.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_waitpid.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_waitpid.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_waitpid.o os/kernel/sched/sched_waitpid.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_yield.o: os/kernel/sched/sched_yield.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_yield.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_yield.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_yield.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_yield.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_yield.o os/kernel/sched/sched_yield.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/semaphore/sem_destroy.o: os/kernel/semaphore/sem_destroy.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/semaphore" 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_destroy.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_destroy.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/semaphore/sem_destroy.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/semaphore/sem_destroy.o.d" -o ${OBJECTDIR}/os/kernel/semaphore/sem_destroy.o os/kernel/semaphore/sem_destroy.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/semaphore/sem_holder.o: os/kernel/semaphore/sem_holder.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/semaphore" 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_holder.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_holder.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/semaphore/sem_holder.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/semaphore/sem_holder.o.d" -o ${OBJECTDIR}/os/kernel/semaphore/sem_holder.o os/kernel/semaphore/sem_holder.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/semaphore/sem_initialize.o: os/kernel/semaphore/sem_initialize.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/semaphore" 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_initialize.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_initialize.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/semaphore/sem_initialize.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/semaphore/sem_initialize.o.d" -o ${OBJECTDIR}/os/kernel/semaphore/sem_initialize.o os/kernel/semaphore/sem_initialize.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/semaphore/sem_post.o: os/kernel/semaphore/sem_post.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/semaphore" 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_post.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_post.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/semaphore/sem_post.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/semaphore/sem_post.o.d" -o ${OBJECTDIR}/os/kernel/semaphore/sem_post.o os/kernel/semaphore/sem_post.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/semaphore/sem_recover.o: os/kernel/semaphore/sem_recover.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/semaphore" 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_recover.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_recover.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/semaphore/sem_recover.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/semaphore/sem_recover.o.d" -o ${OBJECTDIR}/os/kernel/semaphore/sem_recover.o os/kernel/semaphore/sem_recover.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/semaphore/sem_reset.o: os/kernel/semaphore/sem_reset.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/semaphore" 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_reset.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_reset.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/semaphore/sem_reset.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/semaphore/sem_reset.o.d" -o ${OBJECTDIR}/os/kernel/semaphore/sem_reset.o os/kernel/semaphore/sem_reset.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/semaphore/sem_setprotocol.o: os/kernel/semaphore/sem_setprotocol.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/semaphore" 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_setprotocol.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_setprotocol.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/semaphore/sem_setprotocol.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/semaphore/sem_setprotocol.o.d" -o ${OBJECTDIR}/os/kernel/semaphore/sem_setprotocol.o os/kernel/semaphore/sem_setprotocol.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/semaphore/sem_tickwait.o: os/kernel/semaphore/sem_tickwait.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/semaphore" 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_tickwait.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_tickwait.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/semaphore/sem_tickwait.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/semaphore/sem_tickwait.o.d" -o ${OBJECTDIR}/os/kernel/semaphore/sem_tickwait.o os/kernel/semaphore/sem_tickwait.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/semaphore/sem_timedwait.o: os/kernel/semaphore/sem_timedwait.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/semaphore" 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_timedwait.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_timedwait.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/semaphore/sem_timedwait.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/semaphore/sem_timedwait.o.d" -o ${OBJECTDIR}/os/kernel/semaphore/sem_timedwait.o os/kernel/semaphore/sem_timedwait.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/semaphore/sem_trywait.o: os/kernel/semaphore/sem_trywait.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/semaphore" 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_trywait.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_trywait.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/semaphore/sem_trywait.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/semaphore/sem_trywait.o.d" -o ${OBJECTDIR}/os/kernel/semaphore/sem_trywait.o os/kernel/semaphore/sem_trywait.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/semaphore/sem_wait.o: os/kernel/semaphore/sem_wait.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/semaphore" 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_wait.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_wait.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/semaphore/sem_wait.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/semaphore/sem_wait.o.d" -o ${OBJECTDIR}/os/kernel/semaphore/sem_wait.o os/kernel/semaphore/sem_wait.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/semaphore/sem_waitirq.o: os/kernel/semaphore/sem_waitirq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/semaphore" 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_waitirq.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_waitirq.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/semaphore/sem_waitirq.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/semaphore/sem_waitirq.o.d" -o ${OBJECTDIR}/os/kernel/semaphore/sem_waitirq.o os/kernel/semaphore/sem_waitirq.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_action.o: os/kernel/signal/sig_action.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_action.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_action.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_action.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_action.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_action.o os/kernel/signal/sig_action.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_allocatependingsigaction.o: os/kernel/signal/sig_allocatependingsigaction.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_allocatependingsigaction.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_allocatependingsigaction.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_allocatependingsigaction.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_allocatependingsigaction.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_allocatependingsigaction.o os/kernel/signal/sig_allocatependingsigaction.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_cleanup.o: os/kernel/signal/sig_cleanup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_cleanup.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_cleanup.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_cleanup.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_cleanup.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_cleanup.o os/kernel/signal/sig_cleanup.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_deliver.o: os/kernel/signal/sig_deliver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_deliver.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_deliver.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_deliver.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_deliver.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_deliver.o os/kernel/signal/sig_deliver.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_dispatch.o: os/kernel/signal/sig_dispatch.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_dispatch.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_dispatch.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_dispatch.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_dispatch.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_dispatch.o os/kernel/signal/sig_dispatch.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_findaction.o: os/kernel/signal/sig_findaction.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_findaction.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_findaction.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_findaction.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_findaction.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_findaction.o os/kernel/signal/sig_findaction.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_initialize.o: os/kernel/signal/sig_initialize.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_initialize.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_initialize.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_initialize.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_initialize.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_initialize.o os/kernel/signal/sig_initialize.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_is_handler_registered.o: os/kernel/signal/sig_is_handler_registered.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_is_handler_registered.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_is_handler_registered.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_is_handler_registered.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_is_handler_registered.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_is_handler_registered.o os/kernel/signal/sig_is_handler_registered.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_kill.o: os/kernel/signal/sig_kill.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_kill.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_kill.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_kill.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_kill.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_kill.o os/kernel/signal/sig_kill.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_lowest.o: os/kernel/signal/sig_lowest.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_lowest.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_lowest.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_lowest.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_lowest.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_lowest.o os/kernel/signal/sig_lowest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_mqnotempty.o: os/kernel/signal/sig_mqnotempty.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_mqnotempty.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_mqnotempty.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_mqnotempty.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_mqnotempty.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_mqnotempty.o os/kernel/signal/sig_mqnotempty.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_nanosleep.o: os/kernel/signal/sig_nanosleep.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_nanosleep.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_nanosleep.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_nanosleep.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_nanosleep.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_nanosleep.o os/kernel/signal/sig_nanosleep.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_pause.o: os/kernel/signal/sig_pause.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_pause.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_pause.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_pause.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_pause.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_pause.o os/kernel/signal/sig_pause.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_pending.o: os/kernel/signal/sig_pending.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_pending.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_pending.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_pending.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_pending.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_pending.o os/kernel/signal/sig_pending.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_procmask.o: os/kernel/signal/sig_procmask.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_procmask.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_procmask.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_procmask.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_procmask.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_procmask.o os/kernel/signal/sig_procmask.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_queue.o: os/kernel/signal/sig_queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_queue.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_queue.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_queue.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_queue.o os/kernel/signal/sig_queue.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_releasependingsigaction.o: os/kernel/signal/sig_releasependingsigaction.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_releasependingsigaction.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_releasependingsigaction.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_releasependingsigaction.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_releasependingsigaction.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_releasependingsigaction.o os/kernel/signal/sig_releasependingsigaction.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_releasependingsignal.o: os/kernel/signal/sig_releasependingsignal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_releasependingsignal.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_releasependingsignal.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_releasependingsignal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_releasependingsignal.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_releasependingsignal.o os/kernel/signal/sig_releasependingsignal.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_removependingsignal.o: os/kernel/signal/sig_removependingsignal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_removependingsignal.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_removependingsignal.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_removependingsignal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_removependingsignal.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_removependingsignal.o os/kernel/signal/sig_removependingsignal.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_sethandler.o: os/kernel/signal/sig_sethandler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_sethandler.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_sethandler.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_sethandler.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_sethandler.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_sethandler.o os/kernel/signal/sig_sethandler.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_suspend.o: os/kernel/signal/sig_suspend.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_suspend.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_suspend.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_suspend.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_suspend.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_suspend.o os/kernel/signal/sig_suspend.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_timedwait.o: os/kernel/signal/sig_timedwait.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_timedwait.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_timedwait.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_timedwait.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_timedwait.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_timedwait.o os/kernel/signal/sig_timedwait.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_unmaskpendingsignal.o: os/kernel/signal/sig_unmaskpendingsignal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_unmaskpendingsignal.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_unmaskpendingsignal.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_unmaskpendingsignal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_unmaskpendingsignal.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_unmaskpendingsignal.o os/kernel/signal/sig_unmaskpendingsignal.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_waitinfo.o: os/kernel/signal/sig_waitinfo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_waitinfo.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_waitinfo.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_waitinfo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_waitinfo.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_waitinfo.o os/kernel/signal/sig_waitinfo.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/exit.o: os/kernel/task/exit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/exit.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/exit.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/exit.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/exit.o.d" -o ${OBJECTDIR}/os/kernel/task/exit.o os/kernel/task/exit.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_activate.o: os/kernel/task/task_activate.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_activate.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_activate.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_activate.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_activate.o.d" -o ${OBJECTDIR}/os/kernel/task/task_activate.o os/kernel/task/task_activate.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_atexit.o: os/kernel/task/task_atexit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_atexit.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_atexit.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_atexit.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_atexit.o.d" -o ${OBJECTDIR}/os/kernel/task/task_atexit.o os/kernel/task/task_atexit.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_cancelpt.o: os/kernel/task/task_cancelpt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_cancelpt.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_cancelpt.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_cancelpt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_cancelpt.o.d" -o ${OBJECTDIR}/os/kernel/task/task_cancelpt.o os/kernel/task/task_cancelpt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_create.o: os/kernel/task/task_create.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_create.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_create.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_create.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_create.o.d" -o ${OBJECTDIR}/os/kernel/task/task_create.o os/kernel/task/task_create.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_delete.o: os/kernel/task/task_delete.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_delete.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_delete.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_delete.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_delete.o.d" -o ${OBJECTDIR}/os/kernel/task/task_delete.o os/kernel/task/task_delete.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_execv.o: os/kernel/task/task_execv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_execv.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_execv.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_execv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_execv.o.d" -o ${OBJECTDIR}/os/kernel/task/task_execv.o os/kernel/task/task_execv.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_exit.o: os/kernel/task/task_exit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_exit.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_exit.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_exit.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_exit.o.d" -o ${OBJECTDIR}/os/kernel/task/task_exit.o os/kernel/task/task_exit.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_exithook.o: os/kernel/task/task_exithook.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_exithook.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_exithook.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_exithook.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_exithook.o.d" -o ${OBJECTDIR}/os/kernel/task/task_exithook.o os/kernel/task/task_exithook.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_getgroup.o: os/kernel/task/task_getgroup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_getgroup.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_getgroup.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_getgroup.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_getgroup.o.d" -o ${OBJECTDIR}/os/kernel/task/task_getgroup.o os/kernel/task/task_getgroup.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_getpid.o: os/kernel/task/task_getpid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_getpid.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_getpid.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_getpid.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_getpid.o.d" -o ${OBJECTDIR}/os/kernel/task/task_getpid.o os/kernel/task/task_getpid.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_init.o: os/kernel/task/task_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_init.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_init.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_init.o.d" -o ${OBJECTDIR}/os/kernel/task/task_init.o os/kernel/task/task_init.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_onexit.o: os/kernel/task/task_onexit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_onexit.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_onexit.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_onexit.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_onexit.o.d" -o ${OBJECTDIR}/os/kernel/task/task_onexit.o os/kernel/task/task_onexit.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_prctl.o: os/kernel/task/task_prctl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_prctl.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_prctl.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_prctl.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_prctl.o.d" -o ${OBJECTDIR}/os/kernel/task/task_prctl.o os/kernel/task/task_prctl.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_recover.o: os/kernel/task/task_recover.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_recover.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_recover.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_recover.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_recover.o.d" -o ${OBJECTDIR}/os/kernel/task/task_recover.o os/kernel/task/task_recover.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_reparent.o: os/kernel/task/task_reparent.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_reparent.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_reparent.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_reparent.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_reparent.o.d" -o ${OBJECTDIR}/os/kernel/task/task_reparent.o os/kernel/task/task_reparent.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_restart.o: os/kernel/task/task_restart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_restart.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_restart.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_restart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_restart.o.d" -o ${OBJECTDIR}/os/kernel/task/task_restart.o os/kernel/task/task_restart.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_setcancelstate.o: os/kernel/task/task_setcancelstate.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_setcancelstate.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_setcancelstate.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_setcancelstate.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_setcancelstate.o.d" -o ${OBJECTDIR}/os/kernel/task/task_setcancelstate.o os/kernel/task/task_setcancelstate.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_setcanceltype.o: os/kernel/task/task_setcanceltype.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_setcanceltype.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_setcanceltype.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_setcanceltype.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_setcanceltype.o.d" -o ${OBJECTDIR}/os/kernel/task/task_setcanceltype.o os/kernel/task/task_setcanceltype.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_setup.o: os/kernel/task/task_setup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_setup.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_setup.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_setup.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_setup.o.d" -o ${OBJECTDIR}/os/kernel/task/task_setup.o os/kernel/task/task_setup.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_start.o: os/kernel/task/task_start.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_start.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_start.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_start.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_start.o.d" -o ${OBJECTDIR}/os/kernel/task/task_start.o os/kernel/task/task_start.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_starthook.o: os/kernel/task/task_starthook.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_starthook.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_starthook.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_starthook.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_starthook.o.d" -o ${OBJECTDIR}/os/kernel/task/task_starthook.o os/kernel/task/task_starthook.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_terminate.o: os/kernel/task/task_terminate.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_terminate.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_terminate.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_terminate.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_terminate.o.d" -o ${OBJECTDIR}/os/kernel/task/task_terminate.o os/kernel/task/task_terminate.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_testcancel.o: os/kernel/task/task_testcancel.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_testcancel.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_testcancel.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_testcancel.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_testcancel.o.d" -o ${OBJECTDIR}/os/kernel/task/task_testcancel.o os/kernel/task/task_testcancel.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_vfork.o: os/kernel/task/task_vfork.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_vfork.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_vfork.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_vfork.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_vfork.o.d" -o ${OBJECTDIR}/os/kernel/task/task_vfork.o os/kernel/task/task_vfork.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/timer/timer_create.o: os/kernel/timer/timer_create.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/timer" 
	@${RM} ${OBJECTDIR}/os/kernel/timer/timer_create.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/timer/timer_create.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/timer/timer_create.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/timer/timer_create.o.d" -o ${OBJECTDIR}/os/kernel/timer/timer_create.o os/kernel/timer/timer_create.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/timer/timer_delete.o: os/kernel/timer/timer_delete.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/timer" 
	@${RM} ${OBJECTDIR}/os/kernel/timer/timer_delete.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/timer/timer_delete.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/timer/timer_delete.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/timer/timer_delete.o.d" -o ${OBJECTDIR}/os/kernel/timer/timer_delete.o os/kernel/timer/timer_delete.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/timer/timer_getoverrun.o: os/kernel/timer/timer_getoverrun.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/timer" 
	@${RM} ${OBJECTDIR}/os/kernel/timer/timer_getoverrun.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/timer/timer_getoverrun.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/timer/timer_getoverrun.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/timer/timer_getoverrun.o.d" -o ${OBJECTDIR}/os/kernel/timer/timer_getoverrun.o os/kernel/timer/timer_getoverrun.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/timer/timer_gettime.o: os/kernel/timer/timer_gettime.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/timer" 
	@${RM} ${OBJECTDIR}/os/kernel/timer/timer_gettime.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/timer/timer_gettime.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/timer/timer_gettime.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/timer/timer_gettime.o.d" -o ${OBJECTDIR}/os/kernel/timer/timer_gettime.o os/kernel/timer/timer_gettime.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/timer/timer_initialize.o: os/kernel/timer/timer_initialize.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/timer" 
	@${RM} ${OBJECTDIR}/os/kernel/timer/timer_initialize.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/timer/timer_initialize.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/timer/timer_initialize.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/timer/timer_initialize.o.d" -o ${OBJECTDIR}/os/kernel/timer/timer_initialize.o os/kernel/timer/timer_initialize.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/timer/timer_release.o: os/kernel/timer/timer_release.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/timer" 
	@${RM} ${OBJECTDIR}/os/kernel/timer/timer_release.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/timer/timer_release.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/timer/timer_release.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/timer/timer_release.o.d" -o ${OBJECTDIR}/os/kernel/timer/timer_release.o os/kernel/timer/timer_release.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/timer/timer_settime.o: os/kernel/timer/timer_settime.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/timer" 
	@${RM} ${OBJECTDIR}/os/kernel/timer/timer_settime.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/timer/timer_settime.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/timer/timer_settime.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/timer/timer_settime.o.d" -o ${OBJECTDIR}/os/kernel/timer/timer_settime.o os/kernel/timer/timer_settime.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/wdog/wd_cancel.o: os/kernel/wdog/wd_cancel.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/wdog" 
	@${RM} ${OBJECTDIR}/os/kernel/wdog/wd_cancel.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/wdog/wd_cancel.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/wdog/wd_cancel.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/wdog/wd_cancel.o.d" -o ${OBJECTDIR}/os/kernel/wdog/wd_cancel.o os/kernel/wdog/wd_cancel.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/wdog/wd_create.o: os/kernel/wdog/wd_create.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/wdog" 
	@${RM} ${OBJECTDIR}/os/kernel/wdog/wd_create.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/wdog/wd_create.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/wdog/wd_create.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/wdog/wd_create.o.d" -o ${OBJECTDIR}/os/kernel/wdog/wd_create.o os/kernel/wdog/wd_create.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/wdog/wd_delete.o: os/kernel/wdog/wd_delete.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/wdog" 
	@${RM} ${OBJECTDIR}/os/kernel/wdog/wd_delete.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/wdog/wd_delete.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/wdog/wd_delete.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/wdog/wd_delete.o.d" -o ${OBJECTDIR}/os/kernel/wdog/wd_delete.o os/kernel/wdog/wd_delete.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/wdog/wd_gettime.o: os/kernel/wdog/wd_gettime.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/wdog" 
	@${RM} ${OBJECTDIR}/os/kernel/wdog/wd_gettime.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/wdog/wd_gettime.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/wdog/wd_gettime.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/wdog/wd_gettime.o.d" -o ${OBJECTDIR}/os/kernel/wdog/wd_gettime.o os/kernel/wdog/wd_gettime.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/wdog/wd_initialize.o: os/kernel/wdog/wd_initialize.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/wdog" 
	@${RM} ${OBJECTDIR}/os/kernel/wdog/wd_initialize.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/wdog/wd_initialize.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/wdog/wd_initialize.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/wdog/wd_initialize.o.d" -o ${OBJECTDIR}/os/kernel/wdog/wd_initialize.o os/kernel/wdog/wd_initialize.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/wdog/wd_recover.o: os/kernel/wdog/wd_recover.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/wdog" 
	@${RM} ${OBJECTDIR}/os/kernel/wdog/wd_recover.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/wdog/wd_recover.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/wdog/wd_recover.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/wdog/wd_recover.o.d" -o ${OBJECTDIR}/os/kernel/wdog/wd_recover.o os/kernel/wdog/wd_recover.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/wdog/wd_start.o: os/kernel/wdog/wd_start.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/wdog" 
	@${RM} ${OBJECTDIR}/os/kernel/wdog/wd_start.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/wdog/wd_start.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/wdog/wd_start.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/wdog/wd_start.o.d" -o ${OBJECTDIR}/os/kernel/wdog/wd_start.o os/kernel/wdog/wd_start.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/mm/kmm_heap/kmm.o: os/mm/kmm_heap/kmm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/mm/kmm_heap" 
	@${RM} ${OBJECTDIR}/os/mm/kmm_heap/kmm.o.d 
	@${RM} ${OBJECTDIR}/os/mm/kmm_heap/kmm.o 
	@${FIXDEPS} "${OBJECTDIR}/os/mm/kmm_heap/kmm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/mm/kmm_heap/kmm.o.d" -o ${OBJECTDIR}/os/mm/kmm_heap/kmm.o os/mm/kmm_heap/kmm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/mm/mm_heap/mm_heap.o: os/mm/mm_heap/mm_heap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/mm/mm_heap" 
	@${RM} ${OBJECTDIR}/os/mm/mm_heap/mm_heap.o.d 
	@${RM} ${OBJECTDIR}/os/mm/mm_heap/mm_heap.o 
	@${FIXDEPS} "${OBJECTDIR}/os/mm/mm_heap/mm_heap.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/mm/mm_heap/mm_heap.o.d" -o ${OBJECTDIR}/os/mm/mm_heap/mm_heap.o os/mm/mm_heap/mm_heap.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/mm/umm_heap/umm.o: os/mm/umm_heap/umm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/mm/umm_heap" 
	@${RM} ${OBJECTDIR}/os/mm/umm_heap/umm.o.d 
	@${RM} ${OBJECTDIR}/os/mm/umm_heap/umm.o 
	@${FIXDEPS} "${OBJECTDIR}/os/mm/umm_heap/umm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/mm/umm_heap/umm.o.d" -o ${OBJECTDIR}/os/mm/umm_heap/umm.o os/mm/umm_heap/umm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/HELP.o: os/arch/HELP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch" 
	@${RM} ${OBJECTDIR}/os/arch/HELP.o.d 
	@${RM} ${OBJECTDIR}/os/arch/HELP.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/HELP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/HELP.o.d" -o ${OBJECTDIR}/os/arch/HELP.o os/arch/HELP.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/sys_config.o: sys_config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/sys_config.o.d 
	@${RM} ${OBJECTDIR}/sys_config.o 
	@${FIXDEPS} "${OBJECTDIR}/sys_config.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/sys_config.o.d" -o ${OBJECTDIR}/sys_config.o sys_config.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/drivers/dev_null.o: os/drivers/dev_null.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/drivers" 
	@${RM} ${OBJECTDIR}/os/drivers/dev_null.o.d 
	@${RM} ${OBJECTDIR}/os/drivers/dev_null.o 
	@${FIXDEPS} "${OBJECTDIR}/os/drivers/dev_null.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/drivers/dev_null.o.d" -o ${OBJECTDIR}/os/drivers/dev_null.o os/drivers/dev_null.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/drivers/dev_zero.o: os/drivers/dev_zero.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/drivers" 
	@${RM} ${OBJECTDIR}/os/drivers/dev_zero.o.d 
	@${RM} ${OBJECTDIR}/os/drivers/dev_zero.o 
	@${FIXDEPS} "${OBJECTDIR}/os/drivers/dev_zero.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/drivers/dev_zero.o.d" -o ${OBJECTDIR}/os/drivers/dev_zero.o os/drivers/dev_zero.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
else
${OBJECTDIR}/lib/libc/aio/wiz_aio.o: lib/libc/aio/wiz_aio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/aio" 
	@${RM} ${OBJECTDIR}/lib/libc/aio/wiz_aio.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/aio/wiz_aio.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/aio/wiz_aio.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/aio/wiz_aio.o.d" -o ${OBJECTDIR}/lib/libc/aio/wiz_aio.o lib/libc/aio/wiz_aio.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/audio/lib_buffer.o: lib/libc/audio/lib_buffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/audio" 
	@${RM} ${OBJECTDIR}/lib/libc/audio/lib_buffer.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/audio/lib_buffer.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/audio/lib_buffer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/audio/lib_buffer.o.d" -o ${OBJECTDIR}/lib/libc/audio/lib_buffer.o lib/libc/audio/lib_buffer.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/dirent/wiz_dirent.o: lib/libc/dirent/wiz_dirent.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/dirent" 
	@${RM} ${OBJECTDIR}/lib/libc/dirent/wiz_dirent.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/dirent/wiz_dirent.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/dirent/wiz_dirent.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/dirent/wiz_dirent.o.d" -o ${OBJECTDIR}/lib/libc/dirent/wiz_dirent.o lib/libc/dirent/wiz_dirent.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/fixedmath/wiz_fixedmath.o: lib/libc/fixedmath/wiz_fixedmath.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/fixedmath" 
	@${RM} ${OBJECTDIR}/lib/libc/fixedmath/wiz_fixedmath.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/fixedmath/wiz_fixedmath.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/fixedmath/wiz_fixedmath.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/fixedmath/wiz_fixedmath.o.d" -o ${OBJECTDIR}/lib/libc/fixedmath/wiz_fixedmath.o lib/libc/fixedmath/wiz_fixedmath.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/inttypes/wiz_inttipes.o: lib/libc/inttypes/wiz_inttipes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/inttypes" 
	@${RM} ${OBJECTDIR}/lib/libc/inttypes/wiz_inttipes.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/inttypes/wiz_inttipes.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/inttypes/wiz_inttipes.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/inttypes/wiz_inttipes.o.d" -o ${OBJECTDIR}/lib/libc/inttypes/wiz_inttipes.o lib/libc/inttypes/wiz_inttipes.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/libgen/wiz_libgen.o: lib/libc/libgen/wiz_libgen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/libgen" 
	@${RM} ${OBJECTDIR}/lib/libc/libgen/wiz_libgen.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/libgen/wiz_libgen.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/libgen/wiz_libgen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/libgen/wiz_libgen.o.d" -o ${OBJECTDIR}/lib/libc/libgen/wiz_libgen.o lib/libc/libgen/wiz_libgen.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/locale/wiz_locale.o: lib/libc/locale/wiz_locale.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/locale" 
	@${RM} ${OBJECTDIR}/lib/libc/locale/wiz_locale.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/locale/wiz_locale.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/locale/wiz_locale.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/locale/wiz_locale.o.d" -o ${OBJECTDIR}/lib/libc/locale/wiz_locale.o lib/libc/locale/wiz_locale.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/math/fpclassify.o: lib/libc/math/fpclassify.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/math" 
	@${RM} ${OBJECTDIR}/lib/libc/math/fpclassify.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/math/fpclassify.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/math/fpclassify.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/math/fpclassify.o.d" -o ${OBJECTDIR}/lib/libc/math/fpclassify.o lib/libc/math/fpclassify.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/misc/wiz_misc.o: lib/libc/misc/wiz_misc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/misc" 
	@${RM} ${OBJECTDIR}/lib/libc/misc/wiz_misc.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/misc/wiz_misc.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/misc/wiz_misc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/misc/wiz_misc.o.d" -o ${OBJECTDIR}/lib/libc/misc/wiz_misc.o lib/libc/misc/wiz_misc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/mqueue/wiz_mqueue.o: lib/libc/mqueue/wiz_mqueue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/mqueue" 
	@${RM} ${OBJECTDIR}/lib/libc/mqueue/wiz_mqueue.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/mqueue/wiz_mqueue.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/mqueue/wiz_mqueue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/mqueue/wiz_mqueue.o.d" -o ${OBJECTDIR}/lib/libc/mqueue/wiz_mqueue.o lib/libc/mqueue/wiz_mqueue.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/net/wiz_net.o: lib/libc/net/wiz_net.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/net" 
	@${RM} ${OBJECTDIR}/lib/libc/net/wiz_net.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/net/wiz_net.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/net/wiz_net.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/net/wiz_net.o.d" -o ${OBJECTDIR}/lib/libc/net/wiz_net.o lib/libc/net/wiz_net.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/pthread/wiz_pthread.o: lib/libc/pthread/wiz_pthread.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/pthread" 
	@${RM} ${OBJECTDIR}/lib/libc/pthread/wiz_pthread.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/pthread/wiz_pthread.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/pthread/wiz_pthread.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/pthread/wiz_pthread.o.d" -o ${OBJECTDIR}/lib/libc/pthread/wiz_pthread.o lib/libc/pthread/wiz_pthread.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/queue/wiz_queue.o: lib/libc/queue/wiz_queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/queue" 
	@${RM} ${OBJECTDIR}/lib/libc/queue/wiz_queue.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/queue/wiz_queue.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/queue/wiz_queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/queue/wiz_queue.o.d" -o ${OBJECTDIR}/lib/libc/queue/wiz_queue.o lib/libc/queue/wiz_queue.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/sched/wiz_sched.o: lib/libc/sched/wiz_sched.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/sched" 
	@${RM} ${OBJECTDIR}/lib/libc/sched/wiz_sched.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/sched/wiz_sched.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/sched/wiz_sched.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/sched/wiz_sched.o.d" -o ${OBJECTDIR}/lib/libc/sched/wiz_sched.o lib/libc/sched/wiz_sched.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/semaphore/wiz_semaphore.o: lib/libc/semaphore/wiz_semaphore.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/semaphore" 
	@${RM} ${OBJECTDIR}/lib/libc/semaphore/wiz_semaphore.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/semaphore/wiz_semaphore.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/semaphore/wiz_semaphore.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/semaphore/wiz_semaphore.o.d" -o ${OBJECTDIR}/lib/libc/semaphore/wiz_semaphore.o lib/libc/semaphore/wiz_semaphore.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/signal/wiz_signal.o: lib/libc/signal/wiz_signal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/signal" 
	@${RM} ${OBJECTDIR}/lib/libc/signal/wiz_signal.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/signal/wiz_signal.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/signal/wiz_signal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/signal/wiz_signal.o.d" -o ${OBJECTDIR}/lib/libc/signal/wiz_signal.o lib/libc/signal/wiz_signal.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/stdio/wiz_stdio.o: lib/libc/stdio/wiz_stdio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/stdio" 
	@${RM} ${OBJECTDIR}/lib/libc/stdio/wiz_stdio.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/stdio/wiz_stdio.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/stdio/wiz_stdio.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/stdio/wiz_stdio.o.d" -o ${OBJECTDIR}/lib/libc/stdio/wiz_stdio.o lib/libc/stdio/wiz_stdio.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/stdlib/wiz_stdlib.o: lib/libc/stdlib/wiz_stdlib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/stdlib" 
	@${RM} ${OBJECTDIR}/lib/libc/stdlib/wiz_stdlib.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/stdlib/wiz_stdlib.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/stdlib/wiz_stdlib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/stdlib/wiz_stdlib.o.d" -o ${OBJECTDIR}/lib/libc/stdlib/wiz_stdlib.o lib/libc/stdlib/wiz_stdlib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/string/wiz_string.o: lib/libc/string/wiz_string.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/string" 
	@${RM} ${OBJECTDIR}/lib/libc/string/wiz_string.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/string/wiz_string.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/string/wiz_string.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/string/wiz_string.o.d" -o ${OBJECTDIR}/lib/libc/string/wiz_string.o lib/libc/string/wiz_string.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/syslog/wiz_syslog.o: lib/libc/syslog/wiz_syslog.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/syslog" 
	@${RM} ${OBJECTDIR}/lib/libc/syslog/wiz_syslog.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/syslog/wiz_syslog.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/syslog/wiz_syslog.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/syslog/wiz_syslog.o.d" -o ${OBJECTDIR}/lib/libc/syslog/wiz_syslog.o lib/libc/syslog/wiz_syslog.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/termios/wiz_termios.o: lib/libc/termios/wiz_termios.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/termios" 
	@${RM} ${OBJECTDIR}/lib/libc/termios/wiz_termios.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/termios/wiz_termios.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/termios/wiz_termios.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/termios/wiz_termios.o.d" -o ${OBJECTDIR}/lib/libc/termios/wiz_termios.o lib/libc/termios/wiz_termios.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/time/wiz_time.o: lib/libc/time/wiz_time.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/time" 
	@${RM} ${OBJECTDIR}/lib/libc/time/wiz_time.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/time/wiz_time.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/time/wiz_time.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/time/wiz_time.o.d" -o ${OBJECTDIR}/lib/libc/time/wiz_time.o lib/libc/time/wiz_time.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/unistd/wiz_unistd.o: lib/libc/unistd/wiz_unistd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/unistd" 
	@${RM} ${OBJECTDIR}/lib/libc/unistd/wiz_unistd.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/unistd/wiz_unistd.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/unistd/wiz_unistd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/unistd/wiz_unistd.o.d" -o ${OBJECTDIR}/lib/libc/unistd/wiz_unistd.o lib/libc/unistd/wiz_unistd.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/wchar/wiz_wchar.o: lib/libc/wchar/wiz_wchar.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/wchar" 
	@${RM} ${OBJECTDIR}/lib/libc/wchar/wiz_wchar.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/wchar/wiz_wchar.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/wchar/wiz_wchar.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/wchar/wiz_wchar.o.d" -o ${OBJECTDIR}/lib/libc/wchar/wiz_wchar.o lib/libc/wchar/wiz_wchar.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/wctype/wiz_wctype.o: lib/libc/wctype/wiz_wctype.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/wctype" 
	@${RM} ${OBJECTDIR}/lib/libc/wctype/wiz_wctype.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/wctype/wiz_wctype.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/wctype/wiz_wctype.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/wctype/wiz_wctype.o.d" -o ${OBJECTDIR}/lib/libc/wctype/wiz_wctype.o lib/libc/wctype/wiz_wctype.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libc/wqueue/wiz_wqueue.o: lib/libc/wqueue/wiz_wqueue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libc/wqueue" 
	@${RM} ${OBJECTDIR}/lib/libc/wqueue/wiz_wqueue.o.d 
	@${RM} ${OBJECTDIR}/lib/libc/wqueue/wiz_wqueue.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libc/wqueue/wiz_wqueue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libc/wqueue/wiz_wqueue.o.d" -o ${OBJECTDIR}/lib/libc/wqueue/wiz_wqueue.o lib/libc/wqueue/wiz_wqueue.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/lib/libxx/libxx_newlib_impure.o: lib/libxx/libxx_newlib_impure.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lib/libxx" 
	@${RM} ${OBJECTDIR}/lib/libxx/libxx_newlib_impure.o.d 
	@${RM} ${OBJECTDIR}/lib/libxx/libxx_newlib_impure.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/libxx/libxx_newlib_impure.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/lib/libxx/libxx_newlib_impure.o.d" -o ${OBJECTDIR}/lib/libxx/libxx_newlib_impure.o lib/libxx/libxx_newlib_impure.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/board/curiosity/pic32mz_boot.o: os/arch/board/curiosity/pic32mz_boot.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/board/curiosity" 
	@${RM} ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_boot.o.d 
	@${RM} ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_boot.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/board/curiosity/pic32mz_boot.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/board/curiosity/pic32mz_boot.o.d" -o ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_boot.o os/arch/board/curiosity/pic32mz_boot.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/board/curiosity/pic32mz_userleds.o: os/arch/board/curiosity/pic32mz_userleds.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/board/curiosity" 
	@${RM} ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_userleds.o.d 
	@${RM} ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_userleds.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/board/curiosity/pic32mz_userleds.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/board/curiosity/pic32mz_userleds.o.d" -o ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_userleds.o os/arch/board/curiosity/pic32mz_userleds.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/board/curiosity/pic32mz_autoleds.o: os/arch/board/curiosity/pic32mz_autoleds.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/board/curiosity" 
	@${RM} ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_autoleds.o.d 
	@${RM} ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_autoleds.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/board/curiosity/pic32mz_autoleds.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/board/curiosity/pic32mz_autoleds.o.d" -o ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_autoleds.o os/arch/board/curiosity/pic32mz_autoleds.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/board/curiosity/pic32mz_bringup.o: os/arch/board/curiosity/pic32mz_bringup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/board/curiosity" 
	@${RM} ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_bringup.o.d 
	@${RM} ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_bringup.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/board/curiosity/pic32mz_bringup.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/board/curiosity/pic32mz_bringup.o.d" -o ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_bringup.o os/arch/board/curiosity/pic32mz_bringup.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/board/curiosity/pic32mz_buttons.o: os/arch/board/curiosity/pic32mz_buttons.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/board/curiosity" 
	@${RM} ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_buttons.o.d 
	@${RM} ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_buttons.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/board/curiosity/pic32mz_buttons.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/board/curiosity/pic32mz_buttons.o.d" -o ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_buttons.o os/arch/board/curiosity/pic32mz_buttons.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/board/curiosity/pic32mz_nsh.o: os/arch/board/curiosity/pic32mz_nsh.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/board/curiosity" 
	@${RM} ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_nsh.o.d 
	@${RM} ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_nsh.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/board/curiosity/pic32mz_nsh.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/board/curiosity/pic32mz_nsh.o.d" -o ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_nsh.o os/arch/board/curiosity/pic32mz_nsh.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/board/curiosity/pic32mz_spi.o: os/arch/board/curiosity/pic32mz_spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/board/curiosity" 
	@${RM} ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_spi.o.d 
	@${RM} ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_spi.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/board/curiosity/pic32mz_spi.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/board/curiosity/pic32mz_spi.o.d" -o ${OBJECTDIR}/os/arch/board/curiosity/pic32mz_spi.o os/arch/board/curiosity/pic32mz_spi.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_allocateheap.o: os/arch/mips/src/common/up_allocateheap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_allocateheap.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_allocateheap.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_allocateheap.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_allocateheap.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_allocateheap.o os/arch/mips/src/common/up_allocateheap.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_createstack.o: os/arch/mips/src/common/up_createstack.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_createstack.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_createstack.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_createstack.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_createstack.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_createstack.o os/arch/mips/src/common/up_createstack.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_etherstub.o: os/arch/mips/src/common/up_etherstub.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_etherstub.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_etherstub.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_etherstub.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_etherstub.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_etherstub.o os/arch/mips/src/common/up_etherstub.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_exit.o: os/arch/mips/src/common/up_exit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_exit.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_exit.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_exit.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_exit.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_exit.o os/arch/mips/src/common/up_exit.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_idle.o: os/arch/mips/src/common/up_idle.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_idle.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_idle.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_idle.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_idle.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_idle.o os/arch/mips/src/common/up_idle.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_initialize.o: os/arch/mips/src/common/up_initialize.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_initialize.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_initialize.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_initialize.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_initialize.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_initialize.o os/arch/mips/src/common/up_initialize.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_interruptcontext.o: os/arch/mips/src/common/up_interruptcontext.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_interruptcontext.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_interruptcontext.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_interruptcontext.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_interruptcontext.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_interruptcontext.o os/arch/mips/src/common/up_interruptcontext.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_lowputs.o: os/arch/mips/src/common/up_lowputs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_lowputs.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_lowputs.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_lowputs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_lowputs.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_lowputs.o os/arch/mips/src/common/up_lowputs.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_mdelay.o: os/arch/mips/src/common/up_mdelay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_mdelay.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_mdelay.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_mdelay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_mdelay.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_mdelay.o os/arch/mips/src/common/up_mdelay.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg16.o: os/arch/mips/src/common/up_modifyreg16.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg16.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg16.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg16.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg16.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg16.o os/arch/mips/src/common/up_modifyreg16.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg32.o: os/arch/mips/src/common/up_modifyreg32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg32.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg32.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg32.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg32.o os/arch/mips/src/common/up_modifyreg32.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg8.o: os/arch/mips/src/common/up_modifyreg8.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg8.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg8.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg8.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg8.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_modifyreg8.o os/arch/mips/src/common/up_modifyreg8.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_puts.o: os/arch/mips/src/common/up_puts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_puts.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_puts.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_puts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_puts.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_puts.o os/arch/mips/src/common/up_puts.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_releasestack.o: os/arch/mips/src/common/up_releasestack.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_releasestack.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_releasestack.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_releasestack.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_releasestack.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_releasestack.o os/arch/mips/src/common/up_releasestack.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_stackframe.o: os/arch/mips/src/common/up_stackframe.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_stackframe.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_stackframe.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_stackframe.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_stackframe.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_stackframe.o os/arch/mips/src/common/up_stackframe.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_udelay.o: os/arch/mips/src/common/up_udelay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_udelay.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_udelay.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_udelay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_udelay.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_udelay.o os/arch/mips/src/common/up_udelay.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/common/up_usestack.o: os/arch/mips/src/common/up_usestack.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/common" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_usestack.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/common/up_usestack.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/common/up_usestack.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/common/up_usestack.o.d" -o ${OBJECTDIR}/os/arch/mips/src/common/up_usestack.o os/arch/mips/src/common/up_usestack.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/mips32/up_assert.o: os/arch/mips/src/mips32/up_assert.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_assert.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_assert.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_assert.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_assert.o.d" -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_assert.o os/arch/mips/src/mips32/up_assert.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/mips32/up_blocktask.o: os/arch/mips/src/mips32/up_blocktask.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_blocktask.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_blocktask.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_blocktask.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_blocktask.o.d" -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_blocktask.o os/arch/mips/src/mips32/up_blocktask.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/mips32/up_copystate.o: os/arch/mips/src/mips32/up_copystate.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_copystate.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_copystate.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_copystate.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_copystate.o.d" -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_copystate.o os/arch/mips/src/mips32/up_copystate.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/mips32/up_doirq.o: os/arch/mips/src/mips32/up_doirq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_doirq.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_doirq.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_doirq.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_doirq.o.d" -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_doirq.o os/arch/mips/src/mips32/up_doirq.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/mips32/up_dumpstate.o: os/arch/mips/src/mips32/up_dumpstate.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_dumpstate.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_dumpstate.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_dumpstate.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_dumpstate.o.d" -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_dumpstate.o os/arch/mips/src/mips32/up_dumpstate.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/mips32/up_initialstate.o: os/arch/mips/src/mips32/up_initialstate.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_initialstate.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_initialstate.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_initialstate.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_initialstate.o.d" -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_initialstate.o os/arch/mips/src/mips32/up_initialstate.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/mips32/up_irq.o: os/arch/mips/src/mips32/up_irq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_irq.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_irq.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_irq.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_irq.o.d" -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_irq.o os/arch/mips/src/mips32/up_irq.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/mips32/up_releasepending.o: os/arch/mips/src/mips32/up_releasepending.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_releasepending.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_releasepending.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_releasepending.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_releasepending.o.d" -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_releasepending.o os/arch/mips/src/mips32/up_releasepending.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/mips32/up_reprioritizertr.o: os/arch/mips/src/mips32/up_reprioritizertr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_reprioritizertr.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_reprioritizertr.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_reprioritizertr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_reprioritizertr.o.d" -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_reprioritizertr.o os/arch/mips/src/mips32/up_reprioritizertr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/mips32/up_schedulesigaction.o: os/arch/mips/src/mips32/up_schedulesigaction.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_schedulesigaction.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_schedulesigaction.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_schedulesigaction.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_schedulesigaction.o.d" -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_schedulesigaction.o os/arch/mips/src/mips32/up_schedulesigaction.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/mips32/up_sigdeliver.o: os/arch/mips/src/mips32/up_sigdeliver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_sigdeliver.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_sigdeliver.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_sigdeliver.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_sigdeliver.o.d" -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_sigdeliver.o os/arch/mips/src/mips32/up_sigdeliver.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/mips32/up_swint0.o: os/arch/mips/src/mips32/up_swint0.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_swint0.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_swint0.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_swint0.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_swint0.o.d" -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_swint0.o os/arch/mips/src/mips32/up_swint0.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/mips32/up_unblocktask.o: os/arch/mips/src/mips32/up_unblocktask.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_unblocktask.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_unblocktask.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_unblocktask.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_unblocktask.o.d" -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_unblocktask.o os/arch/mips/src/mips32/up_unblocktask.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/mips32/up_vfork.o: os/arch/mips/src/mips32/up_vfork.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/mips32" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_vfork.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/mips32/up_vfork.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/mips32/up_vfork.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/mips32/up_vfork.o.d" -o ${OBJECTDIR}/os/arch/mips/src/mips32/up_vfork.o os/arch/mips/src/mips32/up_vfork.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-decodeirq.o: os/arch/mips/src/pic32mz/pic32mz-decodeirq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/pic32mz" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-decodeirq.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-decodeirq.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-decodeirq.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-decodeirq.o.d" -o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-decodeirq.o os/arch/mips/src/pic32mz/pic32mz-decodeirq.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-ethernet.o: os/arch/mips/src/pic32mz/pic32mz-ethernet.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/pic32mz" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-ethernet.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-ethernet.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-ethernet.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-ethernet.o.d" -o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-ethernet.o os/arch/mips/src/pic32mz/pic32mz-ethernet.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-exception.o: os/arch/mips/src/pic32mz/pic32mz-exception.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/pic32mz" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-exception.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-exception.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-exception.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-exception.o.d" -o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-exception.o os/arch/mips/src/pic32mz/pic32mz-exception.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpio.o: os/arch/mips/src/pic32mz/pic32mz-gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/pic32mz" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpio.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpio.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpio.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpio.o.d" -o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpio.o os/arch/mips/src/pic32mz/pic32mz-gpio.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpioirq.o: os/arch/mips/src/pic32mz/pic32mz-gpioirq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/pic32mz" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpioirq.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpioirq.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpioirq.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpioirq.o.d" -o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-gpioirq.o os/arch/mips/src/pic32mz/pic32mz-gpioirq.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-irq.o: os/arch/mips/src/pic32mz/pic32mz-irq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/pic32mz" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-irq.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-irq.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-irq.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-irq.o.d" -o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-irq.o os/arch/mips/src/pic32mz/pic32mz-irq.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowconsole.o: os/arch/mips/src/pic32mz/pic32mz-lowconsole.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/pic32mz" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowconsole.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowconsole.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowconsole.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowconsole.o.d" -o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowconsole.o os/arch/mips/src/pic32mz/pic32mz-lowconsole.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowinit.o: os/arch/mips/src/pic32mz/pic32mz-lowinit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/pic32mz" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowinit.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowinit.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowinit.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowinit.o.d" -o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-lowinit.o os/arch/mips/src/pic32mz/pic32mz-lowinit.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-serial.o: os/arch/mips/src/pic32mz/pic32mz-serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/pic32mz" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-serial.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-serial.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-serial.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-serial.o.d" -o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-serial.o os/arch/mips/src/pic32mz/pic32mz-serial.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-spi.o: os/arch/mips/src/pic32mz/pic32mz-spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/pic32mz" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-spi.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-spi.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-spi.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-spi.o.d" -o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-spi.o os/arch/mips/src/pic32mz/pic32mz-spi.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-timerisr.o: os/arch/mips/src/pic32mz/pic32mz-timerisr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch/mips/src/pic32mz" 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-timerisr.o.d 
	@${RM} ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-timerisr.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-timerisr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-timerisr.o.d" -o ${OBJECTDIR}/os/arch/mips/src/pic32mz/pic32mz-timerisr.o os/arch/mips/src/pic32mz/pic32mz-timerisr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/drivers/bch/bch.o: os/drivers/bch/bch.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/drivers/bch" 
	@${RM} ${OBJECTDIR}/os/drivers/bch/bch.o.d 
	@${RM} ${OBJECTDIR}/os/drivers/bch/bch.o 
	@${FIXDEPS} "${OBJECTDIR}/os/drivers/bch/bch.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/drivers/bch/bch.o.d" -o ${OBJECTDIR}/os/drivers/bch/bch.o os/drivers/bch/bch.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/drivers/serial/lowconsole.o: os/drivers/serial/lowconsole.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/drivers/serial" 
	@${RM} ${OBJECTDIR}/os/drivers/serial/lowconsole.o.d 
	@${RM} ${OBJECTDIR}/os/drivers/serial/lowconsole.o 
	@${FIXDEPS} "${OBJECTDIR}/os/drivers/serial/lowconsole.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/drivers/serial/lowconsole.o.d" -o ${OBJECTDIR}/os/drivers/serial/lowconsole.o os/drivers/serial/lowconsole.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/drivers/serial/serial.o: os/drivers/serial/serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/drivers/serial" 
	@${RM} ${OBJECTDIR}/os/drivers/serial/serial.o.d 
	@${RM} ${OBJECTDIR}/os/drivers/serial/serial.o 
	@${FIXDEPS} "${OBJECTDIR}/os/drivers/serial/serial.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/drivers/serial/serial.o.d" -o ${OBJECTDIR}/os/drivers/serial/serial.o os/drivers/serial/serial.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/drivers/serial/serialirq.o: os/drivers/serial/serialirq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/drivers/serial" 
	@${RM} ${OBJECTDIR}/os/drivers/serial/serialirq.o.d 
	@${RM} ${OBJECTDIR}/os/drivers/serial/serialirq.o 
	@${FIXDEPS} "${OBJECTDIR}/os/drivers/serial/serialirq.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/drivers/serial/serialirq.o.d" -o ${OBJECTDIR}/os/drivers/serial/serialirq.o os/drivers/serial/serialirq.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/drivers/syslog/ramlog.o: os/drivers/syslog/ramlog.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/drivers/syslog" 
	@${RM} ${OBJECTDIR}/os/drivers/syslog/ramlog.o.d 
	@${RM} ${OBJECTDIR}/os/drivers/syslog/ramlog.o 
	@${FIXDEPS} "${OBJECTDIR}/os/drivers/syslog/ramlog.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/drivers/syslog/ramlog.o.d" -o ${OBJECTDIR}/os/drivers/syslog/ramlog.o os/drivers/syslog/ramlog.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/drivers/syslog/syslog_console.o: os/drivers/syslog/syslog_console.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/drivers/syslog" 
	@${RM} ${OBJECTDIR}/os/drivers/syslog/syslog_console.o.d 
	@${RM} ${OBJECTDIR}/os/drivers/syslog/syslog_console.o 
	@${FIXDEPS} "${OBJECTDIR}/os/drivers/syslog/syslog_console.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/drivers/syslog/syslog_console.o.d" -o ${OBJECTDIR}/os/drivers/syslog/syslog_console.o os/drivers/syslog/syslog_console.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/fs/aio/fs_aio.o: os/fs/aio/fs_aio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/fs/aio" 
	@${RM} ${OBJECTDIR}/os/fs/aio/fs_aio.o.d 
	@${RM} ${OBJECTDIR}/os/fs/aio/fs_aio.o 
	@${FIXDEPS} "${OBJECTDIR}/os/fs/aio/fs_aio.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/fs/aio/fs_aio.o.d" -o ${OBJECTDIR}/os/fs/aio/fs_aio.o os/fs/aio/fs_aio.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/fs/dirent/fs_dirent.o: os/fs/dirent/fs_dirent.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/fs/dirent" 
	@${RM} ${OBJECTDIR}/os/fs/dirent/fs_dirent.o.d 
	@${RM} ${OBJECTDIR}/os/fs/dirent/fs_dirent.o 
	@${FIXDEPS} "${OBJECTDIR}/os/fs/dirent/fs_dirent.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/fs/dirent/fs_dirent.o.d" -o ${OBJECTDIR}/os/fs/dirent/fs_dirent.o os/fs/dirent/fs_dirent.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/fs/driver/block/fs_block.o: os/fs/driver/block/fs_block.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/fs/driver/block" 
	@${RM} ${OBJECTDIR}/os/fs/driver/block/fs_block.o.d 
	@${RM} ${OBJECTDIR}/os/fs/driver/block/fs_block.o 
	@${FIXDEPS} "${OBJECTDIR}/os/fs/driver/block/fs_block.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/fs/driver/block/fs_block.o.d" -o ${OBJECTDIR}/os/fs/driver/block/fs_block.o os/fs/driver/block/fs_block.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/fs/driver/block/ramdisk.o: os/fs/driver/block/ramdisk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/fs/driver/block" 
	@${RM} ${OBJECTDIR}/os/fs/driver/block/ramdisk.o.d 
	@${RM} ${OBJECTDIR}/os/fs/driver/block/ramdisk.o 
	@${FIXDEPS} "${OBJECTDIR}/os/fs/driver/block/ramdisk.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/fs/driver/block/ramdisk.o.d" -o ${OBJECTDIR}/os/fs/driver/block/ramdisk.o os/fs/driver/block/ramdisk.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/fs/inode/fs_inode.o: os/fs/inode/fs_inode.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/fs/inode" 
	@${RM} ${OBJECTDIR}/os/fs/inode/fs_inode.o.d 
	@${RM} ${OBJECTDIR}/os/fs/inode/fs_inode.o 
	@${FIXDEPS} "${OBJECTDIR}/os/fs/inode/fs_inode.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/fs/inode/fs_inode.o.d" -o ${OBJECTDIR}/os/fs/inode/fs_inode.o os/fs/inode/fs_inode.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/fs/mount/fs_mount.o: os/fs/mount/fs_mount.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/fs/mount" 
	@${RM} ${OBJECTDIR}/os/fs/mount/fs_mount.o.d 
	@${RM} ${OBJECTDIR}/os/fs/mount/fs_mount.o 
	@${FIXDEPS} "${OBJECTDIR}/os/fs/mount/fs_mount.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/fs/mount/fs_mount.o.d" -o ${OBJECTDIR}/os/fs/mount/fs_mount.o os/fs/mount/fs_mount.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/fs/vfs/vfs.o: os/fs/vfs/vfs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/fs/vfs" 
	@${RM} ${OBJECTDIR}/os/fs/vfs/vfs.o.d 
	@${RM} ${OBJECTDIR}/os/fs/vfs/vfs.o 
	@${FIXDEPS} "${OBJECTDIR}/os/fs/vfs/vfs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/fs/vfs/vfs.o.d" -o ${OBJECTDIR}/os/fs/vfs/vfs.o os/fs/vfs/vfs.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/fs/fs_initialize.o: os/fs/fs_initialize.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/fs" 
	@${RM} ${OBJECTDIR}/os/fs/fs_initialize.o.d 
	@${RM} ${OBJECTDIR}/os/fs/fs_initialize.o 
	@${FIXDEPS} "${OBJECTDIR}/os/fs/fs_initialize.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/fs/fs_initialize.o.d" -o ${OBJECTDIR}/os/fs/fs_initialize.o os/fs/fs_initialize.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/clock/clock.o: os/kernel/clock/clock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/clock" 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/clock/clock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/clock/clock.o.d" -o ${OBJECTDIR}/os/kernel/clock/clock.o os/kernel/clock/clock.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/clock/clock_abstime2ticks.o: os/kernel/clock/clock_abstime2ticks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/clock" 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_abstime2ticks.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_abstime2ticks.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/clock/clock_abstime2ticks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/clock/clock_abstime2ticks.o.d" -o ${OBJECTDIR}/os/kernel/clock/clock_abstime2ticks.o os/kernel/clock/clock_abstime2ticks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/clock/clock_dow.o: os/kernel/clock/clock_dow.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/clock" 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_dow.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_dow.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/clock/clock_dow.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/clock/clock_dow.o.d" -o ${OBJECTDIR}/os/kernel/clock/clock_dow.o os/kernel/clock/clock_dow.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/clock/clock_getres.o: os/kernel/clock/clock_getres.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/clock" 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_getres.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_getres.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/clock/clock_getres.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/clock/clock_getres.o.d" -o ${OBJECTDIR}/os/kernel/clock/clock_getres.o os/kernel/clock/clock_getres.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/clock/clock_gettime.o: os/kernel/clock/clock_gettime.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/clock" 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_gettime.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_gettime.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/clock/clock_gettime.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/clock/clock_gettime.o.d" -o ${OBJECTDIR}/os/kernel/clock/clock_gettime.o os/kernel/clock/clock_gettime.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/clock/clock_gettimeofday.o: os/kernel/clock/clock_gettimeofday.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/clock" 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_gettimeofday.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_gettimeofday.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/clock/clock_gettimeofday.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/clock/clock_gettimeofday.o.d" -o ${OBJECTDIR}/os/kernel/clock/clock_gettimeofday.o os/kernel/clock/clock_gettimeofday.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/clock/clock_initialize.o: os/kernel/clock/clock_initialize.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/clock" 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_initialize.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_initialize.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/clock/clock_initialize.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/clock/clock_initialize.o.d" -o ${OBJECTDIR}/os/kernel/clock/clock_initialize.o os/kernel/clock/clock_initialize.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/clock/clock_settime.o: os/kernel/clock/clock_settime.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/clock" 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_settime.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_settime.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/clock/clock_settime.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/clock/clock_settime.o.d" -o ${OBJECTDIR}/os/kernel/clock/clock_settime.o os/kernel/clock/clock_settime.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/clock/clock_systimer.o: os/kernel/clock/clock_systimer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/clock" 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_systimer.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_systimer.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/clock/clock_systimer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/clock/clock_systimer.o.d" -o ${OBJECTDIR}/os/kernel/clock/clock_systimer.o os/kernel/clock/clock_systimer.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/clock/clock_systimespec.o: os/kernel/clock/clock_systimespec.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/clock" 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_systimespec.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_systimespec.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/clock/clock_systimespec.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/clock/clock_systimespec.o.d" -o ${OBJECTDIR}/os/kernel/clock/clock_systimespec.o os/kernel/clock/clock_systimespec.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/clock/clock_ticks2time.o: os/kernel/clock/clock_ticks2time.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/clock" 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_ticks2time.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_ticks2time.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/clock/clock_ticks2time.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/clock/clock_ticks2time.o.d" -o ${OBJECTDIR}/os/kernel/clock/clock_ticks2time.o os/kernel/clock/clock_ticks2time.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/clock/clock_time2ticks.o: os/kernel/clock/clock_time2ticks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/clock" 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_time2ticks.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/clock/clock_time2ticks.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/clock/clock_time2ticks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/clock/clock_time2ticks.o.d" -o ${OBJECTDIR}/os/kernel/clock/clock_time2ticks.o os/kernel/clock/clock_time2ticks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/debug/sysdbg.o: os/kernel/debug/sysdbg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/debug" 
	@${RM} ${OBJECTDIR}/os/kernel/debug/sysdbg.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/debug/sysdbg.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/debug/sysdbg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/debug/sysdbg.o.d" -o ${OBJECTDIR}/os/kernel/debug/sysdbg.o os/kernel/debug/sysdbg.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/environ/env_clearenv.o: os/kernel/environ/env_clearenv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/environ" 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_clearenv.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_clearenv.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/environ/env_clearenv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/environ/env_clearenv.o.d" -o ${OBJECTDIR}/os/kernel/environ/env_clearenv.o os/kernel/environ/env_clearenv.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/environ/env_dup.o: os/kernel/environ/env_dup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/environ" 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_dup.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_dup.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/environ/env_dup.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/environ/env_dup.o.d" -o ${OBJECTDIR}/os/kernel/environ/env_dup.o os/kernel/environ/env_dup.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/environ/env_findvar.o: os/kernel/environ/env_findvar.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/environ" 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_findvar.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_findvar.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/environ/env_findvar.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/environ/env_findvar.o.d" -o ${OBJECTDIR}/os/kernel/environ/env_findvar.o os/kernel/environ/env_findvar.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/environ/env_getenv.o: os/kernel/environ/env_getenv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/environ" 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_getenv.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_getenv.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/environ/env_getenv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/environ/env_getenv.o.d" -o ${OBJECTDIR}/os/kernel/environ/env_getenv.o os/kernel/environ/env_getenv.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/environ/env_getenvironptr.o: os/kernel/environ/env_getenvironptr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/environ" 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_getenvironptr.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_getenvironptr.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/environ/env_getenvironptr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/environ/env_getenvironptr.o.d" -o ${OBJECTDIR}/os/kernel/environ/env_getenvironptr.o os/kernel/environ/env_getenvironptr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/environ/env_putenv.o: os/kernel/environ/env_putenv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/environ" 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_putenv.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_putenv.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/environ/env_putenv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/environ/env_putenv.o.d" -o ${OBJECTDIR}/os/kernel/environ/env_putenv.o os/kernel/environ/env_putenv.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/environ/env_release.o: os/kernel/environ/env_release.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/environ" 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_release.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_release.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/environ/env_release.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/environ/env_release.o.d" -o ${OBJECTDIR}/os/kernel/environ/env_release.o os/kernel/environ/env_release.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/environ/env_removevar.o: os/kernel/environ/env_removevar.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/environ" 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_removevar.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_removevar.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/environ/env_removevar.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/environ/env_removevar.o.d" -o ${OBJECTDIR}/os/kernel/environ/env_removevar.o os/kernel/environ/env_removevar.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/environ/env_setenv.o: os/kernel/environ/env_setenv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/environ" 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_setenv.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_setenv.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/environ/env_setenv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/environ/env_setenv.o.d" -o ${OBJECTDIR}/os/kernel/environ/env_setenv.o os/kernel/environ/env_setenv.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/environ/env_unsetenv.o: os/kernel/environ/env_unsetenv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/environ" 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_unsetenv.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/environ/env_unsetenv.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/environ/env_unsetenv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/environ/env_unsetenv.o.d" -o ${OBJECTDIR}/os/kernel/environ/env_unsetenv.o os/kernel/environ/env_unsetenv.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/errno/errno_get.o: os/kernel/errno/errno_get.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/errno" 
	@${RM} ${OBJECTDIR}/os/kernel/errno/errno_get.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/errno/errno_get.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/errno/errno_get.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/errno/errno_get.o.d" -o ${OBJECTDIR}/os/kernel/errno/errno_get.o os/kernel/errno/errno_get.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/errno/errno_getptr.o: os/kernel/errno/errno_getptr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/errno" 
	@${RM} ${OBJECTDIR}/os/kernel/errno/errno_getptr.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/errno/errno_getptr.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/errno/errno_getptr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/errno/errno_getptr.o.d" -o ${OBJECTDIR}/os/kernel/errno/errno_getptr.o os/kernel/errno/errno_getptr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/errno/errno_set.o: os/kernel/errno/errno_set.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/errno" 
	@${RM} ${OBJECTDIR}/os/kernel/errno/errno_set.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/errno/errno_set.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/errno/errno_set.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/errno/errno_set.o.d" -o ${OBJECTDIR}/os/kernel/errno/errno_set.o os/kernel/errno/errno_set.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_addrenv.o: os/kernel/group/group_addrenv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_addrenv.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_addrenv.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_addrenv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_addrenv.o.d" -o ${OBJECTDIR}/os/kernel/group/group_addrenv.o os/kernel/group/group_addrenv.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_childstatus.o: os/kernel/group/group_childstatus.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_childstatus.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_childstatus.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_childstatus.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_childstatus.o.d" -o ${OBJECTDIR}/os/kernel/group/group_childstatus.o os/kernel/group/group_childstatus.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_create.o: os/kernel/group/group_create.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_create.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_create.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_create.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_create.o.d" -o ${OBJECTDIR}/os/kernel/group/group_create.o os/kernel/group/group_create.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_find.o: os/kernel/group/group_find.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_find.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_find.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_find.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_find.o.d" -o ${OBJECTDIR}/os/kernel/group/group_find.o os/kernel/group/group_find.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_foreachchild.o: os/kernel/group/group_foreachchild.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_foreachchild.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_foreachchild.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_foreachchild.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_foreachchild.o.d" -o ${OBJECTDIR}/os/kernel/group/group_foreachchild.o os/kernel/group/group_foreachchild.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_free.o: os/kernel/group/group_free.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_free.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_free.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_free.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_free.o.d" -o ${OBJECTDIR}/os/kernel/group/group_free.o os/kernel/group/group_free.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_join.o: os/kernel/group/group_join.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_join.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_join.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_join.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_join.o.d" -o ${OBJECTDIR}/os/kernel/group/group_join.o os/kernel/group/group_join.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_killchildren.o: os/kernel/group/group_killchildren.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_killchildren.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_killchildren.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_killchildren.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_killchildren.o.d" -o ${OBJECTDIR}/os/kernel/group/group_killchildren.o os/kernel/group/group_killchildren.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_leave.o: os/kernel/group/group_leave.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_leave.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_leave.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_leave.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_leave.o.d" -o ${OBJECTDIR}/os/kernel/group/group_leave.o os/kernel/group/group_leave.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_malloc.o: os/kernel/group/group_malloc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_malloc.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_malloc.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_malloc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_malloc.o.d" -o ${OBJECTDIR}/os/kernel/group/group_malloc.o os/kernel/group/group_malloc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_setupidlefiles.o: os/kernel/group/group_setupidlefiles.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_setupidlefiles.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_setupidlefiles.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_setupidlefiles.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_setupidlefiles.o.d" -o ${OBJECTDIR}/os/kernel/group/group_setupidlefiles.o os/kernel/group/group_setupidlefiles.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_setupstreams.o: os/kernel/group/group_setupstreams.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_setupstreams.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_setupstreams.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_setupstreams.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_setupstreams.o.d" -o ${OBJECTDIR}/os/kernel/group/group_setupstreams.o os/kernel/group/group_setupstreams.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_setuptaskfiles.o: os/kernel/group/group_setuptaskfiles.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_setuptaskfiles.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_setuptaskfiles.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_setuptaskfiles.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_setuptaskfiles.o.d" -o ${OBJECTDIR}/os/kernel/group/group_setuptaskfiles.o os/kernel/group/group_setuptaskfiles.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_signal.o: os/kernel/group/group_signal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_signal.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_signal.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_signal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_signal.o.d" -o ${OBJECTDIR}/os/kernel/group/group_signal.o os/kernel/group/group_signal.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/group/group_zalloc.o: os/kernel/group/group_zalloc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/group" 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_zalloc.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/group/group_zalloc.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/group/group_zalloc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/group/group_zalloc.o.d" -o ${OBJECTDIR}/os/kernel/group/group_zalloc.o os/kernel/group/group_zalloc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/init/os_bringup.o: os/kernel/init/os_bringup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/init" 
	@${RM} ${OBJECTDIR}/os/kernel/init/os_bringup.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/init/os_bringup.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/init/os_bringup.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/init/os_bringup.o.d" -o ${OBJECTDIR}/os/kernel/init/os_bringup.o os/kernel/init/os_bringup.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/init/os_start.o: os/kernel/init/os_start.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/init" 
	@${RM} ${OBJECTDIR}/os/kernel/init/os_start.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/init/os_start.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/init/os_start.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/init/os_start.o.d" -o ${OBJECTDIR}/os/kernel/init/os_start.o os/kernel/init/os_start.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/irq/irq_attach.o: os/kernel/irq/irq_attach.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/irq" 
	@${RM} ${OBJECTDIR}/os/kernel/irq/irq_attach.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/irq/irq_attach.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/irq/irq_attach.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/irq/irq_attach.o.d" -o ${OBJECTDIR}/os/kernel/irq/irq_attach.o os/kernel/irq/irq_attach.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/irq/irq_dispatch.o: os/kernel/irq/irq_dispatch.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/irq" 
	@${RM} ${OBJECTDIR}/os/kernel/irq/irq_dispatch.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/irq/irq_dispatch.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/irq/irq_dispatch.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/irq/irq_dispatch.o.d" -o ${OBJECTDIR}/os/kernel/irq/irq_dispatch.o os/kernel/irq/irq_dispatch.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/irq/irq_info.o: os/kernel/irq/irq_info.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/irq" 
	@${RM} ${OBJECTDIR}/os/kernel/irq/irq_info.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/irq/irq_info.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/irq/irq_info.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/irq/irq_info.o.d" -o ${OBJECTDIR}/os/kernel/irq/irq_info.o os/kernel/irq/irq_info.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/irq/irq_initialize.o: os/kernel/irq/irq_initialize.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/irq" 
	@${RM} ${OBJECTDIR}/os/kernel/irq/irq_initialize.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/irq/irq_initialize.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/irq/irq_initialize.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/irq/irq_initialize.o.d" -o ${OBJECTDIR}/os/kernel/irq/irq_initialize.o os/kernel/irq/irq_initialize.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/irq/irq_unexpectedisr.o: os/kernel/irq/irq_unexpectedisr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/irq" 
	@${RM} ${OBJECTDIR}/os/kernel/irq/irq_unexpectedisr.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/irq/irq_unexpectedisr.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/irq/irq_unexpectedisr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/irq/irq_unexpectedisr.o.d" -o ${OBJECTDIR}/os/kernel/irq/irq_unexpectedisr.o os/kernel/irq/irq_unexpectedisr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/paging/pg_miss.o: os/kernel/paging/pg_miss.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/paging" 
	@${RM} ${OBJECTDIR}/os/kernel/paging/pg_miss.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/paging/pg_miss.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/paging/pg_miss.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/paging/pg_miss.o.d" -o ${OBJECTDIR}/os/kernel/paging/pg_miss.o os/kernel/paging/pg_miss.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/paging/pg_worker.o: os/kernel/paging/pg_worker.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/paging" 
	@${RM} ${OBJECTDIR}/os/kernel/paging/pg_worker.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/paging/pg_worker.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/paging/pg_worker.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/paging/pg_worker.o.d" -o ${OBJECTDIR}/os/kernel/paging/pg_worker.o os/kernel/paging/pg_worker.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_cancel.o: os/kernel/pthread/pthread_cancel.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_cancel.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_cancel.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_cancel.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_cancel.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_cancel.o os/kernel/pthread/pthread_cancel.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_cleanup.o: os/kernel/pthread/pthread_cleanup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_cleanup.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_cleanup.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_cleanup.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_cleanup.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_cleanup.o os/kernel/pthread/pthread_cleanup.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_completejoin.o: os/kernel/pthread/pthread_completejoin.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_completejoin.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_completejoin.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_completejoin.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_completejoin.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_completejoin.o os/kernel/pthread/pthread_completejoin.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_condbroadcast.o: os/kernel/pthread/pthread_condbroadcast.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_condbroadcast.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_condbroadcast.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_condbroadcast.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_condbroadcast.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_condbroadcast.o os/kernel/pthread/pthread_condbroadcast.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_condsignal.o: os/kernel/pthread/pthread_condsignal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_condsignal.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_condsignal.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_condsignal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_condsignal.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_condsignal.o os/kernel/pthread/pthread_condsignal.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_condtimedwait.o: os/kernel/pthread/pthread_condtimedwait.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_condtimedwait.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_condtimedwait.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_condtimedwait.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_condtimedwait.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_condtimedwait.o os/kernel/pthread/pthread_condtimedwait.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_condwait.o: os/kernel/pthread/pthread_condwait.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_condwait.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_condwait.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_condwait.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_condwait.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_condwait.o os/kernel/pthread/pthread_condwait.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_create.o: os/kernel/pthread/pthread_create.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_create.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_create.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_create.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_create.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_create.o os/kernel/pthread/pthread_create.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_detach.o: os/kernel/pthread/pthread_detach.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_detach.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_detach.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_detach.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_detach.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_detach.o os/kernel/pthread/pthread_detach.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_exit.o: os/kernel/pthread/pthread_exit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_exit.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_exit.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_exit.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_exit.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_exit.o os/kernel/pthread/pthread_exit.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_findjoininfo.o: os/kernel/pthread/pthread_findjoininfo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_findjoininfo.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_findjoininfo.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_findjoininfo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_findjoininfo.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_findjoininfo.o os/kernel/pthread/pthread_findjoininfo.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_getschedparam.o: os/kernel/pthread/pthread_getschedparam.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_getschedparam.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_getschedparam.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_getschedparam.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_getschedparam.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_getschedparam.o os/kernel/pthread/pthread_getschedparam.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_getspecific.o: os/kernel/pthread/pthread_getspecific.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_getspecific.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_getspecific.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_getspecific.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_getspecific.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_getspecific.o os/kernel/pthread/pthread_getspecific.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_initialize.o: os/kernel/pthread/pthread_initialize.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_initialize.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_initialize.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_initialize.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_initialize.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_initialize.o os/kernel/pthread/pthread_initialize.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_join.o: os/kernel/pthread/pthread_join.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_join.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_join.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_join.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_join.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_join.o os/kernel/pthread/pthread_join.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_keycreate.o: os/kernel/pthread/pthread_keycreate.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_keycreate.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_keycreate.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_keycreate.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_keycreate.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_keycreate.o os/kernel/pthread/pthread_keycreate.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_keydelete.o: os/kernel/pthread/pthread_keydelete.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_keydelete.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_keydelete.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_keydelete.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_keydelete.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_keydelete.o os/kernel/pthread/pthread_keydelete.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_keydestroy.o: os/kernel/pthread/pthread_keydestroy.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_keydestroy.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_keydestroy.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_keydestroy.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_keydestroy.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_keydestroy.o os/kernel/pthread/pthread_keydestroy.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_kill.o: os/kernel/pthread/pthread_kill.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_kill.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_kill.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_kill.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_kill.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_kill.o os/kernel/pthread/pthread_kill.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_mutex.o: os/kernel/pthread/pthread_mutex.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutex.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutex.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_mutex.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_mutex.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_mutex.o os/kernel/pthread/pthread_mutex.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_mutexconsistent.o: os/kernel/pthread/pthread_mutexconsistent.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutexconsistent.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutexconsistent.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_mutexconsistent.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_mutexconsistent.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_mutexconsistent.o os/kernel/pthread/pthread_mutexconsistent.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_mutexdestroy.o: os/kernel/pthread/pthread_mutexdestroy.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutexdestroy.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutexdestroy.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_mutexdestroy.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_mutexdestroy.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_mutexdestroy.o os/kernel/pthread/pthread_mutexdestroy.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_mutexinconsistent.o: os/kernel/pthread/pthread_mutexinconsistent.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutexinconsistent.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutexinconsistent.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_mutexinconsistent.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_mutexinconsistent.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_mutexinconsistent.o os/kernel/pthread/pthread_mutexinconsistent.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_mutexinit.o: os/kernel/pthread/pthread_mutexinit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutexinit.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutexinit.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_mutexinit.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_mutexinit.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_mutexinit.o os/kernel/pthread/pthread_mutexinit.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_mutexlock.o: os/kernel/pthread/pthread_mutexlock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutexlock.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutexlock.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_mutexlock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_mutexlock.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_mutexlock.o os/kernel/pthread/pthread_mutexlock.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_mutextrylock.o: os/kernel/pthread/pthread_mutextrylock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutextrylock.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutextrylock.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_mutextrylock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_mutextrylock.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_mutextrylock.o os/kernel/pthread/pthread_mutextrylock.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_mutexunlock.o: os/kernel/pthread/pthread_mutexunlock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutexunlock.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_mutexunlock.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_mutexunlock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_mutexunlock.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_mutexunlock.o os/kernel/pthread/pthread_mutexunlock.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_release.o: os/kernel/pthread/pthread_release.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_release.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_release.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_release.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_release.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_release.o os/kernel/pthread/pthread_release.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_setschedparam.o: os/kernel/pthread/pthread_setschedparam.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_setschedparam.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_setschedparam.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_setschedparam.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_setschedparam.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_setschedparam.o os/kernel/pthread/pthread_setschedparam.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_setschedprio.o: os/kernel/pthread/pthread_setschedprio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_setschedprio.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_setschedprio.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_setschedprio.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_setschedprio.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_setschedprio.o os/kernel/pthread/pthread_setschedprio.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_setspecific.o: os/kernel/pthread/pthread_setspecific.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_setspecific.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_setspecific.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_setspecific.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_setspecific.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_setspecific.o os/kernel/pthread/pthread_setspecific.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_sigmask.o: os/kernel/pthread/pthread_sigmask.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_sigmask.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_sigmask.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_sigmask.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_sigmask.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_sigmask.o os/kernel/pthread/pthread_sigmask.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/pthread/pthread_tryjoin_np.o: os/kernel/pthread/pthread_tryjoin_np.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/pthread" 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_tryjoin_np.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/pthread/pthread_tryjoin_np.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/pthread/pthread_tryjoin_np.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/pthread/pthread_tryjoin_np.o.d" -o ${OBJECTDIR}/os/kernel/pthread/pthread_tryjoin_np.o os/kernel/pthread/pthread_tryjoin_np.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_addblocked.o: os/kernel/sched/sched_addblocked.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_addblocked.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_addblocked.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_addblocked.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_addblocked.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_addblocked.o os/kernel/sched/sched_addblocked.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_addprioritized.o: os/kernel/sched/sched_addprioritized.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_addprioritized.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_addprioritized.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_addprioritized.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_addprioritized.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_addprioritized.o os/kernel/sched/sched_addprioritized.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_addreadytorun.o: os/kernel/sched/sched_addreadytorun.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_addreadytorun.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_addreadytorun.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_addreadytorun.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_addreadytorun.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_addreadytorun.o os/kernel/sched/sched_addreadytorun.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_cpuload.o: os/kernel/sched/sched_cpuload.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_cpuload.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_cpuload.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_cpuload.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_cpuload.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_cpuload.o os/kernel/sched/sched_cpuload.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_foreach.o: os/kernel/sched/sched_foreach.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_foreach.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_foreach.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_foreach.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_foreach.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_foreach.o os/kernel/sched/sched_foreach.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_free.o: os/kernel/sched/sched_free.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_free.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_free.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_free.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_free.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_free.o os/kernel/sched/sched_free.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_garbage.o: os/kernel/sched/sched_garbage.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_garbage.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_garbage.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_garbage.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_garbage.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_garbage.o os/kernel/sched/sched_garbage.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_getfiles.o: os/kernel/sched/sched_getfiles.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_getfiles.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_getfiles.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_getfiles.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_getfiles.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_getfiles.o os/kernel/sched/sched_getfiles.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_getparam.o: os/kernel/sched/sched_getparam.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_getparam.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_getparam.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_getparam.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_getparam.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_getparam.o os/kernel/sched/sched_getparam.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_getscheduler.o: os/kernel/sched/sched_getscheduler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_getscheduler.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_getscheduler.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_getscheduler.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_getscheduler.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_getscheduler.o os/kernel/sched/sched_getscheduler.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_getsockets.o: os/kernel/sched/sched_getsockets.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_getsockets.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_getsockets.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_getsockets.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_getsockets.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_getsockets.o os/kernel/sched/sched_getsockets.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_getstreams.o: os/kernel/sched/sched_getstreams.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_getstreams.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_getstreams.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_getstreams.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_getstreams.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_getstreams.o os/kernel/sched/sched_getstreams.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_gettcb.o: os/kernel/sched/sched_gettcb.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_gettcb.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_gettcb.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_gettcb.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_gettcb.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_gettcb.o os/kernel/sched/sched_gettcb.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_lock.o: os/kernel/sched/sched_lock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_lock.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_lock.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_lock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_lock.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_lock.o os/kernel/sched/sched_lock.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_lockcount.o: os/kernel/sched/sched_lockcount.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_lockcount.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_lockcount.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_lockcount.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_lockcount.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_lockcount.o os/kernel/sched/sched_lockcount.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_mergepending.o: os/kernel/sched/sched_mergepending.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_mergepending.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_mergepending.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_mergepending.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_mergepending.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_mergepending.o os/kernel/sched/sched_mergepending.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_processtimer.o: os/kernel/sched/sched_processtimer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_processtimer.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_processtimer.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_processtimer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_processtimer.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_processtimer.o os/kernel/sched/sched_processtimer.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_releasetcb.o: os/kernel/sched/sched_releasetcb.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_releasetcb.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_releasetcb.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_releasetcb.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_releasetcb.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_releasetcb.o os/kernel/sched/sched_releasetcb.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_removeblocked.o: os/kernel/sched/sched_removeblocked.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_removeblocked.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_removeblocked.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_removeblocked.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_removeblocked.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_removeblocked.o os/kernel/sched/sched_removeblocked.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_removereadytorun.o: os/kernel/sched/sched_removereadytorun.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_removereadytorun.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_removereadytorun.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_removereadytorun.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_removereadytorun.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_removereadytorun.o os/kernel/sched/sched_removereadytorun.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_reprioritize.o: os/kernel/sched/sched_reprioritize.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_reprioritize.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_reprioritize.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_reprioritize.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_reprioritize.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_reprioritize.o os/kernel/sched/sched_reprioritize.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_rrgetinterval.o: os/kernel/sched/sched_rrgetinterval.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_rrgetinterval.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_rrgetinterval.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_rrgetinterval.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_rrgetinterval.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_rrgetinterval.o os/kernel/sched/sched_rrgetinterval.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_self.o: os/kernel/sched/sched_self.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_self.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_self.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_self.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_self.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_self.o os/kernel/sched/sched_self.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_setparam.o: os/kernel/sched/sched_setparam.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_setparam.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_setparam.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_setparam.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_setparam.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_setparam.o os/kernel/sched/sched_setparam.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_setpriority.o: os/kernel/sched/sched_setpriority.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_setpriority.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_setpriority.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_setpriority.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_setpriority.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_setpriority.o os/kernel/sched/sched_setpriority.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_setscheduler.o: os/kernel/sched/sched_setscheduler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_setscheduler.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_setscheduler.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_setscheduler.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_setscheduler.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_setscheduler.o os/kernel/sched/sched_setscheduler.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_timerexpiration.o: os/kernel/sched/sched_timerexpiration.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_timerexpiration.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_timerexpiration.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_timerexpiration.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_timerexpiration.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_timerexpiration.o os/kernel/sched/sched_timerexpiration.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_unlock.o: os/kernel/sched/sched_unlock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_unlock.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_unlock.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_unlock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_unlock.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_unlock.o os/kernel/sched/sched_unlock.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_verifytcb.o: os/kernel/sched/sched_verifytcb.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_verifytcb.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_verifytcb.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_verifytcb.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_verifytcb.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_verifytcb.o os/kernel/sched/sched_verifytcb.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_wait.o: os/kernel/sched/sched_wait.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_wait.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_wait.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_wait.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_wait.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_wait.o os/kernel/sched/sched_wait.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_waitid.o: os/kernel/sched/sched_waitid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_waitid.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_waitid.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_waitid.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_waitid.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_waitid.o os/kernel/sched/sched_waitid.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_waitpid.o: os/kernel/sched/sched_waitpid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_waitpid.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_waitpid.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_waitpid.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_waitpid.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_waitpid.o os/kernel/sched/sched_waitpid.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/sched/sched_yield.o: os/kernel/sched/sched_yield.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/sched" 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_yield.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/sched/sched_yield.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/sched/sched_yield.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/sched/sched_yield.o.d" -o ${OBJECTDIR}/os/kernel/sched/sched_yield.o os/kernel/sched/sched_yield.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/semaphore/sem_destroy.o: os/kernel/semaphore/sem_destroy.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/semaphore" 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_destroy.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_destroy.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/semaphore/sem_destroy.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/semaphore/sem_destroy.o.d" -o ${OBJECTDIR}/os/kernel/semaphore/sem_destroy.o os/kernel/semaphore/sem_destroy.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/semaphore/sem_holder.o: os/kernel/semaphore/sem_holder.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/semaphore" 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_holder.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_holder.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/semaphore/sem_holder.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/semaphore/sem_holder.o.d" -o ${OBJECTDIR}/os/kernel/semaphore/sem_holder.o os/kernel/semaphore/sem_holder.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/semaphore/sem_initialize.o: os/kernel/semaphore/sem_initialize.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/semaphore" 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_initialize.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_initialize.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/semaphore/sem_initialize.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/semaphore/sem_initialize.o.d" -o ${OBJECTDIR}/os/kernel/semaphore/sem_initialize.o os/kernel/semaphore/sem_initialize.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/semaphore/sem_post.o: os/kernel/semaphore/sem_post.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/semaphore" 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_post.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_post.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/semaphore/sem_post.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/semaphore/sem_post.o.d" -o ${OBJECTDIR}/os/kernel/semaphore/sem_post.o os/kernel/semaphore/sem_post.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/semaphore/sem_recover.o: os/kernel/semaphore/sem_recover.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/semaphore" 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_recover.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_recover.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/semaphore/sem_recover.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/semaphore/sem_recover.o.d" -o ${OBJECTDIR}/os/kernel/semaphore/sem_recover.o os/kernel/semaphore/sem_recover.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/semaphore/sem_reset.o: os/kernel/semaphore/sem_reset.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/semaphore" 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_reset.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_reset.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/semaphore/sem_reset.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/semaphore/sem_reset.o.d" -o ${OBJECTDIR}/os/kernel/semaphore/sem_reset.o os/kernel/semaphore/sem_reset.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/semaphore/sem_setprotocol.o: os/kernel/semaphore/sem_setprotocol.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/semaphore" 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_setprotocol.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_setprotocol.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/semaphore/sem_setprotocol.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/semaphore/sem_setprotocol.o.d" -o ${OBJECTDIR}/os/kernel/semaphore/sem_setprotocol.o os/kernel/semaphore/sem_setprotocol.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/semaphore/sem_tickwait.o: os/kernel/semaphore/sem_tickwait.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/semaphore" 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_tickwait.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_tickwait.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/semaphore/sem_tickwait.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/semaphore/sem_tickwait.o.d" -o ${OBJECTDIR}/os/kernel/semaphore/sem_tickwait.o os/kernel/semaphore/sem_tickwait.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/semaphore/sem_timedwait.o: os/kernel/semaphore/sem_timedwait.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/semaphore" 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_timedwait.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_timedwait.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/semaphore/sem_timedwait.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/semaphore/sem_timedwait.o.d" -o ${OBJECTDIR}/os/kernel/semaphore/sem_timedwait.o os/kernel/semaphore/sem_timedwait.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/semaphore/sem_trywait.o: os/kernel/semaphore/sem_trywait.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/semaphore" 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_trywait.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_trywait.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/semaphore/sem_trywait.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/semaphore/sem_trywait.o.d" -o ${OBJECTDIR}/os/kernel/semaphore/sem_trywait.o os/kernel/semaphore/sem_trywait.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/semaphore/sem_wait.o: os/kernel/semaphore/sem_wait.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/semaphore" 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_wait.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_wait.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/semaphore/sem_wait.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/semaphore/sem_wait.o.d" -o ${OBJECTDIR}/os/kernel/semaphore/sem_wait.o os/kernel/semaphore/sem_wait.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/semaphore/sem_waitirq.o: os/kernel/semaphore/sem_waitirq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/semaphore" 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_waitirq.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/semaphore/sem_waitirq.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/semaphore/sem_waitirq.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/semaphore/sem_waitirq.o.d" -o ${OBJECTDIR}/os/kernel/semaphore/sem_waitirq.o os/kernel/semaphore/sem_waitirq.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_action.o: os/kernel/signal/sig_action.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_action.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_action.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_action.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_action.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_action.o os/kernel/signal/sig_action.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_allocatependingsigaction.o: os/kernel/signal/sig_allocatependingsigaction.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_allocatependingsigaction.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_allocatependingsigaction.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_allocatependingsigaction.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_allocatependingsigaction.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_allocatependingsigaction.o os/kernel/signal/sig_allocatependingsigaction.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_cleanup.o: os/kernel/signal/sig_cleanup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_cleanup.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_cleanup.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_cleanup.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_cleanup.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_cleanup.o os/kernel/signal/sig_cleanup.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_deliver.o: os/kernel/signal/sig_deliver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_deliver.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_deliver.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_deliver.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_deliver.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_deliver.o os/kernel/signal/sig_deliver.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_dispatch.o: os/kernel/signal/sig_dispatch.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_dispatch.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_dispatch.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_dispatch.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_dispatch.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_dispatch.o os/kernel/signal/sig_dispatch.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_findaction.o: os/kernel/signal/sig_findaction.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_findaction.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_findaction.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_findaction.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_findaction.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_findaction.o os/kernel/signal/sig_findaction.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_initialize.o: os/kernel/signal/sig_initialize.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_initialize.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_initialize.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_initialize.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_initialize.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_initialize.o os/kernel/signal/sig_initialize.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_is_handler_registered.o: os/kernel/signal/sig_is_handler_registered.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_is_handler_registered.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_is_handler_registered.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_is_handler_registered.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_is_handler_registered.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_is_handler_registered.o os/kernel/signal/sig_is_handler_registered.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_kill.o: os/kernel/signal/sig_kill.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_kill.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_kill.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_kill.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_kill.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_kill.o os/kernel/signal/sig_kill.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_lowest.o: os/kernel/signal/sig_lowest.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_lowest.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_lowest.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_lowest.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_lowest.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_lowest.o os/kernel/signal/sig_lowest.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_mqnotempty.o: os/kernel/signal/sig_mqnotempty.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_mqnotempty.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_mqnotempty.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_mqnotempty.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_mqnotempty.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_mqnotempty.o os/kernel/signal/sig_mqnotempty.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_nanosleep.o: os/kernel/signal/sig_nanosleep.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_nanosleep.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_nanosleep.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_nanosleep.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_nanosleep.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_nanosleep.o os/kernel/signal/sig_nanosleep.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_pause.o: os/kernel/signal/sig_pause.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_pause.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_pause.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_pause.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_pause.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_pause.o os/kernel/signal/sig_pause.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_pending.o: os/kernel/signal/sig_pending.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_pending.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_pending.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_pending.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_pending.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_pending.o os/kernel/signal/sig_pending.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_procmask.o: os/kernel/signal/sig_procmask.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_procmask.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_procmask.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_procmask.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_procmask.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_procmask.o os/kernel/signal/sig_procmask.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_queue.o: os/kernel/signal/sig_queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_queue.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_queue.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_queue.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_queue.o os/kernel/signal/sig_queue.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_releasependingsigaction.o: os/kernel/signal/sig_releasependingsigaction.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_releasependingsigaction.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_releasependingsigaction.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_releasependingsigaction.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_releasependingsigaction.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_releasependingsigaction.o os/kernel/signal/sig_releasependingsigaction.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_releasependingsignal.o: os/kernel/signal/sig_releasependingsignal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_releasependingsignal.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_releasependingsignal.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_releasependingsignal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_releasependingsignal.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_releasependingsignal.o os/kernel/signal/sig_releasependingsignal.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_removependingsignal.o: os/kernel/signal/sig_removependingsignal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_removependingsignal.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_removependingsignal.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_removependingsignal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_removependingsignal.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_removependingsignal.o os/kernel/signal/sig_removependingsignal.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_sethandler.o: os/kernel/signal/sig_sethandler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_sethandler.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_sethandler.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_sethandler.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_sethandler.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_sethandler.o os/kernel/signal/sig_sethandler.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_suspend.o: os/kernel/signal/sig_suspend.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_suspend.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_suspend.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_suspend.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_suspend.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_suspend.o os/kernel/signal/sig_suspend.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_timedwait.o: os/kernel/signal/sig_timedwait.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_timedwait.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_timedwait.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_timedwait.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_timedwait.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_timedwait.o os/kernel/signal/sig_timedwait.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_unmaskpendingsignal.o: os/kernel/signal/sig_unmaskpendingsignal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_unmaskpendingsignal.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_unmaskpendingsignal.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_unmaskpendingsignal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_unmaskpendingsignal.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_unmaskpendingsignal.o os/kernel/signal/sig_unmaskpendingsignal.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/signal/sig_waitinfo.o: os/kernel/signal/sig_waitinfo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/signal" 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_waitinfo.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/signal/sig_waitinfo.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/signal/sig_waitinfo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/signal/sig_waitinfo.o.d" -o ${OBJECTDIR}/os/kernel/signal/sig_waitinfo.o os/kernel/signal/sig_waitinfo.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/exit.o: os/kernel/task/exit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/exit.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/exit.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/exit.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/exit.o.d" -o ${OBJECTDIR}/os/kernel/task/exit.o os/kernel/task/exit.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_activate.o: os/kernel/task/task_activate.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_activate.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_activate.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_activate.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_activate.o.d" -o ${OBJECTDIR}/os/kernel/task/task_activate.o os/kernel/task/task_activate.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_atexit.o: os/kernel/task/task_atexit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_atexit.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_atexit.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_atexit.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_atexit.o.d" -o ${OBJECTDIR}/os/kernel/task/task_atexit.o os/kernel/task/task_atexit.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_cancelpt.o: os/kernel/task/task_cancelpt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_cancelpt.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_cancelpt.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_cancelpt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_cancelpt.o.d" -o ${OBJECTDIR}/os/kernel/task/task_cancelpt.o os/kernel/task/task_cancelpt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_create.o: os/kernel/task/task_create.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_create.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_create.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_create.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_create.o.d" -o ${OBJECTDIR}/os/kernel/task/task_create.o os/kernel/task/task_create.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_delete.o: os/kernel/task/task_delete.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_delete.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_delete.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_delete.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_delete.o.d" -o ${OBJECTDIR}/os/kernel/task/task_delete.o os/kernel/task/task_delete.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_execv.o: os/kernel/task/task_execv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_execv.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_execv.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_execv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_execv.o.d" -o ${OBJECTDIR}/os/kernel/task/task_execv.o os/kernel/task/task_execv.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_exit.o: os/kernel/task/task_exit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_exit.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_exit.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_exit.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_exit.o.d" -o ${OBJECTDIR}/os/kernel/task/task_exit.o os/kernel/task/task_exit.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_exithook.o: os/kernel/task/task_exithook.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_exithook.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_exithook.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_exithook.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_exithook.o.d" -o ${OBJECTDIR}/os/kernel/task/task_exithook.o os/kernel/task/task_exithook.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_getgroup.o: os/kernel/task/task_getgroup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_getgroup.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_getgroup.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_getgroup.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_getgroup.o.d" -o ${OBJECTDIR}/os/kernel/task/task_getgroup.o os/kernel/task/task_getgroup.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_getpid.o: os/kernel/task/task_getpid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_getpid.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_getpid.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_getpid.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_getpid.o.d" -o ${OBJECTDIR}/os/kernel/task/task_getpid.o os/kernel/task/task_getpid.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_init.o: os/kernel/task/task_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_init.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_init.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_init.o.d" -o ${OBJECTDIR}/os/kernel/task/task_init.o os/kernel/task/task_init.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_onexit.o: os/kernel/task/task_onexit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_onexit.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_onexit.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_onexit.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_onexit.o.d" -o ${OBJECTDIR}/os/kernel/task/task_onexit.o os/kernel/task/task_onexit.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_prctl.o: os/kernel/task/task_prctl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_prctl.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_prctl.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_prctl.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_prctl.o.d" -o ${OBJECTDIR}/os/kernel/task/task_prctl.o os/kernel/task/task_prctl.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_recover.o: os/kernel/task/task_recover.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_recover.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_recover.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_recover.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_recover.o.d" -o ${OBJECTDIR}/os/kernel/task/task_recover.o os/kernel/task/task_recover.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_reparent.o: os/kernel/task/task_reparent.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_reparent.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_reparent.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_reparent.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_reparent.o.d" -o ${OBJECTDIR}/os/kernel/task/task_reparent.o os/kernel/task/task_reparent.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_restart.o: os/kernel/task/task_restart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_restart.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_restart.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_restart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_restart.o.d" -o ${OBJECTDIR}/os/kernel/task/task_restart.o os/kernel/task/task_restart.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_setcancelstate.o: os/kernel/task/task_setcancelstate.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_setcancelstate.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_setcancelstate.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_setcancelstate.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_setcancelstate.o.d" -o ${OBJECTDIR}/os/kernel/task/task_setcancelstate.o os/kernel/task/task_setcancelstate.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_setcanceltype.o: os/kernel/task/task_setcanceltype.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_setcanceltype.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_setcanceltype.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_setcanceltype.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_setcanceltype.o.d" -o ${OBJECTDIR}/os/kernel/task/task_setcanceltype.o os/kernel/task/task_setcanceltype.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_setup.o: os/kernel/task/task_setup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_setup.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_setup.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_setup.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_setup.o.d" -o ${OBJECTDIR}/os/kernel/task/task_setup.o os/kernel/task/task_setup.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_start.o: os/kernel/task/task_start.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_start.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_start.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_start.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_start.o.d" -o ${OBJECTDIR}/os/kernel/task/task_start.o os/kernel/task/task_start.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_starthook.o: os/kernel/task/task_starthook.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_starthook.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_starthook.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_starthook.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_starthook.o.d" -o ${OBJECTDIR}/os/kernel/task/task_starthook.o os/kernel/task/task_starthook.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_terminate.o: os/kernel/task/task_terminate.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_terminate.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_terminate.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_terminate.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_terminate.o.d" -o ${OBJECTDIR}/os/kernel/task/task_terminate.o os/kernel/task/task_terminate.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_testcancel.o: os/kernel/task/task_testcancel.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_testcancel.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_testcancel.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_testcancel.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_testcancel.o.d" -o ${OBJECTDIR}/os/kernel/task/task_testcancel.o os/kernel/task/task_testcancel.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/task/task_vfork.o: os/kernel/task/task_vfork.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/task" 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_vfork.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/task/task_vfork.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/task/task_vfork.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/task/task_vfork.o.d" -o ${OBJECTDIR}/os/kernel/task/task_vfork.o os/kernel/task/task_vfork.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/timer/timer_create.o: os/kernel/timer/timer_create.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/timer" 
	@${RM} ${OBJECTDIR}/os/kernel/timer/timer_create.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/timer/timer_create.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/timer/timer_create.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/timer/timer_create.o.d" -o ${OBJECTDIR}/os/kernel/timer/timer_create.o os/kernel/timer/timer_create.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/timer/timer_delete.o: os/kernel/timer/timer_delete.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/timer" 
	@${RM} ${OBJECTDIR}/os/kernel/timer/timer_delete.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/timer/timer_delete.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/timer/timer_delete.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/timer/timer_delete.o.d" -o ${OBJECTDIR}/os/kernel/timer/timer_delete.o os/kernel/timer/timer_delete.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/timer/timer_getoverrun.o: os/kernel/timer/timer_getoverrun.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/timer" 
	@${RM} ${OBJECTDIR}/os/kernel/timer/timer_getoverrun.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/timer/timer_getoverrun.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/timer/timer_getoverrun.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/timer/timer_getoverrun.o.d" -o ${OBJECTDIR}/os/kernel/timer/timer_getoverrun.o os/kernel/timer/timer_getoverrun.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/timer/timer_gettime.o: os/kernel/timer/timer_gettime.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/timer" 
	@${RM} ${OBJECTDIR}/os/kernel/timer/timer_gettime.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/timer/timer_gettime.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/timer/timer_gettime.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/timer/timer_gettime.o.d" -o ${OBJECTDIR}/os/kernel/timer/timer_gettime.o os/kernel/timer/timer_gettime.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/timer/timer_initialize.o: os/kernel/timer/timer_initialize.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/timer" 
	@${RM} ${OBJECTDIR}/os/kernel/timer/timer_initialize.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/timer/timer_initialize.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/timer/timer_initialize.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/timer/timer_initialize.o.d" -o ${OBJECTDIR}/os/kernel/timer/timer_initialize.o os/kernel/timer/timer_initialize.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/timer/timer_release.o: os/kernel/timer/timer_release.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/timer" 
	@${RM} ${OBJECTDIR}/os/kernel/timer/timer_release.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/timer/timer_release.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/timer/timer_release.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/timer/timer_release.o.d" -o ${OBJECTDIR}/os/kernel/timer/timer_release.o os/kernel/timer/timer_release.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/timer/timer_settime.o: os/kernel/timer/timer_settime.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/timer" 
	@${RM} ${OBJECTDIR}/os/kernel/timer/timer_settime.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/timer/timer_settime.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/timer/timer_settime.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/timer/timer_settime.o.d" -o ${OBJECTDIR}/os/kernel/timer/timer_settime.o os/kernel/timer/timer_settime.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/wdog/wd_cancel.o: os/kernel/wdog/wd_cancel.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/wdog" 
	@${RM} ${OBJECTDIR}/os/kernel/wdog/wd_cancel.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/wdog/wd_cancel.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/wdog/wd_cancel.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/wdog/wd_cancel.o.d" -o ${OBJECTDIR}/os/kernel/wdog/wd_cancel.o os/kernel/wdog/wd_cancel.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/wdog/wd_create.o: os/kernel/wdog/wd_create.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/wdog" 
	@${RM} ${OBJECTDIR}/os/kernel/wdog/wd_create.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/wdog/wd_create.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/wdog/wd_create.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/wdog/wd_create.o.d" -o ${OBJECTDIR}/os/kernel/wdog/wd_create.o os/kernel/wdog/wd_create.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/wdog/wd_delete.o: os/kernel/wdog/wd_delete.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/wdog" 
	@${RM} ${OBJECTDIR}/os/kernel/wdog/wd_delete.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/wdog/wd_delete.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/wdog/wd_delete.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/wdog/wd_delete.o.d" -o ${OBJECTDIR}/os/kernel/wdog/wd_delete.o os/kernel/wdog/wd_delete.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/wdog/wd_gettime.o: os/kernel/wdog/wd_gettime.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/wdog" 
	@${RM} ${OBJECTDIR}/os/kernel/wdog/wd_gettime.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/wdog/wd_gettime.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/wdog/wd_gettime.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/wdog/wd_gettime.o.d" -o ${OBJECTDIR}/os/kernel/wdog/wd_gettime.o os/kernel/wdog/wd_gettime.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/wdog/wd_initialize.o: os/kernel/wdog/wd_initialize.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/wdog" 
	@${RM} ${OBJECTDIR}/os/kernel/wdog/wd_initialize.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/wdog/wd_initialize.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/wdog/wd_initialize.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/wdog/wd_initialize.o.d" -o ${OBJECTDIR}/os/kernel/wdog/wd_initialize.o os/kernel/wdog/wd_initialize.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/wdog/wd_recover.o: os/kernel/wdog/wd_recover.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/wdog" 
	@${RM} ${OBJECTDIR}/os/kernel/wdog/wd_recover.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/wdog/wd_recover.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/wdog/wd_recover.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/wdog/wd_recover.o.d" -o ${OBJECTDIR}/os/kernel/wdog/wd_recover.o os/kernel/wdog/wd_recover.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/kernel/wdog/wd_start.o: os/kernel/wdog/wd_start.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/kernel/wdog" 
	@${RM} ${OBJECTDIR}/os/kernel/wdog/wd_start.o.d 
	@${RM} ${OBJECTDIR}/os/kernel/wdog/wd_start.o 
	@${FIXDEPS} "${OBJECTDIR}/os/kernel/wdog/wd_start.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/kernel/wdog/wd_start.o.d" -o ${OBJECTDIR}/os/kernel/wdog/wd_start.o os/kernel/wdog/wd_start.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/mm/kmm_heap/kmm.o: os/mm/kmm_heap/kmm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/mm/kmm_heap" 
	@${RM} ${OBJECTDIR}/os/mm/kmm_heap/kmm.o.d 
	@${RM} ${OBJECTDIR}/os/mm/kmm_heap/kmm.o 
	@${FIXDEPS} "${OBJECTDIR}/os/mm/kmm_heap/kmm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/mm/kmm_heap/kmm.o.d" -o ${OBJECTDIR}/os/mm/kmm_heap/kmm.o os/mm/kmm_heap/kmm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/mm/mm_heap/mm_heap.o: os/mm/mm_heap/mm_heap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/mm/mm_heap" 
	@${RM} ${OBJECTDIR}/os/mm/mm_heap/mm_heap.o.d 
	@${RM} ${OBJECTDIR}/os/mm/mm_heap/mm_heap.o 
	@${FIXDEPS} "${OBJECTDIR}/os/mm/mm_heap/mm_heap.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/mm/mm_heap/mm_heap.o.d" -o ${OBJECTDIR}/os/mm/mm_heap/mm_heap.o os/mm/mm_heap/mm_heap.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/mm/umm_heap/umm.o: os/mm/umm_heap/umm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/mm/umm_heap" 
	@${RM} ${OBJECTDIR}/os/mm/umm_heap/umm.o.d 
	@${RM} ${OBJECTDIR}/os/mm/umm_heap/umm.o 
	@${FIXDEPS} "${OBJECTDIR}/os/mm/umm_heap/umm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/mm/umm_heap/umm.o.d" -o ${OBJECTDIR}/os/mm/umm_heap/umm.o os/mm/umm_heap/umm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/arch/HELP.o: os/arch/HELP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/arch" 
	@${RM} ${OBJECTDIR}/os/arch/HELP.o.d 
	@${RM} ${OBJECTDIR}/os/arch/HELP.o 
	@${FIXDEPS} "${OBJECTDIR}/os/arch/HELP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/arch/HELP.o.d" -o ${OBJECTDIR}/os/arch/HELP.o os/arch/HELP.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/sys_config.o: sys_config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/sys_config.o.d 
	@${RM} ${OBJECTDIR}/sys_config.o 
	@${FIXDEPS} "${OBJECTDIR}/sys_config.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/sys_config.o.d" -o ${OBJECTDIR}/sys_config.o sys_config.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/drivers/dev_null.o: os/drivers/dev_null.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/drivers" 
	@${RM} ${OBJECTDIR}/os/drivers/dev_null.o.d 
	@${RM} ${OBJECTDIR}/os/drivers/dev_null.o 
	@${FIXDEPS} "${OBJECTDIR}/os/drivers/dev_null.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/drivers/dev_null.o.d" -o ${OBJECTDIR}/os/drivers/dev_null.o os/drivers/dev_null.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
${OBJECTDIR}/os/drivers/dev_zero.o: os/drivers/dev_zero.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/os/drivers" 
	@${RM} ${OBJECTDIR}/os/drivers/dev_zero.o.d 
	@${RM} ${OBJECTDIR}/os/drivers/dev_zero.o 
	@${FIXDEPS} "${OBJECTDIR}/os/drivers/dev_zero.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/libc" -I"os" -I"os/include" -I"os/kernel" -I"os/fs" -I"os/arch/mips/src/common" -I"os/arch/mips/src/mips32" -I"os/arch/mips/src/pic32mz" -MMD -MF "${OBJECTDIR}/os/drivers/dev_zero.o.d" -o ${OBJECTDIR}/os/drivers/dev_zero.o os/drivers/dev_zero.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -fno-short-double -mnewlib-libc
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/TIZEN.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    os/arch/board/curiosity/linker/WizIO_p32MZ2048EFM100.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION) -nostartfiles -o dist/${CND_CONF}/${IMAGE_TYPE}/TIZEN.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x37F   -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=_min_heap_size=450000,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/TIZEN.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   os/arch/board/curiosity/linker/WizIO_p32MZ2048EFM100.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION) -nostartfiles -o dist/${CND_CONF}/${IMAGE_TYPE}/TIZEN.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=450000,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/TIZEN.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
