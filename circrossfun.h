#ifndef FUN
#define FUN

#include <iostream>
#include <cmath>
#include <cstdlib>
#include "board.h"

using namespace std;

//------------------------------------------------

int strToInts(string coords, int poz, int decPos = 2);

int bigger(int a, int b);

int findMax(int tab[]);

bool moveRow(const int sCoords[], int coords[], const char board[], const int bSize);

bool moveCol(const int sCoords[], int coords[], const char board[], const int bSize);

bool moveDiag1(const int sCoords[], int coords[], const char board[], const int bSize);

bool moveDiag2(const int sCoords[], int coords[], const char board[], const int bSize);

//void userMove(Board &board);

//void botMove(Board &board, Bot &bot, Player &playerX, Player &playerO);

void playWithBot(int n);

//------------------------------------------------

#endif //FUN