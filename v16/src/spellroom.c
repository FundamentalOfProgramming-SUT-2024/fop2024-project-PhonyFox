#include "rogue.h"
char spellRoomTiles[40][120];
int isInSpellRoom = 0;

void spellRoomMaker() {
    isInSpellRoom = 1;
    play_or_replace_music("horror.mp3");
    for (int i = 2; i < 11; i++) {
        for (int j = 103; j < 112; j++) {
            printWithColor(i, j, '.');
        }
    }
    for (int i = 102; i < 113; i++) {
        printWithColor(1, i, '-');
        printWithColor(11, i, '-');
    }
    for (int i = 1; i < 12; i++) {
        printWithColor(i, 102, '|');
        printWithColor(i, 112, '|');
    }
    int numberOfSpells = rand() % 15 + 15;
    int x;
    int y;
    int whichSpell;
    for (int i = 0; i < numberOfSpells; i++) {
        x = rand() % 9 + 103;
        y = rand() % 9 + 2;
        whichSpell = rand() % 3;
        if (whichSpell == 0) {
            printWithColor(y, x, 'h');
        }
        if (whichSpell == 1) {
            printWithColor(y, x, 'd');
        }
        if (whichSpell == 2) {
            printWithColor(y, x, 'v');
        }
    }
    x = rand() % 9 + 103;
    y = rand() % 9 + 2;
    printWithColor(y, x,'U');

    for (int y = 2; y < 11; y++) {
        for (int x = 103; x < 112; x++) {
        if((mvinch(y, x) & A_CHARTEXT) != '@') spellRoomTiles[y][x] = (mvinch(y, x) & A_CHARTEXT);
        else spellRoomTiles[y][x] = '.';
        }
    }
}