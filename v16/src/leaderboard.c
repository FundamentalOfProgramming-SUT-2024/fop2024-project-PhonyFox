#include "rogue.h"

int compare_users(const void *a, const void *b) {
    UserForBoard *userA = (UserForBoard *)a;
    UserForBoard *userB = (UserForBoard *)b;
    return userB->score - userA->score;
}

int rankUsersByScore() {
    FILE *file = fopen("LEADERBOARD.txt", "r");

    UserForBoard users[100];
    int count = 0;
    char line[256];

    while (fgets(line, sizeof(line), file) && count < 100) {
        sscanf(line, "%[^,],%d,%d,%d,%d,%d", users[count].username, &users[count].won_games, &users[count].total_games, &users[count].score, &users[count].gold, &users[count].day);
        count++;
    }
    fclose(file);

    qsort(users, count, sizeof(UserForBoard), compare_users);

    //start_color();
    // init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    // init_pair(2, COLOR_GREEN, COLOR_BLACK);
    // init_pair(3, COLOR_RED, COLOR_BLACK);

    int page = 0;
    int items_per_page = 5;
    int total_pages = (count + items_per_page - 1) / items_per_page;

    while (1) {
        clear();
        int start_index = page * items_per_page;
        int end_index = (page + 1) * items_per_page;
        if (end_index > count) end_index = count;

        for (int i = start_index; i < end_index; i++) {
            if (i == 0) {
                attron(COLOR_PAIR(6));
                attron(A_BOLD);
                attron(A_UNDERLINE);
            } else if (i == 1) {
                attron(COLOR_PAIR(2));
                attron(A_BOLD);
                attron(A_UNDERLINE);
            } else if (i == 2) {
                attron(COLOR_PAIR(3));
                attron(A_BOLD);
                attron(A_UNDERLINE);
            }

            if (strcmp(users[i].username, currentUserLogin) == 0) {
                printw("%d*. %s (Score: %d) (Wins: %d) (Total Games: %d) (Golds: %d) (Exp: %ld)",
                    i + 1, users[i].username, users[i].score, users[i].won_games, users[i].total_games, users[i].gold, time(NULL)/86400-users[i].day);
            } else {
                printw("%d. %s (Score: %d) (Wins: %d) (Total Games: %d) (Golds: %d) (Exp: %ld)",
                       i + 1, users[i].username, users[i].score, users[i].won_games, users[i].total_games, users[i].gold, time(NULL)/86400-users[i].day);
            }
            if (i == 0) printw("  Gold ***");
            if (i == 1) printw("  Silver **");
            if (i == 2) printw("  Bronze *");
            printw("\n");

            attroff(A_BOLD);
            attroff(A_UNDERLINE);
            attroff(COLOR_PAIR(6));
            attroff(COLOR_PAIR(2));
            attroff(COLOR_PAIR(3));
        }
        attron(A_DIM);
        attron(COLOR_PAIR(1));
        printw("\nPage %d of %d\n", page + 1, total_pages);
        printw("\nPress UP/DOWN to navigate pages, ESC to exit.\n");
        attroff(A_DIM);
        attroff(COLOR_PAIR(1));
        int ch = getch();
        if (ch == KEY_DOWN && page < total_pages - 1) {
            page++;
        } else if (ch == KEY_UP && page > 0) {
            page--;
        } else if (ch == 27) {
            break;
        }

        refresh();
    }

    clear();
    attroff(COLOR_PAIR(1));
    attroff(COLOR_PAIR(2));
    attroff(COLOR_PAIR(3));
    attroff(COLOR_PAIR(4));
    attroff(COLOR_PAIR(5));
    attroff(COLOR_PAIR(6));
    attroff(COLOR_PAIR(7));
    refresh();
    mainMenu();
    return 0;
}


