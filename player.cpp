#include "player.h"

//---------------------------------------------------------------------

Player::Player(char symbol)
{
	sign = symbol;

	maxRow = 0;
	maxCol = 0;
	maxDiag1 = 0;
	maxDiag2 = 0;
}

//---------------------------------------------------------------------

void Player::getLines(int lines[4])
{
	lines[row] = maxRow;
	lines[col] = maxCol;
	lines[diag1] = maxDiag1;
	lines[diag2] = maxDiag2;
}

//---------------------------------------------------------------------

void Player::getCoords(char choice, int coords[])
{
	switch(choice)
	{
		case 'r':
		{
			for(int i=0;i<4;i++)
			{
				coords[i] = rowCoords[i];
			}
			break;
		}
		case 'c':
		{
			for(int i=0;i<4;i++)
			{
				coords[i] = rowCoords[i];
			}
			break;
		}
		case 'd':
		{
			for(int i=0;i<4;i++)
			{
				coords[i] = rowCoords[i];
			}
			break;
		}
		case 'p':
		{
			for(int i=0;i<4;i++)
			{
				coords[i] = rowCoords[i];
			}
			break;
		}
	}
}

//---------------------------------------------------------------------

void Player::update(int x, int y, const char board[], const int bSize)
{
	rowUpdate(x,y, board, bSize);
	colUpdate(x,y, board, bSize);
	diag1Update(x,y, board, bSize);
	diag2Update(x,y, board, bSize);
}

//---------------------------------------------------------------------

void Player::rowUpdate(int x, int y, const char board[], const int bSize)
{
	int j = y;
	int countRow = 0;

	while((j >= 0) && (board[x*bSize + j] == board[x*bSize + y]))
	{
		countRow++;
		j--;
	}

	j++;

	rowCoords[x1] = x;
	rowCoords[y1] = j;

	j = y;

	while((j <= bSize - 1) && (board[x*bSize + j] == board[x*bSize + y]))
	{
		countRow++;
		j++;
	}
	
	j--;
	countRow--;

	rowCoords[x2] = x;
	rowCoords[y2] = j;

	maxRow = bigger(countRow, maxRow);
	//cout<<"MaxRow = "<<maxRow<<endl;
}

//---------------------------------------------------------------------

void Player::colUpdate(int x, int y, const char board[], const int bSize)
{
	int i = x;
	int countCol = 0;

	while((i >= 0) && (board[i*bSize + y] == board[x*bSize + y]))
	{
		countCol++;
		i--;
	}

	i++;

	colCoords[x1] = i;
	colCoords[y1] = y;

	i = x;

	while((i <= bSize - 1) && (board[i*bSize + y] == board[x*bSize + y]))
	{
		countCol++;
		i++;
	}
	
	i--;
	countCol--;

	rowCoords[x2] = i;
	rowCoords[y2] = y;

	maxCol = bigger(countCol, maxCol);
}

//---------------------------------------------------------------------

void Player::diag1Update(int x, int y, const char board[], const int bSize)
{
	int i = x;
	int j = y;
	int countDiag1 = 0;

	while((j >= 0) && (i >= 0) && (board[i*bSize + j] == board[x*bSize + y]))
	{
		countDiag1++;
		j--;
		i--;
	}

	j++;
	i++;

	diag1Coords[x1] = i;
	diag1Coords[y1] = j;

	i = x;
	j = y;

	while((i <= bSize - 1) && (j <= bSize - 1) && (board[i*bSize + j] == board[x*bSize + y]))
	{
		countDiag1++;
		j++;
		i++;
	}
	
	j--;
	i--;
	countDiag1--;

	diag1Coords[x2] = i;
	diag1Coords[y2] = j;

	maxDiag1 = bigger(countDiag1, maxDiag1);

	//cout<<"MaxDiag = "<<maxDiag1<<endl;
}

//---------------------------------------------------------------------

void Player::diag2Update(int x, int y, const char board[], const int bSize)
{
	int i = x;
	int j = y;
	int countDiag2 = 0;

	while((j <= bSize - 1) && (i >= 0) && (board[i*bSize + j] == board[x*bSize + y]))
	{
		countDiag2++;
		j++;
		i--;
	}

	j--;
	i++;

	diag2Coords[x1] = i;
	diag2Coords[y1] = j;

	i = x;
	j = y;

	while((i <= bSize - 1) && (j >= 0) && (board[i*bSize + j] == board[x*bSize + y]))
	{
		countDiag2++;
		j--;
		i++;
	}
	
	j++;
	i--;
	countDiag2--;

	diag2Coords[x2] = i;
	diag2Coords[y2] = j;

	maxDiag2 = bigger(countDiag2, maxDiag2);
}





