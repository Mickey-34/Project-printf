#include "main.h"
/**
* get_precision - Calculates the precision for printing
* @format: Formatted string in which to print the arguments
* @k: List of arguments to be printed.
* @list: list of arguments.
*
* Return: Precision.
*/
int get_precision(const char *format, int *k, va_list list)
{
	int dust_k = *k + 1;
	int precision = -1;

	if (format[dust_k] != '.')
	return (precision);
	precision = 0;
	for (dust_k += 1; format[dust_k] != '\0'; dust_k++)
{
	if (is_digit(format[dust_k]))
{
	precision *= 10;
	precision += format[dust_k] - '0';
}
	else if (format[dust_k] == '*')
{
	dust_k++;
	precision = va_arg(list, int);
	break;
}
	else
	break;
}
	*k = dust_k - 1;
	return (precision);
}
