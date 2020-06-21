//======================================================================================================================
// Name: Cameron Sherry
// UCInetID: crsherry
// Student ID: 61391595
//======================================================================================================================

#include <iostream>
#include "Movie.h"

Movie::Movie(int duration, int year, double price, std::string& title, Director& director)
    : movie_duration{duration}, movie_year{year}, movie_price_USD{price}, movie_title{title}, director{director}
    {};

Movie::Movie()
    : movie_duration{0}, movie_year{0}, movie_price_USD{0.00}, movie_title{""}, director{}
    {};

Movie::Movie(Movie &movie)
    : movie_duration{movie.movie_duration}, movie_year{movie.movie_year}, movie_price_USD{movie.movie_price_USD}, movie_title{movie.movie_title}, director{movie.director}
    {};

Director Movie::get_Director() {
    return this->director;
}

int Movie::get_movie_duration() {
    return this->movie_duration;
}

void Movie::set_movie_duration(int duration) {
    this->movie_duration = duration;
}

int Movie::get_movie_year() {
    return this->movie_year;
}

void Movie::set_movie_year(int year) {
    this->movie_year = year;
}

double Movie::get_movie_price_USD() {
    return this->movie_price_USD;
}

void Movie::set_movie_price_USD(double price) {
    this->movie_price_USD = price;
}

std::string Movie::get_movie_title() {
    return this->movie_title;
}

void Movie::set_movie_title(std::string title) {
    this->movie_title = title;
}

void Movie::details() {
    std::cout << "Title: " << this->movie_title << " Published in: " << this->movie_year << std::endl;
    std::cout << std::endl;
    std::cout << "Duration of Movie: " << this->movie_duration << " minutes" << std::endl;
    std::cout << std::endl;
    std::cout << "Price: $" << this->movie_price_USD << std::endl;
    std::cout << std::endl;
    std::cout << "Directed by " << this->director.get_first_name() << " ";
    std::cout << this->director.get_last_name() << ", who was born in ";
    std::cout << this->director.get_birth_year() << " and has " << this->director.get_films_directed();
    std::cout << " releases." << std::endl;
}