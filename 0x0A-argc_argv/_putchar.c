#include <stdio.h>
#include "main.h"

/**
 * _putchar - writes character c to stdout
 * @c:The character to print
 *
 * Return: on success 1.
 * On error, -1 is returned and error no is set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
