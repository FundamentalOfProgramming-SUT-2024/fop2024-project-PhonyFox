#include "rogue.h"

int speedSteps = 0;
int hasSpeedSpell = 0;
int healthSteps = 0;
int hasHealthSpell = 0;
int damageSteps = 0;
int hasDamageSpell = 0;

void chooseSpell(Level * level) {
    clearLine(emptyLine());
    attron(A_DIM);
    attron(COLOR_PAIR(1));
    mvprintw(emptyLine(), 2, "Speed Spell x %d   Health Spell x %d   Damage Spell x %d", level->user->sSpeed, level->user->sHealth, level->user->sDamage);
    attroff(A_DIM);
    attroff(COLOR_PAIR(1));
    clearLine(emptyLine());
    attron(A_DIM);
    attron(COLOR_PAIR(1));
    mvprintw(emptyLine(), 2, "Choose Between Speed (1), Health (2), Damage (3)");
    attroff(A_DIM);
    attroff(COLOR_PAIR(1));
    int ch = getch();
    switch (ch) {
        case '1':
            if (level->user->sSpeed > 0) {
                level->user->sSpeed--;
                speedSteps = 50;
                hasSpeedSpell = 1;
            }
            else {
                clearLine(emptyLine());
                attron(A_DIM);
                attron(COLOR_PAIR(1));
                mvprintw(emptyLine(), 2, "You Have No Speed Spell!");
                attroff(A_DIM);
                attroff(COLOR_PAIR(1));
            }
            break;
        case '2':
            if (level->user->sHealth > 0) {
                level->user->sHealth--;
                healthSteps = 50;
                hasHealthSpell = 1;
            }
            else {
                clearLine(emptyLine());
                attron(A_DIM);
                attron(COLOR_PAIR(1));
                mvprintw(emptyLine(), 2, "You Have No Health Spell!");
                attroff(A_DIM);
                attroff(COLOR_PAIR(1));
            }
            break;
        case '3':
            if (level->user->sDamage > 0) {
                level->user->sDamage--;
                damageSteps = 50;
                hasDamageSpell = 1;
            }
            else {
                clearLine(emptyLine());
                attron(A_DIM);
                attron(COLOR_PAIR(1));
                mvprintw(emptyLine(), 2, "You Have No Damage Spell!");
                attroff(A_DIM);
                attroff(COLOR_PAIR(1));
            }
            break;
    }
}