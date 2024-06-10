#include "System.h"

System::System() {
    // Initialize the system with reading the 
    // movies and series from the database file
    database = new Database("./");

    functions[0] = &Database::displayMovies;
    functions[1] = &Database::displaySeries;

    database->readMovies();
    database->readSeries();
}

void System::displayMenu() {
    cout << MAIN_MENU << endl;
}

int System::getInputFromUser() {
    string input = "-1";

    cout << "Enter your choice (1 - 7): ";
    cin >> input;
    cout << "Current option " << input << endl;
    
    return stoi(input);
}

void System::run() {
    int input = -1;

    while (true) {
        displayMenu();
        input = getInputFromUser();

        if (input == 7) {
            cout << "Thank you for using the program.\n";
            break;
        }

        if (this->database != nullptr) {
            (this->database->*functions[input - 1])();
        }
    }
}

