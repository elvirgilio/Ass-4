#include "Account.h"
#include "Transaction.cpp"

Account::Account()
{   
    srand(time(0));
    this->balance=0;
    this->accountNumber=rand()%500+1000;
    this->accountType="";
    this->deleted=false;
}

Account::~Account()
{

}

Account::Account( double balance,  string accountType)
{
    srand(time(0));
    this->balance = balance;
    this->accountNumber=rand()%500+1000;
    this->accountType = accountType;
    this->deleted=false;
}

double Account::getBalance()
{
    return this->balance;
}

int Account::getAccountNumber()
{
    return this->accountNumber;
}
string Account::getAccountType()
{
    return this->accountType;
}
void Account::Deposit(double deposit)
{
    this->balance += deposit;
}
void Account::Withdraw(double withdrawed)
{
    if (withdrawed>this->balance)
    {
        cout<<"Withdrawal failed! Not enough money in the account. \n";
        
    }
    else
    {
        this->balance -= withdrawed;
        cout<<"Transaction successfully completed. \n";
        
    }
}

void Account::addTransaction(Transaction& transaction)
{
    transactions.push_back(transaction);
    cout<<"Transaction has been saved added to your account log.\n";
}

int Account::getTransactionCount()
{
    int count = 0;
    list <Transaction>::iterator it;
    for( it=transactions.begin(); it!=transactions.end();it++)
    count++;
    return count;
}

Transaction* Account::getTransaction(int ID)
{
    list <Transaction>::iterator it;
    for (it=transactions.begin(); it!=transactions.end(); it++)
    {
        if (it->getID()==ID)
        return &*it;
    }
    Transaction* null= new Transaction ;
    return null;
}

void Account::print_transactions ()
{
    list<Transaction>::iterator it;
    for (it=transactions.begin(); it!=transactions.end(); it++)
    {
        cout << "Transaction #"<<" "<<it->getID()<<endl;
        cout << " Date and time: "<<" "<<it->getTransactionTD()<<endl;
        cout << " Location: "<<" "<<it->getTransactionLocation()<<endl;
        cout<< " Type: "<<" "<<it->getTransactionType()<<endl;
        cout << "Amount deposited or withdrawed: "<<" "<<it->getAmount()<<endl;
        cout<< "Used card number: "<<" "<<it->getCard()<<endl;
    }

}

void Account::delete_acc()
{
    this->deleted=true;
}

bool Account::isDeleted()
{
    return this->deleted;
}
