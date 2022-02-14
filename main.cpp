#include <iostream>
#include<ctype.h>

using namespace std;

char board[3][3] = {{'1', '2','3'}, {'4','5','6'}, {'7','8','9'}};
char current_marker;
int current_player;


void DrawBoard()//the board of the game.
{
    int i=0;
    for(i=0; i<3; i++)
    {
        cout << " "<< board[i][0] << " | "  << board[i][1] << " | " << board[i][2] << endl;
        cout <<"----------- \n";
    }

}
void placeMarker(int slot)//placing the markers
{
    int row=slot/3;
    int column;
    if(slot%3==0)
    {
        row = row-1;
        column = 2;
    }
    else column=(slot%3)-1;

    cout << row << ',' << column;


    if(isdigit(board[row][column]))//if slot is free
    {

        board[row][column] = current_marker;
        cout << "\n";
        DrawBoard();
    }
    else
    {
        cout << "\n Slot is alredy occupied try again\n Choose a new slot: \n";
        int newSlot;
        cin >> newSlot;
        placeMarker(newSlot);
    }
}

int winner()//Evaluating a possible winner
{
    int i;
    for (i=0; i<3; i++)
    {
        //row
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return current_player;
        //column
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return current_player;
    }
    //diagonal
    if (board[0][0] == board[1][1] && board[1][1]== board[2][2]) return current_player;
    if (board[0][2]== board[1][1] && board[1][1] == board[2][0]) return current_player;
    return 0;
}

void swap_player_marker()//swapping player and marker
{

    if(current_player == 1)current_player= 2;

    else current_player=1;


    if(current_marker =='X') current_marker ='O';

    else current_marker='X';
}

void game()
{
    cout << "Player 1 choose your marker:\n X or O \n";
    char marker_p1;
    cin >> marker_p1;

    current_player =1;
    current_marker= toupper(marker_p1);
    int player_won;
    DrawBoard();

    for(int i= 0; i<9 ; i++)
    {
        cout << "It's player  " << current_player << "  turn. Enter your slot: \n";
        int slot;
        cin >> slot;
        if(slot<1 || slot >9)
        {
            cout << "Slot is not real \n try again: \n ";
            i--;
            continue;//the rest of the loot stops and stars all over
        }

        placeMarker(slot);
        player_won=winner();

        if(player_won == 1)
        {
            cout << "\n Player 1 is the winner\n";
            break;
        }
        if (player_won == 2)
        {
            cout << "\n Player 2 is the winner\n";
            break;
        }
        swap_player_marker();
    }
    if (player_won == 0) cout << "\nGamer over\n";

}





int main()
{
  game();

}

