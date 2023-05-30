#include "main.h"
/**
* get_size - Calculates the size to cast the argument
* @format: Formatted string in which to print the arguments
* @k: List of arguments to be printed.
*
* Return: size.
*/
int get_size(const char *format, int *k)
{
	int dust_k = *k + 1;
	int shoe = 0;

	if (format[dust_k] == 'h')
		shoe = S_SHORT;
	else if (format[dust_k] == 'l')
		shoe = S_LONG;
	if (shoe == 0)
		*k = dust_k - 1;
	else
		*k = dust_k;
	return (shoe);
}
