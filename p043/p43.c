#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <stdbool.h>

#define MAX_PERMS 3265921 //MAX+1
#define PERM_LEN  16

/**
 * Concatenates first and second together.
 */
void str_concat(char* dst, char* first, char second) {
    int len = strlen(first);
    memcpy(dst, first, strlen(first));
    dst[len] = second;
}

/**
 * Shifts all bytes from i+1 by one towards i into dst.
 */
void str_shift(char* dst, char* str, int i) {
    bool i_found = false;
    // shift each byte down wards from i
    for(int j = 0; j < strlen(str) - 1; j++) {
        if(j == i) {
            i_found = true;
        }

        if(!i_found) {
            dst[j] = str[j];
        } else {
            dst[j] = str[j + 1];
        }
    }
}

/**
 * Generates all permutations of str into the global permutations array.
 */
void permute(
    char permutations[MAX_PERMS][PERM_LEN],
    int* permCount,
    char* prefix,
    char* str
 )
{
    int len = strlen(str);
    if(len == 0) {
        if(prefix[0] != '0') { // ignore all permutations starting with zero
            memcpy(permutations[*permCount], prefix, 11);
            (*permCount)++;
        }
    } else {
        for(int i = 0; i < len; i++) {
            char new_prefix[11] = { '\0' };
            char new_str[11] = { '\0' };

            str_concat(new_prefix, prefix, str[i]);
            str_shift(new_str, str, i);
            permute(permutations, permCount, new_prefix, new_str);
        }
    }
}

// declare global, otherwise stack gets blown, could also malloc
char permutations[MAX_PERMS][PERM_LEN] = { { 0 } };

int main(int argc, char* argv[]) {

    int permCount = 0;

    char* start = "0123456789";
    char* prefix = "\0\0\0\0\0\0\0\0\0\0";

    // Create all permutations
    permute(permutations, &permCount, prefix, start);

    int divs[] = { 2, 3, 5, 7, 11, 13, 17 };
    unsigned long long sum = 0;

    for(int i = 0; i < permCount; i++) {
        char* p = permutations[i];
        bool is_divisible = true;
        for(int j = 1; j <= 7; j++) {
            char temp[4] = { 0 };
            memcpy(temp, &p[j], 3);

            unsigned int d;
            sscanf(temp, "%u", &d);
            if(d % divs[j - 1] != 0) {
                is_divisible = false;
                break;
            }
        }

        if(is_divisible) {
            unsigned long long d;
            sscanf(p, "%llu", &d);
            sum += d;
        }
    }

    printf("%llu", sum);

    return 0;
}

