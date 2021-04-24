#ifndef BANK_H
#define BANK_H
#include "Customer.cpp"

class Bank
{
    list <Customer> customers;
    int CustomersNumber;
public:
    Bank();
    ~Bank();
    
    void addCustomer (Customer&);
    Customer* SearchForCustomer(int ID);
    void deleteCustomer(int ID);
    
    int getCustomersNumber();
};

#endif 
