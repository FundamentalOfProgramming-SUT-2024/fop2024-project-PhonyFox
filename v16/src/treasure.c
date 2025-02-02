#include "rogue.h"

void makeTreasureRoom(Level * level) {
    for (int i = 0; i < level->numberOfMonsters; i++) {
        level->monstersList[i]->alive = 0;
    }
    play_or_replace_music("heart.mp3");
    for (int i = 40; i < 60; i++) {
        for (int j = 6; j < 18; j++) {
            printWithColor(j, i, '.');
        }
    }
    for (int i = 39; i < 61; i++) {
        printWithColor(5, i, '-');
        printWithColor(18, i, '-');
    }
    for (int i = 6; i < 18; i++) {
        printWithColor(i, 39, '|');
        printWithColor(i, 60, '|');
    }
    for (int i = 39; i < 61; i++) {
        for (int j = 5; j < 19; j++) {
            level->tiles[j][i] = (mvinch(j, i) & A_CHARTEXT);
        }
    }
    level->user->position->x = 59;
    level->user->position->y = 17;
    printChar(level->user->position->y, level->user->position->x);
    move(level->user->position->y, level->user->position->x);
    level->monstersList = malloc(sizeof(Monster *) * 20);
    level->numberOfMonsters = 0;
    for (int x = 18; x > difficulty; x--) {
        level->monstersList[level->numberOfMonsters] = selectMonster(level->level);
        setStartingPositionTreasure(level->monstersList[level->numberOfMonsters]);
        level->numberOfMonsters += 1;
    }
}

void setStartingPositionTreasure(Monster * monster)
{   
    int x = (rand() % 19) + 40;
    int y = (rand() % 11) + 6;
    if ((mvinch(y, x) & A_CHARTEXT) == '.') {
        monster->position->x = x;
        monster->position->y = y;
    }
}