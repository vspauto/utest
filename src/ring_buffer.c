#include <stdbool.h>
#include "ring_buffer.h"


bool ring_buffer_init(ring_buffer_t *rb, int *buffer, int size)
{
    rb->count = 0;
    rb->head = 0;
    rb->tail = 0;
    rb->size = size;
    rb->buffer = buffer;
    return true;
}

bool ring_buffer_is_full(ring_buffer_t *rb)
{
    if(rb->count == rb->size)
        return true;
    return false;

}
bool ring_buffer_is_empty(ring_buffer_t *rb)
{
    if(rb->count == 0)
        return true;
    return false;
}

bool ring_buffer_push(ring_buffer_t *rb, int data)
{
    if (ring_buffer_is_full(rb)) {
        return false; // Buffer is full
    }

    rb->buffer[rb->head] = data;
    rb->head = (rb->head + 1) % rb->size;

    // If head catches up to tail, the buffer is now full
    //if (rb->head == rb->tail) {
    //    rb->full = true;
    //}
    rb->count++;

    return true;
}

bool ring_buffer_pop(ring_buffer_t *rb, int *data)
{
    if (ring_buffer_is_empty(rb)) {
        return false; // Buffer is empty
    }

    *data = rb->buffer[rb->tail];
    rb->tail = (rb->tail + 1) % rb->size;
    
    // Since we just removed an item, it can no longer be full
    //rb->full = false;
    rb->count--;
    
    return true;
}