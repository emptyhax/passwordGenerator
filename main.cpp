#include <iostream>
#include <string>
#include <cstdlib>   
#include <ctime>   

using namespace std;

string generatePassword(int length);
void menu();

int main() {
    srand(time(0)); 
    
    while (true) {
        menu();
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1: {
                cout << "Enter password length: ";
                int length;
                cin >> length;
                string password = generatePassword(length);
                cout << "Generated Password: " << password << endl;
                break;
            }
            case 2:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
}

string generatePassword(int length) {
    const char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*()_+-=[]{}|;:,.<>?/";
    const int charsetSize = sizeof(charset) - 1;
    string password;
    
    for (int i = 0; i < length; ++i) {
        password += charset[rand() % charsetSize];
    }
    
    return password;
}

 
void menu() {
    cout << "\nPassword Generator Menu:" << endl;
    cout << "1. Generate Password" << endl;
    cout << "2. Exit" << endl;
    cout << "Enter your choice: ";
}
