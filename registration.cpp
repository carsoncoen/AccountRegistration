#include "registration.h"
#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Log in function, validates your log in
bool LogIn() {

    string username;
    string password;
    string validUsername;
    string validPassword;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // gets information from saved data
    ifstream read(username + "_login" + ".txt");
    getline(read, validUsername);
    getline(read, validPassword);

    // validates your log in
    if (validUsername == username && validPassword == password) {
        return true;
    }
    else {
        return false;
    }
}

// Validates the username and password when creating your account
bool ValidatePass(string password) {

    vector <char> specialChars = {'!', '*', '$', '?', '_', '&', '~', '@', '^', '#', '%'};
    vector <char> numbers = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

    bool hasSpecial = false;
    bool hasNumber = false;

    // checks string size and white spaces
    if (password.size() >= 5 && password.size() <= 20) {
        if (password.find(' ') != string::npos) {
            cout << endl << "Password cannot cannot include spaces!" << endl;
            return false;
        }
        else {
            for (unsigned int i = 0; i < password.size(); i++) {
                if (find(specialChars.begin(), specialChars.end(), password[i]) != specialChars.end()) {
                    hasSpecial = true;
                }
                if (find(numbers.begin(), numbers.end(), password[i]) != numbers.end()) {
                    hasNumber = true;
                }
            }
            if (hasNumber && hasSpecial) {
                return true;
            }
            else {
            cout << endl << "Password must contain a special character and number!" << endl;
            return false;
            }
        }
    }
    else {
        cout << endl << "Password must be between 5 and 20 characters!" << endl;
        return false;
    }
}

bool ValidateUsername(string username) {

    vector <char> specialChars = {'!', '*', '$', '?', '_', '&', '~', '@', '^', '#'};

    // checks string size and white spaces
    if (username.size() >= 5 && username.size() <= 20) {
        if (username.find(' ') != string::npos) {
            cout << endl << "Username cannot include spaces!" << endl;
            return false;
        }
        else {
            return true;
        }
    }
    else {
        cout << endl << "Username must be between 5 and 20 characters!" << endl;
        return false;
    }
}

// Function to reset username
void ResetUsername() {
    string username;
    string existingName;
    string existingPass;
    string newUsername;

    cout << "Enter your OLD username: ";
    getline(cin.ignore(), username);

    ifstream read(username + "_login" + ".txt");
    getline(read, existingName);
    getline(read, existingPass);

    if (existingName == username) {
    }
    else {
        while (existingName != username) {
            cout << "That username does not exist, please input your correct username." << endl << endl;
            cout << "Enter your OLD username: ";
            getline(cin, username);
            ifstream read(username + "_login" + ".txt");
            getline(read, existingName);
            getline(read, existingPass);
        }
    }

    cout << endl << "Enter your new username: ";
    getline(cin, newUsername);

    // checks if new username is valid

    if (ValidateUsername(newUsername)) {
            cout << endl << "Username updated successfully!" << endl;
                ofstream file;
                file.open(username + "_login" + ".txt");
                file << newUsername << endl << existingPass;
                file.close();
            }
            else {
                while (ValidatePass(newUsername) == false) {
                    cout << "Please try again: ";
                    getline(cin.ignore(), newUsername);
                }
        }   
}

// Function to reset password
void ResetPassword() {
    string username;
    string newPass;
    string existingPass;
    string existingUsername;

    cout << "Please enter your Username: ";
    cin >> username;

    ifstream read(username + "_login" + ".txt");
    getline(read, existingUsername);
    getline(read, existingPass);

    if (username != existingUsername) {
        while (existingUsername != username) {
            cout << "That username does not exist, please input your correct username." << endl << endl;
            cout << "Enter your correct username: ";
            cin >> username;
            ifstream read(username + "_login" + ".txt");
            getline(read, existingUsername);
            getline(read, existingPass);
    }
    }

    // validates the users inputted username 
    cout << "What would you like your new password to be? " << endl;
    getline(cin.ignore(), newPass);
    if (ValidatePass(newPass)) {
        cout << endl << "Password updated successfully!" << endl;
        ofstream file;
        file.open(username + "_login" + ".txt");
        file << username << endl << newPass;
        file.close();
    }
    else {
        while (ValidatePass(newPass) == false) {
            cout << "Please try again: ";
            getline(cin, newPass);
        }
        cout << endl << "Password updated successfully!" << endl;
        ofstream file;
        file.open(username + "_login" + ".txt");
        file << username << endl << newPass;
        file.close();
    }
}

// Main account creation function
void CreateAccount() {
    string username;
    string password;
    bool validateUsername = false;
    bool validatePassword = false;
    bool validUser, validPass = false;

    cout << endl << "Username and password must be between 5 and 20 characters, and includes no spaces. Password requires a special character and number." << endl;
    cout << endl << "Enter your desired username!" << endl;
    cout << "Username: "; 
    getline(cin.ignore(), username);

    // asks for user input until the username is valid
    while (validateUsername == false) {
        validUser = ValidateUsername(username);
        if (validUser) {
            validateUsername = true;
        }
        else {
            cout << "Please try again: ";
            getline(cin, username);
        }
    }

    cout << endl;
    cout << "Enter your desired password!" << endl;
    cout << "Password: ";
    getline(cin, password);

    // asks for input until password is valid
    while (validatePassword == false) {
        validPass = ValidatePass(password);
        if (validPass) {
            validatePassword = true;
        }
        else {
            cout << "Please try again: ";
            getline(cin, password);
        }
    }
    
    cout << endl << "Successfully created your account!" << endl;

    // writes users data to new file

    ofstream file;
    file.open(username + "_login" + ".txt");

    file << username << endl << password;
    file.close();

}
