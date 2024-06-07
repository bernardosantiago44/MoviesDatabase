#include "Database.h"
#include <fstream>
#include <sstream>

Database::Database(string directory) { this->directory = directory; }

vector<Movie> Database::readMovies() {
  vector<Movie> movies;
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
  return movies;
}