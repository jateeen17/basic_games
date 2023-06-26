#include <iostream>
#include <string>

using namespace std;

int main() {
    int choice;
    while (true) {
        // Display menu
        cout << "Select an option:" << endl;
        cout << "1. File 1" << endl;
        cout << "2. File 2" << endl;
        cout << "3. File 3" << endl;
        cout << "4. Exit" << endl;

        // Get user's choice
        cout << "Enter your choice: ";
        cin >> choice;

        // Execute user's choice
        switch (choice) {
            case 1:
                // Call File 1 function
                cout << "Executing File 1..." << endl;
                 #include "car_game.cpp"
                break;
            case 2:
                // Call File 2 function
                cout << "Executing File 2..." << endl;
                //#include "File2.cpp"
                break;
            case 3:
                // Call File 3 function
                cout << "Executing File 3..." << endl;
                // #include "File3.cpp"
                break;
            case 4:
                // Exit program
                cout << "Exiting program..." << endl;
                return 0;
            default:
                // Invalid choice
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    }
}
