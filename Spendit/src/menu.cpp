#include "menu.h"
#include "budget.h"
#include <time.h>

void clear_menu() {
    int i;
    for (i = 0; i < 5; i++) {
        WriteLine("\n\n\n\n\n");
    }
}

void any_key() {
    WriteLine("\nPress enter to continue...");
    getchar();
}

int initial_menu(NODE *users, USER **auth){
    int opc = 1;

    do {
        clear_menu();
        WriteLine("-----------------------------------------------------------\n");
        WriteLine("\n");
        WriteLine(" .d8888b.                                  888 d8b 888    \n");
        WriteLine("d88P  Y88b                                 888 Y8P 888    \n");
        WriteLine("Y88b.                                      888     888    \n");
        WriteLine(" \"Y888b.   88888b.   .d88b.  88888b.   .d88888 888 888888 \n");
        WriteLine("    \"Y88b. 888 \"88b d8P  Y8b 888 \"88b d88\" 888 888 888    \n");
        WriteLine("      \"888 888  888 88888888 888  888 888  888 888 888    \n");
        WriteLine("Y88b  d88P 888 d88P Y8b.     888  888 Y88b 888 888 Y88b.  \n");
        WriteLine(" \"Y8888P\"  88888P\"   \"Y8888  888  888  \"Y88888 888  \"Y888 \n");
        WriteLine("           888                                             \n");
        WriteLine("           888                                             \n");
        WriteLine("           888                                             \n");
        WriteLine("\n");
        WriteLine("-----------------------------------------------------------\n");    
        WriteLine("\n");
        WriteLine("\n");
        WriteLine("\n");

        WriteLine("-------------------\n");
        WriteLine("      WELCOME      \n");
        WriteLine("-------------------\n");
        WriteLine("[ 1 ] Authenticate\n");
        WriteLine("[ 0 ] Exit\n\n");
        WriteLine("Option:");
        scanf("%d", &opc);
        fflush(stdin);

        clear_menu();

        if(opc == 1 && auth_menu(users, auth) == 0) return 0;

    }while(opc != 0);

    return -1;
}

int auth_menu(NODE *users, USER **auth) {
    char username[MAX], password[MAX];
    int opc = 1;

    clear_menu();
    do {
        WriteLine("--------------------------\n");
        WriteLine("      AUTHENTICATION      \n");
        WriteLine("--------------------------\n");

        WriteLine("     | Username:");
        scanf("%s", username);
        fflush(stdin);

        WriteLine("     | Password:");
        scanf("%s", password);
        fflush(stdin);

        clear_menu();

        *auth = login(users, username, password);
        clear_menu();

        if (*auth != NULL) return 0;

        if (*auth == NULL) {
            do {
                WriteLine("--------------------------\n");
                WriteLine("      AUTHENTICATION      \n");
                WriteLine("--------------------------\n");
                WriteLine("[1] Try again!\n[0] Exit\n\nOption:");
                scanf("%i", &opc);
                fflush(stdin);
                clear_menu();
            } while (opc < 0 || opc > 1);
        }
    } while (*auth == NULL && opc != 0);

    return -1;
}

int admin_menu(USER auth, NODE **users, NODE **budgets, NODE **queue) {
    int opc;

    do {
        clear_menu();
        WriteLine("----------------------------------------\n");
        WriteLine("               ADMIN MENU               \n");
        WriteLine("----------------------------------------\n");

        WriteLine("[ 1 ] Create new user\n");
        WriteLine("[ 2 ] Budgets CRUD\n");
        WriteLine("[ 3 ] Listing options\n");
        WriteLine("[ 4 ] User ranking\n");
        WriteLine("[ 5 ] Save finished budgets to text file\n");
        WriteLine("[ 9 ] Sign out\n");
        WriteLine("[ 0 ] Exit\n\n");
        WriteLine("Option:");
        scanf("%i", &opc);
        fflush(stdin);

        clear_menu();
        switch (opc) {
            case 1:
                create_user(users);
                any_key();
                break;
            case 2:
                budget_crud_menu(budgets, queue);
                break;
            case 3:
                budget_listing_menu(budgets, queue);
                break;
            case 4:
                list_user_ranking(*users, *budgets);
                any_key();
                break;
            case 5:
                save_finished_budgets(*budgets);
                any_key();
                break;
            case 8:
                print_users(*users);
                any_key();
                break;
            case 9:
                return -4;
            default:
                break;
        }

    } while (opc != 0);
    return 0;
}

int user_menu(USER auth, NODE **budgets, NODE **queue){
    int opc;

    do {
        clear_menu();
        WriteLine("----------------------\n");
        WriteLine("       USER MENU      \n");
        WriteLine("----------------------\n");
        WriteLine("[ 1 ] Budgets CRUD\n");
        WriteLine("[ 2 ] Analyse budget\n");
        WriteLine("[ 3 ] Listing options\n");
        WriteLine("[ 4 ] Save finished budgets to text file\n");
        WriteLine("[ 5 ] Sign out\n");
        WriteLine("[ 0 ] Exit\n\n");
        WriteLine("Option:");
        scanf("%i", &opc);
        fflush(stdin);
        clear_menu();

        switch (opc) {
            case 1:
                budget_crud_menu(budgets, queue);
                break;
            case 2:
                analyse_budget(auth,budgets,queue);
                any_key();
                break;
            case 3:
                budget_listing_menu(budgets, queue);
                break;
            case 4:
                save_finished_budgets(*budgets);
                any_key();
                break;
            case 5:
                return -4;
            default:
                break;
        }

    } while (opc != 0);
    return 0;
}

int budget_listing_menu(NODE **budgets, NODE **queue){
    int opc;
    float amount = 0;
    char string[MAX];

    do {
        clear_menu();
        WriteLine("-----------------------------------------------\n");
        WriteLine("               BUDGET LISTING MENU             \n");
        WriteLine("-----------------------------------------------\n");
        WriteLine("[ 1 ] List all under-spent budgets\n");
        WriteLine("[ 2 ] List all overspent budgets\n");
        WriteLine("[ 3 ] List all expired budgets\n");
        WriteLine("[ 4 ] List all budgets above given amount\n");
        WriteLine("[ 5 ] List all budgets by certain user\n");
        WriteLine("[ 0 ] Exit\n\n");
        WriteLine("Option:");
        scanf("%i", &opc);
        clear_menu();

        switch (opc) {
            case 1:
                list_pending_budgets(*queue);
                any_key();
                break;
            case 2:
                list_finished_budgets(*budgets);
                any_key();
                break;
            case 3:
                list_approved_budgets(*budgets);
                any_key();
                break;
            case 4:
                WriteLine("Enter the amount:");
                scanf("%f", &amount);
                list_budgets_above_amount(*budgets, amount);
                any_key();
                break;
            case 5:
                WriteLine("Enter the username:");
                scanf("%s", string);
                list_finished_budgets_by_user(*budgets, string);
                any_key();
                break;
            default:
                break;
        }

    } while (opc != 0);
    return 0;
}

int budget_crud_menu(NODE **budgets, NODE **queue){
    int opc;

    do {
        clear_menu();
        WriteLine("-----------------------------\n");
        WriteLine("      BUDGET CRUD MENU       \n");
        WriteLine("-----------------------------\n");

        WriteLine("[ 1 ] Create new budget\n");
        WriteLine("[ 2 ] Read budget by ID\n");
        WriteLine("[ 3 ] Update budget by ID\n");
        WriteLine("[ 4 ] Delete budget by ID\n");
        WriteLine("[ 0 ] Exit\n\n");
        WriteLine("Option:");
        scanf("%i", &opc);
        fflush(stdin);

        clear_menu();
        switch (opc) {
            case 1:
                create_budget(budgets, queue);
                any_key();
                break;
            case 2:
                read_budget_by_id(budgets);
                any_key();
                break;
            case 3:
                update_budget_by_id(budgets, queue);
                break;
            case 4:
                crud_remove_budget_by_id(budgets, queue);
                any_key();
                break;
            default:
                break;
        }

    } while (opc != 0);
}

// START::{ADMIN FUNCTIONS}

int create_user(NODE **users) {
    int opc, res;

    USER *user = malloc(sizeof(USER));

    if (user == NULL) return -3;

    do {
        clear_menu();
        WriteLine("----------------------\n");
        WriteLine("       NEW USER       \n");
        WriteLine("----------------------\n");

        WriteLine(" | Username:");
        scanf("%s", user->username);
        fflush(stdin);

        WriteLine(" | Name:");
        scanf("%s", user->name);
        fflush(stdin);

        WriteLine(" | Password:");
        scanf("%s", user->password);
        fflush(stdin);

        WriteLine(" | Role: (0) - user | (1) - admin\n");
        WriteLine("   Option:");
        scanf("%d", (int*)&user->role);
        fflush(stdin);

        res = add_user(users, user);

        switch (res) {
            case 0:
                save_users(*users);
                WriteLine("User created successfully!");
                return 0;
            case -1:
                do {
                    clear_menu();
                    WriteLine("-------------------------------------\n");
                    WriteLine("       USERNAME ALREADY EXISTS       \n");
                    WriteLine("-------------------------------------\n");
                    WriteLine("[ 1 ] Try again!\n");
                    WriteLine("[ 0 ] Exit\n\n");
                    WriteLine("Option:");
                    scanf("%i", &opc);
                } while (opc < 0 || opc > 1);
                break;
            default:
                break;
        }

    } while (opc != 0);

    free(user);
    return -1;
}

int create_budget(NODE **budgets, NODE **queue) {
    int opc, res;
    NODE *aux = NULL;
    DETAIL *detail = NULL;
    BUDGET *budget = (BUDGET *) malloc(sizeof(BUDGET));

    if (budget == NULL) return -3;

    budget->total = 0;
    budget->state = pending;
    budget->details = NULL;

    WriteLine("------------------------\n");
    WriteLine("       NEW BUDGET       \n");
    WriteLine("------------------------\n");

    WriteLine(" | Budget Name:");
    scanf("%s", budget->supplier);
    fflush(stdin);

    WriteLine(" | Description:");
    scanf("%s", budget->description);
    fflush(stdin);

    do {
        WriteLine(" | Want to add category? (1) - yes | (0) - no\n");
        WriteLine("   Option:");
        scanf("%i", &opc);
        fflush(stdin);
    } while (opc < 0 || opc > 1);

    while (opc != 0) {

        res = create_detail(&budget->details);

        if(res == -2) break;

        if(res != 0)
            return res;

        calculate_budget_total(budget);

        do {
            WriteLine(" | Want to add more category? (1) - yes | (0) - no\n");
            WriteLine("   Option:");
            scanf("%i", &opc);
            fflush(stdin);
        } while (opc < 0 || opc > 1);
    }

    res = add_budget(budgets, budget);
    push(queue, budget, sizeof (BUDGET));

    if (res != 0) {
        free(budget);
        return res;
    }

    save_budgets(*budgets);
    WriteLine("Budget created successfully!");
    return 0;
}

int create_detail(NODE **details){
    int res = 0;

    if(length(*details) >= 20) {
        WriteLine("Maximum details reached!\n");
        return -2;
    }

    DETAIL *detail = (DETAIL *) malloc(sizeof(DETAIL));

    if (detail == NULL) return -3;

    WriteLine("-----------------------------\n");
    WriteLine("       NEW DETAIL NR%i       \n", length(*details));
    WriteLine("-----------------------------\n");
    WriteLine("   | Category Name:");
    scanf("%s", detail->description);
    fflush(stdin);

    WriteLine("   | Time Limit:");
    scanf("%d", &detail->quantity);
    fflush(stdin);

    WriteLine("   | Allocated amount:");
    scanf("%f", &detail->price);
    fflush(stdin);

    res = add_detail(details, detail);

    if (res != 0) {
        free(detail);
        return res;
    }

    return 0;
}

void read_budget_by_id(NODE **budgets){
    int opc, res = 0;
    BUDGET *budget = NULL;

    if(length(*budgets) == 0){
        WriteLine("Budgets list is empty!");
        return;
    }

    do{
        opc = 0;
        WriteLine("Budget ID:");
        scanf("%i",&res);
        fflush(stdin);

        budget = find_budget_by_id(*budgets,res);

        if(budget == NULL){
            do{
                WriteLine("Budget not found!\n");
                WriteLine("Would you like to try again? (1) - yes | (0) - no\n");
                WriteLine("Option: ");
                scanf("%i",&opc);
                fflush(stdin);
            }while(opc < 0 || opc > 1);
        }else{
            print_budget(budget);
        }
    }while(opc != 0);


}

void crud_remove_budget_by_id(NODE **budgets, NODE **queue){
    int opc, res = 0;

    BUDGET *budget = NULL;

    if(length(*budgets) == 0){
        WriteLine("Budgets list is empty!");
        return;
    }

    do{
        opc = 0;
        WriteLine("Budget ID:");
        scanf("%i",&res);
        fflush(stdin);

        budget = find_budget_by_id(*budgets,res);

        if(budget == NULL){
            do{
                WriteLine("Budget not found!\n");
                WriteLine("Would you like to try again? (1) - yes | (0) - no\n");
                WriteLine("Option: ");
                scanf("%i",&opc);
                fflush(stdin);
            }while(opc < 0 || opc > 1);
        }else{
            opc = remove_budget_by_id(budgets, queue, res);
            if(opc == 0){
                save_budgets(*budgets);
                WriteLine("Budget removed successfully!\n");
            }
        }
    }while(opc != 0);
}

void update_budget_by_id(NODE **budgets, NODE **queue){
    int opc, res = 0, selected = 0, validState;
    BUDGET *budget = NULL;

    if(length(*budgets) == 0){
        WriteLine("Budgets list is empty!");
        any_key();
        return;
    }

    do{
        opc = 0;
        WriteLine("Budget ID:");
        scanf("%i",&res);
        fflush(stdin);

        budget = find_budget_by_id(*budgets,res);

        if(budget == NULL){
            do{
                WriteLine("Budget not found!\n");
                WriteLine("Would you like to try again? (1) - yes | (0) - no\n");
                WriteLine("Option: ");
                scanf("%i",&opc);
                fflush(stdin);
            }while(opc < 0 || opc > 1);
        }else{
            do {
                clear_menu();
                print_budget(budget);
                WriteLine("\nWhich field would you like to update?\n");
                WriteLine("[ 1 ] Budget Name\n");
                WriteLine("[ 2 ] Description\n");
                WriteLine("[ 3 ] State\n");
                WriteLine("[ 4 ] Details\n");
                WriteLine("[ 0 ] Exit\n");
                WriteLine("Option:");
                scanf("%i", &selected);
                fflush(stdin);

                switch(selected){
                    case 1:
                        WriteLine("\nNew Name:");
                        fgets(budget->supplier, sizeof(budget->supplier), stdin);
                        fflush(stdin);
                        save_budgets(*budgets);
                        break;
                    case 2:
                        WriteLine("\nNew description:");
                        fgets(budget->description, sizeof(budget->description), stdin);
                        fflush(stdin);
                        save_budgets(*budgets);
                        break;
                    case 3:
                        do{
                            validState = 0;
                            WriteLine("\nNew State: (0) - pending");

                            if(strlen(budget->user) != 0 && budget->state != finished)
                                WriteLine(" | (2) - finished");
                            WriteLine("\nOption:");

                            scanf("%d", (int*)&budget->state);
                            fflush(stdin);

                            if(budget->state == finished && strlen(budget->user) == 0)
                                validState = -1;

                        }while(budget->state < 0 || budget->state > 2 || budget->state == 1 || validState != 0);
                        if(budget->state == pending) load_queue(*budgets,queue);
                        save_budgets(*budgets);
                        break;
                    case 4:
                        budget_details_menu(budgets,budget);
                        break;
                }

            }while(selected != 0);
        }
    }while(opc != 0);
}

void budget_details_menu(NODE **budgets, BUDGET *budget){
    int opc = 0, selected = 0, res ;
    DETAIL *detail;

    if(budget == NULL) return;

    do{
        opc = 0;
        clear_menu();
        WriteLine("BUDGET category MENU\n");
        WriteLine("[ 1 ] Add new category\n");
        WriteLine("[ 2 ] Update category by number\n");
        WriteLine("[ 3 ] Remove category by number\n");
        WriteLine("[ 0 ] Exit\n");
        WriteLine("Option:");
        scanf("%i", &opc);
        fflush(stdin);

        switch(opc){
            case 1:
                create_detail(&budget->details);
                calculate_budget_total(budget);
                save_budgets(*budgets);
                any_key();
                break;
            case 2:
                if(length(budget->details) == 0) {
                    WriteLine("Budget category list is empty!");
                    any_key();
                    break;
                }

                print_budget(budget);
                WriteLine("\nUPDATE category\n");
                WriteLine("Category number:");
                scanf("%i", &selected);

                detail = find_detail_by_position(budget->details, selected);

                if(detail == NULL){
                    WriteLine("Category not found!\n");
                    any_key();
                }else{
                    do{
                        clear_menu();
                        WriteLine("Category NR%i\n", selected);
                        WriteLine(" |- Description: %s\n", detail->description);
                        WriteLine(" |- Time Limit: %i\n", detail->quantity);
                        WriteLine(" |- Allocated money: %.2f\n\n", detail->price);

                        WriteLine("What would you like to update?\n");
                        WriteLine("[ 1 ] Description\n");
                        WriteLine("[ 2 ] Time Limit\n");
                        WriteLine("[ 3 ] Allocated money\n");
                        WriteLine("[ 0 ] Exit\n");
                        scanf("%i", &opc);
                        fflush(stdin);

                        switch(opc){
                            case 1:
                                WriteLine("New description:");
                                fgets(detail->description, sizeof(detail->description), stdin);
                                save_budgets(*budgets);
                                break;
                            case 2:
                                WriteLine("New Time Limit:");
                                scanf("%i", &detail->quantity);
                                calculate_budget_total(budget);
                                save_budgets(*budgets);
                                break;
                            case 3:
                                WriteLine("New Allocated money:");
                                scanf("%f", &detail->price);
                                calculate_budget_total(budget);
                                save_budgets(*budgets);
                                break;
                        }
                    }while(opc != 0);
                    opc = 1;
                }


                break;
            case 3:
                if(length(budget->details) == 0) {
                    WriteLine("Budget category list is empty!");
                    any_key();
                    break;
                }

                print_budget(budget);
                WriteLine("\nREMOVE category\n");
                WriteLine("Category number:");
                scanf("%i", &selected);

                res = remove_detail_by_position(&budget->details, selected);

                if(res == 0){
                    WriteLine("Category removed successfully!");
                }else{
                    WriteLine("Failed to remove detail!");
                }

                any_key();
                break;
        }

    }while(opc != 0);
}

void list_pending_budgets(NODE *queue){
    NODE *aux = NULL;
    BUDGET *budget_data = NULL;

    if(queue == NULL){
        WriteLine("No pending budgets found!\n");
        return;
    }

    aux = queue;
    while(aux != NULL){
        budget_data = (BUDGET*) aux->data;

        print_budget(budget_data);
        WriteLine("\n");
        aux = aux->next;
    }
}

void list_finished_budgets(NODE *budgets){
    int count = 0;
    NODE *aux = NULL;
    BUDGET *budget_data = NULL;


    aux = budgets;
    while(aux != NULL){
        budget_data = (BUDGET*) aux->data;

        if(budget_data->state == finished){
            print_budget(budget_data);
            WriteLine("\n");
            count++;
        }

        aux = aux->next;
    }

    if(count == 0) WriteLine("No finished budgets found!\n");
}

void list_approved_budgets(NODE *budgets){
    int count = 0;
    NODE *aux = NULL;
    BUDGET *budget_data = NULL;


    aux = budgets;
    while(aux != NULL){
        budget_data = (BUDGET*) aux->data;

        if(budget_data->state == finished && budget_data->result == approved){
            print_budget(budget_data);
            WriteLine("\n");
            count++;
        }

        aux = aux->next;
    }

    if(count == 0) WriteLine("No finished and approved budgets found!\n");
}

void list_budgets_above_amount(NODE *budgets, float amount){
    int count = 0;
    NODE *aux = NULL;
    BUDGET *budget_data = NULL;


    aux = budgets;
    while(aux != NULL){
        budget_data = (BUDGET*) aux->data;

        if(budget_data->total > amount){
            print_budget(budget_data);
            WriteLine("\n");
            count++;
        }

        aux = aux->next;
    }

    if(count == 0) WriteLine("No budgets found with total above %.2f$!\n", amount);
}

void list_budgets_by_supplier(NODE *budgets, char supplier[MAX]){
    int count = 0;
    NODE *aux = NULL;
    BUDGET *budget_data = NULL;


    aux = budgets;
    while(aux != NULL){
        budget_data = (BUDGET*) aux->data;

        if(strcmp(budget_data->supplier, supplier) == 0){
            print_budget(budget_data);
            WriteLine("\n");
            count++;
        }

        aux = aux->next;
    }

    if(count == 0) WriteLine("No budgets found by supplier: %s!\n", supplier);
}

void list_user_ranking(NODE *users, NODE *budgets){
    NODE *aux = NULL;
    RANKING *ranking = NULL, temp;
    int size = 0, i, j, pos = 0;

    /* Counts how many users there is */
    aux = users;
    while(aux != NULL){
        USER *data = (USER *) aux->data;

        if(data->role == decision_maker) size++;
        aux = aux->next;
    }

    if(size == 0){
        WriteLine("Ranking is empty!");
        return;
    }

    ranking = (RANKING *) calloc(size, sizeof (RANKING));

    /* Populate the array with all users */
    aux = users;
    while(aux != NULL){
        USER *data = (USER *) aux->data;

        if(data->role == decision_maker){
            strcpy(ranking[pos].username, data->username);
            ranking[pos].score = 0;
            pos++;
        }

        aux = aux->next;
    }

    /* Iterate through the budgets list */
    aux = budgets;
    while(aux != NULL){
        BUDGET *data = (BUDGET *) aux->data;

        if(data->state == finished){
            /* Loop through all the ranking array */
            for(i = 0; i < pos; i++){
                /* When user found, increment the score */
                if(strcmp(ranking[i].username, data->user) == 0 ){
                    ranking[i].score++;
                    break;
                }
            }
        }

        aux = aux->next;
    }

    // Insertion sort
    for(i = 1; i < pos; i++){
        temp = ranking[i];
        j = i - 1;
        while(j >= 0 && ranking[j].score < temp.score){
            ranking[j + 1] = ranking[j];
            j--;
        }

        ranking[j + 1] = temp;
    }

    WriteLine("--------------------------\n");
    WriteLine("       USER RANKING       \n");
    WriteLine("--------------------------\n");
    for(i = 0; i < pos; i++){
        WriteLine("%i: %i - %s\n", i + 1, ranking[i].score, ranking[i].username);
    }

    free(ranking);
}

void list_finished_budgets_by_user(NODE *budgets, char username[MAX]){
    NODE *aux = NULL;
    BUDGET *list = NULL, temp;
    int size = 0, i, j, pos = 0;

    /* Counts how many finished budgets there is */
    aux = budgets;
    while(aux != NULL){
        BUDGET *data = (BUDGET *) aux->data;

        if(data->state == finished && strcmp(data->user, username) == 0) size++;
        aux = aux->next;
    }

    if(size == 0){
        WriteLine("List is empty!");
        return;
    }

    list = (BUDGET *) calloc(size, sizeof (BUDGET));

    /* Populate the array with all budgets */
    aux = budgets;
    while(aux != NULL){
        BUDGET *data = (BUDGET *) aux->data;

        if(data->state == finished  && strcmp(data->user, username) == 0){
            list[pos] = *data;
            pos++;
        }

        aux = aux->next;
    }


    // Insertion sort - date
    for(i = 1; i < pos; i++){
        temp = list[i];
        j = i - 1;
        while(j >= 0 && list[j].date > temp.date){
            list[j + 1] = list[j];
            j--;
        }

        list[j + 1] = temp;
    }

    // Insertion sort - result
    for(i = 1; i < pos; i++){
        temp = list[i];
        j = i - 1;
        while(j >= 0 && list[j].result > temp.result){
            list[j + 1] = list[j];
            j--;
        }

        list[j + 1] = temp;
    }


    WriteLine("--------------------------\n");
    WriteLine("          BUDGETS         \n");
    WriteLine("--------------------------\n");
    for(i = 0; i < pos; i++){
        print_budget(&list[i]);
        WriteLine("\n");
    }

    free(list);
}

int save_finished_budgets(NODE *budgets){
    NODE *aux = NULL;
    DETAIL *detail = NULL;
    BUDGET *list = NULL, temp;
    int size = 0, i, j, pos = 0;

    FILE *fp = fopen(finished_budgets_filename, "w");

    if(fp == NULL) return -3;

    /* Counts how many finished budgets there is */
    aux = budgets;
    while(aux != NULL){
        BUDGET *data = (BUDGET *) aux->data;

        if(data->state == finished) size++;
        aux = aux->next;
    }

    if(size == 0){
        WriteLine("List is empty!");
        fWriteLine(fp,"");
        return 0;
    }

    list = (BUDGET *) calloc(size, sizeof (BUDGET));

    /* Populate the array with all budgets */
    aux = budgets;
    while(aux != NULL){
        BUDGET *data = (BUDGET *) aux->data;

        if(data->state == finished){
            list[pos] = *data;
            pos++;
        }

        aux = aux->next;
    }


    // Insertion sort - amount
    for(i = 1; i < pos; i++){
        temp = list[i];
        j = i - 1;
        while(j >= 0 && list[j].total > temp.total){
            list[j + 1] = list[j];
            j--;
        }

        list[j + 1] = temp;
    }

    for(i = 0; i < pos; i++){
        temp = list[i];

        fWriteLine(fp,"------- BUDGET -------\n");
        fWriteLine(fp," |- ID: %i\n", temp.id);
        fWriteLine(fp," |- Budget Name: %s\n", temp.supplier);
        fWriteLine(fp," |- Description: %s\n", temp.description);
        fWriteLine(fp," | Total: %.2f$\n", temp.total);

        switch (temp.state) {
            case 0:
                fWriteLine(fp," |- State: Pending\n");
                break;
            case 1:
                fWriteLine(fp," |- State: Analysing\n");
                break;
            case 2:
                fWriteLine(fp," |- State: Finished\n");
                break;
        }

        aux = temp.details;

        if(aux == NULL){
            fWriteLine(fp," |- Details list empty!\n");
        }else{
            fWriteLine(fp," |- Details list:\n");
            while(aux != NULL){
                detail = (DETAIL*) aux->data;

                fWriteLine(fp,"  |- Item:\n");
                fWriteLine(fp,"     |- Description: %s\n", detail->description);
                fWriteLine(fp,"     |- Quantity: %d\n", detail->quantity);
                fWriteLine(fp,"     |- Unitary price: %.2f$\n", detail->price);

                aux = aux->next;
            }
        }

        switch (temp.result) {
            case -1:
                break;
            case 0:
                fWriteLine(fp," |- Result: Denied\n");
                break;
            case 1:
                fWriteLine(fp," |- Result: Approved\n");
                break;
        }

        fWriteLine(fp," |- Date: %s\n", asctime(gmtime(&temp.date)));
        fWriteLine(fp," |- Justification: %s\n", temp.justification);
        fWriteLine(fp," |- User that analysed: %s\n", temp.user);
        fWriteLine(fp,"\n\n");
    }



    free(list);
    fclose(fp);
    return 0;
}
// END::{ADMIN FUNCTIONS}

// START::{USER FUNCTIONS}

void analyse_budget(USER auth,NODE **budgets, NODE **queue){
    int result;
    char justification[MAX];

    if(*queue == NULL) {
        WriteLine("Queue is empty!");
        return;
    }

    BUDGET *budget = (BUDGET*) (*queue)->data;

    print_budget(budget);

    budget->state = analysing;

    do{
        WriteLine(" | Final result: (1) approved | (0) denied\n");
        WriteLine("   Option:");
        scanf("%i", &result);
        fflush(stdin);
    }while(result < 0 || result > 1);

    WriteLine(" | Justification:");
    fgets(justification, sizeof(justification), stdin);
    fflush(stdin);

    budget->result = result;
    strcpy(budget->justification, justification);
    strcpy(budget->user ,auth.username);
    budget->date = time(NULL);
    budget->state = finished;

    shift(queue);
    save_budgets(*budgets);
}

// END::{USER FUNCTIONS}