#include "Playable.h"
#ifndef EPISODE_H
#define EPISODE_H

using namespace std;

class Episode: public Playable {
  private:
  float calculateRating() override;
  unsigned short int season;
  string seriesName;
  
  public:
  void setSeriesName(string name);
  void setSeason(unsigned int season);

  void displayInformation() override;
  Episode(string id, string seriesName, 
          string title, int duration, unsigned short int season);
  Episode();
  virtual ~Episode();
};

#endif