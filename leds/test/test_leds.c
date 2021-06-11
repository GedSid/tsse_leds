#include "unity.h"
#include "leds.h"

#define LED 5

uint16_t ledsVirtuales;

void setUp(void){
    Leds_Create(&ledsVirtuales);
}

void tearDown(void){

}

void test_LedsOffAfterCreate(void){
    ledsVirtuales = ALL_LEDS_ON;
    Leds_Create(&ledsVirtuales);
    TEST_ASSERT_EQUAL_HEX16(ALL_LEDS_OFF, ledsVirtuales);
}

void test_TurnOnLedOne(void){
    Leds_TurnOn(LED);
    TEST_ASSERT_EQUAL_HEX16(1<<(LED-1), ledsVirtuales);
}

void test_TurnOffOneLed(void){
    Leds_TurnOn(LED);
    Leds_TurnOff(LED);
    TEST_ASSERT_EQUAL_HEX16(ALL_LEDS_OFF, ledsVirtuales);
}

void test_TurnOnAndOffManyLeds(void){
    Leds_TurnOn(3);
    Leds_TurnOn(LED);
    Leds_TurnOff(3);
    TEST_ASSERT_EQUAL_HEX16(1 << (LED - 1), ledsVirtuales);
}

// 1) Se pueden prender todos los LEDs de una vez.
void test_TurnAllOn(void){
   Leds_TurnAllOn();
   TEST_ASSERT_EQUAL_HEX16(ALL_LEDS_ON, ledsVirtuales);   
}

// 2) Se pueden apagar todos los LEDs de una vez.
void test_TurnAllOff(void){
   Leds_TurnAllOn();
   Leds_TurnAllOff();
   TEST_ASSERT_EQUAL_HEX16(ALL_LEDS_OFF, ledsVirtuales);
}

// 3) Se puede consultar el estado de un LED apagado.
void test_Leds_StateOff(void){
   Leds_TurnAllOff();
   TEST_ASSERT_EQUAL(LED_OFF, Leds_State(3));
}

// 4) Se puede consultar el estado de un LED prendido.
void test_Leds_StateOn(void){
   Leds_TurnOn(3);
   TEST_ASSERT_EQUAL(LED_ON, Leds_State(3));
}

// 5) Revisar limites de los parametros.
void test_Leds_OnLimit(void){
   Leds_TurnOn(LED_MAX+1);
   TEST_ASSERT_EQUAL_HEX16(ALL_LEDS_OFF, ledsVirtuales);
}

void test_Leds_OffLimit(void){
   Leds_TurnAllOn();
   Leds_TurnOff(LED_MAX+1);
   TEST_ASSERT_EQUAL_HEX16(ALL_LEDS_ON, ledsVirtuales);
}
