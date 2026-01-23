#include <stddef.h>

typedef union Chunk Chunk;
union Chunk {
    Chunk* next;
    char arr[64];
};

typedef struct Pool Pool;
struct Pool {
    Chunk* free_chunk;
    Chunk* chunk_arr; 
};

Pool* pool_create(void *memory_space, size_t pool_size)
{
    Pool *self = (Pool *)(memory_space);

    if (self == NULL)
    {
        return NULL;
    }

    self->chunk_arr = (Chunk *)((char *)memory_space + sizeof(Pool));
    self->free_chunk = self->chunk_arr;

    for (size_t i = 0; i < pool_size - 1; i++)
    {
        self->chunk_arr[i].next = &self->chunk_arr[i + 1];
    }

    self->chunk_arr[pool_size - 1].next = NULL;
    return self;
}

void* pool_alloc(Pool *self)
{
    if (self == NULL || self->free_chunk == NULL)
    {
        return NULL;
    }

    Chunk* first_block = self->free_chunk;
    self->free_chunk = first_block->next;
    return first_block;
}

void pool_free(Pool *self, void* ptr)
{
    if (self == NULL || ptr == NULL)
    {
        return;
    }

    Chunk* freed = ptr;
    freed->next = self->free_chunk;
    self->free_chunk = freed;
}