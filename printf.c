#include "main.h"
void printBuffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	int i, printed = 0, printedCharts = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;/*Declare a va_list object*/
	char buffer[buffSize];

/**/
	if (format == NULL)
		return (-1);/*This line checks if the format string is NULL. If it is, it returns -1 to indicate an error.*/
	va_start(list, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')/*This line checks if the current character in the format string is not a %.*/
		{
			buffer[buff_ind++] = format[i];/*If the current character is not a %, it is copied to the buffer array at index buff_ind. The buff_ind is then incremented.*/
			if (buff_ind == buffSize)
				printBuffer(buffer, &buff_ind);/*f the buff_ind reaches the buffSize, it means the buffer is full. In this case, the printBuffer function is called to flush the buffer to the output. The &buff_ind is passed to the function to update the buff_ind after printing.*/
			printedCharts++;
		}
		else
		{
			printBuffer(buffer, &buff_ind);
			flags = getFlags(format, &i);/*The getFlags function is called to parse the format flags from the format string starting from the current character. The &i is passed to the function to update the i after parsing the flags.*/
			width = getWidth(format, &i, list);
			precision = getPrecision(format, &i, list);
			size = getSize(format, &i);/*The getSize function is called to parse the size modifier from the format string starting from the current character. The &i is passed to the function to update the i after parsing the size.*/
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);/*If handle_print returns -1, it indicates an error. In this case, the function returns -1 to propagate the error.*/
			printedCharts += printed;
		}
	}
	printBuffer(buffer, &buff_ind);/*The printBuffer function is called to flush any remaining characters in the buffer to the output.*/
	va_end(list);
	return (printedCharts);
}
/**
 * printBuffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void printBuffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
