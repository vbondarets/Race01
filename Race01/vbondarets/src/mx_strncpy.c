#include "header.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    int i = 0;
    while (src[i] && i != len) {
        dst[i] = src[i];
        i++;
    }
    return dst;
}
