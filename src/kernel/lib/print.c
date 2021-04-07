#include <dev/serial.h>
#include <stdarg.h>
#include <port.h>
#include <print.h>

/*
 * Writes a character to the console.
 */
int putchar(int ch) {
	serial_write(COM1, ch);
}

/*
 * Prints a string to the
 * console.
 */
int print(char *str) {
	while (*str++)
		putchar(*str);
}

/*
 * Formats and prints a string.
 * Stripped down version of stdio's "printf".
 */
int printf(const char *fmt, ...) {
	va_list arg;
	va_start(arg, fmt);

	char buf[NPBUF];
	vnsprintf(buf, sizeof(buf), fmt, arg);

	print(buf);
	va_end(arg);
}

/*
 * Formats a string.
 * Only supports basic formats:
 * %c, %s.
 */
size_t vnsprintf(char *str, size_t n, const char *fmt, va_list arg) {
	size_t i = 0;
	char c;

	while (*fmt++) {
		if (*fmt != '%') {
			if (*fmt == '\0')
				goto out;
			str[i++] = fmt;
		}

		switch (*fmt++) {
		case 'c':
			str[i++] = (char)va_arg(arg, int);
		case 's':
			char *s = (char *)va_arg(arg, const char *);
			while (*s++)
				str[i++] = *s;
		}
	}

out:
	return i;
}
