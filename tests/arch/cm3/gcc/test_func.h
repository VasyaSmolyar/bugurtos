#include <bugurt.h>
#include <stm32l1xx.h>
extern void(*test_kernel_preempt)(void);
extern proc_t proc[6];
extern stack_t proc_stack[6][PROC_STACK_SIZE];

#define ARG_END

// No load balancing, single core!
#define SCHED_LOCAL_LOAD_BALANCER()
#define SCHED_IDLE_LOAD_BALANCER()
#define SCHED_ARG_END
#define SCHED_LB_TEST_START()

#define SCHED_SYSTICK_HOOK_ADD() (kernel.timer_tick = systick_hook)

#define SCHED_FIX_PROC_2() sched_fix_proc_2()

/// TODO write led init and control!!!
#define LED_ON()
#define LED_OFF()

void kernel_preemt_hook_add( void(*arg)(void) );
void kernel_preemt_hook(void);
void test_do_nothing(void);

void init_hardware(void);
void sched_fix_proc_2(void);

// proc test functions
void test_output( bool_t test_result, count_t test_mun );
void test_start(void);
void tests_end(void);

// signal test functions
extern unsigned char test_var_sig;
void test_clear(void);
void test_inc(void);


void systick_hook(void);


