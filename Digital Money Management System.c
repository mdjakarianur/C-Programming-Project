/*Full System Code
Digital Money Management System. Code & Output Step by Step
Project Title: Digital Money Management*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <conio.h>
struct user {
char phone[50];
char password[50];
};
char name[20];
char ac[50];
int dip_amt, amt = 10000, phone, count = 0,acc;
int with_amt,cc,ch;
void deposit_money();
void withdraw_money();
void AccountDetails();

void ExitProgram();
void divider()
{
 printf("\n\t\t\t\t\t");
 for (int i = 0; i < 50; i++)
 {
 printf("-");
 }
}
int main(){
system("color A0");
struct user user;
char filename[50],phone[50],password[50],phone2[50];
FILE *fp;
int opt,choice;
int amount,acc;
char cont = 'y';
 system("cls");
jump:
printf("\n\n\n\n\t\t\t\t\t*Digital Money Management*\t\t\t\t\t");
printf("\n\n\n\t\t\t\t 1.Register your account\t\t\t\t");
printf("\n\n\n\t\t\t\t 2.Login to your account\t\t\t\t");
printf("\n\n\n\t\t\t\t Please enter your choice: ");
scanf("\n\t\t\t\t\t%d",&opt);
system("cls");
if(opt == 1){
system("cls");
printf("\n\t\t\t\t\tEnter your name:\t");
scanf("\n\t\t\t\t\t%s",name);
printf("\n\t\t\t\t\tEnter your account number:\t");
scanf("\n\t\t\t\t\t%s",ac);
printf("\n\t\t\t\t\tEnter your phone number:\t");
scanf("\n\t\t\t\t\t%s",user.phone);
printf("\n\t\t\t\t\tEnter your new password:\t");
scanf("\n\t\t\t\t\t%s",user.password);
stpcpy(filename,user.phone);
fp=fopen(strcat(filename,".dat"),"w");
fwrite(&user,sizeof(user),1,fp);
if(fwrite != 0){
printf("\n\t\t\t\t\tSuccesfully registered\n\n\n");
getch();
system("cls");
goto jump;
}
}
else if(opt == 2){
system("cls");
printf("\n\n\t\t\t\t\tPhone No.:\t");
scanf("\n\t\t\t\t\t%s",phone);
printf("\n\t\t\t\t\tPassword:\t");
scanf("\n\t\t\t\t\t%s",password);
fp = fopen(strcat(phone,".dat"),"r");
if(fp == NULL) printf("Phone number not registered");
else {
fread(&user,sizeof(struct user),1,fp);
fclose(fp);
if(!strcmp(password,user.password))
 {
while(cont == 'y'){
system("cls");
 printf("\n\t\t\t\t\tMENU\n");
 divider();
 printf("\n\t\t\t\t\t1.Deposit Money\n");
 printf("\n\t\t\t\t\t2.Withdraw Money\n");
 printf("\n\t\t\t\t\t3.Account details\n");
 printf("\n\t\t\t\t\t4.Exit\n");
 scanf("\n\t\t\t\t\t%d",&choice);
switch(choice)
{
case 1:
 system("cls");
 deposit_money();
 break;
 case 2:
 system("cls");
 withdraw_money();
 break;
 case 3:
 system("cls");
 AccountDetails();
 break;
 case 4:
 system("cls");
 ExitProgram();
 exit(0);
 default:
 printf("\n\t\t\t\t\t*Invalid choice*");
 }
printf("Enter any key to continue\n");
 printf("\n\n\t\t\t\t\tDo you want to continue?[y/n]:\t");
scanf("\n\t\t\t\t\t%s",&cont);
}
}
else {
printf("\n\t\t\t\t\tInvalid password");
}
}
printf("\n\n\t\t\t\t\t*Thank you for banking*\n\n");
}
return 0;
}
void deposit_money()
{
 FILE *ptr = fopen("userAccount.txt", "w");
 printf("\n\t\t\t\t\t*DEPOSITING MONEY*\n");
 divider();
 printf("\n\n\t\t\t\t\tEnter the amount you want to deposit:");
 scanf("%d", &dip_amt);
 amt += dip_amt;
 printf("\n\t\t\t\t\t**Money Deposited\n");
 printf("\n\t\t\t\t\tNow balance : %d\n", amt);
 fprintf(ptr, "\n\n\t\t\t\t\tTk%d had been deposited to your account \n", dip_amt);
 count++;
 fclose(ptr);
 printf("\n\t\t\t\t\tPress any key....\n");
 getch();
}
void withdraw_money()
{
 FILE *ptr = fopen("userAccount.txt", "w");
 printf("\n\t\t\t\t\t*WITHDRAWING MONEY*\n");
 divider();
 printf("\n\n\t\t\t\t\tEnter the amount you want to withdraw:");
 scanf("%d", &with_amt);
 if (amt < with_amt)
 {
 printf("\n\t\t\t\t\t*Insufficient balance*\n");
 }
 else
 {
 amt = amt - with_amt;
 printf("\n\t\t\t\t\t*Money withdrawn*\n");
 printf("\n\t\t\t\t\tCurrent balance : %d\n", amt);
 fprintf(ptr, "\n\n\t\t\t\t\tTk%d had been withdrawn from your account \n",
with_amt);
 count++;
 }
 fclose(ptr);
 printf("\n\t\t\t\t\tPress any key....\n");
 getch();
}
void AccountDetails()
{
 printf("\n\t\t\t\t\tACCOUNT DETAILS\n");
 divider();
 printf("\n\n\t\t\t\t\tName : %s\n", name);
 printf("\n\t\t\t\t\tAccount No. : %s\n", ac);
 printf("\n\t\t\t\t\tTotal balance = %d\n ", amt);
 printf("\n\n\n\t\t\t\t\tPress any key to exit.....");
 getch();
}
void ExitProgram()
{
 printf("\n\n\n\t\t\t\t\tAre you sure you want to exit?\n\n\n\t\t\t\t\t Press any key to confirm ");
 getch();
}
