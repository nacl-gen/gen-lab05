// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"

using std::ostringstream;
using std::vector;

using namespace std;

string Customer::statement()
{
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    vector< Rental >::iterator iter = _rentals.begin();
    vector< Rental >::iterator iter_end = _rentals.end();
    ostringstream result;
    result << "Rental Record for " << getName() << "\n";
    for ( ; iter != iter_end; ++iter ) {
        double thisAmount = 0;
        Rental each = *iter;

        // determine amounts for each line
        thisAmount += each.computeAmount();

        // add frequent renter points
        frequentRenterPoints++;
        // add bonus for a two day new release rental
        frequentRenterPoints += getBonusPoints(each);

        // show figures for this rental
        result << "\t" << each.getMovie().getTitle() << "\t"
               << thisAmount << "\n";
        totalAmount += thisAmount;
    }
    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";
    return result.str();
}

int Customer::getBonusPoints(const Rental &each) const {
    if ((each.getMovie().getPriceCode() == Movie::NEW_RELEASE ) && each.getDaysRented() > 1 ) {
        return 1;
    }
    return 0;
}