//
// Created by ExMachina on 9/20/2020.
//

#ifndef OTHELLOCLION_CELLDATA_H
#define OTHELLOCLION_CELLDATA_H
#include <bits/stdc++.h>
using namespace std;

class cellData {
public:
    int x,y,piece;   //-1 for empty, 0 for white, 1 for black
    string positionInString;

    //constructors
    cellData(int x, int y, int piece);
    cellData();
    cellData(int x, int y);

    //misc methods
    void toString();
    void show();

    //cell Information Methods
    int getPiece();
    void setPiece(int val);
    void reverse();
    void setValue(int a, int b);
    void clear();


    bool operator==(const cellData &rhs) const;

    bool operator!=(const cellData &rhs) const;

    bool operator<(const cellData &rhs) const;

    bool operator>(const cellData &rhs) const;

    bool operator<=(const cellData &rhs) const;

    bool operator>=(const cellData &rhs) const;
};


#endif //OTHELLOCLION_CELLDATA_H
