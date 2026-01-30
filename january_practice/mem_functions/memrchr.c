#include <stddef.h>

void *memrchr(const void *mem, int byte, size_t n)
{
    const unsigned char *pmem = mem;
    unsigned char pbyte = (unsigned char)byte;

    if (n == 0)
    {
        return NULL;
    }

    for (size_t i = n; i > 0; i--)
    {
        if (pmem[i - 1] == pbyte)
        {
            return (void *)(pmem + i - 1);
        }
    }

    return NULL;
}