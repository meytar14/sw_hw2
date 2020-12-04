#ifndef MYBANKLIB
#define MYBANKLIB
void openAccount(double amount);
void balance(int account_number);
void deposit(int account_number,double amount);
void draw(int account_number,double amount);
void close(int account_number);
void rate(double rate);
void print();
void end();
int status(int account_number);
#endif