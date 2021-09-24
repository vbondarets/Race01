#include "header.h"

void mx_printint(int n) {
	if (n == 0) {
		mx_printchar('0');
		return;
	}
	if (n < 0) {
		n = -n;
		mx_printchar('-');
	}
	char arr[11];
	short i = 0;
	for (; n != 0; n /= 10, i++)
		arr[i] = (char)(n % 10) + 48;
	for (i--; i >= 0; i--)
		mx_printchar(arr[i]);
}
