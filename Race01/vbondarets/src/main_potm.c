#include "header.h"

int main(int argc, char *argv[]) {
    if (argc != 5) {
        mx_printerr("usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]\n");
        return 1;
    }

    char *operand1 = mx_strtrim(argv[1]);
    char *operation = mx_strtrim(argv[2]);
    char *operand2 = mx_strtrim(argv[3]);
    char *result = mx_strtrim(argv[4]);

    mx_validation(argv, operand1, operation, operand2, result);
    mx_calculation(operand1, operation, operand2, result);
    
    free(operand1); operand1 = NULL;
    free(operation); operation = NULL;
    free(operand2); operand2 = NULL;
    free(result); result = NULL;

    return 0;
}
