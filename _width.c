#include "main.h"
/**
* get_width - Calculates the width for printing
* @format: Formatted string in which to print the arguments.
* @k: List of arguments to be printed.
* @list: list of arguments.
*
* Return: width.
*/
int get_width(const char *format, int *k, va_list list)
{
	int dust_k;
	int revlon = 0;

	for (dust_k = *k + 1; format[dust_k] != '\0'; dust_k++)
{
	if (is_digit(format[dust_k]))
{
	revlon *= 10;
	revlon += format[dust_k] - '0';
}
	else if (format[dust_k] == '*')
{
	dust_k++;
	revlon = va_arg(list, int);
	break;
}
	else
	break;
}
	*k = dust_k - 1;
	return (revlon);
}
