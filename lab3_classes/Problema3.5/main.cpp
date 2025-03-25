#include <iostream>
#include <string>
#include "header.h"

using namespace std;

int main()
{
    BankApp bank;
    int choice;
    string inputUsername, inputPassword;
    double amount;

    while (true)
    {
        cout << "\nBank App Menu:\n";
        cout << "1. Login\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Display Balance\n";
        cout << "5. Count Logged-in Users\n";
        cout << "6. Logout\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter username: ";
            cin >> inputUsername;
            cout << "Enter password: ";
            cin >> inputPassword;
            bank.login(inputUsername, inputPassword);
            break;

        case 2:
            cout << "Enter amount to deposit: $";
            cin >> amount;
            bank.deposit(amount);
            break;

        case 3:
            cout << "Enter amount to withdraw: $";
            cin >> amount;
            bank.withdraw(amount);
            break;

        case 4:
            bank.displayBalance();
            break;

        case 5:
            BankApp::displayUserCount(); // se apeleaza metoda statica
            break;

        case 6:
            bank.logout();
            break;

        case 7:
            cout << "Exiting Bank App.\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}