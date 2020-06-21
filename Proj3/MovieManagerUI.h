//
// Created by CamCam on 11/16/2019.
//
#include <string>
#include <iostream>
#include "Exceptions.cpp"

#ifndef PROJECT3_MOVIEMANAGERUI_H
#define PROJECT3_MOVIEMANAGERUI_H


class MovieManagerUI {
public:
    static void printMenu();
    static std::string getInput();
    static std::string getCommand();

    //Getter functions for standard input from console.
    static std::string getMovieInfo();
    static std::string getRenterInfo();
    static int getRenterID();
};


#endif //PROJECT3_MOVIEMANAGERUI_H
