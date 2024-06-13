#include "Episode.h"
#include "Movie.h"
#include "Series.h"
#include "System.h"
#include <iostream>
#include <map>

using namespace std;
using MovieDict = map<string, Movie>;
using SeriesDict = map<string, Series>;
using PlayableDict = map<string, Playable>;

#ifndef DATABASE_H
#define DATABASE_H

class Database {
private:
  string directory;
  MovieDict movies;
  SeriesDict series;

  bool movieExists(string title);
  bool seriesExists(string title);

  bool writeToDatabase(const Movie &movie);
  bool writeToDatabase(const Series &series);
  bool writeToDatabase(const Episode &episode);

  void resetFile(string filename) const;

public:
  Database(string directory);
  void readMovies();
  void readSeries();
  void readEpisodes();

  void displayMovies();
  void displaySeries();
  void searchMovie();
  void searchSeries();
  void rateMovie();
  void rateSeries();
  void rateEpisode();

  void writeMovies();
  void writeSeries();
};

#endif