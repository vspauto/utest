#include <stdio.h>
#include "average/average.h"
#include "ring_buffer.h"

int main(int argc, char *argv[])
{

    if(argc > 1) {
        for(int i=0; i < argc; i++) {
            printf("%s ", argv[i]);
        }
        printf("\n");
    }

    float array[] = {-1.0, 0.0, 1.0, 2.0, 3.0};
    float avg = average(array, 5);
    printf("Average: %f\r\n", avg);

    ring_buffer_t rb;
    #define RB_SIZE 8
    int buffer[RB_SIZE] = {0};

    printf("\nInit RingBuffer size:%d\n", RB_SIZE);
    ring_buffer_init(&rb, buffer, RB_SIZE);
    printf("--- Pushing items ---\n");
    for (int i = 1; i <= 5; i++) {
        if (ring_buffer_push(&rb, (uint8_t)(i * 10))) {
            printf("Pushed: %d\n", i * 10);
        } else {
            printf("Failed to push %d (Buffer Full)\n", i * 10);
        }
    }

    printf("Current buffer size: %d\n", rb.count);

    printf("--- Popping items ---\n");
    int val;
    while (ring_buffer_pop(&rb, &val)) {
        printf("Popped: %u\n", val);
    }

    return 0;
}