#include <iostream>

#include "Customer.h"
#include "pricecode/NewReleasePriceCode.h"
#include "pricecode/ChildrenPriceCode.h"

int main() {

    Customer customer("Olivier");
    customer.addRental( Rental( Movie("Karate Kid"), 7));
    customer.addRental( Rental( Movie( "Avengers: Endgame", NewReleasePriceCode::getInstance() ), 5));
    customer.addRental( Rental( Movie("Snow White", ChildrenPriceCode::getInstance()), 3 ));

    std::cout << customer.statement() << std::endl;

    return 0;
}