#include <ctype.h>
#include <stddef.h>

/**
 * is_number - Checks if a string is a valid integer
 * @str: The string to check
 *
 * Return: 1 if the string is a valid integer, 0 otherwise
 */
int is_number(const char *str)
{
    if (str == NULL || *str == '\0')
        return 0;

    if (*str == '-' || *str == '+')
        str++;  /* Handle negative or positive sign */

    while (*str)
    {
        if (!isdigit(*str))
            return 0;
        str++;
    }

    return 1;
}
