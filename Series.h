#include "Playable.h"
#include "Episode.h"
#include <unordered_map>

#ifndef SERIES_H
#define SERIES_H

using namespace std;
using EpisodesDict = unordered_map<string, Episode>;

class Series: public Playable {
  private:
  unsigned int numberOfSeasons;
  EpisodesDict episodes;
  void displayEpisodesList(int maxCount);

  public:
  void displayInformation() override;
  void setNumberOfSeasons(unsigned int numberOfSeasons);
  EpisodesDict& getEpisodes();
  Series(string id, string title, string genre, 
         unsigned int numberOfSeasons);
  Series();
  virtual ~Series();
};

#endif