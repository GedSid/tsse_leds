#include "leds.h"

static uint16_t* puerto;

uint16_t led_to_bit(uint8_t led){
    return (LED_ON << (led - LED_OFFSET));
}

void Leds_Create(uint16_t* puntero){
    puerto = puntero;
    *puerto = ALL_LEDS_OFF;
}

void Leds_TurnOn(uint8_t led){
    *puerto |= led_to_bit(led);
}

void Leds_TurnOff(uint8_t led){
    *puerto &= ~led_to_bit(led);
}

void Leds_TurnAllOff(void){
   *puerto = ALL_LEDS_OFF;
};

void Leds_TurnAllOn(void){
   *puerto = ALL_LEDS_ON;
}

bool Leds_State(uint8_t led){
    if((*puerto) == (1 << (led-LED_OFFSET))){
        return LED_ON;
    }
    else{
        return LED_OFF;
    }
}
