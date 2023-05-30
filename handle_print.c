#include "main.h"
/**
* handle_print - Prints an argument based on its type
* @jir: Formatted string in which to print the arguments.
* @list: List of arguments to be printed.
* @k: k.
* @buffer: Buffer array to handle print.
* @flags: Calculates active flags
* @width: get width.
* @precision: Precision specification
* @size: Size specifier
* Return: 1 or 2;
*/
int handle_print(const char *jir, int *k, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int f, saka = 0, navy = -1;
	jir_r jir_types[] = {
{'c', print_char}, {'s', print_string}, {'%', print_percent},
{'i', print_int}, {'d', print_int}, {'b', print_binary},
{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_unprintable},
{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
};
for (f = 0; jir_types[f].jir != '\0'; f++)
if (jir[*k] == jir_types[f].jir)
return (jir_types[f].a(list, buffer, flags, width, precision, size));
if (jir_types[f].jir == '\0')
{
	if (jir[*k] == '\0')
		return (-1);
	saka += write(1, "%%", 1);
	if (jir[*k - 1] == ' ')
		saka += write(1, " ", 1);
	else if (width)
{
	--(*k);
	while (jir[*k] != ' ' && jir[*k] != '%')
		--(*k);
	if (jir[*k] == ' ')
		--(*k);
	return (1);
}
	saka += write(1, &jir[*k], 1);
	return (saka);
}
	return (navy);
}
