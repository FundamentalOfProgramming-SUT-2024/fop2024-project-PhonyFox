#include "rogue.h"

int passwordChances = 3;
int gameStatus = 0;
int spellOrLevel = 0;
int inSpellRoomRandom = 0;
int isInTreasure = 0;

Player * playerSetUp() {
  Player * newPlayer;
  newPlayer = malloc(sizeof(Player));
  newPlayer->position = malloc(sizeof(Position));
  newPlayer->health = 1000;
  newPlayer->maxHealth = 20;
  newPlayer->gold = 0;
  newPlayer->exp = 0;
  newPlayer->mace = 0;
  newPlayer->dagger = 0;
  newPlayer->wand = 0;
  newPlayer->arrow = 0;
  newPlayer->sword = 0;
  newPlayer->sHealth = 0;
  newPlayer->sDamage = 0;
  newPlayer->sSpeed = 0;
  return newPlayer;
}


int placePlayer(Room ** rooms, Player * user) {
  user->position->x = rooms[0]->position.x + 1;
  user->position->y = rooms[0]->position.y + 1;
  printChar(user->position->y, user->position->x);
  move(user->position->y, user->position->x);
}

Position * handleInput(int input, Player * user) {
  Position * newPosition;
  newPosition = malloc(sizeof(Position));

  if (newPosition == NULL) {
    return NULL;
  }
  switch (input) {
    case 'Q':
    case 'q':
      newPosition->y = user->position->y - 1;
      newPosition->x = user->position->x - 1;
      break;
    case 'E':
    case 'e':
      newPosition->y = user->position->y - 1;
      newPosition->x = user->position->x + 1;
      break;
    case 'Z':
    case 'z':
      newPosition->y = user->position->y + 1;
      newPosition->x = user->position->x - 1;
      break;
    case 'C':
    case 'c':
      newPosition->y = user->position->y + 1;
      newPosition->x = user->position->x + 1;
      break;
    case 'w':
    case 'W':
      newPosition->y = user->position->y - 1;
      newPosition->x = user->position->x;
      break;
    case 's':
    case 'S':
      newPosition->y = user->position->y + 1;
      newPosition->x = user->position->x;
      break;
    case 'a':
    case 'A':
      newPosition->y = user->position->y;
      newPosition->x = user->position->x - 1;
      break;
    case 'd':
    case 'D':
      newPosition->y = user->position->y;
      newPosition->x = user->position->x + 1;
      break;
    default:
      break;
  }
  return newPosition;
}

int checkPosition(Position * newPosition, Level * level) {
  Player * user;
  user = level->user;
  switch ((mvinch(newPosition->y, newPosition->x) & A_CHARTEXT)) {
    case '.':
    case '#':
      playerMove(newPosition, user, level->tiles);
      break;
    case 'p':
      doorPassword = rand() % 9000 + 1000;
      clearLine(emptyLine());
      attron(A_DIM);
      attron(COLOR_PAIR(1));
      mvprintw(emptyLine(), 2, "%d", doorPassword);
      attroff(A_DIM);
      attroff(COLOR_PAIR(1));
      playerMove(newPosition, user, level->tiles);
      break;
    case 'O':
      if (passwordChances) {
      	if (windowMaker()) {
          attron(A_BOLD);
          attron(A_DIM);
          attron(COLOR_PAIR(5));
          mvprintw(newPosition->y, newPosition->x, "+");
          attroff(A_BOLD);
          attroff(A_DIM);
          attroff(COLOR_PAIR(5));
        	playerMove(newPosition, user, level->tiles);
      	}
      }
      break;
    case '?':
      clear();
  	  level->level += 1;
      for (int i = 0; i < level->numberOfMonsters; i++) {
        level->monstersList[i]->alive = 0;
      }
      spellOrLevel = rand() % 5;
      if (level->level == 5) {
        level->rooms = lastroomsSetUp();
        connectDoors(level);
        level->tiles = saveLevelPosition();
        addMonsters(level);
        placePlayer(level->rooms, level->user);
        printGameHub(level);
      }
      else if (spellOrLevel) {
        level->rooms = roomsSetUp();
        connectDoors(level);
        level->tiles = saveLevelPosition();
        addMonsters(level);
        placePlayer(level->rooms, level->user);
        printGameHub(level);
      }
      else {
        spellRoomMaker();
        newPosition->y = 2;
        newPosition->x = 103;
        inSpellRoomRandom = 1;
        playerMove(newPosition, user, level->tiles);
      }
      break;
    case '+':
      if (level->tiles[user->position->y][user->position->x] == '#') {
        clearLine(emptyLine());
        attron(A_DIM);
        attron(COLOR_PAIR(1));
        mvprintw(emptyLine(), 2, "Explore The New Room!");
        attroff(A_DIM);
        attroff(COLOR_PAIR(1));
        play_effect_newRoom();
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
    case 'U':
      clear();
      refresh();
      play_or_replace_music("music1.mp3");
      inSpellRoomRandom = 0;
      level->rooms = roomsSetUp();
      connectDoors(level);
      level->tiles = saveLevelPosition();
      placePlayer(level->rooms, level->user);
      printGameHub(level);
      break;
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
    case 'F':
      //gameStatus = 1;
      clear();
      isInTreasure = 1;
      makeTreasureRoom(level);
    default:
      move(user->position->y, user->position->x);
      break;
  }
}

int playerMove(Position * newPosition, Player * user, char ** tiles)
{
  	if (tiles == NULL) {
          return 0;
  	}
    char ch = tiles[user->position->y][user->position->x];
    if (!(ch == 'g' || ch == 'G' || ch == 'f')) {
    	if (!inSpellRoomRandom) {
        printWithColor(user->position->y, user->position->x, ch);
      }
      else {
        ch = spellRoomTiles[user->position->y][user->position->x];
        printWithColor(user->position->y, user->position->x, ch);
      }
    }
    else {
      printWithColor(user->position->y, user->position->x, '.');
    }

    user->position->y = newPosition->y;
    user->position->x = newPosition->x;
	if ((mvinch(user->position->y, user->position->x) & A_CHARTEXT) == '.') {
    if (!inSpellRoomRandom) {
      if (rand() % 100 == 0) {
        user->health = user->health - 1;
        clearLine(emptyLine());
        attron(A_DIM);
        attron(COLOR_PAIR(1));
        mvprintw(emptyLine(), 2, "Trap!");
        attroff(A_DIM);
        attroff(COLOR_PAIR(1));
      }
    }
    else {
      if (rand() % 10 == 0) {
        user->health = user->health - 1;
        clearLine(emptyLine());
        attron(A_DIM);
        attron(COLOR_PAIR(1));
        mvprintw(emptyLine(), 2, "Trap!");
        attroff(A_DIM);
        attroff(COLOR_PAIR(1));
      }
    }
	}
    printChar(user->position->y, user->position->x);
    move(user->position->y, user->position->x);
    play_effect1();
}

void changeGun(Level * level) {
  clearLine(emptyLine());
  attron(A_DIM);
  attron(COLOR_PAIR(1));
  mvprintw(emptyLine(), 2, "Choose A Number Between 1 to 5");
  attroff(A_DIM);
  attroff(COLOR_PAIR(1));
  char ch = getch();
  if (ch != 'w') return;
  else ch = getch(); 
  switch (ch) {
    case '2':
      level->user->gunType = 2;
      break;
    case '3':
      level->user->gunType = 3;
      break;
    case '4':
      level->user->gunType = 4;
      break;
    case '5':
      level->user->gunType = 5;
      break;
    default:
      level->user->gunType = 1;
      break;
  }
}
