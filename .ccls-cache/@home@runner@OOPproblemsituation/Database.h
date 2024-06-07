#include "Movie.h"
#include <iostream>

using namespace std;

#ifndef DATABASE_H
#define DATABASE_H

class Database {
private:
  string directory;

public: 
  Database(string directory);
  vector<Movie> readMovies();
};

#endif