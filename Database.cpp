#include "Database.h"
#include <fstream>
#include <sstream>

Database::Database(string directory) {
    this->directory = directory;
    this->readMovies();
    this->readSeries();
    this->readEpisodes();
}

bool Database::movieExists(string title) {
    return movies.find(title) != movies.end();
}

bool Database::seriesExists(string title) {
    return series.find(title) != series.end();
}

void Database::readMovies() {
    movies.clear();
    ifstream file(this->directory + "movies.txt");
    string line;  // Will change over the columns
    string title; // for constructing the map
    const char colDelimeter = ';';
    const char ratingDelimeter = ',';

    while (getline(file, line)) {
        stringstream ss(line);
        string lineItem; // store the current line
        Movie movie;     // construct the read movie

        getline(ss, lineItem, colDelimeter); // reading the id
        movie.setID(lineItem);

        getline(ss, title, colDelimeter); // reading the title
        movie.setTitle(title);

        getline(ss, lineItem, colDelimeter); // reading the genre
        movie.setGenre(lineItem);

        getline(ss, lineItem, colDelimeter); // reading the duration
        movie.setDuration(stof(lineItem));

        getline(ss, lineItem, colDelimeter); // reading the line of the ratings
        stringstream ratingStream(lineItem); // create
        string rating;
        while (getline(ratingStream, rating, ratingDelimeter)) {
            movie.addRating(stoi(rating));
        }
        movies.emplace(title, movie);
    }
    file.close();
}

void Database::readSeries() {
    series.clear();
    ifstream file(this->directory + "series.txt");
    string line;  // Will change over the columns
    string title; // For the series map
    const char colDelimeter = ';';
    const char ratingDelimeter = ',';

    while (getline(file, line)) {
        stringstream ss(line);
        string lineItem; // store the current line
        Series serie;    // construct the read series

        getline(ss, lineItem, colDelimeter); // reading the id
        serie.setID(lineItem);

        getline(ss, title, colDelimeter); // reading the title
        serie.setTitle(title);

        getline(ss, lineItem, colDelimeter); // reading the genre
        serie.setGenre(lineItem);

        getline(ss, lineItem, colDelimeter); // reading the number of seasons
        serie.setNumberOfSeasons(stoi(lineItem));

        getline(ss, lineItem, colDelimeter); // reading the line of the ratings
        stringstream ratingStream(lineItem); // create
        string rating;
        while (getline(ratingStream, rating, ratingDelimeter)) {
            serie.addRating(stoi(rating));
        }
        series.emplace(title, serie);
    }
    file.close();
}

void Database::readEpisodes() {
    ifstream file(this->directory + "episodes.txt");
    string line; // Will change over the columns
    const char colDelimeter = ';';
    const char ratingDelimeter = ',';

    while (getline(file, line)) {
        stringstream ss(line);
        string lineItem;   // store the current line
        string seriesName; // for using in the dictionary
        Episode episode;   // construct the read episode

        getline(ss, lineItem, colDelimeter); // reading the id
        episode.setID(lineItem);

        getline(ss, seriesName, colDelimeter); // reading the series name
        episode.setSeriesName(seriesName);

        getline(ss, lineItem, colDelimeter); // reading the title
        episode.setTitle(lineItem);

        getline(ss, lineItem, colDelimeter); // reading the season
        episode.setSeason(stoi(lineItem));

        getline(ss, lineItem, colDelimeter); // reading the duration
        episode.setDuration(stoi(lineItem));

        getline(ss, lineItem, colDelimeter); // reading the line of the ratings
        stringstream ratingStream(lineItem); // create
        string rating;
        while (getline(ratingStream, rating, ratingDelimeter)) {
            episode.addRating(stoi(rating));
        }
        if (!seriesExists(seriesName)) {
            throw runtime_error("The series " + seriesName + " does not exist.");
        }
        // serie must exist at this point
        EpisodesDict &seriesEpisodes = series.at(seriesName).getEpisodes();
        cout << endl;

        seriesEpisodes.emplace(episode.getTitle(), episode);
    }
    file.close();
}

void Database::displayMovies() {
    cout << "------ Movies ------" << endl;
    for (auto &movie : movies) {
        movie.second.displayInformation();
    }
}

void Database::displaySeries() {
    cout << "------ Series ------" << endl;
    for (auto &serie : series) {
        serie.second.displayInformation();
    }
}

void Database::searchMovie() {
    // Read the title from the user
    string title = System::askForInput("Enter the title of the movie: ");

    if (!movieExists(title)) {
        cout << "The movie " << title << " does not exist." << endl;
        return;
    }
    movies.at(title).displayInformation();
}

void Database::searchSeries() {
    // Read the title from the user
    string title = System::askForInput("Enter the title of the series: ");

    if (!seriesExists(title)) {
        cout << "The series " << title << " does not exist." << endl;
        return;
    }
    series.at(title).displayInformation();
}

void Database::rateMovie() {
         // Read the title from the user
         string title = System::askForInput("Enter the title of the movie: ");

         // Check if it exists.
        if (!movieExists(title)) { 
                // If the movie does not exist, alert the user and abort execution
                cout << "The movie " << title << " does not exist." << endl << endl;
                return;
        }

        // Read the rating from the user
        int rating = System::askForInput(1, 5, "Enter the rating (1-5): ");
        // Modify the value of the movie in the dictionary
        this->movies.at(title).addRating(rating);

        // Register new data to the file
}

void Database::rateSeries(){
    string title = System::askForInput("Enter the title of the series: ");

    if(!seriesExists(title)){
        cout << "The series " << title << " does not exist." << endl << endl;
        return;
    }

    int rating = System::askForInput(1, 5, "Enter the rating (1-5): ");

    this->series.at(title).addRating(rating);
}

void Database::rateEpisode(){
    string title_series = System::askForInput("Enter the title of the series the episode is from: ");
    if(!seriesExists(title_series)){
        cout << "The series " << title_series << " does not exist." << endl << endl;
        return;
    }
    string title_episode = System::askForInput("Enter the title of the episode: ");
    if (!series.at(title_series).episodeExists(title_episode)){
        cout << "The episode " << title_episode << " does not exist in the series " <<title_series<<endl << endl;
        return;
    }
    int rating = System::askForInput(1, 5, "Enter the rating (1-5): ");
    this->series.at(title_series).rateEpisode(title_episode,rating);
}

bool Database::writeToDatabase(const Movie& movie) {
    ofstream file(this->directory + "movies.txt", ios::app);

    if (!file.is_open()) {
        cout << "Could not write " + movie.getTitle() + " to database\n";
        return false;
    }

    file << movie.getID()    << ";";
    file << movie.getTitle() << ";";
    file << movie.getGenre() << ";";
    file << movie.getDuration() << ";";

    for (int rating : movie.getRatings()) {
        file << rating << ",";
    }
    file << endl;
    file.close();
    return true;
}

bool Database::writeToDatabase(const Series& series) {
    ofstream file(this->directory + "series.txt", ios::app);

    if (!file.is_open()) {
        cout << "Could not write " + series.getTitle() + " to database\n";
        return false;
    }

    file << series.getID()    << ";";
    file << series.getTitle() << ";";
    file << series.getGenre() << ";";
    for (int rating : series.getRatings()) {
        file << rating << ",";
    }
    file << endl;
    file.close();
    return true;
}

bool Database::writeToDatabase(const Episode& episode) {
    ofstream file(this->directory + "episodes.txt", ios::app);

    if (!file.is_open()) {
        cout << "Could not open database file\n";
        return false;
    }

    file << episode.getID()    << ";";
    file << episode.getSeriesName() << ";";
    file << episode.getTitle() << ";";
    file << episode.getSeason() << ";";
    file << episode.getDuration() << ";";

    for (int rating : episode.getRatings()) {
        file << rating << ",";
    }

    file << endl;
    file.close();
    return true;
}

void Database::resetFile(string filename) const {
    ofstream file(this->directory + filename, ios::trunc);
    file << "";
    file.close();
}

void Database::writeMovies() {
    resetFile("movies.txt");
    for (auto iterator = movies.begin(); iterator != movies.end(); iterator++) {
        if(!writeToDatabase(iterator->second)) {
            throw("Could not write " + iterator->second.getTitle() + " to database\n");
        }
    }
}

void Database::writeSeries() {
    // clear the file to work in
    resetFile("series.txt");
    resetFile("episodes.txt");
    // iterate through the series dictionary
    for (auto iterator = series.begin(); iterator != series.end(); iterator++) {
        if(!writeToDatabase(iterator->second)) {
            throw("Could not write " + iterator->second.getTitle() + " to database\n");
        }
        // For each of the series, iterate through the episodes
        EpisodesDict &seriesEpisodes = iterator->second.getEpisodes();
        for (auto episodesIter = seriesEpisodes.begin(); episodesIter != seriesEpisodes.end(); episodesIter++) {
            // Now attempt to write the episodes to the file, 
            // but without reseting this time
            if(!writeToDatabase(episodesIter->second)) {
                throw("Could not write " + episodesIter->second.getTitle() + " to database\n");
            }
        }
    }
}