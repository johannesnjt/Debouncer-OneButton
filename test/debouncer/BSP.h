#ifndef BSP_h
#define BSP_h

#include <stdint.h>
#include <stdbool.h>

void bsp_pin_Mode(uint8_t pin, uint8_t mode);
uint8_t bsp_digital_Read(uint8_t pin);

void bsp_set_pin_status(bool status);
uint8_t bsp_get_pin_num(void);
uint8_t bsp_get_pin_mode(void);
uint8_t bsp_get_pin_state(void);

#endif