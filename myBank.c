
#include <stdio.h>
#include "myBank.h"

float accounts[50][2]={{0},{0}};//{status,balance}
int numOfAccounts=0;
void openAccount(double amount)
{
   if(numOfAccounts>=50)
   {
       printf("there is maximum number of accounts, cant open more accounts\n");
       return;
   }
   if(amount<0)
   {
       printf("invalid amount\n");
       return;
   }
   for(int i=0;i<50;i++)
   {
       if(accounts[i][0]==0)//check if the account is close
       {
           accounts[i][0]=1;
           accounts[i][1]=amount;
           printf("New account number is: :%d\n",(i+901));
           return;
       }
   }
   numOfAccounts++;
}
void balance(int account_number)
{
    if(!(901<=account_number && account_number<=950))
    {
        return;
    }
    if(accounts[account_number-901][0]==0)
    {
      printf("this account is closed\n");
      return;
    }
    else
    {
      printf("The balance of account number %d is: %f\n",account_number,accounts[account_number-901][1]);
    }
}
void deposit(int account_number,double amount)
{
   if(!(901<=account_number && account_number<=950))
    {
        return;
    }
    if(amount<0)
    {
        printf("Cannot deposit a negative amount\n");
        return;
    }
     if(accounts[account_number-901][0]==0)
    {
      printf("this account is closed\n");
      return;
    }
    else
    {
      accounts[account_number-901][1]=accounts[account_number-901][1]+amount;
      printf("the new balnce  is %f\n",accounts[account_number-901][1]);
    }
}
void draw(int account_number,double amount)
{
     if(!(901<=account_number && account_number<=950))
    {
        return;
    }
    if(accounts[account_number-901][0]==0)
    {
      printf("this account is closed\n");
      return;
    }
    if(accounts[account_number-901][1]<amount)
    {
        printf("Cannot withdraw more than the balance");
        return;
    }
    else
    {
      accounts[account_number-901][1]=accounts[account_number-901][1]-amount;
      printf("The new balance is: %lf\n",accounts[account_number-901][1]);
    }
}
void close(int account_number)
{
   if(!(901<=account_number && account_number<=950))
    {
        return;
    }
    if(accounts[account_number-901][0]==1)
    {
      accounts[account_number-901][0]=0;
      accounts[account_number-901][1]=0;
      printf("close account number %d\n",account_number);
    }
}
void rate(double rate)
{
    for(int i=0;i<50;i++)
   {
       if(accounts[i][0]==1)//check if the account is open
       {
           accounts[i][1]=accounts[i][1]*(1+(rate/100));
       }
   }
}
void print()
{
 for(int i=0;i<50;i++)
   {
       if(accounts[i][0]==1)//check if the account is open
       {
           printf("the balnce of account number %d is %f\n",(i+901),accounts[i][1]);
       }
   }
}
void end()
{
for(int i=0;i<50;i++)
   {
       if(accounts[i][0]==1)//check if the account is open
       {
           accounts[i][0]=0;//close the account
           accounts[i][1]=0;//reset the amount in this acount
       }
   }
}

int status(int account_number){
return accounts[account_number-901][0];
}