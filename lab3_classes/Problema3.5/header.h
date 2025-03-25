#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>

using namespace std;

class BankApp
{
private:
    string username = "user123";
    string password = "pass123";
    double balance = 0.0;
    bool isLoggedIn = false;
    static int userCount;

public:
    // constructor de initializare
    BankApp() {}

    // functie de login
    void login(const string &inputUsername, const string &inputPassword)
    {
        if (inputUsername == username && inputPassword == password)
        {
            isLoggedIn = true;
            userCount++;
            cout << "Login successful.\n";
        }
        else
        {
            cout << "Invalid username or password.\n";
        }
    }

    void deposit(double amount)
    {
        if (!isLoggedIn)
        {
            cout << "Please log in first to perform this operation.\n";
            return;
        }
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited: $" << amount << "\n";
        }
        else
        {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount)
    {
        if (!isLoggedIn)
        {
            cout << "Please log in first to perform this operation.\n";
            return;
        }
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawn: $" << amount << "\n";
        }
        else
        {
            cout << "Invalid withdrawal amount or insufficient balance.\n";
        }
    }

    void displayBalance()
    {
        if (!isLoggedIn)
        {
            cout << "Please log in first to perform this operation.\n";
            return;
        }
        cout << "Current balance: $" << balance << "\n";
    }

    static void displayUserCount()
    {
        cout << "Total users who have logged in: " << userCount << "\n";
    }

    void logout()
    {
        if (isLoggedIn)
        {
            isLoggedIn = false;
            cout << "You have logged out.\n";
        }
        else
        {
            cout << "No user is currently logged in.\n";
        }
    }
};

// initializare valoare statica
int BankApp::userCount = 0;

#endif