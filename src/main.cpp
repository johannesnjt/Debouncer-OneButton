#include <Metro.h>
#include <Arduino.h>
#include "debouncer.h"

#define UPDATE_TIME 10

#define BUTTON_1_PIN 33
// #define BUTTON_2_PIN 34
// #define BUTTON_3_PIN 35

static uint8_t prev_state1 = DEBOUNCER_HIGH;
static uint8_t prev_state2 = DEBOUNCER_HIGH;
static uint8_t prev_state3 = DEBOUNCER_HIGH;
static Metro timer = Metro(UPDATE_TIME);

void setup()
{
  Serial.begin(9600);
  delay(2000);

  debouncer_init(BUTTON_1_PIN);
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (timer.check())
  {
    debouncer_update();
    uint8_t state1 = debouncer_get_button_state();
    // uint8_t state2 = Debouncer_get_button_state(BUTTON2);
    // uint8_t state3 = Debouncer_get_button_state(BUTTON3);

    if (prev_state1 != state1)
    {
      prev_state1 = state1;
      Serial.printf("BUTTON 1 State = %c\n", state1);
    }

    /* if (prev_state != state2)
    {
      prev_state2 = state2;
      Serial.printf("BUTTON 2 State = %d\n", state2);
    }

    if (prev_state3 != state3)
    {
      prev_state3 = state3;
      Serial.printf("BUTTON 3 State = %d\n", state3);
    } */
  }
}