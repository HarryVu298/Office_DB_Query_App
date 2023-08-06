# OfficeDBQueryApp

OfficeDBQueryApp is a command-line application developed by Harry Vu, providing users with the ability to interact with and query office data from a database. The application offers a simple interface with options to retrieve phone numbers by country and count the number of offices based on state or city.

## Features

1. **Find Phone Numbers By Country**: Users can enter a few characters of a country name to retrieve phone numbers associated with that country.
2. **Count Offices By Location**: Users have the option to count the number of offices based on either the city or state within a particular country.
3. **User-Friendly Interface**: Simple textual menu-driven interaction allowing users to easily choose their desired operation.

## Dependencies

- [MySQL++](https://tangentsoft.com/mysqlpp/home): C++ wrapper for MySQL's C API.

## How to Run

1. Ensure you have the MySQL++ library installed.
2. Compile the project using a suitable C++ compiler.
3. Execute the generated binary.
4. Follow on-screen prompts to interact with the application.

## Code Structure

- `Functions.cpp`: Contains utility functions for connecting to the database, displaying the user menu, and performing the query operations.
- `QueryApp.cpp`: Contains the main application loop, handling user input and triggering appropriate actions.

## License

This project is open source and available under the [MIT License](LICENSE).

