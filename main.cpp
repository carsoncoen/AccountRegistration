#include "registration.h"
#include <iostream>
#include <fstream> 

using namespace std;

// Main function
int main() {

    int choice;
    int choiceReset;
    bool status;

    cout << "1.) Create Account" << endl;
    cout << "2.) Login" << endl;
    cout << "3.) Reset Username or Password" << endl;
    cin >> choice;

    // user inputs whether to log in or to create an account if they do not have one
    while (choice != 1 && choice != 2 && choice !=3) {
        cout << "Invalid input, please choose from the list above." << endl;
        cin >> choice;
    }
    if (choice == 1) {
        CreateAccount();
    }
    else if (choice == 2) {
        status = LogIn();

        if (status) {
            cout << "Successfully logged in." << endl;
            system("PAUSE");
            return 1;
        }
        else if (!status) {
            while (!status) {
                cout << endl << "Invalid username or password, please try again." << endl;
                cout << "Need to reset your password?" << endl << endl;
                status = LogIn();
            }
            cout << "Successfully logged in." << endl;
            system("PAUSE");
            return 1;
        }
    }
    else if (choice == 3) {
        cout << endl << "Reset Username or Password?" << endl;
        cout << "1.) Username" << endl;
        cout << "2.) Password" << endl << endl;
        cin >> choiceReset;
        while (choiceReset != 1 && choiceReset != 2) {
            cout << "Invalid option, please choose either 1 to reset your Username, or 2 to reset your Password." << endl;
            cout << "1.) Username" << endl;
            cout << "2.) Password" << endl << endl;
            cin >> choiceReset;
        }
        if (choiceReset == 1) {
            ResetUsername();
        }
        else if (choiceReset == 2) {
            ResetPassword();
        }
    }
}

