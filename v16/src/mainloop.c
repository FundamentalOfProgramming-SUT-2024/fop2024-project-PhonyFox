#include "rogue.h"

int numberOfFoods = 0;
int walkingAndHunger = 0;
int fullToHealth = 0;
int isGunChosen = 0;
int wantedToAutoAim = 0;
int characterColor = 5;
int foodSteps[4][5] = {0};
int totalWalk = 0;


int mainGameLoop() {
  int ch;
  gameStatus = 0;
  curs_set(0);
  Position * newPosition;

  Level * level;

  level = createLevel(1);
  printGameHub(level);
  while ((ch = getch()) != 27 || isInSpellRoom || isInTreasure) {
    refresh();
    if (ch == '.') {
      fastPassing(level);
      continue;
    }
    if (ch == 'o') {
      chooseSpell(level);
      printGameHub(level);
      continue;
    }
    if (ch == 'y') {
      clearLine(emptyLine());
      attron(A_DIM);
      attron(COLOR_PAIR(1));
      mvprintw(emptyLine(), 2, "You Have %d Food.", numberOfFoods);
      attroff(A_DIM);
      attroff(COLOR_PAIR(1));
      continue;
    }
    if (ch == '=') {
      if (hasSavedShot) {
        int launchGun = hasSavedShot / 10;
        wantedToAutoAim = 1;
        if (launchGun == 2) {
          combat(2, level);
        }
        else if (launchGun == 3) {
          combat(3, level);
        }
        else if (launchGun == 4) {
          combat(4, level);
        }
        monstersAttack(level);
      }
      else {
        clearLine(emptyLine());
        attron(A_DIM);
        attron(COLOR_PAIR(1));
        mvprintw(emptyLine(), 2, "You Have No Saved Shot!");
        attroff(A_DIM);
        attroff(COLOR_PAIR(1));
      }
      printGameHub(level);
      continue;
    }
    wantedToAutoAim = 0;
    if (ch == ' ') {
    if (!isInSpellRoom && (level->tiles[level->user->position->y][level->user->position->x] != '#')) {
    if (isGunChosen) {
      combat(level->user->gunType, level);
    }
    else {
      combat(1, level);
    }
    monstersAttack(level);
    printGameHub(level);
    continue;
    }
  } 
    if (ch == 'i') {
      isGunChosen = 1;
      refresh();
      changeGun(level);
      printGameHub(level);
      continue;
    }
    if (ch == 'f') {
      //gold: g, black gold: G, gorz: M, khanjar: D, asa: S, tir: A, shamshir: W, s sorat: v, s health: h, s damage: d
      if (!isInSpellRoom) {
        switch(level->tiles[level->user->position->y][level->user->position->x]) {
          // case 'M':
          //   level->user->mace += 1;
          //   level->tiles[level->user->position->y][level->user->position->x] = '.';
          //   break;
          case '~':
            if (level->tiles[level->user->position->y][level->user->position->x] == '~') {level->user->dagger += 9;
            play_effect3();}
            level->user->dagger += 1;
            level->tiles[level->user->position->y][level->user->position->x] = '.';
            play_effect3();
            break;
          case ',':
            if (level->tiles[level->user->position->y][level->user->position->x] == ',') {level->user->wand += 7;
            play_effect3();}
            level->user->wand += 1;
            level->tiles[level->user->position->y][level->user->position->x] = '.';
            play_effect3();
            break;
          case '`':
            if (level->tiles[level->user->position->y][level->user->position->x] == '`') {level->user->arrow += 19;
            play_effect3();}
            level->user->arrow += 1;
            level->tiles[level->user->position->y][level->user->position->x] = '.';
            play_effect3();
            break;
          case 'W':
            level->user->sword += 1;
            level->tiles[level->user->position->y][level->user->position->x] = '.';
            play_effect3();
            break;
          case 'v':
            level->user->sSpeed += 1;
            level->tiles[level->user->position->y][level->user->position->x] = '.';
            play_effect3();
            break;
          case 'h':
            level->user->sHealth += 1;
            level->tiles[level->user->position->y][level->user->position->x] = '.';
            play_effect3();
            break;
          case 'd':
            level->user->sDamage += 1;
            level->tiles[level->user->position->y][level->user->position->x] = '.';
            play_effect3();
            break;
        }
      }
      else {
        switch(spellRoomTiles[level->user->position->y][level->user->position->x]) {
          case 'v':
            level->user->sSpeed += 1;
            spellRoomTiles[level->user->position->y][level->user->position->x] = '.';
            play_effect3();
            break;
          case 'h':
            level->user->sHealth += 1;
            spellRoomTiles[level->user->position->y][level->user->position->x] = '.';
            play_effect3();
            break;
          case 'd':
            level->user->sDamage += 1;
            spellRoomTiles[level->user->position->y][level->user->position->x] = '.';
            play_effect3();
            break;
        }
      }
    }
	if (ch == 'g' || ch == 'G') {
    if (level->user->sword > 0) {
      clearLine(emptyLine());
      attron(A_DIM);
      attron(COLOR_PAIR(1));
      mvprintw(emptyLine(), 2, "Dagger x %d   Wand x %d   Arrow x %d  With Sword ", level->user->dagger, level->user->wand, level->user->arrow);
      attroff(A_DIM);
      attroff(COLOR_PAIR(1));
    }
    else {
      clearLine(emptyLine());
      attron(A_DIM);
      attron(COLOR_PAIR(1));
      mvprintw(emptyLine(), 2, "Dagger x %d   Wand x %d   Arrow x %d  Without Sword ", level->user->dagger, level->user->wand, level->user->arrow);
      attroff(A_DIM);
      attroff(COLOR_PAIR(1));
    }
	}
	if (ch == 't' || ch == 'T') {
    clearLine(emptyLine());
    attron(A_DIM);
    attron(COLOR_PAIR(1));
    mvprintw(emptyLine(), 2, "Speed Spell x %d   Health Spell x %d   Damage Spell x %d", level->user->sSpeed, level->user->sHealth, level->user->sDamage);
    attroff(A_DIM);
    attroff(COLOR_PAIR(1));
	}
    printGameHub(level);
    newPosition = handleInput(ch, level->user);
    checkPosition(newPosition, level);
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

    if (walkingAndHunger < 60) {
      walkingAndHunger++;
    }
    else if (numberOfFoods > 0) {
      numberOfFoods--;
      int oldestFood = -1;
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
          if (oldestFood < foodSteps[i][j]) {
            oldestFood = foodSteps[i][j];
          }
        }
      }
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
          if (oldestFood == foodSteps[i][j]) {
            if (i == 0) {
              foodSteps[i][j] = 0;
              level->user->health -= 10;
              clearLine(emptyLine());
              attron(A_DIM);
              attron(COLOR_PAIR(1));
              mvprintw(emptyLine(), 2, "Oh! That Was Spoiled!");
              attroff(A_DIM);
              attroff(COLOR_PAIR(1));
            }
            if (i == 1) {
              foodSteps[i][j] = 0;
              level->user->health += 10;
              clearLine(emptyLine());
              attron(A_DIM);
              attron(COLOR_PAIR(1));
              mvprintw(emptyLine(), 2, "Yami Yami!");
              attroff(A_DIM);
              attroff(COLOR_PAIR(1));
            }
            if (i == 2) {
              foodSteps[i][j] = 0;
              level->user->health += 10;
              hasDamageSpell = 1;
              damageSteps = 50;
              clearLine(emptyLine());
              attron(A_DIM);
              attron(COLOR_PAIR(1));
              mvprintw(emptyLine(), 2, "Food and Power? Nice!");
              attroff(A_DIM);
              attroff(COLOR_PAIR(1));
            }
            if (i == 3) {
              foodSteps[i][j] = 0;
              level->user->health += 10;
              hasSpeedSpell = 1;
              speedSteps = 50;
              clearLine(emptyLine());
              attron(A_DIM);
              attron(COLOR_PAIR(1));
              mvprintw(emptyLine(), 2, "Food and Speed? Nice!");
              attroff(A_DIM);
              attroff(COLOR_PAIR(1));
            }
          }
        }
      }
      // clearLine(emptyLine());
      // attron(A_DIM);
      // attron(COLOR_PAIR(1));
      // mvprintw(emptyLine(), 2, "Yami Yami!");
      // attroff(A_DIM);
      // attroff(COLOR_PAIR(1));
      walkingAndHunger = 0;
    }
    else {
      level->user->health -= 20;
      clearLine(emptyLine());
      attron(A_DIM);
      attron(COLOR_PAIR(1));
      mvprintw(emptyLine(), 2, "Hunger And No Food! You Are Hurting!");
      attroff(A_DIM);
      attroff(COLOR_PAIR(1));
      walkingAndHunger = 0;
    }

    if (numberOfFoods > 2) {
      if (fullToHealth < 20) {
        fullToHealth++;
        if (hasHealthSpell) fullToHealth++;
      }
      else {
        level->user->health += 20;
        if (hasHealthSpell) level->user->health += 20;
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
    totalWalk++;
    for (int i = 1; i < 4; i++) {
      for (int j = 0; j < 5; j++) {
        if (totalWalk - foodSteps[i][j] > 60) {
          if (i == 1) {
            for (int q = 0; q < 5; q++) {
              if (foodSteps[0][q] == 0) {
                foodSteps[0][q] = foodSteps[i][j];
                foodSteps[i][j] = 0;
                break;
              }
            }
          }
          if (i == 2 || i == 3) {
            for (int q = 0; q < 5; q++) {
              if (foodSteps[1][q] == 0) {
                foodSteps[1][q] = foodSteps[i][j];
                foodSteps[i][j] = 0;
                break;
              }
            }
          }
        }
      }
    }
    if (isInTreasure) {

      int isFinished = 1;
      for (int i = 0; i < 6; i++) {
        if (level->monstersList[i]->alive == 1) {
          isFinished = 0;
          break;
        }
      }

      if (isFinished) {
        // clear();
        // attron(A_BOLD);
        // attron(COLOR_PAIR(1));
        // mvprintw(10, 10, "You Won!");
        // attroff(A_BOLD);
        // attroff(COLOR_PAIR(1));
        // play_effect_win();
        // play_or_replace_music("music1.mp3");
        gameStatus = 1;
        isInTreasure = 0;
        if (!isGeust) {
          isInTreasure = 0;
          saveToLeaderBoard(level);
          saveUserGame(level);
        }
        trollFace();
        if (!isGeust) {
          saveToLeaderBoard(level);
          saveUserGame(level);
        }
        int chFinish;
        clearLine(emptyLine());
        attron(A_BOLD);
        attron(COLOR_PAIR(1));
        mvprintw(emptyLine(), 2, "Press Esc To Exit");
        attroff(A_BOLD);
        attroff(COLOR_PAIR(1));
        while ((chFinish = getch()) != 27) {}
        clear();
        mainMenu();
      }
    }

    checkStatus(level);

    if (!isGeust) {
      if (gameStatus) {
        saveToLeaderBoard(level);
        clear();
        mainMenu();
      }
	  }
    refresh();
  }
  if (!isGeust && !gameStatus) saveUserGame(level);
}


int changeLevel(Level * level) {
  for (int i = 0; i < level->numberOfMonsters; i++) {
    level->monstersList[i]->alive = 0;
  }
  level->level += 1;
  level->rooms = roomsSetUp();
  connectDoors(level);
  level->tiles = saveLevelPosition();
  level->user = playerSetUp();
  placePlayer(level->rooms, level->user);
  return 1;
}

void checkStatus(Level * level) {
	if (level->user->health <= 0) {
    	  gameStatus = -1;
        if (!isGeust) {
          if (gameStatus) {
            saveToLeaderBoard(level);
            clear();
            mainMenu();
          }
        }
        isInTreasure = 0;
        printTrolls();
        // play_effect_lose();
        // clear();
        // refresh();
        // attron(A_BOLD);
        // attron(COLOR_PAIR(1));
        // mvprintw(10, 10, "You Lost the Game!");
        // attroff(A_BOLD);
        // attroff(COLOR_PAIR(1));
        // refresh();
		    // getch();
        // getch();
        // clear();
        //mainMenu();
    }
}

void saveToLeaderBoard(Level * level) {
	FILE * file = fopen("LEADERBOARD.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");
    char line[256];
    int userFound = 0;
    while (fgets(line, sizeof(line), file)) {
    	char user[50];
        int values[10];
        sscanf(line, "%[^,],%d,%d,%d,%d", user, &values[0], &values[1], &values[2], &values[3]);
        if (strcmp(user, currentUserLogin) == 0) {
        	  userFound = 1;
            values[0] += (gameStatus + 1) / 2;
            values[1] += 1;
            values[2] += level->user->gold * (difficulty / 3);
            values[3] += level->user->gold;
            fprintf(tempFile, "%s,%d,%d,%d,%d\n", user, values[0], values[1], values[2], values[3]);
		}
        else {
        	fputs(line, tempFile);
        }
    }
    fclose(file);
    fclose(tempFile);
    remove("LEADERBOARD");
    rename("temp.txt", "LEADERBOARD.txt");
}