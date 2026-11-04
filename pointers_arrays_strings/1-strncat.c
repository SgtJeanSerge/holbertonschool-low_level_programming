#include "main.h"

/**
 * _strncat - concatenates at most n bytes of src to dest
 * @dest: pointer to the destination string
 * @src: pointer to the string to append
 * @n: maximum number of bytes to use from src
 *
 * Return: pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i;
        int j;

        i = 0;

        while (dest[i] != '\0')
        {
                i++;
        }

        j = 0;

        while (j < n && src[j] != '\0')
        {
                dest[i] = src[j];
                i++;
                j++;
        }
        dest[i] = '\0';

        return (dest);
}
