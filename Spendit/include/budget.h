#pragma once
#include "category.h"
#include "string.h"
#include "list.h"

class Budget {
public:
    Budget();
    Budget(const String& name, const String& timeframe);
    void AddCategory(const String& name, double allocatedAmount);
    void ModifyCategory(const String& name, double newAllocatedAmount);
    void AddSubcategory(const String& categoryName, const String& subcategoryName, double allocatedAmount);
    double CalculateRemainingBudget();
    double CalculateTotalExpenses() const;
    double CalculateTotalIncome() const;

    String name;
    String timeframe;
    List<Category> categories;
};
