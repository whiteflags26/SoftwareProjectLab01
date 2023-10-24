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
    while (true) {
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "Manage Budget:" << std::endl;
        std::cout << "1. View Budget" << std::endl;
        std::cout << "2. Change Budget" << std::endl;
        std::cout << "3. Make Budget" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Please enter your choice: ";

        int choice;
        std::cin >> choice;

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
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}

void DriverClass::ViewBudget() {
    // Implement budget viewing functionality here
    std::cout << "Inside View Budget function" << std::endl;
    // Add your budget viewing logic here
}

void DriverClass::ChangeBudget() {
    // Implement budget changing functionality here
    std::cout << "Inside Change Budget function" << std::endl;
    // Add your budget changing logic here
}

void DriverClass::MakeBudget() {
    // Implement budget making functionality here
    std::cout << "Inside Make Budget function" << std::endl;
    // Add your budget making logic here
}

void DriverClass::AddTransaction() {
    // Implement add transaction functionality here
    std::cout << "Inside Add Transaction function" << std::endl;
    // Add your transaction logic here
}
