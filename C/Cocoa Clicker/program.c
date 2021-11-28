#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curses.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define BLUE 1
#define YELLOW 2
#define MAGENTA 3
#define RED 4
#define CYAN 5
//

void draw_chocolate() {

    char chocolate[8][11] = {
            {"  _____    "},
            {" |_]_]_]_  "},
            {" |_]_]_]_] "},
            {" |_]_]_]_] "},
            {"|`````````|"},
            {"|CHOCOLATE|"},
            {"|    <3   |"},
            {"!_________!"},
    };


    for(int r = 0; r < 8; r++) {
        for(int c = 0; c < 11; c++) {
            move((LINES/2)+r, (COLS/4)-5+c);
            printw("%c", chocolate[r][c]);
            refresh();
        }
    }

}


void draw_border () {

    // vertikalna hranica
    for(int i = 7; i < LINES; i++) {
        move(i, (COLS/2)-1);
        printw("%s", "||");
        refresh();
    }

    // horizontalna hranica
    for(int i = 0; i < COLS; i++) {
        move(7, i);
        printw("%c", '=');
        refresh();
    }

    // oddelenie cocoa displeju
    for(int i = 0; i < (COLS/2)-1; i++) {
        move(10, i);
        printw("%c", '_');
        move(13, i);
        printw("%c", '_');
        refresh();
    }

    mvprintw(LINES-1, COLS-5, "by SN"); refresh();

}


void draw_heading() {

    start_color();
    use_default_colors();
    init_pair(BLUE, COLOR_BLUE, -1);

    attron(COLOR_PAIR(BLUE) | A_BOLD);
    mvprintw(1, (COLS/2)-35, "%s", "   ___                              ___   _   _        _               "); refresh();
    mvprintw(2, (COLS/2)-35, "%s", "  / __|  ___   __   ___   __ _     / __| | | (_)  __  | |__  ___   _ _ "); refresh();
    mvprintw(3, (COLS/2)-35, "%s", " | (__  / _ \\ / _| / _ \\ / _` |   | (__  | | | | / _| | / / / -_) | '_|"); refresh();
    mvprintw(4, (COLS/2)-35, "%s", "  \\___| \\___/ \\__| \\___/ \\__,_|    \\___| |_| |_| \\__| |_\\_\\ \\___| |_| "); refresh();
    attroff(COLOR_PAIR(BLUE) | A_BOLD);
    refresh();

    mvprintw(1, COLS-20, "      __________ "); refresh();
    mvprintw(2, COLS-20, " _   |          |"); refresh();
    mvprintw(3, COLS-20, "|M|  |   MENU   |"); refresh();
    mvprintw(4, COLS-20, "     !__________!"); refresh();
}


void draw_shop() {

    start_color();
    use_default_colors();

    attron(COLOR_PAIR(BLUE) | A_BOLD);
    mvprintw(9, (COLS/1.5), "%s", " _____  _             "); refresh();
    mvprintw(10, (COLS/1.5), "%s", "|   __|| |_  ___  ___ "); refresh();
    mvprintw(11, (COLS/1.5), "%s", "|__   ||   || . || . |"); refresh();
    mvprintw(12, (COLS/1.5), "%s", "|_____||_|_||___||  _|"); refresh();
    mvprintw(13, (COLS/1.5), "%s", "                 |_|  "); refresh();
    attroff(COLOR_PAIR(BLUE) | A_BOLD);

    mvprintw(14, (COLS/2)+3, "Press the corresponding number on your keyboard to buy an upgrade.");
    refresh();
    
    // UPGRADE 1

    mvprintw(15, (COLS/2)+3, "%s", "      _______________________________________________________________");
    mvprintw(16, (COLS/2)+3, "%s", "     |   _____                                                       |");
    mvprintw(17, (COLS/2)+3, "%s", " _   |  |     |       POWER OF THE PURPLE COW        +1  Cocoa/press |");
    mvprintw(18, (COLS/2)+3, "%s", "|1|  |  | °m~ |   Milk of the Purple Cow increases   Price:         |");
    mvprintw(19, (COLS/2)+3, "%s", "     |  !_____!   your Cocoa per click.              10 Cocoa        |");
    mvprintw(20, (COLS/2)+3, "%s", "     !_______________________________________________________________!");
    refresh();

    // DRAW COW ICON
    init_pair(MAGENTA, COLOR_MAGENTA, -1);
    attron(COLOR_PAIR(MAGENTA));

    mvprintw(18, (COLS/2)+12, "%s", " °m~ "); refresh();
    attroff(COLOR_PAIR(MAGENTA));

    // HEADER 

    attron(A_UNDERLINE);
    mvprintw(17, (COLS/2)+25, "POWER OF THE PURPLE COW"); refresh();
    attroff(A_UNDERLINE);

//-------------------------------------------------------------------------------------------------------------------------    

    // UPGRADE 2

    mvprintw(22, (COLS/2)+3, "%s", "      _______________________________________________________________");
    mvprintw(23, (COLS/2)+3, "%s", "     |   _____                                                       |");
    mvprintw(24, (COLS/2)+3, "%s", " _   |  | .o. |           OOMPA LOOMPA               +1  Cocoa/s     |");
    mvprintw(25, (COLS/2)+3, "%s", "|2|  |  |  ^  |   This skillful little guy will      Price:          |");
    mvprintw(26, (COLS/2)+3, "%s", "     |  !_____!   harvest cocoa for you.             20 Cocoa        |");
    mvprintw(27, (COLS/2)+3, "%s", "     !_______________________________________________________________!");
    refresh();

    // DRAW OOMPA LOOMPA ICON
    init_pair(RED, COLOR_RED, -1);
    attron(COLOR_PAIR(RED));

    mvprintw(25, (COLS/2)+12, "  ^  "); refresh();
    attroff(COLOR_PAIR(RED));

    // HEADER

    attron(A_UNDERLINE);
    mvprintw(24, (COLS/2)+29, "OOMPA LOOMPA"); refresh();
    attroff(A_UNDERLINE);

//-------------------------------------------------------------------------------------------------------------------------    
    
    // UPGRADE 3

    mvprintw(29, (COLS/2)+3, "%s", "      _______________________________________________________________");
    mvprintw(30, (COLS/2)+3, "%s", "     |   _____                                                       |");
    mvprintw(31, (COLS/2)+3, "%s", " _   |  |     |      KEY TO THE CHOCOLATE FACTORY    +3  Cocoa/s     |");
    mvprintw(32, (COLS/2)+3, "%s", "|3|  |  | O=m |   This factory was previously owned  Price:          |");
    mvprintw(33, (COLS/2)+3, "%s", "     |  !_____!   by someone called Mr. Wonka.       150 Cocoa       |");
    mvprintw(34, (COLS/2)+3, "%s", "     !_______________________________________________________________!");
    refresh();

    // DRAW KEY ICON
    init_pair(YELLOW, COLOR_YELLOW, -1);
    attron(COLOR_PAIR(YELLOW) | A_BOLD);
    mvprintw(32, (COLS/2)+12, " O=m "); refresh();
    attroff(COLOR_PAIR(YELLOW) | A_BOLD);

    // HEADER
    attron(A_UNDERLINE);
    mvprintw(31, (COLS/2)+24, "KEY TO THE CHOCOLATE FACTORY"); refresh();
    attroff(A_UNDERLINE);

//------------------------------------------------------------------------------------------------------------------------- 

    // UPGRADE 4

    mvprintw(36, (COLS/2)+3, "%s", "      _______________________________________________________________");
    mvprintw(37, (COLS/2)+3, "%s", "     |   _____                                                       |");
    mvprintw(38, (COLS/2)+3, "%s", " _   |  | [oo]|           CHOCOLATE ROBOT            +10  Cocoa/s    |");
    mvprintw(39, (COLS/2)+3, "%s", "|4|  |  | /[]\\|   Thanks to your coding skills,      Price:          |");
    mvprintw(40, (COLS/2)+3, "%s", "     |  !_____!   you can make cocoa-collecting AI.  700 Cocoa       |");
    mvprintw(41, (COLS/2)+3, "%s", "     !_______________________________________________________________!");
    refresh();

    // DRAW ROBOT ICON
    init_pair(CYAN, COLOR_CYAN, -1);
    attron(COLOR_PAIR(CYAN));

    mvprintw(38, (COLS/2)+12, " [");
    attroff(COLOR_PAIR(CYAN));
    attron(COLOR_PAIR(YELLOW) | A_BOLD);
    mvprintw(38, (COLS/2)+14, "oo");
    attroff(COLOR_PAIR(YELLOW) | A_BOLD);
    attron(COLOR_PAIR(CYAN));
    mvprintw(38, (COLS/2)+16, "]");
    mvprintw(39, (COLS/2)+12, " /[]\\");
    attroff(COLOR_PAIR(CYAN));

    // HEADER
    attron(A_UNDERLINE);
    mvprintw(38, (COLS/2)+29, "CHOCOLATE ROBOT");
    attroff(A_UNDERLINE);

}


int centerCocoa(int cocoa) {

    if(cocoa > 99999) {
        return 5;
    }
    else if(cocoa > 9999) {
        return 4;
    }
    else if(cocoa > 999) {
        return 3;
    }
    else if(cocoa > 99) {
        return 2;
    }
    else if(cocoa > 9) {
        return 1;
    }
    else {
        return 0;
    }
}


int centerCost(int cost) {
    if(cost > 99999) {
        return 5;
    }
    else if(cost > 9999) {
        return 4;
    }
    else if(cost > 999) {
        return 3;
    }
    else if(cost > 99) {
        return 2;
    }
    else if(cost > 9) {
        return 1;
    }
    else {
        return 0;
    }
}


void stats(int pressCocoa, int cocoaPerSec) {

    mvprintw(LINES-5, 5, "Cocoa/press: %d", pressCocoa); refresh();
    mvprintw(LINES-5, (COLS/2)-23, "Cocoa/second: %d", cocoaPerSec); refresh();

}


void create_savefile() {

    // create file    // vytvorim savefile
    FILE* checkfile = fopen("savefile.txt", "r");
  
    if(checkfile == NULL) {
        FILE* savefile = fopen("savefile.txt", "w");
        fputs("0 1 0 10 20 150 700", savefile);
        fclose(savefile);
        endwin();
        printf("Savefile was successfully created.\nPlease, start game again.\n");
        exit(EXIT_FAILURE);
    }

    fclose(checkfile);

}


void read_savefile(int readBuffer[]) {

    FILE* savefile = fopen("savefile.txt", "r");

    // citam vsetky hodnoty zo savefile postupne
    for(int i = 0; i < 7; i++) {
    
        fscanf(savefile, "%d", &readBuffer[i]);

    }

    // vypis ceny
    mvprintw(19, (COLS/2)+56, "              "); refresh();  
    mvprintw(19, (COLS/2)+56, "%d", readBuffer[3]); refresh();
    attron(COLOR_PAIR(YELLOW));
    mvprintw(19, (COLS/2)+58+(centerCost(readBuffer[3])), "%s", "Cocoa"); refresh();
    attroff(COLOR_PAIR(YELLOW));

    mvprintw(26, (COLS/2)+56, "              "); refresh();
    mvprintw(26, (COLS/2)+56, "%d", readBuffer[4]); refresh(); 
    attron(COLOR_PAIR(YELLOW));
    mvprintw(26, (COLS/2)+58+(centerCost(readBuffer[4])), "%s", "Cocoa"); refresh();
    attroff(COLOR_PAIR(YELLOW));
 
    mvprintw(33, (COLS/2)+56, "              "); refresh();
    mvprintw(33, (COLS/2)+56, "%d", readBuffer[5]); refresh();
    attron(COLOR_PAIR(YELLOW));
    mvprintw(33, (COLS/2)+58+(centerCost(readBuffer[5])), "%s", "Cocoa"); refresh();
    attroff(COLOR_PAIR(YELLOW));

    mvprintw(40, (COLS/2)+56, "              "); refresh();
    mvprintw(40, (COLS/2)+56, "%d", readBuffer[6]); refresh();
    attron(COLOR_PAIR(YELLOW));
    mvprintw(40, (COLS/2)+58+(centerCost(readBuffer[6])), "%s", "Cocoa"); refresh();
    attroff(COLOR_PAIR(YELLOW));

    // zatvorim subor
    fclose(savefile);
}


void save_game(int cocoa, int pressCocoa, int cocoaPerSec, int cost1, int cost2, int cost3, int cost4) {

    FILE* savefile = fopen("savefile.txt", "w");

    fprintf(savefile, "%d ", cocoa);
    fprintf(savefile, "%d ", pressCocoa);
    fprintf(savefile, "%d ", cocoaPerSec);
    fprintf(savefile, "%d ", cost1);
    fprintf(savefile, "%d ", cost2);
    fprintf(savefile, "%d ", cost3);
    fprintf(savefile, "%d", cost4);

    fclose(savefile);
}


void reset_savefile() {

    FILE* savefile = fopen("savefile.txt", "w");
    if(savefile == NULL) {
        fprintf(stderr, "Error opening file.");
    }

    fputs("0 1 0 10 20 150 700", savefile);
    fclose(savefile);

}


int main() {

    // inicializujem kniznicu curses
    initscr();

    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    curs_set(FALSE);

    nodelay(stdscr, TRUE);

    // 4 HLAVNE PREMENNE 

    // hlavna currency v hre
    int cocoa = 0;
    // cocoa za klik
    int pressCocoa = 1;
    // cocoa za sekundu
    int cocoaPerSec = 0;
    // zapis casu do premennej
    time_t seconds = 0;

    // upgrade specific variables
    int cost1 = 10;   // cena za upgrade 1
    int cost2 = 20;   // cena za upgrade 2
    int cost3 = 150;  // cena za upgrade 3
    int cost4 = 700;  // cena za upgrade 4

    // funkcia vytvori savefile!
    create_savefile();

    redraw:

    // funkcia nakresli nadpis (nazov hry) na vrch obrazovky
    draw_heading();
    // funkcia, ktora nakresli hranice herneho pola a obchodu, menu
    draw_border();
    // funkcia nakresli cokoladu do herneho pola
    draw_chocolate();
    // funkcia vykresli obchod s upgradami
    draw_shop();

    // nacitanie ulozenej hry
    int readBuffer[7];
    read_savefile(readBuffer);
    cocoa = readBuffer[0];
    pressCocoa = readBuffer[1];
    cocoaPerSec = readBuffer[2];
    cost1 = readBuffer[3];
    cost2 = readBuffer[4];
    cost3 = readBuffer[5];
    cost4 = readBuffer[6];

    // vypise Cocoa na vrch do stredu herneho pola
    attron(COLOR_PAIR(YELLOW));
    mvprintw(12, (COLS/4), "%s", "COCOA");
    attroff(COLOR_PAIR(YELLOW));
    mvprintw(12, (COLS/4)-3-(centerCocoa(cocoa)), "%d", cocoa); refresh();

    // funkcia vypise hracove statistiky
    stats(pressCocoa, cocoaPerSec);

    // ak hra bezi, game on = 1
    bool game_on = 1;

    while(game_on == 1) {

        // tip pre noveho hraca
        if(cocoa == 0) {
            mvprintw(18, (COLS/4)-16, "Press SPACEBAR to harvest Cocoa."); refresh();
        }
        else if(cocoa == 1) {
            mvprintw(18, (COLS/4)-16, "                                "); refresh();
        }

        // pripocitavanie Cocoa pri upgrade cocoa/sec
        if(seconds != time(NULL)) {
            cocoa += cocoaPerSec;
            mvprintw(12, (COLS/4)-3-(centerCocoa(cocoa)), "%d", cocoa); refresh();
            seconds = time(NULL);
        }

        // pri kazdom stlaceni medzerniku, tak sa zvysi cocoa 
        int input = getch();
        switch(input) {
            case ' ': {
                cocoa += pressCocoa;
                mvprintw(12, (COLS/4)-3-(centerCocoa(cocoa)), "%d", cocoa);
                refresh();
                break;
            }
            // ak stlacim 1, kupim upgrade 1 - PURPLE COW
            case '1': { 
           
                if(cocoa >= cost1) {
                    // odpocitam CENU
                    cocoa -= cost1;
                    // clear
                    mvprintw(12, (COLS/4)-10, "         "); refresh();
                    // prepise
                    mvprintw(12, (COLS/4)-3-(centerCocoa(cocoa)), "%d", cocoa); refresh();

                    // UPGRADE
                    pressCocoa += 1;
                    // prepisu sa stats
                    stats(pressCocoa, cocoaPerSec);

                    // zapisem NOVU CENU
                    cost1 = cost1*2.7;
                    // clear
                    mvprintw(19, (COLS/2)+56, "              "); refresh();
                    // zapise
                    mvprintw(19, (COLS/2)+56, "%d", cost1); refresh();
                    mvprintw(19, (COLS/2)+58+(centerCost(cost1)), "%s", "Cocoa"); refresh();
                }
                break;

            }
            // ak stlacim 2, kupim upgrade 2 - OOMPAS
            case '2': { 
           
                if(cocoa >= cost2) {
                    // odpocitam CENU
                    cocoa -= cost2;
                    // clear
                    mvprintw(12, (COLS/4)-10, "         "); refresh();
                    // prepise
                    mvprintw(12, (COLS/4)-3-(centerCocoa(cocoa)), "%d", cocoa); refresh();

                    // UPGRADE
                    cocoaPerSec += 1;
                    // prepisu sa stats
                    stats(pressCocoa, cocoaPerSec);

                    // zapisem NOVU CENU
                    cost2 = cost2*1.7;
                    // clear
                    mvprintw(26, (COLS/2)+56, "              "); refresh();
                    // zapise
                    mvprintw(26, (COLS/2)+56, "%d", cost2); refresh();
                    mvprintw(26, (COLS/2)+58+(centerCost(cost2)), "%s", "Cocoa"); refresh();
                }
                break;

            }
            // ak stlacim 3, kupim upgrade 3 - CHOCOLATE FACTORY
            case '3': { 

                if(cocoa >= cost3) {
                    // odpocitam CENU
                    cocoa -= cost3;
                    // clear
                    mvprintw(12, (COLS/4)-10, "         "); refresh();
                    // prepise
                    mvprintw(12, (COLS/4)-3-(centerCocoa(cocoa)), "%d", cocoa); refresh();

                    // UPGRADE
                    cocoaPerSec += 3;
                    // prepisu sa stats
                    stats(pressCocoa, cocoaPerSec);

                    // zapisem NOVU CENU
                    cost3 = cost3*2.2;
                    // clear
                    mvprintw(33, (COLS/2)+56, "              "); refresh();
                    // zapise
                    mvprintw(33, (COLS/2)+56, "%d", cost3); refresh();
                    mvprintw(33, (COLS/2)+58+(centerCost(cost3)), "%s", "Cocoa"); refresh();
                }
                break;

            }
            // ak stlacim 4, kupim upgrade 4 - CHOCOLATE ROBOT
            case '4': { 
           
                if(cocoa >= cost4) {
                    // odpocitam CENU
                    cocoa -= cost4;
                    // clear
                    mvprintw(12, (COLS/4)-10, "         "); refresh();
                    // prepise
                    mvprintw(12, (COLS/4)-3-(centerCocoa(cocoa)), "%d", cocoa); refresh();

                    // UPGRADE
                    cocoaPerSec += 10;
                    // prepisu sa stats
                    stats(pressCocoa, cocoaPerSec);

                    // zapisem NOVU CENU
                    cost4 = cost4*2.7;
                    // clear
                    mvprintw(40, (COLS/2)+56, "              "); refresh();
                    // zapise
                    mvprintw(40, (COLS/2)+56, "%d", cost4); refresh();
                    mvprintw(40, (COLS/2)+58+(centerCost(cost4)), "%s", "Cocoa"); refresh();
                }
                break;
            }
            // MENU
            case 'm': case 'M': {
                WINDOW* menu = newwin(LINES/1.3, COLS/3, LINES/6, COLS/3);

                refresh();
              
                box(menu, 0, 0);

                wattron(menu, COLOR_PAIR(BLUE) | A_BOLD);
                mvwprintw(menu, 2, (COLS/6)-11, " _____                "); wrefresh(menu);
                mvwprintw(menu, 3, (COLS/6)-11, "|     | ___  ___  _ _ "); wrefresh(menu);
                mvwprintw(menu, 4, (COLS/6)-11, "| | | || -_||   || | |"); wrefresh(menu);
                mvwprintw(menu, 5, (COLS/6)-11, "|_|_|_||___||_|_||___|"); wrefresh(menu);
                wattroff(menu, COLOR_PAIR(BLUE) | A_BOLD);

                mvwprintw(menu, 8, (COLS/6)-24, "Press the corresponding key to choose an option."); wrefresh(menu);

                mvwprintw(menu, 10, (COLS/6)-19, "       _________________________ ");
                mvwprintw(menu, 11, (COLS/6)-19, " _    |                         |");
                mvwprintw(menu, 12, (COLS/6)-19, "|C|   |         CONTINUE        |");
                mvwprintw(menu, 13, (COLS/6)-19, "      !_________________________!");
                wrefresh(menu);

                mvwprintw(menu, 15, (COLS/6)-19, "       _________________________ ");
                mvwprintw(menu, 16, (COLS/6)-19, " _    |                         |");
                mvwprintw(menu, 17, (COLS/6)-19, "|R|   |          RESTART        |");
                mvwprintw(menu, 18, (COLS/6)-19, "      !_________________________!");
                wrefresh(menu);

                mvwprintw(menu, 20, (COLS/6)-19, "       _________________________ ");
                mvwprintw(menu, 21, (COLS/6)-19, " _    |                         |");
                mvwprintw(menu, 22, (COLS/6)-19, "|H|   |           HELP          |");
                mvwprintw(menu, 23, (COLS/6)-19, "      !_________________________!");
                wrefresh(menu);

                mvwprintw(menu, 25, (COLS/6)-19, "       _________________________ ");
                mvwprintw(menu, 26, (COLS/6)-19, " _    |                         |");
                mvwprintw(menu, 27, (COLS/6)-19, "|Q|   |       SAVE & QUIT       |");
                mvwprintw(menu, 28, (COLS/6)-19, "      !_________________________!");
                wrefresh(menu);

                delwin(menu);
                break;
            }
            // CONTINUE
            case 'c': case 'C': {
                // ulozim hru
                save_game(cocoa, pressCocoa, cocoaPerSec, cost1, cost2, cost3, cost4);
                // a pokracujem
                clear();
                goto redraw;
                break;
            }
            // RESTART
            case 'r': case 'R': {
                clear();
                // zresetujem premenne ako na zaciatku hry
                cocoa = 0;
                pressCocoa = 1;
                cocoaPerSec = 0;
                cost1 = 10;
                cost2 = 20;
                cost3 = 150;
                cost4 = 700;
                // zresetujem savefile
                reset_savefile();
                goto redraw;
                break;
            }
            // HELP
            case 'h': case 'H': {
                WINDOW* help = newwin(LINES/1.3, COLS/3, LINES/6, COLS/3);

                refresh();
               
                box(help, 0, 0);

                wattron(help, COLOR_PAIR(BLUE) | A_BOLD);
                mvwprintw(help, 3, (COLS/6)-27, " _____                _____         _____  _           ");
                mvwprintw(help, 4, (COLS/6)-27, "|  |  | ___  _ _ _   |_   _| ___   |  _  || | ___  _ _ ");
                mvwprintw(help, 5, (COLS/6)-27, "|     || . || | | |    | |  | . |  |   __|| || .'|| | |");
                mvwprintw(help, 6, (COLS/6)-27, "|__|__||___||_____|    |_|  |___|  |__|   |_||__,||_  |");
                mvwprintw(help, 7, (COLS/6)-27, "                                                  |___|");
                wattroff(help, COLOR_PAIR(BLUE) | A_BOLD);
                wrefresh(help);

                mvwprintw(help, 10, 3, "Harvest Cocoa by pressing SPACEBAR. Buy Upgrades in Shop"); wrefresh(help); 
                mvwprintw(help, 11, 3, "to gain more Cocoa. To Save & Quit game, press Q."); wrefresh(help);

                mvwprintw(help, 13, 3, "If you would like to restart your game, press R. However,"); wrefresh(help);
                mvwprintw(help, 14, 3, "be warned that you will LOSE your progress."); wrefresh(help);

                mvwprintw(help, 17, 3, "Upgrade 1 - This upgrade increases your Cocoa/press,"); wrefresh(help);
                mvwprintw(help, 18, 3, "            which means you will gain more cocoa each"); wrefresh(help);
                mvwprintw(help, 19, 3, "            time you press SPACEBAR."); wrefresh(help);

                mvwprintw(help, 21, 3, "Upgrade 2~4 - These upgrades increase your Cocoa/s,"); wrefresh(help);
                mvwprintw(help, 22, 3, "              which determines how much cocoa you will"); wrefresh(help);
                mvwprintw(help, 23, 3, "              get passively every second."); wrefresh(help);

                mvwprintw(help, 26, (COLS/6)-19, "       _________________________ ");
                mvwprintw(help, 27, (COLS/6)-19, " _    |                         |");
                mvwprintw(help, 28, (COLS/6)-19, "|C|   |         CONTINUE        |");
                mvwprintw(help, 29, (COLS/6)-19, "      !_________________________!");
                wrefresh(help);

                delwin(help);
                break;                
            }
            // SAVE AND QUIT
            case 'q': case 'Q': {
                
                // save game
                save_game(cocoa, pressCocoa, cocoaPerSec, cost1, cost2, cost3, cost4); 

                // quit game
                game_on = 0;
                clear();
                mvprintw((LINES/2)-1, (COLS/2)-10, "Your game was SAVED."); refresh();
                mvprintw((LINES/2)+1, (COLS/2)-12, "Thank you for playing ^^"); refresh();
                sleep(3);
                endwin();
                return EXIT_SUCCESS;
                break;

            }
        }
    }

    // ukoncim curses
    endwin();

    return EXIT_SUCCESS;
    
}
