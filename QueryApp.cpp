#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include <string>
#include <iostream>
#include "Functions.h"
using namespace std;

/**
 * This program is used to get some information from the Database to the user
 * author: Harry Vu
*/
int main(int argc, char* argv[]) {
    // Create a flag for the loop
    bool loop = true;
    // Create a MySQL connection object
    mysqlpp::Connection myDB;
    // Connect to the database
    connectDB(myDB);
    
    // Run the loop until the user chooses to exit
    while (loop) {
        // Print the menu for the user
        printMenu();
        // Get the user's choice
        int choice;
        cin >> choice;
        cout << "\n";
        
        // Perform the chosen action
        switch (choice) {
            // List phone numbers by country
            case 1:
                std::cout << "You chose option 1.\n" << std::endl;
                findPhoneByCountry(myDB);
                break;
            // Count number of offices for each state/city by country
            case 2:
                std::cout << "You chose option 2.\n" << std::endl;
                countOfficesCountry(myDB);
                break;
            // exit
            case 3:
                loop = false;
                break;
            default:
                std::cout << "Invalid choice. There are only 3 options(1, 2, 3)\n" << std::endl;
        }
    }

    return 0;
}
