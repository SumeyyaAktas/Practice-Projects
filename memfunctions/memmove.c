#include <stddef.h>

void *memmove(void *dest, const void *src, size_t n)
{
    unsigned char *pdest;
    const unsigned char *psrc;

    pdest = (unsigned char *)dest;
    psrc = (const unsigned char *)src;

    if (dest < src)
    {
        for (size_t i = 0; i < n; i++)
        {
            *(pdest) = *(psrc);
        
            pdest++;
            psrc++;
        }
    }
    else if (dest > src)
    {
        for (size_t i = n; i > 0; i--)
        {
            pdest[i-1] = psrc[i-1];  
        }
    }

    return dest;
}