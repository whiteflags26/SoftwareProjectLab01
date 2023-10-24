#pragma once
#include "budget.h"
#include "category.h"
#include "console.h"
#include "string.h"
#include "list.h"
#include<iostream>

class DriverClass {
public:
    //void DriverClass();
    void MainMenu();
    
    ///////////////////////////
    void ManageBudget();
    
    void ViewBudget();
    void ChangeBudget();
    void MakeBudget();
    ///////////////////////
    void AddTransaction();
};
