#include "main.h"

/************************* PRINT CHAR *************************/

/**
* print_char - Prints a char
* @types: List  of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: Width
* @precision: precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char c = va_arg(types, int);
return (handle_write_char(c, buffer, flags, width, precision, size));
}

/************************* PRINT A STRING *************************/
/**
* print_string - Prints a string
* @types: List of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width.
* @precision: precision specification
* @size: Size specifier
* Return: Number of char printed
*/
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int car = 0, k;
char *saint = va_arg(types, char *);

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (saint == NULL)
{
saint = "(null)";
if (precision >= 6)
saint = " ";
}
while (saint[car] != '\0')
car++;
if (precision >= 0 && precision < car)
car = precision;
if (width > car)
{
if (flags & F_MINUS)
{
write(1, &saint[0], car);
for (k = width - car; k > 0; k--)
write(1, " ", 1);
return (width);
}
else
{
for (k = width - car; k > 0; k--)
write(1, " ", 1);
write(1, &saint[0], car);
return (width);
}
}
return (write(1, saint, car));
}

/************************* PRINT PERCENT SIGN *************************/
/**
* print_percent - Prints a percent sign
* @types: List of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width.
*@precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
UNUSED(types);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
* print_int - Print int
* @types: List of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width.
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int k = BUFF_SIZE - 2;
int is_negative = 0;
long int n = va_arg(types, long int);
unsigned long int num;
n = convert_size_number(n, size);
if (n == 0)
buffer[k--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
num = (unsigned long int)n;
if (n < 0)
{
num = (unsigned long int)((-1) * n);
is_negative = 1;
}
while (num > 0)
{
buffer[k--] = (num % 10) + '0';
num /= 10;
}
k++;
return (write_number(is_negative, k, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
* print_binary - Prints an unsigned number
* @types: List of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width.
* @precision: Precision specification
* @size: Size specifier
* Return: Numbers of char printed.
*/
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
unsigned int d, e, f, los;
unsigned int a[32];
int compute;

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
d = va_arg(types, unsigned int);
e = 2147483648; /* (2 ^ 31) */
a[0] = d / e;
for (f = 1; f < 32; f++)
{
e /= 2;
a[f] = (d / e) % 2;
}
for (f = 0, los = 0, compute = 0; f < 32; f++)
{
los += a[f];
if (los || f == 31)
{
char q = '0' + a[f];
write(1, &q, 1);
compute++; }
}
return (compute);
}
