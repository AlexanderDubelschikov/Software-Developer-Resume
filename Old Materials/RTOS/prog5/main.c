#include <stdio.h>
#include <board.h>
#include <xtimer.h>
#include <periph/gpio.h>
#include "periph_conf.h"

volatile int k = 1;
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

//Ускоренное прерывание
void btn_handler(void *arg){
	(void)arg;
	if ((xtimer_usec_from_ticks(xtimer_now()) - debounce_timer) > 100000){ 
        if (k==1)
        {
            k=2;
            r=6;
        }
        else if (k==2 && r<6)
        {r=6;}
		debounce_timer = xtimer_usec_from_ticks(xtimer_now());
	}


	
}

//Основное тело цикла
int main(void)
{   
    gpio_init_int(GPIO_PIN(PORT_B,1), GPIO_IN_PU ,GPIO_FALLING, btn_handler, NULL);
    gpio_init(GPIO_PIN(PORT_B, 0), GPIO_OUT);
	while (1){
			
        //Красный свет
			while (k == 1)
		{	delay_ms(500);
        	gpio_set(GPIO_PIN(PORT_B, 0));
        	delay_ms(500);
        	gpio_clear(GPIO_PIN(PORT_B, 0));
            r = r+1;
            if (r==10)
            {
                r=0;
                k=2;
            }
		}
        
        //Желтый свет
        while (k == 2)
    {   delay_ms(250);
        gpio_set(GPIO_PIN(PORT_B, 0));
        delay_ms(250);
        gpio_clear(GPIO_PIN(PORT_B, 0));
        delay_ms(250);
        gpio_set(GPIO_PIN(PORT_B, 0));
        delay_ms(250);
        gpio_clear(GPIO_PIN(PORT_B, 0));
        r = r+1;
        if (r==10)
        {
            r=0;
            k=3;
        }
    }
        
        //Зеленый свет
        while (k == 3)
    {   delay_ms(100);
        gpio_set(GPIO_PIN(PORT_B, 0));
        delay_ms(100);
        gpio_clear(GPIO_PIN(PORT_B, 0));
        delay_ms(100);
        gpio_set(GPIO_PIN(PORT_B, 0));
        delay_ms(100);
        gpio_clear(GPIO_PIN(PORT_B, 0));
        delay_ms(100);
        gpio_set(GPIO_PIN(PORT_B, 0));
        delay_ms(100);
        gpio_clear(GPIO_PIN(PORT_B, 0));
        delay_ms(100);
        gpio_set(GPIO_PIN(PORT_B, 0));
        delay_ms(100);
        gpio_clear(GPIO_PIN(PORT_B, 0));
        delay_ms(100);
        gpio_set(GPIO_PIN(PORT_B, 0));
        delay_ms(100);
        gpio_clear(GPIO_PIN(PORT_B, 0));
        r = r+1;
        if (r==10)
        {
            r=0;
            k=1;
        }
    }
		
	
}
return 0;
}


