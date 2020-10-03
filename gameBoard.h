//
// Created by ExMachina on 9/20/2020.
//

#ifndef OTHELLOCLION_GAMEBOARD_H
#define OTHELLOCLION_GAMEBOARD_H
#include <bits/stdc++.h>
#include "cellData.h"
using namespace std;

class gameBoard {
public:
    int board[8][8], pcount[2];
    map< cellData, bool> emptyCells, valid_moves;
    map< cellData, vector<int> > valid_directions;
    map< cellData, int> dist;
    gameBoard();
    void updateBoard(cellData &n, int color);
    void displayBoard();

    cellData showValidMoves();

    int getWhiteCount();
    int getBlackCount();


private:
    //directions
    const int dirx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int diry[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    void delay(int n)
    {
        using namespace std::this_thread; // sleep_for, sleep_until
        using namespace std::chrono; // nanoseconds, system_clock, seconds

        sleep_for(nanoseconds(10));
        sleep_until(system_clock::now() + seconds(n));
    }


};


#endif //OTHELLOCLION_GAMEBOARD_H
