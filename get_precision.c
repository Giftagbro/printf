#include "main.h"

/**
 * print_integer - Prints an integer with the given format
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Number of characters printed.
 */
int print_integer(const char *format, int *i, va_list list)
{
	int precision = get_precision(format, i, list);
	int num = va_arg(list, int);
	char buffer[100];
	int len = 0;

	// Convert the integer to a string
	snprintf(buffer, sizeof(buffer), "%d", num);
	len = strlen(buffer);

	// If precision is specified, truncate or pad the string accordingly
	if (precision >= 0) {
		if (len > precision) {
			buffer[precision] = '\0';
			len = precision;
		} else {
			for (int j = 0; j < precision - len; j++) {
				putchar('0');
			}
			len = precision;
		}
	}

	// Print the formatted integer
	for (int j = 0; j < len; j++) {
		putchar(buffer[j]);
	}

	return len;
}
