#include "main.h"
/**
* is_printable - Evaluates if a char is printable
* @d: Char to be evaluated.
*
* Return: 1 if d is printable, 0 otherwise
*/
int is_printable(char d)
{
	if (d >= 32 && d < 127)
		return (1);
	return (0);
}

/**
* append_hexa_code - Append ascii in hexadecimal code to buffer
* @buffer: Array of chars.
* @k: Index at which to start appending.
* @ascii_code: ASSCI CODE.
* Return: Must be 3
*/
int append_hexa_code(char ascii_code, char buffer[], int k)
{
	char map_to[] = "0123456789ABCDEF";
/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[k++] = '\\';
	buffer[k++] = 'x';
	buffer[k++] = map_to[ascii_code / 16];
	buffer[k] = map_to[ascii_code % 16];
	return (3);
}

/**
 * is_digit - Verifies if a char is a digit
* @w: Char to be evaluated
*
* Return: 1 if w is a digit, 0 otherwise
*/
int is_digit(char w)
{
	if (w >= '0' && w <= '9')
		return (1);
	return (0);
}

/**
* convert_size_number - Casts a number to the specified size
* @num: The number to cast.
* @size: Number indicating the type to be casted.
* Return: Casted value of num
*/
long int convert_size_number(long int num, int size)
{
	if (size == S_SHORT)
		return (num);
	else if (size == S_LONG)
		return ((long)num);
	return ((int)num);
}

/**
* convert_size_unsigned - Casts a number to the specified size
* @num: The number to be casted
* @size: Number indicating the type to be casted
* Return: value of num casted
*/
long int convert_size_unsigned(unsigned long int num, int size)
{
	if (size == S_SHORT)
		return (num);
	else if (size == S_LONG)
		return ((unsigned long)num);
	return ((unsigned int)num);
}
