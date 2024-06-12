#include "Playable.h"

float Playable::calculateRating(){
  float rating = 0;
    const int size = this->ratings.size();

    for (int i : this->ratings) {
      rating += i;
    }
    return rating / size;
}

void Playable::setID(string id) {
  this->id = id;
}

void Playable::setTitle(string title) {
  this->title = title;
}

void Playable::setGenre(string genre) {
  this->genre = genre;
}

void Playable::setDuration(float duration) {
  this->duration = duration;
}

void Playable::addRating(int rating) {
  this->ratings.push_back(rating);
}

string Playable::getTitle() const {
  return this->title;
}

string Playable::getGenre() const {
  return this->genre;
}

string Playable::getID() const {
  return this->id;
}

int Playable::getDuration() const {
  return this->duration;
}

vector<int> Playable::getRatings() const {
  return this->ratings;
}