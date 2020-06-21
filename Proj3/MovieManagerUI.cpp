//======================================================================================================================
// Name: Cameron Sherry
// UCInetID: crsherry
// Student ID: 61391595
//======================================================================================================================

#include <algorithm>
#include "MovieManagerUI.h"

//This prints out the menu of commands
void MovieManagerUI::printMenu() {
    std::cout << "Menu:" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "am: Add Movie" << std::endl;
    std::cout << "dm: Discontinue Movie" << std::endl;
    std::cout << "rm: Rent Movie" << std::endl;
    std::cout << "rr: Return Rental" << std::endl;
    std::cout << "p: Print Movie Inventory" << std::endl;
    std::cout << "q: Quit Program" << std::endl;
    std::cout << "------------------------------" << std::endl;
}

//This gets standard input from the console
std::string MovieManagerUI::getInput() {
    std::string input;
    std::getline(std::cin, input);
    std::for_each(input.begin(), input.end(), [](char & c) {
        c = ::tolower(c);
    });
    return input;
}

//This converts console input to commands and loops until it gets a valid one to return
std::string MovieManagerUI::getCommand() {
    while (true) {
        std::cout << "Enter Command:" << std::endl;
        std::string command = getInput();
        if (command == "am") {
            return "am";
        }
        if (command == "dm") {
            return "dm";
        }
        if (command == "rm") {
            return "rm";
        }
        if (command == "rr") {
            return "rr";
        }
        if (command == "p") {
            return "p";
        }
        if (command == "q") {
            return "q";
        }
        std::cout << "You have not entered a valid command, please try again." << std::endl;
    }
}

//This double checks some exception conditions and returns a string from the console
std::string MovieManagerUI::getMovieInfo() {
    std::string info = getInput();
    if (info.empty()) {
        throw EmptyMovieInfoException();
    }
    return info;
}

//This double checks some exception conditions and returns a string from the console
std::string MovieManagerUI::getRenterInfo() {
    std::string info = getInput();
    if (info.empty()) {
        throw EmptyRenterNameException();
    }
    return info;
}

//This double checks some exception conditions and returns a int from the console
int MovieManagerUI::getRenterID() {
    int ID = std::stoi(getInput());
    if (ID < 0) {
        throw InvalidRenterIDException();
    }
    return ID;
}