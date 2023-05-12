#pragma once
#include <string>

using namespace std;

//function interface
void gotoxy(int x, int y);
void drawboard();
void processfinish(int whowin);
int fmenuchinh(int x);
int fmenuseved();
void fxuli();
void fxuli_seved();

//function operation
void resetLuot();
void resetdata();
void newgame();
void exitgame();

void savegame(string filename);
void loaddata(string filename);
void loadgame(int stt);
void wrlistfile(bool flag);

void console_go(int&dem, int&soquanP1, int&soquanP2);

short testboard();
bool check_xeophu(int x, int y);
bool check_xeochinh(int x, int y);
bool check_hang(int x, int y);
bool check_cot(int x, int y);
