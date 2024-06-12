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

  float calculateRating();

public:
  virtual void displayInformation() { cout << "Display information" << endl; }

  void setID(string id);
  void setTitle(string title);
  void setGenre(string genre);
  void setDuration(float duration);
  void addRating(int rating);

  string getID() const;
  string getTitle() const;
  string getGenre() const;
  int getDuration() const;
  vector<int> getRatings() const;
};

#endif