#include "main.h"
/**
 * IsItPrintable - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int IsItPrintable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
/**
 * appendHexaCode - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int appendHexaCode(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];
	return (3);
}
/**
 * IsItDigit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int IsItDigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
/**
 * ConvertSizeNum - Casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int ConvertSizeNum(long int num, int size)
{
	if (size == longSize)
		return (num);
	else if (size == shortSize)
		return ((short)num);
	return ((int)num);
}
/**
 * ConvertSizeUnsign - Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int ConvertSizeUnsign(unsigned long int num, int size)
{
	if (size == longSize)
		return (num);
	else if (size == shortSize)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
