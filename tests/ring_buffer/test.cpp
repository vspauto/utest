#include "CppUTest/TestHarness.h"

extern "C" {
    #include "ring_buffer.h"
}

#define BUFFER_SIZE 3

// Create a test group
TEST_GROUP(ring_buffer_test_group)
{
    ring_buffer_t rb;
    int raw_buffer[BUFFER_SIZE];

    void setup()
    {
        // Initialize before each test
        ring_buffer_init(&rb, raw_buffer, BUFFER_SIZE);
    }
    
    void teardown()
    {
        // Deinitialize after each test
    }
};


TEST(ring_buffer_test_group, test_InitEmpty)
{
    CHECK_EQUAL(0, rb.count);
    POINTERS_EQUAL(raw_buffer, rb.buffer);
}


TEST(ring_buffer_test_group, test_PushPop)
{
    int out_val = 0;
    
    CHECK_TRUE(ring_buffer_push(&rb, 42));
    CHECK_EQUAL(1, rb.count);
    
    CHECK_TRUE(ring_buffer_pop(&rb, &out_val));
    CHECK_EQUAL(42, out_val);
    CHECK_EQUAL(0, rb.count);
}

TEST(ring_buffer_test_group, test_OverflowAndUnderflow)
{
    int out_val = 0;
    
    //push 3
    CHECK_TRUE(ring_buffer_push(&rb, 10));
    CHECK_TRUE(ring_buffer_push(&rb, 20));
    CHECK_TRUE(ring_buffer_push(&rb, 30));
    // check overflow
    CHECK_FALSE(ring_buffer_push(&rb, 40));

    //pop all 3
    CHECK_TRUE(ring_buffer_pop(&rb, &out_val));
    CHECK_TRUE(ring_buffer_pop(&rb, &out_val));
    CHECK_TRUE(ring_buffer_pop(&rb, &out_val));
    // check underflow
    CHECK_FALSE(ring_buffer_pop(&rb, &out_val));
}




