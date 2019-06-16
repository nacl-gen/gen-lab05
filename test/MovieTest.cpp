#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <ostream>

#include "../src/Movie.h"

// mocking (not really useful there but it's the only pure virtual class that we have
// and we didn't manage to find how to mock non-pure virtual classes...

using ::testing::Return;

class PriceCodeMock : public PriceCode {
public:

    PriceCodeMock() : PriceCode(1) {}
    MOCK_CONST_METHOD1(computePrice, double(int dayRendted));
    MOCK_CONST_METHOD0(getBonusPoints, int());
};

// Unit test suite for the Movie class

/**
 * UnitTest
 * Test movie getPrice
 */
 TEST(movie_tests, getPriceReturnsRightPrice) {
     PriceCodeMock priceCodeMock;

     EXPECT_CALL(priceCodeMock, computePrice(2)).WillOnce(Return(5));

     Movie movie("Get me out", priceCodeMock);

     double price = movie.getPrice(2);
     double expectedPrice = 5;

     EXPECT_EQ(price, expectedPrice);
 }

/**
* UnitTest
* Test movie getBonus
*/
TEST(movie_tests, getBonusReturnsRightBonus) {
    PriceCodeMock priceCodeMock;

    EXPECT_CALL(priceCodeMock, getBonusPoints()).WillOnce(Return(1));

    Movie movie("please", priceCodeMock);

    double bonus = movie.getBonus();
    double expectedBonus = 1;

    EXPECT_EQ(bonus, expectedBonus);
}

/**
 * UnitTest
 * Test movie print (output stream)
 */
TEST(movie_tests, moviePrint) {

    Movie movie("Movie name");

    // OSS 117 ;)
    std::ostringstream oss;
    oss << movie;
    std::string name = oss.str();

    std::string expectedName = "Movie name";


    EXPECT_EQ(name, expectedName);
}

TEST(movie_tests, getTitleWorks) {

    Movie movie("Movie name");

    std::string name = movie.getTitle();

    std::string expectedName = "Movie name";

    EXPECT_EQ(name, expectedName);
}