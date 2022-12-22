/*THIS IS THE C PROGRAM WHICH CAN MANAGE NEW PROJECTS,EXPENSES,FEED HISTORY,EMPLOYEE SALARY,SELLING INFO, AND GENERATE REPORTS LIKE TOTAL EXPENSES,TOTAL SELLS, LOSS PROFIT ECT.
AUTHOR IS:---- MD. SAMI ALAM---ID: 222-16-656------SECTION: A--------DEPARTMENT: CIS----BATCH: 15TH*/

#include <stdio.h>
#include <string.h>
// function declaration
void menu();
int authentication();
// manage project function declaration
void sub_menu();
void create_new_project();
void save_project_info();
void view_all_project_info();
void update_project_info();
void delete_project_info();
int manage_PID();
// expense project function declaration
void sub_menu_2();
void create_new_expense();
void save_expense_info();
void view_all_expense_info();
void update_expense_info();
void delete_expense_info();
int expense_PID();
// feed history function declaration
void sub_menu_3();
void create_new_feed_history();
void save_feed_history_info();
void view_all_feed_history_info();
void update_feed_history_info();
void delete_feed_history_info();
int feed_PID();
// selling history function declaration
void sub_menu_4();
void create_new_selling_info();
void save_selling_info();
void view_all_selling_history_info();
void update_selling_info();
void delete_selling_info();
int sell_PID();
// employee salary function declaration
void sub_menu_5();
void create_new_employee_info();
void save_employee_info();
void view_all_employees_history_info();
void update_employee_salary_info();
void delete_employee_salary_info();
int employee_PID();
// generate report function declaration
void report_generation();
// price estimation feature
// .......................................
// global declaration section

//----------------7 structure for 7 types of main menu-----------------------//
struct Project
{
    int project_code;
    char project_id[50], project_name[50], project_short_des[100], project_type[30], start_date[15], end_date[15];
    float estimated_budget;
};
struct expense
{
    int project_code;
    char expense_id[50];
    char expense_date[50], expense_type[50], item_name[50], supplier_info[100];
    float expense_amount;
};
struct feed
{
    int project_code;
    float feed_quantity;
    char feed_id[50], feed_date[50], feed_timing[50], feed_catagory[100];
};
struct sell
{
    int project_code;
    char selling_id[50], selling_date[50], buyer_info[50];
    float sell_quantity, unit_price, total_amount;
};
struct employee
{
    int project_code;
    char employee_id[50];
    char employee_name[50];
    char employee_address[50];
    char employee_email[50];
    int employee_phone;
    float employee_salary;
};

FILE *filetooperate, *temp_file;
struct Project project_info;
struct expense expense_info;
struct feed feed_info; // declare variables
struct sell sell_info;
struct employee employee_info;

//--------------###########################-------------------- main function section----------------------------------
int main()
{

    int choice;
    printf("\n================================ WELCOME =====================================\n");
    printf("\n========================MAZUMDAR'S AGRO & FRISHARIES==========================\n\nWHAT DO YOU WANT TO DO?-----------?\nDO YOU WANT TO LOGIN----------?\n\n1. YES LOGIN\n2. NO\n\nPLEASE ENTER YOUR CHOICE(1/2)------: ");

lebel1:
    scanf("%d", &choice);
    if (choice == 1)
    {

    lebel3:
        if (authentication() == 0)
        {

            menu();
        }
        else
        {
            printf("\nYOUR PASSWORD IS INCORRECT. PLEASE TRY AGAIN.\n");
            goto lebel3;
        }
    }
    else if (choice == 2)
    {
        exit(0);
    }
    else
    {
        printf("\nINVALID CHOICE. IF YOU WANT TO LOGIN---PLEASE ENTER ('1') OR IF YOU WANT TO EXIT---PLEASE ENTER ('2')\nTRY AGAIN: ");
        goto lebel1;
    }

    return 0;
}

// function definition
void menu()
{
    system("cls");
    printf("\n-----------------------------------------------------------------------------\n===================MAZUMDAR'S AGRO & FRISHARIES ADMIN PANEL=================\n-----------------------------------------------------------------------------\n\n1.MANAGE FISH OR POULTRY PROJECT\n\n2.MANAGE EXPENSES\n\n3.MANAGE FEED HISTORY\n\n4.MANAGE SELLING INFO\n\n5.MANAGE EMPLOYEE SALARY INFO\n\n6.GENERATE REPORTS\n\n7.MAKE A PRICE ESTIMATION\n\n8.BACK TO HOME\n\n9.EXIT\n\nENTER A TERM YOU WANT TO USE(1/2/3/4/5/6/7/8/9): ");
    int user_choice;

lebel2:
    scanf("%d", &user_choice);
    switch (user_choice)
    {
    case 1:
        sub_menu();
        break;
    case 2:
        sub_menu_2();
        break;
    case 3:
        sub_menu_3();
        break;
    case 4:
        sub_menu_4();
        break;
    case 5:
        sub_menu_5();
        break;
    case 6:
        report_generation();
        break;
    case 7:

        break;
    case 8:
        menu();
        break;
    case 9:
        exit(0);
        break;
    default:
        printf("\nINVALID INPUT. PLEASE ENTER A VALID INPUT: ");
        goto lebel2;
    }
}

int authentication()
{
    char system_password[30] = "12345";
    char user_password[30];
    printf("\nTO ACCESS ENTER THE PASSWORD: ");
    fflush(stdin);
    gets(user_password);
    return strcmp(user_password, system_password);
}

//.......................... manage section.......................
void sub_menu()
{

    system("cls");
    char sub_menu_choice;

    printf("\n\n\n#################################-----MAZUMDAR'S AGRO & FRISHARIES ADMIN PANEL-----#################################\n");
    printf("\n\n========================================= MANAGE NEW FISH & POULTRY PROJECTS ========================================\n\n");
    printf("\n\nA.CREATE NEW PROJECT INFO");
    printf("\n\nB.VIEW ALL PROJECT INFO");
    printf("\n\nC.UPDATE EXISTING PROJECT INFO");
    printf("\n\nD.DELETE A PROJECT");
    printf("\n\nE.BACK TO MAIN MENU");
label4:
    printf("\n\nCHOSE THE OPTION(A/B/C/D/E): ");

    // Choose User Input
    fflush(stdin);
    scanf("%c", &sub_menu_choice);
    sub_menu_choice = toupper(sub_menu_choice);
    switch (sub_menu_choice)
    {
    case 'A':
        create_new_project();
        break;
    case 'B':
        view_all_project_info();
        break;
    case 'C':
        update_project_info();
        break;
    case 'D':
        delete_project_info();
        break;
    case 'E':
        printf("\nBack Successfully\n");
        menu();
        break;
    default:
        printf("\nInvalid Input!\nTry again!!\n");
        goto label4;
    }
}

void create_new_project()
{
    system("cls");
    struct project;
    printf("\n\n\n-----------------------------------MAZUMDAR'S AGRO & FRISHARIES ADMIN PANEL.-----------------------------------\n");
    printf("\n====================================== PROVIDE ALL INFORMATION ABOUT THE PROJECT ====================================\n\n\n");

    project_info.project_code = manage_PID() + 1;
    fflush(stdin);

    printf("Please Enter Project Type (Fish/Poultry): ");
    fflush(stdin);
    gets(project_info.project_type);

    printf("Please your Project id: ");
    fflush(stdin);
    gets(project_info.project_id);

    printf("Please Enter Project Name/Title: ");
    fflush(stdin);
    gets(project_info.project_name);

    printf("Please Provide Short Details About Projcet: ");
    fflush(stdin);
    gets(project_info.project_short_des);

    printf("Please Enter Project Start Date: ");
    fflush(stdin);
    gets(project_info.start_date);

    printf("Please Enter Project End Date: ");
    fflush(stdin);
    gets(project_info.end_date);

    printf("Please Enter the Estimated Budget: ");
    fflush(stdin);
    scanf("%f", &project_info.estimated_budget);

    save_project_info();

add_record:
    printf("\n\t\t\t1.Do You Want To Add Another new Project info?\n\t\t\t0.Project Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        create_new_project();
    }
    else if (choice == 0)
    {
        sub_menu();
    }
    else
    {
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto add_record;
    }
}
void save_project_info()
{
    filetooperate = fopen("projectinformation.txt", "a");
    fwrite(&project_info, sizeof(struct Project), 1, filetooperate);
    if (fwrite != 0)
    {
        printf("\nSuccessfully Saved\n");
    }
    else
    {
        printf("\nSomething went wrong\n");
    }
    fclose(filetooperate);
}
int manage_PID()
{
    int current_id = 0;
    filetooperate = fopen("projectinformation.txt", "r");
    while (fread(&project_info, sizeof(struct Project), 1, filetooperate))
    {
        current_id = project_info.project_code;
    }
    fclose(filetooperate);
    return current_id;
}

void view_all_project_info()
{
    system("cls");
    filetooperate = fopen("projectinformation.txt", "r");
    printf("\n\n==========================================================All PROJECT INFORMATION====================================================\n\n");
    printf("\n\nPROJECT CODE\tPROJECT ID\tPROJECT TYPE\tPROJECT NAME\tPROJECT SHORT DESCRIPTION\tStart Date\tEnd Date\t\tESTIMATED BUDGET");
    while (fread(&project_info, sizeof(struct Project), 1, filetooperate))
    {
        printf("\n\n%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%.3f\n", project_info.project_code, project_info.project_id, project_info.project_type, project_info.project_name, project_info.project_short_des, project_info.start_date, project_info.end_date, project_info.estimated_budget);
    }
    fclose(filetooperate);

add_record1:
    printf("\n\t\t\t1.Project Menu\n\t\t\t2.Main Menu\n\t\t\t3. Exit");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        sub_menu();
    }
    else if (choice == 2)
    {
        menu();
    }
    else if (choice == 3)
    {
        exit(0);
    }
    else
    {
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto add_record1;
    }
}
// ############################# UPDATE YOUR PROJECT ##########################
void update_project_info()
{
    system("cls");
    printf("\n\n############## UPDATE PROJECT INFORMATION ##################\n\n");

    printf("\nPLEASE ENTER PROJECT CODE YOU WANT TO MODIFY: ");
    int p_id;
    fflush(stdin);
    scanf("%d", &p_id);
    filetooperate = fopen("projectinformation.txt", "r+");
    int found = 0;
    while (fread(&project_info, sizeof(struct Project), 1, filetooperate))
    {
        if (project_info.project_code == p_id)
        {
            found = 1;
            printf("\n\n#########################--------PROVIDE ALL THE NECESSARY INFORMATION ABOUT THE PROJECT--------#########################\n\n");

            printf("Please Enter Project Type (Fish/Poultry): ");
            fflush(stdin);
            gets(project_info.project_type);

            printf("Enter the project ID: ");
            fflush(stdin);
            gets(project_info.project_id);

            printf("Please Enter Project Name/Title: ");
            fflush(stdin);
            gets(project_info.project_name);

            printf("Please Provide Short Details About Projcet: ");
            fflush(stdin);
            gets(project_info.project_short_des);

            printf("Please Enter Project Start Date: ");
            fflush(stdin);
            gets(project_info.start_date);

            printf("Please Enter Project End Date: ");
            fflush(stdin);
            gets(project_info.end_date);

            printf("Please Enter the Estimated Budget: ");
            fflush(stdin);
            scanf("%f", &project_info.estimated_budget);

            fseek(filetooperate, -sizeof(project_info), SEEK_CUR);
            fwrite(&project_info, sizeof(struct Project), 1, filetooperate);
            break;
        }
    }
    fclose(filetooperate);
    if (found == 1)
    {
        printf("\nPROJECT INFO HAS UPDATED");
    }
    else
    {
        printf("\nPROJECT ID NOT FOUND ON OUR DATABASE");
    }
update_project:
    printf("\n\t\t\t1.Do You Want To Modify Another  Project info?\n\t\t\t2.Project Menu\n\t\t\t3.Main Menu");
    printf("\n\t\tEnter your choice: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        update_project_info();
    }
    else if (choice == 2)
    {
        sub_menu();
    }
    else if (choice == 3)
    {
        menu();
    }
    else
    {
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto update_project;
    }
}

// ######################### Delete project ###########################
void delete_project_info()
{
    FILE *remove_file;
    int p_id;
    printf("\n##############################--------DELETE YOUR PROJECT--------################################\n");
    printf("\n\n\nENTER THE PROJECT CODE YOU WANT DELETE: ");
    fflush(stdin);
    scanf("%d", &p_id);

    filetooperate = fopen("projectinformation.txt", "r+");
    remove_file = fopen("temp.txt", "a+");
    if (filetooperate == NULL)
    {
        fprintf(stderr, "THIS FILE CAN NOT BE OPENED");
        exit(0);
    }
    while (fread(&project_info, sizeof(struct Project), 1, filetooperate))
    {
        if (project_info.project_code != p_id)
        {
            fwrite(&project_info, sizeof(struct Project), 1, remove_file);
        }
    }
    fclose(filetooperate);
    fclose(remove_file);

    remove("projectinformation.txt");
    rename("temp.txt", "projectinformation.txt");
    printf("\nproject information delete successfuly\n");

delete_record:
    printf("\n\t\t1.DO YOU WANT TO DELETE ANOTHER PROJECT INFO?\n\t\t2.PROJECT MENU\n\t\t3.MAIN MENU");
    printf("\n\t\tEnter your choice: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        delete_project_info();
    }
    else if (choice == 2)
    {
        sub_menu();
    }
    else if (choice == 3)
    {
        menu();
    }
    else
    {
        printf("\n\t\tINVALID INPUT..........PLEASE ENTER A VALID CHOICE");
        goto delete_record;
    }
}

//..........................expense section....................//
void sub_menu_2()
{

    system("cls");
    char sub_menu_choice;

    printf("\n\n\n-----------------------------------MAZUMDAR'S AGRO & FRISHARIES ADMIN PANEL.-----------------------------------\n");
    printf("\n============================================== MANAGE THE EXPENSE SECTION ==============================================\n\n");
    printf("\n\nA.CREATE NEW EXPENSE INFO");
    printf("\n\nB.VIEW ALL EXPENSE INFO");
    printf("\n\nC.UPDATE EXISTING EXPENSE INFO");
    printf("\n\nD.DELETE A EXPENSE INFO");
    printf("\n\nE.BACK TO MAIN MENU");
label4:
    printf("\n\nCHOSE THE OPTION(A/B/C/D/E): ");

    // Choose User Input
    fflush(stdin);
    scanf("%c", &sub_menu_choice);
    sub_menu_choice = toupper(sub_menu_choice);
    switch (sub_menu_choice)
    {
    case 'A':
        create_new_expense();
        break;
    case 'B':
        view_all_expense_info();
        break;
    case 'C':
        update_expense_info();
        break;
    case 'D':
        delete_expense_info();
        break;
    case 'E':
        printf("\nBack Successfully\n");
        menu();
        break;
    default:
        printf("\nInvalid Input!\nTry again!!\n");
        goto label4;
    }
}

void create_new_expense()
{
    system("cls");
    struct expense;
    printf("\n\n\n-----------------------------------MAZUMDAR'S AGRO & FRISHARIES ADMIN PANEL.-----------------------------------\n");
    printf("\n====================================== PROVIDE ALL INFORMATION ABOUT THE EXPENSES ====================================\n\n\n");

    fflush(stdin);
    expense_info.project_code = expense_PID() + 1;

    printf("Please Enter expense Type (Fish/Poultry): ");
    fflush(stdin);
    gets(expense_info.expense_type);

    printf("Please Enter expense ID: ");
    fflush(stdin);
    gets(expense_info.expense_id);

    printf("Please Enter expense Name/Title: ");
    fflush(stdin);
    gets(expense_info.item_name);

    printf("Please Provide the expense date: ");
    fflush(stdin);
    gets(expense_info.expense_date);

    printf("Please Enter supplier information: ");
    fflush(stdin);
    gets(expense_info.supplier_info);

    printf("Please Enter the expense amount: ");
    fflush(stdin);
    scanf("%f", &expense_info.expense_amount);

    save_expense_info();

add_record:
    printf("\n\t\t\t1.Do You Want To Add Another new EXPENSE info?\n\t\t\t0.Expense Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        create_new_expense();
    }
    else if (choice == 0)
    {
        sub_menu_2();
    }
    else if (choice == 2)
    {
        create_new_expense();
    }
    else
    {
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto add_record;
    }
}
void save_expense_info()
{
    filetooperate = fopen("expenseinformation.txt", "a");
    fwrite(&expense_info, sizeof(struct expense), 1, filetooperate);
    if (fwrite != 0)
    {
        printf("\nSuccessfully Saved\n");
    }
    else
    {
        printf("\nSomething went wrong\n");
    }
    fclose(filetooperate);
}

int expense_PID()
{
    int current_id = 0;
    filetooperate = fopen("expenseinformation.txt", "r");
    while (fread(&expense_info, sizeof(struct expense), 1, filetooperate))
    {
        current_id = expense_info.project_code;
    }
    fclose(filetooperate);
    return current_id;
}
void view_all_expense_info()
{
    system("cls");
    filetooperate = fopen("expenseinformation.txt", "r");
    printf("\n\n=================================== All EXPENSE INFO =======================================\n\n");
    printf("\n\nPROJECT CODE\tEXPENSE ID\tEXPENSE ITEM NAME\tEXPENSE TYPE\tEXPENSE DATE\tSUPPLIER INFORMATIO\t\tEXPENSE AMOUNT\n");
    while (fread(&expense_info, sizeof(struct expense), 1, filetooperate))
    {
        printf("\n\n%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%.3f\n", expense_info.project_code, expense_info.expense_id, expense_info.item_name, expense_info.expense_type, expense_info.expense_date, expense_info.supplier_info, expense_info.expense_amount);
    }
    fclose(filetooperate);

add_record1:
    printf("\n\t\t\t1.Expense Menu\n\t\t\t2.Main Menu\n\t\t\t3. Exit");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        sub_menu_2();
    }
    else if (choice == 2)
    {
        menu();
    }
    else if (choice == 3)
    {
        exit(0);
    }
    else
    {
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto add_record1;
    }
}
// ############################# UPDATE YOUR EXPENSE ##########################
void update_expense_info()
{
    system("cls");
    printf("\n\n========================= UPDATE EXPENSE INFORMATION =========================\n\n");

    printf("\nPLEASE ENTER PROJECT CODE YOU WANT TO MODIFY: ");
    int p_id;
    fflush(stdin);
    scanf("%d", &p_id);
    filetooperate = fopen("expenseinformation.txt", "r+");
    int found = 0;
    while (fread(&expense_info, sizeof(struct expense), 1, filetooperate))
    {
        if (expense_info.project_code == p_id)
        {
            found = 1;
            printf("\n======================= PROVIDE ALL THE NECESSARY INFOMATION ABOUT THE EXPENSE =========================\n\n");

            printf("Please Enter expense Type (Fish/Poultry): ");
            fflush(stdin);
            gets(expense_info.expense_type);

            printf("Please Enter expense ID: ");
            fflush(stdin);
            gets(expense_info.expense_id);

            printf("Please Enter expense Name/Title: ");
            fflush(stdin);
            gets(expense_info.item_name);

            printf("Please Provide the expense date: ");
            fflush(stdin);
            gets(expense_info.expense_date);

            printf("Please Enter supplier information: ");
            fflush(stdin);
            gets(expense_info.supplier_info);

            printf("Please Enter the expense amount: ");
            fflush(stdin);
            scanf("%f", &expense_info.expense_amount);

            fseek(filetooperate, -sizeof(expense_info), SEEK_CUR);
            fwrite(&expense_info, sizeof(struct expense), 1, filetooperate);
            break;
        }
    }
    fclose(filetooperate);
    if (found == 1)
    {
        printf("\nEXPENSE INFO HAS UPDATED");
    }
    else
    {
        printf("\nEXPENSE ID NOT FOUND ON OUR DATABASE");
    }
update_project:
    printf("\n\t\t\t1.Do You Want To Modify Another  Expense info?\n\t\t\t2.expense Menu\n\t\t\t3.Main Menu");
    printf("\n\t\tEnter your choice: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        update_expense_info();
    }
    else if (choice == 2)
    {
        sub_menu_2();
    }
    else if (choice == 3)
    {
        menu();
    }
    else
    {
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto update_project;
    }
}
// ######################### Delete project ###########################
void delete_expense_info()
{
    FILE *remove_file;
    int p_id;
    printf("\n################-------- DELETE YOUR EXPENSE --------################");
    printf("\n\nENTER THE PROJECT CODE YOU WANT TO DELETE: ");
    fflush(stdin);
    scanf("%d", &p_id);

    filetooperate = fopen("expenseinformation.txt", "r+");
    remove_file = fopen("temp.txt", "a+");
    if (filetooperate == NULL)
    {
        fprintf(stderr, "THIS FILE CAN NOT BE OPENED");
        exit(0);
    }
    while (fread(&expense_info, sizeof(struct expense), 1, filetooperate))
    {
        if (expense_info.project_code != p_id)
        {
            fwrite(&expense_info, sizeof(struct expense), 1, remove_file);
        }
    }
    fclose(filetooperate);
    fclose(remove_file);

    remove("expenseinformation.txt");
    rename("temp.txt", "expenseinformation.txt");
    printf("\nproject information delete successfuly\n");

delete_record:
    printf("\n\t\t1.DO YOU WANT TO DELETE ANOTHER EXPENSE INFO?\n\t\t2.EXPENSE MENU\n\t\t3.MAIN MENU");
    printf("\n\t\tEnter your choice: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        delete_expense_info();
    }
    else if (choice == 2)
    {
        sub_menu_2();
    }
    else if (choice == 3)
    {
        menu();
    }
    else
    {
        printf("\n\t\tINVALID INPUT..........PLEASE ENTER A VALID CHOICE");
        goto delete_record;
    }
}
//------------------------FEED HISTORY SECTION---------------------------//
void sub_menu_3()
{

    system("cls");
    char sub_menu_choice;
    printf("\n\n===================== MAZUMDAR'S AGRO & FRISHARIES ADMIN PANEL =======================\n\n");
    printf("\n\n========================= FEED HISTORY SECTION =======================\n\n");
    printf("\n\nA.CREATE NEW FEED HISTORY INFO");
    printf("\n\nB.VIEW ALL FEED HISTORY INFO");
    printf("\n\nC.UPDATE EXISTING FEED HISTORY INFO");
    printf("\n\nD.DELETE A FEED HISTORY");
    printf("\n\nE.BACK TO MAIN MENU");
label4:
    printf("\n\nCHOSE THE OPTION(A/B/C/D/E): ");

    // Choose User Input
    fflush(stdin);
    scanf("%c", &sub_menu_choice);
    sub_menu_choice = toupper(sub_menu_choice);
    switch (sub_menu_choice)
    {
    case 'A':
        create_new_feed_history();
        break;
    case 'B':
        view_all_feed_history_info();
        break;
    case 'C':
        update_feed_history_info();
        break;
    case 'D':
        delete_feed_history_info();
        break;
    case 'E':
        printf("\nBack Successfully\n");
        menu();
        break;
    default:
        printf("\nInvalid Input!\nTry again!!\n");
        goto label4;
    }
}

void create_new_feed_history()
{
    system("cls");
    struct feed;

    printf("\n\n=========================== PROVIDE ALL INFORMATION ABOUT FEED HISTORY ==================\n\n");

    fflush(stdin);
    feed_info.project_code = feed_PID() + 1;

    printf("Please Enter Feed ID: ");
    fflush(stdin);
    gets(feed_info.feed_id);

    printf("Please Provide the feed history date: ");
    fflush(stdin);
    gets(feed_info.feed_date);

    printf("Please Enter food timing: ");
    fflush(stdin);
    gets(feed_info.feed_timing);

    printf("Please Enter food quantity(KG): ");
    fflush(stdin);
    scanf("%f", &feed_info.feed_quantity);

    printf("Please Enter food catagory: ");
    fflush(stdin);
    gets(feed_info.feed_catagory);

    save_feed_history_info();

add_record:
    printf("\n\t\t\t1.Do You Want To Add Another new Feed History info?\n\t\t\t0.Feed Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        create_new_feed_history();
    }
    else if (choice == 0)
    {
        sub_menu_3();
    }
    else
    {
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto add_record;
    }
}
void save_feed_history_info()
{
    filetooperate = fopen("feedhistoryinformation.txt", "a");
    fwrite(&feed_info, sizeof(struct feed), 1, filetooperate);
    if (fwrite != 0)
    {
        printf("\nSuccessfully Saved\n");
    }
    else
    {
        printf("\nSomething went wrong\n");
    }
    fclose(filetooperate);
}

int feed_PID()
{
    int current_id = 0;
    filetooperate = fopen("feedhistoryinformation.txt", "r");
    while (fread(&feed_info, sizeof(struct feed), 1, filetooperate))
    {
        current_id = feed_info.project_code;
    }
    fclose(filetooperate);
    return current_id;
}
void view_all_feed_history_info()
{
    system("cls");
    filetooperate = fopen("feedhistoryinformation.txt", "r");
    printf("\n\n##############################--------ALL FEED HISTORY MINFORMATION--------##############################\n");
    printf("\n\nPROJECT CODE\t\tFEED ID\t\tFEED DATE\tFEED TIMING\tFEED QUANTITY\tFEED CATAGORY\n");
    while (fread(&feed_info, sizeof(struct feed), 1, filetooperate))
    {
        printf("\n\n%d\t\t%s\t\t%s\t\t%s\t\t%.2f KG\t\t%s\n", feed_info.project_code, feed_info.feed_id, feed_info.feed_date, feed_info.feed_timing, feed_info.feed_quantity, feed_info.feed_catagory);
    }
    fclose(filetooperate);

add_record1:
    printf("\n\t\t\t1.Feed Menu\n\t\t\t2.Main Menu\n\t\t\t3. Exit");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        sub_menu_3();
    }
    else if (choice == 2)
    {
        menu();
    }
    else if (choice == 3)
    {
        exit(0);
    }
    else
    {
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto add_record1;
    }
}
// ############################# UPDATE YOUR FEED HISTORY ##########################
void update_feed_history_info()
{
    system("cls");
    printf("\n\n##############################--------UPDATE FEED HISTORY MINFORMATION--------##############################\n\n");

    printf("\n\nPLEASE ENTER PROJECT CODE YOU WANT TO MODIFY: ");
    int p_id;
    fflush(stdin);
    scanf("%d", &p_id);
    filetooperate = fopen("feedhistoryinformation.txt", "r+");
    int found = 0;
    while (fread(&feed_info, sizeof(struct feed), 1, filetooperate))
    {
        if (feed_info.project_code == p_id)
        {
            found = 1;
            printf("\n=================== PROVIDE ALL THE NECESSARY INFORMATION ABOUT THE FEED HISTORY ============================\n\n");

            printf("Please Enter Feed ID: ");
            fflush(stdin);
            gets(feed_info.feed_id);

            printf("Please Provide the feed history date: ");
            fflush(stdin);
            gets(feed_info.feed_date);

            printf("Please Enter food timing: ");
            fflush(stdin);
            gets(feed_info.feed_timing);

            printf("Please Enter food quantity(KG): ");
            fflush(stdin);
            scanf("%f", &feed_info.feed_quantity);

            printf("Please Enter food catagory: ");
            fflush(stdin);
            gets(feed_info.feed_catagory);

            fseek(filetooperate, -sizeof(feed_info), SEEK_CUR);
            fwrite(&feed_info, sizeof(struct feed), 1, filetooperate);
            break;
        }
    }
    fclose(filetooperate);
    if (found == 1)
    {
        printf("\n\nFEED HISTORY INFO HAS UPDATED");
    }
    else
    {
        printf("\n\nFEED HISTORY ID NOT FOUND ON OUR DATABASE");
    }
update_project:
    printf("\n\t\t\t1.Do You Want To Modify Another  Feed history info?\n\t\t\t2.Feed history Menu\n\t\t\t3.Main Menu");
    printf("\n\t\tEnter your choice: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        update_feed_history_info();
    }
    else if (choice == 2)
    {
        sub_menu_3();
    }
    else if (choice == 3)
    {
        menu();
    }
    else
    {
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto update_project;
    }
}
// ######################### Delete feed history ###########################
void delete_feed_history_info()
{
    FILE *remove_file;
    int p_id;
    printf("\n######################### DELETE FEED HISTORY INFO ###########################");
    printf("\n\nENTER THE PROJECT CODE YOU WANT TO DELETE: ");
    fflush(stdin);
    scanf("%d", &p_id);

    filetooperate = fopen("feedhistoryinformation.txt", "r+");
    remove_file = fopen("temp.txt", "a+");
    if (filetooperate == NULL)
    {
        fprintf(stderr, "THIS FILE CAN NOT BE OPENED");
        exit(0);
    }
    while (fread(&feed_info, sizeof(struct feed), 1, filetooperate))
    {
        if (feed_info.project_code != p_id)
        {
            fwrite(&feed_info, sizeof(struct feed), 1, remove_file);
        }
    }
    fclose(filetooperate);
    fclose(remove_file);

    remove("feedhistoryinformation.txt");
    rename("temp.txt", "feedhistoryinformation.txt");
    printf("\nproject information delete successfuly\n");

delete_record:
    printf("\n\t\t1.DO YOU WANT TO DELETE ANOTHER FEED HISTORY INFO?\n\t\t2.FEED HISTORY MENU\n\t\t3.MAIN MENU");
    printf("\n\t\tEnter your choice: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        delete_feed_history_info();
    }
    else if (choice == 2)
    {
        sub_menu_3();
    }
    else if (choice == 3)
    {
        menu();
    }
    else
    {
        printf("\n\t\tINVALID INPUT..........PLEASE ENTER A VALID CHOICE");
        goto delete_record;
    }
}

//-----------------------------manage selling section----------------------------
void sub_menu_4()
{

    system("cls");
    char sub_menu_choice;

    printf("\n\n\n-----------------------------------MAZUMDAR'S AGRO & FRISHARIES ADMIN PANEL.-----------------------------------\n");
    printf("\n===============================================SELLING INFORMATION SECTION============================================\n\n");
    printf("\n\nA.CREATE NEW SELLING INFO");
    printf("\n\nB.VIEW ALL SELLING INFO");
    printf("\n\nC.UPDATE EXISTING SELLING INFO");
    printf("\n\nD.DELETE A SELLING INFO");
    printf("\n\nE.BACK TO MAIN MENU");
label4:
    printf("\n\nCHOSE THE OPTION(A/B/C/D/E): ");

    // Choose User Input
    fflush(stdin);
    scanf("%c", &sub_menu_choice);
    sub_menu_choice = toupper(sub_menu_choice);
    switch (sub_menu_choice)
    {
    case 'A':
        create_new_selling_info();
        break;
    case 'B':
        view_all_selling_history_info();
        break;
    case 'C':
        update_selling_info();
        break;
    case 'D':
        delete_selling_info();
        break;
    case 'E':
        printf("\nBack Successfully\n");
        menu();
        break;
    default:
        printf("\nInvalid Input!\nTry again!!\n");
        goto label4;
    }
}

void create_new_selling_info()
{
    system("cls");
    struct sell;
    printf("\n\n\n-----------------------------------MAZUMDAR'S AGRO & FRISHARIES ADMIN PANEL.-----------------------------------\n");
    printf("\n=======================================PROVIDE ALL INFORMATION ABOUT THE SELLING====================================\n\n\n");

    fflush(stdin);
    sell_info.project_code = sell_PID() + 1;

    printf("Please Enter Selling ID: ");
    fflush(stdin);
    gets(sell_info.selling_id);

    printf("Please Enter selling date: ");
    fflush(stdin);
    gets(sell_info.selling_date);

    printf("Please Enter the buyer information: ");
    fflush(stdin);
    gets(sell_info.buyer_info);

    printf("Please Provide selling quantity(KG): ");
    fflush(stdin);
    scanf("%fKG", &sell_info.sell_quantity);

    printf("Please Enter the unit price(TK): ");
    fflush(stdin);
    scanf("%f", &sell_info.unit_price);

    printf("The total amount is: %.3f TK", sell_info.total_amount = sell_info.sell_quantity * sell_info.unit_price);

    save_selling_info();

add_record:
    printf("\n\t\t\t1.Do You Want To Add Another new Selling info?\n\t\t\t0.Selling Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        create_new_selling_info();
    }
    else if (choice == 0)
    {
        sub_menu_4();
    }
    else
    {
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto add_record;
    }
}
void save_selling_info()
{
    filetooperate = fopen("sellinginformation.txt", "a");
    fwrite(&sell_info, sizeof(struct sell), 1, filetooperate);
    if (fwrite != 0)
    {
        printf("\nSuccessfully Saved\n");
    }
    else
    {
        printf("\nSomething went wrong\n");
    }
    fclose(filetooperate);
}

int sell_PID()
{
    int current_id = 0;
    filetooperate = fopen("sellinginformation.txt", "r");
    while (fread(&sell_info, sizeof(struct sell), 1, filetooperate))
    {
        current_id = sell_info.project_code;
    }
    fclose(filetooperate);
    return current_id;
}

void view_all_selling_history_info()
{
    system("cls");
    filetooperate = fopen("sellinginformation.txt", "r");
    printf("\n\n============================== ALL SELLING INFORMATION ==============================\n");
    printf("\n\nPROJECT CODE\t\tSELLING ID\t\tSELLING DATE\t\tBUYER INFO\t\tSELL QUANTITY\t\tUNIT PRICE\t\tTOTAL AMOUNT\n");
    while (fread(&sell_info, sizeof(struct sell), 1, filetooperate))
    {

        printf("\n\n%d\t\t%s\t\t%s\t\t%s\t\t%.3f KG\t\t%.3f TK\t\t%.3f TK\n", sell_info.project_code, sell_info.selling_id, sell_info.selling_date, sell_info.buyer_info, sell_info.sell_quantity, sell_info.unit_price, sell_info.total_amount = sell_info.sell_quantity * sell_info.unit_price);
    }
    fclose(filetooperate);

add_record1:
    printf("\n\t\t\t1.Selling Menu\n\t\t\t2.Main Menu\n\t\t\t3. Exit");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        sub_menu_4();
    }
    else if (choice == 2)
    {
        menu();
    }
    else if (choice == 3)
    {
        exit(0);
    }
    else
    {
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto add_record1;
    }
}
// ############################# UPDATE YOUR SELLING HISTORY ##########################
void update_selling_info()
{
    system("cls");
    printf("\n\n############## UPDATE SELLING HISTORY INFORMATION ##################\n\n");

    printf("\nPLEASE ENTER PROJECT CODE YOU WANT TO MODIFY: ");
    int p_id;
    fflush(stdin);
    scanf("%d", &p_id);
    filetooperate = fopen("sellinginformation.txt", "r+");
    int found = 0;
    while (fread(&sell_info, sizeof(struct sell), 1, filetooperate))
    {
        if (sell_info.project_code == p_id)
        {
            found = 1;
            printf("\nProvide all necessary information about the selling\n\n");

            printf("Please Enter project ID: ");
            fflush(stdin);
            gets(sell_info.selling_id);

            printf("Please Enter selling date: ");
            fflush(stdin);
            gets(sell_info.selling_date);

            printf("Please Enter the buyer information: ");
            fflush(stdin);
            gets(sell_info.buyer_info);

            printf("Please Provide selling quantity(KG): ");
            fflush(stdin);
            scanf("%f", &sell_info.sell_quantity);

            printf("Please Enter the unit price(TK): ");
            fflush(stdin);
            scanf("%f", &sell_info.unit_price);

            printf("The toatal amount is: %.3f TK", sell_info.sell_quantity * sell_info.unit_price);
            // fflush(stdin);
            // scanf("%f", &sell_info.total_amount);

            fseek(filetooperate, -sizeof(sell_info), SEEK_CUR);
            fwrite(&sell_info, sizeof(struct sell), 1, filetooperate);
            break;
        }
    }
    fclose(filetooperate);
    if (found == 1)
    {
        printf("\nSELLING HISTORY INFO HAS UPDATED");
    }
    else
    {
        printf("\nSELLING HISTORY ID NOT FOUND ON OUR DATABASE");
    }
update_project:
    printf("\n\t\t\t1.Do You Want To Modify Another  Selling history info?\n\t\t\t2.Selling history Menu\n\t\t\t3.Main Menu");
    printf("\n\t\tEnter your choice: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        update_selling_info();
    }
    else if (choice == 2)
    {
        sub_menu_4();
    }
    else if (choice == 3)
    {
        menu();
    }
    else
    {
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto update_project;
    }
}
// ######################### Delete project ###########################
void delete_selling_info()
{
    FILE *remove_file;
    int p_id;
    printf("\n===================== DELETE YOUR SELLING INFO ====================");
    printf("\n\nENTER THE PROJECT CODE THAT YOU WANT TO DELETE: ");
    fflush(stdin);
    scanf("%d", &p_id);

    filetooperate = fopen("sellinginformation.txt", "r+");
    remove_file = fopen("temp.txt", "a+");
    if (filetooperate == NULL)
    {
        fprintf(stderr, "THIS FILE CAN NOT BE OPENED");
        exit(0);
    }
    while (fread(&sell_info, sizeof(struct sell), 1, filetooperate))
    {
        if (sell_info.project_code != p_id)
        {
            fwrite(&sell_info, sizeof(struct sell), 1, remove_file);
        }
    }
    fclose(filetooperate);
    fclose(remove_file);

    remove("sellinginformation.txt");
    rename("temp.txt", "sellinginformation.txt");
    printf("\nproject information delete successfuly\n");

delete_record:
    printf("\n\t\t1.DO YOU WANT TO DELETE ANOTHER SELLING HISTORY INFO?\n\t\t2.SELLING HISTORY MENU\n\t\t3.MAIN MENU");
    printf("\n\t\tEnter your choice: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        delete_selling_info();
    }
    else if (choice == 2)
    {
        sub_menu_4();
    }
    else if (choice == 3)
    {
        menu();
    }
    else
    {
        printf("\n\t\tINVALID INPUT..........PLEASE ENTER A VALID CHOICE");
        goto delete_record;
    }
}
//------------------------manage employee salary section------------------------//
void sub_menu_5()
{

    system("cls");
    char sub_menu_choice;

    printf("\n\n================= EMPLOYEE SALARY SECTION =================\n\n");
    printf("\n\nA.CREATE NEW EMPLOYEE SALARY INFO");
    printf("\n\nB.VIEW ALL EMPLOYEE SALARY INFO");
    printf("\n\nC.UPDATE EXISTING EMPLOYEE SALARY INFO");
    printf("\n\nD.DELETE AN EMPLOYEE SALARY INFO");
    printf("\n\nE.BACK TO MAIN MENU");
label4:
    printf("\n\nCHOSE THE OPTION(A/B/C/D/E): ");
    // Choose User Input
    fflush(stdin);
    scanf("%c", &sub_menu_choice);
    sub_menu_choice = toupper(sub_menu_choice);
    switch (sub_menu_choice)
    {
    case 'A':
        create_new_employee_info();
        break;
    case 'B':
        view_all_employees_history_info();
        break;
    case 'C':
        update_employee_salary_info();
        break;
    case 'D':
        delete_employee_salary_info();
        break;
    case 'E':
        printf("\nBack Successfully\n");
        menu();
        break;
    default:
        printf("\nInvalid Input!\nTry again!!\n");
        goto label4;
    }
}

void create_new_employee_info()
{
    system("cls");
    struct employee;

    printf("\n\n\n-----------------------------------MAZUMDAR'S AGRO & FRISHARIES ADMIN PANEL.-----------------------------------\n");
    printf("\n\n=========== CREATE NEW EMPLOYEE INFO ============\n\n");
    fflush(stdin);
    employee_info.project_code = employee_PID() + 1;

    printf("Please Enter employee name: ");
    fflush(stdin);
    gets(employee_info.employee_name);

    printf("Please Enter employee ID: ");
    fflush(stdin);
    gets(employee_info.employee_id);

    printf("Please Enter employee address: ");
    fflush(stdin);
    gets(employee_info.employee_address);

    printf("Please Provide the employee email: ");
    fflush(stdin);
    gets(employee_info.employee_email);

    printf("Please Enter the employee phone number: ");
    fflush(stdin);
    scanf("%d", &employee_info.employee_phone);

    printf("Please Enter the employee salary(TK): ");
    fflush(stdin);
    scanf("%f", &employee_info.employee_salary);

    save_employee_info();

add_record:
    printf("\n\t\t\t1.Do You Want To Add Another new Employee info?\n\t\t\t0.Employee Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        create_new_employee_info();
    }
    else if (choice == 0)
    {
        sub_menu_5();
    }
    else
    {
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto add_record;
    }
}
void save_employee_info()
{
    filetooperate = fopen("employeeinformation.txt", "a");
    fwrite(&employee_info, sizeof(struct employee), 1, filetooperate);
    if (fwrite != 0)
    {
        printf("\nSuccessfully Saved\n");
    }
    else
    {
        printf("\nSomething went wrong\n");
    }
    fclose(filetooperate);
}
int employee_PID()
{
    int current_id = 0;
    filetooperate = fopen("employeeinformation.txt", "r");
    while (fread(&employee_info, sizeof(struct employee), 1, filetooperate))
    {
        current_id = employee_info.project_code;
    }
    fclose(filetooperate);
    return current_id;
}
void view_all_employees_history_info()
{
    system("cls");
    filetooperate = fopen("employeeinformation.txt", "r");
    printf("\n\n============================ ALL EMPLOYEE INFORMATION ================================\n");
    printf("\n\nPROJECT CODE\tEMPLOYEE ID\tEMPLOYEE NAME\tEMPLOYEE ADDRESS\tEMPLOYEE EMAIL\tEMPLOYEE PHONE\tEMPLOYEE SALARY\n");
    while (fread(&employee_info, sizeof(struct employee), 1, filetooperate))
    {
        printf("\n\n%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%d\t\t%.3f TK\n", employee_info.project_code, employee_info.employee_id, employee_info.employee_name, employee_info.employee_address, employee_info.employee_email, employee_info.employee_phone, employee_info.employee_salary);
    }
    fclose(filetooperate);

add_record1:
    printf("\n\t\t\t1.Employee Menu\n\t\t\t2.Main Menu\n\t\t\t3. Exit");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        sub_menu_5();
    }
    else if (choice == 2)
    {
        menu();
    }
    else if (choice == 3)
    {
        exit(0);
    }
    else
    {
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto add_record1;
    }
}
// ############################# UPDATE YOUR EMPLOYEE SALARY INFO ##########################
void update_employee_salary_info()
{
    system("cls");
    printf("\n\n=============== UPDATE EMPLOYEE SALARY INFORMATION =================\n\n");
    printf("\nPLEASE ENTER EMPLOYEE ID YOU WANT TO MODIFY: ");
    int p_id;
    fflush(stdin);
    scanf("%d", &p_id);
    filetooperate = fopen("employeeinformation.txt", "r+");
    int found = 0;
    while (fread(&employee_info, sizeof(struct employee), 1, filetooperate))
    {
        if (employee_info.project_code == p_id)
        {
            found = 1;
            printf("\n============ PROVIDE ALL THE NECESSARY INFORMATION ABOUT THE EMPLOYEE ===========\n\n");

            printf("Please Enter employee name: ");
            fflush(stdin);
            gets(employee_info.employee_name);

            printf("Please Enter employee ID: ");
            fflush(stdin);
            gets(employee_info.employee_id);

            printf("Please Enter employee address: ");
            fflush(stdin);
            gets(employee_info.employee_address);

            printf("Please Provide the employee email: ");
            fflush(stdin);
            gets(employee_info.employee_email);

            printf("Please Enter the employee phone number: ");
            fflush(stdin);
            scanf("%d", &employee_info.employee_phone);

            printf("Please Enter the employee salary(TK): ");
            fflush(stdin);
            scanf("%f", &employee_info.employee_salary);

            fseek(filetooperate, -sizeof(employee_info), SEEK_CUR);
            fwrite(&employee_info, sizeof(struct employee), 1, filetooperate);
            break;
        }
    }
    fclose(filetooperate);
    if (found == 1)
    {
        printf("\nEMPLOYEE INFO HAS UPDATED");
    }
    else
    {
        printf("\nEMPLOYEE ID NOT FOUND ON OUR DATABASE");
    }
update_project:
    printf("\n\t\t\t1.Do You Want To Modify Another  Employee info?\n\t\t\t2.Employee Menu\n\t\t\t3.Main Menu");
    printf("\n\t\tEnter your choice: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        update_employee_salary_info();
    }
    else if (choice == 2)
    {
        sub_menu_5();
    }
    else if (choice == 3)
    {
        menu();
    }
    else
    {
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto update_project;
    }
}
// ######################### Delete project ###########################
void delete_employee_salary_info()
{
    FILE *remove_file;
    int p_id;
    printf("\n================================== DELETE YOUR EMPLOYEE INFORMATION ==================================");
    printf("\n\nENTER THE PROJECT CODE THAT YOU WANT TO DELETE: ");
    fflush(stdin);
    scanf("%d", &p_id);

    filetooperate = fopen("employeeinformation.txt", "r+");
    remove_file = fopen("temp.txt", "a+");
    if (filetooperate == NULL)
    {
        fprintf(stderr, "THIS FILE CAN NOT BE OPENED");
        exit(0);
    }
    while (fread(&employee_info, sizeof(struct employee), 1, filetooperate))
    {
        if (employee_info.project_code != p_id)
        {
            fwrite(&employee_info, sizeof(struct employee), 1, remove_file);
        }
    }
    fclose(filetooperate);
    fclose(remove_file);

    remove("employeeinformation.txt");
    rename("temp.txt", "employeeinformation.txt");
    printf("\nproject information delete successfuly\n");

delete_record:
    printf("\n\t\t1.DO YOU WANT TO DELETE ANOTHER EMPLOYEE INFO?\n\t\t2.EMPLOYEE MENU\n\t\t3.MAIN MENU");
    printf("\n\t\tEnter your choice: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        delete_employee_salary_info();
    }
    else if (choice == 2)
    {
        sub_menu_5();
    }
    else if (choice == 3)
    {
        menu();
    }
    else
    {
        printf("\n\t\tINVALID INPUT..........PLEASE ENTER A VALID CHOICE");
        goto delete_record;
    }
}

//------------------------ Report Generation Section -------------------------
void report_generation()
{
    system("cls");
    int p_id;
    float total_expense = 0, total_sell = 0, total_feed = 0;
    printf("\n---------------------------------------- WELCOME TO REPORT GENERATION INTERFACE ----------------------------------------\n\n\n\n");
    printf("PLEASE ENTER THE PROJECT CODE THAT YOU WANT TO GENERATE REPORT: ");
    fflush(stdin);
    scanf("%d", &p_id);

    printf("----------------------------------------- REPORT GENETARION INFORMATION ------------------------------------------");

    filetooperate = fopen("expenseinformation.txt", "r");
    while (fread(&expense_info, sizeof(struct expense), 1, filetooperate))
    {
        if (expense_info.project_code == p_id)
        {
            total_expense += expense_info.expense_amount;
        }
    }
    fclose(filetooperate);

    filetooperate = fopen("feedhistoryinformation.txt", "r");
    while (fread(&feed_info, sizeof(struct feed), 1, filetooperate))
    {
        if (feed_info.project_code == p_id)
        {
            total_feed += feed_info.feed_quantity;
        }
    }
    fclose(filetooperate);

    filetooperate = fopen("sellinginformation.txt", "r");
    while (fread(&sell_info, sizeof(struct sell), 1, filetooperate))
    {
        if (sell_info.project_code == p_id)
        {
            total_sell += sell_info.total_amount;
        }
    }
    fclose(filetooperate);
    printf("\n\nPROJECT CODE: %d", p_id);
    printf("\n\nTHE TOTAL EXPENSE OF THIS PROJECT: %.3f KG", total_expense);
    printf("\n\nTHE TOTAL FEED WERE GIVEN TO THIS PROJECT: %.3f KG", total_feed);
    printf("\n\nTHE TOTAL SELL OF THIS PROJECT: %.3f", total_sell);
    if (total_sell > total_expense)
    {
        printf("\n\nTHE PROJECT HAS MADE INCURRED PROFIT: %.3f TK", total_sell - total_expense);
    }
    else
    {
        printf("\n\nTHE PROJECT HAS MADE INCURRED LOSS: %.3f TK", total_expense - total_sell);
    }

addRecord:
    printf("\n\n\t\t\t1.DO YOU WANT TO GENERATE ANOTHER PROJECT REPORT?\n\t\t\t2.MAIN MENU\n\t\t\t3.EXIT PROGRAM ");
    printf("ENTER THE CHOICE(1/2/3): ");

    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        report_generation();
        break;
    case 2:
        menu();
        break;
    case 3:
        exit(0);
        break;
    default:
        printf("INVALID INPUT!!!!! PLEASE ENTER A VALID INPUT(1/2/3)");
        goto addRecord;
        break;
    }
}
