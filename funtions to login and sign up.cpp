#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class User {
private:
    string username;
    string password;

public: 
    // Method to set the username
    void setUsername(const string& uname) {
        username = uname;
    }

    // Method to set the password
    void setPassword(const string& pwd) {
        password = pwd;
    }

    // Method to get the username
    string getUsername() const {
        return username;
    }

    // Method to get the password
    string getPassword() const {
        return password;
    }

    // Method to sign up a new user
    void signUp() {
        cout << "Enter a username: ";
        cin >> username;
        cout << "Enter a password: ";
        cin >> password;

        // Open the file in append mode to add new user data
        ofstream file("users.txt", ios::app);
        if (!file) {
            cout << "Error: Unable to open file for writing." << endl;
            return;
        }

        // Write username and password to the file
        file << username << " " << password << endl;
        file.close();

        cout << "Sign-up successful! You can now log in." << endl;
    }

    // Method to log in an existing user
    bool logIn() {
        string uname, pwd;

        cout << "Enter your username: ";
        cin >> uname;
        cout << "Enter your password: ";
        cin >> pwd;

        // Open the file in read mode to check user data
        ifstream file("users.txt");
        if (!file) {
            cout << "Error: Unable to open file for reading." << endl;
            return false;
        }

        string storedUsername, storedPassword;
        // Read each line from the file
        while (file >> storedUsername >> storedPassword) {
            // Check if the entered credentials match stored credentials
            if (storedUsername == uname && storedPassword == pwd) {
                file.close();
                return true;
            }
        }

        file.close();
        return false;
    }
};

int main() {
    User user;
    int choice;

    cout << "1. Sign Up" << endl;
    cout << "2. Log In" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        user.signUp();
    } else if (choice == 2) {
        if (user.logIn()) {
            cout << "Login successful!" << endl;
        } else {
            cout << "Invalid username or password." << endl;
            user.logIn();
             cout << "Login successful!" << endl;
        }
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
