#include "holberton.h"

/**
 * print_last_digit - prints the last digit
 * @i: interger to perform on
 * Return: ld
 */

int print_last_digit(int i)
{
	if (i >= 0 && i <= 9)
		i = i;
	else
		i = i % 10;
	if (i < 0)
		i = i * -1;
	_putchar(i);
	return (i);
}
