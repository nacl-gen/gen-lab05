#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <ostream>

#include "../src/Movie.h"

// Unit test suite for the Movie class

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