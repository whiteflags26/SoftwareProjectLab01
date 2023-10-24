#include "driver.h"

void DriverClass::MainMenu() {
    while (true) {
        Console::WriteLine("-----------------------------------");
        Console::WriteLine("Main Menu:");
        Console::WriteLine("Welcome to SpendIt, A Console-Based Personal Budget Management System");
        Console::WriteLine("1. Manage Budget");
        Console::WriteLine("2. Add Transaction");
        Console::WriteLine("3. Exit");
        Console::WriteLine("Please enter your choice: ");

        int choice;
        choice = Console::ReadLine().to_int();

        switch (choice) {
            case 1:
                ManageBudget();
                break;
            case 2:
                AddTransaction();
                break;
            case 3:
                Console::WriteLine("Goodbye!");
                return;
            default:
                Console::WriteLine("Invalid choice. Please try again.");
        }
    }
}

void DriverClass::ManageBudget() {
    while (true) {
        Console::WriteLine("-----------------------------------");
        Console::WriteLine("Manage Budget:");
        Console::WriteLine("1. View Budget");
        Console::WriteLine("2. Change Budget");
        Console::WriteLine("3. Make Budget");
        Console::WriteLine("4. Exit");
        Console::WriteLine("Please enter your choice: ");

        int choice;
        choice = Console::ReadLine().to_int();

        switch (choice) {
            case 1:
                ViewBudget();
                break;
            case 2:
                ChangeBudget();
                break;
            case 3:
                MakeBudget();
                break;
            case 4:
                return; // Exit the ManageBudget menu
            default:
                Console::WriteLine("Invalid choice. Please try again.");
        }
    }
}

void DriverClass::ViewBudget() {
    // Implement budget viewing functionality here
    Console::WriteLine("Inside View Budget function");
    // Add your budget viewing logic here
}

void DriverClass::ChangeBudget() {
    // Implement budget changing functionality here
    Console::WriteLine("Inside Change Budget function");
    // Add your budget changing logic here
}

void DriverClass::MakeBudget() {
    // Implement budget making functionality here
    Console::WriteLine("Inside Make Budget function");
    // Add your budget making logic here
}

void DriverClass::AddTransaction() {
    // Implement add transaction functionality here
    Console::WriteLine("Inside Add Transaction function");
    // Add your transaction logic here
}
