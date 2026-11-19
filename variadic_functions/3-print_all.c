#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything, followed by a new line
 * @format: list of types of arguments passed to the function
 *          (c: char, i: integer, f: float, s: char *)
 * @...: the arguments to print
 *
 * Return: nothing
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	int i = 0;
	char lettre;
	char *chaine;
	int num;
	char *concat = "";

	va_start(ap,format);
	while (format[i] != '\0')
	{
		switch (format)
		{
			case 'c':
				concat += va_arg(ap, int));
				continue;
			case 'f':
				concat += va_arg(ap, double);
				continue;
			case 'i':
				concat += va_arg(ap, int);
				continue;
			case 's':
				if (char * == NULL);
					concat += "(nil)";
				

		}
		i++;
	}
}
