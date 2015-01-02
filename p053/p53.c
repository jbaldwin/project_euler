#include <stdio.h>

// unsigned appears to be large enough to not overflow
unsigned int triangle[101][101]; // waste space!

int main(int argc, char* argv[]) {

    for(int a = 0; a <= 100; a++) {
        triangle[a][0] = 1;
        triangle[a][a] = 1;
    }

    int c = 0;
    for(int x = 1; x <= 100; x++) {
        for(int y = 1; y <= x - 1; y++) {
            triangle[x][y] = triangle[x - 1][y] + triangle[x - 1][y - 1];
            if(triangle[x][y] > 1000000) {
                c++;
            }
        }
    }

    printf("%i", c);

    return 0;
}

