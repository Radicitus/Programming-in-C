//======================================================================================================================
// Name: Cameron Sherry
// UCInetID: crsherry
// Student ID: 61391595
//======================================================================================================================

#include "Movies.h"

//This is the constructor for the Movie class, taking two parameters
Movies::Movies(std::string& movieCode, std::string& movieName) {
    if (movieCode.empty() || movieName.empty()) {
        throw EmptyMovieInfoException();
    }
    this->movieCode = movieCode;
    this->movieName = movieName;
}

//This function sorts the array of Renters stored in the class, making sure they are sorted lexicographically or by ID
void Movies::sort() {
    for (int i = 0; i < rentCount - 1; i++) {
        for (int j = i + 1; j < rentCount; j++) {
            if (std::string(renters[i].getLastName()) == renters[j].getLastName()) {
                if (renters[i].getID() > renters[j].getID()) {
                    Renter temp = renters[i];
                    renters[i] = renters[j];
                    renters[j] = temp;
                    continue;
                }
            }
            if (std::string(renters[i].getLastName()) > renters[j].getLastName()) {
                Renter temp = renters[i];
                renters[i] = renters[j];
                renters[j] = temp;
                continue;
            }
        }
    }
}

//This checks if a renter's ID is unique to the movie
bool Movies::checkUnique(Renter& renter) {
    for (int i = 0; i < rentCount; i++) {
        if (renters[i].getID() == renter.getID()) {
            return false;
        }
    }
    return true;
}

//This checks to make sure the renter's ID is valid, so greater than 1
bool Movies::checkValidID(Renter& renter) {
    return renter.getID() > 0;
}

//This checks the renter array to see if the renter exists
int Movies::checkRenterExists(int renterID) {
    for (int i = 0; i < rentCount; ++i) {
        if (renters[i].getID() == renterID) {
            return i;
        }
    }
    return -1;
}

//Fixes the consecutive indexing of the renter array after returning a movie
void Movies::fixArrayIndexes(int renterIndex) {
    for (int i = renterIndex; i < rentCount - 1; ++i) {
        renters[i] = renters[i + 1];
    }
}

//This handles double checking exception conditions before adding a renter to the renter array
void Movies::rentMovie(Renter& renter) {
    if (rentCount == 10) {
        throw RenterLimitException();
    }
    if (!checkUnique(renter)) {
        throw DuplicateRenterException();
    }
    if (!checkValidID(renter)) {
        throw InvalidRenterIDException();
    }
    renters[rentCount] = renter;
    rentCount++;
    sort();
}

//This handles double checking exception conditions before removing a renter from the renter array
void Movies::returnRental(int renterID) {
    if (rentCount == 0) {
        throw EmptyRenterListException();
    }
    int exists = checkRenterExists(renterID);
    if (exists == -1) {
        throw RenterNotFoundException();
    }
    fixArrayIndexes(exists);
    rentCount--;
}

//This overloads the << operator
std::ostream& operator<<(std::ostream& os, const Movies& movie) {
    os << "Movie Code is: " << movie.movieCode << ", ";
    os << "Movie Name is: " << movie.movieName << ", ";
    os << "Rented Copies is: " << movie.rentCount << ", ";
    os << "List of Renters is: \n";
    for (int i = 0; i < movie.rentCount; ++i) {
        os << " [ID: " << movie.renters[i].getID();
        os << ", Last Name: " << movie.renters[i].getLastName();
        os << ", First Name: " << movie.renters[i].getFirstName() << "]\n";
    }
    return os;
}

//This returns a string representing the movie's code
std::string Movies::getMovieCode() {
    return this->movieCode;
}

//This returns an integer representing the amount of renters renting the movie
int Movies::getRentCount() {
    return this->rentCount;
}
