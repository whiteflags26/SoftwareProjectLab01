#include "budget.h"

Budget::Budget(const String& name, const String& timeframe) : name(name), timeframe(timeframe) {}

void Budget::AddCategory(const String& name, double allocatedAmount) {
    Category category(name, allocatedAmount);
    categories.push(category);
}

void Budget::ModifyCategory(const String& name, double newAllocatedAmount) {
    for (int i = 0; i < categories.size(); i++) {
        if (categories[i].name == name) {
            categories[i].ModifyAllocatedAmount(newAllocatedAmount);
            break; // Assuming each category name is unique
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

    // Calculate total income and expenses (not implemented here)
    double totalIncome = 0.0;
    double totalExpenses = 0.0;

    // Calculate remaining budget
    double remainingBudget = totalIncome - totalExpenses - totalAllocated;

    return remainingBudget;
}

double Budget::CalculateTotalExpenses() const {
    // Calculate and return total expenses (not implemented here)
    double totalExpenses = 0.0;
    return totalExpenses;
}

double Budget::CalculateTotalIncome() const {
    // Calculate and return total income (not implemented here)
    double totalIncome = 0.0;
    return totalIncome;
}
