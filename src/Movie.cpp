#include <utility>

#include "Movie.h"

std::ostream& operator<< (std::ostream& ostream, const Movie& movie) {
    return ostream << movie.getTitle();
}
 