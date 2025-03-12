#include <stdio.h>
#include <board.h>
#include <xtimer.h>
#include <periph/gpio.h>
#include "periph_conf.h"
#include "msg.h"

volatile int k = 0;
volatile int r = 0;
int i = 1;
int a;
uint32_t debounce_timer = 0;

//Таймер для моргания
	void delay_ms(const uint16_t ms) 
{
    	uint32_t i = ms * 4000; 
    	while (i-- > 0) {
      	__asm("nop");
    	}
}

void btn_handler(void *arg){
    (void) arg;
    
    if (gpio_read(GPIO_PIN(PORT_B,1)) > 0){
        if ((xtimer_usec_from_ticks(xtimer_now()) - debounce_timer) > 100000){
            if (r==1)
            {r=0;}
            else
            {r=1;}
            k = 2;
    debounce_timer = xtimer_usec_from_ticks(xtimer_now());
        
    }
    }
    else {
        if ((xtimer_usec_from_ticks(xtimer_now()) - debounce_timer) > 100000){
        k = 1;
            debounce_timer = xtimer_usec_from_ticks(xtimer_now());
    }
}
}

//Основное тело цикла
int main(void)
{   gpio_init_int(GPIO_PIN(PORT_B,1), GPIO_IN_PU ,GPIO_BOTH, btn_handler, NULL);
    gpio_init(GPIO_PIN(PORT_B, 0), GPIO_OUT);
	while (1){
    
        
        while (r == 1)
        {
            
                
			if (k == 1)
		{	delay_ms(200);
        	gpio_set(GPIO_PIN(PORT_B, 0));
        	delay_ms(200);
            gpio_clear(GPIO_PIN(PORT_B, 0));
            delay_ms(200);
            gpio_set(GPIO_PIN(PORT_B, 0));
            delay_ms(200);
            gpio_clear(GPIO_PIN(PORT_B, 0));
            r = 1;

		}
		
            if (k == 2)
        {
            delay_ms(500);
            gpio_set(GPIO_PIN(PORT_B, 0));
            delay_ms(500);
            gpio_clear(GPIO_PIN(PORT_B, 0));
            
        }
            }
    
}
return 0;
}


