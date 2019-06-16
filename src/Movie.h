#include <utility>

// Movie.h
#ifndef MOVIE_H
#define MOVIE_H
#include <string>

#include "pricecode/PriceCode.h"
#include "pricecode/RegularPriceCode.h"

class Movie {
public:

    explicit Movie(std::string title, PriceCode& priceCode = RegularPriceCode::getInstance());

    friend std::ostream& operator<< (std::ostream& ostream, const Movie& movie);

    virtual double getPrice(int daysRented) const;

    virtual int getBonus() const;

    void setPriceCode( PriceCode& priceCode );

    std::string getTitle() const;

private:
    std::string _title;
    PriceCode* _priceCode;
};

inline Movie::
Movie(std::string title, PriceCode& priceCode )
        : _title(std::move(title))
        , _priceCode( &priceCode )
{}

inline void Movie::
setPriceCode( PriceCode& priceCode ) { _priceCode = &priceCode; }

inline std::string Movie::
getTitle() const { return _title; }

#endif // MOVIE_H