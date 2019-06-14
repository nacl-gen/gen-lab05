#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../src/pricecode/RegularPriceCode.h"
#include "../src/pricecode/NewReleasePriceCode.h"
#include "../src/pricecode/ChildrenPriceCode.h"

// Unit test suite for the price code classes computePrice method (all of the subclasses)

/**
 * UnitTest
 * Test regular price code with more than 2 days gives right amount
 */
TEST(pricecode_amount_tests, regularPriceCodeWithMoreThanTwoRentalDays) {

    double amount = RegularPriceCode::getInstance().computePrice(3);

    double expectedAmount = 2 + 1.5;

    EXPECT_EQ(amount, expectedAmount);
}

/**
 * UnitTest
 * Test regular price code with less than 3 days gives right amount
 */
TEST(pricecode_amount_tests, regularPriceCodeWithLessThanTreeRentalDays) {

    double amount = RegularPriceCode::getInstance().computePrice(1);

    double expectedAmount = 2;

    EXPECT_EQ(amount, expectedAmount);
}

/**
 * UnitTest
 * Test new release price code gives right amount
 */
TEST(pricecode_amount_tests, newReleasePriceCode) {

    double amount = NewReleasePriceCode::getInstance().computePrice(3);

    double expectedAmount = 9;

    EXPECT_EQ(amount, expectedAmount);
}

/**
 * UnitTest
 * Test children price code with more than 3 days gives right amount
 */
TEST(pricecode_amount_tests, childrenPriceCodeWithMoreThanThreeDays) {

    double amount = ChildrenPriceCode::getInstance().computePrice(4);

    double expectedAmount = 3;

    EXPECT_EQ(amount, expectedAmount);
}

/**
 * UnitTest
 * Test children price code with less than 4 days gives right amount
 */
TEST(pricecode_amount_tests, childrenPriceCodeWithLessThanFourDays) {

    double amount = ChildrenPriceCode::getInstance().computePrice(2);

    double expectedAmount = 1.5;

    EXPECT_EQ(amount, expectedAmount);
}

// Unit test for the getBonusPoints method (only NewReleasePriceCode actually)

/**
 * UnitTest
 * Test if the the NewReleasePriceCode return a bonus of 1
 */
TEST(pricecode_bonus_tests, newReleasePriceCodeReturnsRightBonus) {

    int bonus = NewReleasePriceCode::getInstance().getBonusPoints();

    int expectedBonus = 1;

    EXPECT_EQ(bonus, expectedBonus);
}

