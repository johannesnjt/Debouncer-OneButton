#include <Arduino.h>
#include "BSP.h"

static bool pin_status = true;
static uint8_t pin_num = 0xFFU;
static uint8_t pin_mode = 0xFFU;
static uint8_t pin_state = 0xFFU;

void bsp_pin_Mode(uint8_t pin, uint8_t mode)
{
    pin_num = pin;
    pin_mode = mode;
}

uint8_t bsp_didigtal_read(uint8_t pin)
{
    return digitalRead(pin);
}

void bsp_set_pin_status(bool status)
{
    pin_status = status;
}

uint8_t bsp_get_pin_num(void)
{
    return pin_num;
}

uint8_t bsp_get_pin_mode(void)
{
    return pin_mode;
}

uint8_t bsp_get_pin_state(void)
{
    return pin_state;
}