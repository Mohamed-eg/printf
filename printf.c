#include "main.h"
void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	int i, printed = 0, printedCharts = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[buffSize];
	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == buffSize)
				print_buffer(buffer, &buff_ind);
			printedCharts++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = getFlags(format, &i);
			width = getWidth(format, &i, list);
			precision = getPrecision(format, &i, list);
			size = getSize(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printedCharts += printed;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (printedCharts);
}
/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
