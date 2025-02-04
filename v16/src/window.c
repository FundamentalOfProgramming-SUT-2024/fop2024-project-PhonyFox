#include "rogue.h"

int windowMaker() {
  WINDOW * window = newwin(7, 26, 19, 103);
  box(window, 0, 0);
  wrefresh(window);
  mvwprintw(window, 1, 1, "Enter The Password:");
  wrefresh(window);
  int password = 0;
  int ch;
  wmove(window, 2, 1);
  ch = wgetch(window);
  password += (ch-48) * 1000;
  waddch(window, ch);
  wrefresh(window);
  ch = wgetch(window);
  password += (ch-48) * 100;
  waddch(window, ch);
  wrefresh(window);
  ch = wgetch(window);
  password += (ch-48) * 10;
  waddch(window, ch);
  wrefresh(window);
  ch = wgetch(window);
  password += (ch-48) * 1;
  waddch(window, ch);
  wrefresh(window);
  if (password == doorPassword) {
    passwordChances = 3;
    mvwprintw(window, 3, 1, "Password is Correct!");
    mvwprintw(window, 4, 1, "press any key to exit");
    wrefresh(window);
    getch();
    werase(window);
    wrefresh(window);
    delwin(window);
    refresh();
    return 1;
  }
  else {
    passwordChances--;
    mvwprintw(window, 3, 1, "Password is wrong!");
    switch(passwordChances) {
      case 2:
        clearLine(emptyLine());
        attron(A_DIM);
        attron(COLOR_PAIR(4));
        mvprintw(emptyLine(), 2, "You have two chances!");
        attroff(A_DIM);
        attroff(COLOR_PAIR(4));
        break;
      case 1:
        clearLine(emptyLine());
        attron(A_DIM);
        attron(COLOR_PAIR(2));
        mvprintw(emptyLine(), 2, "You have one chance!");
        attroff(A_DIM);
        attroff(COLOR_PAIR(2));
        break;
      case 0:
        clearLine(emptyLine());
        attron(A_DIM);
        attron(COLOR_PAIR(6));
        mvprintw(emptyLine(), 2, "Security mode activated.");
        attroff(A_DIM);
        attroff(COLOR_PAIR(6));
        break;
    }
    mvwprintw(window, 5, 1, "press any key to exit");
    wrefresh(window);
    getch();
    werase(window);
    wrefresh(window);
    delwin(window);
    refresh();
    return 0;
  }
}