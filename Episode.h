#include "Playable.h"
#ifndef EPISODE_H
#define EPISODE_H

using namespace std;

class Episode: public Playable {
private:
    unsigned short int season;
    string seriesName;
  
public:
    void setSeriesName(string name);
    void setSeason(unsigned int season);

    void displayInformation() override;
    string getSeriesName() const;
    unsigned short int getSeason() const;

    Episode(string id, string seriesName, 
          string title, int duration, unsigned short int season);
    Episode();
    virtual ~Episode();
};

#endif