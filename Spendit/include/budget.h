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