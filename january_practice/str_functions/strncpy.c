#include <stddef.h>

char *strncpy(char *dest, const char *src, size_t n)
{
    char *pdest;
    const char *psrc;

    for (size_t i = 0; i < n; i++)
    {   
        if (*psrc != '\0')
        {
            *(pdest) = *(psrc);
            psrc++;
        }
        else
        {
            *pdest = '\0';
        }

        pdest++;
    }

    return dest;
}