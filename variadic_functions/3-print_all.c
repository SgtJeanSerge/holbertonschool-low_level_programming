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
	char *sep = "";
	char *chaine;

	va_start(ap, format);
	while (format != NULL && format[i] != '\0')
	{
		switch (format[i])
		{
			case 'c':
				printf("%s%c", sep, va_arg(ap, int));
				sep = ", ";
				break;
			case 'f':
				printf("%s%f", sep, va_arg(ap, double));
				sep = ", ";
				break;
			case 'i':
				printf("%s%d", sep, va_arg(ap, int));
				sep = ", ";
				break;
			case 's':
				chaine = (va_arg(ap, char *));
				if (chaine == NULL)
				{
					printf("%s(nil)", sep);
					sep = ", ";
					break;
				}
				printf("%s%s", sep, chaine);
				sep = ", ";
				break;
		}
		i++;
	}
	printf("\n");
	va_end(ap);
}
