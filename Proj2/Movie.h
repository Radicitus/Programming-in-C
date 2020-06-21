//======================================================================================================================
// Name: Cameron Sherry
// UCInetID: crsherry
// Student ID: 61391595
//======================================================================================================================

#ifndef PROJECT2_MOVIE_H
#define PROJECT2_MOVIE_H


#include <string>
#include "Director.h"

class Movie {
public:
    Director director{};
private:
    int movie_duration;
    int movie_year;
    double movie_price_USD;
    std::string movie_title;
public:
    Movie(int movie_duration, int movie_year, double movie_price, std::string& movie_title, Director& director);
    Movie();
    Movie(Movie &movie);

    Director get_Director();
    int get_movie_duration();
    void set_movie_duration(int duration);
    int get_movie_year();
    void set_movie_year(int year);
    double get_movie_price_USD();
    void set_movie_price_USD(double price);
    std::string get_movie_title();
    void set_movie_title(std::string title);

    void details();
};


#endif //PROJECT2_MOVIE_H
