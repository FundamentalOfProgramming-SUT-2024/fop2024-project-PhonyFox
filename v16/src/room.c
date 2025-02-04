#include "rogue.h"

int doorPassword = 0;

Room * createLastRoom(int grid, int numberOfDoors) {
  Room * newRoom;
  newRoom = malloc(sizeof(Room));
  newRoom->grid = -1;
  newRoom->numberOfDoors = numberOfDoors;
  switch (grid) {
    case 0:
      newRoom->position.x = 0;
      newRoom->position.y = 0;
      break;
    case 1:
      newRoom->position.x = 33;
      newRoom->position.y = 0;
      break;
    case 2:
      newRoom->position.x = 66;
      newRoom->position.y = 0;
      break;
    case 3:
      newRoom->position.x = 0;
      newRoom->position.y = 14;
      break;
    case 4:
      newRoom->position.x = 33;
      newRoom->position.y = 14;
      break;
    case 5:
      newRoom->position.x = 66;
      newRoom->position.y = 14;
      break;
  }

  newRoom->height = rand() % 6 + 4;
  newRoom->width = rand() % 14 + 4;

  newRoom->position.x += rand() % (30 - newRoom->width) + 1;
  newRoom->position.y += rand() % (10 - newRoom->height) + 1;

  newRoom->doors = malloc(sizeof(Door *) * numberOfDoors);

  for (int i = 0; i < numberOfDoors; i++) {
    newRoom->doors[i] = malloc(sizeof(Door));
    newRoom->doors[i]->connected = 0;
  }

  newRoom->doors[0]->position.x = rand() % (newRoom->width - 2) + newRoom->position.x + 1;
  newRoom->doors[0]->position.y = newRoom->position.y;

  newRoom->doors[1]->position.y = rand() % (newRoom->height - 2) + newRoom->position.y + 1;
  newRoom->doors[1]->position.x = newRoom->position.x;

  newRoom->doors[2]->position.x = rand() % (newRoom->width - 2) + newRoom->position.x + 1;
  newRoom->doors[2]->position.y = newRoom->position.y + newRoom->height - 1;

  newRoom->doors[3]->position.y = rand() % (newRoom->height - 2) + newRoom->position.y + 1;
  newRoom->doors[3]->position.x = newRoom->position.x + newRoom->width - 1;

  return newRoom;
}

Room * createRoom(int grid, int numberOfDoors) {
  Room * newRoom;
  newRoom = malloc(sizeof(Room));
  newRoom->grid = grid;
  newRoom->numberOfDoors = numberOfDoors;
  switch (grid) {
    case 0:
      newRoom->position.x = 0;
      newRoom->position.y = 0;
      break;
    case 1:
      newRoom->position.x = 33;
      newRoom->position.y = 0;
      break;
    case 2:
      newRoom->position.x = 66;
      newRoom->position.y = 0;
      break;
    case 3:
      newRoom->position.x = 0;
      newRoom->position.y = 14;
      break;
    case 4:
      newRoom->position.x = 33;
      newRoom->position.y = 14;
      break;
    case 5:
      newRoom->position.x = 66;
      newRoom->position.y = 14;
      break;
  }

  newRoom->height = rand() % 6 + 4;
  newRoom->width = rand() % 14 + 4;

  newRoom->position.x += rand() % (30 - newRoom->width) + 1;
  newRoom->position.y += rand() % (10 - newRoom->height) + 1;

  newRoom->doors = malloc(sizeof(Door *) * numberOfDoors);

  for (int i = 0; i < numberOfDoors; i++) {
    newRoom->doors[i] = malloc(sizeof(Door));
    newRoom->doors[i]->connected = 0;
  }

  newRoom->doors[0]->position.x = rand() % (newRoom->width - 2) + newRoom->position.x + 1;
  newRoom->doors[0]->position.y = newRoom->position.y;

  newRoom->doors[1]->position.y = rand() % (newRoom->height - 2) + newRoom->position.y + 1;
  newRoom->doors[1]->position.x = newRoom->position.x;

  newRoom->doors[2]->position.x = rand() % (newRoom->width - 2) + newRoom->position.x + 1;
  newRoom->doors[2]->position.y = newRoom->position.y + newRoom->height - 1;

  newRoom->doors[3]->position.y = rand() % (newRoom->height - 2) + newRoom->position.y + 1;
  newRoom->doors[3]->position.x = newRoom->position.x + newRoom->width - 1;

  return newRoom;
}

int drawRoom(Room * room)
{
    int x;
    int y;

    /* draw top and bottom */
    for (x = room->position.x; x < room->position.x + room->width; x++)
    {
        printWithColor(room->position.y, x, '-'); /* top */
        printWithColor(room->position.y + room->height - 1, x, '-'); /* bottom */
    }

    /* draw floors and side walls */
    for (y = room->position.y + 1; y < room->position.y + room->height - 1; y++)
    {
        /* draw side walls */
        printWithColor(y, room->position.x, '|');
        printWithColor(y, room->position.x + room->width - 1, '|');

        /* draw floors */
        for (x = room->position.x + 1; x <room->position.x + room->width - 1; x++)
        {
            printWithColor(y, x, '.');
        }
    }

  if (room->grid != 0) printWithColor(room->doors[0]->position.y, room->doors[0]->position.x, '+');
  if (room->grid != 5 && room->grid != -1) printWithColor(room->doors[3]->position.y, room->doors[3]->position.x, '+');

  //gold: g, black gold: G, gorz: M, khanjar: D, asa: S, tir: A, shamshir: W, s sorat: v, s health: h, s damage: d
  if (room->grid != -1) {
  int randomItemNumber = rand() % 100;
  if (randomItemNumber % 5 == 0) {
    x = rand() % (room->width - 2) + room->position.x + 1;
    y = rand() % (room->height - 2) + room->position.y + 1;
    if (randomItemNumber > 15) printWithColor(y, x, 'g');
    else printWithColor(y, x, 'G');
  }
  if (randomItemNumber % 20 == 1) {
    x = rand() % (room->width - 2) + room->position.x + 1;
    y = rand() % (room->height - 2) + room->position.y + 1;
    printWithColor(y, x, '~');
  }
  if (randomItemNumber % 20 == 2) {
    x = rand() % (room->width - 2) + room->position.x + 1;
    y = rand() % (room->height - 2) + room->position.y + 1;
    printWithColor(y, x, ',');
  }
  if (randomItemNumber % 15 == 3) {
    x = rand() % (room->width - 2) + room->position.x + 1;
    y = rand() % (room->height - 2) + room->position.y + 1;
    printWithColor(y, x, '`');
  }
  if (randomItemNumber % 15 == 4) {
    x = rand() % (room->width - 2) + room->position.x + 1;
    y = rand() % (room->height - 2) + room->position.y + 1;
    printWithColor(y, x, 'W');
  }
  if (randomItemNumber % 15 == 5) {
    x = rand() % (room->width - 2) + room->position.x + 1;
    y = rand() % (room->height - 2) + room->position.y + 1;
    printWithColor(y, x, 'v');
  }
  if (randomItemNumber % 15 == 6) {
    x = rand() % (room->width - 2) + room->position.x + 1;
    y = rand() % (room->height - 2) + room->position.y + 1;
    printWithColor(y, x, 'h');
  }
  if (randomItemNumber % 15 == 7) {
    x = rand() % (room->width - 2) + room->position.x + 1;
    y = rand() % (room->height - 2) + room->position.y + 1;
    printWithColor(y, x, 'd');
  }
  if (randomItemNumber % 15 > 8) {
    x = rand() % (room->width - 2) + room->position.x + 1;
    y = rand() % (room->height - 2) + room->position.y + 1;
    printWithColor(y, x, 'f');
  }
  if (rand() % 4 == 1) {
    x = rand() % (room->width - 2) + room->position.x + 1;
    y = rand() % (room->height - 2) + room->position.y + 1;
    printWithColor(y, x, 'f');
  }
  if (room->grid == 5) {
    x = rand() % (room->width - 2) + room->position.x + 1;
    y = rand() % (room->height - 2) + room->position.y + 1;
    printWithColor(y, x, '?');
  }

  if (room->grid < 5) {
    if (randomItemNumber < 10) {
      x = room->position.x + 1;
      y = room->position.y + 1;
      printWithColor(y, x, 'p');
      printWithColor(room->doors[3]->position.y, room->doors[3]->position.x, 'O');
      doorPassword = rand() % 9000 + 1000;
    }
  }
  }
  else {
    int numberOfGolds = rand() % 10 + 10;
    for (int i = 0; i < numberOfGolds; i++) {
      x = rand() % (room->width - 2) + room->position.x + 1;
      y = rand() % (room->height - 2) + room->position.y + 1;
      if (rand() % 2 == 0) printWithColor(y, x, 'G');
      else printWithColor(y, x, 'g');
    }
	x = rand() % (room->width - 3) + room->position.x + 1;
    y = rand() % (room->height - 3) + room->position.y + 1;
    printWithColor(y, x, 'F');
  }
  return 1;
}

void setStartingPosition(Monster * monster, Room * room)
{
    monster->position->x = (rand() % (room->width - 2)) + room->position.x + 1;
    monster->position->y = (rand() % (room->height - 2)) + room->position.y + 1;
}