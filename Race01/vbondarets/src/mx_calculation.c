#include "header.h"

void mx_calculation(char *operand1, char *operation, char *operand2, char *result) {
    if (*operation == '?') {
        mx_calculation(operand1, "+", operand2, result);
        mx_calculation(operand1, "-", operand2, result);
        mx_calculation(operand1, "*", operand2, result);
        mx_calculation(operand1, "/", operand2, result);
        return;
    }
    int operand1_len = mx_strlen(operand1);
    int operand2_len = mx_strlen(operand2); 
    int res_len = mx_strlen(result);
    bool operand1_neg = false;
    bool operand2_neg = false;
    bool result_neg = false;
    if (operand1[0] == '-') {
        operand1_neg = true;
        operand1++;
        operand1_len--;
    } 
    if (operand2[0] == '-') {
        operand2_neg = true;
        operand2++;
        operand2_len--;
    }
    if (result[0] == '-') {
        result_neg = true;
        result++;
        res_len--;
    }
    int operand1_int = mx_atoi(operand1);
    int operand2_int = mx_atoi(operand2);
    int result_int = mx_atoi(result);
    for (long long i = 0; i < mx_pow(10, operand1_len); i++) {
        if (operand1_int > 0) {
            i = operand1_int;
        }
        char *i_queue = mx_itoa(i);
        int ilen = mx_strlen(i_queue);
        bool i_is_correct = true;
        for (int j = 0; j < operand1_len - ilen; j++) {
            if (mx_isdigit(operand1[j]) && operand1[j] != '0') {
                i_is_correct = false;
                break;
            }
        }
        for (int j = operand1_len - ilen, k = 0; j < operand1_len; j++, k++) {
            if (operand1[j] != '?' && operand1[j] != i_queue[k]) {
                i_is_correct = false;
                break;
            }
        }
        free(i_queue); i_queue = NULL;
        if (!i_is_correct)
            continue;

        for (long long j = 0; j < mx_pow(10, operand2_len); j++) {  
            if (operand2_int > 0) {
                j = operand2_int;
            }
            char *j_queue = mx_itoa(j);
            int j_len = mx_strlen(j_queue);
            bool j_is_correct = true;

            for (int p = 0; p < operand2_len - j_len; p++) {
                if (mx_isdigit(operand2[p]) && operand2[p] != '0') {
                    j_is_correct = false;
                    break;
                }
            }
            for (int p = operand2_len - j_len, j_queue_i = 0; p < operand2_len; p++, j_queue_i++) {
                if (operand2[p] != '?' && operand2[p] != j_queue[j_queue_i]) {
                    j_is_correct = false;
                    break;
                }
            }
            free(j_queue); j_queue = NULL;
            if (!j_is_correct)
                continue;
            
            for (long long k = 0; k < mx_pow(10, res_len); k++) {
                if (result_int > 0) {
                    k = result_int;
                }
                char *k_queue = mx_itoa(k);
                int k_queue_len = mx_strlen(k_queue);
                bool k_is_correct = true;

                for (int n = 0; n < res_len - k_queue_len; n++) {
                    if (mx_isdigit(result[n]) && result[n] != '0') {
                        k_is_correct = false;
                        break;
                    }
                }
                for (int n = res_len - k_queue_len, k_queue_i = 0; n < res_len; n++, k_queue_i++) {
                    if (result[n] != '?' && result[n] != k_queue[k_queue_i]) {
                        k_is_correct = false;
                        break;
                    }
                }
                free(k_queue); k_queue = NULL;
                if (!k_is_correct){
                    continue;
                }
                if (operand1_neg){
                    i *= -1;
                }
                if (operand2_neg){
                    j *= -1;
                }
                if (result_neg){
                    k *= -1;
                }
                if (*operation == '+'){
                    if (i + j == k){
                        mx_printint(i);
                        mx_printstr(" + ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(k);
                        mx_printchar('\n');
                    }
                }
                else if (*operation == '-'){
                        if (i - j == k){
                        mx_printint(i);
                        mx_printstr(" - ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(k);
                        mx_printchar('\n');
                    }
                }
                else if (*operation == '*'){
                        if (i * j == k){
                        mx_printint(i);
                        mx_printstr(" * ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(k);
                        mx_printchar('\n');
                    }
                }
                else if (*operation == '/'){
                    if (j != 0 && i / j == k){
                        mx_printint(i);
                        mx_printstr(" / ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(k);
                        mx_printchar('\n');
                    }
                }
                
                if (operand1_neg){
                    i *= -1;
                }
                if (operand2_neg){
                    j *= -1;
                }
                if (result_neg){
                    k *= -1;
                }
                if (result_int > 0){
                    break;
                }
            }
            if (operand2_int > 0){
                break;
            }
        }
        if (operand1_int > 0){
            break;
        }
    }
    if (operand1_neg){
        operand1--;
    }
    if (operand2_neg){
        operand2--;
    }
    if (result_neg){
        result--;
    }    
}
