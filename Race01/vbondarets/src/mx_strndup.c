#include "header.h"

char *mx_strndup(const char *s1, int n) {
    char *duplicate = NULL;
    int length = mx_strlen(s1);

    if (n < length){
        length = n;
    }
    duplicate = mx_strnew(length);
    mx_strncpy(duplicate, s1, length);
    return duplicate;
}
