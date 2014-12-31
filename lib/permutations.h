#include <stdlib.h>
#include <stdbool.h>

static void str_concat(char* dst, char* first, char second) {
    int len = strlen(first);
    memcpy(dst, first, strlen(first));
    dst[len] = second;
}

static void str_shift(char* dst, char* str, int i ) {
    bool i_found = false;
    // shift each byte downwards from i
    int len = strlen(str) - 1;
    for(int j = 0; j < len; j++) {
        if(j == i) i_found = true;
        dst[j] = (i_found) ? str[j + 1] : str[j];
    }
}

static void _permutate(
    char* prefix,
    char* str,
    int max_len,
    void(*callback)(char*, void*),
    void* data
)
{
    int len = strlen(str);
    if(len == 0) {
        // permutation found, invoke callback
        callback(prefix, data);
    } else {
        for(int i = 0; i < len; i++) {
            char new_prefix[max_len];
            char new_str[max_len];
            memset(new_prefix, '\0', max_len);
            memset(new_str, '\0', max_len);

            str_concat(new_prefix, prefix, str[i]);
            str_shift(new_str, str, i);
            _permutate(new_prefix, new_str, max_len, callback, data);
        }
    }
}

void permutate(
    char* str,
    void(*callback)(char* permutation, void* data),
    void* data
)
{
    int max_len = strlen(str);
    char prefix[max_len];
    memset(prefix, '\0', max_len);
    _permutate(prefix, str, max_len, callback, data);
}

