#ifndef DEBOUNCER_H
#define DEBOUNCER_H

#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    DEBOUNCER_LOW = 'L',
    DEBOUNCER_HIGH = 'H',
    DEBOUNCER_FALLING_EDGE = 'F',
    DEBOUNCER_RISING_EDGE = 'R',
    DEBOUNCER_ERROR,
    DEBOUNCER_OK,
} debouncer_state_t;

uint8_t debouncer_init(uint8_t pin);

void debouncer_update(void);

debouncer_state_t debouncer_get_button_state();
#endif