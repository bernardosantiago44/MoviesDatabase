#include "Playable.h"

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