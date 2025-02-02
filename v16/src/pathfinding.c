#include "rogue.h"

void addPositionYX(int ** frontier, int frontierCount, int y, int x) {
  frontier[frontierCount][0] = y;
  frontier[frontierCount][1] = x;
}

int checkPositionPath(int y, int x) {
  char temp = (mvinch(y, x) & A_CHARTEXT);
  if (temp == '.' || temp == '|' || temp == '-') return 0;
  else return 1;
}

int addNeighbors(int ** frontier, int frontierCount,int *** cameFrom, int y, int x) {
  if (y > 0 && cameFrom[y - 1][x][0] < 0 && checkPositionPath(y - 1, x)) {
    addPositionYX(frontier, frontierCount, y - 1, x);
    frontierCount++;
    cameFrom[y - 1][x][0] = y;
    cameFrom[y - 1][x][1] = x;
  }
  if (y < (25 - 1) && cameFrom[y + 1][x][0] < 0 && checkPositionPath(y + 1, x)) {
    addPositionYX(frontier, frontierCount, y + 1, x);
    frontierCount++;
    cameFrom[y + 1][x][0] = y;
    cameFrom[y + 1][x][1] = x;
  }
  if (x < (100 - 1) && cameFrom[y][x + 1][0] < 0 && checkPositionPath(y, x + 1)) {
    addPositionYX(frontier, frontierCount, y, x + 1);
    frontierCount++;
    cameFrom[y][x + 1][0] = y;
    cameFrom[y][x + 1][1] = x;
  }
  if (x > 0 && cameFrom[y][x - 1][0] < 0 && checkPositionPath(y, x - 1)) {
    addPositionYX(frontier, frontierCount, y, x - 1);
    frontierCount++;
    cameFrom[y][x - 1][0] = y;
    cameFrom[y][x - 1][1] = x;
  }
  return frontierCount;
}

void pathFind(Position * start, Position * end)
{
  int i, j;
  int x, y;
  int tempY;
  int ** frontier = malloc(sizeof(int*) * 30 * 110);
  int *** cameFrom = malloc(sizeof(int**) * 30 );

  int frontierIndex = 0;
  int frontierCount = 0;

  for (i = 0; i < 25 * 100; i++)
  {
    frontier[i] = malloc(sizeof(int)*10);
  }

  for (i = 0; i < 25; i++)
  {
    cameFrom[i] = malloc(sizeof(int*)* 110);
    for (j = 0; j < 100; j++)
    {
      cameFrom[i][j] = malloc(sizeof(int)*44);
      cameFrom[i][j][0] = -1;
      cameFrom[i][j][1] = -1;
    }
  }

  // add start to cameFrom
  cameFrom[start->y][start->x][0] = -9;
  cameFrom[start->y][start->x][1] = -9;

  // add start position to frontier
  addPositionYX(frontier, frontierCount, start->y, start->x);
  frontierCount++;


  while (frontierIndex < frontierCount)
  {
    y = frontier[frontierIndex][0];
    x = frontier[frontierIndex][1];

    frontierIndex++;

    if (y == end->y && x == end->x)
    {
      break;
    }

    frontierCount = addNeighbors(frontier, frontierCount, cameFrom, y, x);
  }

  y = end->y;
  x = end->x;

  while (y != start->y || x != start->x)
  {
    tempY = y;
    y = cameFrom[tempY][x][0];
    x = cameFrom[tempY][x][1];
    if ((mvinch(y, x) & A_CHARTEXT) != '+' && (mvinch(y, x) & A_CHARTEXT) != 'O') {
      attron(A_BOLD);
      attron(A_DIM);
      attron(COLOR_PAIR(1));
      mvprintw(y, x, "#");
      attroff(A_BOLD);
      attroff(A_DIM);
      attroff(COLOR_PAIR(1));
    }
    //getch();
  }

}