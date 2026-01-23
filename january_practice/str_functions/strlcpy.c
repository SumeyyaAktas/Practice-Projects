#include <stddef.h>

size_t strlcpy(char *dest, const char *src, size_t size)
{
    char *pdest;
    const char *psrc;

    pdest = (char *)dest;
    psrc = (const char *)src;
    
    size_t srclen = 0;

    if (size == 0)
    {
        while (*psrc != '\0')
        {
            psrc++;
            srclen++;
        }
        
        return srclen;
    }

    for (size_t i = 0; i < size - 1 && *psrc != '\0'; i++)
    {
        *pdest++ = *psrc++;
        srclen++;
    }

    *pdest = '\0';

    while (*psrc != '\0')
    {
        psrc++;
        srclen++;
    }

    return srclen;
}