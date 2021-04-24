#ifndef ACCOUNT_H
#define ACCOUNT_H
using namespace std;
#include "Transaction.h"
#include "Customer.h"
class Customer;
class Account
{
    double balance;
    int accountNumber;
    string accountType;
    bool deleted;
    list <Transaction> transactions;
public:
    Account();
    Account( double,  string);
    ~Account();
    
    double getBalance();
    int getAccountNumber();
    string getAccountType();

    void Deposit(double);
    void Withdraw(double);

    void addTransaction(Transaction& transaction);
    int getTransactionCount();
    Transaction* getTransaction(int ID);
    void print_transactions ();
    void delete_acc();
    bool isDeleted ();
};
#endif 
