#include "rogue.h"

int difficulty = 12;
char musicName[50] = "music1.mp3";

void characterSetting() {
}


void difficultySetting() {
    clear();
    refresh();
    
    const char *difficultyChoices[] = {"easy", "medium", "hard"};
    int numChoices = 3;

    int currentIndex = 0;
    int c;

    WINDOW *menu_win = newwin(10, 40, LINES / 2 - 5, COLS / 2 - 20);
    box(menu_win, 0, 0);
    wrefresh(menu_win);

    while (1) {
        for (int i = 0; i < numChoices; i++) {
            if (i == currentIndex) {
                wattron(menu_win, A_REVERSE);
                mvwprintw(menu_win, i + 1, 2, "%s", difficultyChoices[i]);
                wattroff(menu_win, A_REVERSE);
            } else {
                mvwprintw(menu_win, i + 1, 2, "%s", difficultyChoices[i]);
            }
        }
        wrefresh(menu_win);

        c = wgetch(menu_win);
        switch (c) {
            refresh();
            case KEY_DOWN:
                currentIndex = (currentIndex + 1) % numChoices;
                break;
            case KEY_UP:
                currentIndex = (currentIndex - 1 + numChoices) % numChoices;
                break;
            case 10: // Enter key
                if (currentIndex == 0) {
                    difficulty = 6;
                } else if (currentIndex == 1) {
                    difficulty = 7;
                } else {
                    difficulty = 8;
                }
                delwin(menu_win);
                return;
        }
    }
}



void settingNavigator(int choice) {
    if (choice == 1) {
        clear();
        refresh();
    
        char *colorChoices[] = {"While", "Yellow", "Cyan", "Green"};
    
        ITEM **colorItems = (ITEM **)calloc(5, sizeof(ITEM *));

        for (int i = 0; i < 4; i++) {
            colorItems[i] = new_item(colorChoices[i], "");
        }

        MENU *colorMenu = new_menu(colorItems);

        keypad(stdscr, TRUE);
        set_menu_win(colorMenu, stdscr);
        set_menu_sub(colorMenu, derwin(stdscr, 15, 40, 1, 1));
        set_menu_format(colorMenu, 4, 1);
        post_menu(colorMenu);

        int c;
        int flag = 1;
        int currentIndex = -1;

        while (flag) {
            c = getch();
            switch (c) {
                refresh();
                case KEY_DOWN:
                    menu_driver(colorMenu, REQ_DOWN_ITEM);
                    break;
                case KEY_UP:
                    menu_driver(colorMenu, REQ_UP_ITEM);
                    break;
                case 10:
                    ITEM *currentItem = current_item(colorMenu);
                    currentIndex = item_index(currentItem);
                    clear();
                    refresh();
                    flag = 0;
                    break;
            }
        }

    if (currentIndex == 0) {
        characterColor = 1;
        clear();
        refresh();
        preGameMenu();
    } else if (currentIndex == 1) {
        characterColor = 2;
        clear();
        refresh();
        preGameMenu();
    } else if (currentIndex == 2) {
        characterColor = 3;
        clear();
        refresh();
        preGameMenu();
    }
    else {
        characterColor = 4;
        clear();
        refresh();
        preGameMenu();
    }

    // unpost_menu(settingMenu1);
    // for (int i = 0; i < 3; i++) {
    //     free_item(settingItems1[i]);
    // }
    // free_menu(settingMenu1);
    // free(settingItems1);

    }
    if (choice == 0) {
        //difficultySetting();
        clear();
        refresh();
    
        char *difficultyChoices[] = {"easy", "medium", "hard"};
    
        ITEM **settingItems1 = (ITEM **)calloc(5, sizeof(ITEM *));

        for (int i = 0; i < 3; i++) {
            settingItems1[i] = new_item(difficultyChoices[i], "");
        }

        MENU *settingMenu1 = new_menu(settingItems1);

        keypad(stdscr, TRUE);
        set_menu_win(settingMenu1, stdscr);
        set_menu_sub(settingMenu1, derwin(stdscr, 15, 40, 1, 1));
        set_menu_format(settingMenu1, 3, 1);
        post_menu(settingMenu1);

        int c;
        int flag = 1;
        int currentIndex = -1;

        while (flag) {
            c = getch();
            switch (c) {
                refresh();
                case KEY_DOWN:
                    menu_driver(settingMenu1, REQ_DOWN_ITEM);
                    break;
                case KEY_UP:
                    menu_driver(settingMenu1, REQ_UP_ITEM);
                    break;
                case 10:
                    ITEM *currentItem = current_item(settingMenu1);
                    currentIndex = item_index(currentItem);
                    clear();
                    refresh();
                    flag = 0;
                    break;
            }
        }

    if (currentIndex == 0) {
        difficulty = 15;
        clear();
        refresh();
        preGameMenu();
    } else if (currentIndex == 1) {
        difficulty = 12;
        clear();
        refresh();
        preGameMenu();
    } else {
        difficulty = 9;
        clear();
        refresh();
        preGameMenu();
    }

    unpost_menu(settingMenu1);
    for (int i = 0; i < 3; i++) {
        free_item(settingItems1[i]);
    }
    free_menu(settingMenu1);
    free(settingItems1);

    }
    if (choice == 2) {
        clear();
        refresh();
        mvprintw(1,1, "Music 1: Press 1                                ");
        mvprintw(2,1, "Music 2: Press 2                                  ");
        mvprintw(3,1, "Music 3: Press 3"                                 );
        mvprintw(4,1, "Silent:  Press 4"                                 );
        int ccch = getch();
        if (ccch == '4') {
            strcpy(musicName, "N");
        }
        else if (ccch == '2') {
            strcpy(musicName, "music2.mp3");
        }
        else if (ccch == '3') {
            strcpy(musicName, "music3.mp3");
        }
        else {
            strcpy(musicName, "N");
        }
        mainMenu();
    }
}

void userSettings() {
    clear();
    refresh();
    
    char *settingChoices[] = {"Difficulty", "Character Setting", "Musics"};
    ITEM **settingItems = (ITEM **)calloc(5, sizeof(ITEM *));
    if (!settingItems) {
        clear();
        mvprintw(LINES / 2, COLS / 2 - 10, "Memory allocation failed!");
        refresh();
        getch();
        endwin();
        exit(1);
    }

    for (int i = 0; i < 3; i++) {
        settingItems[i] = new_item(settingChoices[i], "");
        if (!settingItems[i]) {
            clear();
            mvprintw(LINES / 2, COLS / 2 - 15, "Failed to create item: %s", settingChoices[i]);
            refresh();
            getch();
            endwin();
            exit(1);
        }
    }

    MENU *settingMenu = new_menu(settingItems);
    if (!settingMenu) {
        clear();
        mvprintw(LINES / 2, COLS / 2 - 10, "Failed to create menu");
        refresh();
        getch();
        endwin();
        exit(1);
    }

    keypad(stdscr, TRUE);
    set_menu_win(settingMenu, stdscr);
    set_menu_sub(settingMenu, derwin(stdscr, 15, 40, 1, 1));
    set_menu_format(settingMenu, 13, 1);
    post_menu(settingMenu);

    int c;
    int flag = 1;
    while (flag) {
        c = getch();
        switch (c) {
            refresh();
            refresh();
            case KEY_DOWN:
                menu_driver(settingMenu, REQ_DOWN_ITEM);
                break;
            case KEY_UP:
                menu_driver(settingMenu, REQ_UP_ITEM);
                break;
            case 10:
                ITEM *currentItem = current_item(settingMenu);
                int currentIndex = item_index(currentItem);
                clear();
                refresh();
                settingNavigator(currentIndex);
                flag = 0;
                break;
        }
    }

    unpost_menu(settingMenu);
    for (int i = 0; i < 2; i++) {
        free_item(settingItems[i]);
    }
    free_menu(settingMenu);
    free(settingItems);
}


void printChar(int y, int x) {
    switch (characterColor) {
        case 1:
            attron(COLOR_PAIR(1));
            attron(A_BOLD);
            mvprintw(y, x, "@");
            attroff(A_BOLD);
            attroff(COLOR_PAIR(1));
            break;
        case 2:
            attron(COLOR_PAIR(2));
            attron(A_BOLD);
            mvprintw(y, x, "@");
            attroff(A_BOLD);
            attroff(COLOR_PAIR(2));
            break;
        case 3:
            attron(COLOR_PAIR(3));
            attron(A_BOLD);
            mvprintw(y, x, "@");
            attroff(A_BOLD);
            attroff(COLOR_PAIR(3));
            break;
        case 4:
            attron(COLOR_PAIR(4));
            attron(A_BOLD);
            mvprintw(y, x, "@");
            attroff(A_BOLD);
            attroff(COLOR_PAIR(4));
            break;
        case 5:
            attron(COLOR_PAIR(5));
            attron(A_BOLD);
            mvprintw(y, x, "@");
            attroff(A_BOLD);
            attroff(COLOR_PAIR(5));
            break;
        case 6:
            attron(COLOR_PAIR(6));
            attron(A_BOLD);
            mvprintw(y, x, "@");
            attroff(A_BOLD);
            attroff(COLOR_PAIR(6));
            break;
        case 7:
            attron(COLOR_PAIR(7));
            attron(A_BOLD);
            mvprintw(y, x, "@");
            attroff(A_BOLD);
            attroff(COLOR_PAIR(7));
            break;
        
    }

}
