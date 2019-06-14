// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"
#include <ostream>

class Rental {
public:
    Rental( const Movie& movie, int daysRented );

    int getDaysRented() const;
    const Movie& getMovie() const;
    double computeAmount() const;
    int getBonusPoints() const;

    friend std::ostream& operator<< (std::ostream& ostream, const Rental& rental);


private:
    Movie _movie;
    int _daysRented;
};

inline Rental::
Rental( const Movie& movie, int daysRented )
        : _movie( movie )
        , _daysRented( daysRented ) {}

inline int Rental::
getDaysRented() const { return _daysRented; }

inline const Movie& Rental::
getMovie() const { return _movie; }

#endif // RENTAL_H