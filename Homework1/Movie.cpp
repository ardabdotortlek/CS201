#include <iostream>
#include <cmath>
#include <sstream>
#include <ctime>
#include "MovieBookingSystem.h"
#include "Movie.h"
using namespace std;

/**
    @author Arda Barýþ Örtlek
*/


/**
    Constructor
*/
Movie::Movie(const long movieID, const int audienceRadius) {
	Movie::movieID = movieID;
	Movie::audienceRadius = audienceRadius;
	if (audienceRadius == 0){
		Movie::availableSeats = MovieBookingSystem::numOfRow * MovieBookingSystem::numOfColumn;
		Movie::availableRow = MovieBookingSystem::numOfRow;
		Movie::availableColumn = MovieBookingSystem::numOfColumn;
    }
	else {
		Movie::availableRow =(int) ceil(1.0 * MovieBookingSystem::numOfRow / (audienceRadius+1));
		Movie::availableColumn = (int) ceil(1.0 * MovieBookingSystem::numOfColumn / (audienceRadius+1));
		Movie::availableSeats = Movie::availableRow * Movie::availableColumn;
	}
    Movie::seats = new char[availableSeats];
	for (int i = 0; i < Movie::availableSeats; i++) {
		Movie::seats[i] = 'x';
	}

}

/**
    Default Constructor
*/
Movie::Movie() {
	Movie::movieID = 0;
	Movie::audienceRadius = 0;
	if (Movie::audienceRadius == 0){
		Movie::availableSeats = MovieBookingSystem::numOfRow * MovieBookingSystem::numOfColumn;
		Movie::availableRow = MovieBookingSystem::numOfRow;
		Movie::availableColumn = MovieBookingSystem::numOfColumn;
	}
	else {
		Movie::availableRow = (int)ceil(1.0 * MovieBookingSystem::numOfRow / (audienceRadius + 1));
		Movie::availableColumn = (int)ceil(1.0 * MovieBookingSystem::numOfColumn / (audienceRadius + 1));
		Movie::availableSeats = Movie::availableRow * Movie::availableColumn;
	}
    Movie::seats = NULL;

}

/**
    Destructor
*/
Movie::~Movie(){
    if(seats)
        delete[] seats;
}

/**
    Operator = has been overloaded
*/
Movie& Movie::operator=(const Movie& right){
     movieID = right.movieID;
	 audienceRadius = right.audienceRadius;
	 availableSeats = right.availableSeats;
	 availableRow = right.availableRow;
	 availableColumn = right.availableColumn;

	 if(seats != NULL)
        delete[] seats;

	 seats = new char[right.availableRow * right.availableColumn];


	 for(int i = 0;i < availableRow * availableColumn; i++){
        seats[i] = right.seats[i];
	 }
}

/**
    Prints information of this Movie
*/
void Movie::printInformation() {
    time_t t = movieID;
    string timeRepresentation = ctime(&t);
    timeRepresentation = timeRepresentation.substr(0, timeRepresentation.length()-1);

	cout << "Movie at " << timeRepresentation << " (" << Movie::availableSeats << " available seats)" << endl;
}

/**
    Prints movie with displaying seats with x and o
*/
void Movie::printDetailedInformation() {
    time_t t = movieID;
    string timeRepresentation = ctime(&t);
    timeRepresentation = timeRepresentation.substr(0, timeRepresentation.length()-1);

	cout << "Movie at " << timeRepresentation << " has " << Movie::availableSeats << " available seats" << endl;
	//print cols
	cout << "  ";
	for(int i = 'A'; i <= 'A' + ((Movie::audienceRadius+1)*(availableColumn-1)); i = i + Movie::audienceRadius+1){
        cout << " " << (char) i;
	}
	cout << endl;
	//print rows
	int j = 1;
	for(int i = 0; i < Movie::availableColumn * Movie::availableRow; i++){
        if(i % Movie::availableColumn == 0){
            cout << j;
            if(j < 10){
                cout << " ";
            }
            j = j + Movie::audienceRadius+1;

        }
        cout << " " << Movie::seats[i];
        if(i % Movie::availableColumn == Movie::availableColumn-1){
            cout << endl;
        }

	}
	cout << endl;
}

long Movie::getMovieID() {
	return Movie::movieID;
}

int Movie::getAudienceRadius() {
	return audienceRadius;
}

/**
    Allocates seat for given row and col
    @param row,col
*/
int Movie::generateUniqueReservation(const int row, const char col) {
	//Check whether col is valid
	int lastChar = (Movie::availableColumn - 1) * (Movie::audienceRadius + 1) + (int)'A';
	for (int i = (int)'A'; i <= lastChar; i = i + Movie::audienceRadius + 1) {
		if (col == (char)i) {
			break; //Col is in the range
		}
		else if (i >= lastChar) {
			return -1; //Col is not in the range
		}
	}
	//Check whether row is valid
	int lastRow = 1 + (Movie::availableRow - 1) * (Movie::audienceRadius + 1);
	for (int i = 1; i <= lastRow; i = i + Movie::audienceRadius + 1) {
		if (row == i) {
			break; //Row is in the range
		}
		else if (i >= lastRow) {
			return -2; //Row is not in the range
		}
	}
	//Find the number of rows before given row
	int seatNumber;
	int tempRow = row;
	int rows = 0; //initial value
	while (tempRow > 1) {
		tempRow = tempRow - (Movie::audienceRadius + 1);
		rows = rows + 1;
	}
	seatNumber = rows * Movie::availableColumn; //Until the given row added, there are seatNumber seats
	int seatsAtGivenRow = (int)(col - 'A') / (audienceRadius + 1) + 1;
	seatNumber = seatNumber + seatsAtGivenRow; //Seat number at given row and col
	if (seats[seatNumber - 1] == 'o')  {
		return -3; //Seat has already been occupied
	}
	Movie::seats[seatNumber - 1] = 'o';
	Movie::availableSeats = Movie::availableSeats - 1;
	return 0;
}

/**
    Makes given seat available again
    @param row,col
*/
void Movie::makeAvailable(const int row, const char col){
    int seatNumber;
	int tempRow = row;
	int rows = 0; //initial value
	while (tempRow > 1) {
		tempRow = tempRow - (Movie::audienceRadius + 1);
		rows = rows + 1;
	}
	seatNumber = rows * Movie::availableColumn; //Until the given row added, there are seatNumber seats
	int seatsAtGivenRow = (int)(col - 'A') / (audienceRadius + 1) + 1;
	seatNumber = seatNumber + seatsAtGivenRow; //Seat number at given row and col
	Movie::seats[seatNumber - 1] = 'x';
	Movie::availableSeats = Movie::availableSeats + 1;
}

