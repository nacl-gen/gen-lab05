#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <ostream>

#include "../src/Rental.h"
#include "../src/pricecode/ChildrenPriceCode.h"
#include "../src/pricecode/NewReleasePriceCode.h"
#include "../src/pricecode/PriceCode.h"

// unit test suite for the Rental class
// but more like integration tests since we didn't mock the dependencies
// didn't manage to make google mock work on non-pure virtual classes :\

/**
 * UnitTest
 * Test rental price computation children with less than 4 rental days
 */
TEST(rental_price_tests, childrenMovieHasRightPriceWithLessThanFourDays) {

    Movie childrenMovie("children movie", ChildrenPriceCode::getInstance());
    Rental rental(childrenMovie, 3);

    double amount = rental.computeAmount();

    double expectedAmount = 1.5;

    EXPECT_EQ(amount, expectedAmount);
}

/**
 * UnitTest
 * Test rental price computation children with more than 3 rental days
 */
TEST(rental_price_tests, childrenMovieHasRightPriceWithMoreThanThreeDays) {

    Movie childrenMovie("children movie", ChildrenPriceCode::getInstance());
    Rental rental(childrenMovie, 4);

    double amount = rental.computeAmount();

    double expectedAmount = 1.5 + (rental.getDaysRented() - 3) * 1.5;


    EXPECT_EQ(amount, expectedAmount);
}

/**
 * UnitTest
 * Test rental price computation new release
 */
TEST(rental_price_tests, newReleaseMovieHasRightPrice) {

    Movie newReleaseMovie("new movie", NewReleasePriceCode::getInstance());
    Rental rental(newReleaseMovie, 2);

    double amount = rental.computeAmount();

    double expectedAmount = rental.getDaysRented() * 3;


    EXPECT_EQ(amount, expectedAmount);
}

/**
 * UnitTest
 * Test rental price computation regular with less than 3 rental days
 */
TEST(rental_price_tests, regularMovieHasRightPriceWithLessThanThreeDays) {

    Movie regularMovie("regular movie", RegularPriceCode::getInstance());
    Rental rental(regularMovie, 2);

    double amount = rental.computeAmount();

    double expectedAmount = 2;

    EXPECT_EQ(amount, expectedAmount);
}

/**
 * UnitTest
 * Test rental price computation regular with more than 2 rental days
 */
TEST(rental_price_tests, regularMovieHasRightPriceWithMoreThanTwoDays) {

    Movie regularMovie("regular movie", RegularPriceCode::getInstance());
    Rental rental(regularMovie, 3);

    double amount = rental.computeAmount();

    double expectedAmount = 2 + (rental.getDaysRented() - 2) * 1.5;


    EXPECT_EQ(amount, expectedAmount);
}

/**
 * UnitTest
 * Test rental bonus computation for more than 1 day rental of a new release
 */
TEST(rental_bonus_tests, newReleaseMovieWithMoreThanOneDayGivesBonus) {

    Movie newMovie("new movie", NewReleasePriceCode::getInstance());
    Rental rental(newMovie, 2);

    double bonus = rental.getBonusPoints();

    double expectedBonus = 1;


    EXPECT_EQ(bonus, expectedBonus);
}

/**
 * UnitTest
 * Test rental bonus computation for less than 2 day rental of new release
 */
TEST(rental_bonus_tests, newReleaseMovieWithLessThanTwoDaysGivesBonus) {

    Movie newMovie("new movie", NewReleasePriceCode::getInstance());
    Rental rental(newMovie, 1);

    double bonus = rental.getBonusPoints();

    double expectedBonus = 0;


    EXPECT_EQ(bonus, expectedBonus);
}

/**
 * UnitTest
 * Test rental print (output stream)
 */
TEST(rental_print_tests, rentalPrint) {

    Movie newMovie("Movie name", NewReleasePriceCode::getInstance());
    Rental rental(newMovie, 1);

    std::ostringstream ss;
    ss << rental;
    std::string result = ss.str();

    std::string expectedResult = "Movie name\t";
    expectedResult += std::to_string((int) rental.computeAmount());


    EXPECT_EQ(result, expectedResult);
}





