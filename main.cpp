#include <iostream>
#include <bits/stdc++.h>
#include "gameBoard.h"
#include <cstdlib>
#include "cellData.h"
#include "ui.h"
#include "gameLogics.h"

using namespace std;
void start_game();
bool gameOver(gameBoard &board);
void debug();
ui ui;
gameBoard board{};
int main() {

    //start_game();
    //debug();
    int choice;
    ui.show_menu();
    choice = ui.getChoice();
    if(choice == 1)
        start_game();
    else
        return 0;
}
void start_game()
{
    ui.loading(3);


    /** In this function, the game instance will be started including initialization of board
     * and points. We will use a loop to iterate until the end of game condition meets
     */

    //getchar();
    int turn = 0;

    while(true)
    {
        cout<<"Number of total turns = "<<++turn<<endl;
        if(gameOver(board))
            break;
        if(turn%2)
        {

            blacks_turn(board);

        }
        else
        {
            cout<<"\n===================================================="<<endl;
            cout<<"Its white's turn now\n";
            whites_turn(board);
        }
    }

    ui.game_over(board.getBlackCount(), board.getWhiteCount());

}

//Function for debug purpose
void debug()
{
    cellData c;
    int x, y;
    cin>>x>>y;
    c.setValue(x,y);
    cout<<"showing value\n";
    cout<<c.x<<" "<<c.y<<endl;
    cout<<"showing string"<<endl;
    if(c.positionInString == "")
        cout<<"string is empty"<<endl;
    c.toString();
    if(c.positionInString!="")
        cout<<"String is not empty\n";
    c.show();
}
bool gameOver(gameBoard &board)
{
    return board.getWhiteCount()==0 or board.getBlackCount()==0 or board.emptyCells.empty() or end_of_game;
}
