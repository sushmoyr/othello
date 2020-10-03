//
// Created by ExMachina on 9/20/2020.
//

#ifndef OTHELLOCLION_GAMELOGICS_H
#define OTHELLOCLION_GAMELOGICS_H
#include "gameBoard.h"
#include "cellData.h"
#include <bits/stdc++.h>

using namespace std;

bool end_of_game = false;
void whites_turn(gameBoard &board);
void blacks_turn(gameBoard &board);
bool isValidCell(gameBoard &board, int a, int b, int dir, int color, int &d);

bool cmp(pair<cellData, int>& a, pair<cellData, int>& b)
{
    return a.second > b.second;
}
void delay(int n)
{
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds

    sleep_for(nanoseconds(10));
    sleep_until(system_clock::now() + seconds(n));
}


bool outOfBounds(int &x, int &y);

//directions
const int dirx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int diry[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void whites_turn(gameBoard &board)
{
    system("CLS");
    cout<<"\n===================================================="<<endl;
    cout<<"\nIts white's turn now\n\n";


    cout<<"Waiting";
    for(int i=0; i<4; i++)
    {
        cout<<" ---";
        delay(1);
    }
    cout<<endl;

    int color = 0;
    board.valid_directions.clear();
    board.valid_moves.clear();
    board.displayBoard();
    vector< pair<cellData, int> > points;


    for(auto it: board.emptyCells)
    {
        //it.first is an empty cell. check for adjacency white cells
        int x = it.first.x;
        int y = it.first.y;
        int count=0;
        bool flag = false;
        vector<int>valid_dir;
        for(int i=0; i<8; i++)
        {
            int a = x + dirx[i];
            int b = y + diry[i];

            if(board.board[a][b] == 1 && !outOfBounds(a,b))
            {
                //black adjacent found
                //check if valid direction
                if(isValidCell(board, a,b,i,color,count))
                {
                    flag = true;
                    valid_dir.push_back(i);
                }
            }
        }
        if(flag)
        {
            board.valid_moves[it.first] = true;
            board.valid_directions[it.first] = valid_dir;
            points.push_back(make_pair(it.first, count) );
        }
    }


    if(board.valid_moves.empty())
    {
        end_of_game = true;
        return;
    }
    /** After getting the available moves for current player, we will show it to the
     * player using showValidMoves in board. After that we will wait for user input.
     * getUserInput returns an integer which is the index of the cell in moves_of_blacks
     * and we will update the board using updateBoard() method.
     * N:B: take index from user and pass the position of vector in updateBoard()
     */
    sort(points.begin(), points.end(), cmp);
    points[0].first.toString();
    cout<<"White put a piece in "<<points[0].first.positionInString<<endl;
    delay(2);
    board.updateBoard(points[0].first,0);
    board.displayBoard();
    delay(3);
    system("CLS");

}

void blacks_turn(gameBoard &board)
{
    system("CLS");
    cout<<"\n===================================================="<<endl;
    cout<<"\nIts black's turn now\n\n";

    int color = 1;
    board.valid_directions.clear();
    board.valid_moves.clear();
    int uv = 0;
    board.displayBoard();


    /** Check for adjacent white cels among all the empty cells in emptyCells map
     * if found a white adjacent cell then check if a valid move is possible in
     * that cell by isValid cell. if a cell is valid then push the cell to valid_moves
     * and store the direction in which the cell is valid.
     */
    for(auto it: board.emptyCells)
    {
        //it.first is an empty cell. check for adjacency white cells
        int x = it.first.x;
        int y = it.first.y;
        bool flag = false;
        vector<int>valid_dir;
        for(int i=0; i<8; i++)
        {
            int a = x + dirx[i];
            int b = y + diry[i];

            if(board.board[a][b] == 0 && !outOfBounds(a,b))
            {
                //white adjacent found
                //check if valid direction
                if(isValidCell(board, a,b,i,1,uv))
                {
                    flag = true;
                    valid_dir.push_back(i);
                }
            }
        }
        if(flag)
        {
            board.valid_moves[it.first] = true;
            board.valid_directions[it.first] = valid_dir;
        }
    }


     if(board.valid_moves.empty())
     {
         end_of_game = true;
         return;
     }
     /** After getting the available moves for current player, we will show it to the
      * player using showValidMoves in board. After that we will wait for user input.
      * getUserInput returns an integer which is the index of the cell in moves_of_blacks
      * and we will update the board using updateBoard() method.
      * N:B: take index from user and pass the position of vector in updateBoard()
      */

     cellData input = board.showValidMoves();
     board.updateBoard(input,1);
     board.displayBoard();
     cout<<endl;

}

bool isValidCell(gameBoard &board, int a, int b, int dir, int color, int &d)
{
    int cnt = 0;
    board.dist.clear();
    while(!outOfBounds(a,b) and board.board[a][b]!=-1)
    {
        cnt++;
        //printf("Checking %d,%d\n",a,b);
        if(board.board[a][b]==color)
        {
            //printf("This is a valid move\n");
            d+=cnt;
            return true;
        }
        a+=dirx[dir];
        b+=diry[dir];
    }

    return false;
}

bool outOfBounds(int &x, int &y) {
    return (x<0 or x>7 or y<0 or y>7);
}


#endif //OTHELLOCLION_GAMELOGICS_H
