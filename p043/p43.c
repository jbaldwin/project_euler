#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <stdbool.h>

#define MAX_PERMS 1024 * 1024 * 16
char* permutations[MAX_PERMS][32];
int i_perm = 0;

/**
 * Concatenates first and second together.
 */
char* str_concat(char* first, char* second) {
    char* copy = (char*)malloc(11);
    memset(copy, '\0', 11);

    memcpy(copy, first, strlen(first));
    memcpy(&copy[strlen(first)], second, strlen(second));
    return copy;
}

/**
 * Shifts all bytes from i+1 by one towards i
 */
char* str_shift(char* str, int i) {
    char* new_str = (char*)malloc(11);
    memset(new_str, '\0', 11);

    bool i_found = false;
    // shift each byte down wards from i
    for(int j = 0; j < strlen(str) - 1; j++) {
        if(j == i) {
            i_found = true;
        }

        if(!i_found) {
            new_str[j] = str[j];
        } else {
            new_str[j] = str[j + 1];
        }
    }
    return new_str;
}

/**
 * Generates all permutations of str into the global permutations array.
 */
void permute(char* prefix, char* str) {
    int len = strlen(str);
    if(len == 0) {
        if(prefix[0] != '0') {
            memcpy(permutations[i_perm], prefix, 11);
            i_perm++;
        }
    } else {
        for(int i = 0; i < len; i++) {
            char postfix[2];
            postfix[0] = str[i];
            postfix[1] = '\0';
            char* new_prefix = str_concat(prefix, postfix);
            char* new_str = str_shift(str, i);
            permute(new_prefix, new_str);
            free(new_prefix);
            free(new_str);
        }
    }
}

int main(int argc, char* argv[]) {

    for(int i = 0; i < MAX_PERMS; i++) {
        memset(permutations[i], '\0', 32);
    }

    char* start = "0123456789";
    char* prefix = "\0\0\0\0\0\0\0\0\0\0";
    int divs[] = { 2, 3, 5, 7, 11, 13, 17 };
    unsigned long long sum = 0;

    permute(prefix, start);

    for(int i = 0; i < i_perm; i++) {
        char* p = (char*)permutations[i];
        for(int j = 1; j <= 7; j++) {
            char temp[4];
            // sscanf apparently does not like leading zeros (octal?)
            if(p[j] - 48 == 0)
            {
                temp[0] = p[j+1];
                temp[1] = p[j+2];
                temp[2] = '\0';
            }
            else
            {
                temp[0] = p[j];
                temp[1] = p[j+1];
                temp[2] = p[j+2];
                temp[3] = '\0';
            }

            unsigned long long d;
            sscanf(temp, "%llu", &d);
            if(d % divs[j - 1] != 0) {
                goto not_divisible;
            }
        }

        unsigned long long d;
        sscanf(p, "%llu", &d);
        sum += d;

not_divisible:
        // gcc won't compile without an expression after the goto
        sum += 0;
    }

    printf("%llu", sum);

    return 0;
}
