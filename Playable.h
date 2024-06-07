#include <iostream>
#include <vector>

using namespace std;

#ifndef PLAYABLE_H
#define PLAYABLE_H

class Playable {
protected:
  string id, title, genre;
  int duration;
  vector<int> ratings;

  virtual float calculateRating() = 0;

public:
  virtual void displayInformation() { cout << "Display information" << endl; }

  void setID(string id);
  void setTitle(string title);
  void setGenre(string genre);
  void setDuration(float duration);
  void addRating(int rating);
};

#endif