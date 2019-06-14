#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <ostream>

#include "../src/Movie.h"

// Unit test suite for the move class

/**
 * UnitTest
 * Test movie print (output stream)
 */
TEST(movie_print_tests, moviePrint) {

    Movie movie("Movie name", 0);

    // OSS 117 ;)
    std::ostringstream oss;
    oss << movie;
    std::string name = oss.str();

    std::string expectedName = "Movie name";


    EXPECT_EQ(name, expectedName);
}