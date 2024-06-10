#include <iostream>
#include <vector>
#include "Movie.h"
#include "Database.h"

using namespace std;

int main() {

  Database database("./");

  //database.displayMovies();
  database.displaySeries();
}