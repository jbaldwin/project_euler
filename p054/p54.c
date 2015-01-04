#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int card_value(char card) {
    int value = 0;
    switch(card) {
        case '2': value =  2; break;
        case '3': value =  3; break;
        case '4': value =  4; break;
        case '5': value =  5; break;
        case '6': value =  6; break;
        case '7': value =  7; break;
        case '8': value =  8; break;
        case '9': value =  9; break;
        case 'T': value = 10; break;
        case 'J': value = 11; break;
        case 'Q': value = 12; break;
        case 'K': value = 13; break;
        case 'A': value = 14; break;
    }
    return value;
}

typedef struct result_t {
    int cards[5];
    int len;
} result_t;

result_t result_init() {
    result_t r;
    memset(r.cards, 0, 5 * sizeof(int));
    r.len = 0;
    return r;
}

void result_add(result_t* r, int value) {
    r->cards[r->len] = value;
    r->len++;
}

int result_sort_cb(const void* pa, const void* pb) {
    int a = *(int*)pa;
    int b = *(int*)pb;

    // sort from highest to lowest
    if(a > b) return -1;
    if(a == b) return 0;
    return 1;
}

result_t result_sort(char hand[5][3]) {
    result_t r = result_init();
    for(int i = 0; i < 5; i++) {
        result_add(&r, card_value(hand[i][0]));
    }
    qsort(r.cards, 5, sizeof(int), result_sort_cb);
    return r;
}

result_t high_card(char hand[5][3]) {
    return result_sort(hand);
}

result_t one_pair(char hand[5][3]) {
    result_t r = result_init();

    int pair = 0;
    for(int i =     0; i < 5; i++) {
    for(int j = i + 1; j < 5; j++) {
        if(i == j) continue;
        if(hand[i][0] == hand[j][0]) {
            pair = card_value(hand[i][0]);
            result_add(&r, pair);
            hand[i][0] = 0; // remove these cards before sorting
            hand[j][0] = 0;

            result_t sorted = result_sort(hand);
            for(int k = 0; k < 5; k++) {
                if(sorted.cards[k] != 0) {
                    result_add(&r, sorted.cards[k]);
                }
            }
        }
    }
    }

    return r;
}

result_t two_pair(char hand[5][3]) {
    result_t r = result_init();

    int first = 0;
    int second = 0;

    for(int i =     0; i < 5; i++) {
    for(int j = i + 1; j < 5; j++) {
        if(i == j) continue;
        if(hand[i][0] == hand[j][0]) {
            if(first == 0) {
                first = card_value(hand[i][0]);
            } else {
                second = card_value(hand[i][0]);
                if(first > second) {
                    result_add(&r, first);
                    result_add(&r, second);
                } else {
                    result_add(&r, second);
                    result_add(&r, first);
                }

                for(int k = 0; k < 5; k++) {
                    if(hand[k][0] != r.cards[0] && hand[k][0] != r.cards[1]) {
                        result_add(&r, hand[k][0]); // high card
                        // memory issue if we don't stop
                        break;
                    }
                }
                return r;
            }
        }
    }
    }

    return r;
}

result_t three_of_a_kind(char hand[5][3]) {
    result_t r = result_init();

    for(int i = 0; i < 5; i++) {
        int count = 1;
        for(int j = 0; j < 5; j++) {
            if(i == j) continue;
            if(hand[i][0] == hand[j][0]) {
                count++;
            }
        }
        if(count == 3) {
            result_add(&r, hand[i][0]);
            return r;
        }
    }

    return r;
}

result_t straight(char hand[5][3]) {
    result_t r = result_init();
    result_t sorted = result_sort(hand);

    for(int i = 1; i < 5; i++) {
        if(sorted.cards[i - 1] - 1 != sorted.cards[i]) {
            return r;
        }
    }

    return sorted;
}

result_t pflush(char hand[5][3]) {
    for(int i = 1; i < 5; i++) {
        if(hand[0][1] != hand[i][1]) {
            return result_init();
        }
    }

    result_t sorted = result_sort(hand);
    return sorted;
}

result_t full_house(char hand[5][3]) {
    result_t r = result_init();
    result_t sorted = result_sort(hand);

    if(sorted.cards[0] == sorted.cards[1] && sorted.cards[0] == sorted.cards[2] &&
        sorted.cards[0] != sorted.cards[3] &&
        sorted.cards[3] == sorted.cards[4]) {
        result_add(&r, sorted.cards[0]);
        result_add(&r, sorted.cards[3]);
        return r;
    }

    if(sorted.cards[0] == sorted.cards[1] &&
        sorted.cards[0] != sorted.cards[2] &&
        sorted.cards[2] == sorted.cards[3] && sorted.cards[2] == sorted.cards[4]) {
        result_add(&r, sorted.cards[2]);
        result_add(&r, sorted.cards[0]);
        return r;
    }

    return r;
}

result_t four_of_a_kind(char hand[5][3]) {
    result_t r = result_init();

    for(int i = 0; i < 2; i++) {
        int count = 0;
        for(int j = i + 1; j < 5; j++) {
            if(hand[i][0] == hand[j][0]) count++;
        }
        if(count == 4) {
            printf("found four of a kind\n");
            return result_sort(hand);
        }
    }
    return r;
}

result_t straight_flush(char hand[5][3]) {
    result_t r = result_init();

    for(int i = 1; i < 5; i++) {
        if(hand[0][1] != hand[i][1]) {
            return r;
        }
    }

    result_t sorted = result_sort(hand);
    for(int i = 1; i < 5; i++) {
        if(sorted.cards[i - 1] - 1 != sorted.cards[i]) {
            return r;
        }
    }

    return sorted;
}

bool winner(char h1[5][3], char h2[5][3]) {
    result_t (*funcs[9])(char h[5][3]);
    funcs[0] = straight_flush;
    funcs[1] = four_of_a_kind;
    funcs[2] = full_house;
    funcs[3] = pflush;
    funcs[4] = straight;
    funcs[5] = three_of_a_kind;
    funcs[6] = two_pair;
    funcs[7] = one_pair;
    funcs[8] = high_card;

    for(int i = 0; i < 9; i++) {
        result_t p1 = funcs[i](h1);
        result_t p2 = funcs[i](h2);

        if(p1.len == 0 && p2.len == 0) continue;
        if(p2.len == 0) return true;
        if(p1.len == 0 && p2.len != 0) return false;

        for(int j = 0; j < p1.len; j++) {
            if(p1.cards[j] == p2.cards[j]) continue;
            return p1.cards[j] > p2.cards[j];
        }
    }

    return false;
}

int main(int argc, char* argv[]) {

    int count = 0;

    FILE* hFile = fopen("poker.txt", "r");
    char p1Hand[5][3] = { { 0 } };
    char p2Hand[5][3] = { { 0 } } ;

    char line[64] = { '\0' };

    while(!feof(hFile)) {
        memset(line, '\0', 64);
        if(NULL == fgets(line, 64, hFile)) break;
        int total_scanned = sscanf(
            line,
            "%2c %2c %2c %2c %2c %2c %2c %2c %2c %2c",
            p1Hand[0], p1Hand[1], p1Hand[2], p1Hand[3], p1Hand[4],
            p2Hand[0], p2Hand[1], p2Hand[2], p2Hand[3], p2Hand[4]
        );
        if(total_scanned != 10) continue; // seems to be a bug on the last item it runs twice...!

        if(winner(p1Hand, p2Hand)) {
            count++;
        }
    }

    fclose(hFile);

    printf("%i", count);

    return 0;
}

