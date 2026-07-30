#ifndef __RING_BUFFER_H__
#define __RING_BUFFER_H__

#include <stdbool.h>
#include <stdint.h>

struct RingBuffer_s {
    int count;
    int head;
    int tail;
    int *buffer;
    int size;
};
typedef struct RingBuffer_s ring_buffer_t;

bool ring_buffer_init(ring_buffer_t *rb, int *buffer, int size);
bool ring_buffer_push(ring_buffer_t *rb, int data);
bool ring_buffer_pop(ring_buffer_t *rb, int *data);

#endif //..__RING_BUFFER_H__