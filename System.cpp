#include "System.h"

System::System() {
    // Initialize the system with reading the 
    // movies and series from the database file
    database = new Database("./");

    functions[1] = &Database::displayMovies;

    database->readMovies();
    database->readSeries();
}

void System::displayMenu() {
    cout << MAIN_MENU << endl;
}

int System::getInputFromUser() {
    string input = "-1";

    while (true) {
        cout << "Enter your choice (1 - 7): ";
        cin >> input;
        
        if (stoi(input) >= 1 && stoi(input) <= 7) {
            break;
        } else {
            cout << "Invalid option.\n";
        }
    }
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

        functions[0];
    }
}

