#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
using namespace std;

// Log in function
bool LogIn();

bool ValidatePass(string password);

bool ValidateUsername(string username);

void ResetUsername();

void ResetPassword();

void CreateAccount();



#endif  // FUNCTIONS_H