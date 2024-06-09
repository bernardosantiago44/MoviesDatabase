#include "Episode.h"
#include "Movie.h"
#include "Series.h"
#include <iostream>
#include <unordered_map>

using namespace std;
using MovieDict = unordered_map<string, Movie>;
using SeriesDict = unordered_map<string, Series>;
using PlayableDict = unordered_map<string, Playable>;

#ifndef DATABASE_H
#define DATABASE_H

class Database {
private:
  string directory;
  MovieDict movies;
  SeriesDict series;

  bool movieExists(string title);
  bool seriesExists(string title);

public:
  Database(string directory);
  void readMovies();
  void readSeries();
  void readEpisodes();

  void displayMovies();
  void displaySeries();
};

#endif