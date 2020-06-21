//======================================================================================================================
// Name: Cameron Sherry
// UCInetID: crsherry
// Student ID: 61391595
//======================================================================================================================

#include <iostream>
#include "Director.h"
#include "Movie.h"

int main() {
    Movie movie{};

    movie.details();

    movie.set_movie_duration(420);
    movie.set_movie_year(6969);
    movie.set_movie_price_USD(3.14);
    movie.set_movie_title("Cameron's Adventure!");

    movie.director.set_first_name("Cameron");
    movie.director.set_last_name("Sherry");
    movie.director.set_birth_year(1999);
    movie.director.set_films_directed(1337);

    std::cout << std::endl;
    std::cout << "MOVIE REFRESH: " << std::endl;
    movie.details();

    Movie reboot_movie{movie};

    std::cout << std::endl;
    std::cout << "REBOOT: " << std::endl;
    reboot_movie.details();

    reboot_movie.director.set_films_directed(reboot_movie.director.get_films_directed() + 1);

    std::cout << std::endl;
    std::cout << "REBOOT REFRESH: " << std::endl;
    reboot_movie.details();
}