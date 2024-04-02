#include "BSP.h"
#include "debouncer.h"

static bool initialized = false;
static uint8_t pin_num = 0xFFU;
static uint8_t counter = 0;
static debouncer_state_t prev_state = DEBOUNCER_HIGH;

// Duplicated from arduino
#define LOW 0
#define HIGH 1
#define INPUT_PULLUP 2

uint8_t debouncer_init(uint8_t pin)
{
    uint8_t result = DEBOUNCER_ERROR;
    // Correct the pin range
    if (pin <= 57)
    {
        bsp_pin_Mode(pin, INPUT_PULLUP);
        initialized = true;
        result = DEBOUNCER_OK;
        pin_num = pin;
        prev_state = DEBOUNCER_HIGH;
        counter = 0;
    }
    else
    {
        initialized = false;
    }

    return result;
}

void debouncer_update(void)
{
    if (initialized)
    {
        uint8_t curr_state = bsp_digital_Read(pin_num);
        if (prev_state == DEBOUNCER_FALLING_EDGE)
        {
            prev_state = DEBOUNCER_LOW;
        }
        else if (prev_state == DEBOUNCER_RISING_EDGE)
        {
            prev_state = DEBOUNCER_HIGH;
        }

        // if (prev_state != curr_state)
        if (prev_state == DEBOUNCER_HIGH && curr_state == LOW)
        {
            counter++;
        }
        else if (prev_state == DEBOUNCER_FALLING_EDGE && curr_state == HIGH)
        {
            counter++;
        }
        else if (prev_state == DEBOUNCER_LOW && curr_state == HIGH)
        {
            counter++;
        }
        else if (prev_state == DEBOUNCER_RISING_EDGE && curr_state == LOW)
        {
            counter++;
        }
        else
        {
            counter = 0;
        }

        if (counter == 5)
        {
            counter = 0;
            if (prev_state == DEBOUNCER_HIGH)
            {
                prev_state = DEBOUNCER_FALLING_EDGE;
            }
            if (prev_state == DEBOUNCER_LOW)
            {
                prev_state = DEBOUNCER_RISING_EDGE;
            }
        }
    }
}

debouncer_state_t debouncer_get_button_state()
{
    debouncer_state_t result = DEBOUNCER_ERROR;

    if (initialized)
    {
        result = prev_state;
    }
    return result;
}
