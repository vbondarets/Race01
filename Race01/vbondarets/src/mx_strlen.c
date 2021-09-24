#include "header.h"

int mx_strlen(const char *s) {
	int i = 0;
	for (; s[i] != '\0'; i++) {}
	return i;
}
