#ifndef BOARD
#define BOARD

#include <iostream>
#include <cstdlib>
#include <cmath>
//#include <ncurses.h>
#include "circrossfun.h"
#include "player.h"

//-----------------------------------------

using namespace std;

class Player;

class Board
{
public:
    Board(int mySize);  //done

    ~Board();  //done

    void display();  //done

    void getFromUser();  //done

    void checkWinner(Player &player);  //done

    //bool draw();  //to do!!!

    void victory(char winner);

    void insert(int x, int y);  //done

    void changePlayer()  //done
    {
        player = ((player == 'X') ? 'O' : 'X');
    }

    const char *getBoard(){return myBoard;}

    const int getSize(){return bSize;}

    int getX(){return lastX;}

    int getY(){return lastY;}

    char getPlayer(){return player;}

private:
	int bSize;
    char *myBoard;   
    int lastX, lastY;
    char player;
};

//-------------------------------------------

#endif //BOARD