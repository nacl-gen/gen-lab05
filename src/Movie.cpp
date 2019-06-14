#include "Movie.h"

const int Movie::CHILDRENS;
const int Movie::REGULAR;
const int Movie::NEW_RELEASE;

std::ostream& operator<< (std::ostream& ostream, const Movie& movie) {
    return ostream << movie.getTitle();
}
 