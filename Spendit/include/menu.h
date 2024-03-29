#pragma once

#include "user.h"
#include "budget.h"

/*
 * Clears the menu screen
*/
void clear_menu();

/*
 * Prompts the user to press enter to continue
*/
void any_key();

/*
 * Initial menu
 *  - return  0: Success
 *  - return -1: Exit program
*/
int initial_menu(NODE *users, USER **auth);

/*
 * Login menu
 *  - return  0: Success
 *  - return -1: Exit
*/
int auth_menu(NODE *users, USER **auth);

/*
 * Admin menu
 *  - return -4: Sign out
*/
int admin_menu(USER auth, NODE **users, NODE **budgets, NODE **queue);

/*
 * User menu
 *  - return -4: Sign out
*/
int user_menu(USER auth, NODE **budgets, NODE **queue);


/*
 * Listing menu
*/
int budget_listing_menu(NODE **budgets, NODE **queue);

/*
 * Budgets CRUD menu
*/
int budget_crud_menu(NODE **budgets, NODE **queue);

/*
 * Prompts the user for new user info
 *  - return  0: Success
 *  - return -1: Failed to create user
 *  - return -3: Out of memory
*/
int create_user(NODE **users);

/*
 * Prompts the user for new budget info
 *  - return  0: Success
 *  - return -1: Failed to create budget
 *  - return -3: Out of memory
*/
int create_budget(NODE **budgets, NODE **queue);

/*
 * Prompts the user the ID to list the budget
*/
void read_budget_by_id(NODE **budgets);

/*
 * Prompts the user the ID and new info to update the budget
*/
void update_budget_by_id(NODE **budgets, NODE **queue);

/*
 * Menu to update te user details
*/
void budget_details_menu(NODE **budgets, BUDGET *budget);

/*
 * Prompts the user the ID to remove the budget
*/
void crud_remove_budget_by_id(NODE **budgets, NODE **queue);

/*
 * Prompts the user for new detail info
 *  - return  0: Success
 *  - return -1: Failed to create detail
 *  - return -2: Maximum details reached
 *  - return -3: Out of memory
*/
int create_detail(NODE **details);

/*
 * Lists all information about the pending budgets
*/
void list_pending_budgets(NODE *queue);

/*
 * Lists all information about the finished budgets
*/
void list_finished_budgets(NODE *budgets);

/*
 * Lists all information about the approved budgets
*/
void list_approved_budgets(NODE *budgets);

/*
 * Lists all information about the budgets that are above a given amount
*/
void list_budgets_above_amount(NODE *budgets, float amount);

/*
 * Lists all information about the budgets given the supplier
*/
void list_budgets_by_supplier(NODE *budgets, char supplier[MAX]);

/*
 * Generates a ranking of users ordered by the number of budgets analysed
*/
void list_user_ranking(NODE *users, NODE *budgets);

/*
 * Lists all information about the finished budgets analysed by a certain user
 * ordered by date and result
*/
void list_finished_budgets_by_user(NODE *budgets, char username[MAX]);

/*
 * Saves to a text file all finished budgets
 * ordered by amount
 *  - return  0: Success
 *  - return -3: Error opening file
*/
int save_finished_budgets(NODE *budgets);

/*
 * Prompts the user with budget info to analyse
*/
void analyse_budget(USER auth, NODE **budgets, NODE **queue);

#endif //PROJB_24473_MENU_H
