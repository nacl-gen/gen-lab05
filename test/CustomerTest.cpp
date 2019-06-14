#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../src/Customer.h"
#include "../src/pricecode/NewReleasePriceCode.h"
#include "../src/pricecode/ChildrenPriceCode.h"

// Integration test suite for the Customers statement

/**
 * Integration
 * Test statement of new Customer with name
 */
TEST(customer_integration_tests, statementNewCustomerWithName) {

    Customer customer("CustomerName");

    std::string result = customer.statement();
    std::string expected = "Rental Record for CustomerName\nAmount owed is 0\nYou earned 0 frequent renter points";

    EXPECT_EQ(result, expected);
}

/**
 * Integration
 * Test statement of new Customer without name
 */
TEST(customer_integration_tests, statementNewCustomerNoName) {

    Customer customer;

    std::string result = customer.statement();
    std::string expected = "Rental Record for \nAmount owed is 0\nYou earned 0 frequent renter points";

    EXPECT_EQ(result, expected);
}

/**
 * Integration
 * Test statement of Customer after some rentals
 */
TEST(customer_integration_tests, statementWithScenario) {

    Customer customer("Olivier");

    customer.addRental( Rental( Movie("Karate Kid"), 7));
    customer.addRental( Rental( Movie( "Avengers: Endgame", NewReleasePriceCode::getInstance()), 5));
    customer.addRental( Rental( Movie("Snow White", ChildrenPriceCode::getInstance()), 3 ));

    std::string result = customer.statement();
    std::string expected = "Rental Record for Olivier\n\tKarate Kid\t9.5\n"
                           "\tAvengers: Endgame\t15\n"
                           "\tSnow White\t1.5\n"
                           "Amount owed is 26\n"
                           "You earned 4 frequent renter points";

    EXPECT_EQ(result, expected);
}