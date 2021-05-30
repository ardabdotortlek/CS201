#pragma once
#include <iostream>
#include <sstream>
#include <cmath>
#include "Movie.h"
#include "Reservation.h"
using namespace std;

/**
    @author Arda Barýþ Örtlek
*/


class MovieBookingSystem {
public:
	const static int numOfRow = 30;
	const static int numOfColumn = 26;
	MovieBookingSystem();
	~MovieBookingSystem();
	void addMovie(const long movieID, const int audienceRadius);
	void cancelMovie(const long movieID);
	void showAllMovies();
	void showMovie(const long movieID);
	int makeReservation(const long movieID, const int row, const char col);
	void cancelReservations(const int numRes, const int* resCode);
	void showReservation(const int resCode);

private:
    Movie* listOfMovies;
	Reservation* listOfReservations;
	int numOfMovies;
	int numOfReservations;
	int searchForMovie(const long movieID);
	int searchForReservationViaCode(const int numRes);
    string timeRepresantation(const long movieID);
};

