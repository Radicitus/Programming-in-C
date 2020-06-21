//
// Created by CamCam on 11/16/2019.
//
#include "Movies.h"
#include "Renter.h"
#include "MovieManagerUI.h"
#include "Exceptions.cpp"

#ifndef PROJECT3_MOVIEMANAGER_H
#define PROJECT3_MOVIEMANAGER_H


class MovieManager {
private:
    Movies* movies[20]{};
    int movieCount = 0;
    void fixArrayIndexes(int movieIndex);
public:
    void run();
    void addMovie(Movies* m);
    void discontinueMovie(std::string& movieCode);
    void rentMovie(std::string& movieCode, Renter& renter);
    void returnRental(int renterID, std::string& movieCode);
    void printInventory();
};


#endif //PROJECT3_MOVIEMANAGER_H
