#include "category.h"

Category::Category() {
    name = ""; 
    allocatedAmount = 0.0; 
}

Category::Category(const String& name, double allocatedAmount)
    : name(name), allocatedAmount(allocatedAmount) {}

void Category::ModifyAllocatedAmount(double newAllocatedAmount) {
    allocatedAmount = newAllocatedAmount;
}

double Category::GiveAlloctedAmount(){
    return  allocatedAmount;
}