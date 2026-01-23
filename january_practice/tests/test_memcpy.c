#include <stdio.h>
#include <stddef.h>

void *memcpy(void *dest, const void *src, size_t n);

int main(void)
{
    {
        unsigned char src[8] = {1, 2, 3, 4, 5, 6, 7, 8};
        unsigned char dest[8] = {0};

        memcpy(dest, src, 8);

        for (size_t i = 0; i < 8; i++)
        {
            if (dest[i] != src[i])
            {
                printf("memcpy did not pass basic copy\n");
                return 1;
            }
        }
    }

    {
        unsigned char src[4] = {9, 9, 9, 9};
        unsigned char dest[4] = {1, 2, 3, 4};

        memcpy(dest, src, 0);

        for (size_t i = 0; i < 4; i++)
        {
            if (dest[i] != (unsigned char)(i + 1))
            {
                printf("memcpy did not pass zero-length copy\n");
                return 1;
            }
        }
    }

    {
        unsigned char src[6] = {10, 20, 30, 40, 50, 60};
        unsigned char dest[6] = {0};

        memcpy(dest, src, 3);

        for (size_t i = 0; i < 3; i++)
        {
            if (dest[i] != src[i])
            {
                printf("memcpy did not pass partial copy (copied bytes)\n");
                return 1;
            }
        }

        for (size_t i = 3; i < 6; i++)
        {
            if (dest[i] != 0)
            {
                printf("memcpy did not pass partial copy (overflow)\n");
                return 1;
            }
        }
    }

    {
        unsigned char src[8] = {0};
        unsigned char dest[8] = {1, 1, 1, 1, 1, 1, 1, 1};

        memcpy(dest, src, 8);

        for (size_t i = 0; i < 8; i++)
        {
            if (dest[i] != 0)
            {
                printf("memcpy did not pass all-zero copy\n");
                return 1;
            }
        }
    }

    {
        unsigned char src[8];
        unsigned char dest[8] = {0};

        for (size_t i = 0; i < 8; i++)
        {
            src[i] = 0xFF;
        }

        memcpy(dest, src, 8);

        for (size_t i = 0; i < 8; i++)
        {
            if (dest[i] != 0xFF)
            {
                printf("memcpy did not pass all-0xFF copy\n");
                return 1;
            }
        }
    }

    {
        unsigned char src[8];
        unsigned char dest[8] = {0};

        for (size_t i = 0; i < 8; i++)
        {
            src[i] = (i % 2 == 0) ? 0xAA : 0x55;
        }        

        memcpy(dest, src, 8);

        for (size_t i = 0; i < 8; i++)
        {
            if (dest[i] != src[i])
            {
                printf("memcpy did not pass alternating-byte copy\n");
                return 1;
            }
        }
    }

    printf("memcpy test passed\n");
    return 0;
}