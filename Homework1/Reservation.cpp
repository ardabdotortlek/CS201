#include <iostream>
#include <ctime>
#include "Reservation.h"
using namespace std;

/**
    @author Arda Barýþ Örtlek
*/

/**
    Constructor
*/
Reservation::Reservation(long movieID, int row, char col, int code){
    Reservation::id = movieID;
    Reservation::resRow = row;
    Reservation::resCol = col;
    Reservation::resCode = code;
}

/**
    Default Constructor
*/
Reservation::Reservation(){
    Reservation::id = 0;
    Reservation::resRow = 0;
    Reservation::resCol = (char) 0;
    Reservation::resCode = 0;
}

int Reservation::getCode(){
    return Reservation::resCode;
}

char Reservation::getCol(){
    return Reservation::resCol;
}

long Reservation::getID(){
    return Reservation::id;
}

int Reservation::getRow(){
    return Reservation::resRow;
}
