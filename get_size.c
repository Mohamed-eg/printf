#include "main.h"
/**
 * getSize - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int getSize(const char *format, int *i)
{
	/*hh h l ll i z t l */
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = longSize;
	else if (format[curr_i] == 'h')
		size = shortSize;
	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;
	return (size);
}
