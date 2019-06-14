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

    ostringstream result;

    // add header line
    result << "Rental Record for " << getName() << "\n";

    // add body
    for (const Rental &rental : _rentals) {

        // add frequent renter points
        ++frequentRenterPoints;

        // add bonus for a two day new release rental
        frequentRenterPoints += rental.getBonusPoints();

        // show figures for this rental
        result << "\t" << rental << "\n";

        // add rental price amount to total
        totalAmount += rental.computeAmount();
    }

    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";

    return result.str();
}