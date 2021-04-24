#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <time.h>
#include <list>
#include "Account.cpp"
using namespace std;
class Customer
{
    int ID;
    string ar_name;
    string en_name;
    string address;
    bool deleted;
    list <Account> accounts;    
public:
    Customer();
    Customer( string, string, string);
    ~Customer();
    
    string get_arName();
    string get_enName();
    int getID();
    void add_Account (Account&);
    Account* getAccount (int accountNumber);
    void deleteAccount (int accountNumber);
    void delete_cus();
    bool isDeleted();
};
#endif 
