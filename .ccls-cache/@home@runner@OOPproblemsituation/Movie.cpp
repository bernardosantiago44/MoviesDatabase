#include "Movie.h"

void Movie::displayInformation() {
  cout.precision(2);
  cout << "Title: " << this->title << endl;
  cout << "--- Genre: " << this->genre << endl;
  cout << "--- Duration: " << this->duration << " min." << endl;
  cout << "--- Rating: " << this->calculateRating() << "/5\n" << endl;
}


Movie::Movie(string id, string title, string genre, int duration) {
  this->id = id;
  this->title = title;
  this->genre = genre;
  this->duration = duration;
  this->ratings = {};
}

Movie::Movie() { Movie("0", "Unknown", "Unknown", 0); }

Movie::~Movie() {
  // cout << "Deleting " + title << endl;
}
