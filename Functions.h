#ifndef Functions_H
#define Functions_H

using namespace std;
void printMenu();
void findPhoneByCountry(mysqlpp::Connection &myDB);
void countOfficesCountry(mysqlpp::Connection &myDB);
void connectDB(mysqlpp::Connection &myDB);

#endif 