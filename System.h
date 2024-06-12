#pragma once

#include "Database.h"
#include <iostream>

using namespace std;

class System {
private:
  Database *database;

  const string MAIN_MENU =
      "1. Show Movies\n2. Show Series\n3. Search Movies\n4. Search Series\n5. "
      "Rate Movie\n6. Rate Series\n7. Rate Episode\n8. Exit";

  // Array of void-function pointers to the Database class
  void (Database::*functions[7])();

public:
  void displayMenu();
  void run();

  static int askForInput(int from, int to, string message);
  static string askForInput(string message);
  System();
};