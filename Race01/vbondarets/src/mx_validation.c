#include "header.h"

void mx_validation(char *argv[], char *operand1, char *operation, char *operand2, char *result) {
    if (mx_strlen(operand1) <= 0) {
        mx_printerr("Invalid operand: ");
        mx_printerr(argv[1]);
        mx_printerr("\n");
        exit(-1);
    }
    if (mx_strlen(operation) != 1) {
        mx_printerr("Invalid operation: ");
        mx_printerr(argv[2]);
        mx_printerr("\n");
        exit(-1);
    }
    if (mx_strlen(operand2) <= 0) {
        mx_printerr("Invalid operand: ");
        mx_printerr(argv[3]);
        mx_printerr("\n");
        exit(-1);
    }
    if (mx_strlen(result) <= 0) {
        mx_printerr("Invalid result: ");
        mx_printerr(argv[4]);
        mx_printerr("\n");
        exit(-1);
    }
    for (int i = 0; i < mx_strlen(operand1); i++) {
        if (i == 0 && operand1[i] == '-') {
            continue;
        }
        if (operand1[i] != '?' && !mx_isdigit(operand1[i])) {
            mx_printerr("Invalid operand: ");
            mx_printerr(argv[1]);
            mx_printerr("\n");
            exit(-1);
        }
    }
    if (*operation != '?' && *operation != '+' && *operation != '-' && *operation != '*' && *operation != '/') {
        mx_printerr("Invalid operation: ");
        mx_printerr(argv[2]);
        mx_printerr("\n");
        exit(-1);
    }
    for (int i = 0; i < mx_strlen(operand2) ; i++) {
        if (i == 0 && operand2[i] == '-') {
            continue;
        }
        if (operand2[i] != '?' && !mx_isdigit(operand2[i])) {
            mx_printerr("Invalid operand: ");
            mx_printerr(argv[3]);
            mx_printerr("\n");
            exit(-1);
        }
    }
    for (int i = 0; i < mx_strlen(result) ; i++) {
        if (i == 0 && result[i] == '-') {
            continue;
        }
        if (result[i] != '?' && !mx_isdigit(result[i])) {
            mx_printerr("Invalid operand: ");
            mx_printerr(argv[4]);
            mx_printerr("\n");
            exit(-1);
        }
    }
}
