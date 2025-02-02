#ifndef ROGUE_H
#define ROGUE_H

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <menu.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>
#include <locale.h>
#include <wchar.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>

//#include <unistd.h>

extern int difficulty;
extern int characterStatus;
extern char currentUserLogin[50];
extern int isGeust;
extern int doorPassword;
extern int passwordChances;
extern int gameStatus;
extern int spellOrLevel;
extern int inSpellRoomRandom;
extern char spellRoomTiles[40][120];
extern int numberOfFoods;
extern int walkingAndHunger;
extern int fullToHealth;
extern int isGunChosen;
extern int hasSavedShot;
extern int wantedToAutoAim;
extern int speedSteps;
extern int hasSpeedSpell;
extern int healthSteps;
extern int hasHealthSpell;
extern int damageSteps;
extern int hasDamageSpell;
extern int isInTreasure;
extern int isOpen;
extern int characterColor;
extern int isInSpellRoom;
extern Mix_Music *current_music;
extern int totalHealth;
extern int lastPrintedLine;
extern char musicName[50];




typedef struct UserForBoard {
    char username[50];
    int won_games;
    int total_games;
    int score;
    int gold;
} UserForBoard;

typedef struct User {
    char username[50];
    char password[50];
    char email[50];
} User;



typedef struct Position {
  int x;
  int y;
} Position;

typedef struct Monster {
  Position * position;
  char string[2];
  int health;
  int canWalk;
  int speed;
  int symbol;
  int defence;
  int attack;
  int numberOfSteps;
  int pathfinding;
  int alive;
  int steps;
} Monster;

typedef struct Room {
  Position position;
  int height;
  int width;
  struct Door ** doors;
  int numberOfDoors;
  int grid;
} Room;

typedef struct Door {
  Position position;
  int connected;
} Door;

typedef struct Player {
  Position * position;
  int health;
  int exp;
  int gold;
  int maxHealth;
  int mace;
  int dagger;
  int wand;
  int arrow;
  int sword;
  int sHealth;
  int sDamage;
  int sSpeed;
  int gunType;
} Player;

typedef struct Level {
  char ** tiles;
  int level;
  int numberOfRooms;
  struct Room ** rooms;
  struct Player * user;
  Monster ** monstersList;
  int numberOfMonsters;
} Level;

void pathFind(Position * start, Position * end);
void addPositionYX(int ** frontier, int frontierCount, int y, int x);
int checkPositionPath(int y, int x);
int addNeighbors(int ** frontier, int frontierCount,int *** cameFrom, int y, int x);


int screenSetUp();
int printGameHub(Level * level);
int mainGameLoop();


Level * createLevel();
Room ** roomsSetUp();
char ** saveLevelPosition();
void connectDoors(Level * level);

Player * playerSetUp();
Position * handleInput();
int checkPosition(Position * newPosition, Level * level);
int playerMove(Position * newPosition, Player * user, char ** level);
int placePlayer(Room ** rooms, Player * user);

Room * createRoom(int grid, int numberOfDoors);
int drawRoom(Room * room);

void preWin(int choice);
void preGameMenu();
void loginUserMenu();
void loginWin(int choice);
int isItItself(const char * password, const char * username);
int isValidUsername(const char *username);
int isValidPassword(const char *password);
int isValidEmail(const char *email);
int saveUser(User *user);
void createPlayerMenu();
int screenSetUp();
void mainMenu();
void newWin(int choice);
int compare_users(const void *a, const void *b);
int rankUsersByScore();
void userSettings();
void settingNavigator(int choice);
void difficultySetting();
void characterSetting();
void saveUserGame(Level * level);
void revive();
void resumeGameProccess();
void reloadUserInfo();
void drawResumeMap();
Level * reloadLevel(int level, int * numbers);
int printGameHubResume(Level * level);
Player * playerSetUpResume(int * numbers);
int placePlayerResume(Player * user, int y, int x);
void makeUserMapFile();
char ** saveLevelPositionResume();
int windowMaker();
int changeLevel(Level * level);
Room * createLastRoom(int grid, int numberOfDoors);
Room ** lastroomsSetUp();
void checkStatus(Level * level);
void saveToLeaderBoard(Level * level);
void spellRoomMaker();
void addMonsters(Level * level);
Monster * selectMonster(int level);
Monster * createMonster(char symbol, int health, int attack, int speed, int defence, int pathfinding, int steps);
void moveMonsters(Level * level);
void pathfindingRandom(Position * position);
void pathfindingSeek(Position * start, Position * destination);
void drawMonsters(Monster * monster);
void setStartingPosition(Monster * monster, Room * room);
void combat(int gun, Level * level);
void killMonster(Monster * monster);
Monster * getMonsterAt(int y, int x, Monster ** monsters);
void changeGun(Level * level);
int useGun(Level * level);
void arrowLauncher(Level * level);
char * getMonsterName(char symbol);
void wandLauncher(Level * level);
void daggerLauncher(Level * level);
void chooseSpell(Level * level);
void monstersAttack(Level * level);
void setStartingPositionTreasure(Monster * monster);
void makeTreasureRoom(Level * level);
void fastPassing(Level * level);
int checkPositionForFast(Position * newPosition, Level * level);
void printChar(int y, int x);
Monster * createMonsterResume(char symbol, int health, int attack, int speed, int defence, int pathfinding, int steps, int y, int x);
Monster* selectMonsterResume(int* numbers, int index);
void addMonstersResume(Level * level, int * numbers);
void play_or_replace_music(const char *musicFile);
void play_effect1();
void play_effect_newRoom();
void play_effect_die();
void play_effect_lose();
void play_effect_win();
void play_effect_fight();
void play_effect_heart();
void play_effect_horror();
int emptyLine();
void clearLine(int line);
void printWithColor(int y, int x, char ch);
void trollFace();
void printMe1();
void printMe2();
void printMe3();
void printMe4();
void printMeDim1();
void printMeDim2();
void printMeDim3();
void printDate1();
void printDate2();
void printDate3();
void printDate4();
void printDate5();
void printDate6();
void printTrolls();
void  troll1();
void  troll2();
void  troll3();
void  troll4();
void  troll5();
void  troll6();
void  troll7();
void  troll8();
void  troll9();
void  troll10();
void  troll11();
void  troll12();
void  troll13();
void  troll14();
void  troll15();
void  troll16();
void  troll17();
void  troll18();
void  troll19();
void  troll20();
void printLost();
void clearThere();
void stop_music();


#endif