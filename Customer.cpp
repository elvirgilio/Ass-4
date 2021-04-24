#include "Customer.h"

Customer::Customer()
{
    srand(time(0));
    this->ID=rand()%1000+1;
    this->ar_name="";
    this->en_name="";
    this->address="";
}

Customer::~Customer()
{
}

Customer::Customer( string ar_name, string en_name, string address)
{   
    srand(time(0));
    this->ID=rand()%1000+1;
    this->ar_name=ar_name;
    this->en_name=en_name;
    this->address=address;
}

string Customer::get_arName()
{
    return ar_name;
}

string Customer::get_enName()
{
    return en_name;
}

int Customer::getID()
{
    return ID;
}

Account* Customer::getAccount (int accountNumber)
{
    list <Account>::iterator it;
    for (it=accounts.begin(); it!=accounts.end(); it++)
    {
        if (it->getAccountNumber()==accountNumber)
        return &*it;
    }
    Account* null = new Account;
    null->delete_acc();
    return null;
}

void Customer::deleteAccount (int accountNumber)
{
    list <Account>::iterator it;
    for (it=accounts.begin(); it!=accounts.end(); it++)
    {
        if (it->getAccountNumber()==accountNumber)
        {
        it=accounts.erase(it);
        it->delete_acc();
        }
    }    
}

void Customer::add_Account(Account& req_acc)
{
    accounts.push_back(req_acc);
    cout<<"Account updated successfully.\n";
}

void Customer::delete_cus()
{
    this-> deleted=true;
}

bool Customer::isDeleted ()
{
    return this->deleted;
}


