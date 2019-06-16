#include <utility>

#include "Movie.h"

std::ostream& operator<< (std::ostream& ostream, const Movie& movie) {
    return ostream << movie.getTitle();
}

double Movie::getPrice(int daysRented) const {
    return _priceCode->computePrice(daysRented);
}

int Movie::getBonus() const {
    return _priceCode->getBonusPoints();
}
 