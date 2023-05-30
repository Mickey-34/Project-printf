#include "main.h"
/************************* WRITE HANDLE *************************/
/**
* handle_write_char - Prints a string
* @c: char types.
* @buffer: Buffer array to handle print
* @flags: Calculates active flags.
* @width: get width.
* @precision: precision specifier
* @size: Size specifier
* Return: Number of chars printed.
*/
int handle_write_char(char c, char buffer[],
int flags, int width, int precision, int size)
{ /* char is stored at left and poolind at buffer's right */
int k = 0;
char pool = ' ';
UNUSED(precision);
UNUSED(size);
if (flags & F_ZERO)
pool = '0';
buffer[k++] = c;
buffer[k] = '\0';
if (width > 1)
{
buffer[BUFF_SIZE - 1] = '\0';
for (k = 0; k < width - 1; k++)
buffer[BUFF_SIZE - k - 2] = pool;
if (flags & F_MINUS)
return (write(1, &buffer[0], 1) +
write(1, &buffer[BUFF_SIZE - k - 1], width - 1));
else
return (write(1, &buffer[BUFF_SIZE - k - 1], width - 1) +
write(1, &buffer[0], 1));
}
return (write(1, &buffer[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
* write_number - Prints a string
* @is_negative: List of arguments
* @ind: char types.
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width.
* @precision: precision specifier
* @size: Size specifier
* Return: Number of chars to print.
*/
int write_number(int is_negative, int ind, char buffer[],
int flags, int width, int precision, int size)
{
int mama = BUFF_SIZE - ind - 1;
char pool = ' ', mason = 0;

UNUSED(size);
if ((flags & F_ZERO) && !(flags & F_MINUS))
pool = '0';
if (is_negative)
mason = '-';
else if (flags & F_PLUS)
mason = '+';
else if (flags & F_SPACE)
mason = ' ';
return (write_num(ind, buffer, flags, width, precision, mama, pool, mason));
}

/**
* write_num - Write a number using a bufffer
* @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
* @flags: Flags
* @width: width
* @prec: Precision specifier
* @mama: Number length
* @pool: Pading char
* @mason: Extra char
* Return: Number of printed chars.
*/
int write_num(int ind, char buffer[], int flags, int width, int prec,
int mama, char pool, char mason)
{
int k, pool_start = 1;
if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
return (0); /* printf(".0d", 0) no char is printed */
if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
buffer[ind] = pool = ' '; /* width is displayed with padding ' ' */
if (prec > 0 && prec < mama)
pool = ' ';
while (prec > mama)
buffer[--ind] = '0', mama++;
if (mason != 0)
mama++;
if (width > mama)
{
for (k = 1; k < width - mama + 1; k++)
buffer[k] = pool;
buffer[k] = '\0';
if (flags & F_MINUS && pool == ' ')/* Asign extra char to left of buffer */
{
if (mason)
buffer[--ind] = mason;
return (write(1, &buffer[ind], mama) + write(1, &buffer[1], k - 1));
}
else if (!(flags & F_MINUS) && pool == ' ')/* extra char to left of buff */
{
if (mason)
buffer[--ind] = mason;
return (write(1, &buffer[1], k - 1) + write(1, &buffer[ind], mama));
}
else if (!(flags & F_MINUS) && pool == '0')/* extra char to left of padd*/
{
if (mason)
buffer[--pool_start] = mason;
return (write(1, &buffer[ind], mama));
}
}
if (mason)
buffer[--ind] = mason;
return (write(1, &buffer[ind], mama));
}

/**
* write_unsigned - Writes an unsigned number
* @is_negative: Number indicating if the num is negative
* @ind: Index at which the number starts in the buffer
* @buffer: Array of chars
* @flags: Flags specifiers
* @width: Width specifier
* @precision: Precision specifier
* @size: Size specifier
* Return: Number of written chars.
*/
int write_unsigned(int is_negative, int ind, char buffer[],
int flags, int width, int precision, int size)
{
/* The number is stored at the bufer's right and starts at position i */
int mama = BUFF_SIZE - ind - 1, k = 0;
char pool = ' ';
UNUSED(is_negative);
UNUSED(size);
if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
return (0); /* printf(".0d", 0) no char is printed */
if (precision > 0 && precision < mama)
pool = ' ';
while (precision > mama)
{
buffer[--ind] = '0';
mama++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
pool = '0';
if (width > mama)
{
for (k = 0; k < width - mama; k++)
buffer[k] = pool;
buffer[k] = '\0';
if (flags & F_MINUS) /* Assign extra char to left of buffer [buffer>pool]*/
{
return (write(1, &buffer[ind], mama) + write(1, &buffer[0], k));
}
else /* Assign extra char to left of padding [pool>buffer]*/
{
return (write(1, &buffer[0], k) + write(1, &buffer[ind], mama));
}
}
return (write(1, &buffer[ind], mama));
}

/**
* write_pointer - Write a memory address
* @buffer: Arrays of chars
* @ind: Index at which the number starts in the buffer
* @mama: Length of number
* @width: Width specifier
* @flags: Flags specifier
* @pool: Char representing the padding
* @mason: Char represents extra char
* @pool_start: Starting padding index
* Return: Number of written chars.
*/
int write_pointer(char buffer[], int ind, int mama,
int width, int flags, char pool, char mason, int pool_start)
{

int k;
if (width > mama)
{
for (k = 3; k < width - mama + 3; k++)
buffer[k] = pool;
buffer[k] = '\0';
if (flags & F_MINUS && pool == ' ')/* Asign extra char to left of buffer */
{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (mason)
buffer[--ind] = mason;
return (write(1, &buffer[ind], mama) + write(1, &buffer[3], k - 3));
}
else if (!(flags & F_MINUS) && pool == ' ')/* extra char to left of buffer*/
{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (mason)
buffer[--ind] = mason;
return (write(1, &buffer[3], k - 3) + write(1, &buffer[ind], mama));
}
else if (!(flags & F_MINUS) && pool == '0')/* extra char to left of padd*/
{
if (mason)
buffer[--pool_start] = mason;
buffer[1] = '0';
buffer[2] = 'x';
return (write(1, &buffer[pool_start], k - pool_start) +
write(1, &buffer[ind], mama - (1 - pool_start) - 2));
}
}
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (mason)
buffer[--ind] = mason;
return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}

