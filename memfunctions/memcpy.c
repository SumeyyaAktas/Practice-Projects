#include <stddef.h>

void *memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *pdest;
    const unsigned char *psrc;

    pdest = (unsigned char *)dest;
    psrc = (const unsigned char *)src;

    for (size_t i = 0; i < n; i++)
    {
        *(pdest) = *(psrc);
        
        pdest++;
        psrc++;
    }

    return dest;
}