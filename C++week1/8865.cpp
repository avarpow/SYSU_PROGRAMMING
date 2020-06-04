//source.h
class Account
{
private:
    int id = 0;
    double balance = 0;
    double annualInterestRate = 0;

public:
    Account() {}
    void setId(int _id)
    {
        id = _id;
    }
    int getId()
    {
        return id;
    }
    void setBalance(double _balance)
    {
        balance = _balance;
    }
    double getBalance()
    {
        return balance;
    }
    void setAnnualInterestRate(double _annualInterestRate)
    {
        annualInterestRate = _annualInterestRate;
    }
    double GetAnnualInterestRate()
    {
        return annualInterestRate;
    }
    double getMonthlyInterestRate()
    {
        return annualInterestRate / 12.0;
    }
    void withDraw(double amount)
    {
        balance -= amount;
    }
    void deposit(double amount)
    {
        balance += amount;
    }
};
//main.cpp
#include <iostream>
#include <iomanip>
#include "source.h"
using namespace std;
void print(Account &account)
{
    cout << "Account ID " << account.getId()
         << fixed << setprecision(2)
         << ", Balance " << account.getBalance() << ", Monthly Interest Rate " << account.getMonthlyInterestRate() << endl;
}
int main()
{

    Account a, b;
    print(a);

    b.setId(1122);
    b.setBalance(20000.0);
    b.setAnnualInterestRate(4.5);
    print(b);

    return 0;
}

/*
[Classes and Objects] The Account class 实时评测
 2020-04-29 23:59
 1000 ms
 32 MB
 贺子阳 (1499677880@qq.com)
Description
Deisgn a class named Account that contains:
An int data field named id for the account (default 0).
A double data field named balance for the account (default 0).
A double data field named annualInterestRate that stores the current interest rate (default 0).
A no-arg constructor that creates a default account.
The accessor and mutator functions for id, balance, and annualInterestRate.
A function named getMonthlyInterestRate() that returns the monthly interest rate. (Hint: monthlyInterestRate = annualInterestRate / 12)
A function name withDraw that withdraws a specified amount from the account.
A function name deposit that deposits a specified amount to the account.
Hint
``` 只提交Account类实现，不要提交main()函数。
*/