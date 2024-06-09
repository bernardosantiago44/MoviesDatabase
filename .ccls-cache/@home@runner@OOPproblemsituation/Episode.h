#include "Playable.h"
#ifndef EPISODE_H
#define EPISODE_H

using namespace std;

class Episode: public Playable {
  private:
  float calculateRating() override;
  unsigned short int season;
  
  public:
  void displayInformation() override;
  Episode(string id, string title, string genre, int duration, unsigned            short int season);
  Episode();
  virtual ~Episode();
};

#endif