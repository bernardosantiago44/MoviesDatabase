#include "Series.h"

float Series::calculateRating() {
    float rating = 0;
    const int size = this->ratings.size();

    for (int i : this->ratings) {
        rating += i;
    }
    return rating / size;
}

void Series::displayInformation() {
    const string title = "Title: " + this->title + " (" + this->id + ")";
    cout.precision(2);
    cout << title << endl;
    cout << "--- Genre: " << this->genre << endl;
    cout << "--- Number of seasons: " << this->numberOfSeasons << endl;
    cout << "--- Rating: " << this->calculateRating() << "/5\n" << endl;
}

void Series::setNumberOfSeasons(unsigned int numberOfSeasons) {
    this->numberOfSeasons = numberOfSeasons;
}

Series::Series(string id, string title, string genre, unsigned int numberOfSeasons) {
    this->id = id;
    this->title = title;
    this->genre = genre;
    this->numberOfSeasons = numberOfSeasons;
    this->ratings = {};
}

Series::Series() { Series("0", "Unknown", "Unknown", 0); }

Series::~Series() {
    // cout << "Deleting " + title << endl;
}