#include <stddef.h>

size_t strnlen(const char *s, size_t maxlen)
{
    const char *ps = s;
    size_t slen = 0;

    while (*ps != '\0' && slen < maxlen)
    {
        ps++;
        slen++;
    }

    return slen;
}