#include "driver.h"

void DriverClass::MainMenu() {
    while (true) {
        Console::WriteLine("\n-----------------------------------");
        Console::WriteLine("Main Menu:");
        Console::WriteLine("Welcome to SpendIt, A Console-Based Personal Budget Management System");
        Console::WriteLine("1. Manage Budget");
        Console::WriteLine("2. Add Transaction");
        Console::WriteLine("3. Exit");
        Console::WriteLine("-----------------------------------\n");

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
        Console::WriteLine("\n-----------------------------------");
        Console::WriteLine("Manage Budget:");
        Console::WriteLine("1. View Budget");
        Console::WriteLine("2. Change Budget");
        Console::WriteLine("3. Make Budget");
        Console::WriteLine("4. Exit");
        Console::WriteLine("-----------------------------------\n");

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
                return; 
            default:
                Console::WriteLine("Invalid choice. Please try again.");
        }
    }
}

void DriverClass::ViewBudget() {

    Console::WriteLine("1. Monthly Budget.");
    Console::WriteLine("2. Travel");
    Console::WriteLine("3. Hospital");
    int opt = Console::ReadLine().to_int();

    Console::WriteLine("\n-----------------------------------");
    Console::WriteLine("View Budget:");
    Console::WriteLine("Budget Status:");
    Console::WriteLine("Monthly Budget");
    Console::WriteLine("- Total Allocated Budget:  $1000.00");
    Console::WriteLine("- Total Expenses:  $0.00");
    Console::WriteLine("- Total Income:  $0.00");
    Console::WriteLine("- Remaining Budget:  $0.00");
    Console::WriteLine("- Risk of Overspending: 0%");
    Console::WriteLine("- Amount Overspent:  $0.00");
    Console::WriteLine("- Amount Saved: $0.00");
    Console::WriteLine("-----------------------------------\n");

    Console::WriteLine("Press Enter to return to the main menu.");
    Console::ReadLine();
}

void DriverClass::MakeBudget() {
    Console::WriteLine("\n-----------------------------------");

    Console::WriteLine("Make Budget:");
    Console::WriteLine("Enter Budget Name:");
    String budgetName = Console::ReadLine();

    Console::WriteLine("Enter Timeframe(Week):");
    String budgetTimeframe = Console::ReadLine();

    Console::WriteLine("Budget Categories:");
    Console::WriteLine("1. Add Category");
    Console::WriteLine("2. Income");
    Console::WriteLine("3. Expense");

    Console::WriteLine("Please enter your choice:");
    int categoryChoice = Console::ReadLine().to_int();

    if (categoryChoice == 1) {
        Console::WriteLine("Enter Category Name:");
        String categoryName = Console::ReadLine();

        Console::WriteLine("Enter Allocated Amount:");
        double allocatedAmount = Console::ReadLine().to_double();

    } else if (categoryChoice == 2) {
    } else if (categoryChoice == 3) {
    }
    

    Console::WriteLine("Press Enter to save the budget.");
    Console::WriteLine("-----------------------------------\n");

    Console::ReadLine();
}

void DriverClass::ChangeBudget() {
    Console::WriteLine("\n-----------------------------------");

    Console::WriteLine("Inside Change Budget function");
    Console::WriteLine("-----------------------------------\n");

    Console::ReadLine();
}

void DriverClass::AddTransaction(){
    Console::WriteLine("\n-----------------------------------");

    Console::WriteLine("Inside Add Transaction function");
    Console::ReadLine();

    Console::WriteLine("-----------------------------------\n");

}