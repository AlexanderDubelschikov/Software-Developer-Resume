#include "stdint.h"
#include <board.h>
#include <periph/gpio.h>
#include "periph_conf.h"
#include "xtimer.h"


volatile int a,b,c,d,k,r,i,v;
volatile int n[4] = {1,2,3,4};
volatile int z[4];

xtimer_t btn_timer;

void callback_btn(void *arg)
{
    (void) arg;
    gpio_t umdk[4] = {UNWD_GPIO_4, UNWD_GPIO_5, UNWD_GPIO_6, UNWD_GPIO_7};

    for(int i = 0; i < 4; i++)
        gpio_irq_enable(umdk[i]);
}

//Таймер для моргания
    void delay_ms(const uint16_t ms)
{
        uint32_t i = ms * 4000;
        while (i-- > 0) {
          __asm("nop");
        }
}

//Обработчик прерываний для 4-тырехкнопочной клавы
static void btn_handler(void *arg)
{
    gpio_irq_disable(*(gpio_t *) arg);
    
    switch(*(gpio_t *) arg)
    {
     case UNWD_GPIO_4:
        z[i] = 1;
        i = i+1;
        k = k+1;
        break;
     case UNWD_GPIO_5:
        z[i] = 2;
        i = i+1;
        k = k+1;
        break;
     case UNWD_GPIO_6:
        z[i] = 3;
        i = i+1;
        k = k+1;
        break;
     case UNWD_GPIO_7:
        z[i] = 4;
        i = i+1;
        k = k+1;
        break;
    }

    xtimer_set(&btn_timer, 500*1000);

    
}

//Основное тело проекта
int main(void)
{   btn_timer.callback = callback_btn;
    
    gpio_t umdk[4] = {UNWD_GPIO_4, UNWD_GPIO_5, UNWD_GPIO_6, UNWD_GPIO_7};
    for(int i = 0; i < 4; i++)
        gpio_init_int(umdk[i], GPIO_IN_PU, GPIO_FALLING, btn_handler, &umdk[i]);
    gpio_init(GPIO_PIN(PORT_B, 0), GPIO_OUT);
    
    while (1){
        
            //ОТКРЫТЬ
        if (r == 0 && k == 4 && z[0] == n[0] && z[1] == n[1] && z[2] == n[2] && z[3] == n[3])
        {
            gpio_set(GPIO_PIN(PORT_B, 0));
            r = 1;
            k = 0;
            z[0] = 0;
            z[1] = 0;
            z[2] = 0;
            z[3] = 0;
            i = 0;
            v = 0;
            printf("Open\n\r");
        }
        
            //ЗАКРЫТЬ
            else if (r == 1 && k == 4 && z[0] == n[0] && z[1] == n[1] && z[2] == n[2] && z[3] == n[3])
        {
            gpio_clear(GPIO_PIN(PORT_B, 0));
            r = 0;
            k = 0;
            z[0] = 0;
            z[1] = 0;
            z[2] = 0;
            z[3] = 0;
            i = 0;
            v = 0;
            printf("Closed\n\r");
        }
            
            else if (k == 4 && z[0] == 1 && z[1] == 1 && z[2] == 1 && z[3] == 1)
            {   k = 0;
                z[0] = 0;
                z[1] = 0;
                z[2] = 0;
                z[3] = 0;
                i=0;
                gpio_toggle(GPIO_PIN(PORT_B, 0));
                delay_ms(1000);
                gpio_toggle(GPIO_PIN(PORT_B, 0));
            }
            
            //Обнуление и блок
            else if (k == 4 && r !=3 && (z[0] != n[0] || z[1] != n[1] || z[2] != n[2] || z[3] != n[3]))
            {
                k = 0;
                z[0] = 0;
                z[1] = 0;
                z[2] = 0;
                z[3] = 0;
                i=0;
                v=v+1;
                printf("Error\n\r");
            }
        
            //Блок при ошибках
            if (v == 3)
            {r = 3;
            printf("U are blocked\n\r");
            }
        
            
    }
return 0;
}
                            
