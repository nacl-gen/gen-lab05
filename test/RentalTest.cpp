#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../src/Rental.h"

/**
 * UnitTest
 * Test rental price computation children with less than 4 rental days
 */
TEST(rental_unit_tests, childrenMovieHasRightPriceWithLessThanFourDays) {

    Movie childrenMovie("children movie", 2);
    Rental rental(childrenMovie, 3);

    double amount = rental.computeAmount();

    double expectedAmount = 1.5;


    EXPECT_EQ(amount, expectedAmount);
}

/**
 * UnitTest
 * Test rental price computation children with more than 3 rental days
 */
TEST(rental_unit_tests, childrenMovieHasRightPriceWithMoreThanThreeDays) {

    Movie childrenMovie("children movie", 2);
    Rental rental(childrenMovie, 4);

    double amount = rental.computeAmount();

    double expectedAmount = 1.5 + (rental.getDaysRented() - 3) * 1.5;


    EXPECT_EQ(amount, expectedAmount);
}

/**
 * UnitTest
 * Test rental price computation new release
 */
TEST(rental_unit_tests, newReleaseMovieHasRightPrice) {

    Movie newReleaseMovie("new movie", 1);
    Rental rental(newReleaseMovie, 2);

    double amount = rental.computeAmount();

    double expectedAmount = rental.getDaysRented() * 3;


    EXPECT_EQ(amount, expectedAmount);
}

/**
 * UnitTest
 * Test rental price computation regular with less than 3 rental days
 */
TEST(rental_unit_tests, regularMovieHasRightPriceWithLessThanThreeDays) {

    Movie regularMovie("regular movie", 0);
    Rental rental(regularMovie, 2);

    double amount = rental.computeAmount();

    double expectedAmount = 2;

    EXPECT_EQ(amount, expectedAmount);
}

/**
 * UnitTest
 * Test rental price computation regular with more than 2 rental days
 */
TEST(rental_unit_tests, regularMovieHasRightPriceWithMoreThanTwoDays) {

    Movie regularMovie("regular movie", 0);
    Rental rental(regularMovie, 3);

    double amount = rental.computeAmount();

    double expectedAmount = 2 + (rental.getDaysRented() - 2) * 1.5;


    EXPECT_EQ(amount, expectedAmount);
}

