#include "Episode.h"

Episode::Episode(string id, string seriesName,
                 string title, int duration, unsigned short int season) {
  this->id = id;
  this->seriesName = seriesName;
  this->title = title;
  this->duration = duration;
  this->season = season;
  this->genre = "Unknown";
}

Episode::Episode() { Episode("0", "0", "Unknown", 0, 0); }

float Episode::calculateRating() {
  float rating = 0;
  const int size = this->ratings.size();

  for (int i : this->ratings) {
    rating += i;
  }
  return rating / size;
}

void Episode::setSeriesName(string name) {
  this->seriesName = name;
}

void Episode::setSeason(unsigned int season) {
  this->season = season;
}

void Episode::displayInformation() {
  cout.precision(2);
  cout << "\tEpisode title: " << this->title << endl;
  cout << "\t\t--- Season " << this->season << endl;
  cout << "\t\t--- Duration: " << this->duration << " min." << endl;
  cout << "\t\t--- Rating: " << this->calculateRating() << "/5\n" << endl;
}

Episode::~Episode() {}