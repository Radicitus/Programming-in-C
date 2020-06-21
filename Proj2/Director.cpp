//======================================================================================================================
// Name: Cameron Sherry
// UCInetID: crsherry
// Student ID: 61391595
//======================================================================================================================

#include "Director.h"

Director::Director(std::string first_name, std::string last_name, int birth_year, int films_directed)
    : first_name{first_name}, last_name{last_name}, birth_year{birth_year}, films_directed{films_directed}
    {};

Director::Director()
    : first_name{"first_name"}, last_name{"last_name"}, birth_year{0}, films_directed{0}
    {};

Director::Director(Director &director)
    : first_name{director.first_name}, last_name{director.last_name}, birth_year{director.birth_year}, films_directed{director.films_directed}
    {};

std::string Director::get_first_name() {
    return this->first_name;
}

void Director::set_first_name(std::string first) {
    this->first_name = first;
}

std::string Director::get_last_name() {
    return this->last_name;
}

void Director::set_last_name(std::string last) {
    this->last_name = last;
}

int Director::get_birth_year() {
    return this->birth_year;
}

void Director::set_birth_year(int year) {
    this->birth_year = year;
}

int Director::get_films_directed() {
    return this->films_directed;
}

void Director::set_films_directed(int films) {
    this->films_directed = films;
}