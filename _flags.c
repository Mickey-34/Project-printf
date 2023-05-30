#include "main.h"
/**
* get_flags - Calculates active flags
* @format: Formatted string in which to print the arguments
* @k: take a parameter.
* Return: Flags
*/
int get_flags(const char *format, int *k)
{
/* ‘ ‘ # 0 + - */
/* 16 8 4 2 1 */
int aloe, dust_k;
int flags = 0;
const char FLAGS_CH[] = {' ‘, '#', '0', ' + ', ' - ', '\0'};
const int FLAGS_ARR[] = {F_SPACE, F_HASH, F_ZERO, F_PLUS,
F_MINUS, 0};

for (dust_k = *k + 1; format[dust_k] != '\0'; dust_k++)
{
	for (aloe = 0; FLAGS_CH[aloe] != '\0'; aloe++)
		if (format[dust_k] == FLAGS_CH[aloe])
{

	flags |= FLAGS_ARR[aloe];

	break;
}
	if (FLAGS_CH[aloe] == 0)

	break;
}
	*k = dust_k - 1;

	return (flags);
}
