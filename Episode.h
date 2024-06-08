#include "Playable.h"
#ifndef EPISODE_H
#define EPISODE_H

using namespace std;

class Episode: public Playable {
  private:
  float calculateRating() override;
  unsigned short int season;
  unsigned short int seriesID;
  string getSeriesTitle();
  
  public:
  void setSeriesID(unsigned int seriesID);
  void setSeason(unsigned int season);

  void displayInformation() override;
  Episode(string id, unsigned short int seriesID, 
          string title, int duration, unsigned short int season);
  Episode();
  virtual ~Episode();
};

#endif