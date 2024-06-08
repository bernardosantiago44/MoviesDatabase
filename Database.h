#include <iostream>
#include "Movie.h"
#include "Series.h"
#include "Episode.h"

using namespace std;

#ifndef DATABASE_H
#define DATABASE_H

class Database {
private:
  string directory;
  vector<Movie> movies;
  vector<Series> series;
  vector<Episode> episodes;

public: 
  Database(string directory);
  void readMovies();
  void readSeries();
  void readEpisodes();

  void displayMovies();
  void displaySeries();
};

#endif