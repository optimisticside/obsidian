#ifndef PRINT_H
#define PRINT_H

#include <def.h>

int	print(char *str);
int	printf(const char *fmt, ...);
int	sprintf(char *str, const char *fmt, ...);
size_t	vnsprintf(char *str, size_t n, const char *fmt, va_list arg);

#endif /* PRINT_H */
