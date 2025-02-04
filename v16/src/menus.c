#include "rogue.h"

char currentUserLogin[50];
int isGeust = 0;


void profileMenu() {
    FILE *file;
    char filename[100];
    char username[100], email[100], password[100];
    
    snprintf(filename, sizeof(filename), "%s.txt", currentUserLogin);
    file = fopen(filename, "r");

    if (file == NULL) return;

    fgets(username, sizeof(username), file);
    username[strcspn(username, "\n")] = '\0';

    fgets(email, sizeof(email), file);
    email[strcspn(email, "\n")] = '\0';

    fgets(password, sizeof(password), file);
    password[strcspn(password, "\n")] = '\0';

    fclose(file);

    mvprintw(1, 1, "%s", username);
    mvprintw(2, 1, "%s", email);
    refresh();
    int ch = getch();
    mvprintw(3,1, "Press [P] To Show Your Password, Esc To Exit");
    while ((ch = getch()) != 27) {
        if (ch == 'p') mvprintw(3,1,"%s                                             ", password);
        refresh();
    }
    preGameMenu();
}

void preWin(int choice) {
	if (choice == 0) {
		clear();
        refresh();
        attron(A_BOLD);
        attron(COLOR_PAIR(1));
        mvprintw(1, 2, "Press any key to start...");
        attroff(A_BOLD);
        attroff(COLOR_PAIR(1));
        getch();
        clear();
        refresh();
        isGeust = 0;
        mainGameLoop();
        return;
	}
	if (choice == 1) {
          resumeGameProccess();
		}
	if (choice == 2) {
          userSettings();
	}
	if (choice == 3) {
        rankUsersByScore();
	}
    if (choice == 4) {
        profileMenu();
    }
}


void preGameMenu() {
	clear();
	refresh();
	char *preChoices[] = {"New Game", "Resume Game", "Settings", "Scoreboard", "Profile"};
	ITEM **preItems = (ITEM **)calloc(10, sizeof(ITEM *));
	for (int i = 0; i < 5; i++) {
		preItems[i] = new_item(preChoices[i], "");
	}

	MENU *preMenu = new_menu(preItems);
	keypad(stdscr, TRUE);
    set_menu_win(preMenu, stdscr);
    set_menu_sub(preMenu, derwin(stdscr, 15, 40, 1, 1));
    set_menu_format(preMenu, 13, 1);
    post_menu(preMenu);

	int c;
    int flag = 1;
    while (flag) {
        c = getch();
        switch (c) {
            case KEY_DOWN:
                menu_driver(preMenu, REQ_DOWN_ITEM);
            break;
            case KEY_UP:
                menu_driver(preMenu, REQ_UP_ITEM);
            break;
            case 10:
                ITEM * currentItem = current_item(preMenu);
                int currentIndex = item_index(currentItem);
                clear();
                refresh();
                preWin(currentIndex);
                flag = 0;
                break;
        }
    }
}

int isItItself(const char * password, const char * username) {
    FILE *file;
    char filename[100], line[256], storedPassword[50];
    snprintf(filename, sizeof(filename), "%s.txt", username);
    file = fopen(filename, "r");
    if (!file) return 0;
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Password:", 9) == 0) {
            sscanf(line + 9, " %49s", storedPassword);
            break;
        }
    }

    fclose(file);
    return strcmp(storedPassword, password) == 0;
}

void loginWin(int choice) {
    if (choice == 0) {
        clear();
        refresh();

        User user;

        
        attron(A_BOLD);
        attron(COLOR_PAIR(1));
        mvprintw(1, 2, "===      Login      ===");
        attroff(A_BOLD);
        attroff(COLOR_PAIR(1));

        attron(A_BOLD);
        attron(COLOR_PAIR(1));
        mvprintw(3, 2, "Enter your username: ");
        attroff(A_BOLD);
        attroff(COLOR_PAIR(1));

        
        echo();
        getnstr(user.username, sizeof(user.username) - 1);
        noecho();

        attron(A_BOLD);
        attron(COLOR_PAIR(1));
        mvprintw(5, 2, "Enter password: ");
        attroff(A_BOLD);
        attroff(COLOR_PAIR(1));
        
        echo();
        getnstr(user.password, sizeof(user.password) - 1);
        noecho();

        if (isItItself(user.password, user.username)) {
            strcpy(currentUserLogin, user.username);
          	preGameMenu();
            return;
        }
        else {
            clear();
            refresh();
            attron(A_BOLD);
            attron(COLOR_PAIR(1));
            mvprintw(1, 2, "Invalid username or password, Press [y] To Recover");
            int chy = getch();
            if (chy == 'y') {
                mvprintw(2, 2, "Press The Secret Key:");
                chy = getch();
                if (chy == 'p') {
                FILE *file;
                char filename[100], line[256], storedPassword[50];
                snprintf(filename, sizeof(filename), "%s.txt", user.username);
                file = fopen(filename, "r");
                if (!file) {
                    mvprintw(2,2, "You Havo Not Made An Account");
                    getch();
                    mainMenu();
                }
                while (fgets(line, sizeof(line), file)) {
                    if (strncmp(line, "Password:", 9) == 0) {
                        sscanf(line + 9, " %49s", storedPassword);
                        break;
                    }
                }
                mvprintw(2,2,"Your %s", line);
                fclose(file);
                }

            }

            attroff(A_BOLD);
            attroff(COLOR_PAIR(1));
            getch();
            clear();
            refresh();
            mainMenu();
            return;
        }
    }
    else {
        clear();
        refresh();
        attron(A_BOLD);
        attron(COLOR_PAIR(1));
        mvprintw(1, 2, "Press any key to start...");
        attroff(A_BOLD);
        attroff(COLOR_PAIR(1));
        getch();
        clear();
        refresh();
        isGeust = 1;
        mainGameLoop();
        return;
    }
}

void loginUserMenu() {
    clear();
    refresh();
    char *loginChoices[] = {"Login", "Guest"};
    ITEM **loginItems = (ITEM **)calloc(2, sizeof(ITEM *));
    for (int i = 0; i < 2; i++) {
        loginItems[i] = new_item(loginChoices[i], "");
    }
    MENU * loginMenu = new_menu(loginItems);
    keypad(stdscr, TRUE);
    set_menu_win(loginMenu, stdscr);
    set_menu_sub(loginMenu, derwin(stdscr, 15, 40, 1, 1));
    set_menu_format(loginMenu, 13, 1);
    post_menu(loginMenu);

    int c;
    int flag = 1;
    while (flag) {
        c = getch();
        switch (c) {
            case KEY_DOWN:
                menu_driver(loginMenu, REQ_DOWN_ITEM);
            break;
            case KEY_UP:
                menu_driver(loginMenu, REQ_UP_ITEM);
            break;
            case 10:
                ITEM * currentItem = current_item(loginMenu);
                int currentIndex = item_index(currentItem);
                clear();
                refresh();
                loginWin(currentIndex);
                flag = 0;
                break;
        }
    }
    endwin();
}

int isValidUsername(const char *username) {
    FILE *file;
    char filename[100];
    snprintf(filename, sizeof(filename), "%s.txt", username);

    file = fopen(filename, "r");
    if (file != NULL) {
      	fclose(file);
        return 0;
    }
    return 1;
}

int isValidPassword(const char *password) {
    if (strlen(password) < 7) return 0;
    int hasUpper = 0, hasLower = 0, hasDigit = 0;
    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i])) hasUpper = 1;
        if (islower(password[i])) hasLower = 1;
        if (isdigit(password[i])) hasDigit = 1;
    }

    return hasUpper && hasLower && hasDigit;
}

int isValidEmail(const char *email) {
    int atCount = 0, dotCount = 0;
    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') atCount++;
        for (int j = i; email[j] != '\0'; j++) {
            if (email[i] == '.') dotCount++;
        }
    }
    return atCount == 1 && dotCount >= 1;
}

int saveUser(User *user) {
    FILE *file;
    char filename[100];
    snprintf(filename, sizeof(filename), "%s.txt", user->username);

    file = fopen(filename, "w");
    if (file == NULL) {
        clear();
        refresh();
        attron(A_BOLD);
        attron(COLOR_PAIR(1));
        mvprintw(1, 2, "Error creating user file!");
        attroff(A_BOLD);
        attroff(COLOR_PAIR(1));
        refresh();
        getch();
        mainMenu();
        return 0;
    }

    fprintf(file, "Username: %s\n", user->username);
    fprintf(file, "Email: %s\n", user->email);
    fprintf(file, "Password: %s\n", user->password);
    fprintf(file, "%ld\n", time(NULL)/86400);
    fclose(file);
    return 1;
}

void createPlayerMenu() {
    clear();
    refresh();

    User user;
    attron(A_BOLD);
    attron(COLOR_PAIR(1));
    mvprintw(1, 2, "=== Create New User ===");
    mvprintw(3, 2, "Enter username: ");
    attroff(A_BOLD);
    attroff(COLOR_PAIR(1));
    

    
    echo();
    getnstr(user.username, sizeof(user.username) - 1);
    noecho();

    if (!isValidUsername(user.username)) {
        clear();
        refresh();
        attron(A_BOLD);
        attron(COLOR_PAIR(1));
        mvprintw(1, 2, "Invalid Username or Username already exists.");
        attroff(A_BOLD);
        attroff(COLOR_PAIR(1));
        getch();
        clear();
        refresh();
        mainMenu();
        return;
    }

    
    attron(A_BOLD);
    attron(COLOR_PAIR(1));
    mvprintw(5, 2, "Do You Want To Make It RandomLy? [ y or n ]                                               ");
    while (1) {
        int ch = getch();
        if (ch == 'y') {
        const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
        const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const char digits[] = "0123456789";
        const char all_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

        srand(time(NULL));

        user.password[0] = lowercase[rand() % (sizeof(lowercase) - 1)];
        user.password[1] = uppercase[rand() % (sizeof(uppercase) - 1)];
        user.password[2] = digits[rand() % (sizeof(digits) - 1)];

        for (int i = 3; i < 10; i++) {
            user.password[i] = all_chars[rand() % (sizeof(all_chars) - 1)];
        }

        for (int i = 0; i < 10; i++) {
            int randIndex = rand() % 10;
            char temp = user.password[i];
            user.password[i] = user.password[randIndex];
            user.password[randIndex] = temp;
        }

        user.password[10] = '\0';
        mvprintw(5, 2, "Your Password Is: %s                                                  ", user.password);
        break;
        }
        else if (ch == 'n') {
            mvprintw(5, 2, "                                                                                                                       ");
            mvprintw(5, 2, "Enter password: ");
            attroff(A_BOLD);
            attroff(COLOR_PAIR(1));
            echo();
            getnstr(user.password, sizeof(user.password) - 1);
            noecho();
            break;
        }
    }
    // mvprintw(5, 2, "                                                                                                                       ");
    // mvprintw(5, 2, "Enter password: ");
    // attroff(A_BOLD);
    // attroff(COLOR_PAIR(1));
    // echo();
    // getnstr(user.password, sizeof(user.password) - 1);
    // noecho();

    if (!isValidPassword(user.password)) {
        clear();
        refresh();
        attron(A_BOLD);
        attron(COLOR_PAIR(1));
        mvprintw(5, 2, "Invalid Password. Must be at least 7 characters, with one uppercase, one lowercase letter, and a digit.");
        attroff(A_BOLD);
        attroff(COLOR_PAIR(1));
        refresh();
        getch();
        clear();
        refresh();
        mainMenu();
        return;
    }

    attron(A_BOLD);
    attron(COLOR_PAIR(1));
    mvprintw(7, 2, "Enter email: ");
    attroff(A_BOLD);
    attroff(COLOR_PAIR(1));
    echo();
    getnstr(user.email, sizeof(user.email) - 1);
    noecho();

    if (!isValidEmail(user.email)) {
        clear();
        refresh();
        attron(A_BOLD);
        attron(COLOR_PAIR(1));
        mvprintw(5, 2, "Invalid Email format.");
        refresh();
        attroff(A_BOLD);
        attroff(COLOR_PAIR(1));
        getch();
        refresh();
        mainMenu();
        return;
    }

    if (!saveUser(&user)) {
        return;
    } else {
      	clear();
        refresh();
        attron(A_BOLD);
        attron(COLOR_PAIR(1));
        mvprintw(5, 2, "User was created successfully.");
        char leaderboard_line[150];
        // snprintf(file1, sizeof(file1), "%s.txt", user.username);
        // snprintf(file2, sizeof(file2), "%sMAP.txt", user.username);

        // FILE *f1 = fopen(file1, "w");
        // fclose(f1);

        // FILE *f2 = fopen(file2, "w");
        // fclose(f2);

        snprintf(leaderboard_line, sizeof(leaderboard_line), "%s,0,0,0,0,%ld\n", user.username, time(NULL)/86400);
        FILE *leaderboard = fopen("LEADERBOARD.txt", "a");
        fputs(leaderboard_line, leaderboard);
        fclose(leaderboard);
        attroff(A_BOLD);
        attroff(COLOR_PAIR(1));
        //makeUserMapFile(user.username);
        getch();
        clear();
        refresh();
        mainMenu();
        return;
    }
}



void newWin(int choice) {
    if (choice == 0) {
      createPlayerMenu();
    }
    else if (choice == 3) {
      endwin();
      exit(0);
    }
    else if (choice == 1) {
      loginUserMenu();
    }
    else if (choice == 2) {
        rankUsersByScore();
    }
    refresh();
    getch();
}

void mainMenu() {
    play_or_replace_music(musicName);
    clear();
    char *mainChoices[] = {
        "Create New User",
        "Login User",
        "Leaderboard",
        "Exit"
    };
    int mainMenuChoices = 4;
    ITEM **mainMenuItems = (ITEM **)calloc(mainMenuChoices, sizeof(ITEM *));


    for (int i = 0; i < mainMenuChoices; i++) {
        mainMenuItems[i] = new_item(mainChoices[i], "");
    }

    MENU * mainMenu = new_menu(mainMenuItems);
	keypad(stdscr, TRUE);
    set_menu_win(mainMenu, stdscr);
    set_menu_sub(mainMenu, derwin(stdscr, 15, 40, 1, 1));
    set_menu_format(mainMenu, 13, 1);
    post_menu(mainMenu);
    refresh();
    int c;
    int flag = 1;
    while (flag) {
        c = getch();
        switch (c) {
            refresh();
            case KEY_DOWN:
                menu_driver(mainMenu, REQ_DOWN_ITEM);
                break;
            case KEY_UP:
                menu_driver(mainMenu, REQ_UP_ITEM);
                break;
            case 10:
                ITEM * currentItem = current_item(mainMenu);
                int currentIndex = item_index(currentItem);
                clear();
                refresh();
                newWin(currentIndex);
                flag = 0;
                break;
        }
    }
    endwin();
}