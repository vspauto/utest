#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "CppUTestExt/MockSupport_c.h"

bool I2C_read(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data, size_t length)
{
    // Record the actual call parameters and the output buffer
    return  mock_c()->actualCall("I2C_read")
    ->withUnsignedIntParameters("dev_addr", dev_addr)
    ->withUnsignedIntParameters("reg_addr", reg_addr)
    ->withOutputParameter("data", data) // Points to the buffer to be filled
    ->withUnsignedIntParameters("length", (unsigned int)length)
    ->returnBoolValueOrDefault(false);
}