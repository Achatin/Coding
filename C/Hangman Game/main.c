#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hangman.h"
#include <time.h>

int main() {
   
    srand(time(NULL));

    char secret[50];

    printf("Secret... %d\n", get_word(secret));

    printf("%d\n", is_word_guessed("weaseled", "abcdefghijklmnopqrstuvwxyz"));
    printf("%d\n", is_word_guessed("secret", ""));
    printf("%d\n", is_word_guessed("main", "amarwertgvbin"));


    char result[30];
    get_guessed_word("container", "", result);
    printf("%s\n", result);

    char dostupne[30];
//    char pouzite_pismena[30];
//    int cyklenie = 0;
//    while(1) {
//        get_available_letters(pouzite_pismena, dostupne);
//        scanf("%s\n", &pouzite_pismena[cyklenie]);
//        printf("Available letters: %s\n", dostupne);
//        cyklenie++;
//    }


    get_available_letters("abcdefghijklmnopqrstu", dostupne);
    printf("%s\n", dostupne);

    hangman(secret);

    return 0;
}
