#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_char - Prints a character
 * @args: Pointer to variadic argument list
 */
void print_char(va_list *args)
{
	printf("%c", va_arg(*args, int));
}

/**
 * print_int - Prints an integer
 * @args: Pointer to variadic argument list
 */
void print_int(va_list *args)
{
	printf("%d", va_arg(*args, int));
}

/**
 * print_float - Prints a float
 * @args: Pointer to variadic argument list
 */
void print_float(va_list *args)
{
	printf("%f", va_arg(*args, double));
}

/**
 * print_string - Prints a string
 * @args: Pointer to variadic argument list
 */
void print_string(va_list *args)
{
	char *str;

	str = va_arg(*args, char *);
	if (str == NULL)
		str = "(nil)";

	printf("%s", str);
}

/**
 * print_all - Prints anything
 * @format: List of argument types
 */
void print_all(const char * const format, ...)
{
	unsigned int i, j;
	va_list args;
	char *separator;
	char types[] = "cifs";
		void (*functions[])(va_list *) = {
		print_char, print_int, print_float, print_string
	};

	va_start(args, format);
	i = 0;
	separator = "";

	while (format != NULL && format[i] != '\0')
	{
		j = 0;
		while (types[j] != '\0')
		{
			if (format[i] == types[j])
			{
				printf("%s", separator);
				functions[j](&args);
				separator = ", ";
				break;
			}
			j++;
		}
		i++;
	}

	printf("\n");
	va_end(args);
}
