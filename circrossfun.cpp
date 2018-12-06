#include "circrossfun.h"

//---------------------------------------------------

int strToInts(string coords, int poz, int decPos)  //decPos - max ilosc pozycji w zapisie dec
{
    //cout<<"converting";

    int i = 0;
    int x = 0,y = 0;
    
    while(coords[i] != ',') i++;
    int iCom = i;  //indeks przecinka

    while(i>0)
    {
        x += ((int)(coords[i-1]) - 48) * pow(10, iCom - i);
        i--;
    }

    i = coords.length() - 1;

    while(i > iCom)
    {
        y += ((int)(coords[i]) - 48) * pow(10, coords.length() - 1 - i);
        i--;
    }
    
    if(!poz) return x;
    else return y;
}

//---------------------------------------------------

int bigger(int a, int b)
{
    return ((a>b) ? a : b);
}

//--------------------------------------------------

int findMax(int tab[])
{
	int max = tab[0];

    for(int i = 1; i < 4; i++)
    {
        if(tab[i] > max) max = tab[i];
    }

	return max;
}

//------------------------------------------------------

bool moveRow(const int sCoords[], int coords[], const char board[], const int bSize)
{
    int x = sCoords[0];
    int y = sCoords[1] - 1;

    if((y >= 0) && (board[x*bSize + y] == '-'))
    {
        coords[0] = x;
        coords[1] = y;
        return true;
    }

    x = sCoords[2];
    y = sCoords[3] + 1;

    if((y <= bSize - 1) && (board[x*bSize + y] == '-'))
    {
        coords[0] = x;
        coords[1] = y;
        return true;
    }

    return false;
}

//------------------------------------------------------

bool moveCol(const int sCoords[], int coords[], const char board[], const int bSize)
{
    int x = sCoords[0] - 1;
    int y = sCoords[1];

    if((x >= 0) && (board[x*bSize + y] == '-'))
    {
        coords[0] = x;
        coords[1] = y;
        return true;
    }

    x = sCoords[2] + 1;
    y = sCoords[3];

    if((x <= bSize - 1) && (board[x*bSize + y] == '-'))
    {
        coords[0] = x;
        coords[1] = y;
        return true;
    }

    return false;
}

//------------------------------------------------------

bool moveDiag1(const int sCoords[], int coords[], const char board[], const int bSize)
{
    int x = sCoords[0] - 1;
    int y = sCoords[1] - 1;

    if((x >= 0) && (y >= 0) && (board[x*bSize + y] == '-'))
    {
        coords[0] = x;
        coords[1] = y;
        return true;
    }

    x = sCoords[2] + 1;
    y = sCoords[3] + 1;

    if((x <= bSize - 1) && (y <= bSize - 1) && (board[x*bSize + y] == '-'))
    {
        coords[0] = x;
        coords[1] = y;
        return true;
    }

    return false;
}

//------------------------------------------------------

bool moveDiag2(const int sCoords[], int coords[], const char board[], const int bSize)
{
    int x = sCoords[0] - 1;
    int y = sCoords[1] + 1;

    if((x >= 0) && (y <= bSize - 1) && (board[x*bSize + y] == '-'))
    {
        coords[0] = x;
        coords[1] = y;
        return true;
    }

    x = sCoords[2] + 1;
    y = sCoords[3] - 1;

    if((x <= bSize - 1) && (y >= 0) && (board[x*bSize + y] == '-'))
    {
        coords[0] = x;
        coords[1] = y;
        return true;
    }

    return false;
}

//------------------------------------------------------

void playWithBot(int n)
{
    Board board(n);
    board.display();

    Player playerX('X'), playerO('O');

    int botCoords[4];
    int usrCoords[4];
    int botLines[4];
    int usrLines[4];
    int coords[2];
    int x, y;

    playerO.getLines(botLines);

    while(1)
    {
        board.getFromUser();
        board.display();
        
        x = board.getX();
        y = board.getY();
        playerX.update(x, y, board.getBoard(), board.getSize());
        board.checkWinner(playerX);

        playerX.getLines(usrLines);

        cout<<"\nTeraz bot: \n\n";

        bool botOk = false;

        if(!findMax(botLines))
        {
            playerX.getCoords('r', usrCoords);
            botOk = moveRow(usrCoords, coords, board.getBoard(), board.getSize());
        }

        if((!botOk) && (botLines[0] == 4))
        {
            playerO.getCoords('r', botCoords);
            botOk = moveRow(botCoords, coords, board.getBoard(), board.getSize());
        }
        if((!botOk) && (botLines[1] == 4))
        {
            playerO.getCoords('c', botCoords);
            botOk = moveCol(botCoords, coords, board.getBoard(), board.getSize());
        }
        if((!botOk) && (botLines[2] == 4))
        {
            playerO.getCoords('d', botCoords);
            botOk = moveDiag1(botCoords, coords, board.getBoard(), board.getSize());
        }
        if((!botOk) && (botLines[3] == 4))
        {
            playerO.getCoords('p', botCoords);
            botOk = moveDiag2(botCoords, coords, board.getBoard(), board.getSize());
        }

        if((!botOk) && (usrLines[0] >= 3))
        {
            playerX.getCoords('r', usrCoords);
            botOk = moveRow(usrCoords, coords, board.getBoard(), board.getSize());
        }
        if((!botOk) && (usrLines[1] >= 3))
        {
            playerX.getCoords('c', usrCoords);
            botOk = moveCol(usrCoords, coords, board.getBoard(), board.getSize());
        }
        if((!botOk) && (usrLines[2] >= 3))
        {
            playerX.getCoords('d', usrCoords);
            botOk = moveDiag1(usrCoords, coords, board.getBoard(), board.getSize());
        }
        if((!botOk) && (usrLines[3] >= 3))
        {
            playerX.getCoords('p', usrCoords);
            botOk = moveDiag2(usrCoords, coords, board.getBoard(), board.getSize());
        }

        if((!botOk) && (botLines[0] == findMax(botLines)))
        {
            playerO.getCoords('r', botCoords);
            botOk = moveRow(botCoords, coords, board.getBoard(), board.getSize());
        }
        if((!botOk) && (botLines[1] == findMax(botLines)))
        {
            playerO.getCoords('c', botCoords);
            botOk = moveCol(botCoords, coords, board.getBoard(), board.getSize());
        }
        if((!botOk) && (botLines[2] == findMax(botLines)))
        {
            playerO.getCoords('d', botCoords);
            botOk = moveDiag1(botCoords, coords, board.getBoard(), board.getSize());
        }
        if((!botOk) && (botLines[3] == findMax(botLines)))
        {
            playerO.getCoords('p', botCoords);
            botOk = moveDiag2(botCoords, coords, board.getBoard(), board.getSize());
        }

        if(!botOk) 
        {
            playerO.getCoords('r', botCoords);
            botOk = moveRow(botCoords, coords, board.getBoard(), board.getSize());
        }
        if(!botOk)
        {
            playerO.getCoords('c', botCoords);
            botOk = moveCol(botCoords, coords, board.getBoard(), board.getSize());
        }
        if(!botOk)
        {
            playerO.getCoords('d', botCoords);
            botOk = moveDiag1(botCoords, coords, board.getBoard(), board.getSize());
        }
        if(!botOk)
        {
            playerO.getCoords('p', botCoords);
            botOk = moveDiag2(botCoords, coords, board.getBoard(), board.getSize());
        }

        if(!botOk) cout<<"Error!"<<endl;

        board.insert(coords[0], coords[1]);
        board.display();

        x = board.getX();
        y = board.getY();
        playerO.update(x, y, board.getBoard(), board.getSize());
        board.checkWinner(playerO);

        playerO.getLines(botLines);
    }
}
