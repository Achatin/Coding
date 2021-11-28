#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include "hangman.h"


int get_word(char secret[]){
    // check if file exists first and is readable
    FILE *fp = fopen(WORDLIST_FILENAME, "rb");
    if( fp == NULL ){
        fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
        return 1;
    }

    // get the filesize first
    struct stat st;
    stat(WORDLIST_FILENAME, &st);
    long int size = st.st_size;

    do {
        // generate random number between 0 and filesize
        long int random = (rand() % size) + 1;
        // seek to the random position of file
        fseek(fp, random, SEEK_SET);
        // get next word in row ;)
        int result = fscanf(fp, "%*s %20s", secret);
        if( result != EOF )
            break;
    } while(1);

    fclose(fp);

    return 0;
}

int is_word_guessed(const char secret[], const char letters_guessed[]) {
    int kontrola = 0;

    for(int i = 0; i < strlen(secret); i++) {
        for(int j = 0; j < strlen(letters_guessed); j++) {
            if(secret[i] == letters_guessed[j]) {
                kontrola++;     // zvysuje sa kontrola
                break;
            }
        }
    }

    if(kontrola == strlen(secret)) {     // ak sa kontrola rovna dlzke secretu, tak bolo slovo uhadnute
        return 1;
    }
    else {
        return 0;
    }

}


void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]) {
    char missing = '_';
    char terminator = '\0';

    for(int i = 0; i < strlen(secret); i++) {
        for(int j = 0; j < strlen(letters_guessed); j++) {
            if(secret[i] == letters_guessed[j]) {
                guessed_word[i] = secret[i];
                break;
            }
            else {
                guessed_word[i] = missing;
            }
        }
    }

    if(strlen(letters_guessed) == 0) {
        for(int i = 0; i < strlen(secret); i++) {
            guessed_word[i] = missing;
        }
    }

    guessed_word[strlen(secret)] = terminator;
}


void get_available_letters(const char letters_guessed[], char available_letters[]) {
    char terminator = '\0';
//    int pozicia = 0;
    char abeceda[] = "abcdefghijklmnopqrstuvwxyz";

//    for(char i = 97; i < 122; i++) {
//        abeceda[pozicia] = i;    // zapise abecedu
//        pozicia++;
//    }

//    printf("abeceda... %s\n", abeceda);
//    abeceda[strlen(abeceda)] = terminator;
//    printf("abeceda s terminatorom... %s\n", abeceda);

    for(int i = 0; i < strlen(letters_guessed); i++) {
        for(int j = 0; j < strlen(abeceda); j++) {
            if(abeceda[j] == letters_guessed[i]) {     // porovnavanie znakov
                for(int k = j; k < strlen(abeceda); k++) {          // popremiestnuje vsetky zvysne pismenka
                    abeceda[k] = abeceda[k+1];       // premiestni (vymaze) znak
                }
                break;
            }
        }
    }

    strcpy(available_letters, abeceda);      // prepise upravenu abecedu do available letters

    available_letters[strlen(available_letters)] = terminator;    // prida terminator na koniec stringu

}

void clear(void) {
    while(getchar() != '\n');
}

void hangman(const char secret[]) {
    
    printf("Welcome to the game, Hangman!\n");
    printf("I am thinking of a word that is %ld letters long.\n", strlen(secret));
    printf("-------------\n");

    int pokusy = 8;
    int cyklenie = 0;
    int kontrola = 0;    // pomocna premenna pre kontrolu celeho slova
    int pomoc = 0;

    char medzera = ' ';
    char terminator = '\0';

    char pouzite_pismena[30];
    char dostupne[30];

    char hadane_slovo[30];
    char hadane_slovo_medzery[30];


    while(pokusy > 0) {
       
        pomoc = 0;

        printf("You have %d guesses left.\n", pokusy);
        get_available_letters(pouzite_pismena, dostupne);
        printf("Available letters: %s\n", dostupne);
        printf("Please guess a letter: ");
        scanf("%s", &pouzite_pismena[cyklenie]);
        clear();

        // ak zadas velke
        pouzite_pismena[cyklenie] = tolower(pouzite_pismena[cyklenie]);

        // vlozenie medzier medzi znaky
        get_guessed_word(secret, pouzite_pismena, hadane_slovo);
        for(int i = 0; i < (strlen(hadane_slovo) * 2); i++) {
            if(i == 0) {
                hadane_slovo_medzery[0] = hadane_slovo[0];
            }
            else if((i%2) == 0) {
                hadane_slovo_medzery[i] = hadane_slovo[(i/2)];
            }
            else {
                hadane_slovo_medzery[i] = medzera;
            }
        }
        hadane_slovo_medzery[(strlen(hadane_slovo) * 2) - 1] = terminator;    // terminator na poslednej pozicii
        

               // ak zadas cele slovo
        if((cyklenie + 1) < strlen(pouzite_pismena)) {

        pouzite_pismena[strlen(pouzite_pismena)] = terminator;

            // kontrola, ci si vyhral
            if(is_word_guessed(secret, pouzite_pismena) == 1) {
                printf("Congratulations, you won!\n");     // vyhral si
                break;
            }
            else {
                printf("Sorry, bad guess. The word was %s.\n", secret);     // prehral si
                break;
            }
            
        }


        // ak zadas rovnake
        for(int i = 0; i < strlen(pouzite_pismena); i++) {
            if(pouzite_pismena[cyklenie] == pouzite_pismena[i-1]) {
                printf("Oops! You've already guessed that letter: %s\n", hadane_slovo_medzery);
                printf("-------------\n");
                pomoc++;
                break;
            }
        }
        
        if(pomoc > 0) {
            continue;
        }

        // ak zadas blbost
        int prechadzanie = 0;
        for(char i = 97; i <= 122; i++) {
            if(pouzite_pismena[cyklenie] != i) {
                prechadzanie++;
            }
        }
        if(prechadzanie == 26) {
            printf("Oops! '%c' is not a valid letter: ", pouzite_pismena[cyklenie]);

            printf("%s\n", hadane_slovo_medzery);     // konecne vypiseme slovo s medzerami

            printf("-------------\n");

            continue;
        }
        

        for(int i = 0; i < strlen(secret); i++) {
            kontrola++;

            if(secret[i] == pouzite_pismena[cyklenie]) { // dopisat poziciu
                printf("Good guess: ");
                kontrola = 0;
                break;
            }
            else if (secret[i] != pouzite_pismena[cyklenie] && kontrola == strlen(secret)) {
                printf("Oops! That letter is not in my word: ");
                pokusy--;
                kontrola = 0;
            }
        }

        printf("%s\n", hadane_slovo_medzery);     // konecne vypiseme slovo s medzerami

        printf("-------------\n");

        // neviem, neviem, SKONTROLOVAT TOTO
        pouzite_pismena[strlen(pouzite_pismena)] = terminator;

        // kontrola, ci si vyhral
        if(is_word_guessed(secret, pouzite_pismena) == 1) {
            printf("Congratulations, you won!\n");     // vyhral si
            break;
        }
        else {
            cyklenie++;            // este si nevyhral
        }
    }

    if(pokusy == 0) {
        printf("Sorry, you ran out of guesses. The word was %s.\n", secret);
    }

}
