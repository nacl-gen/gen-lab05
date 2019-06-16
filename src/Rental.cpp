#include "Rental.h"

double Rental::computeAmount() const {
    return _movie.getPrice(getDaysRented());
}

int Rental::getBonusPoints() const {
    if(_daysRented > 1) {
        return _movie.getBonus();
    }
    return 0;
}

std::ostream& operator<< (std::ostream& ostream, const Rental& rental) {
    return ostream << rental._movie << "\t" << rental.computeAmount();
}

