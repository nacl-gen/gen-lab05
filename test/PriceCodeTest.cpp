#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../src/pricecode/RegularPriceCode.h"
#include "../src/pricecode/NewReleasePriceCode.h"
#include "../src/pricecode/ChildrenPriceCode.h"

// Unit test suite for the price code classes (all of the subclasses)

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
TEST(pricecode_amount_tests, ChildrenPriceCodeWithMoreThanThreeDays) {

    double amount = ChildrenPriceCode::getInstance().computePrice(4);

    double expectedAmount = 3;

    EXPECT_EQ(amount, expectedAmount);
}

/**
 * UnitTest
 * Test children price code with less than 4 days gives right amount
 */
TEST(pricecode_amount_tests, ChildrenPriceCodeWithLessThanFourDays) {

    double amount = ChildrenPriceCode::getInstance().computePrice(2);

    double expectedAmount = 1.5;

    EXPECT_EQ(amount, expectedAmount);
}

