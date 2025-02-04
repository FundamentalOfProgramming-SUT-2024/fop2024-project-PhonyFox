#include "rogue.h"
char spellRoomTiles[40][150];
int isInSpellRoom = 0;

void spellRoomMaker() {
    isInSpellRoom = 1;
    play_or_replace_music("horror.mp3");
    for (int i = 19; i < 29; i++) {
        for (int j = 103; j < 132; j++) {
            printWithColor(i, j, '.');
        }
    }
    for (int i = 102; i < 133; i++) {
        printWithColor(18, i, '-');
        printWithColor(29, i, '-');
    }
    for (int i = 19; i < 29; i++) {
        printWithColor(i, 102, '|');
        printWithColor(i, 132, '|');
    }
    int numberOfSpells = rand() % 15 + 15;
    int x;
    int y;
    int whichSpell;
    for (int i = 0; i < numberOfSpells; i++) {
        x = rand() % 28 + 103;
        y = rand() % 9 + 19;
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
    x = rand() % 26 + 104;
    y = rand() % 7 + 20;
    printWithColor(y, x,'U');

    for (int y = 18; y < 30; y++) {
        for (int x = 102; x < 132; x++) {
        if((mvinch(y, x) & A_CHARTEXT) != '@') spellRoomTiles[y][x] = (mvinch(y, x) & A_CHARTEXT);
        else spellRoomTiles[y][x] = '.';
        }
    }
}