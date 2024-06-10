#include "Database.h"
#include <fstream>
#include <sstream>

Database::Database(string directory) { 
  this->directory = directory; 
  this->readMovies();
  this->readSeries();
  this->readEpisodes();
}

bool Database::movieExists(string title) {
  return movies.find(title) != movies.end();
}

bool Database::seriesExists(string title) {
  return series.find(title) != series.end();
}

void Database::readMovies() {
  movies.clear();
  ifstream file(this->directory + "movies.txt");
  string line; // Will change over the columns
  string title; // for constructing the map
  const char colDelimeter = ';';
  const char ratingDelimeter = ',';

  while (getline(file, line)) {
    stringstream ss(line);
    string lineItem; // store the current line
    Movie movie; // construct the read movie

    getline(ss, lineItem, colDelimeter); // reading the id
    movie.setID(lineItem);

    getline(ss, title, colDelimeter); // reading the title
    movie.setTitle(title);

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
    movies.emplace(title, movie);
  }
  file.close();
}

void Database::readSeries() {
  series.clear();
  ifstream file(this->directory + "series.txt");
  string line; // Will change over the columns
  string title; // For the series map
  const char colDelimeter = ';';
  const char ratingDelimeter = ',';

  while (getline(file, line)) {
    stringstream ss(line);
    string lineItem; // store the current line
    Series serie; // construct the read series

    getline(ss, lineItem, colDelimeter); // reading the id
    serie.setID(lineItem);

    getline(ss, title, colDelimeter); // reading the title
    serie.setTitle(title);

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
    series.emplace(title, serie);
  }
  file.close();
}

void Database::readEpisodes() {
  ifstream file(this->directory + "episodes.txt");
  string line; // Will change over the columns
  const char colDelimeter = ';';
  const char ratingDelimeter = ',';

  while (getline(file, line)) {
    stringstream ss(line);
    string lineItem; // store the current line
    string seriesName; // for using in the dictionary
    Episode episode; // construct the read episode

    getline(ss, lineItem, colDelimeter); // reading the id
    episode.setID(lineItem);

    getline(ss, seriesName, colDelimeter); // reading the series name
    episode.setSeriesName(seriesName);

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
    if (!seriesExists(seriesName)) {
      throw runtime_error("The series " + seriesName + " does not exist.");
    }
    // serie must exist at this point
    EpisodesDict& seriesEpisodes = series.at(seriesName).getEpisodes();
    cout << endl;

    seriesEpisodes.emplace(episode.getTitle(), episode);
  }
  file.close();
}

void Database::displayMovies() {
  cout << "------ Movies ------" << endl;
  for (auto& movie : movies) {
    movie.second.displayInformation();
  }
}

void Database::displaySeries() {
  cout << "------ Series ------" << endl;
  for (auto& serie : series) {
    serie.second.displayInformation();
  }
}

void Database::searchMovie() {
  // Read the title from the user
  string title = System::askForInput("Enter the title of the movie: ");

  if (!movieExists(title)) {
    cout << "The movie " << title << " does not exist." << endl;
    return;
  }
  movies.at(title).displayInformation();
}

void Database::searchSeries() {
  // Read the title from the user
  string title = System::askForInput("Enter the title of the series: ");

  if (!seriesExists(title)) {
    cout << "The series " << title << " does not exist." << endl;
    return;
  }
  series.at(title).displayInformation();
}
