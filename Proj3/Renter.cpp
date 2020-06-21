//======================================================================================================================
// Name: Cameron Sherry
// UCInetID: crsherry
// Student ID: 61391595
//======================================================================================================================

#include "Renter.h"

//This is the constructor for the Renter class, taking three parameters
Renter::Renter(int renterID, std::string& firstName, std::string& lastName) {
    this->renterID = renterID;
    this->firstName = firstName;
    this->lastName = lastName;
}

//This is the default constructor for the Renter class, taking no parameters
Renter::Renter() {
    this->renterID = -1;
    this->firstName = "";
    this->lastName = "";
}

//This returns an integer representing the renter's ID
int Renter::getID() const {
   return this->renterID;
}

//This returns an string representing the renter's first name
std::string Renter::getFirstName() const {
    return this->firstName;
}

//This returns an string representing the renter's last name
std::string Renter::getLastName() const {
    return this->lastName;
}