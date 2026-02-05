#include <stddef.h>

void *memchr(const void *mem, int byte, size_t n)
{
    const unsigned char *pmem = mem;
    unsigned char pbyte = (unsigned char)byte;

    for (size_t i = 0; i < n; i++)
    {
        if (pmem[i] == pbyte)
        {
            return (void *)(pmem + i);
        }
    }

    return NULL;
}