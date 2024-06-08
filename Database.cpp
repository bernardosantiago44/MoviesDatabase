#include "Database.h"
#include <fstream>
#include <sstream>

Database::Database(string directory) { 
  this->directory = directory; 
  this->readMovies();
  this->readSeries();
  this->readEpisodes();
}

void Database::readMovies() {
  movies.clear();
  ifstream file(this->directory + "movies.txt");
  string line; // Will change over the columns
  const char colDelimeter = ';';
  const char ratingDelimeter = ',';

  while (getline(file, line)) {
    stringstream ss(line);
    string lineItem; // store the current line
    Movie movie; // construct the read movie

    getline(ss, lineItem, colDelimeter); // reading the id
    movie.setID(lineItem);

    getline(ss, lineItem, colDelimeter); // reading the title
    movie.setTitle(lineItem);

    getline(ss, lineItem, colDelimeter); // reading the genre
    movie.setGenre(lineItem);

    getline(ss, lineItem, colDelimeter); // reading the duration
    movie.setDuration(stof(lineItem));

    getline(ss, lineItem, colDelimeter); // reading the line of the ratings
    stringstream ratingStream(lineItem); // create 
    string rating;
    while (getline(ratingStream, rating, ratingDelimeter)) {
      movie.addRating(stoi(rating));
    }
    movies.push_back(movie);
  }
  file.close();
}

void Database::readSeries() {
  series.clear();
  ifstream file(this->directory + "series.txt");
  string line; // Will change over the columns
  const char colDelimeter = ';';
  const char ratingDelimeter = ',';

  while (getline(file, line)) {
    stringstream ss(line);
    string lineItem; // store the current line
    Series serie; // construct the read series

    getline(ss, lineItem, colDelimeter); // reading the id
    serie.setID(lineItem);

    getline(ss, lineItem, colDelimeter); // reading the title
    serie.setTitle(lineItem);

    getline(ss, lineItem, colDelimeter); // reading the genre
    serie.setGenre(lineItem);

    getline(ss, lineItem, colDelimeter); // reading the number of seasons
    serie.setNumberOfSeasons(stoi(lineItem));

    getline(ss, lineItem, colDelimeter); // reading the line of the ratings
    stringstream ratingStream(lineItem); // create 
    string rating;
    while (getline(ratingStream, rating, ratingDelimeter)) {
      serie.addRating(stoi(rating));
    }
    series.push_back(serie);
  }
  file.close();
}

void Database::readEpisodes() {
  episodes.clear();
  ifstream file(this->directory + "episodes.txt");
  string line; // Will change over the columns
  const char colDelimeter = ';';
  const char ratingDelimeter = ',';

  while (getline(file, line)) {
    stringstream ss(line);
    string lineItem; // store the current line
    Episode episode; // construct the read episode

    getline(ss, lineItem, colDelimeter); // reading the id
    episode.setID(lineItem);

    getline(ss, lineItem, colDelimeter); // reading the series id
    episode.setSeriesID(stoi(lineItem));

    getline(ss, lineItem, colDelimeter); // reading the title
    episode.setTitle(lineItem);

    getline(ss, lineItem, colDelimeter); // reading the season
    episode.setSeason(stoi(lineItem));

    getline(ss, lineItem, colDelimeter); // reading the duration
    episode.setDuration(stoi(lineItem));

    getline(ss, lineItem, colDelimeter); // reading the line of the ratings
    stringstream ratingStream(lineItem); // create 
    string rating;
    while (getline(ratingStream, rating, ratingDelimeter)) {
      episode.addRating(stoi(rating));
    }
    episodes.push_back(episode);
  }
  file.close();
}

void Database::displayMovies() {
  cout << "------ Movies ------" << endl;
  for (Movie movie : movies) {
    movie.displayInformation();
  }
}

void Database::displaySeries() {
  cout << "------ Series ------" << endl;
  for (Series serie : series) {
    serie.displayInformation();
  }
}

