#include <stdio.h>
#include "myBank.h"
void menu()
{
     printf(" Please choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n ");
 
}
int main()
{
    menu();
    int boolean=1;
    while(boolean==1)
    { char c;
      double amount;
      int account_number;
      double r;
        scanf("%c", &c);
      
        switch(c)
           {
         case 'O':
            printf("Please enter amount for deposit:");
            if(scanf("%lf", &amount)!=1)
            {
                printf("Failed to read the amount\n");
            }
            else if(amount<0)
            {
                printf("Invalid Amount\n");
            }
            else{
            openAccount(amount);
            }
            menu();

         break;

         case 'B':
            printf("Please enter account number:");
            if(scanf("%d",&account_number)!=1)
            {
                printf("Failed to read the account number\n");
            }
            else if(account_number>=901&&account_number<=950)
            {
                if(status(account_number)==1)
                {
                 balance(account_number);
                }
                else
                {
                 printf("this account is closed\n");
                }   
            }
            else
            {
                printf("invalid account number\n");
            }
            menu();
         break;

         case 'D':
            printf("Please enter account number:");
            if(scanf("%d",&account_number)!=1)
            {
                printf("Failed to read the account number\n");
            }
            else if(account_number>=901&&account_number<=950){
            if(status(account_number)==1){
            printf("Please enter amount for deposit:");
            if(scanf("%lf", &amount)!=1)
            {
                printf("Failed to read the amount\n");
            }
            else{
                deposit(account_number,amount);
            }
           }
            else{
                printf("this account is closed\n");
            }
           }
           else{
               printf("invalid account number\n");
           }
            menu();
         break;

         case 'W':
            printf("Please enter account number:");
            if(scanf("%d",&account_number)!=1)
            {
                printf("Failed to read the account number\n");
            }
            else if(account_number>=901&&account_number<=950)
            {
                if(status(account_number)==1)
                {
                    printf("Please enter the amount to withdraw:");
                    if(scanf("%lf", &amount)!=1)
                    {
                        printf("Failed to read the amount\n");
                    }
                    else
                    {
                        draw(account_number,amount);
                    }
                }
                else
                {
                    printf("this account is closed\n");
                }
            }
            else{
                printf("invalid account number\n");
            }
            menu();
         break;

         case 'C':
            printf("Please enter account number:");
            if(scanf("%d",&account_number)!=1)
            {
                printf("Failed to read the account number\n");
            }
            else if(account_number>=901&&account_number<=950)
            {
                if(status(account_number)==1)
                {
                 close(account_number);
                }
                else
                {
                 printf("this account is closed\n");
                }   
            }
            else
            {
                printf("invalid account number\n");
            }
            menu();
         break;

         case 'I':
            printf("Please enter interest rate:");
            if(scanf("%lf", &r)!=1)
            {
                printf("Failed to read the interest rate\n");
            }
            else if(r<0)
            {
                printf("Invalid interest rate");
            }
            else
            {
                rate(r);
            }
            menu();
         break;

         case 'P':
            print();
            menu();
         break;

         case 'E':
            end();
            boolean=0;
         break;
         case ' ':
         break;

         case '\n':
         break;

        

         default:
             printf("Invalid transaction type\n");
             menu();
        }

    }
}
