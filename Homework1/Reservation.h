#pragma once
#include <iostream>
using namespace std;

/**
    @author Arda Barýþ Örtlek
*/

class Reservation{
public:
    Reservation(long movieID, int row, char col, int code);
    Reservation();
    long getID();
    int getRow();
    char getCol();
    int getCode();

private:
    long id;
    int resRow;
    char resCol;
    int resCode;
};
