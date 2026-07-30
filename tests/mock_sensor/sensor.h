#ifndef __SENSOR_H__
#define __SENSOR_H__

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

//int i2c_read(uint8_t dev_addr, uint8_t reg, uint8_t *data);
bool I2C_read(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data, size_t length);
int read_temperature_sensor(void);
#endif