/*
Full System Code
Project Title: Digital Money Manager
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
//structure veriable
struct user {
    char phone[50];
    char password[50];
    char name[50];
    char account_number[50];
    int balance;
};
//initial balance
int balance=0;
//function prototype
void divider();
void exit_program();
void login_user();
void register_user();
void admin_menu();
void deposit_money();
void withdraw_money();
void account_report();
void account_details();
void account_update();
void account_delete();
void total_user_account();
void search_account();
//void current_date();
//main fuction
int main() {
    system("color F1");
    int option;
    char date_str[20];
    system("cls");

    while (1) {
        printf("\n\n\n\n\t\t\t\t\t\t*Digital Money Manager*\t\t\t\t\t\n");
        time_t t = time(NULL);
        struct tm *tm_info = localtime(&t);
        strftime(date_str, sizeof(date_str), "%Y-%m-%d", tm_info);
        printf("\t\t\t\t\t\t Date: %s\n", date_str);
        divider();
        printf("\n\n\t\t\t\t\t\t 1. User Login\t\t\t\t\n");
        printf("\n\n\t\t\t\t\t\t 2. User Register\t\t\t\t\n");
        printf("\n\n\t\t\t\t\t\t 3. Admin Login\t\t\t\t\n");
        printf("\n\n\t\t\t\t\t\t 4. Exit From System\t\t\t\t\n");
        printf("\n\n\t\t\t\t\t\t Enter Your Choice: ");
        scanf("%d", &option);
        system("cls");

        switch (option) {
            case 1:
                login_user();
                break;
            case 2:
                 register_user();
                break;
            case 3:
                admin_menu();
                break;
            case 4:
                exit_program();
                return 0;
            default:
                printf("\n\t\t\t\t\t*Invalid Choice, Try Again!*");
                break;
        }
    }
    return 0;
}
//divider function
void divider() {
    printf("\n\n\t\t");
    for (int i = 0; i < 90; i++) {
        printf("-");
    }
    printf("\n");
}
//exit function
void exit_program() {
    printf("\n\n\n\n\t\t\t\t\tThanks For Using Digital Money Manager!\n\n\n\n");
}
//login function
void login_user() {
    system("cls");
        printf("\n\n\n\n\t\t\t\t\t\t*User Login*\n");
        divider();
    struct user accountUser;
    char filename[50], phone[50], password[50];
    FILE *fp;
    int choice;
    char cont = 'y';
    printf("\n\n\t\t\t\t\tPhone No:\t");
    scanf("%s", phone);
    printf("\n\n\t\t\t\t\tPassword:\t");
    scanf("%s", password);

    strcpy(filename, phone);
    fp = fopen(strcat(filename, ".dat"), "r");

    if (fp == NULL) {
        printf("\n\t\t\t\t\tPhone Number Not Registered\n");
        return;
    }
    fread(&accountUser, sizeof(struct user), 1, fp);
    fclose(fp);

    if (strcmp(password, accountUser.password) != 0) {
        printf("\n\t\t\t\t\tInvalid password\n");
        return;
    }
//user dashboard
    while (cont == 'y') {
        system("cls");
        printf("\n\t\t\t\t\t\t*User Dashboard*\n");
        divider();
        printf("\n\t\t\t\t\t1. Deposit Your Salary\n");
        printf("\n\t\t\t\t\t2. Withdraw From Salary\n");
        printf("\n\t\t\t\t\t3. Account Report\n");
        printf("\n\t\t\t\t\t4. Account Details\n");
        printf("\n\t\t\t\t\t5. Account Update\n");
        printf("\n\t\t\t\t\t6. Account Delete\n");
        printf("\n\t\t\t\t\t7. Logout From System\n");
        printf("\n\n\t\t\t\t\tEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deposit_money(&accountUser);
                break;
            case 2:
                withdraw_money(&accountUser);
                break;
            case 3:
                account_report(&accountUser);
                break;
            case 4:
                account_details(&accountUser);
                break;
            case 5:
                account_update(&accountUser);
                break;
            case 6:
                account_delete(&accountUser);
                break;
            case 7:
                return;
            default:
                printf("\n\t\t\t\t\t*Invalid Choice, Try Again!*");
                break;
        }
        printf("\n\n\t\t\t\t\tDo You Want To Continue? [y/n]: ");
        scanf(" %c", &cont);
    }
}
//registration function
void register_user(){
    system("cls");
    printf("\n\n\n\n\t\t\t\t\t\t\t*User Registration*\n");
        divider();
    struct user new_user;
    char filename[50];
    FILE *fp;
    printf("\n\n\t\t\t\t\tEnter Your Name:\t");
    scanf("%s", new_user.name);
    printf("\n\n\t\t\t\t\tEnter Your Phone Number:\t");
    scanf("%s", new_user.phone);
    printf("\n\n\t\t\t\t\tEnter Your Phone Number Again:\t");
    scanf("%s", new_user.account_number);
    printf("\n\n\t\t\t\t\tEnter Your New Password:\t");
    scanf("%s", new_user.password);
    new_user.balance = 0;
    strcpy(filename, new_user.phone);
    fp = fopen(strcat(filename, ".dat"),"w");
    fwrite(&new_user, sizeof(new_user),1, fp);
    fclose(fp);
    printf("\n\n\t\t\t\t\tSuccessfully Registered\n\n");
}
//admin function
void admin_menu() {
    system("cls");
    printf("\n\n\n\n\t\t\t\t\t\t   *Admin Login*\n");
        divider();
    char admin_password[50];
    printf("\n\n\t\t\t\t\t\tEnter Admin Password: ");
    scanf("%s", admin_password);
    if (strcmp(admin_password, "admin123") != 0) {
        printf("\n\n\t\t\t\t\tInvalid Password.\n");
        return;
    }
    int admin_choice;
    system("cls");
//admin dashboard
    while (1){
        printf("\n\n\n\n\t\t\t\t\t\t*Admin Menu*\n");
        divider();
        printf("\n\n\t\t\t\t\t 1. View Total Account\n");
        printf("\n\t\t\t\t\t 2. Search User Account\n");
        printf("\n\t\t\t\t\t 3. Report User Account\n");
        printf("\n\t\t\t\t\t 4. Update User Account\n");
        printf("\n\t\t\t\t\t 5. Delete User Account\n");
        printf("\n\t\t\t\t\t 6. User Account Details\n");
        printf("\n\t\t\t\t\t 7. Logout From System\n");
        printf("\n\n\t\t\t\t\t Enter Your Choice: ");
        scanf("%d", &admin_choice);

        switch (admin_choice) {
            case 1:
                total_user_account();
                break;
            case 2:
                search_account();
                break;
            case 3:
                account_report();
                break;
            case 4:
               account_update();
                break;
            case 5:
               account_delete();
                break;
            case 6:
               account_details();
                break;
            case 7:
                return;
            default:
                printf("\n\t\t\t\t\t*Invalid Choice, Try Again!*");
                break;
        }
    }
}
//deposit fuction
void deposit_money(struct user *accountUser) {
    int diposit_amount;
    FILE *fb = fopen("userAccount.txt", "w");
    printf("\n\t\t\t\t\t*Deposit Money*\n");
    divider();
    printf("\n\n\t\t\t\t\tEnter The Amount You Want To Deposit:");
    scanf("%d", &diposit_amount);
    balance += diposit_amount;

    printf("\n\t\t\t\t\t**Money Deposited\n");
    printf("\n\t\t\t\t\tNow balance : %d\n", balance);
    fprintf(fb, "\n\n\t\t\t\t\tTk%d Had Been Deposited To Your Account \n", diposit_amount);
    fclose(fb);
    printf("\n\t\t\t\t\tPress any key....\n");
    getch();
}
//withdraw fuction
void withdraw_money(struct user *accountUser) {
    int withdraw_amount;
    FILE *fb = fopen("userAccount.txt", "w");
    printf("\n\t\t\t\t\t*Withdraw Money*\n");
    divider();
    printf("\n\n\t\t\t\t\tEnter The Amount You Want To Deposit:");
    scanf("%d", &withdraw_amount);
    if (balance > withdraw_amount) {
        printf("\n\t\t\t\t\tInsufficient Funds\n");
    } else {
        balance -= withdraw_amount;
    printf("\n\t\t\t\t\t**Money Deposited\n");
    printf("\n\t\t\t\t\tNow Balance : %d\n", balance);
    fprintf(fb, "\n\n\t\t\t\t\tTk%d had been deposited to your account \n", withdraw_amount);
    }
    fclose(fb);
    printf("\n\t\t\t\t\tPress any key....\n");
    getch();
}
//account report function
void account_report(struct user *accountUser){
    system("cls");
    FILE *fb = fopen("userAccount.txt", "w");
    printf("\n\t\t\t\t\t\t*Account Report*\n");
    divider();


    //statement


    printf("\n\t\t\t\t\tThe Months Report Of Running Year:\n\n");
    printf("\n\t January-   | Deposit: 0 | Withdraw: 0 | House: 0 | Food: 0 | Child: 0 | Family: 0 | Another: 0\n");
    printf("\n\t February-  | Deposit: 0 | Withdraw: 0 | House: 0 | Food: 0 | Child: 0 | Family: 0 | Another: 0\n");
    printf("\n\t March-     | Deposit: 0 | Withdraw: 0 | House: 0 | Food: 0 | Child: 0 | Family: 0 | Another: 0\n");
    printf("\n\t April-     | Deposit: 0 | Withdraw: 0 | House: 0 | Food: 0 | Child: 0 | Family: 0 | Another: 0\n");
    printf("\n\t May-       | Deposit: 0 | Withdraw: 0 | House: 0 | Food: 0 | Child: 0 | Family: 0 | Another: 0\n");
    printf("\n\t June-      | Deposit: 0 | Withdraw: 0 | House: 0 | Food: 0 | Child: 0 | Family: 0 | Another: 0\n");
    printf("\n\t July-      | Deposit: 0 | Withdraw: 0 | House: 0 | Food: 0 | Child: 0 | Family: 0 | Another: 0\n");
    printf("\n\t August-    | Deposit: 0 | Withdraw: 0 | House: 0 | Food: 0 | Child: 0 | Family: 0 | Another: 0\n");
    printf("\n\t September- | Deposit: 0 | Withdraw: 0 | House: 0 | Food: 0 | Child: 0 | Family: 0 | Another: 0\n");
    printf("\n\t October-   | Deposit: 0 | Withdraw: 0 | House: 0 | Food: 0 | Child: 0 | Family: 0 | Another: 0\n");
    printf("\n\t November-  | Deposit: 0 | Withdraw: 0 | House: 0 | Food: 0 | Child: 0 | Family: 0 | Another: 0\n");
    printf("\n\t December-  | Deposit: 0 | Withdraw: 0 | House: 0 | Food: 0 | Child: 0 | Family: 0 | Another: 0\n");
    divider();
    printf("\n\t\t\t\t\tThe Yearly Report Of Account:\n\n");
    printf("\n\t 2023-      | Deposit: 0 | Withdraw: 0 | House: 0 | Food: 0 | Child: 0 | Family: 0 | Another: 0\n");
    printf("\n\t 2024-      | Deposit: 0 | Withdraw: 0 | House: 0 | Food: 0 | Child: 0 | Family: 0 | Another: 0\n");
    printf("\n\t 2025-      | Deposit: 0 | Withdraw: 0 | House: 0 | Food: 0 | Child: 0 | Family: 0 | Another: 0\n");
    printf("\n\t 2026-      | Deposit: 0 | Withdraw: 0 | House: 0 | Food: 0 | Child: 0 | Family: 0 | Another: 0\n");
    printf("\n\t 2027-      | Deposit: 0 | Withdraw: 0 | House: 0 | Food: 0 | Child: 0 | Family: 0 | Another: 0\n");
    printf("\n\t 2028-      | Deposit: 0 | Withdraw: 0 | House: 0 | Food: 0 | Child: 0 | Family: 0 | Another: 0\n");

}
// account details function
void account_details(struct user *accountUser){
    struct user new_user;
    FILE *fb = fopen("userAccount.txt", "w");
    printf("\n\t\t\t\t\t*Account Details*\n");
    divider();
    printf("\n\n\t\t\t\t\tName: %s\n", new_user.name);
    printf("\n\t\t\t\t\tAccount No.: %s\n", new_user.account_number);
    printf("\n\t\t\t\t\tPhone No.: %s\n", new_user.phone);
    printf("\n\t\t\t\t\tBalance: %d\n", new_user.balance);
    printf("\n\n\t\t\t\t\tPress any key to return to menu...");
    getch();
}
//account update function
void account_update (struct user *user){
struct user user_data;
    char filename[50], phone[50];
    FILE *fp;
    printf("\n\t\t\tEnter the phone number of the account to update: ");
    scanf("%s", phone);
    strcpy(filename, phone);
    strcat(filename, ".dat");
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("\n\t\t\tAccount not found.\n");
        getch();
        return;
    }
    fread(&user_data, sizeof(struct user), 1, fp);
    fclose(fp);
    int update_choice;
    printf("\n\t\t\t\t\t*Account Update*\n");
    divider();
    printf("\n\t\t\tWhat would you like to update?\n");
    printf("\n\t\t\t1. Account Name\n");
    printf("\n\t\t\t2. Phone Number\n");
    printf("\n\t\t\t3. Account Password\n");
    printf("\n\t\t\tEnter your choice: ");
    scanf("%d", &update_choice);
    switch (update_choice){
        case 1:
            printf("\n\t\t\tEnter new Account Name: ");
            scanf("%s", user_data.name);
            strcpy(user_data.account_number, user_data.name);
            printf("\n\t\t\tAccount Name updated.\n");
            break;
        case 2:
            printf("\n\t\t\tEnter new phone number: ");
            scanf("%s", user_data.phone);
            strcpy(user_data.account_number, user_data.phone);
            printf("\n\t\t\tPhone number updated.\n");
            break;
        case 3:
            printf("\n\t\t\tEnter new password: ");
            scanf("%s", user_data.password);
            printf("\n\t\t\tPassword updated.\n");
            break;
        default:
            printf("\n\t\t\tInvalid choice.\n");
            return;
    }
    remove(filename);
    strcpy(filename, user_data.phone);
    strcat(filename, ".dat");
    fp = fopen(filename, "w");
    if (fp != NULL) {
        fwrite(&user_data, sizeof(struct user), 1, fp);
        fclose(fp);
        printf("\n\t\t\tAccount updated successfully.\n");
    } else {
        printf("\n\t\t\tError updating account.\n");
    }
    getch();
}
//account delete function
void account_delete (struct user *user){
int delete;
    char phone[50];
    char filename[50];
    printf("\n\t\t\t\t\t*Account Delete*\n");
    divider();
    printf("\n\t\t\tEnter the phone number of the account to delete: ");
    scanf("%s", phone);
    strcpy(filename, phone);
    strcat(filename, ".dat");
    if (remove(filename) == 0) {
        printf("\n\t\t\tAccount deleted successfully.\n");
    } else {
        printf("\n\t\t\tError: Account not found or unable to delete.\n");
    }
    getch();
}
//total user account
void total_user_account(){
    system("cls");
    FILE *fp;
    struct user user_data;

    fp = fopen("users.dat", "r");
    if (fp == NULL)
    {
        printf("\n\t\t\t\t No users found.\n");
        getch();
        return;
    }
    printf("\n\n\n\n\t\t\t\t\t*** All Registered Users ***\n");
    divider();
    while (fread(&user_data, sizeof(struct user), 1, fp))
    {
        printf("\n\n\t\t\t\t Name: %s | Phone: %s | Balance: %d\n", user_data.name, user_data.phone, user_data.balance);
    }
    fclose(fp);
    getch();
}
//account search function
void search_account() {
    struct user user;
    char phone[50], filename[50];
    FILE *fp;
    printf("\n\t\t\t\t\t*Account Search*\n");
    divider();
    printf("\n\n\t\t\t\t\tEnter the phone number to search: ");
    scanf("%s", phone);
    strcpy(filename, phone);
    fp = fopen(strcat(filename, ".dat"), "r");
    if (fp == NULL) {
        printf("\n\t\t\t\t\tAccount not found\n");
        return;
    }
    fread(&user, sizeof(struct user), 1, fp);
    fclose(fp);
    printf("\n\t\t\t\t\tAccount found\n");
    printf("\n\t\t\t\t\tName: %s\n", user.name);
    printf("\n\t\t\t\t\tAccount No.: %s\n", user.account_number);
    printf("\n\t\t\t\t\tPhone No.: %s\n", user.phone);
    printf("\n\t\t\t\t\tBalance: %d\n", user.balance);
}
//date function
/*void current_date(char *date_str) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(date_str, 20, "%Y-%m-%d", tm_info);
}*/
