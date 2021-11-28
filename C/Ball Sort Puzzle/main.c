#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ballsortpuzzle.h"

int main() {

   /* char pole2[20][100];

    game_field(4, 6, pole2);

    char pole[4][6] = {
    {'*', ' ', '^', '@', '+', ' '},
    {'*', ' ', '^', '@', '+', ' '},
    {'*', ' ', '^', '@', '+', ' '},
    {'*', ' ', '^', '@', '+', ' '}
    };

    down_possible(4, 6, pole, 1, 3);

    for(int r = 0; r < 4; r++) {
        for(int c = 0; c < 6; c++) {
            printf("%c", pole[r][c]);
        }
        printf("\n");
    }

    check(4, 6, pole);*/

    ball_sort_puzzle();

}
