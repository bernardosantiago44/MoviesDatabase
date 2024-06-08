#include <iostream>
#include <vector>
#include "Movie.h"
#include "Database.h"

using namespace std;

int main() {
  vector<Movie> movies;
  vector<Series> series;
  vector<Episode> episodes;

  Database database("./");

  database.displayMovies();
  database.displaySeries();
}