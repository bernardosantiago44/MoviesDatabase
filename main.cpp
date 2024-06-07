#include <iostream>
#include <vector>
#include "Movie.h"
#include "Database.h"

using namespace std;

int main() {
  vector<Movie> playables;
  Database database("./");

  playables = database.readMovies();
  for (Movie movie : playables) {
    movie.displayInformation();
  }
}