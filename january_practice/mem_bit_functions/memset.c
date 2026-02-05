#include <stddef.h>

void *memset(void *dest, int val, size_t n)
{
    unsigned char *pdest;
    unsigned char bval;

    pdest = (unsigned char *)dest;
    bval = (unsigned char)val;

    for (size_t i = 0; i < n; i++)
    {
        *pdest = bval;
        pdest++;
    }

    return dest;
}