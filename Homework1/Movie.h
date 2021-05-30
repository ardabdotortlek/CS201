#pragma once
#include <iostream>
using namespace std;

/**
    @author Arda Barýþ Örtlek
*/

class Movie {

public:
	Movie(const long movieID, const int audienceRadius);
	Movie();
	~Movie();
    Movie& operator=(const Movie& right );
	void printInformation();
	void printDetailedInformation();
	int generateUniqueReservation(const int row, const char col);
	long getMovieID();
	int getAudienceRadius();
	void makeAvailable(const int row, const char col);
	char* seats;

private:

	long movieID;
	int audienceRadius;
	int availableSeats;
	int availableRow;
	int availableColumn;
};
