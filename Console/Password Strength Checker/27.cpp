#include <iostream>
#include <string>
using namespace std;

bool hasUppercase(const string& password) {
    for (char ch : password) {
        if (isupper(ch)) return true;
    }
    return false;
}

bool hasLowercase(const string& password) {
    for (char ch : password) {
        if (islower(ch)) return true;
    }
    return false;
}

bool hasDigit(const string& password) {
    for (char ch : password) {
        if (isdigit(ch)) return true;
    }
    return false;
}

bool hasSpecialChar(const string& password) {
    string specialChars = "!@#$%^&*()-_=+[]{}|;:',.<>?/`~";
    for (char ch : password) {
        if (specialChars.find(ch) != string::npos) return true;
    }
    return false;
}

string checkPasswordStrength(const string& password) {
    if (password.length() < 8) {
        return "Weak (too short)";
    }
    if (!hasUppercase(password)) {
        return "Weak (missing uppercase letter)";
    }
    if (!hasLowercase(password)) {
        return "Weak (missing lowercase letter)";
    }
    if (!hasDigit(password)) {
        return "Weak (missing digit)";
    }
    if (!hasSpecialChar(password)) {
        return "Weak (missing special character)";
    }
    return "Strong password!";
}

int main() {
    string password;
    cout << "Enter your password: ";
    cin >> password;

    string strength = checkPasswordStrength(password);
    cout << "Password strength: " << strength << endl;

    return 0;
}
