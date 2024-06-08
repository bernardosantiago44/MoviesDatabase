#include "Episode.h"

Episode::Episode(string id, unsigned short int seriesID,
                 string title, int duration, unsigned short int season) {
  this->id = id;
  this->seriesID = seriesID;
  this->title = title;
  this->duration = duration;
  this->season = season;
  this->genre = "Unknown";
}

Episode::Episode() { Episode("0", 0, "Unknown", 0, 0); }

float Episode::calculateRating() {
  float rating = 0;
  const int size = this->ratings.size();

  for (int i : this->ratings) {
    rating += i;
  }
  return rating / size;
}

void Episode::setSeriesID(unsigned int seriesID) {
  this->seriesID = seriesID;
}

void Episode::setSeason(unsigned int season) {
  this->season = season;
}

string Episode::getSeriesTitle() {
  return "Series title goes here";
  // return this->seriesTitle;
}

void Episode::displayInformation() {
  cout.precision(2);
  cout << "Episode title: " << this->title << endl;
  cout << "--- Series: " << this->getSeriesTitle() << endl;
  cout << "--- Season " << this->season << endl;
  cout << "--- Duration: " << this->duration << " min." << endl;
  cout << "--- Rating: " << this->calculateRating() << "/5\n" << endl;
}

Episode::~Episode() {}