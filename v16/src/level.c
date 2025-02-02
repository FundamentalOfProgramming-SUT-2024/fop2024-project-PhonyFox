#include "rogue.h"


Level * createLevel(int level) {
  Level * newLevel;
  newLevel = malloc(sizeof(Level));
  newLevel->level = level;
  newLevel->numberOfRooms = 6;
  newLevel->rooms = roomsSetUp();
  connectDoors(newLevel);
  newLevel->tiles = saveLevelPosition();
  addMonsters(newLevel);
  newLevel->user = playerSetUp();
  placePlayer(newLevel->rooms, newLevel->user);
  return newLevel;
}

Room ** roomsSetUp() {
  Room ** rooms;
  rooms = malloc(sizeof(Room) * 6);

  for (int x = 0; x < 6; x++) {
    rooms[x] = createRoom(x, 4);
    drawRoom(rooms[x]);
  }
  return rooms;
}

Room ** lastroomsSetUp() {
  Room ** rooms;
  rooms = malloc(sizeof(Room) * 6);

  for (int x = 0; x < 5; x++) {
    rooms[x] = createRoom(x, 4);
    drawRoom(rooms[x]);
  }
  rooms[5] = createLastRoom(5, 4);
  drawRoom(rooms[5]);

  return rooms;
}


void connectDoors(Level * level) {

  int shuffleArr[4] = {1, 2, 3, 4};

  for (int i = 3; i > 0; i--) {
    int j = rand() % (i + 1);
    int temp = shuffleArr[i];
    shuffleArr[i] = shuffleArr[j];
    shuffleArr[j] = temp;
  }

  int roomArrangement[6];
  roomArrangement[0] = 0;
  roomArrangement[5] = 5;
  for (int i = 1; i < 5; i++) {
    roomArrangement[i] = shuffleArr[i-1];
  }

  for (int i = 0; i < 5; i++) {
    pathFind(&level->rooms[roomArrangement[i]]->doors[3]->position, &level->rooms[roomArrangement[i+1]]->doors[0]->position);
  }
}

char ** saveLevelPosition() {
  char ** positions;
  positions = malloc(sizeof(char *) * 25);
  for (int y = 0; y < 25; y++) {
    positions[y] = malloc(sizeof(char) * 100);
    for (int x = 0; x < 100; x++) {
      if((mvinch(y, x) & A_CHARTEXT) != '@') positions[y][x] = (mvinch(y, x) & A_CHARTEXT);
      else positions[y][x] = '.';
      }
  }
  return positions;
}

void addMonsters(Level * level) {
  level->monstersList = malloc(sizeof(Monster *) * 20);
  level->numberOfMonsters = 0;
  int randomMonster;
  for (int x = 0; x < level->numberOfRooms; x++) {
    randomMonster = rand() % difficulty;
    if (randomMonster < 6) {
      level->monstersList[level->numberOfMonsters] = selectMonster(level->level);
      setStartingPosition(level->monstersList[level->numberOfMonsters], level->rooms[x]);
      level->numberOfMonsters += 1;
    }
  }
}

void moveMonsters(Level * level) {
  for (int x = 0; x < level->numberOfMonsters; x++) {
    if (level->monstersList[x]->alive == 0) continue;
    if (level->monstersList[x]->canWalk == 0) continue;
    if (level->monstersList[x]->pathfinding == 1) {
      if (level->tiles[level->user->position->y][level->user->position->x] != '#' && abs(level->user->position->y - level->monstersList[x]->position->y) < 8 && abs(level->user->position->x - level->monstersList[x]->position->x) < 20) {
        pathfindingRandom(level->monstersList[x]->position);
      }
    }
    if (level->monstersList[x]->pathfinding == 2) {
      if (level->tiles[level->user->position->y][level->user->position->x] != '#' && abs(level->user->position->y - level->monstersList[x]->position->y) < 8 && abs(level->user->position->x - level->monstersList[x]->position->x) < 20) {
        level->monstersList[x]->steps--;
        if (level->monstersList[x]->steps > 0) {
          pathfindingSeek(level->monstersList[x]->position, level->user->position);
        }
      }
    }
    if (level->monstersList[x]->pathfinding == 3) {
      if (level->tiles[level->user->position->y][level->user->position->x] != '#' && abs(level->user->position->y - level->monstersList[x]->position->y) < 8 && abs(level->user->position->x - level->monstersList[x]->position->x) < 20) {
        pathfindingSeek(level->monstersList[x]->position, level->user->position);
      }
    }
  }
}
