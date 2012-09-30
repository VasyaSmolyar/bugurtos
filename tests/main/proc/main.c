#include <test_func.h>

proc_t proc[6];
stack_t proc_stack[6][PROC_STACK_SIZE];

bool_t test;

void main_proc_test( void * arg )
{
    proc_run( &proc[1] );

    test_start();
    // No other processes are running,
    // so it's not necessary to disable interrupts or to spin_lock something.

    // proc_run test 1
    proc[2].flags |= PROC_FLG_DEAD;
    // Must NOT run the process.
    test = !proc_run( &proc[2] );
    test_output( test , 1 );

    // proc_run test 2
    proc[2].flags &= ~PROC_FLG_DEAD;
    proc[2].flags |= PROC_FLG_MUTEX;
    // Must run the process
    test = proc_run( &proc[2] );
    test_output( test , 2 );

    // proc_terminate test 3
    wait_time( 10 );
    // proc[2] has higher priority, so it must BE DEAD now!
    test = !!(proc[2].flags & PROC_FLG_DEAD);
    test_output( test , 3 );

    // proc_terminate test 4
    proc_run( &proc[3] );
    wait_time( 10 );
    test = (bool_t)(!(proc[3].flags & PROC_FLG_DEAD)) && (!!(proc[3].flags & PROC_FLG_END));
    test_output( test , 4 );

    // proc_restart test 5
    // Must NOT restart!
    test = !proc_restart( &proc[2] );
    test_output( test , 5 );

    // proc_restart test 6
    // Must restart!
    test = proc_restart( &proc[3] );
    test_output( test , 6 );

    // proc_stop test 7
    // Must return 1, process is not running now!
    proc[2].flags &= ~(PROC_FLG_MUTEX|PROC_FLG_DEAD);
    test = proc_stop( &proc[2] );
    test_output( test , 7 );


    proc_run( &proc[4] );

    // proc_flag_stop test 8
    // Must NOT stop the process!
    wait_time(2); // let proc[4] to call proc_flag_stop!
    test = !!( proc[4].flags & PROC_FLG_RUN );
    test_output( test , 8 );

    // proc_stop test 9
    // Must stop the process!
    test = proc_stop( &proc[4] );
    test_output( test , 9 );

    // proc_stop test 10
    // Must NOT stop the process!
    proc[4].flags |= PROC_FLG_SEM; // proc[4] is stoped, we can work with it,s properties!
    proc_run( &proc[4] );
    test = !proc_stop( &proc[4] );
    test = test && !!( proc[4].flags & PROC_FLG_PRE_STOP );
    test_output( test , 10 );

    // proc_flag_stop test 11
    // Must stop the process!
    wait_time(20); // let proc[4] to call proc_flag_stop!
    test = !( proc[4].flags & PROC_FLG_RUN );
    test_output( test , 11 );

    // proc_reset_watchdog test 12
    test = 0;
    proc_run( &proc[5] );
    wait_time(10); // let proc[5] test proc_reset_watchdog!
    test_output( test , 12 );

    // proc_self_stop test 13
    wait_time(10); // let proc[4] to call proc_self_stop!
    test = !( proc[5].flags & PROC_FLG_RUN );
    test_output( test , 13 );

    // proc_reset_watchdog test 14
    test = 0;
    proc[5].flags &= ~PROC_FLG_RT;
    proc_run( &proc[5] );
    wait_time(10); // let proc[5] test proc_reset_watchdog!
    test_output( test , 14 );

    tests_end();
}

void main_with_return( void * arg )
{
    wait_time(1);
}

void main_wd_ss( void * arg )
{
    // proc_reset_watchdog test 12
    wait_time(1);
    proc_reset_watchdog();
    wait_time(1);
    proc_reset_watchdog();
    wait_time(1);
    proc_reset_watchdog();
    wait_time(1);
    proc_reset_watchdog();
    test = 1; // If wathdog has been reset then test must pass.
    proc_self_stop();
    // proc_reset_watchdog test 14
    wait_time(1);
    proc_reset_watchdog();
    test = (proc[5].timer != proc[5].time_quant);
}

void main_fs( void * arg )
{
    while(1)
    {
        // For proc_flag_stop tests 8 and 11
        proc_flag_stop( PROC_FLG_SEM );
        wait_time(10);
    }
}

void main_lb( void * arg )
{
    while(1)
    {
        wait_time(10);
        // Run local load balancer on multicore system with local load balancing.
        SCHED_LOCAL_LOAD_BALANCER();
    }
}

void idle_main( void * arg )
{
    while(1)
    {
        wait_time(10);
        // Run local/global load balancer on multicore system with local/global lazy load balancing.
        SCHED_IDLE_LOAD_BALANCER();
    }
}

int main(void)
{
    /**************************************************
    *          For test purposes only!!!              *
    *  It is strongly recomended to initiate hardware *
    *         AFTER init_bugurt() call!!!             *
    **************************************************/
    /*
     * This function disables interrupts
     * and initiates hardware.
     */
    init_hardware();
    init_bugurt();

    proc_init_isr( &proc[0], main_proc_test,     SVH0, RSH0, 0, &proc_stack[0][PROC_STACK_SIZE-1], 4,      1, 0 ARG_END );
    proc_init_isr( &proc[1], main_lb,            SVH1, RSH1, 0, &proc_stack[1][PROC_STACK_SIZE-1], LOWEST, 1, 0 SCHED_ARG_END );
    proc_init_isr( &proc[2], main_with_return,   SVH2, RSH2, 0, &proc_stack[2][PROC_STACK_SIZE-1], 0,      2, 0 ARG_END );
    proc_init_isr( &proc[3], main_with_return,   SVH3, RSH3, 0, &proc_stack[3][PROC_STACK_SIZE-1], 1,      2, 0 ARG_END );
    proc_init_isr( &proc[4], main_fs,            SVH4, RSH4, 0, &proc_stack[4][PROC_STACK_SIZE-1], 2,      2, 0 ARG_END );
    proc_init_isr( &proc[5], main_wd_ss,         SVH5, RSH5, 0, &proc_stack[5][PROC_STACK_SIZE-1], 3,      2, 1 ARG_END );

    proc_run_isr( &proc[0] );

    start_bugurt();
    return 0;
}