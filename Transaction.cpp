#include "Transaction.h"

Transaction::Transaction()
{
    srand(time(0));
    this->ID=rand()%1000+1;
}

Transaction::Transaction(string date_time,  string location,string type, double amount, int card_no)
{
    srand(time(0));
    this->ID=rand()%1000+1;
    this->date_time=date_time;
    this->location=location;
    this->amount = amount;
    this->card_no=card_no;
    this->type=type;
}

Transaction::~Transaction()
{

}

string Transaction::getTransactionTD(){
    return this->date_time;
}

string Transaction::getTransactionType(){
    return this->type;
}

string Transaction::getTransactionLocation(){
    return this->location;
}

long Transaction::getCard (){
    return this->card_no;
}

int Transaction::getID()
{
    return this->ID;
}

double Transaction::getAmount()
{
    return this->amount;
}

void Transaction::deposit( Account*& req_acc, double amount)
{
    req_acc->Deposit(amount);
}

void Transaction::withdraw( Account*& req_acc, double amount)
{
    req_acc->Withdraw(amount);
}
