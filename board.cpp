#include "board.h"

//---------------------------------------------------------------

Board::Board(int mySize)
{
    bSize = mySize;
    myBoard = new char [bSize*bSize];

    player = 'X';

    for(int i=0;i<bSize;i++)
    {
        for(int j=0;j<bSize;j++)
        {
            myBoard[i*bSize + j] = '-';
        }
    }
}

//--------------------------------------------------------------

Board::~Board()
{
    delete [] myBoard;
}

//---------------------------------------------------------------

void Board::display()
{
    //initscr();

    for(int i=0;i<bSize;i++)
    {
        for(int j=0;j<bSize;j++)
        {
            //printw("%d  ", myBoard[i*bSize + j]);
            //refresh();
            cout<<myBoard[i*bSize + j]<<"  ";
        }
        cout<<endl;
        //printw("\n");
        //refresh();
    }
}

//-----------------------------------------------------------------

void Board::getFromUser()
{
    string coords;
    int x, y;

    do
    {
        cout<<"Podaj wspolrzedne oddzielone pojedynczym przecinkiem: "<<endl;
        cin>>coords;
        if(coords == "exit") exit(1);

        x = strToInts(coords, 0);
        y = strToInts(coords, 1);

        if(myBoard[x*bSize + y] == '-') break;
        else cout<<"Nie mozesz tu nic wstawic. Wybierz puste pole. Debilu."<<endl;
        if((x >= bSize) || (y >= bSize)) 
            cout<<"Nieprawidlowe wpolrzedne. Podaj liczby z przedzialu [0, "
                <<bSize-1<<"]. Debilu."<<endl;
    }
    while(1);

    insert(x,y);
}

//---------------------------------------------------------------------

void Board::checkWinner(Player &player)
{
    int lines[4];

    player.getLines(lines);

    if(findMax(lines) == 5) victory(player.getSign());
}

//------------------------------------------------------------------

void Board::victory(char winner)
{
    cout<<"Wygrywa "<<winner<<"!"<<endl;
    exit(1);
}

//----------------------------------------------------------------

void Board::insert(int x, int y)  //done
{
    myBoard[x*bSize + y] = player;
    lastX = x;
    lastY = y;
    changePlayer();
}  

