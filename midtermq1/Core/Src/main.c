#include "main.h"
#include "usb_host.h"

int i;


void init_leds(){
    RCC->AHB1ENR|=(1<<3);
    GPIOD->MODER=(1<<26);
    GPIOD->MODER |= (1<<30);

}
void turn_name_on(){
    GPIOD->ODR |= (1<<13);
}
void turn_surname_on(){

    GPIOD->ODR |= (1<<15);
}
void turn_name_off(){
    GPIOD->ODR = (0<<13);
}
void turn_surname_off(){

    GPIOD->ODR = (0<<15);
}
void delay(){
    int delay0 = 0x000FFFFF;
    while (delay0--);
        }

int main(){
    init_leds();

	for(i=0;i<10;i++)
    {
        turn_name_on();
        delay();
        turn_name_off();
        delay();

    }
    turn_name_off();
    for(i=0;i<6;i++){
            turn_surname_on();
            delay();
            turn_surname_off();
            delay();
        }

}
