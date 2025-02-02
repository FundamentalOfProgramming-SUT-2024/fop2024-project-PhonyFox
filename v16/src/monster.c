#include "rogue.h"

Monster * selectMonster(int level) {
    int monster = rand() % 5;
    switch (monster) {
        case 0:
            return createMonster('0', 5, 1, 1, 1, 1, 0);
            break;
        case 1:
            return createMonster('1', 10, 1, 1, 1, 1, 0);
            break;
        case 2:
            return createMonster('2', 15, 3, 1, 1, 2, 5);
            break;
        case 3:
            return createMonster('3', 20, 5, 1, 1, 3, 0);
            break;
        case 4:
            return createMonster('4', 30, 5, 1, 1, 2, 5);
            break;
    }
}

Monster * createMonster(char symbol, int health, int attack, int speed, int defence, int pathfinding, int steps) {
    Monster * newMonster;
    newMonster = malloc(sizeof(Monster));
    newMonster->symbol = symbol;
    newMonster->health = health;
    newMonster->attack = attack;
    newMonster->speed = speed;
    newMonster->canWalk = defence;
    newMonster->pathfinding = pathfinding;
    newMonster->alive = 1;
    newMonster->steps = steps;
    sprintf(newMonster->string, "%c", symbol);
    newMonster->position = malloc(sizeof(Position));
    return newMonster;
}


void pathfindingRandom(Position * position) {
    int randomPosition = rand() % 4;
    switch (randomPosition) {
        case 0:
            if ((mvinch(position->y - 1, position->x) & A_CHARTEXT) == '.') {
                attron(A_DIM);
                attron(COLOR_PAIR(1));
                mvprintw(position->y, position->x, ".");
                attroff(A_DIM);
                attroff(COLOR_PAIR(1));
                position->y--;
            }
            break;
        case 1:
            if ((mvinch(position->y + 1, position->x) & A_CHARTEXT) == '.') {
                attron(A_DIM);
                attron(COLOR_PAIR(1));
                mvprintw(position->y, position->x, ".");
                attroff(A_DIM);
                attroff(COLOR_PAIR(1));
                position->y++;
            }
            break;
        case 2:
            if ((mvinch(position->y, position->x - 1) & A_CHARTEXT) == '.') {
                attron(A_DIM);
                attron(COLOR_PAIR(1));
                mvprintw(position->y, position->x, ".");
                attroff(A_DIM);
                attroff(COLOR_PAIR(1));
                position->x--;
            }
            break;
        case 3:
            if ((mvinch(position->y, position->x + 1) & A_CHARTEXT) == '.') {
                attron(A_DIM);
                attron(COLOR_PAIR(1));
                mvprintw(position->y, position->x, ".");
                attroff(A_DIM);
                attroff(COLOR_PAIR(1));
                position->x++;
            }
            break;
    }
}

void pathfindingSeek(Position * start, Position * destination) {
    /* step left */
    if ((abs((start->x - 1) - destination->x) < abs(start->x - destination->x)) && ((mvinch(start->y, start->x - 1) & A_CHARTEXT) == '.'))
    {   
        attron(A_DIM);
        attron(COLOR_PAIR(1));
        mvprintw(start->y, start->x, ".");
        attroff(A_DIM);
        attroff(COLOR_PAIR(1));
        start->x = start->x - 1;

    /* step right */
    } else if ((abs((start->x + 1) - destination->x) < abs(start->x - destination->x)) && ((mvinch(start->y, start->x + 1) & A_CHARTEXT) == '.'))
    {
        attron(A_DIM);
        attron(COLOR_PAIR(1));
        mvprintw(start->y, start->x, ".");
        attroff(A_DIM);
        attroff(COLOR_PAIR(1));
        start->x = start->x + 1;
    
    /* step down */
    } else if ((abs((start->y + 1) - destination->y) < abs(start->y - destination->y)) && ((mvinch(start->y + 1, start->x) & A_CHARTEXT) == '.'))
    {
        attron(A_DIM);
        attron(COLOR_PAIR(1));
        mvprintw(start->y, start->x, ".");
        attroff(A_DIM);
        attroff(COLOR_PAIR(1));
        start->y = start->y + 1;

    /* step up */
    } else if ((abs((start->y - 1) - destination->y) < abs(start->y - destination->y)) && ((mvinch(start->y - 1, start->x) & A_CHARTEXT) == '.'))
    {
        attron(A_DIM);
        attron(COLOR_PAIR(1));
        mvprintw(start->y, start->x, ".");
        attroff(A_DIM);
        attroff(COLOR_PAIR(1));
        start->y = start->y - 1;
    } else
    {
        /* do nothing */
    }
}

void drawMonsters(Monster * monster) {
    if (monster->alive) {
        attron(A_BOLD);
        attron(COLOR_PAIR(6));
        mvprintw(monster->position->y, monster->position->x, "%c",monster->symbol);
        attroff(A_BOLD);
        attroff(COLOR_PAIR(6));

    }
}

void killMonster(Monster * monster)
{
    monster->alive = 0;
    clearLine(emptyLine());
    attron(A_DIM);
    attron(COLOR_PAIR(1));
    mvprintw(emptyLine(), 2, "You Killed A %s!", getMonsterName(monster->symbol));
    attroff(A_DIM);
    attroff(COLOR_PAIR(1));
    play_effect_die();
}

char * getMonsterName(char symbol) {
    switch (symbol) {
        case '0':
            return "Deamon";
            break;
        case '1':
            return "Fire Breathing Monster";
            break;
        case '2':
            return "Giant";
            break;
        case '3':
            return "Snake";
            break;
        case '4':
            return "Undeed";
            break;
    }
}