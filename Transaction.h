#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
#include "Account.h"
using namespace std;
class Account;
class Transaction
{
    string date_time;
    string location;
    string type;
    double amount;
    long card_no;
    int ID;
public:
    Transaction();
    Transaction( string, string, string, double, int);
    ~Transaction();
    
    string getTransactionType();
    string getTransactionTD();
    string getTransactionLocation();
    double getAmount();
    long getCard();
    int getID();
    void deposit(Account*& , double amount);
    void withdraw(Account*&, double amount);
};

#endif 
