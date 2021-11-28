#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ballsortpuzzle.h"
#include <time.h>



bool check(const int rows, const int columns, char field[rows][columns]) {

    int kontrola = 0; // kontrolna premenna

    // kontroluje stlpce po riadkoch
    for(int c = 0; c < columns; c++) {
        // vyberiem z posledneho riadku znak a zapisem ho do premennej
        char znak = field[rows-1][c];
        for(int r = 0; r < rows; r++) {
            if(field[r][c] == znak) {
                kontrola++;
            }
            else {
                break;
            }
        }
    }

    // ak su vsetky znaky na spravnej pozicii, tak vrati 1
    if(kontrola == (rows*columns)) {
        return 1;
    }
    else {
        return 0;
    }

}



void generator(const int rows, const int columns, char field[rows][columns]) {

    // aktivujem generator nahodnych cisel
    srand(time(NULL));

    // zapisem vsade medzery
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < columns; c++) {
            field[r][c] = ' ';
        }
    }

    // zistim si kolko mam dostupnych columns
    int vybraneColumns[columns-2];
    int nahodne = 0;
    int pomocna = 0;
    int pocetPrvkov = sizeof(vybraneColumns) / sizeof(vybraneColumns[0]);
    for(int c = 0; c < (columns-2); c++) {
        // vyberiem nahodne columns
        nahodne = rand() % columns;
        // prechadzam vybranymiColumns
        for(int i = 0; i < pocetPrvkov; i++) {
            if(vybraneColumns[i] != nahodne) {
                pomocna++;
            }
            else {   // ak sa rovnake cislo nachadza v poli, vrati sa a vygeneruje nove
                c--;
                break;
            }
        }
        // kontrola, ci sa v celom poli nenachadza dane cislo
        if(pomocna == pocetPrvkov) {
            //zapise
            vybraneColumns[c] = nahodne;
        }
        pomocna = 0;
    }


    // pre @
    int nahodneRows = 0;
    int nahodneColumns = 0;
    for(int i = 0; i < rows; i++) {
        // vygeneruje poziciu
        nahodneRows = rand() % rows;
        nahodneColumns = vybraneColumns[rand() % pocetPrvkov];
        // ak sa na pozicii nachadza medzera, tak zapise @
        if(field[nahodneRows][nahodneColumns] == ' ') {
            field[nahodneRows][nahodneColumns] = '@';
        }
        else { // ak tam nie je medzera, tak 
            i--;   // sa vrati a generuje poziciu znova
        }

    }

    // pre +
    for(int i = 0; i < rows; i++) {
        nahodneRows = rand() % rows;
        nahodneColumns = vybraneColumns[rand() % pocetPrvkov];
        if(field[nahodneRows][nahodneColumns] == ' ') {
            field[nahodneRows][nahodneColumns] = '+';
        }
        else {
            i--;
        }
    }

    // pre ^
    if(columns > 4) {
        for(int i = 0; i < rows; i++) {
            nahodneRows = rand() % rows;
            nahodneColumns = vybraneColumns[rand() % pocetPrvkov]; 
            if(field[nahodneRows][nahodneColumns] == ' ') {
                field[nahodneRows][nahodneColumns] = '^';
            }
            else {
                i--;
            }
        }
    }


    // pre *
    if(columns > 5) {
        for(int i = 0; i < rows; i++) {
            nahodneRows = rand() % rows;
            nahodneColumns = vybraneColumns[rand() % pocetPrvkov];
            if(field[nahodneRows][nahodneColumns] == ' ') {
                field[nahodneRows][nahodneColumns] = '*';
            }
            else {
                i--;
            }    
        }
    }

     // pre #
    if(columns > 6) {
        for(int i = 0; i < rows; i++) {
            nahodneRows = rand() % rows;
            nahodneColumns = vybraneColumns[rand() % pocetPrvkov];
            if(field[nahodneRows][nahodneColumns] == ' ') {
                field[nahodneRows][nahodneColumns] = '#';
            }
            else {
                i--;
            }    
        }
    }

    // pre &
    if(columns > 7) {
        for(int i = 0; i < rows; i++) {
            nahodneRows = rand() % rows;
            nahodneColumns = vybraneColumns[rand() % pocetPrvkov];
            if(field[nahodneRows][nahodneColumns] == ' ') {
                field[nahodneRows][nahodneColumns] = '&';
            }
            else {
                i--;
            }    
        }
    }

    // pre $
    if(columns > 8) {
        for(int i = 0; i < rows; i++) {
            nahodneRows = rand() % rows;
            nahodneColumns = vybraneColumns[rand() % pocetPrvkov];
            if(field[nahodneRows][nahodneColumns] == ' ') {
                field[nahodneRows][nahodneColumns] = '$';
            }
            else {
                i--;
            }    
        }
    }

    // pre %
    if(columns > 9) {
        for(int i = 0; i < rows; i++) {
            nahodneRows = rand() % rows;
            nahodneColumns = vybraneColumns[rand() % pocetPrvkov];
            if(field[nahodneRows][nahodneColumns] == ' ') {
                field[nahodneRows][nahodneColumns] = '%';
            }
            else {
                i--;
            }    
        }
    }

     // pre O
    if(columns > 10) {
        for(int i = 0; i < rows; i++) {
            nahodneRows = rand() % rows;
            nahodneColumns = vybraneColumns[rand() % pocetPrvkov];
            if(field[nahodneRows][nahodneColumns] == ' ') {
                field[nahodneRows][nahodneColumns] = 'O';
            }
            else {
                i--;
            }    
        }
    }

    // pre X
    if(columns > 11) {
        for(int i = 0; i < rows; i++) {
            nahodneRows = rand() % rows;
            nahodneColumns = vybraneColumns[rand() % pocetPrvkov];
            if(field[nahodneRows][nahodneColumns] == ' ') {
                field[nahodneRows][nahodneColumns] = 'X';
            }
            else {
                i--;
            }    
        }
    }


    // ak sa vygeneruje vyherne pole, tak sa zamiesa
    if(check(rows, columns, field) == 1) {
        generator(rows, columns, field);
    }

}


void down_possible(const int rows, const int columns, char field[rows][columns], int x, int y) {

    // najdem x a zapisem
    char xko;
    int invalid = 0; // pomocna premenna na zistenie neplatneho vyberu

    // znaky presuva iba ak je v 2. nadobe miesto
    if(field[0][y-1] == ' ') {

        for(int r = 0; r < rows; r++) {
            if(field[0+r][x-1] != ' ') {
                // zapise x
                xko = field[0+r][x-1];
                // a vymaze zo starej pozicie
                field[0+r][x-1] = ' ';
                break;
            }
            else {
                invalid++;
            }
        }

        // ak je vyber neplatny, vypise
        if(invalid == rows) {
            printf("Empty bottle. Please, choose again.\n");
        }
        else {
            invalid = 0;
            for(int i = 0; i < rows; i++) {
                // polozenie znaku do prazdneho stlpca
                if((field[rows-1][y-1] == ' ') && (i == rows-1)){  // ak je medzera na poslednej pozicii
                    field[rows-1][y-1] = xko;
                    break;
                }
                // polozenie znaku na rovnaky znak
                else if((field[i][y-1] == xko) && (field[i-1][y-1] == ' ')) {
                    field[i-1][y-1] = xko;
                    break;
                }
                else {
                    invalid++;
                }
            }

            if(invalid == rows) {
                printf("Invalid choice. Please, choose again.\n");
                // zapisem znak nas5
                for(int r = 0; r < rows; r++) {
                    // ak sa v stlpci uz nachadzaju znaky
                    if(field[r][x-1] != ' ') {
                        field[r-1][x-1] = xko;
                        break;
                    }
                    // ak tam nie su ziadne znaky
                    else if(field[rows-1][x-1] == ' ') {
                        field[rows-1][x-1] = xko;
                        break;
                    }
                }
            }

        }
    }
    // ak v 2. nadobe nie je miesto, vypise...
    else {
        printf("Bottle full. Please, choose again.\n");
    }

}



void game_field(const int rows, const int columns, char field[rows][columns]) {

        // 2d pole pre moje nadoby
    char nadoba[rows+2][(4*columns)+4];

    // vsetky podstatne medzery, ktore budu vzdy dole na zaciatku
    nadoba[rows][0] = ' ';
    nadoba[rows][1] = ' ';
    nadoba[rows][2] = ' ';
    nadoba[rows][3] = ' ';
    nadoba[rows+1][0] = ' ';
    nadoba[rows+1][1] = ' ';
    nadoba[rows+1][2] = ' ';

    // zapisem ---
    for(int i = 0; i < columns; i++) {
        nadoba[rows][(4+(i*4))] = '`';
        nadoba[rows][(5+(i*4))] = '-';
        nadoba[rows][(6+(i*4))] = '\'';
        nadoba[rows][(7+(i*4))] = ' ';
    }

    // ocisluje collumns
    for(int i = 0; i < columns; i++) {
        nadoba[rows+1][(3+(i*4))] = ' ';
        nadoba[rows+1][(4+(i*4))] = ' ';
        if(i < 9) {    // ocislovanie jednocifernych cisel
            nadoba[rows+1][(5+(i*4))] = (i+1) + '0';  // ocislovanie
        }
        else {
            nadoba[rows+1][(4+(i*4))] = '1';                // aby spravne ocislovalo aj ak je columns
            nadoba[rows+1][(5+(i*4))] = ((i+1) % 10) + '0';   // vacsie ako 9 (dvojciferne)
        }
        nadoba[rows+1][(6+(i*4))] = ' ';
        nadoba[rows+1][(7+(i*4))] = ' ';    // aby som predisiel
        nadoba[rows+1][(8+(i*4))] = ' ';    // otaznicom a inym zvlastnostiam
    }

    // ocislujem rows
    for(int i = 0; i < rows; i++) {
        nadoba[i][0] = ' ';   // medzera na oddelenie
        if(i < 9) {   // ocislovanie jednocifernych riadkov
            nadoba[i][1] = (i+1) + '0';   // cislo
        }
        else {   // ocislovanie dvojcifernych riadkov
            nadoba[i][0] = '1';
            nadoba[i][1] = ((i+1) % 10) + '0';
        }
        nadoba[i][2] = ' ';   // a medzera
        nadoba[i][3] = '|';   // ciarky
    }


    // zapis vsetkych nadob
    int cols = 0;
    while(cols < columns) {
        for(int r = 0; r < rows; r++) {
            for(int m = 4 + (cols*4); m < (7 + (cols*4)); m++) {
                nadoba[r][m] = ' ';
                nadoba[r][(7+(cols*4))] = '|';
                nadoba[r][(8+(cols*4))] = ' ';   // nadoba navyse, aby sa nevypisovale chybne znaky
            }
        }
        cols++;
    }

    // zapis znakov
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < columns; c++) {
            nadoba[r][5+(c*4)] = field[r][c];
        }
    }

        // vypis nadob
    for(int r = 0; r <= (rows+1); r++) {
        for(int j = 0; j <= 4 + (columns*4); j++) {
            printf("%c", nadoba[r][j]);
        }
        printf("\n");
    }

    // iba zariadkujem
    printf("\n");

}

bool check_validity(const int columns, int x, int y) {

    // ak je vyber mimo herneho pola
    if( (x < 1) || ( x > columns)) {
        printf("Position out of play field. Please, choose again.\n");
        return 0;
    }
    else if( ( y < 1) || (y > columns) ) {
        printf("Position out of play field. Please, choose again.\n");
        return 0;
    }
    else {
        return 1;
    }

}

void ball_sort_puzzle() {

    // uvod hraca do hry
    printf("Welcome to the Ball Sort Game!\n");
    printf("Your goal is to match all the characters in the columns.\n");
    printf("\n");

    // hrac si vyberie velkost herneho pola
    int rows = 0;
    int columns = 0;
    printf("Height of the game field: ");
    scanf("%d", &rows);
    printf("Width of the game field: ");
    scanf("%d", &columns);
    printf("\n");

    // vygenerujem herne pole
    char pole[50][50];
    generator(rows, columns, pole);
    game_field(rows, columns, pole);

    // presun znakov - dialog
    while(check(rows, columns, pole) == 0) {
        int x = 0;
        int y = 0;
        printf("Choose character to move: ");
        scanf("%d", &x);
        printf("\n");
        printf("Choose where to move: ");
        scanf("%d", &y);
        printf("\n");

        // funkcia, ktora skontroluje, ci si vybral platne cislo
        if(check_validity(columns, x, y) == 0) {
            game_field(rows, columns, pole);
            continue;     // ak je hodnota x alebo y neplatna, tak sa vrati na zaciatok cyklu
        }

        // presun znakov
        down_possible(rows, columns, pole, x, y);

        // vykresli herne pole
        game_field(rows, columns, pole);
    }
    if(check(rows, columns, pole) == 1) {
        printf("Congratulations! You've WON.\n");
    }

}

