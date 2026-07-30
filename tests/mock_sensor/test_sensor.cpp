#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

extern "C" {
    #include "sensor.h"
}

TEST_GROUP(SendorTestGroup)
{
    void setup() override 
    {

    }
    void teardown() override
    {
        mock().checkExpectations();
        mock().clear();
    }
};

TEST(SendorTestGroup, ReadTempSuccess)
{
    uint8_t mock_temp_raw = 25;

    mock().expectOneCall("I2C_read")
          .withParameter("dev_addr", 0x48)
          .withParameter("reg_addr", 0x01)
          .withParameter("length", 1)
          .withOutputParameterReturning("data", 
            &mock_temp_raw, sizeof(mock_temp_raw))
          .andReturnValue(true);

    int temp = read_temperature_sensor();
    LONGS_EQUAL(25, temp);
}

TEST(SendorTestGroup, ReadTempFail)
{
    mock().expectOneCall("I2C_read")
          .ignoreOtherParameters()
          .andReturnValue(false);

    int temp = read_temperature_sensor();
    LONGS_EQUAL(-999, temp);
}