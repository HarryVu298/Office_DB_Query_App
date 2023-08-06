#include <iostream>
#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include <string>
#include "Functions.h"

using namespace std;

/**
 * This is the method used to connect the Database
*/
void connectDB(mysqlpp::Connection &myDB)
{
    if (myDB.connect("cse278", "localhost", "cse278",
                     "MonSepM1am1"))
    {
    }
    else
    {
        std::cerr << "Connection failed: " << myDB.error() << std::endl;
        return;
    }
}

/**
 * The medthod to print the menu to the user
*/
void printMenu()
{
    cout << "A Query Application for Offices Data\n\n";
    cout << "1. Find the city, phone number and state by country\n"
         << "2. Count the number of offices for each state (or city) from country\n"
         << "3. Exit\n\n"
         << "Enter a menu number >>> ";
}

/**
 * This is the moethod to find phone number
 * by country from the database
 * @param myDB the database connection
*/
void findPhoneByCountry(mysqlpp::Connection &myDB)
{
    // Take the input from the user
    string country, order;
    cout << "Enter a few characters to find the list of phone number by country (Ex: \"U\"): ";
    cin >> country;
    cout << "The columns are city, phone, state and country. Order the result by (Ex: \"city\"): ";
    cin >> order;
    cout << "Here is the list: \n";
    // Create a query object
    mysqlpp::Query query = myDB.query();
    // Add a query statement to the query object
    query << "SELECT city, phone, state, country  "
          << "FROM Offices "
          << "WHERE country LIKE \"" << country << "%\" "
          << "ORDER BY " << order << ";";
    query.parse();
    mysqlpp::StoreQueryResult result = query.store();
    // Always check for errors for sql statement
    if (result)
    {
        std::cout << std::left << std::setw(30) << "city"
                  << std::setw(50) << "phone"
                  << std::setw(30) << "state"
                  << std::setw(30) << "country"
                  << std::endl;
        std::string line(125, '-');
        std::cout << line << std::endl;
        for (const auto &row : result)
        {

            std::cout << std::left << std::setw(30) << row[0].c_str()
                      << std::setw(50) << row[1]
                      << std::setw(30) << row[2].c_str()
                      << std::setw(30) << row[3].c_str()
                      << std::endl;
        } // done printing results
        cout << "\n";
    }
    else
    {
        std::cerr << "Query failed: " << query.error() << std::endl;
    }
}

/**
 * This is the method to count the number of 
 * Offices based on state, country or city, country
 * The user can choose between state or city
 * @param myDB the database to read from
*/
void countOfficesCountry(mysqlpp::Connection &myDB)
{
    // Getting the inputs from the user
    string choice, country, order;
    cout << "Do you want to count the number of phone based on city or state, please enter \"city\" or \"state\": ";
    cin >> choice;
    cout << "Enter a few characters of the country you want to count the number of offices (Ex: \"U\"): ";
    cin >> country;
    cout << "The columns are " << choice << ", country, and count(*). Order the result by (Ex: \"country\"): ";
    cin >> order;

    cout << "Here is the list: \n";

    // Create a query object
    mysqlpp::Query query = myDB.query();
    // Add a query statement to the query object
    query << "SELECT " << choice << " , country, count(*) "
          << "FROM Offices "
          << "WHERE country LIKE \"" << country << "%\" "
          << "GROUP BY " << choice << " , country "
          << "ORDER BY " << order << ";";
    query.parse();
    mysqlpp::StoreQueryResult result = query.store();
    // Always check for errors for sql statement
    if (result)
    {
        std::cout << std::left << std::setw(30) << choice
                  << std::setw(30) << "country"
                  << std::setw(10) << "count(*)"
                  << std::endl;
        std::string line(100, '-');
        std::cout << line << std::endl;
        for (const auto &row : result)
        {

            std::cout << std::left << std::setw(30) << row[0].c_str()
                      << std::setw(30) << row[1]
                      << std::setw(10) << row[2].c_str()
                      << std::endl;
        } // done printing results
        cout << "\n";
    }
    else
    {
        std::cerr << "Query failed: " << query.error() << std::endl;
    }
}