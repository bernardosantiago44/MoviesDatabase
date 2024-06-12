#include "System.h"
#include "Database.h"

System::System() {
  // Initialize the system with reading the
  // movies and series from the database file
  database = new Database("./");

  // Initialize the array of function pointers
  // in the same order of appearance as the menu
  functions[0] = &Database::displayMovies; // Pointer to the function displayMovies
  functions[1] = &Database::displaySeries; // Pointer to the function displaySeries
  functions[2] = &Database::searchMovie; // Pointer to the function searchMovie
  functions[3] = &Database::searchSeries;         // Pointer to the function searchSeries
  functions[4] = &Database::rateMovie; // Pointer to the function rateMovie
  functions[5] = &Database::rateSeries; // Pointer to the function rateSeries
  functions[6] = &Database::rateEpisode; // Pointer to the function rateEpisode

  database->readMovies();
  database->readSeries();
  database->readEpisodes();
}

void System::displayMenu() { cout << MAIN_MENU << endl; }

int System::askForInput(int from, int to, string message) {
  string input = "-1";

  while (true) {
    // Enter your choice (from - to)
    cout << message;
    cin >> input;

    // Check if the input is a number
    try {
      stoi(input);
    } catch (invalid_argument e) {
      cout << "Hey, that's not a number. Please try again.\n";
      continue;
    }

    // Check if the number is within the range
    if (stoi(input) < from || stoi(input) > to) {
      cout << "Invalid input. Please try again.\n";
      continue;
    }
    break;
  }

  cout << "\n\n";

  return stoi(input);
}

string System::askForInput(string message) {
  string input;
  cout << message;
  cin.ignore(); // Ignore any previous newline character
  getline(cin, input);
  return input;
}

void System::run() {
  int input = -1;

  while (true) {
    displayMenu();
    // ask for numeric input from 1 to 7
    input = askForInput(1, 8, "Enter your choice (1-8): ");

    if (input == 8) {
      cout << "Thank you for using the program.\n";
      this->database->writeMovies();
      break;
    }

    if (this->database != nullptr) {
      (this->database->*functions[input - 1])();
    }
  }
}
