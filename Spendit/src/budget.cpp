#pragma once
#include "category.h"
#include "string.h"
#include "list.h"
#include "console.h"
#include <iostream>

class Budget {
public:
    Budget();
    Budget(const String& name, const String& timeframe, double totalAllocatedBudget);
    void AddCategory(const String& name, double allocatedAmount);
    void ModifyCategory(const String& name, double newAllocatedAmount);
    void AddSubcategory(const String& categoryName, const String& subcategoryName, double allocatedAmount);
    double CalculateRemainingBudget();
    double CalculateTotalExpenses() const;
    double CalculateTotalIncome() const;
    void DisplayBudgetSummary() const;

    String name;
    String timeframe;
    double totalAllocatedBudget;
    List<Category> categories;
};
Bekkol
Mir Sayad
#include "budget.h"

Budget::Budget(){}

Budget::Budget(const String& name, const String& timeframe, double totalAllocatedBudget) : name(name), timeframe(timeframe) {
    totalAllocatedBudget = 0.0;
}

void Budget::AddCategory(const String& name, double allocatedAmount) {
    Category category(name, allocatedAmount);
    categories.push(category);
}

void Budget::ModifyCategory(const String& name, double newAllocatedAmount) {
    for (int i = 0; i < categories.size(); i++) {
        if (categories[i].name == name) {
            categories[i].ModifyAllocatedAmount(newAllocatedAmount);
            break;
        }
    }
}


// void Budget::AddSubcategory(const String& categoryName, const String& subcategoryName, double allocatedAmount) {
//     for (Category& category : categories) {
//         if (category.name == categoryName) {
//             category.AddSubcategory(subcategoryName, allocatedAmount);
//             break; // Assuming each subcategory name is unique within its category
//         }
//     }
// }

double Budget::CalculateRemainingBudget(){
    double totalAllocated = 0.0;
    for (int i = 0; i < categories.size(); i++) {
        totalAllocated += categories[i].GiveAlloctedAmount();
    }

    double totalIncome = 0.0;
    double totalExpenses = 0.0;

    double remainingBudget = totalIncome - totalExpenses - totalAllocated;

    return remainingBudget;
}

double Budget::CalculateTotalExpenses() const {
    double totalExpenses = 0.0;
    return totalExpenses;
}

double Budget::CalculateTotalIncome() const {
    double totalIncome = 0.0;
    return totalIncome;
}

void Budget::DisplayBudgetSummary() const {
    Console::WriteLine("View Budget:");
    Console::WriteLine("Budget Status:");

    // Calculate total allocated budget, total expenses, and total income
    //double totalAllocatedBudget = 0.0;
    // for (int i = 0; i < categories.size(); i++) {
    //     totalAllocatedBudget += categories[i].allocatedAmount;
    // }

    double totalExpenses = 0.0;
    // for (int i = 0; i < expenses.size(); i++) {
    //     totalExpenses += expenses[i].allocatedAmount;
    // }

    double totalIncome = 0.0;
    // for (int i = 0; i < incomes.size(); i++) {
    //     totalIncome += incomes[i].allocatedAmount;
    // }

    double remainingBudget = totalAllocatedBudget - totalExpenses + totalIncome;
    double riskOfOverspending = (totalExpenses / totalAllocatedBudget) * 100;
    double amountOverspent = totalExpenses - totalIncome;
    double amountSaved = totalIncome - totalExpenses;

    // Display budget status
    // Console::WriteLine("Total Allocated Budget: $" << totalAllocatedBudget);
    // Console::WriteLine("Total Expenses: $" << totalExpenses);
    // Console::WriteLine("Total Income: $" << totalIncome);
    // Console::WriteLine("Remaining Budget: $" << remainingBudget);
    // Console::WriteLine("Risk of Overspending: " << riskOfOverspending << "%");
    // Console::WriteLine("Amount Overspent: $" << amountOverspent);
    // Console::WriteLine("Amount Saved: $" << amountSaved);

    // Console::WriteLine("Press Enter to return to the main menu.");
    Console::ReadLine();
}