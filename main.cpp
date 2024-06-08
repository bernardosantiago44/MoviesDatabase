#include <iostream>
#include <vector>
#include "Movie.h"
#include "Database.h"

using namespace std;

int main() {
  vector<Movie> movies;
  vector<Series> series;
  Database database("./");

  movies = database.readMovies();
  series = database.readSeries();

  // for (Movie movie : movies) {
  //   movie.displayInformation();
  // }

  for (Series serie : series) {
    serie.displayInformation();
  }
}