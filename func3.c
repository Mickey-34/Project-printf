#include "main.h"

/****************** PRINT POINTER ******************/
/**
* print_pointer - Prints the value of a pointer variable
* @types: List  of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed.
*/
int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char mason = 0, pool = ' ';
int ind = BUFF_SIZE - 2, mama = 2, pool_start = 1; /* mama=2, for '0x' */
unsigned long num_addrs;
char map_to[] = "0123456789abcdef";
void *addrs = va_arg(types, void *);

UNUSED(width);
UNUSED(size);

if (addrs == NULL)
return (write(1, "(nil)", 5));
buffer[BUFF_SIZE - 1] = '\0';
UNUSED(precision);
num_addrs = (unsigned long)addrs;
while (num_addrs > 0)
{
buffer[ind--] = map_to[num_addrs % 16];
num_addrs /= 16;
mama++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
pool = '0';
if (flags & F_PLUS)
mason = '+', mama++;
else if (flags & F_SPACE)
mason = ' ', mama++;
ind++;
/*return (write(1, &buffer[k], BUFF_SIZE - k - 1));*/
return (write_pointer(buffer, ind, mama,
width, flags, pool, mason, pool_start));
}

/************************* PRINT UN PRINTABLE *************************/
/*
* print_unprintable - Prints ascii codes in hexa of non printable chars
* @types: List of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int print_unprintable(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int k = 0, onga = 0;
char *str = va_arg(types, char *);

UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

if (str == NULL)
return (write(1, "(null)", 6));
while (str[k] != '\0')
{
if (is_printable(str[k]))
buffer[k + onga] = str[k];
else
onga += append_hexa_code(str[k], buffer, k + onga);
k++;
}
buffer[k + onga] = '\0';
return (write(1, buffer, k + onga));
}

/************************* PRINT REVERSE *************************/
/**
* print_reverse - Prints reverse string.
* @types: Lista of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
* Return: Numbers of chars printed
*/
int print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char *str;
int k, compute = 0;

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(size);
str = va_arg(types, char *);
if (str == NULL)
{
UNUSED(precision);
str = ")Null(";
}
for (k = 0; str[k]; k++)
;
for (k = k - 1; k >= 0; k--)
{
char q = str[k];
write(1, &q, 1);
compute++;
}
return (compute);
}

/************************* PRINT A STRING IN ROT13 *************************/
/**
* print_rot13string - Print a string in rot13.
* @types: List of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
* Return: Numbers of chars printed
*/
int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char w;
char *str;
unsigned int x, s;
int compute = 0;
char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
str = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

if (str == NULL)
str = "(AHYY)";
for (x = 0; str[x]; x++)
{
for (s = 0; in[s]; s++)
{
if (in[s] == str[x])
{
w = out[s];
write(1, &w, 1);
compute++;
break;
}
}
if (!in[s])
{
w = str[x];
write(1, &w, 1);
compute++;
}
}
return (compute);
}
