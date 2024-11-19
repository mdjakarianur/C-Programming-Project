/*
Full System Code
Project Title: Digital Money Management
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

struct user {
    char phone[50];
    char password[50];
    char name[50];
    char account_number[50];
    int balance;
};

int balance=0;

void register_user();
void login_user();
void search_account();
void deposit_money();
void withdraw_money();
void account_details();
void account_update();
void account_delete();
void exit_program();
void divider();

int main() {
    system("color F1");
    int option;
    system("cls");

    while (1) {
        printf("\n\n\n\n\t\t\t\t\t*Dynamic Banking System*\t\t\t\t\t");
        printf("\n\n\n\t\t\t\t 1. Login Account\t\t\t\t");
        printf("\n\n\n\t\t\t\t 2. Register Account\t\t\t\t");
        printf("\n\n\n\t\t\t\t 3. Search Account\t\t\t\t");
        printf("\n\n\n\t\t\t\t 4. Exit From System\t\t\t\t");
        printf("\n\n\n\t\t\t\t Enter Your Choice: ");
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
                search_account();
                break;
            case 4:
                exit_program();
                return 0;
            default:
                printf("\n\t\t\t\t\t*Invalid choice, Try Again!*");
                break;
        }
    }
    return 0;
}

void register_user(){
    struct user new_user;
    char filename[50];
    FILE *fp;

    printf("\n\t\t\t\t\tEnter your name:\t");
    scanf("%s", new_user.name);
    printf("\n\t\t\t\t\tEnter your phone number:\t");
    scanf("%s", new_user.phone);
    printf("\n\t\t\t\t\tEnter your phone number again:\t");
    scanf("%s", new_user.account_number);
    printf("\n\t\t\t\t\tEnter your new password:\t");
    scanf("%s", new_user.password);
    new_user.balance = 0;

    strcpy(filename, new_user.phone);
    fp = fopen(strcat(filename, ".dat"),"w");
    fwrite(&new_user, sizeof(new_user),1, fp);
    fclose(fp);

    printf("\n\t\t\t\t\tSuccessfully registered\n\n");
}

void login_user() {
    struct user bankingUser;
    char filename[50], phone[50], password[50];
    FILE *fp;
    int choice;
    char cont = 'y';

    printf("\n\n\t\t\t\t\tPhone No:\t");
    scanf("%s", phone);
    printf("\n\t\t\t\t\tPassword:\t");
    scanf("%s", password);

    strcpy(filename, phone);
    fp = fopen(strcat(filename, ".dat"), "r");

    if (fp == NULL) {
        printf("\n\t\t\t\t\tPhone number not registered\n");
        return;
    }

    fread(&bankingUser, sizeof(struct user), 1, fp);
    fclose(fp);

    if (strcmp(password, bankingUser.password) != 0) {
        printf("\n\t\t\t\t\tInvalid password\n");
        return;
    }

    while (cont == 'y') {
        system("cls");
        printf("\n\t\t\t\t\tBanking MENU\n");
        divider();
        printf("\n\t\t\t\t\t1. Deposit Money\n");
        printf("\n\t\t\t\t\t2. Withdraw Money\n");
        printf("\n\t\t\t\t\t3. Account details\n");
        printf("\n\t\t\t\t\t4. Account Update\n");
        printf("\n\t\t\t\t\t5. Account Delete\n");
        printf("\n\t\t\t\t\t6. Logout\n");

        printf("\n\n\t\t\t\t\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deposit_money(&bankingUser);
                break;
            case 2:
                withdraw_money(&bankingUser);
                break;
            case 3:
                account_details(&bankingUser);
                break;
            case 4:
                account_update(&bankingUser);
                break;
            case 5:
                account_delete(&bankingUser);
                break;
            case 6:
                return;
            default:
                printf("\n\t\t\t\t\t*Invalid choice, Try Again!*");
                break;
        }
        printf("\n\n\t\t\t\t\tDo you want to continue? [y/n]: ");
        scanf(" %c", &cont);
    }
}

void deposit_money(struct user *bankingUser) {
    int diposit_amount;
    FILE *fb = fopen("userAccount.txt", "w");
    printf("\n\t\t\t\t\t*DEPOSITING MONEY*\n");
    divider();
    printf("\n\n\t\t\t\t\tEnter the amount you want to deposit:");
    scanf("%d", &diposit_amount);
    balance += diposit_amount;
    printf("\n\t\t\t\t\t**Money Deposited\n");
    printf("\n\t\t\t\t\tNow balance : %d\n", balance);
    fprintf(fb, "\n\n\t\t\t\t\tTk%d had been deposited to your account \n", diposit_amount);
    fclose(fb);
    printf("\n\t\t\t\t\tPress any key....\n");
    getch();
}

void withdraw_money(struct user *bankingUser) {
    int withdraw_amount;
    FILE *fb = fopen("userAccount.txt", "w");
    printf("\n\t\t\t\t\t*DEPOSITING MONEY*\n");
    divider();
    printf("\n\n\t\t\t\t\tEnter the amount you want to deposit:");
    scanf("%d", &withdraw_amount);
    balance -= withdraw_amount;
    printf("\n\t\t\t\t\t**Money Deposited\n");
    printf("\n\t\t\t\t\tNow balance : %d\n", balance);
    fprintf(fb, "\n\n\t\t\t\t\tTk%d had been deposited to your account \n", withdraw_amount);
    fclose(fb);
    printf("\n\t\t\t\t\tPress any key....\n");
    getch();
}

void account_details(struct user *user){
    printf("\n\t\t\t\t\tACCOUNT DETAILS\n");
    divider();
    printf("\n\n\t\t\t\t\tName: %s\n", user->name);
    printf("\n\t\t\t\t\tAccount No.: %s\n", user->account_number);
    printf("\n\t\t\t\t\tPhone No.: %s\n", user->phone);
    printf("\n\t\t\t\t\tBalance: %d\n", user->balance);
    printf("\n\n\t\t\t\t\tPress any key to return to menu...");
    getch();
}

void account_update (struct user *user){
struct user user_data;
    char filename[50], phone[50];
    FILE *fp;

    printf("\n\t\t\tEnter the phone number of the account to update: ");
    scanf("%s", phone);

    strcpy(filename, phone);
    strcat(filename, ".dat");

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("\n\t\t\tAccount not found.\n");
        getch();
        return;
    }

    fread(&user_data, sizeof(struct user), 1, fp);
    fclose(fp);

    int choice;
    printf("\n\t\t\tWhat would you like to update?\n");
    printf("\n\t\t\t1. Account Name\n");
    printf("\n\t\t\t2. Phone Number\n");
    printf("\n\t\t\t3. Account Password\n");
    printf("\n\t\t\tEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
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

    remove(filename); // Delete old file
    strcpy(filename, user_data.phone);
    strcat(filename, ".dat");

    fp = fopen(filename, "wb");
    if (fp != NULL) {
        fwrite(&user_data, sizeof(struct user), 1, fp);
        fclose(fp);
        printf("\n\t\t\tAccount updated successfully.\n");
    } else {
        printf("\n\t\t\tError updating account.\n");
    }

    getch();
}

void account_delete (struct user *user){
int delete;
     char phone[50];
    char filename[50];

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

void search_account() {
    struct user user;
    char phone[50], filename[50];
    FILE *fp;

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

void exit_program() {
    printf("\n\n\n\t\t\t\t\tThanks for using Dynamic Banking System\n\n");
}
void divider() {
    printf("\n\t\t\t\t\t");
    for (int i = 0; i < 50; i++) {
        printf("-");
    }
}
