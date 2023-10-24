#include "driver.h"

void DriverClass::MainMenu() {
    while (true) {
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "Main Menu:" << std::endl;
        std::cout << "Welcome to SpendIt, A Console-Based Personal Budget Management System" << std::endl;
        std::cout << "1. Manage Budget" << std::endl;
        std::cout << "2. Add Transaction" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Please enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                ManageBudget();
                break;
            case 2:
                AddTransaction();
                break;
            case 3:
                std::cout << "Goodbye!" << std::endl;
                return;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}

void DriverClass::ManageBudget() {
    // Implement budget management functionality here
    std::cout << "Inside Manage Budget function" << std::endl;
    // Add your budget management logic here
}

void DriverClass::AddTransaction() {
    // Implement add transaction functionality here
    std::cout << "Inside Add Transaction function" << std::endl;
    // Add your transaction logic here
}
