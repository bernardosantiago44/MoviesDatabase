#include "Playable.h"

#ifndef MOVIE_H
#define MOVIE_H

class Movie: public Playable {
  private:

  public:
  void displayInformation() override;
  Movie(string id, string title, string genre, int duration);
  Movie();
  virtual ~Movie();
};

#endif