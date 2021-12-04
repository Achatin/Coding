#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hangman.h"
#include <time.h>

int main() {
   
    srand(time(NULL));

    char secret[50];

    get_secret(secret);
   
    hangman(secret);

    return 0;
}
