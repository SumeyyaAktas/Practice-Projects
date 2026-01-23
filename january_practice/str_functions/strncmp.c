#include <stddef.h>

int strncmp(const char *s1, const char *s2, size_t n)
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

        if (ps1[i] == '\0')
        {
            return 0;
        }
    }

    return 0;
}