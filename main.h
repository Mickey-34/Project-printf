#ifndef MAIN_H 
#define MAIN_H
 #include <stdarg.h> 
#include <stdio.h> 
#include <unistd.h>
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_SPACE 16
#define F_HASH 8
#define F_ZERO 4 
#define F_PLUS 2
#define F_MINUS 1

/* SIZES */
 #define S_SHORT 1
#define S_LONG 2

/**
* struct jir - Struct op 
* @jir: The format.
* @a: The function associated. 
*/
struct jir 
{
char jir;
int (*a)(va_list, char[], int, int, int, int); 
};

/**
* typedef struct jir jir_r - Struct op 
* @jir: The format.
* @ji_r: The function associated. 
*/

typedef struct jir jir_r;
int _printf(const char *format, ...);
int handle_print(const char *jir, int *k,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** ALL FUNCTIONS ******************/

/* Function which prints chars, strings and percent*/ 
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size); 

int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size); 

int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Functions to print numbers, binary, flags, width*/
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size); 

int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size); 

int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size); 

int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size); 

int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size); 

int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print unprintable characters */
int print_unprintable(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Function to print memory address */
int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size);

/*Functions for other specifiers */
int get_flags(const char *format, int *k);
int get_width(const char *format, int *k, va_list list);
int get_precision(const char *format, int *k, va_list list); 
int get_size(const char *format, int *k);

/*Function to print a reversed string*/
int print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size);

/*Function to print rot 13 string*/
int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* handle write */
int handle_write_char(char g, char buffer[],
int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
int width, int flags, char padd, char extra_c, int padd_start);
int write_unsigned(int is_negative, int ind, char buffer[],
int flags, int width, int precision, int size);

/****************** LIBRE******************/ 
int is_printable(char);
int append_hexa_code(char, char[], int); int is_digit(char);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */

