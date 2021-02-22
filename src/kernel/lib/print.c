#include <stdarg.h>
#include <port.h>
#include <print.h>

/*
 * puts a char in the debug console
 * supported by bochs
 */
int putchar(char ch) {
	outb(0xEF8, ch);
}

/*
 * prints a series of chars to console
 * doesnt support formatting
 */
int print(char *str) {
	while (*str++)
		putchar(*str);
}

/*
 * formats and prints a string
 * stripped down version of stdio printf
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
 * main formatting procedure
 * only suppostrs basic formats
 * supports %c and %s right now
 */
size_t vnsprintf(char *str, size_t n, const char *fmt, va_list arg) {
	size_t i = 0;

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
