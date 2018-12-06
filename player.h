#ifndef PLAYER
#define PLAYER

#include <iostream>
#include "board.h"

using namespace std;

//------------------------------------------------

class Player
{
	
public:

	Player(char symbol);

	~Player(){}

	void getLines(int lines[4]);

	void getCoords(char choice, int coords[]);

	void update(int x, int y, const char board[], const int bSize);

	void rowUpdate(int x, int y, const char board[], const int bSize);

	void colUpdate(int x, int y, const char board[], const int bSize);

	void diag1Update(int x, int y, const char board[], const int bSize);

	void diag2Update(int x, int y, const char board[], const int bSize);

	const char getSign(){ return sign; }

	friend class Board;

private:

	enum seqs {row, col, diag1, diag2};

	enum coords{x1, y1, x2, y2};

	char sign;

	int maxRow;
	int maxCol;
	int maxDiag1;
	int maxDiag2;

	int rowCoords[4];
	int colCoords[4];
	int diag1Coords[4];
	int diag2Coords[4];
};

#endif //PLAYER