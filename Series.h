#include "Playable.h"

#ifndef SERIES_H
#define SERIES_H

using namespace std;

class Series: public Playable {
  private:
  float calculateRating() override;
  unsigned int numberOfSeasons;

  public:
  void displayInformation() override;
  void setNumberOfSeasons(unsigned int numberOfSeasons);
  Series(string id, string title, string genre, 
         unsigned int numberOfSeasons);
  Series();
  virtual ~Series();
};

#endif