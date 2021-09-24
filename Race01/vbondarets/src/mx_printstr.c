#include "header.h"

void mx_printstr(const char *s) {
	const char *temp = s;
	int length = 0;
	while(*temp++)
		length++;
	write(1, s, length);
}
