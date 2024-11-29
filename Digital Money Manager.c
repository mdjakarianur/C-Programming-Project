
/*
    Full System Code
    Project Title: Digital Money Manager
*/

// header file
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <conio.h>
    #include <time.h>


// user structure variable
struct user
{
    char name[50];
    char account_number[50];
    char phone[50];
    char password[50];
    int balance;
};

// pending deletion request structure variable
struct deletion_request
{
    char account_number[50];
    char phone[50];
};

//support ticket variable
struct support_request
{
    char name[50];
    char phone[50];
    char message[200];
    char date[20];
};

// transaction structure variable
struct transaction
{
    char type[10];
    int amount;
    char date[20];
};

// account repor structure variable
struct accountReport
{
    int deposit_january, deposit_february, deposit_march, deposit_april, deposit_may, deposit_june,
        deposit_july, deposit_august, deposit_september, deposit_october, deposit_november, deposit_december;

    int withdraw_january, withdraw_february, withdraw_march, withdraw_april, withdraw_may, withdraw_june,
        withdraw_july, withdraw_august, withdraw_september, withdraw_october, withdraw_november, withdraw_december;

    int house_january, house_february, house_march, house_april, house_may, house_june,
        house_july, house_august, house_september, house_october, house_november, house_december;

    int food_january, food_february, food_march, food_april, food_may, food_june,
        food_july, food_august, food_september, food_october, food_november, food_december;

    int child_january, child_february, child_march, child_april, child_may, child_june,
        child_july, child_august, child_september, child_october, child_november, child_december;

    int family_january, family_february, family_march, family_april, family_may, family_june,
        family_july, family_august, family_september, family_october, family_november, family_december;

    int another_january, another_february, another_march, another_april, another_may, another_june,
        another_july, another_august, another_september, another_october, another_november, another_december;


    int deposit_2024, deposit_2025, deposit_2026, deposit_2027, deposit_2028, deposit_2029, deposit_2030;

    int withdraw_2024, withdraw_2025, withdraw_2026, withdraw_2027, withdraw_2028, withdraw_2029, withdraw_2030;

    int house_2024, house_2025, house_2026, house_2027, house_2028, house_2029, house_2030;

    int food_2024, food_2025, food_2026, food_2027, food_2028, food_2029, food_2030;

    int child_2024, child_2025, child_2026, child_2027, child_2028, child_2029, child_2030;

    int family_2024, family_2025, family_2026, family_2027, family_2028, family_2029, family_2030;

    int another_2024, another_2025, another_2026, another_2027, another_2028, another_2029, another_2030;
};

// total user define function prototype

    void main_menu();       // home page

    void login_user();      // main menu 1
    void register_user();   // main menu 2
    void admin_login();     // main menu 3
    void user_support();    // main menu 4

    struct user deposit_money(struct user current_user);            // user menu 1
    struct user withdraw_money(struct user current_user);           // user menu 2
    void account_report(struct user current_user);                  // user menu 3
    void view_all_transactions(struct user current_user);           // user menu 4
    void account_details(struct user current_user);                 // user menu 5
    void submit_support_request(struct user current_user);          // user menu 6
    struct user update_account_details(struct user current_user);   // user menu 7
    void request_account_deletion(struct user current_user);        // user menu 8


    void admin_menu();                  // admin dashboard

    void view_support_requests();       // admin menu 1
    void approve_deletion_requests();   // admin menu 2
    void search_account();              // admin menu 3
    void view_all_users();              // admin menu 4

    struct user load_user_data(char phone[]);                                       // another menu 1
    void save_user_data(struct user current_user);                                  // another menu 2
    void save_deletion_request(struct deletion_request request);                    // another menu 3
    void save_report_data(struct user current_user, struct accountReport report);   // another menu 4
    struct accountReport get_report_data();                                         // another menu 5
    void record_transaction(struct user current_user, char type[], int amount);     // another menu 6


    void divider();         // divider menu
    void exit_program();    // exit menu


// main function
int main()
{
    system("color F1");
    main_menu();
    return 0;
}


// main menu
void main_menu()
{
    int choice;

    while (1)
    {
        system("cls");

        printf("\n\n\n\t\t\t\t\t\t*** Digital Money Manager ***\n");

        divider();

        printf("\n\t\t\t\t\t\t 1. Login to Account\n");
        printf("\n\t\t\t\t\t\t 2. Register Account\n");
        printf("\n\t\t\t\t\t\t 3. Admin Login\n");
        printf("\n\t\t\t\t\t\t 4. User Support\n");
        printf("\n\t\t\t\t\t\t 5. Exit\n");

        divider();

        printf("\n\t\t\t\t\t\t Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            login_user();
            break;
        case 2:
            register_user();
            break;
        case 3:
            admin_login();
            break;
        case 4:
            user_support();
            break;
        case 5:
            exit_program();
            return;
        default:
            printf("\n\t\t\t\t\t\t Invalid choice. Try again.\n");
            getch();
        }
    }
}


// Login user | main menu 1
void login_user()
{
    struct user current_user;
    char phone[50], password[50];

        system("cls");

            printf("\n\n\n\t\t\t\t\t\t *** Login to Account ***\n");

            divider();

            printf("\n\t\t\t\t\t\t Enter phone number:   ");
            scanf("%s", phone);

            printf("\n\t\t\t\t\t\t Enter your password:  ");
            scanf("%s", password);

            current_user = load_user_data(phone);

    if (strcmp(password, current_user.password) == 0)
    {
        int choice;

        while (1)
        {
            system("cls");
            printf("\n\n\n\t\t\t\t\t\t *** Welcome, %s ***\n", current_user.name);

            divider();

            printf("\n\t\t\t\t\t\t 1. Deposit Money\n");
            printf("\n\t\t\t\t\t\t 2. Withdraw Money\n");
            printf("\n\t\t\t\t\t\t 3. View Account Report\n");
            printf("\n\t\t\t\t\t\t 4. View Total Transactions\n");
            printf("\n\t\t\t\t\t\t 5. View Account Details\n");
            printf("\n\t\t\t\t\t\t 6. Submit Support Ticket\n");
            printf("\n\t\t\t\t\t\t 7. Update Account Details\n");
            printf("\n\t\t\t\t\t\t 8. Request Account Deletion\n");
            printf("\n\t\t\t\t\t\t 9. Logout\n");

            divider();

            printf("\n\t\t\t\t\t\t Enter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                current_user = deposit_money(current_user);
                break;
            case 2:
                current_user = withdraw_money(current_user);
                break;
            case 3:
                account_report(current_user);
                break;
            case 4:
                view_all_transactions(current_user);
                break;
            case 5:
                account_details(current_user);
                break;
            case 6:
                submit_support_request(current_user);
                break;
            case 7:
                current_user = update_account_details(current_user);
                break;
            case 8:
                request_account_deletion(current_user);
                break;
            case 9:
                save_user_data(current_user);
                return;
            default:
                printf("\n\n\t\t\t\t\t\t Invalid choice. Try again.\n");
                getch();
            }
        }
    }
    else
    {
            printf("\n\n\t\t\t\t\t\t Invalid password. Try again.\n");

            getch();
    }
}

// Register a new user | main menu 2
void register_user()
{
        struct user new_user;

        system("cls");

        printf("\n\n\n\t\t\t\t\t\t *** Register New Account ***\n");

        divider();

        printf("\n\t\t\t\t\t\t Enter your name:     ");
        scanf("%s", new_user.name);

        printf("\n\t\t\t\t\t\t Enter phone number:  ");
        scanf("%s", new_user.phone);

        printf("\n\t\t\t\t\t\t Enter new password:  ");
        scanf("%s", new_user.password);

        strcpy(new_user.account_number, new_user.phone); // Phone number as account number
        new_user.balance = 0;

        save_user_data(new_user);

        printf("\n\t\t\t\t\t\t Account successfully registered!\n");

        getch();
}

// Admin login | main menu 3
void admin_login()
{
        char username[50], password[50];

        system("cls");

        printf("\n\n\n\t\t\t\t\t\t *** Admin Login ***\n");

        divider();

        printf("\n\t\t\t\t\t\t Enter admin username: ");
        scanf("%s", username);

        printf("\n\t\t\t\t\t\t Enter admin password: ");
        scanf("%s", password);

    if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0)
        {
        admin_menu();
        }
    else
        {
        printf("\n\t\t\t\t\t\t Invalid Information\n");

        getch();
        }
}

//user support | main menu 4
void user_support()
{
            system("cls");

            printf("\n\n\n\t\t\t\t\t\t *** Welcome to User Support ***\n");

            divider();

            printf("\n\t\t\t\t\t\t Admin-1:\n");
            printf("\n\t\t\t\t\t\t Name  : Md Jakaria Nur \n\t\t\t\t\t\t Phone : 01837-000721\n");

            printf("\n\t\t\t\t\t\t Admin-2:\n");
            printf("\n\t\t\t\t\t\t Name  : Sami Ansari \n\t\t\t\t\t\t Phone : 01883-236707\n");

            printf("\n\t\t\t\t\t\t Admin-3:\n");
            printf("\n\t\t\t\t\t\t Name  : Monira Islam \n\t\t\t\t\t\t Phone : 01618-360986\n");

            divider();

            getch();
}


// Deposit money | user menu 1
struct user deposit_money(struct user current_user)
{
    int amount;
    struct accountReport report = get_report_data(current_user);

        char date_str[20];

        time_t t = time(NULL);
        struct tm *tm_info = localtime(&t);
        strftime(date_str, sizeof(date_str), "%Y-%m-%d", tm_info);
        int day, month, year;
        sscanf(date_str, "%d-%d-%d", &year, &month, &day);

        printf("\n\t\t\t\t\t\t Enter amount to deposit: ");
        scanf("%d", &amount);

    if (amount > 0)
        {
        current_user.balance += amount;

        printf("\n\t\t\t\t\t\t Deposit successful. \n\n\t\t\t\t\t\t New balance: %d\n", current_user.balance);

        save_user_data(current_user);
        record_transaction(current_user, "Deposit", amount);

        }
    else
        {
        printf("\n\t\t\t\t\t\t Invalid amount.\n");
        }

    if (year == 2024) {

            report.deposit_2024 += amount;

        if (month == 1) {
            report.deposit_january += amount;
        } else if (month == 2) {
            report.deposit_february += amount;
        } else if (month == 3) {
            report.deposit_march += amount;
        }else if (month == 4) {
            report.deposit_april += amount;
        }else if (month == 5) {
            report.deposit_may += amount;
        }else if (month == 6) {
            report.deposit_june += amount;
        }else if (month == 7) {
            report.deposit_july += amount;
        }else if (month == 8) {
            report.deposit_august += amount;
        }else if (month == 9) {
            report.deposit_september += amount;
        }else if (month == 10) {
            report.deposit_october += amount;
        }else if (month == 11) {
            report.deposit_november += amount;
        }else if (month == 12) {
            report.deposit_december += amount;
        }
    } else if (year == 2025) {
        report.deposit_2025 += amount;
    } else if (year == 2026) {
        report.deposit_2026 += amount;
    } else if (year == 2027) {
        report.deposit_2027 += amount;
    } else if (year == 2028) {
        report.deposit_2028 += amount;
    } else if (year == 2029) {
        report.deposit_2029 += amount;
    } else if (year == 2030) {
        report.deposit_2030 += amount;
    }

    save_report_data(current_user, report);

    getch();

    return current_user;
}

// Withdraw money | user menu 2
struct user withdraw_money(struct user current_user)
{
    int amount;
    int category;
    struct accountReport report = get_report_data(current_user);


    char date_str[20];

        time_t t = time(NULL);
        struct tm *tm_info = localtime(&t);
        strftime(date_str, sizeof(date_str), "%Y-%m-%d", tm_info);
        int day, month, year;
        sscanf(date_str, "%d-%d-%d", &year, &month, &day);

        printf("\n\t\t\t\t\t\t Enter amount to withdraw: ");
        scanf("%d", &amount);

    if (amount > current_user.balance)
    {
        printf("\n\t\t\t\t\t\t Insufficient balance.\n");
    }
    else
    {
        current_user.balance -= amount;
        printf("\n\t\t\t\t\t\t Withdrawal successful. \n\n\t\t\t\t\t\t Remaining balance: %d\n", current_user.balance);

    save_user_data(current_user);

    record_transaction(current_user, "Withdraw", amount);

    printf("\n\t\t\t\t\t\t *** Select the category to withdraw ***\n");

    divider();

    printf("\n\t\t\t\t\t\t 1. House\n");
    printf("\n\t\t\t\t\t\t 2. Food\n");
    printf("\n\t\t\t\t\t\t 3. Child\n");
    printf("\n\t\t\t\t\t\t 4. Family\n");
    printf("\n\t\t\t\t\t\t 5. Another\n");

    divider();

    scanf("%d", &category);
    printf("\n\t\t\t\t\t\t Enter your choice: ");

      switch (category)
    {
    case 1: {

        if (year == 2024) {

            report.withdraw_2024 += amount;
            report.house_2024 += amount;

        if (month == 1) {
            report.withdraw_january += amount;
            report.house_january += amount;
        } else if (month == 2) {
            report.withdraw_february += amount;
            report.house_february += amount;
        } else if (month == 3) {
            report.withdraw_march += amount;
            report.house_march += amount;
        }else if (month == 4) {
            report.withdraw_april += amount;
            report.house_april += amount;
        }else if (month == 5) {
            report.withdraw_may += amount;
            report.house_may += amount;
        }else if (month == 6) {
            report.withdraw_june += amount;
            report.house_june += amount;
        }else if (month == 7) {
            report.withdraw_july += amount;
            report.house_july += amount;
        }else if (month == 8) {
            report.withdraw_august += amount;
            report.house_august += amount;
        }else if (month == 9) {
            report.withdraw_september += amount;
            report.house_september += amount;
        }else if (month == 10) {
            report.withdraw_october += amount;
            report.house_october += amount;
        }else if (month == 11) {
            report.withdraw_november += amount;
            report.house_november += amount;
        }else if (month == 12) {
            report.withdraw_december += amount;
            report.house_december += amount;
        }
    } else if (year == 2025) {
        report.withdraw_2025 += amount;
        report.house_2025 += amount;
    } else if (year == 2026) {
        report.withdraw_2026 += amount;
        report.house_2026 += amount;
    } else if (year == 2027) {
        report.withdraw_2027 += amount;
        report.house_2027 += amount;
    } else if (year == 2028) {
        report.withdraw_2028 += amount;
        report.house_2028 += amount;
    } else if (year == 2029) {
        report.withdraw_2029 += amount;
        report.house_2029 += amount;
    } else if (year == 2030) {
        report.withdraw_2030 += amount;
        report.house_2030 += amount;
    }
    }
        break;

    case 2: {
        if (year == 2024) {

            report.withdraw_2024 += amount;
            report.food_2024 += amount;

        if (month == 1) {
            report.withdraw_january += amount;
            report.food_january += amount;
        } else if (month == 2) {
            report.withdraw_february += amount;
            report.food_february += amount;
        } else if (month == 3) {
            report.withdraw_march += amount;
            report.food_march += amount;
        }else if (month == 4) {
            report.withdraw_april += amount;
            report.food_april += amount;
        }else if (month == 5) {
            report.withdraw_may += amount;
            report.food_may += amount;
        }else if (month == 6) {
            report.withdraw_june += amount;
            report.food_june += amount;
        }else if (month == 7) {
            report.withdraw_july += amount;
            report.food_july += amount;
        }else if (month == 8) {
            report.withdraw_august += amount;
            report.food_august += amount;
        }else if (month == 9) {
            report.withdraw_september += amount;
            report.food_september += amount;
        }else if (month == 10) {
            report.withdraw_october += amount;
            report.food_october += amount;
        }else if (month == 11) {
            report.withdraw_november += amount;
            report.food_november += amount;
        }else if (month == 12) {
            report.withdraw_december += amount;
            report.food_december += amount;
        }
    } else if (year == 2025) {
        report.withdraw_2025 += amount;
        report.food_2025 += amount;
    } else if (year == 2026) {
        report.withdraw_2026 += amount;
        report.food_2026 += amount;
    } else if (year == 2027) {
        report.withdraw_2027 += amount;
        report.food_2027 += amount;
    } else if (year == 2028) {
        report.withdraw_2028 += amount;
        report.food_2028 += amount;
    } else if (year == 2029) {
        report.withdraw_2029 += amount;
        report.food_2029 += amount;
    } else if (year == 2030) {
        report.withdraw_2030 += amount;
        report.food_2030 += amount;
    }
  }
        break;

    case 3:
        {
        if (year == 2024) {

            report.withdraw_2024 += amount;
            report.child_2024 += amount;

        if (month == 1) {
            report.withdraw_january += amount;
            report.child_january += amount;
        } else if (month == 2) {
            report.withdraw_february += amount;
            report.child_february += amount;
        } else if (month == 3) {
            report.withdraw_march += amount;
            report.child_march += amount;
        }else if (month == 4) {
            report.withdraw_april += amount;
            report.child_april += amount;
        }else if (month == 5) {
            report.withdraw_may += amount;
            report.child_may = amount;
        }else if (month == 6) {
            report.withdraw_june += amount;
            report.child_june += amount;
        }else if (month == 7) {
            report.withdraw_july += amount;
            report.child_july += amount;
        }else if (month == 8) {
            report.withdraw_august += amount;
            report.child_august += amount;
        }else if (month == 9) {
            report.withdraw_september += amount;
            report.child_september += amount;
        }else if (month == 10) {
            report.withdraw_october += amount;
            report.child_october += amount;
        }else if (month == 11) {
            report.withdraw_november += amount;
            report.child_november += amount;
        }else if (month == 12) {
            report.withdraw_december += amount;
            report.child_december += amount;
        }
    } else if (year == 2025) {
        report.withdraw_2025 += amount;
        report.child_2025 += amount;
    } else if (year == 2026) {
        report.withdraw_2026 += amount;
        report.child_2026 += amount;
    } else if (year == 2027) {
        report.withdraw_2027 += amount;
        report.child_2027 += amount;
    } else if (year == 2028) {
        report.withdraw_2028 += amount;
        report.child_2028 += amount;
    } else if (year == 2029) {
        report.withdraw_2029 += amount;
        report.child_2029 += amount;
    } else if (year == 2030) {
        report.withdraw_2030 += amount;
        report.child_2030 += amount;
    }
  }
        break;
    case 4:
        {
        if (year == 2024) {

            report.withdraw_2024 += amount;
            report.family_2024 += amount;

        if (month == 1) {
            report.withdraw_january += amount;
            report.family_january += amount;
        } else if (month == 2) {
            report.withdraw_february += amount;
            report.family_february += amount;
        } else if (month == 3) {
            report.withdraw_march += amount;
            report.family_march += amount;
        }else if (month == 4) {
            report.withdraw_april += amount;
            report.family_april += amount;
        }else if (month == 5) {
            report.withdraw_may += amount;
            report.family_may += amount;
        }else if (month == 6) {
            report.withdraw_june += amount;
            report.family_june += amount;
        }else if (month == 7) {
            report.withdraw_july += amount;
            report.family_july += amount;
        }else if (month == 8) {
            report.withdraw_august += amount;
            report.family_august += amount;
        }else if (month == 9) {
            report.withdraw_september += amount;
            report.family_september += amount;
        }else if (month == 10) {
            report.withdraw_october += amount;
            report.family_october += amount;
        }else if (month == 11) {
            report.withdraw_november += amount;
            report.family_november += amount;
        }else if (month == 12) {
            report.withdraw_december += amount;
            report.family_december += amount;
        }
    } else if (year == 2025) {
        report.withdraw_2025 += amount;
        report.family_2025 += amount;
    } else if (year == 2026) {
        report.withdraw_2026 += amount;
        report.family_2026 += amount;
    } else if (year == 2027) {
        report.withdraw_2027 += amount;
        report.family_2027 += amount;
    } else if (year == 2028) {
        report.withdraw_2028 += amount;
        report.family_2028 += amount;
    } else if (year == 2029) {
        report.withdraw_2029 += amount;
        report.family_2029 += amount;
    } else if (year == 2030) {
        report.withdraw_2030 += amount;
        report.family_2030 += amount;
    }
  }
        break;
    case 5:
        {
        if (year == 2024) {

            report.withdraw_2024 += amount;
            report.another_2024 += amount;

        if (month == 1) {
            report.withdraw_january += amount;
            report.another_january += amount;
        } else if (month == 2) {
            report.withdraw_february += amount;
            report.another_february += amount;
        } else if (month == 3) {
            report.withdraw_march += amount;
            report.another_march += amount;
        }else if (month == 4) {
            report.withdraw_april += amount;
            report.another_april += amount;
        }else if (month == 5) {
            report.withdraw_may += amount;
            report.another_may += amount;
        }else if (month == 6) {
            report.withdraw_june += amount;
            report.another_june += amount;
        }else if (month == 7) {
            report.withdraw_july += amount;
            report.another_july += amount;
        }else if (month == 8) {
            report.withdraw_august += amount;
            report.another_august += amount;
        }else if (month == 9) {
            report.withdraw_september += amount;
            report.another_september += amount;
        }else if (month == 10) {
            report.withdraw_october += amount;
            report.another_october += amount;
        }else if (month == 11) {
            report.withdraw_november += amount;
            report.another_november += amount;
        }else if (month == 12) {
            report.withdraw_december += amount;
            report.another_december += amount;
        }
    } else if (year == 2025) {
        report.withdraw_2025 += amount;
        report.another_2025 += amount;
    } else if (year == 2026) {
        report.withdraw_2026 += amount;
        report.another_2026 += amount;
    } else if (year == 2027) {
        report.withdraw_2027 += amount;
        report.another_2027 += amount;
    } else if (year == 2028) {
        report.withdraw_2028 += amount;
        report.another_2028 += amount;
    } else if (year == 2029) {
        report.withdraw_2029 += amount;
        report.another_2029 += amount;
    } else if (year == 2030) {
        report.withdraw_2030 += amount;
        report.another_2030 += amount;
    }
  }
        break;

    default:
        printf("\n\t\t\t\t\t\t Invalid choice! Please try again.\n");
        break;
    }

    save_report_data(current_user, report);

    }
    getch();
    return current_user;
}

// View account report | user menu 3
void account_report(struct user current_user)
{
    struct accountReport report = get_report_data(current_user);

        system("cls");

        printf("\n\n\n\t\t\t\t\t\t\t\t  *** Account Report ***\n");

        printf("\n\n\t\t-----------------------------------------------------------------------------------------------------------------------------------\n\n");


        printf("\n\t\t\t\t\t\t\t    ***The Months Report Of Running Year***\n\n");

        printf("\n\t\t 01. January-   | Deposit: %-6d | Withdraw: %-6d | House: %-6d | Food: %-6d | Child: %-6d | Family: %-6d | Another: %-6d\n",
          report.deposit_january, report.withdraw_january, report.house_january, report.food_january,
          report.child_january, report.family_january, report.another_january);

        printf("\n\t\t 02. February-  | Deposit: %-6d | Withdraw: %-6d | House: %-6d | Food: %-6d | Child: %-6d | Family: %-6d | Another: %-6d\n",
           report.deposit_february, report.withdraw_february, report.house_february, report.food_february,
           report.child_february, report.family_february, report.another_february);

        printf("\n\t\t 03. March-     | Deposit: %-6d | Withdraw: %-6d | House: %-6d | Food: %-6d | Child: %-6d | Family: %-6d | Another: %-6d\n",
           report.deposit_march, report.withdraw_march, report.house_march, report.food_march,
           report.child_march, report.family_march, report.another_march);

        printf("\n\t\t 04. April-     | Deposit: %-6d | Withdraw: %-6d | House: %-6d | Food: %-6d | Child: %-6d | Family: %-6d | Another: %-6d\n",
           report.deposit_april, report.withdraw_april, report.house_april, report.food_april,
           report.child_april, report.family_april, report.another_april);

        printf("\n\t\t 05. May-       | Deposit: %-6d | Withdraw: %-6d | House: %-6d | Food: %-6d | Child: %-6d | Family: %-6d | Another: %-6d\n",
           report.deposit_may, report.withdraw_may, report.house_may, report.food_may,
           report.child_may, report.family_may, report.another_may);

        printf("\n\t\t 06. June-      | Deposit: %-6d | Withdraw: %-6d | House: %-6d | Food: %-6d | Child: %-6d | Family: %-6d | Another: %-6d\n",
           report.deposit_june, report.withdraw_june, report.house_june, report.food_june,
           report.child_june, report.family_june, report.another_june);

        printf("\n\t\t 07. July-      | Deposit: %-6d | Withdraw: %-6d | House: %-6d | Food: %-6d | Child: %-6d | Family: %-6d | Another: %-6d\n",
           report.deposit_july, report.withdraw_july, report.house_july, report.food_july,
           report.child_july, report.family_july, report.another_july);

        printf("\n\t\t 08. August-    | Deposit: %-6d | Withdraw: %-6d | House: %-6d | Food: %-6d | Child: %-6d | Family: %-6d | Another: %-6d\n",
           report.deposit_august, report.withdraw_august, report.house_august, report.food_august,
           report.child_august, report.family_august, report.another_august);

        printf("\n\t\t 09. September- | Deposit: %-6d | Withdraw: %-6d | House: %-6d | Food: %-6d | Child: %-6d | Family: %-6d | Another: %-6d\n",
           report.deposit_september, report.withdraw_september, report.house_september, report.food_september,
           report.child_september, report.family_september, report.another_september);

        printf("\n\t\t 10. October-   | Deposit: %-6d | Withdraw: %-6d | House: %-6d | Food: %-6d | Child: %-6d | Family: %-6d | Another: %-6d\n",
           report.deposit_october, report.withdraw_october, report.house_october, report.food_october,
           report.child_october, report.family_october, report.another_october);

        printf("\n\t\t 11. November-  | Deposit: %-6d | Withdraw: %-6d | House: %-6d | Food: %-6d | Child: %-6d | Family: %-6d | Another: %-6d\n",
           report.deposit_november, report.withdraw_november, report.house_november, report.food_november,
           report.child_november, report.family_november, report.another_november);

        printf("\n\t\t 12. December-  | Deposit: %-6d | Withdraw: %-6d | House: %-6d | Food: %-6d | Child: %-6d | Family: %-6d | Another: %-6d\n",
           report.deposit_december, report.withdraw_december, report.house_december, report.food_december,
           report.child_december, report.family_december, report.another_december);

        printf("\n\n\t\t-----------------------------------------------------------------------------------------------------------------------------------\n\n");

        printf("\n\t\t\t\t\t\t\t      ***The Yearly Report Of Account***\n\n");

        printf("\n\t\t 01. 2024-      | Deposit: %-6d | Withdraw: %-6d | House: %-6d | Food: %-6d | Child: %-6d | Family: %-6d | Another: %-6d\n",
           report.deposit_2024, report.withdraw_2024, report.house_2024, report.food_2024,
           report.child_2024, report.family_2024, report.another_2024);

        printf("\n\t\t 02. 2025-      | Deposit: %-6d | Withdraw: %-6d | House: %-6d | Food: %-6d | Child: %-6d | Family: %-6d | Another: %-6d\n",
           report.deposit_2025, report.withdraw_2025, report.house_2025, report.food_2025,
           report.child_2025, report.family_2025, report.another_2025);

        printf("\n\t\t 03. 2026-      | Deposit: %-6d | Withdraw: %-6d | House: %-6d | Food: %-6d | Child: %-6d | Family: %-6d | Another: %-6d\n",
           report.deposit_2026, report.withdraw_2026, report.house_2026, report.food_2026,
           report.child_2026, report.family_2026, report.another_2026);

        printf("\n\t\t 04. 2027-      | Deposit: %-6d | Withdraw: %-6d | House: %-6d | Food: %-6d | Child: %-6d | Family: %-6d | Another: %-6d\n",
           report.deposit_2027, report.withdraw_2027, report.house_2027, report.food_2027,
           report.child_2027, report.family_2027, report.another_2027);

        printf("\n\t\t 05. 2028-      | Deposit: %-6d | Withdraw: %-6d | House: %-6d | Food: %-6d | Child: %-6d | Family: %-6d | Another: %-6d\n",
           report.deposit_2028, report.withdraw_2028, report.house_2028, report.food_2028,
           report.child_2028, report.family_2028, report.another_2028);

        printf("\n\t\t 06. 2029-      | Deposit: %-6d | Withdraw: %-6d | House: %-6d | Food: %-6d | Child: %-6d | Family: %-6d | Another: %-6d\n",
           report.deposit_2029, report.withdraw_2029, report.house_2029, report.food_2029,
           report.child_2027, report.family_2027, report.another_2027);

        printf("\n\t\t 07. 2030-      | Deposit: %-6d | Withdraw: %-6d | House: %-6d | Food: %-6d | Child: %-6d | Family: %-6d | Another: %-6d\n",
           report.deposit_2030, report.withdraw_2030, report.house_2030, report.food_2030,
           report.child_2030, report.family_2030, report.another_2030);

        printf("\n\n\t\t-----------------------------------------------------------------------------------------------------------------------------------\n\n");


    getch();
}

// View all transaction | user menu 4
void view_all_transactions(struct user current_user)
{
    char filename[50];
    strcpy(filename, current_user.phone);
    strcat(filename, "_transactions.dat");

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("\n\t\t\t\t\t\t No transaction history found.\n");
        getch();
        return;
    }

    struct transaction record;

    system("cls");

        printf("\n\t\t\t\t\t\t *** All Transactions for %s ***\n", current_user.name);

        divider();

    int tran_no=0;

    while (fread(&record, sizeof(struct transaction), 1, fp))
    {
        tran_no++;
        printf("\n\t\t\t\t\t\t %3d. Date: %-10s | Type: %-10s | Amount: %-6d\n", tran_no, record.date, record.type, record.amount);
    }

    fclose(fp);
    getch();
}


// View account details | user menu 5
void account_details(struct user current_user)
{
    system("cls");

    printf("\n\n\n\t\t\t\t\t\t *** Account Details ***\n");

    divider();

    printf("\n\t\t\t\t\t\t Name: %s\n", current_user.name);
    printf("\n\t\t\t\t\t\t Phone: %s\n", current_user.phone);
    printf("\n\t\t\t\t\t\t Balance: %d\n", current_user.balance);

    divider();

    getch();
}

//user support request | user menu 6
void submit_support_request(struct user current_user)
{
    struct support_request request;

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(request.date, sizeof(request.date), "%Y-%m-%d", tm);

    strcpy(request.name, current_user.name);
    strcpy(request.phone, current_user.phone);

    system("cls");

    printf("\n\n\n\t\t\t\t\t\t *** Submit Support Request ***\n");

    printf("\n\t\t\t\t\t\t Date      : %s\n", request.date);
    printf("\n\t\t\t\t\t\t Name      : %s\n", request.name);
    printf("\n\t\t\t\t\t\t Phone     : %s\n", request.phone);

    printf("\n\t\t\t\t\t\t Enter your message (max 200 characters): ");

    getchar();

    fgets(request.message, sizeof(request.message), stdin);

    size_t len = strlen(request.message);
    if (len > 0 && request.message[len - 1] == '\n')
        request.message[len - 1] = '\0';

    FILE *fp = fopen("support_requests.dat", "a");

    if (fp != NULL)
    {
        fwrite(&request, sizeof(struct support_request), 1, fp);
        fclose(fp);

        printf("\n\t\t\t\t\t\t Your support request has been submitted successfully.\n");
    }
    else
    {
        printf("\n\t\t\t\t\t\t Error: Unable to submit your request. Please try again later.\n");
    }

    getch();
}

// Update account details | user menu 7
struct user update_account_details(struct user current_user)
{
    int update_choice;

    printf("\n\t\t\t\t\t\t 1. Update Account Name\n");
    printf("\n\t\t\t\t\t\t 2. Update Phone Number\n");
    printf("\n\t\t\t\t\t\t 3. Update Account Password\n");

    printf("\n\t\t\t\t\t\t Which one do you want to update: ");
    scanf("%d", &update_choice);

    switch (update_choice)
    {
    case 1:
        printf("\n\t\t\t\t\t\t Enter new name: ");
        scanf("%s", current_user.name);
        break;

    case 2:
        printf("\n\t\t\t\t\t\t Enter new phone number: ");
        scanf("%s", current_user.phone);
        break;

    case 3:
        printf("\n\t\t\t\t\t\t Enter new password: ");
        scanf("%s", current_user.password);
        break;

    default:
        printf("\n\t\t\t\t\t\t Invalid choice! Please try again.\n");
        break;
    }

    if (update_choice >= 1 && update_choice <= 3)
    {
        printf("\n\t\t\t\t\t\t Account details updated successfully.\n");

        save_user_data(current_user);
    }

    getch();
    return current_user;
}

// Request account deletion | user menu 8
void request_account_deletion(struct user current_user)
{
    char choice;

        printf("\n\t\t\t\t\t\t If you surely want to delete you account type (y/n): ");

        scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y')
        {

        struct deletion_request request;

        strcpy(request.account_number, current_user.name);
        strcpy(request.phone, current_user.phone);

        save_deletion_request(request);

        printf("\n\t\t\t\t\t\t Account deletion request is submitted.\n");

        }
    else
        {
        printf("\n\t\t\t\t\t\t Account deletion request is not submitted.\n");
        }


    getch();
}


// Admin menu
void admin_menu()
{
    int choice;

    while (1)
    {
        system("cls");

        printf("\n\n\n\t\t\t\t\t\t *** Admin Dashboard ***\n");

        divider();

        printf("\n\t\t\t\t\t\t 1. View Support Ticket\n");
        printf("\n\t\t\t\t\t\t 2. Approve Account Deletion Request\n");
        printf("\n\t\t\t\t\t\t 3. Search Registered User Account\n");
        printf("\n\t\t\t\t\t\t 4. View Total Registered User Information\n");
        printf("\n\t\t\t\t\t\t 5. Logout\n");

        divider();

        printf("\n\t\t\t\t\t\t Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            view_support_requests();
            break;
        case 2:
            approve_deletion_requests();
            break;
        case 3:
            search_account();
            break;
        case 4:
            view_all_users();
            break;
        case 5:
            return;
        default:
            printf("\n\t\t\t\t\t\t Invalid choice. Try again.\n");
            getch();
        }
    }
}


// view Support Ticket | admin menu 1
void view_support_requests()
{
    FILE *fp = fopen("support_requests.dat", "r");
    struct support_request request;

    if (fp == NULL)
    {
        printf("\n\t\t\t\t\t\t No support requests found.\n");

        getch();

        return;
    }

    printf("\n\t\t\t\t\t\t *** User Support Requests ***\n");

    divider();

    while (fread(&request, sizeof(struct support_request), 1, fp))
    {
        printf("\n\t\t\t\t\t\t Date      : %s\n", request.date);
        printf("\n\t\t\t\t\t\t Name      : %s\n", request.name);
        printf("\n\t\t\t\t\t\t Phone     : %s\n", request.phone);
        printf("\n\t\t\t\t\t\t Message   : %s\n", request.message);

        divider();
    }

    fclose(fp);

    getch();
}

// Approve deletion requests | admin menu 2
void approve_deletion_requests()
{
    FILE *fp = fopen("pending_requests.dat", "r");
    FILE *temp_fp = fopen("temp_pending_requests.dat", "w");

    struct deletion_request request;

    if (fp == NULL)
    {
        printf("\n\t\t\t\t\t\t No deletion requests found.\n");

        getch();

        return;
    }

    if (temp_fp == NULL)
    {
        fclose(fp);

        printf("\n\t\t\t\t\t\t Error processing requests.\n");

        getch();

        return;
    }

    while (fread(&request, sizeof(struct deletion_request), 1, fp))
    {
        printf("\n\t\t\t\t\t\t Approve deletion for Account Name: %s | Phone: %s? (y/n): ", request.account_number, request.phone);

        char choice;
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y')
        {
            char user_file[50];
            strcpy(user_file, request.phone);
            strcat(user_file, ".dat");

          if (remove(user_file) == 0)
            {
                printf("\n\t\t\t\t\t\t Account with phone %s deleted successfully.\n", request.phone);
            }
        }
        else
        {
            fwrite(&request, sizeof(struct deletion_request), 1, temp_fp);
        }
    }

    fclose(fp);
    fclose(temp_fp);

    remove("pending_requests.dat");
    rename("temp_pending_requests.dat", "pending_requests.dat");

    printf("\n\t\t\t\t\t\t All deletion requests processed.\n");

    getch();
}

// Search user account | admin menu 3
void search_account() {

    struct user user;
    char phone[50], filename[50];
    FILE *fp;

    system("cls");

        printf("\n\n\n\t\t\t\t\t\t *User Account Search*\n");

        divider();

        printf("\n\t\t\t\t\t\t Enter the phone number to search: ");
        scanf("%s", phone);

        divider();

    strcpy(filename, phone);
    fp = fopen(strcat(filename, ".dat"), "r");

    if (fp == NULL) {

        printf("\n\t\t\t\t\t *** Account not found ***\n");

        getch();

        return;
    }

    fread(&user, sizeof(struct user), 1, fp);
    fclose(fp);

        printf("\n\t\t\t\t\t\t *** Account Found ***\n");
        printf("\n\t\t\t\t\t\t Name     : %s\n", user.name);
        printf("\n\t\t\t\t\t\t Phone    : %s\n", user.phone);
        printf("\n\t\t\t\t\t\t Balance  : %d\n", user.balance);
        printf("\n\t\t\t\t\t\t Password : %s\n", user.password);

        divider();

    getch();
}

// View all users | admin menu 4
void view_all_users()
{
    FILE *fp;
    struct user user_data;

    fp = fopen("users.dat", "rb");
    if (fp == NULL)
    {
        printf("\n\t\t\t\t\t\t *** No users found ***\n");
        getch();
        return;
    }

    system("cls");

        printf("\n\t\t\t\t\t\t *** All Registered Users ***\n");

    divider();

    int userno=0;

    while (fread(&user_data, sizeof(struct user), 1, fp))
    {
        userno++;
        printf("\n\t\t %d. Name: %-10s | Phone: %-10s | Password: %-8s | Balance: %-6d\n", userno, user_data.name, user_data.phone, user_data.password, user_data.balance);
    }

    fclose(fp);

    getch();
}

// Load user data | another menu 1
struct user load_user_data(char phone[])
{
    struct user current_user = {0};
    char filename[50];

    strcpy(filename, phone);
    strcat(filename, ".dat");

    FILE *fp = fopen(filename, "r");

    if (fp != NULL)
    {
        fread(&current_user, sizeof(struct user), 1, fp);
        fclose(fp);
    }
    else
    {
        printf("\n\n\t\t\t\t\t\t Error: The phone number is not registered.\n");

        getch();
    }

    return current_user;
}

// Save user data | another menu 2
void save_user_data(struct user current_user)
{
    char filename[50];
    strcpy(filename, current_user.phone);
    strcat(filename, ".dat");

    FILE *fp = fopen(filename, "w");
    if (fp != NULL)
    {
        fwrite(&current_user, sizeof(struct user), 1, fp);
        fclose(fp);
    }
    else
    {
        printf("\n\t\t\t\t\t\t Error: Failed to save user data to file.\n");
    }

    FILE *users_fp = fopen("users.dat", "r");
    FILE *temp_fp = fopen("temp_users.dat", "w");

    struct user temp_user;

    int found = 0;

    if (users_fp != NULL && temp_fp != NULL)
    {
        while (fread(&temp_user, sizeof(struct user), 1, users_fp))
        {
            if (strcmp(temp_user.phone, current_user.phone) == 0)
            {
                fwrite(&current_user, sizeof(struct user), 1, temp_fp);
                found = 1;
            }
            else
            {
                fwrite(&temp_user, sizeof(struct user), 1, temp_fp);
            }
        }

        fclose(users_fp);
    }

    if (!found && temp_fp != NULL)
    {
        fwrite(&current_user, sizeof(struct user), 1, temp_fp);
    }

    fclose(temp_fp);
    remove("users.dat");
    rename("temp_users.dat", "users.dat");
}

// save deletion request | another menu 3
void save_deletion_request(struct deletion_request request)
{
    FILE *fp = fopen("pending_requests.dat", "a");

    if (fp != NULL)
    {
        fwrite(&request, sizeof(struct deletion_request), 1, fp);
        fclose(fp);
    }
}

// Save the account report to a file | another menu 4
void save_report_data(struct user current_user, struct accountReport report)
{
    char filename[100];
    snprintf(filename, sizeof(filename), "account_report_%s.dat", current_user.account_number);

    FILE *file = fopen(filename, "w");

    if (file == NULL) {

        perror("\n\t\t\t\t\t\t Error opening file to save report");
        exit(1);
    }

    size_t written = fwrite(&report, sizeof(struct accountReport), 1, file);
    if (written != 1) {

        perror("\n\t\t\t\t\t\t Error writing report to file");
    }

    fclose(file);
}

// Function to read account data from a file | another menu 5
struct accountReport get_report_data(struct user current_user)
{
    struct accountReport report;
    char filename[100];

    snprintf(filename, sizeof(filename), "account_report_%s.dat", current_user.account_number);

    FILE *file = fopen(filename, "r");

    if (file == NULL) {

        printf("\n\t\t\t\t\t\t No existing report found for %s. Initializing a new report...\n", current_user.account_number);

        memset(&report, 0, sizeof(report));

    } else {

        fread(&report, sizeof(struct accountReport), 1, file);

        fclose(file);
    }

    return report;
}

// Record a transaction | another menu 6
void record_transaction(struct user current_user, char type[], int amount)
{
    char filename[50];
    strcpy(filename, current_user.phone);
    strcat(filename, "_transactions.dat");

    FILE *fp = fopen(filename, "a");
    if (fp != NULL)
    {
        struct transaction new_transaction;
        strcpy(new_transaction.type, type);
        new_transaction.amount = amount;

        time_t t = time(NULL);
        struct tm *tm = localtime(&t);
        strftime(new_transaction.date, sizeof(new_transaction.date), "%Y-%m-%d", tm);

        fwrite(&new_transaction, sizeof(struct transaction), 1, fp);
        fclose(fp);
    }
}


// Divider function
void divider()
{
    printf("\n\t\t-----------------------------------------------------------------------------------------\n");
}

// Exit program
void exit_program()
{
    printf("\n\t\t\t\t\t\t Thank you for using Digital Money Management System. Goodbye!\n");
    getch();
}

/*

Digital Money Manager Project by

01. Name: Md Jakaria Nur | ID: 232-35-252
02. Name: Sami Ansari    | ID: 232-35-176
03. Monira Islam         | ID: 232-35-015

*/

// The System Code End
