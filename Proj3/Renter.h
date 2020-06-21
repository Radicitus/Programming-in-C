//
// Created by CamCam on 11/16/2019.
//
#include <string>

#ifndef PROJECT3_RENTER_H
#define PROJECT3_RENTER_H


class Renter {
private:
    int renterID;
    std::string firstName;
    std::string lastName;

public:
    Renter(int renterID, std::string& firstName, std::string& lastName);
    Renter();
    int getID() const;
    std::string getFirstName() const;
    std::string getLastName() const;
};


#endif //PROJECT3_RENTER_H
