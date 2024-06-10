#include <iostream>
#include "Database.h"

using namespace std;

class System {
private:
    Database* database;

    const string MAIN_MENU = "1. Show Movies\n2. Show Series\n3. Search Movies\n4. Search Series\n5. Rate Movie\n6. Rate Series\n7. Exit";
    void (Database::*functions[7])();

    int getInputFromUser();

public:
    void displayMenu(); 
    void run();
    System();
};