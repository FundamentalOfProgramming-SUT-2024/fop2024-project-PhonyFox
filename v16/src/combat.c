#include "rogue.h"

int hasSavedShot = 0;

void combat(int gun, Level * level) {
    if (gun == 1 || gun == 5) {
        int x, y;
        x = level->user->position->x + 1;
        y = level->user->position->y;
        if ((mvinch(y, x) & A_CHARTEXT) == '0' || (mvinch(y, x) & A_CHARTEXT) == '1' || (mvinch(y, x) & A_CHARTEXT) == '2' || (mvinch(y, x) & A_CHARTEXT) == '3' || (mvinch(y, x) & A_CHARTEXT) == '4') {
            Monster * monster = getMonsterAt(y, x, level->monstersList);
            if (monster) {
                monster->health -= useGun(level) * (hasDamageSpell + 1);
                char * monsterName = getMonsterName(monster->symbol);
                clearLine(emptyLine());
                attron(A_DIM);
                attron(COLOR_PAIR(1));
                mvprintw(emptyLine(), 2, "You Damaged A %s (%d)", monsterName, gun*5);
                attroff(A_DIM);
                attroff(COLOR_PAIR(1));
                play_effect_fight();
                if (monster->health <= 0) {
                    killMonster(monster);
                    attron(A_DIM);
                    attron(COLOR_PAIR(1));
                    mvprintw(monster->position->y, monster->position->x, ".");
                    attroff(A_DIM);
                    attroff(COLOR_PAIR(1));
                }
            }
        }
        x = level->user->position->x - 1;
        y = level->user->position->y;
        if ((mvinch(y, x) & A_CHARTEXT) == '0' || (mvinch(y, x) & A_CHARTEXT) == '1' || (mvinch(y, x) & A_CHARTEXT) == '2' || (mvinch(y, x) & A_CHARTEXT) == '3' || (mvinch(y, x) & A_CHARTEXT) == '4') {
            Monster * monster = getMonsterAt(y, x, level->monstersList);
            if (monster) {
                monster->health -= useGun(level) * (hasDamageSpell + 1);
                char * monsterName = getMonsterName(monster->symbol);
                clearLine(emptyLine());
                attron(A_DIM);
                attron(COLOR_PAIR(1));
                mvprintw(emptyLine(), 2, "You Damaged A %s (%d)", monsterName, gun*5);
                attroff(A_DIM);
                attroff(COLOR_PAIR(1));
                play_effect_fight();
                if (monster->health <= 0) {
                    killMonster(monster);
                    attron(A_DIM);
                    attron(COLOR_PAIR(1));
                    mvprintw(monster->position->y, monster->position->x, ".");
                    attroff(A_DIM);
                    attroff(COLOR_PAIR(1));
                }
            }
        }
        x = level->user->position->x;
        y = level->user->position->y + 1;
        if ((mvinch(y, x) & A_CHARTEXT) == '0' || (mvinch(y, x) & A_CHARTEXT) == '1' || (mvinch(y, x) & A_CHARTEXT) == '2' || (mvinch(y, x) & A_CHARTEXT) == '3' || (mvinch(y, x) & A_CHARTEXT) == '4') {
            Monster * monster = getMonsterAt(y, x, level->monstersList);
            if (monster) {
                monster->health -= useGun(level) * (hasDamageSpell + 1);
                char * monsterName = getMonsterName(monster->symbol);
                clearLine(emptyLine());
                attron(A_DIM);
                attron(COLOR_PAIR(1));
                mvprintw(emptyLine(), 2, "You Damaged A %s (%d)", monsterName, gun*5);
                attroff(A_DIM);
                attroff(COLOR_PAIR(1));
                play_effect_fight();
                if (monster->health <= 0) {
                    killMonster(monster);
                    attron(A_DIM);
                    attron(COLOR_PAIR(1));
                    mvprintw(monster->position->y, monster->position->x, ".");
                    attroff(A_DIM);
                    attroff(COLOR_PAIR(1));
                }
            }
        }
        x = level->user->position->x;
        y = level->user->position->y - 1;
        if ((mvinch(y, x) & A_CHARTEXT) == '0' || (mvinch(y, x) & A_CHARTEXT) == '1' || (mvinch(y, x) & A_CHARTEXT) == '2' || (mvinch(y, x) & A_CHARTEXT) == '3' || (mvinch(y, x) & A_CHARTEXT) == '4') {
            Monster * monster = getMonsterAt(y, x, level->monstersList);
            if (monster) {
                monster->health -= useGun(level) * (hasDamageSpell + 1);
                char * monsterName = getMonsterName(monster->symbol);
                clearLine(emptyLine());
                attron(A_DIM);
                attron(COLOR_PAIR(1));
                mvprintw(emptyLine(), 2, "You Damaged A %s (%d)", monsterName, gun*5);
                attroff(A_DIM);
                attroff(COLOR_PAIR(1));
                play_effect_fight();
                // mvprintw(0, 1, "%d", monster->health);
                if (monster->health <= 0) {
                    killMonster(monster);
                    attron(A_DIM);
                    attron(COLOR_PAIR(1));
                    mvprintw(monster->position->y, monster->position->x, ".");
                    attroff(A_DIM);
                    attroff(COLOR_PAIR(1));
                }
            }
        }
        x = level->user->position->x + 1;
        y = level->user->position->y + 1;
        if ((mvinch(y, x) & A_CHARTEXT) == '0' || (mvinch(y, x) & A_CHARTEXT) == '1' || (mvinch(y, x) & A_CHARTEXT) == '2' || (mvinch(y, x) & A_CHARTEXT) == '3' || (mvinch(y, x) & A_CHARTEXT) == '4') {
            Monster * monster = getMonsterAt(y, x, level->monstersList);
            if (monster) {
                monster->health -= useGun(level) * (hasDamageSpell + 1);
                char * monsterName = getMonsterName(monster->symbol);
                clearLine(emptyLine());
                attron(A_DIM);
                attron(COLOR_PAIR(1));
                mvprintw(emptyLine(), 2, "You Damaged A %s (%d)", monsterName, gun*5);
                attroff(A_DIM);
                attroff(COLOR_PAIR(1));
                play_effect_fight();
                if (monster->health <= 0) {
                    killMonster(monster);
                    attron(A_DIM);
                    attron(COLOR_PAIR(1));
                    mvprintw(monster->position->y, monster->position->x, ".");
                    attroff(A_DIM);
                    attroff(COLOR_PAIR(1));
                }
            }
        }
        x = level->user->position->x + 1;
        y = level->user->position->y - 1;
        if ((mvinch(y, x) & A_CHARTEXT) == '0' || (mvinch(y, x) & A_CHARTEXT) == '1' || (mvinch(y, x) & A_CHARTEXT) == '2' || (mvinch(y, x) & A_CHARTEXT) == '3' || (mvinch(y, x) & A_CHARTEXT) == '4') {
            Monster * monster = getMonsterAt(y, x, level->monstersList);
            if (monster) {
                monster->health -= useGun(level) * (hasDamageSpell + 1);
                char * monsterName = getMonsterName(monster->symbol);
                clearLine(emptyLine());
                attron(A_DIM);
                attron(COLOR_PAIR(1));
                mvprintw(emptyLine(), 2, "You Damaged A %s (%d)", monsterName, gun*5);
                attroff(A_DIM);
                attroff(COLOR_PAIR(1));
                play_effect_fight();
                if (monster->health <= 0) {
                    killMonster(monster);
                    attron(A_DIM);
                    attron(COLOR_PAIR(1));
                    mvprintw(monster->position->y, monster->position->x, ".");
                    attroff(A_DIM);
                    attroff(COLOR_PAIR(1));
                }
            }
        }
        x = level->user->position->x - 1;
        y = level->user->position->y + 1;
        if ((mvinch(y, x) & A_CHARTEXT) == '0' || (mvinch(y, x) & A_CHARTEXT) == '1' || (mvinch(y, x) & A_CHARTEXT) == '2' || (mvinch(y, x) & A_CHARTEXT) == '3' || (mvinch(y, x) & A_CHARTEXT) == '4') {
            Monster * monster = getMonsterAt(y, x, level->monstersList);
            if (monster) {
                monster->health -= useGun(level) * (hasDamageSpell + 1);
                char * monsterName = getMonsterName(monster->symbol);
                clearLine(emptyLine());
                attron(A_DIM);
                attron(COLOR_PAIR(1));
                mvprintw(emptyLine(), 2, "You Damaged A %s (%d)", monsterName, gun*5);
                attroff(A_DIM);
                attroff(COLOR_PAIR(1));
                play_effect_fight();
                if (monster->health <= 0) {
                    killMonster(monster);
                    attron(A_DIM);
                    attron(COLOR_PAIR(1));
                    mvprintw(monster->position->y, monster->position->x, ".");
                    attroff(A_DIM);
                    attroff(COLOR_PAIR(1));
                }
            }
        }
        x = level->user->position->x - 1;
        y = level->user->position->y - 1;
        if ((mvinch(y, x) & A_CHARTEXT) == '0' || (mvinch(y, x) & A_CHARTEXT) == '1' || (mvinch(y, x) & A_CHARTEXT) == '2' || (mvinch(y, x) & A_CHARTEXT) == '3' || (mvinch(y, x) & A_CHARTEXT) == '4') {
            Monster * monster = getMonsterAt(y, x, level->monstersList);
            if (monster) {
                monster->health -= useGun(level) * (hasDamageSpell + 1);
                char * monsterName = getMonsterName(monster->symbol);
                clearLine(emptyLine());
                attron(A_DIM);
                attron(COLOR_PAIR(1));
                mvprintw(emptyLine(), 2, "You Damaged A %s (%d)", monsterName, gun*5);
                attroff(A_DIM);
                attroff(COLOR_PAIR(1));
                play_effect_fight();
                if (monster->health <= 0) {
                    killMonster(monster);
                    attron(A_DIM);
                    attron(COLOR_PAIR(1));
                    mvprintw(monster->position->y, monster->position->x, ".");
                    attroff(A_DIM);
                    attroff(COLOR_PAIR(1));
                }
            }
        }
    }
    else if (gun == 2) {
        useGun(level);
    }
    else if (gun == 3) {
        useGun(level);
    }
    else if (gun == 4) {
        useGun(level);
    }
}

Monster * getMonsterAt(int y, int x, Monster ** monsters)
{   
    for (int i = 0; i < 6; i++)
    {
        if ((y == monsters[i]->position->y) && (x == monsters[i]->position->x)) {
         return monsters[i];
        }
    }
    return NULL;
}

int useGun(Level * level) {
    int gunType = level->user->gunType;
    switch (gunType) {
        case 2:
            if (level->user->dagger > 0) daggerLauncher(level);
            else {
                clearLine(emptyLine());
                attron(A_DIM);
                attron(COLOR_PAIR(1));
                mvprintw(emptyLine(), 2, "You Have No Dagger!");
                attroff(A_DIM);
                attroff(COLOR_PAIR(1));
            }
            break;
        case 3:
            if (level->user->wand > 0) wandLauncher(level);
            else {
                clearLine(emptyLine());
                attron(A_DIM);
                attron(COLOR_PAIR(1));
                mvprintw(emptyLine(), 2, "You Have No Magic Wand!");
                attroff(A_DIM);
                attroff(COLOR_PAIR(1));
            }
            break;
        case 4:
            if (level->user->arrow > 0) arrowLauncher(level);
            else {
                clearLine(emptyLine());
                attron(A_DIM);
                attron(COLOR_PAIR(1));
                mvprintw(emptyLine(), 2, "You Have No Arrow");
                attroff(A_DIM);
                attroff(COLOR_PAIR(1));
            }

            break;
        case 5:
            return 10;
            break;
        default: return 5;
    }
}

void arrowLauncher(Level * level) {
    clearLine(emptyLine());
    attron(A_DIM);
    attron(COLOR_PAIR(1));
    mvprintw(emptyLine(), 2, "Aim!");
    attroff(A_DIM);
    attroff(COLOR_PAIR(1));
    int ch;
    if (!wantedToAutoAim) {
        ch = getch();
    }
    else {
        if (hasSavedShot % 10 == 1) ch = KEY_DOWN; 
        if (hasSavedShot % 10 == 2) ch = KEY_RIGHT; 
        if (hasSavedShot % 10 == 3) ch = KEY_UP; 
        if (hasSavedShot % 10 == 4) ch = KEY_LEFT; 
    }
    keypad(stdscr, TRUE);
    switch (ch) {
        case KEY_DOWN:
            level->user->arrow--;
            hasSavedShot = 41;
            for (int i = 1; i < 5; i++) {
                if ((mvinch(level->user->position->y + i, level->user->position->x) & A_CHARTEXT) == '+' 
                || (mvinch(level->user->position->y + i, level->user->position->x) & A_CHARTEXT) == '-' 
                || (mvinch(level->user->position->y + i, level->user->position->x) & A_CHARTEXT) == '|' 
                || (mvinch(level->user->position->y + i, level->user->position->x) & A_CHARTEXT) == 'O') {
                    attron(A_BOLD);
                    attron(A_UNDERLINE);
                    attron(COLOR_PAIR(2));
                    mvprintw(level->user->position->y + i - 1, level->user->position->x, "`");
                    attroff(A_BOLD);
                    attroff(A_UNDERLINE);
                    attroff(COLOR_PAIR(2));
                    return;
                    break;
                }
                else if ((mvinch(level->user->position->y + i, level->user->position->x) & A_CHARTEXT) == '1' 
                || (mvinch(level->user->position->y + i, level->user->position->x) & A_CHARTEXT) == '2' 
                || (mvinch(level->user->position->y + i, level->user->position->x) & A_CHARTEXT) == '3' 
                || (mvinch(level->user->position->y + i, level->user->position->x) & A_CHARTEXT) == '4' 
                || (mvinch(level->user->position->y + i, level->user->position->x) & A_CHARTEXT) == '0') {
                    Monster * monster = getMonsterAt(level->user->position->y + i, level->user->position->x, level->monstersList);
                    monster->health -= 5  * (hasDamageSpell + 1);
                    char * monsterName = getMonsterName(monster->symbol);
                    clearLine(emptyLine());
                    attron(A_DIM);
                    attron(COLOR_PAIR(1));
                    mvprintw(emptyLine(), 2, "You Damaged A %s (5)", monsterName);
                    attroff(A_DIM);
                    attroff(COLOR_PAIR(1));
                    play_effect_fight();
                    if (monster->health <= 0) {
                        killMonster(monster);
                        attron(A_DIM);
                        attron(COLOR_PAIR(1));
                        mvprintw(monster->position->y, monster->position->x, ".");
                        attroff(A_DIM);
                        attroff(COLOR_PAIR(1));
                    }
                    return;
                    break;
                }
                attron(A_BOLD);
                attron(A_UNDERLINE);
                attron(COLOR_PAIR(2));
                mvprintw(level->user->position->y + i, level->user->position->x, "`");
                attroff(A_BOLD);
                attroff(A_UNDERLINE);
                attroff(COLOR_PAIR(2));
                refresh();
                napms(50);
                printWithColor(level->user->position->y + i, level->user->position->x, '.');
                
            }
            attron(A_BOLD);
            attron(A_UNDERLINE);
            attron(COLOR_PAIR(2));
            mvprintw(level->user->position->y + 4, level->user->position->x, "`");
            attroff(A_BOLD);
            attroff(A_UNDERLINE);
            attroff(COLOR_PAIR(2));
            break;
        case KEY_RIGHT:
            level->user->arrow--;
            hasSavedShot = 42;
            for (int i = 1; i < 5; i++) {
                if ((mvinch(level->user->position->y, level->user->position->x + i) & A_CHARTEXT)  == '+' ||
                 (mvinch(level->user->position->y, level->user->position->x + i) & A_CHARTEXT) == '-' ||
                  (mvinch(level->user->position->y, level->user->position->x + i) & A_CHARTEXT) == '|' ||
                   (mvinch(level->user->position->y, level->user->position->x + i) & A_CHARTEXT) == 'O') {
                    attron(A_BOLD);
                    attron(A_UNDERLINE);
                    attron(COLOR_PAIR(2));
                    mvprintw(level->user->position->y, level->user->position->x + i - 1, "`");
                    attroff(A_BOLD);
                    attroff(A_UNDERLINE);
                    attroff(COLOR_PAIR(2));
                    return;
                    break;
                }
                else if ((mvinch(level->user->position->y, level->user->position->x + i) & A_CHARTEXT) == '1' 
                || (mvinch(level->user->position->y, level->user->position->x + i) & A_CHARTEXT) == '2' 
                || (mvinch(level->user->position->y, level->user->position->x + i) & A_CHARTEXT) == '3' 
                || (mvinch(level->user->position->y, level->user->position->x + i) & A_CHARTEXT) == '4' 
                || (mvinch(level->user->position->y, level->user->position->x + i) & A_CHARTEXT) == '0') {
                    Monster * monster = getMonsterAt(level->user->position->y, level->user->position->x + i, level->monstersList);
                    monster->health -= 5  * (hasDamageSpell + 1);
                    char * monsterName = getMonsterName(monster->symbol);
                    clearLine(emptyLine());
                    attron(A_DIM);
                    attron(COLOR_PAIR(1));
                    mvprintw(emptyLine(), 2, "You Damaged A %s (5)", monsterName);
                    attroff(A_DIM);
                    attroff(COLOR_PAIR(1));
                    play_effect_fight();
                    if (monster->health <= 0) {
                        killMonster(monster);
                        attron(A_DIM);
                        attron(COLOR_PAIR(1));
                        mvprintw(monster->position->y, monster->position->x, ".");
                        attroff(A_DIM);
                        attroff(COLOR_PAIR(1));
                    }
                    return;
                    break;
                }
                attron(A_BOLD);
                attron(A_UNDERLINE);
                attron(COLOR_PAIR(2));
                mvprintw(level->user->position->y, level->user->position->x + i, "`");
                attroff(A_BOLD);
                attroff(A_UNDERLINE);
                attroff(COLOR_PAIR(2));
                refresh();
                napms(50);
                printWithColor(level->user->position->y, level->user->position->x + i, '.');
            }
            attron(A_BOLD);
            attron(A_UNDERLINE);
            attron(COLOR_PAIR(2));
            mvprintw(level->user->position->y, level->user->position->x + 4, "`");
            attroff(A_BOLD);
            attroff(A_UNDERLINE);
            attroff(COLOR_PAIR(2));
            break;
        case KEY_UP:
            level->user->arrow--;
            hasSavedShot = 43;
            for (int i = 1; i < 5; i++) {
                if ((mvinch(level->user->position->y - i, level->user->position->x) & A_CHARTEXT) == '+' 
                || (mvinch(level->user->position->y - i, level->user->position->x) & A_CHARTEXT) == '-' 
                || (mvinch(level->user->position->y - i, level->user->position->x) & A_CHARTEXT) == '|' 
                || (mvinch(level->user->position->y - i, level->user->position->x) & A_CHARTEXT) == 'O') {
                    attron(A_BOLD);
                    attron(A_UNDERLINE);
                    attron(COLOR_PAIR(2));
                    mvprintw(level->user->position->y - i + 1, level->user->position->x, "`");
                    attroff(A_BOLD);
                    attroff(A_UNDERLINE);
                    attroff(COLOR_PAIR(2));
                    return;
                    break;
                }
                else if ((mvinch(level->user->position->y - i, level->user->position->x) & A_CHARTEXT) == '1' 
                || (mvinch(level->user->position->y - i, level->user->position->x) & A_CHARTEXT) == '2' 
                || (mvinch(level->user->position->y - i, level->user->position->x) & A_CHARTEXT) == '3' 
                || (mvinch(level->user->position->y - i, level->user->position->x) & A_CHARTEXT) == '4' 
                || (mvinch(level->user->position->y - i, level->user->position->x) & A_CHARTEXT) == '0') {
                    Monster * monster = getMonsterAt(level->user->position->y - i, level->user->position->x, level->monstersList);
                    char * monsterName = getMonsterName(monster->symbol);
                    clearLine(emptyLine());
                    attron(A_DIM);
                    attron(COLOR_PAIR(1));
                    mvprintw(emptyLine(), 2, "You Damaged A %s (5)", monsterName);
                    attroff(A_DIM);
                    attroff(COLOR_PAIR(1));
                    play_effect_fight();
                    monster->health -= 5 * (hasDamageSpell + 1);
                    if (monster->health <= 0) {
                        killMonster(monster);
                        attron(A_DIM);
                        attron(COLOR_PAIR(1));
                        mvprintw(monster->position->y, monster->position->x, ".");
                        attroff(A_DIM);
                        attroff(COLOR_PAIR(1));
                    }
                    return;
                    break;
                }
                attron(A_BOLD);
                attron(A_UNDERLINE);
                attron(COLOR_PAIR(2));
                mvprintw(level->user->position->y - i, level->user->position->x, "`");
                attroff(A_BOLD);
                attroff(A_UNDERLINE);
                attroff(COLOR_PAIR(2));
                refresh();
                napms(50);
                printWithColor(level->user->position->y - i, level->user->position->x, '.');
            }
            attron(A_BOLD);
            attron(A_UNDERLINE);
            attron(COLOR_PAIR(2));
            mvprintw(level->user->position->y - 4, level->user->position->x, "`");
            attroff(A_BOLD);
            attroff(A_UNDERLINE);
            attroff(COLOR_PAIR(2));
            break;
        case KEY_LEFT:
            level->user->arrow--;
            hasSavedShot = 44;
            for (int i = 1; i < 5; i++) {
                if ((mvinch(level->user->position->y, level->user->position->x - i) & A_CHARTEXT) == '+' 
                || (mvinch(level->user->position->y, level->user->position->x - i) & A_CHARTEXT) == '-' 
                || (mvinch(level->user->position->y, level->user->position->x - i) & A_CHARTEXT) == '|' 
                || (mvinch(level->user->position->y, level->user->position->x - i) & A_CHARTEXT) == 'O') {
                    attron(A_BOLD);
                    attron(A_UNDERLINE);
                    attron(COLOR_PAIR(2));
                    mvprintw(level->user->position->y, level->user->position->x - i + 1, "`");
                    attroff(A_BOLD);
                    attroff(A_UNDERLINE);
                    attroff(COLOR_PAIR(2));
                    return;
                    break;
                }
                else if ((mvinch(level->user->position->y, level->user->position->x - i) & A_CHARTEXT) == '1' 
                || (mvinch(level->user->position->y, level->user->position->x - i) & A_CHARTEXT) == '2' 
                || (mvinch(level->user->position->y, level->user->position->x - i) & A_CHARTEXT) == '3' 
                || (mvinch(level->user->position->y, level->user->position->x - i) & A_CHARTEXT) == '4' 
                || (mvinch(level->user->position->y, level->user->position->x - i) & A_CHARTEXT) == '0') {
                    Monster * monster = getMonsterAt(level->user->position->y, level->user->position->x - i, level->monstersList);
                    monster->health -= 5 * (hasDamageSpell + 1);
                    char * monsterName = getMonsterName(monster->symbol);
                    clearLine(emptyLine());
                    attron(A_DIM);
                    attron(COLOR_PAIR(1));
                    mvprintw(emptyLine(), 2, "You Damaged A %s (5)", monsterName);
                    attroff(A_DIM);
                    attroff(COLOR_PAIR(1));
                    play_effect_fight();
                    if (monster->health <= 0) {
                        killMonster(monster);
                        attron(A_DIM);
                        attron(COLOR_PAIR(1));
                        mvprintw(monster->position->y, monster->position->x, ".");
                        attroff(A_DIM);
                        attroff(COLOR_PAIR(1));
                    }
                    return;
                    break;
                }
                attron(A_BOLD);
                attron(A_UNDERLINE);
                attron(COLOR_PAIR(2));
                mvprintw(level->user->position->y, level->user->position->x - i, "`");
                attroff(A_BOLD);
                attroff(A_UNDERLINE);
                attroff(COLOR_PAIR(2));
                refresh();
                napms(50);
                printWithColor(level->user->position->y, level->user->position->x - i, '.');
            }
            attron(A_BOLD);
            attron(A_UNDERLINE);
            attron(COLOR_PAIR(2));
            mvprintw(level->user->position->y, level->user->position->x - 4, "`");
            attroff(A_BOLD);
            attroff(A_UNDERLINE);
            attroff(COLOR_PAIR(2));
            break;
    }
}

void wandLauncher(Level * level) {
    clearLine(emptyLine());
    attron(A_DIM);
    attron(COLOR_PAIR(1));
    mvprintw(emptyLine(), 2, "Aim!");
    attroff(A_DIM);
    attroff(COLOR_PAIR(1));
    int ch;
    if (!wantedToAutoAim) {
        ch = getch();
    }
    else {
        if (hasSavedShot % 10 == 1) ch = KEY_DOWN; 
        if (hasSavedShot % 10 == 2) ch = KEY_RIGHT; 
        if (hasSavedShot % 10 == 3) ch = KEY_UP; 
        if (hasSavedShot % 10 == 4) ch = KEY_LEFT; 
    }
    keypad(stdscr, TRUE);
    switch (ch) {
        case KEY_DOWN:
            level->user->wand--;
            hasSavedShot = 31;
            for (int i = 1; i < 10; i++) {
                if ((mvinch(level->user->position->y + i, level->user->position->x) & A_CHARTEXT) == '+' 
                || (mvinch(level->user->position->y + i, level->user->position->x) & A_CHARTEXT) == '-' 
                || (mvinch(level->user->position->y + i, level->user->position->x) & A_CHARTEXT) == '|' 
                || (mvinch(level->user->position->y + i, level->user->position->x) & A_CHARTEXT) == 'O') {
                    attron(A_BOLD);
                    attron(A_UNDERLINE);
                    attron(COLOR_PAIR(2));
                    mvprintw(level->user->position->y + i - 1, level->user->position->x, ",");
                    attroff(A_BOLD);
                    attroff(A_UNDERLINE);
                    attroff(COLOR_PAIR(2));
                    return;
                    break;
                }
                else if ((mvinch(level->user->position->y + i, level->user->position->x) & A_CHARTEXT) == '1' 
                || (mvinch(level->user->position->y + i, level->user->position->x) & A_CHARTEXT)== '2' 
                || (mvinch(level->user->position->y + i, level->user->position->x) & A_CHARTEXT) == '3' 
                || (mvinch(level->user->position->y + i, level->user->position->x) & A_CHARTEXT) == '4' 
                || (mvinch(level->user->position->y + i, level->user->position->x) & A_CHARTEXT) == '0') {
                    Monster * monster = getMonsterAt(level->user->position->y + i, level->user->position->x, level->monstersList);
                    monster->canWalk = 0;
                    char * monsterName = getMonsterName(monster->symbol);
                    clearLine(emptyLine());
                    attron(A_DIM);
                    attron(COLOR_PAIR(1));
                    mvprintw(emptyLine(), 2, "%s won't walk anymore!", monsterName);
                    attroff(A_DIM);
                    attroff(COLOR_PAIR(1));
                    play_effect_fight();
                    return;
                    break;
                }
                attron(A_BOLD);
                attron(A_UNDERLINE);
                attron(COLOR_PAIR(2));
                mvprintw(level->user->position->y + i, level->user->position->x, ",");
                attroff(A_BOLD);
                attroff(A_UNDERLINE);
                attroff(COLOR_PAIR(2));
                refresh();
                napms(50);
                printWithColor(level->user->position->y + i, level->user->position->x, '.');
            }
            attron(A_BOLD);
            attron(A_UNDERLINE);
            attron(COLOR_PAIR(2));
            mvprintw(level->user->position->y + 9, level->user->position->x, ",");
            attroff(A_BOLD);
            attroff(A_UNDERLINE);
            attroff(COLOR_PAIR(2));
            break;
        case KEY_RIGHT:
            level->user->wand--;
            hasSavedShot = 32;
            for (int i = 1; i < 10; i++) {
                if ((mvinch(level->user->position->y, level->user->position->x + i) & A_CHARTEXT) == '+' 
                || (mvinch(level->user->position->y, level->user->position->x + i) & A_CHARTEXT) == '-' 
                || (mvinch(level->user->position->y, level->user->position->x + i) & A_CHARTEXT) == '|' 
                || (mvinch(level->user->position->y, level->user->position->x + i) & A_CHARTEXT) == 'O') {
                    attron(A_BOLD);
                    attron(A_UNDERLINE);
                    attron(COLOR_PAIR(2));
                    mvprintw(level->user->position->y, level->user->position->x + i - 1, ",");
                    attroff(A_BOLD);
                    attroff(A_UNDERLINE);
                    attroff(COLOR_PAIR(2));
                    return;
                    break;
                }
                else if ((mvinch(level->user->position->y, level->user->position->x + i) & A_CHARTEXT) == '1' 
                || (mvinch(level->user->position->y, level->user->position->x + i) & A_CHARTEXT) == '2' 
                || (mvinch(level->user->position->y, level->user->position->x + i) & A_CHARTEXT) == '3' 
                || (mvinch(level->user->position->y, level->user->position->x + i) & A_CHARTEXT) == '4' 
                || (mvinch(level->user->position->y, level->user->position->x + i) & A_CHARTEXT) == '0') {
                    Monster * monster = getMonsterAt(level->user->position->y, level->user->position->x + i, level->monstersList);
                    monster->canWalk = 0;
                    char * monsterName = getMonsterName(monster->symbol);
                    clearLine(emptyLine());
                    attron(A_DIM);
                    attron(COLOR_PAIR(1));
                    mvprintw(emptyLine(), 2, "%s won't walk anymore!", monsterName);
                    attroff(A_DIM);
                    attroff(COLOR_PAIR(1));
                    play_effect_fight();
                    return;
                    break;
                }
                attron(A_BOLD);
                attron(A_UNDERLINE);
                attron(COLOR_PAIR(2));
                mvprintw(level->user->position->y, level->user->position->x + i, ",");
                attroff(A_BOLD);
                attroff(A_UNDERLINE);
                attroff(COLOR_PAIR(2));
                refresh();
                napms(50);
                printWithColor(level->user->position->y, level->user->position->x + i, '.');
            }
            attron(A_BOLD);
            attron(A_UNDERLINE);
            attron(COLOR_PAIR(2));
            mvprintw(level->user->position->y, level->user->position->x + 9, ",");
            attroff(A_BOLD);
            attroff(A_UNDERLINE);
            attroff(COLOR_PAIR(2));
            break;
        case KEY_UP:
            level->user->wand--;
            hasSavedShot = 33;
            for (int i = 1; i < 10; i++) {
                if ((mvinch(level->user->position->y - i, level->user->position->x) & A_CHARTEXT) == '+' 
                || (mvinch(level->user->position->y - i, level->user->position->x) & A_CHARTEXT) == '-' 
                || (mvinch(level->user->position->y - i, level->user->position->x) & A_CHARTEXT) == '|' 
                || (mvinch(level->user->position->y - i, level->user->position->x) & A_CHARTEXT) == 'O') {
                    attron(A_BOLD);
                    attron(A_UNDERLINE);
                    attron(COLOR_PAIR(2));
                    mvprintw(level->user->position->y - i + 1, level->user->position->x, ",");
                    attroff(A_BOLD);
                    attroff(A_UNDERLINE);
                    attroff(COLOR_PAIR(2));
                    return;
                    break;
                }
                else if ((mvinch(level->user->position->y - i, level->user->position->x) & A_CHARTEXT) == '1' 
                || (mvinch(level->user->position->y - i, level->user->position->x) & A_CHARTEXT) == '2' 
                || (mvinch(level->user->position->y - i, level->user->position->x) & A_CHARTEXT) == '3' 
                || (mvinch(level->user->position->y - i, level->user->position->x) & A_CHARTEXT) == '4' 
                || (mvinch(level->user->position->y - i, level->user->position->x) & A_CHARTEXT) == '0') {
                    Monster * monster = getMonsterAt(level->user->position->y - i, level->user->position->x, level->monstersList);
                    monster->canWalk = 0;
                    char * monsterName = getMonsterName(monster->symbol);
                    clearLine(emptyLine());
                    attron(A_DIM);
                    attron(COLOR_PAIR(1));
                    mvprintw(emptyLine(), 2, "%s won't walk anymore!", monsterName);
                    attroff(A_DIM);
                    attroff(COLOR_PAIR(1));
                    play_effect_fight();
                    return;
                    break;
                }
                attron(A_BOLD);
                attron(A_UNDERLINE);
                attron(COLOR_PAIR(2));
                mvprintw(level->user->position->y - i, level->user->position->x, ",");
                attroff(A_BOLD);
                attroff(A_UNDERLINE);
                attroff(COLOR_PAIR(2));
                refresh();
                napms(50);
                printWithColor(level->user->position->y - i, level->user->position->x, '.');
            }
            attron(A_BOLD);
            attron(A_UNDERLINE);
            attron(COLOR_PAIR(2));
            mvprintw(level->user->position->y - 9, level->user->position->x, ",");
            attroff(A_BOLD);
            attroff(A_UNDERLINE);
            attroff(COLOR_PAIR(2));
            break;
        case KEY_LEFT:
            level->user->wand--;
            hasSavedShot = 34;
            for (int i = 1; i < 10; i++) {
                if ((mvinch(level->user->position->y, level->user->position->x - i) & A_CHARTEXT) == '+' 
                || (mvinch(level->user->position->y, level->user->position->x - i) & A_CHARTEXT) == '-' 
                || (mvinch(level->user->position->y, level->user->position->x - i) & A_CHARTEXT) == '|' 
                || (mvinch(level->user->position->y, level->user->position->x - i) & A_CHARTEXT) == 'O') {
                    attron(A_BOLD);
                    attron(A_UNDERLINE);
                    attron(COLOR_PAIR(2));
                    mvprintw(level->user->position->y, level->user->position->x - i + 1, ",");
                    attroff(A_BOLD);
                    attroff(A_UNDERLINE);
                    attroff(COLOR_PAIR(2));
                    return;
                    break;
                }
                else if ((mvinch(level->user->position->y, level->user->position->x - i) & A_CHARTEXT) == '1' 
                || (mvinch(level->user->position->y, level->user->position->x - i) & A_CHARTEXT) == '2' 
                || (mvinch(level->user->position->y, level->user->position->x - i) & A_CHARTEXT) == '3' 
                || (mvinch(level->user->position->y, level->user->position->x - i) & A_CHARTEXT) == '4' 
                || (mvinch(level->user->position->y, level->user->position->x - i) & A_CHARTEXT) == '0') {
                    Monster * monster = getMonsterAt(level->user->position->y, level->user->position->x - i, level->monstersList);
                    monster->canWalk = 0;
                    char * monsterName = getMonsterName(monster->symbol);
                    clearLine(emptyLine());
                    attron(A_DIM);
                    attron(COLOR_PAIR(1));
                    mvprintw(emptyLine(), 2, "%s won't walk anymore!", monsterName);
                    attroff(A_DIM);
                    attroff(COLOR_PAIR(1));
                    play_effect_fight();
                    return;
                    break;
                }
                attron(A_BOLD);
                attron(A_UNDERLINE);
                attron(COLOR_PAIR(2));
                mvprintw(level->user->position->y, level->user->position->x - i, ",");
                attroff(A_BOLD);
                attroff(A_UNDERLINE);
                attroff(COLOR_PAIR(2));
                refresh();
                napms(50);
                printWithColor(level->user->position->y, level->user->position->x - i, '.');
            }
            attron(A_BOLD);
            attron(A_UNDERLINE);
            attron(COLOR_PAIR(2));
            mvprintw(level->user->position->y, level->user->position->x - 9, ",");
            attroff(A_BOLD);
            attroff(A_UNDERLINE);
            attroff(COLOR_PAIR(2));
            break;
    }
}

void daggerLauncher(Level * level) {
    clearLine(emptyLine());
    attron(A_DIM);
    attron(COLOR_PAIR(1));
    mvprintw(emptyLine(), 2, "Aim!");
    attroff(A_DIM);
    attroff(COLOR_PAIR(1));
    int ch;
    if (!wantedToAutoAim) {
        ch = getch();
    }
    else {
        if (hasSavedShot % 10 == 1) ch = KEY_DOWN; 
        if (hasSavedShot % 10 == 2) ch = KEY_RIGHT; 
        if (hasSavedShot % 10 == 3) ch = KEY_UP; 
        if (hasSavedShot % 10 == 4) ch = KEY_LEFT; 
    }
    keypad(stdscr, TRUE);
    switch (ch) {
        case KEY_DOWN:
            level->user->dagger--;
            hasSavedShot = 21;
            for (int i = 1; i < 5; i++) {
                if ((mvinch(level->user->position->y + i, level->user->position->x) & A_CHARTEXT) == '+' 
                || (mvinch(level->user->position->y + i, level->user->position->x) & A_CHARTEXT) == '-' 
                || (mvinch(level->user->position->y + i, level->user->position->x) & A_CHARTEXT) == '|' 
                || (mvinch(level->user->position->y + i, level->user->position->x) & A_CHARTEXT) == 'O') {
                    attron(A_BOLD);
                    attron(A_UNDERLINE);
                    attron(COLOR_PAIR(2));
                    mvprintw(level->user->position->y + i - 1, level->user->position->x, "~");
                    attroff(A_BOLD);
                    attroff(A_UNDERLINE);
                    attroff(COLOR_PAIR(2));
                    return;
                    break;
                }
                else if ((mvinch(level->user->position->y + i, level->user->position->x) & A_CHARTEXT) == '1' 
                || (mvinch(level->user->position->y + i, level->user->position->x) & A_CHARTEXT) == '2' 
                || (mvinch(level->user->position->y + i, level->user->position->x) & A_CHARTEXT) == '3' 
                || (mvinch(level->user->position->y + i, level->user->position->x) & A_CHARTEXT) == '4' 
                || (mvinch(level->user->position->y + i, level->user->position->x) & A_CHARTEXT) == '0') {
                    Monster * monster = getMonsterAt(level->user->position->y + i, level->user->position->x, level->monstersList);
                    monster->health -= 12 * (hasDamageSpell + 1);
                    char * monsterName = getMonsterName(monster->symbol);
                    clearLine(emptyLine());
                    attron(A_DIM);
                    attron(COLOR_PAIR(1));
                    mvprintw(emptyLine(), 2, "You Damaged A %s (12)", monsterName);
                    attroff(A_DIM);
                    attroff(COLOR_PAIR(1));
                    play_effect_fight();
                    if (monster->health <= 0) {
                        killMonster(monster);
                        attron(A_DIM);
                        attron(COLOR_PAIR(1));
                        mvprintw(monster->position->y, monster->position->x, ".");
                        attroff(A_DIM);
                        attroff(COLOR_PAIR(1));
                    }
                    return;
                    break;
                }
                attron(A_BOLD);
                attron(A_UNDERLINE);
                attron(COLOR_PAIR(2));
                mvprintw(level->user->position->y + i, level->user->position->x, "~");
                attroff(A_BOLD);
                attroff(A_UNDERLINE);
                attroff(COLOR_PAIR(2));
                refresh();
                napms(50);
                printWithColor(level->user->position->y + i, level->user->position->x, '.');
            }
            attron(A_BOLD);
            attron(A_UNDERLINE);
            attron(COLOR_PAIR(2));
            mvprintw(level->user->position->y + 4, level->user->position->x, "~");
            attroff(A_BOLD);
            attroff(A_UNDERLINE);
            attroff(COLOR_PAIR(2));
            break;
        case KEY_RIGHT:
            level->user->dagger--;
            hasSavedShot = 22;
            for (int i = 1; i < 5; i++) {
                if ((mvinch(level->user->position->y, level->user->position->x + i) & A_CHARTEXT) == '+' 
                || (mvinch(level->user->position->y, level->user->position->x + i) & A_CHARTEXT) == '-' 
                || (mvinch(level->user->position->y, level->user->position->x + i) & A_CHARTEXT) == '|' 
                || (mvinch(level->user->position->y, level->user->position->x + i) & A_CHARTEXT) == 'O') {
                    attron(A_BOLD);
                    attron(A_UNDERLINE);
                    attron(COLOR_PAIR(2));
                    mvprintw(level->user->position->y, level->user->position->x + i - 1, "~");
                    attroff(A_BOLD);
                    attroff(A_UNDERLINE);
                    attroff(COLOR_PAIR(2));
                    return;
                    break;
                }
                else if ((mvinch(level->user->position->y, level->user->position->x + i) & A_CHARTEXT) == '1' 
                || (mvinch(level->user->position->y, level->user->position->x + i) & A_CHARTEXT) == '2' 
                || (mvinch(level->user->position->y, level->user->position->x + i) & A_CHARTEXT) == '3' 
                || (mvinch(level->user->position->y, level->user->position->x + i) & A_CHARTEXT) == '4' 
                || (mvinch(level->user->position->y, level->user->position->x + i) & A_CHARTEXT) == '0') {
                    Monster * monster = getMonsterAt(level->user->position->y, level->user->position->x + i, level->monstersList);
                    monster->health -= 12 * (hasDamageSpell + 1);
                    char * monsterName = getMonsterName(monster->symbol);
                    clearLine(emptyLine());
                    attron(A_DIM);
                    attron(COLOR_PAIR(1));
                    mvprintw(emptyLine(), 2, "You Damaged A %s (12)", monsterName);
                    attroff(A_DIM);
                    attroff(COLOR_PAIR(1));
                    play_effect_fight();
                    if (monster->health <= 0) {
                        killMonster(monster);
                        attron(A_DIM);
                        attron(COLOR_PAIR(1));
                        mvprintw(monster->position->y, monster->position->x, ".");
                        attroff(A_DIM);
                        attroff(COLOR_PAIR(1));
                    }
                    return;
                    break;
                }
                attron(A_BOLD);
                attron(A_UNDERLINE);
                attron(COLOR_PAIR(2));
                mvprintw(level->user->position->y, level->user->position->x + i, "~");
                attroff(A_BOLD);
                attroff(A_UNDERLINE);
                attroff(COLOR_PAIR(2));
                refresh();
                napms(50);
                printWithColor(level->user->position->y, level->user->position->x + i, '.');
            }
            attron(A_BOLD);
            attron(A_UNDERLINE);
            attron(COLOR_PAIR(2));
            mvprintw(level->user->position->y, level->user->position->x + 4, "~");
            attroff(A_BOLD);
            attroff(A_UNDERLINE);
            attroff(COLOR_PAIR(2));
            break;
        case KEY_UP:
            level->user->dagger--;
            hasSavedShot = 23;
            for (int i = 1; i < 5; i++) {
                if ((mvinch(level->user->position->y - i, level->user->position->x) & A_CHARTEXT) == '+' 
                || (mvinch(level->user->position->y - i, level->user->position->x) & A_CHARTEXT) == '-' 
                || (mvinch(level->user->position->y - i, level->user->position->x) & A_CHARTEXT) == '|' 
                || (mvinch(level->user->position->y - i, level->user->position->x) & A_CHARTEXT) == 'O') {
                    attron(A_BOLD);
                    attron(A_UNDERLINE);
                    attron(COLOR_PAIR(2));
                    mvprintw(level->user->position->y - i + 1, level->user->position->x, "~");
                    attroff(A_BOLD);
                    attroff(A_UNDERLINE);
                    attroff(COLOR_PAIR(2));
                    return;
                    break;
                }
                else if ((mvinch(level->user->position->y - i, level->user->position->x) & A_CHARTEXT) == '1' 
                || (mvinch(level->user->position->y - i, level->user->position->x) & A_CHARTEXT) == '2' 
                || (mvinch(level->user->position->y - i, level->user->position->x) & A_CHARTEXT) == '3' 
                || (mvinch(level->user->position->y - i, level->user->position->x) & A_CHARTEXT) == '4' 
                || (mvinch(level->user->position->y - i, level->user->position->x) & A_CHARTEXT) == '0') {
                    Monster * monster = getMonsterAt(level->user->position->y - i, level->user->position->x, level->monstersList);
                    char * monsterName = getMonsterName(monster->symbol);
                    clearLine(emptyLine());
                    attron(A_DIM);
                    attron(COLOR_PAIR(1));
                    mvprintw(emptyLine(), 2, "You Damaged A %s (12)", monsterName);
                    attroff(A_DIM);
                    attroff(COLOR_PAIR(1));
                    play_effect_fight();
                    monster->health -= 12 * (hasDamageSpell + 1);
                    if (monster->health <= 0) {
                        killMonster(monster);
                        attron(A_DIM);
                        attron(COLOR_PAIR(1));
                        mvprintw(monster->position->y, monster->position->x, ".");
                        attroff(A_DIM);
                        attroff(COLOR_PAIR(1));
                    }
                    return;
                    break;
                }
                attron(A_BOLD);
                attron(A_UNDERLINE);
                attron(COLOR_PAIR(2));
                mvprintw(level->user->position->y - i, level->user->position->x, "~");
                attroff(A_BOLD);
                attroff(A_UNDERLINE);
                attroff(COLOR_PAIR(2));
                refresh();
                napms(50);
                printWithColor(level->user->position->y - i, level->user->position->x, '.');
            }
            attron(A_BOLD);
            attron(A_UNDERLINE);
            attron(COLOR_PAIR(2));
            mvprintw(level->user->position->y - 4, level->user->position->x, "~");
            attroff(A_BOLD);
            attroff(A_UNDERLINE);
            attroff(COLOR_PAIR(2));
            break;
        case KEY_LEFT:
            level->user->dagger--;
            hasSavedShot = 24;
            for (int i = 1; i < 5; i++) {
                if ((mvinch(level->user->position->y, level->user->position->x - i) & A_CHARTEXT) == '+' 
                || (mvinch(level->user->position->y, level->user->position->x - i) & A_CHARTEXT) == '-' 
                || (mvinch(level->user->position->y, level->user->position->x - i) & A_CHARTEXT) == '|' 
                || (mvinch(level->user->position->y, level->user->position->x - i) & A_CHARTEXT) == 'O') {
                    attron(A_BOLD);
                    attron(A_UNDERLINE);
                    attron(COLOR_PAIR(2));
                    mvprintw(level->user->position->y, level->user->position->x - i + 1, "~");
                    attroff(A_BOLD);
                    attroff(A_UNDERLINE);
                    attroff(COLOR_PAIR(2));
                    return;
                    break;
                }
                else if ((mvinch(level->user->position->y, level->user->position->x - i) & A_CHARTEXT) == '1' 
                || (mvinch(level->user->position->y, level->user->position->x - i) & A_CHARTEXT) == '2' 
                || (mvinch(level->user->position->y, level->user->position->x - i) & A_CHARTEXT) == '3' 
                || (mvinch(level->user->position->y, level->user->position->x - i) & A_CHARTEXT) == '4' 
                || (mvinch(level->user->position->y, level->user->position->x - i) & A_CHARTEXT) == '0') {
                    Monster * monster = getMonsterAt(level->user->position->y, level->user->position->x - i, level->monstersList);
                    monster->health -= 12 * (hasDamageSpell + 1);
                    char * monsterName = getMonsterName(monster->symbol);
                    clearLine(emptyLine());
                    attron(A_DIM);
                    attron(COLOR_PAIR(1));
                    mvprintw(emptyLine(), 2, "You Damaged A %s (12)", monsterName);
                    attroff(A_DIM);
                    attroff(COLOR_PAIR(1));
                    play_effect_fight();
                    if (monster->health <= 0) {
                        killMonster(monster);
                        attron(A_DIM);
                        attron(COLOR_PAIR(1));
                        mvprintw(monster->position->y, monster->position->x, ".");
                        attroff(A_DIM);
                        attroff(COLOR_PAIR(1));
                    }
                    return;
                    break;
                }
                attron(A_BOLD);
                attron(A_UNDERLINE);
                attron(COLOR_PAIR(2));
                mvprintw(level->user->position->y, level->user->position->x - i, "~");
                attroff(A_BOLD);
                attroff(A_UNDERLINE);
                attroff(COLOR_PAIR(2));
                refresh();
                napms(50);
                printWithColor(level->user->position->y, level->user->position->x - i, '.');
            }
            attron(A_BOLD);
            attron(A_UNDERLINE);
            attron(COLOR_PAIR(2));
            mvprintw(level->user->position->y, level->user->position->x - 4, "~");
            attroff(A_BOLD);
            attroff(A_UNDERLINE);
            attroff(COLOR_PAIR(2));
            break;
    }
}

void monstersAttack(Level * level) {
        int x, y;
        x = level->user->position->x + 1;
        y = level->user->position->y;
        if ((mvinch(y, x) & A_CHARTEXT) == '0' || (mvinch(y, x) & A_CHARTEXT) == '1' || (mvinch(y, x) & A_CHARTEXT) == '2' || (mvinch(y, x) & A_CHARTEXT) == '3' || (mvinch(y, x) & A_CHARTEXT) == '4') {
            Monster * monster = getMonsterAt(y, x, level->monstersList);
            if (monster) {
                level->user->health -= monster->attack;
                char * monsterName = getMonsterName(monster->symbol);
                clearLine(emptyLine());
                play_effect2();
                attron(A_DIM);
                attron(COLOR_PAIR(1));
                mvprintw(emptyLine(), 2, "A %s Hit You! (%d)", monsterName, monster->attack);
                attroff(A_DIM);
                attroff(COLOR_PAIR(1));
            }
        }
        x = level->user->position->x - 1;
        y = level->user->position->y;
        if ((mvinch(y, x) & A_CHARTEXT) == '0' 
        || (mvinch(y, x) & A_CHARTEXT) == '1' 
        || (mvinch(y, x) & A_CHARTEXT) == '2' 
        || (mvinch(y, x) & A_CHARTEXT) == '3' 
        || (mvinch(y, x) & A_CHARTEXT) == '4') {
            Monster * monster = getMonsterAt(y, x, level->monstersList);
            if (monster) {
                level->user->health -= monster->attack;
                char * monsterName = getMonsterName(monster->symbol);
                clearLine(emptyLine());
                play_effect2();
                attron(A_DIM);
                attron(COLOR_PAIR(1));
                mvprintw(emptyLine(), 2, "A %s Hit You! (%d)", monsterName, monster->attack);
                attroff(A_DIM);
                attroff(COLOR_PAIR(1));
            }
        }
        x = level->user->position->x;
        y = level->user->position->y + 1;
        if ((mvinch(y, x) & A_CHARTEXT) == '0' 
        || (mvinch(y, x) & A_CHARTEXT) == '1' 
        || (mvinch(y, x) & A_CHARTEXT) == '2' 
        || (mvinch(y, x) & A_CHARTEXT) == '3' 
        || (mvinch(y, x) & A_CHARTEXT) == '4') {
            Monster * monster = getMonsterAt(y, x, level->monstersList);
            if (monster) {
                level->user->health -= monster->attack;
                char * monsterName = getMonsterName(monster->symbol);
                clearLine(emptyLine());
                play_effect2();
                attron(A_DIM);
                attron(COLOR_PAIR(1));
                mvprintw(emptyLine(), 2, "A %s Hit You! (%d)", monsterName, monster->attack);
                attroff(A_DIM);
                attroff(COLOR_PAIR(1));
            }
        }
        x = level->user->position->x;
        y = level->user->position->y - 1;
        if ((mvinch(y, x) & A_CHARTEXT) == '0' 
        || (mvinch(y, x) & A_CHARTEXT) == '1' 
        || (mvinch(y, x) & A_CHARTEXT) == '2' 
        || (mvinch(y, x) & A_CHARTEXT) == '3' 
        || (mvinch(y, x) & A_CHARTEXT) == '4') {
            Monster * monster = getMonsterAt(y, x, level->monstersList);
            if (monster) {
                level->user->health -= monster->attack;
                char * monsterName = getMonsterName(monster->symbol);
                clearLine(emptyLine());
                play_effect2();
                attron(A_DIM);
                attron(COLOR_PAIR(1));
                mvprintw(emptyLine(), 2, "A %s Hit You! (%d)", monsterName, monster->attack);
                attroff(A_DIM);
                attroff(COLOR_PAIR(1));
            }
        }
        x = level->user->position->x + 1;
        y = level->user->position->y + 1;
        if ((mvinch(y, x) & A_CHARTEXT) == '0' 
        || (mvinch(y, x) & A_CHARTEXT) == '1' 
        || (mvinch(y, x) & A_CHARTEXT) == '2' 
        || (mvinch(y, x) & A_CHARTEXT) == '3' 
        || (mvinch(y, x) & A_CHARTEXT) == '4') {
            Monster * monster = getMonsterAt(y, x, level->monstersList);
            if (monster) {
                level->user->health -= monster->attack;
                char * monsterName = getMonsterName(monster->symbol);
                clearLine(emptyLine());
                play_effect2();
                attron(A_DIM);
                attron(COLOR_PAIR(1));
                mvprintw(emptyLine(), 2, "A %s Hit You! (%d)", monsterName, monster->attack);
                attroff(A_DIM);
                attroff(COLOR_PAIR(1));
            }
        }
        x = level->user->position->x + 1;
        y = level->user->position->y - 1;
        if ((mvinch(y, x) & A_CHARTEXT) == '0' 
        || (mvinch(y, x) & A_CHARTEXT) == '1' 
        || (mvinch(y, x) & A_CHARTEXT) == '2' 
        || (mvinch(y, x) & A_CHARTEXT) == '3' 
        || (mvinch(y, x) & A_CHARTEXT) == '4') {
            Monster * monster = getMonsterAt(y, x, level->monstersList);
            if (monster) {
                level->user->health -= monster->attack;
                char * monsterName = getMonsterName(monster->symbol);
                clearLine(emptyLine());
                play_effect2();
                attron(A_DIM);
                attron(COLOR_PAIR(1));
                mvprintw(emptyLine(), 2, "A %s Hit You! (%d)", monsterName, monster->attack);
                attroff(A_DIM);
                attroff(COLOR_PAIR(1));
            }
        }
        x = level->user->position->x - 1;
        y = level->user->position->y + 1;
        if ((mvinch(y, x) & A_CHARTEXT) == '0' 
        || (mvinch(y, x) & A_CHARTEXT) == '1' 
        || (mvinch(y, x) & A_CHARTEXT) == '2' 
        || (mvinch(y, x) & A_CHARTEXT) == '3' 
        || (mvinch(y, x) & A_CHARTEXT) == '4') {
            Monster * monster = getMonsterAt(y, x, level->monstersList);
            if (monster) {
                level->user->health -= monster->attack;
                char * monsterName = getMonsterName(monster->symbol);
                clearLine(emptyLine());
                attron(A_DIM);
                attron(COLOR_PAIR(1));
                mvprintw(emptyLine(), 2, "A %s Hit You! (%d)", monsterName, monster->attack);
                play_effect2();
                attroff(A_DIM);
                attroff(COLOR_PAIR(1));
            }
        }
        x = level->user->position->x - 1;
        y = level->user->position->y - 1;
        if ((mvinch(y, x) & A_CHARTEXT) == '0' 
        || (mvinch(y, x) & A_CHARTEXT) == '1' 
        || (mvinch(y, x) & A_CHARTEXT) == '2' 
        || (mvinch(y, x) & A_CHARTEXT) == '3' 
        || (mvinch(y, x) & A_CHARTEXT) == '4') {
            Monster * monster = getMonsterAt(y, x, level->monstersList);
            if (monster) {
                level->user->health -= monster->attack;
                char * monsterName = getMonsterName(monster->symbol);
                clearLine(emptyLine());
                play_effect2();
                attron(A_DIM);
                attron(COLOR_PAIR(1));
                mvprintw(emptyLine(), 2, "A %s Hit You! (%d)", monsterName, monster->attack);
                attroff(A_DIM);
                attroff(COLOR_PAIR(1));
            }
        }   
}