#include <stdint.h>
#include "sensor.h"

#define SENSOR_I2C_ADDR 0x48
#define TEMP_REG_ADDR   0x01

int read_temperature_sensor(void)
{
    uint8_t raw_temp = 0;
    bool result;

    result = I2C_read(SENSOR_I2C_ADDR, TEMP_REG_ADDR, &raw_temp, 1);
    if(result != true) {
        return -999; /* ERROR */
    }
    int celsius = (int)raw_temp;
    return celsius;
}