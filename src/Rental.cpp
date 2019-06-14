#include "Rental.h"

double Rental::computeAmount() const {
    double amount = 0;
    switch ( getMovie().getPriceCode() ) {
        case Movie::REGULAR:
            amount += 2;
            if ( getDaysRented() > 2 )
                amount += ( getDaysRented() - 2 ) * 1.5 ;
            break;
        case Movie::NEW_RELEASE:
            amount += getDaysRented() * 3;
            break;
        case Movie::CHILDRENS:
            amount += 1.5;
            if ( getDaysRented() > 3 )
                amount += ( getDaysRented() - 3 ) * 1.5;
            break;
    }
    return amount;
}

int Rental::getBonusPoints() const {
    if ((getMovie().getPriceCode() == Movie::NEW_RELEASE ) && getDaysRented() > 1 ) {
        return 1;
    }
    return 0;
}

std::ostream& operator<< (std::ostream& ostream, const Rental& rental) {
    ostream << rental.getMovie() << "\t"
            << rental.computeAmount();
    return ostream;
}

