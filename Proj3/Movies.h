//
// Created by CamCam on 11/16/2019.
//
#include <string>
#include <iostream>
#include "Renter.h"
#include "Exceptions.cpp"

#ifndef PROJECT3_MOVIES_H
#define PROJECT3_MOVIES_H


class Movies {
private:
    std::string movieCode;
    std::string movieName;
    int rentCount = 0;
    Renter renters[10];
    void sort();
    bool checkUnique(Renter& renter);
    static bool checkValidID(Renter& renter);
    int checkRenterExists(int renterID);
    void fixArrayIndexes(int renterIndex);
public:
    Movies(std::string& movieCode, std::string& movieName);
    void rentMovie(Renter& renter);
    void returnRental(int renterID);
    friend std::ostream& operator<<(std::ostream& os, const Movies& movie);
    std::string getMovieCode();
    int getRentCount();
};


#endif //PROJECT3_MOVIES_H
