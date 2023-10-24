#pragma once
#include "string.h"

class Category {
public:
    Category();
    Category(const String& name, double allocatedAmount);
    void ModifyAllocatedAmount(double newAllocatedAmount);
    //void AddSubcategory(const String& subcategoryName, double allocatedAmount);
    double GiveAlloctedAmount();

    String name;

private:
    double allocatedAmount;
};