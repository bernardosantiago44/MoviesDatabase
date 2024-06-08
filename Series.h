#include "Playable.h"

#ifndef SERIES_H
#define SERIES_H

using namespace std;

class Series: public Playable {
  private:
  float calculateRating() override;

  public:
  void displayInformation() override;
  Series(string id, string title, string genre);
  Series();
  virtual ~Series();
};

#endif