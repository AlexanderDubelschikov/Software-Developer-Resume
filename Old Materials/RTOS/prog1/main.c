#include <stdio.h>
#include <board.h>
#include <xtimer.h>
#include <periph/gpio.h>
#include "periph_conf.h"
#include "thread.h"

uint32_t debounce_timer = 0;
char stack_one[THREAD_STACKSIZE_DEFAULT];


//Таймер для моргания
    void delay_ms(const uint16_t ms)
{
        uint32_t i = ms * 4000;
        while (i-- > 0) {
          __asm("nop");
        }
}

void *thread_one(void *arg){
    (void) arg;
    static const int a;
    static int b;
    const int d;
    printf("Thred.Static const local to main() is at %p\n\r", &a);
    printf("Thred.Static local to main() is at %p\n\r", &b);
    printf("Thred.Const local to main() is at %p\n\r", &d);
    return NULL;
}

//Ускоренное прерывание
void btn_handler(void *arg){
    (void)arg;
    if ((xtimer_usec_from_ticks(xtimer_now()) - debounce_timer) > 100000){
        static const int z;
        static int x;
        const int c;
        printf("Prer.Static const local to main() is at %p\n\r", &z);
        printf("Prer.Static local to main() is at %p\n\r", &x);
        printf("Prer.Const local to main() is at %p\n\r", &c);
        debounce_timer = xtimer_usec_from_ticks(xtimer_now());
    }
}

int main(void)
{   gpio_init_int(GPIO_PIN(PORT_B,1), GPIO_IN_PU ,GPIO_BOTH, btn_handler, NULL);
    static const int i;
    static int r;
    const int v;
    printf("Static const local to main() is at %p\n\r", &i);
    printf("Static local to main() is at %p\n\r", &r);
    printf("Const local to main() is at %p\n\r", &v);
    
    thread_create(stack_one, sizeof(stack_one),
            THREAD_PRIORITY_MAIN-1,
            THREAD_CREATE_STACKTEST,
            thread_one,
            NULL, "thread_one");
    

    return 0;
}
