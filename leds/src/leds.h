#include "stdint.h"
#include <stdbool.h>

#define ALL_LEDS_OFF 	0x0000
#define ALL_LEDS_ON 	0xFFFF
#define LED_ON 		1
#define LED_OFF 	0
#define LED_OFFSET 	1
#define LED_MAX 	16

void Leds_Create(uint16_t* puntero);
void Leds_TurnOn(uint8_t led);
void Leds_TurnOff(uint8_t led);
void Leds_TurnAllOff(void);
void Leds_TurnAllOn(void);
bool Leds_State(uint8_t led);
