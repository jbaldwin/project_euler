#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool read_word(FILE* hFile, char* word) {
    int word_found = fscanf(hFile, "\"%[ABCDEFGHIJKLMNOPQRSTUVWXYZ]\",", word);
    return (word_found == 1);
}

int main(int argc, char* argv[]) {

    int limit = 19; // no triangles are composed higher than t(19) in words.txt
    int triangles[limit];
    for(int i = 1; i < limit; i++) {
        triangles[i] = (i * (i + 1)) / 2;
    }

    FILE* file = fopen("words.txt", "r");
    char word[128] = { 0 };
    bool more = read_word(file, word);

    int triangle_words = 0;

    while(more) {
        int len = strlen(word);
        int total = 0;

        for(int i = 0; i < len; i++) {
            total += (word[i] - 'A') + 1; // A is 1, Z is 27
        }

        // only checking a few so who cares?!
        for(int i = 0; i < limit; i++) {
            if(triangles[i] == total) {
                triangle_words++;
                break;
            }
        }

        memset(word, '\0', 128);
        more = read_word(file, word);
    }

    fclose(file);

    printf("%i", triangle_words);

    return 0;
}

