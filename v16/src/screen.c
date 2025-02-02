#include "rogue.h"

int totalHealth = 1000;
int lastPrintedLine = 26;

int screenSetUp()
{
    initscr();
    cbreak();
    noecho();
    refresh();
    srand(time(NULL));
    return 1;
}


int printGameHub(Level * level) {
  int healthBlocksTotal = totalHealth / 20;
  int heathBlocksNow = level->user->health / healthBlocksTotal + 1;
  attron(COLOR_PAIR(2));
  attron(A_BOLD);
  mvprintw(2, 102, "Health:   ");
  attroff(A_BOLD);
  attroff(COLOR_PAIR(2));
  if (heathBlocksNow > 3) {
    for (int i = 0; i < heathBlocksNow && i < 20; i++) {
      attron(COLOR_PAIR(4));
      attron(A_BOLD);
      printw("|");
      attroff(A_BOLD);
      attroff(COLOR_PAIR(4));
    }
  }
  else {
    for (int i = 0; i < heathBlocksNow && i < 20; i++) {
      attron(COLOR_PAIR(6));
      attron(A_BOLD);
      printw("|");
      attroff(A_BOLD);
      attroff(COLOR_PAIR(6));
    }
  }
  for (int i = heathBlocksNow; i < 20; i++) {
    attron(COLOR_PAIR(1));
    attron(A_BOLD);
    printw("|");
    attroff(A_BOLD);
    attroff(COLOR_PAIR(1));
  }
  attron(COLOR_PAIR(2));
  attron(A_BOLD);
  mvprintw(3, 102, "Gold:  ");
  attroff(A_BOLD);
  attroff(COLOR_PAIR(2));
  attron(COLOR_PAIR(1));
  attron(A_BOLD);
  printw("%d", level->user->gold);
  attroff(A_BOLD);
  attroff(COLOR_PAIR(1));
  attron(COLOR_PAIR(2));
  attron(A_BOLD);
  mvprintw(4, 102, "Level: ");
  attroff(A_BOLD);
  attroff(COLOR_PAIR(2));
  attron(COLOR_PAIR(1));
  attron(A_BOLD);
  printw("%d", level->level);
  attroff(A_BOLD);
  attroff(COLOR_PAIR(1));

  attron(COLOR_PAIR(7));
  for (int i = 1; i < 5; i++) {
    mvprintw(26, i, "_");
  }
  printw(" message ");
  for (int i = 0; i < 80; i++) {
    printw("_");
  }
  for (int i = 1; i < 94; i++) {
    mvprintw(30, i, "_");
  }
  for (int i = 0; i < 4; i++) {
    mvprintw(i+27, 0, "|");
    mvprintw(i+27, 94, "|");
  }

  for (int i = 101; i < 134; i++) {
    mvprintw(0, i, "_");
    mvprintw(5, i , "_");
    mvprintw(17, i, "_");
    mvprintw(30, i, "_");
  }

  for (int i = 1; i < 31; i++) {
    mvprintw(i, 100, "|");
    mvprintw(i, 134, "|");
  }

  attroff(COLOR_PAIR(7));

  attron(COLOR_PAIR(2));
  attron(A_BOLD);
  mvprintw(26, 6, "message");
  attroff(A_BOLD);
  attroff(COLOR_PAIR(2));

  attron(COLOR_PAIR(1));
  attron(A_BOLD);
  attron(A_UNDERLINE);
  attron(A_DIM);
  mvprintw(6, 102, "Guides:");
  attroff(COLOR_PAIR(1));
  attroff(A_BOLD);
  attroff(A_UNDERLINE);
  attroff(A_DIM);

  attron(COLOR_PAIR(3));
  attron(A_BOLD);
  mvprintw(8, 102, "Movement:");
  attroff(COLOR_PAIR(3));
  attroff(A_BOLD);

  attron(COLOR_PAIR(1));
  attron(A_DIM);
  mvprintw(8, 113, "Q W E");
  mvprintw(9, 113, "A @ D");
  mvprintw(10, 113, "Z X C");
  attroff(COLOR_PAIR(1));
  attroff(A_DIM);

  attron(COLOR_PAIR(3));
  attron(A_BOLD);
  mvprintw(12, 102, "Auto Run:");
  attroff(COLOR_PAIR(3));
  attroff(A_BOLD);

  attron(COLOR_PAIR(1));
  attron(A_DIM);
  mvprintw(12, 113, "CTRL");
  attroff(COLOR_PAIR(1));
  attroff(A_DIM);

  attron(COLOR_PAIR(1));
  printw(" + ");
  attroff(COLOR_PAIR(1));

  attron(COLOR_PAIR(1));
  attron(A_DIM);
  printw("Arrow Keys");
  attroff(COLOR_PAIR(1));
  attroff(A_DIM);  

  attron(COLOR_PAIR(3));
  attron(A_BOLD);
  mvprintw(14, 102, "Menus:");
  attroff(COLOR_PAIR(3));
  attroff(A_BOLD);

  attron(COLOR_PAIR(1));
  attron(A_DIM);
  mvprintw(14, 113, "G  T  F");
  attroff(COLOR_PAIR(1));
  attroff(A_DIM);  

  attron(COLOR_PAIR(3));
  attron(A_BOLD);
  mvprintw(16, 102, "Exit:");
  attroff(COLOR_PAIR(3));
  attroff(A_BOLD);

  attron(COLOR_PAIR(1));
  attron(A_DIM);
  mvprintw(16, 113, "ESC");
  attroff(COLOR_PAIR(1));
  attroff(A_DIM);   

  refresh();
  return 1;
}

void clearLine(int line) {
  mvprintw(line, 1, "                                                                            ");
}

int emptyLine() {
  lastPrintedLine++;
  if (lastPrintedLine > 29) lastPrintedLine = 27;
  if (mvinch(27, 2) == ' ') return 27;
  if (mvinch(28, 2) == ' ') return 28;
  if (mvinch(29, 2) == ' ') return 29;
  else return lastPrintedLine;
}

void printWithColor(int y, int x, char ch) {
  switch (ch) {
    case ',':
    case '`':
    case '~':
      attron(A_BOLD);
      attron(A_UNDERLINE);
      attron(COLOR_PAIR(2));
      mvprintw(y, x, "%c", ch);
      attroff(A_BOLD);
      attroff(A_UNDERLINE);
      attroff(COLOR_PAIR(2));
      break;
    case 'W':
      attron(A_BOLD);
      attron(COLOR_PAIR(1));
      mvprintw(y, x, "%c", ch);
      attroff(A_BOLD);
      attroff(COLOR_PAIR(1));
      break;
    case 'f':
      attron(COLOR_PAIR(5));
      mvprintw(y, x, "%c", ch);
      attroff(COLOR_PAIR(5));
      break;
    case 'F':
      attron(A_BOLD);
      attron(COLOR_PAIR(3));
      mvprintw(y, x, "%c", ch);
      attroff(A_BOLD);
      attroff(COLOR_PAIR(3));
      break;
    case 'U':
      attron(A_BOLD);
      attron(COLOR_PAIR(4));
      mvprintw(y, x, "%c", ch);
      attroff(A_BOLD);
      attroff(COLOR_PAIR(4));
      break;
    case '1':
    case '0':
    case '2':
    case '3':
    case '4':
      attron(A_BOLD);
      attron(COLOR_PAIR(6));
      mvprintw(y, x, "%c", ch);
      attroff(A_BOLD);
      attroff(COLOR_PAIR(6));
      break;
    case '|':
    case '-':
      attron(A_BOLD);
      attron(COLOR_PAIR(1));
      mvprintw(y, x, "%c", ch);
      attroff(A_BOLD);
      attroff(COLOR_PAIR(1));
      break;
    case '+':
      attron(A_BOLD);
      attron(A_DIM);
      attron(COLOR_PAIR(5));
      mvprintw(y, x, "%c", ch);
      attroff(A_BOLD);
      attroff(A_DIM);
      attroff(COLOR_PAIR(5));
      break;
    case '.':
      attron(A_DIM);
      attron(COLOR_PAIR(1));
      mvprintw(y, x, "%c", ch);
      attroff(A_DIM);
      attroff(COLOR_PAIR(1));
      break;
    case '#':
      attron(A_BOLD);
      attron(COLOR_PAIR(1));
      attron(A_DIM);
      mvprintw(y, x, "%c", ch);
      attroff(A_DIM);
      attroff(A_BOLD);
      attroff(COLOR_PAIR(1));
      break;
    case 'O':
      attron(A_BOLD);
      attron(COLOR_PAIR(6));
      mvprintw(y, x, "%c", ch);
      attroff(A_BOLD);
      attroff(COLOR_PAIR(6));
      break;
    case 'p':
      attron(COLOR_PAIR(2));
      mvprintw(y, x, "%c", ch);
      attroff(COLOR_PAIR(2));
      break;
    case 'h':
    case 'v':
    case 'd':
      break;
    case '?':
      attron(A_BOLD);
      attron(COLOR_PAIR(3));
      mvprintw(y, x, "%c",ch);
      attroff(A_BOLD);
      attroff(COLOR_PAIR(3));
      break;
    case 'G':
    case 'g':
      attron(A_BOLD);
      attron(COLOR_PAIR(2));
      mvprintw(y, x, "%c",ch);
      attroff(A_BOLD);
      attroff(COLOR_PAIR(2));
      break;
  }
}
  /*
      attron(A_BOLD);
      attron(A_UNDERLINE);
      attron(COLOR_PAIR(2));

      attroff(A_BOLD);
      attroff(A_UNDERLINE);
      attroff(COLOR_PAIR(2));


      attron(A_BOLD);
      attron(COLOR_PAIR(1));

      attroff(A_BOLD);
      attroff(COLOR_PAIR(1));


      attron(COLOR_PAIR(5));

      attroff(COLOR_PAIR(5));


      attron(A_BOLD);
      attron(COLOR_PAIR(3));

      attroff(A_BOLD);
      attroff(COLOR_PAIR(3));


      attron(A_BOLD);
      attron(COLOR_PAIR(4));

      attroff(A_BOLD);
      attroff(COLOR_PAIR(4));


      attron(A_BOLD);
      attron(COLOR_PAIR(6));

      attroff(A_BOLD);
      attroff(COLOR_PAIR(6));


      attron(A_DIM);
      attron(COLOR_PAIR(1));

      attroff(A_DIM);
      attroff(COLOR_PAIR(1));


      attron(A_BOLD);
      attron(COLOR_PAIR(1));

      attroff(A_BOLD);
      attroff(COLOR_PAIR(1));


      attron(A_BOLD);
      attron(A_DIM);
      attron(COLOR_PAIR(5));

      attroff(A_BOLD);
      attroff(A_DIM);
      attroff(COLOR_PAIR(5));

      message
      .
      attron(A_DIM);
      attron(COLOR_PAIR(1));

      attroff(A_DIM);
      attroff(COLOR_PAIR(1));


      attron(A_BOLD);
      attron(COLOR_PAIR(1));

      attroff(A_BOLD);
      attroff(COLOR_PAIR(1));


      attron(A_BOLD);
      attron(COLOR_PAIR(6));

      attroff(A_BOLD);
      attroff(COLOR_PAIR(6));


      attron(COLOR_PAIR(4));

      attroff(COLOR_PAIR(4));


      attron(COLOR_PAIR(2));

      attroff(COLOR_PAIR(2));


      attron(A_BOLD);
      attron(COLOR_PAIR(3));

      attroff(A_BOLD);
      attroff(COLOR_PAIR(3));
  */














