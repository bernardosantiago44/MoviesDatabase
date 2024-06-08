#include "Episode.h"

Episode::Episode(string id, string title, string genre, int duration,
                 unsigned short int season) {
  this->id = id;
  this->title = title;
  this->genre = genre;
  this->duration = duration;
  this->season = season;
}

Episode::Episode() { Episode("0", "Unknown", "Unknown", 0, -1); }

float Episode::calculateRating() {
  float rating = 0;
  const int size = this->ratings.size();

  for (int i : this->ratings) {
    rating += i;
  }
  return rating / size;
}

void Episode::displayInformation() {
  cout.precision(2);
  cout << "Episode title: " << this->title << endl;
  cout << "--- Season " << this->season << endl;
  cout << "--- Genre: " << this->genre << endl;
  cout << "--- Duration: " << this->duration << " min." << endl;
  cout << "--- Rating: " << this->calculateRating() << "/5\n" << endl;
}

Episode::~Episode() {}