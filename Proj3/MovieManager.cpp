//======================================================================================================================
// Name: Cameron Sherry
// UCInetID: crsherry
// Student ID: 61391595
//======================================================================================================================

#include "MovieManager.h"

//Fixes the consecutive indexing of the array after discontinuing a movie
void MovieManager::fixArrayIndexes(int movieIndex) {
    for (int i = movieIndex; i < movieCount - 1; ++i) {
        movies[i] = movies[i + 1];
    }
}

//The core run function, it controls the flow of the program
void MovieManager::run() {
    std::cout << "Welcome to Movie Rental Kiosk\n" << std::endl;
    while (true) {
        MovieManagerUI::printMenu();
        std::string command = MovieManagerUI::getCommand();
        try {
            if (command == "am") {
                std::cout << "Please enter a movie code:" << std::endl;
                std::string code = MovieManagerUI::getMovieInfo();
                std::cout << "Please enter a movie name:" << std::endl;
                std::string name = MovieManagerUI::getMovieInfo();
                auto* movie = new Movies(code, name);
                addMovie(movie);
            }
            if (command == "dm") {
                std::cout << "Please enter a movie code:" << std::endl;
                std::string code = MovieManagerUI::getMovieInfo();
                discontinueMovie(code);
            }
            if (command == "rm") {
                std::cout << "Please enter a movie code:" << std::endl;
                std::string code = MovieManagerUI::getMovieInfo();
                std::cout << "Please enter a renter ID:" << std::endl;
                int ID = MovieManagerUI::getRenterID();
                std::cout << "Please enter the First Name of the renter:" << std::endl;
                std::string firstName = MovieManagerUI::getRenterInfo();
                std::cout << "Please enter the Last Name of the renter:" << std::endl;
                std::string lastName = MovieManagerUI::getRenterInfo();
                Renter renter = Renter(ID, firstName, lastName);
                rentMovie(code, renter);
            }
            if (command == "rr") {
                std::cout << "Please enter a movie code:" << std::endl;
                std::string code = MovieManagerUI::getMovieInfo();
                std::cout << "Please enter a renter ID:" << std::endl;
                int ID = MovieManagerUI::getRenterID();
                returnRental(ID, code);
            }
            if (command == "p") {
                std::cout << "Movie inventory is: " << std::endl;
                printInventory();
            }
            if (command == "q") {
                exit(0);
            }
        } catch (RenterLimitException &exception) {
            std::cout << "Exception Caught: " << exception.errorMessage() << "\n" << std::endl;
        } catch (DuplicateRenterException &exception) {
            std::cout << "Exception Caught: " << exception.errorMessage() << "\n" << std::endl;
        } catch (InvalidRenterIDException &exception) {
            std::cout << "Exception Caught: " << exception.errorMessage() << "\n" << std::endl;
        } catch (EmptyRenterListException &exception) {
            std::cout << "Exception Caught: " << exception.errorMessage() << "\n" << std::endl;
        } catch (RenterNotFoundException &exception) {
            std::cout << "Exception Caught: " << exception.errorMessage() << "\n" << std::endl;
        } catch (EmptyMovieInfoException &exception) {
            std::cout << "Exception Caught: " << exception.errorMessage() << "\n" << std::endl;
        } catch (DuplicateMovieException &exception) {
            std::cout << "Exception Caught: " << exception.errorMessage() << "\n" << std::endl;
        } catch (MovieLimitException &exception) {
            std::cout << "Exception Caught: " << exception.errorMessage() << "\n" << std::endl;
        } catch (MovieNotFoundException &exception) {
            std::cout << "Exception Caught: " << exception.errorMessage() << "\n" << std::endl;
        } catch (EmptyMovieListException &exception) {
            std::cout << "Exception Caught: " << exception.errorMessage() << "\n" << std::endl;
        } catch (EmptyRenterNameException &exception) {
            std::cout << "Exception Caught: " << exception.errorMessage() << "\n" << std::endl;
        } catch (RentedMovieException &exception) {
            std::cout << "Exception Caught: " << exception.errorMessage() << "\n" << std::endl;
        }
    }
}

//This double checks certain exception conditions and adds a movie to the movie array
void MovieManager::addMovie(Movies* m) {
    if (movieCount == 20) {
        throw MovieLimitException();
    }
    for (int i = 0; i < movieCount; ++i) {
        if (m->getMovieCode() == movies[i]->getMovieCode()) {
            throw DuplicateMovieException();
        }
    }
    movies[movieCount] = m;
    movieCount++;
}

//This double checks certain exception conditions and removes a movie from the movie array
void MovieManager::discontinueMovie(std::string& movieCode) {
    if (movieCount == 0) {
        throw EmptyMovieListException();
    }
    for (int i = 0; i < movieCount; ++i) {
        if (movies[i]->getMovieCode() == movieCode) {
            if (movies[i]->getRentCount() > 0) {
                throw RentedMovieException();
            }
            else {
                delete movies[i];
                fixArrayIndexes(i);
                movieCount--;
                return;
            }
        }
    }
    throw MovieNotFoundException();
}

//This double checks certain exception conditions and adds a renter to a movie
void MovieManager::rentMovie(std::string& movieCode, Renter& renter) {
    for (int i = 0; i < movieCount; ++i) {
        if (movies[i]->getMovieCode() == movieCode) {
            movies[i]->rentMovie(renter);
            return;
        }
    }
    throw MovieNotFoundException();
}

//This double checks certain exception conditions and removes a renter from a movie
void MovieManager::returnRental(int renterID, std::string& movieCode) {
    for (int i = 0; i < movieCount; ++i) {
        if (movies[i]->getMovieCode() == movieCode) {
            movies[i]->returnRental(renterID);
            return;
        }
    }
    throw MovieNotFoundException();
}

//This uses the overloaded << operator in the movie class to print the inventory of movies
void MovieManager::printInventory() {
    for (int i = 0; i < movieCount; ++i) {
        std::cout << *movies[i] << std::endl;
    }
}

