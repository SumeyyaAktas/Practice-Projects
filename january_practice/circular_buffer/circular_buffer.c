#include <stdint.h>
#include <stddef.h>

typedef struct 
{
    uint8_t * const buffer;
    const int capacity;
    size_t head;
    size_t tail;
} CircularBuffer;

int cb_write(CircularBuffer *c, uint8_t data)
{
    int next;
    next = (c->head + 1) % c->capacity;

    if (next == c->tail)
    {
        return -1;
    }

    c->buffer[c->head] = data;
    c->head = next;
    return 0;
}

int cb_read(CircularBuffer *c, uint8_t *data)
{
    int next;

    if (c->head == c->tail)
    {
        return -1;
    }

    next = (c->tail + 1) % c->capacity;

    *data = c->buffer[c->tail];
    c->tail = next;
    return 0; 
}