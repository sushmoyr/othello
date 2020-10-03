//
// Created by ExMachina on 9/20/2020.
//

#include "cellData.h"

cellData::cellData(int x, int y, int piece) : x(x), y(y), piece(piece) {
    this->x = x;
    this->y = y;
    this->piece = piece;
}

cellData::cellData() {
    x = -1;
    y = -1;
    piece = -1; //-1 means empty cell
}

cellData::cellData(int x, int y) : x(x), y(y) {
    this->x = x;
    this->y = y;
    this->piece = -1;
}

void cellData::show() {
    cout<<positionInString<<endl;
}


void cellData::toString() {
    positionInString.clear();
    positionInString+=(char) ('A'+x);
    positionInString+=(char) ('1'+y);
}

int cellData::getPiece() {
    return this->piece;
}

void cellData::setPiece(int val) {
    this->piece=val;
}

void cellData::reverse() {
    if(this->piece == 1)
        this->piece = 0;
    else
        this->piece = 1;

}

void cellData::setValue(int a, int b) {
    x = a;
    y = b;
}

void cellData::clear() {
    x = -1;
    y = -1;
    piece = -1;
}

bool cellData::operator==(const cellData &rhs) const {
    return x == rhs.x &&
           y == rhs.y;
}

bool cellData::operator!=(const cellData &rhs) const {
    return !(rhs == *this);
}

bool cellData::operator<(const cellData &rhs) const {
    return x<rhs.x or (!(rhs.x<x) and y<rhs.y );
}

bool cellData::operator>(const cellData &rhs) const {
    return rhs < *this;
}

bool cellData::operator<=(const cellData &rhs) const {
    return !(rhs < *this);
}

bool cellData::operator>=(const cellData &rhs) const {
    return !(*this < rhs);
}
