#include "rogue.h"

void saveUserGame(Level * level) {
  char buffer[2501];
  int index = 0;
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 100; j++) {
      char ch;
      if (level->tiles[i][j] != '.' && (mvinch(i, j) & A_CHARTEXT) == '.') ch = '.';
      else ch = level->tiles[i][j];
      buffer[index++] = ch;
    }
  }
  buffer[index] = '\0';
  char fileName[100];
  snprintf(fileName, sizeof(fileName), "%sMAP.txt", currentUserLogin);
  FILE *file = fopen(fileName, "w");
  fprintf(file, "%s", buffer);
  int aliveMonsters[10];
  index = 0;
  for (int i = 0; i < level->numberOfMonsters; i++) {
    if (level->monstersList[i]->alive) {
      aliveMonsters[index++] = i;
    }
  }
  int monstersInfo[30];
  int numberOfAliveMonsters = index;
  int secondIndex = 0;
  for (int i = 0; i < index; i++) {
    monstersInfo[secondIndex++] = level->monstersList[aliveMonsters[i]]->symbol;
    monstersInfo[secondIndex++] = level->monstersList[aliveMonsters[i]]->position->y;
    monstersInfo[secondIndex++] = level->monstersList[aliveMonsters[i]]->position->x;
  }
  for (int i = index; i < 10; i++) {
    monstersInfo[secondIndex++] = -1;
    monstersInfo[secondIndex++] = -1;
    monstersInfo[secondIndex++] = -1;
  }

  //level, y, x, health, gold, mace, dagger, wand, arrow, sword, sSpeed, sHealth, sDamage ---- 13 items
  fprintf(file, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", level->level,
                                                    level->user->position->y,
                                                    level->user->position->x,
                                                    numberOfFoods,
                                                    monstersInfo[0],monstersInfo[1],monstersInfo[2],monstersInfo[3],monstersInfo[4],monstersInfo[5],monstersInfo[6],monstersInfo[7],monstersInfo[8],monstersInfo[9],monstersInfo[10],monstersInfo[11],monstersInfo[12],monstersInfo[13],monstersInfo[14],monstersInfo[15],monstersInfo[16],monstersInfo[17],monstersInfo[18],monstersInfo[19],monstersInfo[20],monstersInfo[21],monstersInfo[22],monstersInfo[23],monstersInfo[24],monstersInfo[25],monstersInfo[26],monstersInfo[27],monstersInfo[28],monstersInfo[29],
                                                    level->user->health,
                                                    level->user->gold,
                                                    level->user->mace,
                                                    level->user->dagger,
                                                    level->user->wand,
                                                    level->user->arrow,
                                                    level->user->sword,
                                                    level->user->sSpeed,
                                                    level->user->sHealth,
                                                    level->user->sDamage,
                                                    numberOfAliveMonsters);
  fclose(file);
}





void drawResumeMap() {
  char filename[100];
  sprintf(filename, "%sMAP.txt", currentUserLogin);
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    clear();
    mvprintw(1, 2, "You Have No Saved Game!");
    getch();
    mainMenu();
  }
  clear();
  for (int i = 0; i < 2500; i++) {
    char ch = fgetc(file);
    mvaddch(i / 100, i % 100, ch);
  }
  refresh();
}

int placePlayerResume(Player * user, int y, int x) {
  user->position->x = x;
  user->position->y = y;
  printChar(user->position->y, user->position->x);
  move(user->position->y, user->position->x);
}

Player * playerSetUpResume(int * numbers) {
  Player * newPlayer;
  newPlayer = malloc(sizeof(Player));
  newPlayer->position = malloc(sizeof(Position));
  newPlayer->health = numbers[34];
  newPlayer->gold = numbers[35];
  newPlayer->mace = numbers[36];
  newPlayer->dagger = numbers[37];
  newPlayer->wand = numbers[38];
  newPlayer->arrow = numbers[39];
  newPlayer->sword = numbers[40];
  newPlayer->sSpeed = numbers[41];
  newPlayer->sHealth = numbers[42];
  newPlayer->sDamage = numbers[43];
  newPlayer->exp = 0;
  return newPlayer;
}

int printGameHubResume(Level * level) {
  mvprintw(25, 0, "    Level: %d", level->level);
  printw("    Gold: %d", level->user->gold);
  printw("    Hp: %d", level->user->health);
  //printw("    Exp: %d", level->user->exp);
  return 1;
}


Level * reloadLevel(int level, int * numbers) {
  Level * newLevel;
  newLevel = malloc(sizeof(Level));
  newLevel->level = level;
  newLevel->numberOfRooms = 6;
  newLevel->tiles = saveLevelPositionResume();
  addMonstersResume(newLevel, numbers);
  newLevel->user = playerSetUpResume(numbers);
  placePlayerResume(newLevel->user, numbers[1], numbers[2]);
  return newLevel;
}

char ** saveLevelPositionResume() {
  char ** positions;
  positions = malloc(sizeof(char *) * 25);
  for (int y = 0; y < 25; y++) {
    positions[y] = malloc(sizeof(char) * 100);
    for (int x = 0; x < 100; x++) {
      positions[y][x] = (mvinch(y, x) & A_CHARTEXT);
      }
  }
  return positions;
}

void reloadUserInfo() {
  char filename[100];
  sprintf(filename, "%sMAP.txt", currentUserLogin);
  FILE *file = fopen(filename, "r");
  fseek(file, 2500, SEEK_SET);

  int numbers[45];
  char buffer[256];
  fgets(buffer, sizeof(buffer), file);

  char *token = strtok(buffer, ",");
  for (int i = 0; i < 45 && token != NULL; i++) {
      numbers[i] = atoi(token);
      token = strtok(NULL, ",");
  }

  Position * newPosition;
  Level * level;
  level = reloadLevel(numbers[0], numbers);
	printGameHub(level);
  fclose(file);
  char ch;
  while ((ch = getch()) != 27 || isInSpellRoom || isInTreasure) {
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
    if (ch == 'i') {
        isGunChosen = 1;
        changeGun(level);
        printGameHub(level);
        continue;
      }
    
    if (ch == 'f') {
      //gold: g, black gold: G, gorz: M, khanjar: D, asa: S, tir: A, shamshir: W, s sorat: v, s health: h, s damage: d
      if (!inSpellRoomRandom) {
        switch(level->tiles[level->user->position->y][level->user->position->x]) {
          // case 'M':
          //   level->user->mace += 1;
          //   level->tiles[level->user->position->y][level->user->position->x] = '.';
          //   break;
          case '~':
            if (level->tiles[level->user->position->y][level->user->position->x] == '~') level->user->dagger += 9;
            level->user->dagger += 1;
            level->tiles[level->user->position->y][level->user->position->x] = '.';
            break;
          case ',':
            if (level->tiles[level->user->position->y][level->user->position->x] == ',') level->user->wand += 7;
            level->user->wand += 1;
            level->tiles[level->user->position->y][level->user->position->x] = '.';
            break;
          case '`':
            if (level->tiles[level->user->position->y][level->user->position->x] == '`') level->user->arrow += 19;
            level->user->arrow += 1;
            level->tiles[level->user->position->y][level->user->position->x] = '.';
            break;
          case 'W':
            level->user->sword += 1;
            level->tiles[level->user->position->y][level->user->position->x] = '.';
            break;
          case 'v':
            level->user->sSpeed += 1;
            level->tiles[level->user->position->y][level->user->position->x] = '.';
            break;
          case 'h':
            level->user->sHealth += 1;
            level->tiles[level->user->position->y][level->user->position->x] = '.';
            break;
          case 'd':
            level->user->sDamage += 1;
            level->tiles[level->user->position->y][level->user->position->x] = '.';
            break;
        }
      }
      else {
        switch(spellRoomTiles[level->user->position->y][level->user->position->x]) {
          case 'v':
            level->user->sSpeed += 1;
            spellRoomTiles[level->user->position->y][level->user->position->x] = '.';
            break;
          case 'h':
            level->user->sHealth += 1;
            spellRoomTiles[level->user->position->y][level->user->position->x] = '.';
            break;
          case 'd':
            level->user->sDamage += 1;
            spellRoomTiles[level->user->position->y][level->user->position->x] = '.';
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

    if (isInTreasure) {

      int isFinished = 1;
      for (int i = 0; i < 6; i++) {
        if (level->monstersList[i]->alive == 1) {
          isFinished = 0;
          break;
        }
      }

      if (isFinished) {
        attron(A_BOLD);
        attron(COLOR_PAIR(1));
        mvprintw(10, 10, "You Won!");
        attroff(A_BOLD);
        attroff(COLOR_PAIR(1));
        play_effect_win();
        play_or_replace_music("music1.mp3");
        gameStatus = 1;
        if (!isGeust) {
          saveToLeaderBoard(level);
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
        break;
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
  }

  if (!isGeust && !gameStatus) saveUserGame(level);
}



void resumeGameProccess() {
  isGeust = 0;
  drawResumeMap();
  reloadUserInfo();
}

void addMonstersResume(Level * level, int * numbers) {
  level->monstersList = malloc(sizeof(Monster *) * 20);
  level->numberOfMonsters = 0;
  int randomMonster;
  for (int x = 0; x < numbers[44]; x++) {
    level->monstersList[level->numberOfMonsters] = selectMonsterResume(numbers, 3 * (x+1) + 1);
    level->numberOfMonsters += 1;
  }
}

Monster* selectMonsterResume(int* numbers, int index) {
  int monster = numbers[index++];
  int y = numbers[index++];
  int x = numbers[index++];
  switch (monster) {
      case '0':
          return createMonsterResume('0', 5, 1, 1, 1, 1, 0, y, x);
      case '1':
          return createMonsterResume('1', 10, 1, 1, 1, 1, 0, y, x);
      case '2':
          return createMonsterResume('2', 15, 3, 1, 1, 2, 5, y, x);
      case '3':
          return createMonsterResume('3', 20, 5, 1, 1, 3, 0, y, x);
      case '4':
          return createMonsterResume('4', 30, 5, 1, 1, 2, 5, y, x);
  }
  return NULL;
}


Monster * createMonsterResume(char symbol, int health, int attack, int speed, int defence, int pathfinding, int steps, int y, int x) {
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
    newMonster->position->y = y;
    newMonster->position->x = x;
    return newMonster;
}