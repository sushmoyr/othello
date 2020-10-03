//
// Created by ExMachina on 9/20/2020.
//
#include <bits/stdc++.h>
#include "gameBoard.h"
#define WHITE 0
#define BLACK 1
using namespace std;

gameBoard::gameBoard() {
    /** -1 for an empty cell
     0 for white cell
     1 for black cell **/
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++){
            if((i==3 and j==3) or (i==4 and j==4))
                board[i][j]=0;
            else if((i==3 and j==4) or (i==4 and j==3))
                board[i][j]=1;
            else
            {
                board[i][j]=-1;
                cellData temp(i,j,-1);
                emptyCells[temp]=true;
            }
        }
    }

    pcount[0] = pcount[1] = 2;

}

void gameBoard::displayBoard() {
    char val;
    cout<<"  ";
    for(int i=0; i<8; i++)
        printf("   %d  ",i+1);
    cout<<endl;

    for(int i=0; i<8; i++)
    {
        cout<<"  ";
        for(int j=0; j<8; j++)
        {
            printf(" -----");
        }
        cout<<endl;
        printf("%c ",'A'+i);
        for(int j=0; j<8; j++)
        {
            if(board[i][j]==-1)
                val = ' ';
            else if(board[i][j]==0)
                val = 'O';
            else
                val = 'X';
            printf("|  %c  ", val);
        }

        printf("|\n");
    }
    printf("  ");
    for(int j=0; j<8; j++)
    {
        printf(" -----");
    }
    cout<<endl;

    //printf("Black pieces: %d\nWhite pieces: %d\n",pcount[1],pcount[0]);
    //printf("Empty cell count = %d\n",emptyCells.size());
}


void gameBoard::updateBoard(cellData &n, int color) {

    vector<int>cdir = valid_directions[n];
    //place the piece
    board[n.x][n.y] = color;
    pcount[color]--;
    emptyCells.erase(n);

    for(int i=0; i<cdir.size(); i++)
    {
        int idx = cdir[i];
        int a = n.x + dirx[idx];
        int b = n.y + diry[idx];

        while(board[a][b]!=color)
        {
            system("CLS");
            if(board[a][b]!=-1)
                pcount[board[a][b]]--;

            displayBoard();
            delay(2);
            board[a][b]=color;
            pcount[color]++;
            cellData temp(a,b);
            emptyCells.erase(temp);
            a+=dirx[idx];
            b+=diry[idx];
        }
        system("CLS");
    }


}


cellData gameBoard::showValidMoves() {
    printf("Available Moves are: \n");

    int cnt = 0;
    cellData temp;
    vector<cellData>v;
    v.clear();
    for(auto item : valid_moves)
    {
        printf("%d: ",++cnt);
        temp = item.first;
        temp.toString();
        temp.show();
        v.push_back(temp);
    }

    while(true)
    {
        printf("Select your move: ");
        cin>>cnt;
        cout << endl;
        if(cnt>valid_moves.size())
        {
            cout<<"Invalid move. Try Again.\n";
            continue;
        }
        break;
    }
    return v[cnt-1];
}

int gameBoard::getWhiteCount() {
    int count = 0;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(board[i][j]==WHITE)
                count++;
        }
    }
    return count;
}

int gameBoard::getBlackCount() {
    int count = 0;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(board[i][j]==BLACK)
                count++;
        }
    }
    return count;
}
