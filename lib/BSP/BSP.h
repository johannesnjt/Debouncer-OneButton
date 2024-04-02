#ifndef BSP_H
#define BSP_H

#include <stdint.h>

void bsp_pin_Mode(uint8_t pin, uint8_t mode);
uint8_t bsp_digital_Read(uint8_t pin);

#endif