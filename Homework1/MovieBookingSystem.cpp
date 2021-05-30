#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "MovieBookingSystem.h"
#include "Movie.h"
#include "Reservation.h"
using namespace std;

/**
    @author Arda Barýþ Örtlek
*/


/**
    Constructor
*/
MovieBookingSystem::MovieBookingSystem() {
	MovieBookingSystem::numOfMovies = 0; //Initially, there is no movie
	MovieBookingSystem::numOfReservations = 0; //Initially, there is no reservation
	MovieBookingSystem::listOfMovies = NULL;
	MovieBookingSystem::listOfReservations = NULL;
	srand((unsigned) time(NULL));
}

/**
    Deconstructor
*/
MovieBookingSystem::~MovieBookingSystem() {
	delete[] listOfMovies;
	listOfMovies = NULL;
	delete[] listOfReservations;
	listOfReservations = NULL;
}

/**
    Function for searching movie ID
    @param movieID
    @return index
*/
int MovieBookingSystem::searchForMovie(const long movieID) {
	if (MovieBookingSystem::listOfMovies == NULL)
		return -1;

	else {
		for (int i = 0; i < MovieBookingSystem::numOfMovies; i++) {
			if (MovieBookingSystem::listOfMovies[i].getMovieID() == movieID)
				return i;
		}
		return -1;
	}
}

/**
    Function for adding new movie
    @param movieID, audienceRadius
*/
void MovieBookingSystem::addMovie(const long movieID, const int audienceRadius) {
    if (MovieBookingSystem::searchForMovie(movieID) != -1) {
        cout << "Movie at " << MovieBookingSystem::timeRepresantation(movieID) << " already exist." << endl;
		return;
	}
	if (audienceRadius < 0 || audienceRadius > 7) {
		cout << "Invalid audience radius" << endl;
		return;
	}
	Movie* tempList = MovieBookingSystem::listOfMovies;
	MovieBookingSystem::listOfMovies = new Movie[numOfMovies + 1];
	 if(tempList != NULL){
        for (int i = 0; i < MovieBookingSystem::numOfMovies; i++) {
            MovieBookingSystem::listOfMovies[i] = tempList[i];
        }
    }

	MovieBookingSystem::listOfMovies[numOfMovies] = Movie(movieID,audienceRadius);
	MovieBookingSystem::numOfMovies = MovieBookingSystem::numOfMovies + 1;
	delete[] tempList;
	tempList = NULL;
	cout << "Movie at " << MovieBookingSystem::timeRepresantation(movieID) << " has been added" << endl;
}

/**
    Function for canceling movie with given ID
    @param movieID
*/
void MovieBookingSystem::cancelMovie(const long movieID) {

	int searchCode = MovieBookingSystem::searchForMovie(movieID);

	if(searchCode == -1){
        cout << "Movie at " << MovieBookingSystem::timeRepresantation(movieID) << " does not exist" << endl;
        return;
	}

	//First delete all of its reservations
    if(MovieBookingSystem::listOfReservations != NULL){
        for(int i = 0; i < MovieBookingSystem::numOfReservations; i++){
            if(MovieBookingSystem::listOfReservations[i].getID() == movieID){
                Reservation* tempResList = MovieBookingSystem::listOfReservations;
                if(MovieBookingSystem::numOfReservations - 1 == 0){
                    MovieBookingSystem::listOfReservations = NULL;
                }
                else{
                    MovieBookingSystem::listOfReservations = new Reservation[numOfReservations - 1];
                    for(int j = 0; j < i; j++){
                        MovieBookingSystem::listOfReservations[j] = tempResList[j];
                    }

                    for(int j = i + 1; j < MovieBookingSystem::numOfReservations; j++){
                        MovieBookingSystem::listOfReservations[j - 1] = tempResList[j];
                    }
                }
                delete[] tempResList;
                MovieBookingSystem::numOfReservations = MovieBookingSystem::numOfReservations - 1;
                i = i - 1;
            }
        }
	}

	//Secondly, delete it from movies
	Movie* tempMovieList = listOfMovies;
	MovieBookingSystem::listOfMovies = new Movie[numOfMovies - 1];
	for(int i = 0; i < searchCode; i++){
        MovieBookingSystem::listOfMovies[i] = tempMovieList[i];
	}

	for(int i = searchCode + 1; i < MovieBookingSystem::numOfMovies; i++){
        MovieBookingSystem::listOfMovies[i-1] = tempMovieList[i];
	}

	delete[] tempMovieList;
	tempMovieList = NULL;
	MovieBookingSystem::numOfMovies = MovieBookingSystem::numOfMovies - 1;

	if(MovieBookingSystem::numOfMovies == 0){
        MovieBookingSystem::listOfMovies = NULL;
	}

    cout << "Movie at " << MovieBookingSystem::timeRepresantation(movieID) << " has been canceled" << endl;

}

/**
    Function which prints details of movies
*/
void MovieBookingSystem::showAllMovies() {
	if(MovieBookingSystem::numOfMovies == 0){
        cout << "No movie on show" << endl;
        return;
	}
	else{
        cout << "Movies on show: " << endl;
        for(int i = 0; i < MovieBookingSystem::numOfMovies; i++){
            MovieBookingSystem::listOfMovies[i].printInformation();
        }
	}
}

/**
    Function for printing movie with given ID
    @param movieID
*/
void MovieBookingSystem::showMovie(const long movieID) {
	int index = MovieBookingSystem::searchForMovie(movieID);

	if(index == -1){
        cout << "There is no movie with given ID" << endl;
	}

	else{
        MovieBookingSystem::listOfMovies[index].printDetailedInformation();
	}
}

/**
    Function for making reservation
    @param movieID,row,col
    @return code
*/
int MovieBookingSystem::makeReservation(const long movieID, const int row, const char col) {
	int index = MovieBookingSystem::searchForMovie(movieID);
	if(index == -1){
        cout << "There is no movie with given ID" << endl;
        return -1;
	}
	int result = MovieBookingSystem::listOfMovies[index].generateUniqueReservation(row,col);
	if(result == -1){
        cout << "Seat " << col << row << " is not occupiable in Movie at " << MovieBookingSystem::timeRepresantation(movieID) << endl;
        return -1;
	}
	else if(result == -2){
        cout << "Seat " << col << row << " is not occupiable in Movie at " << MovieBookingSystem::timeRepresantation(movieID) << endl;
        return -1;
	}
	else if(result == -3){
        cout << "Seat " << col << row << " is not occupiable in Movie at " << MovieBookingSystem::timeRepresantation(movieID) << endl;
        return -1;
	}

    int code = rand();
	Reservation* tempList = MovieBookingSystem::listOfReservations;
	MovieBookingSystem::listOfReservations = new Reservation[numOfReservations+1];
	if(tempList != NULL){
        for (int i = 0; i < MovieBookingSystem::numOfReservations; i++) {
            MovieBookingSystem::listOfReservations[i] = tempList[i];
        }
    }
	MovieBookingSystem::listOfReservations[numOfReservations] = Reservation(movieID,row,col,code);
	MovieBookingSystem::numOfReservations = MovieBookingSystem::numOfReservations + 1;
	delete[] tempList;
    tempList = NULL;
    cout << "Reservation done for " << col << row << " in Movie at " << MovieBookingSystem::timeRepresantation(movieID) << endl;

    return code;
}

/**
    Function for canceling reservation
    @param numRes,resCode
*/
void MovieBookingSystem::cancelReservations(const int numRes, const int* resCode) {
    for(int i = 0; i < numRes; i++){
        int searchCode = MovieBookingSystem::searchForReservationViaCode(resCode[i]);
        if(searchCode == -1){
            cout << "Some of the codes do not exist. Cancelation is failed" << endl;
            return;
        }

    }

    for(int i = 0; i < numRes; i++){
        int searchCode = MovieBookingSystem::searchForReservationViaCode(resCode[i]);

        //Cancel/delete reservation
        cout << "Reservation on code " << resCode[i] << " is canceled: Seat " << MovieBookingSystem::listOfReservations[searchCode].getCol() << MovieBookingSystem::listOfReservations[searchCode].getRow() << " in Movie at " << timeRepresantation(listOfReservations[searchCode].getID()) << endl;

        MovieBookingSystem::listOfMovies[searchForMovie(listOfReservations[searchCode].getID())].makeAvailable(listOfReservations[searchCode].getRow(),listOfReservations[searchCode].getCol());


        Reservation* tempList = MovieBookingSystem::listOfReservations;
        if(MovieBookingSystem::numOfReservations - 1 == 0){
            MovieBookingSystem::listOfReservations = NULL;
        }
        else{
            MovieBookingSystem::listOfReservations = new Reservation[numOfReservations-1];

            for(int j = 0 ; j < searchCode; j++){
                MovieBookingSystem::listOfReservations[j] = tempList[j];
            }

            for(int j = searchCode + 1; j < MovieBookingSystem::numOfReservations; j++){
                MovieBookingSystem::listOfReservations[j-1] = tempList[j];
            }
        }

        delete[] tempList;
        tempList = NULL;
        MovieBookingSystem::numOfReservations = MovieBookingSystem::numOfReservations - 1;
    }

}

/**
    Function for printing reservation given resCode
    @param resCode
*/
void MovieBookingSystem::showReservation(const int resCode) {
    int searchCode = MovieBookingSystem::searchForReservationViaCode(resCode);
    if(searchCode == -1){
        cout << "No reservation with code " << resCode << endl;
        return;
    }

    cout << "Reservation with code " << resCode << ": Seat " << MovieBookingSystem::listOfReservations[searchCode].getCol() << MovieBookingSystem::listOfReservations[searchCode].getRow() << " in Movie at " << timeRepresantation(listOfReservations[searchCode].getID()) << endl;

}

/**
    Function for searching reservation
    @param numRes
    @return index
*/
int MovieBookingSystem::searchForReservationViaCode(const int numRes){
    if(MovieBookingSystem::numOfReservations == 0)
        return -1;
    for(int i = 0; i < MovieBookingSystem::numOfReservations; i++){
        if(MovieBookingSystem::listOfReservations[i].getCode() == numRes)
            return i;
    }
    return -1;
}

/**
    Function for printing time represantation of movie
    @param movieID
    @return timeRepresentation
*/
string MovieBookingSystem::timeRepresantation(const long movieID){
    time_t t = movieID;
    string timeRepresentation = ctime(&t);
    timeRepresentation = timeRepresentation.substr(0, timeRepresentation.length()-1);
    return timeRepresentation;
}





