//======================================================================================================================
// Name: Cameron Sherry
// UCInetID: crsherry
// Student ID: 61391595
//======================================================================================================================

#include <exception>
#ifndef PROJECT3_EXCEPTIONS_CPP_
#define PROJECT3_EXCEPTIONS_CPP_

struct DuplicateMovieException:public std::exception {
public:
    const char * errorMessage () const noexcept{
        return "You are trying to add a movie, but that movie already exists...";
    }
};

struct MovieLimitException:public std::exception {
public:
    const char * errorMessage () const noexcept{
        return "You are trying to add a movie, but you have already reached the maximum allowed...";
    }
};

struct EmptyMovieInfoException:public std::exception {
public:
    const char * errorMessage () const noexcept{
        return "The movie code or name is empty...";
    }
};

struct MovieNotFoundException:public std::exception {
public:
    const char * errorMessage () const noexcept{
        return "The movie does not exist...";
    }
};

struct EmptyMovieListException:public std::exception {
public:
    const char * errorMessage () const noexcept{
        return "You are trying to return or discontinue a movie, but the inventory list is empty...";
    }
};

struct EmptyRenterListException:public std::exception {
public:
    const char * errorMessage () const noexcept{
        return "You are trying to return a movie, but the movie has no renters...";
    }
};

struct RenterLimitException:public std::exception {
public:
    const char * errorMessage () const noexcept{
        return "You are trying to rent a movie, but the movie has no available copies...";
    }
};

struct RenterNotFoundException:public std::exception {
public:
    const char * errorMessage () const noexcept{
        return "You are trying to remove a renter, but the renter does not exist...";
    }
};

struct DuplicateRenterException:public std::exception {
public:
    const char * errorMessage () const noexcept{
        return "You are trying to add a renter, but that renter ID already exists...";
    }
};

struct InvalidRenterIDException:public std::exception {
public:
    const char * errorMessage () const noexcept{
        return "You have entered an invalid renter ID...";
    }
};

struct EmptyRenterNameException:public std::exception {
public:
    const char * errorMessage () const noexcept{
        return "You are trying to create a renter, but the first or last name is empty...";
    }
};

struct RentedMovieException:public std::exception {
public:
    const char * errorMessage () const noexcept{
        return "You are trying to discontinue a movie, but some copies are still being rented out...";
    }
};

#endif