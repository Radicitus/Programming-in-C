//======================================================================================================================
// Name: Cameron Sherry
// UCInetID: crsherry
// Student ID: 61391595
//======================================================================================================================

#ifndef PROJECT2_DIRECTOR_H
#define PROJECT2_DIRECTOR_H


#include <string>

class Director {
private:
    std::string first_name;
    std::string last_name;
    int birth_year;
    int films_directed;
public:
    Director(std::string first_name, std::string last_name, int birth_year, int films_directed);
    Director();
    Director(Director &director);

    std::string get_first_name();
    void set_first_name(std::string first);
    std::string get_last_name();
    void set_last_name(std::string last);
    int get_birth_year();
    void set_birth_year(int year);
    int get_films_directed();
    void set_films_directed(int films);
};


#endif //PROJECT2_DIRECTOR_H
