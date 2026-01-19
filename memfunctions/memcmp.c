#include <stddef.h>

int memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *ps1;
    const unsigned char *ps2;

    ps1 = (const unsigned char *)s1;
    ps2 = (const unsigned char *)s2;

    for (size_t i = 0; i < n; i++)
    {
        if (ps1[i] != ps2[i])
        {
            return ps1[i] - ps2[i];
        }
    }

    return 0;
}