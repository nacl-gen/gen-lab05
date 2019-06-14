#include <utility>

// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"
#include <ostream>

class Rental {
public:
    Rental(Movie movie, int daysRented );

    int getDaysRented() const;
    double computeAmount() const;
    int getBonusPoints() const;

    friend std::ostream& operator<< (std::ostream& ostream, const Rental& rental);


private:
    Movie _movie;
    int _daysRented;
};

inline Rental::
Rental(Movie movie, int daysRented )
        : _movie(std::move(movie))
        , _daysRented( daysRented ) {}

inline int Rental::
getDaysRented() const { return _daysRented; }

#endif // RENTAL_H