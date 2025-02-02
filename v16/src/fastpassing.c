#include "rogue.h"

int isOpen = 1;

void fastPassing(Level * level) {
    Position * newPosition;
    isOpen = 1;
    clearLine(emptyLine());
    attron(A_DIM);
    attron(COLOR_PAIR(1));
    mvprintw(emptyLine(), 2, "Choose The Direction:");
    attroff(A_DIM);
    attroff(COLOR_PAIR(1));
    int ch = getch();
    while (isOpen) {
        printGameHub(level);
        switch (ch) {
            case 'W':
            case 'w':
                newPosition = handleInput(ch, level->user);
                checkPositionForFast(newPosition, level);
                break;
            case 'D':
            case 'd':
                newPosition = handleInput(ch, level->user);
                checkPositionForFast(newPosition, level);
                break;
            case 'S':
            case 's':
                newPosition = handleInput(ch, level->user);
                checkPositionForFast(newPosition, level);
                break;
            case 'A':
            case 'a':
                newPosition = handleInput(ch, level->user);
                checkPositionForFast(newPosition, level);
                break;
            default:
                clearLine(emptyLine());
                attron(A_DIM);
                attron(COLOR_PAIR(1));
                mvprintw(emptyLine(), 2, "You Chose A Wrong Key");
                attroff(A_DIM);
                attroff(COLOR_PAIR(1));
                isOpen = 0;
                break;
        }
        if (hasSpeedSpell) {
        hasSpeedSpell *= -1;
        if (hasSpeedSpell == 1) {
            moveMonsters(level);
        }
        }
        else {
        moveMonsters(level);
        }
        for (int i = 0; i < level->numberOfMonsters; i++)
        {
            drawMonsters(level->monstersList[i]);
        }

        monstersAttack(level);

        if (walkingAndHunger < 20) {
        walkingAndHunger++;
        }
        else if (numberOfFoods > 0) {
        numberOfFoods--;
        clearLine(emptyLine());
        attron(A_DIM);
        attron(COLOR_PAIR(1));
        mvprintw(emptyLine(), 2, "Yami Yami!");
        attroff(A_DIM);
        attroff(COLOR_PAIR(1));
        walkingAndHunger = 0;
        }
        else {
        level->user->health--;
        clearLine(emptyLine());
        attron(A_DIM);
        attron(COLOR_PAIR(1));
        mvprintw(emptyLine(), 2, "Hunger And No Food! You Are Hurting!");
        attroff(A_DIM);
        attroff(COLOR_PAIR(1));
        walkingAndHunger = 0;
        }

        if (numberOfFoods == 5) {
        if (fullToHealth < 20) {
            fullToHealth++;
            if (hasHealthSpell) fullToHealth++;
        }
        else {
            level->user->health++;
            if (hasHealthSpell) level->user->health++;
            clearLine(emptyLine());
            attron(A_DIM);
            attron(COLOR_PAIR(1));
            mvprintw(emptyLine(), 2, "Enough Food Leads to Health!");
            attroff(A_DIM);
            attroff(COLOR_PAIR(1));
            fullToHealth = 0;
        }
        }
        if (speedSteps > 0) {
        speedSteps--;
        if (speedSteps == 0) {
            hasSpeedSpell = 0;
        }
        }
        if (healthSteps > 0) {
        healthSteps--;
        if (healthSteps == 0) {
            hasHealthSpell = 0;
        }
        }
        if (damageSteps > 0) {
        damageSteps--;
        if (damageSteps == 0) {
            hasDamageSpell = 0;
        }
        }
        checkStatus(level);
        refresh();
        napms(200);
    }
}

int checkPositionForFast(Position * newPosition, Level * level) {
  Player * user;
  user = level->user;
  switch ((mvinch(newPosition->y, newPosition->x) & A_CHARTEXT)) {
    case '.':
    case '#':
      playerMove(newPosition, user, level->tiles);
      break;
    case '+':
      if ((mvinch(user->position->y, user->position->x) & A_CHARTEXT) == '#') {
        clearLine(emptyLine());
        attron(A_DIM);
        attron(COLOR_PAIR(1));
        mvprintw(emptyLine(), 2, "Explore the new room");
        attroff(A_DIM);
        attroff(COLOR_PAIR(1));
        }
      playerMove(newPosition, user, level->tiles);
      break;
    case 'g':
      clearLine(emptyLine());
      attron(A_DIM);
      attron(COLOR_PAIR(1));
      mvprintw(emptyLine(), 2, "Hooray! Gold!");
      attroff(A_DIM);
      attroff(COLOR_PAIR(1));
      level->user->gold += 1;
      playerMove(newPosition, user, level->tiles);
      break;
    // case 'U':
    //   clear();
    //   refresh();
    //   inSpellRoomRandom = 0;
    //   level->rooms = roomsSetUp();
    //   connectDoors(level);
    //   level->tiles = saveLevelPosition();
    //   placePlayer(level->rooms, level->user);
    //   printGameHub(level);
    //   break;
    case 'f':
      clearLine(emptyLine());
      attron(A_DIM);
      attron(COLOR_PAIR(1));
      mvprintw(emptyLine(), 2, "Food is good!");
      attroff(A_DIM);
      attroff(COLOR_PAIR(1));
      if (numberOfFoods < 5) numberOfFoods += 1;
      playerMove(newPosition, user, level->tiles);
      break;
    //gold: g, black gold: G, gorz: M, khanjar: D, asa: S, tir: A, shamshir: W, s sorat: v, s health: h, s damage: d
    //case 'M':
    case '~':
      if (level->tiles[newPosition->y][newPosition->x] != '~') level->user->dagger++;
      playerMove(newPosition, user, level->tiles);
      break;
    case ',':
      if (level->tiles[newPosition->y][newPosition->x] != ',') level->user->wand++;
      playerMove(newPosition, user, level->tiles);
      break;
    case '`':
      if (level->tiles[newPosition->y][newPosition->x] != '`') level->user->arrow++;
      playerMove(newPosition, user, level->tiles);
      break;
    case 'W':
    case 'v':
    case 'h':
    case 'd':
      playerMove(newPosition, user, level->tiles);
      break;
    case 'G':
      clearLine(emptyLine());
      attron(A_DIM);
      attron(COLOR_PAIR(1));
      mvprintw(emptyLine(), 2, "Hooray! Black Gold!");
      attroff(A_DIM);
      attroff(COLOR_PAIR(1));
      level->user->gold += 3;
      playerMove(newPosition, user, level->tiles);
      break;
    default:
      move(user->position->y, user->position->x);
      isOpen = 0;
      break;
  }
}