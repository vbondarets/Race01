#include "header.h"

int mx_pow(int num, int pow) {
    int temp = num;
    for (int i = 1; i < pow; i++)
        num *= temp;
    return num;
}
