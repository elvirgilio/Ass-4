#include "Bank.h"

Bank::Bank(void)
{
    CustomersNumber = 0;
}

Bank::~Bank(void)
{
}

int Bank::getCustomersNumber()
{
    return CustomersNumber;
}

void Bank::addCustomer(Customer&new_cus)
{
    list <Customer>::iterator it;
    for (it= customers.begin(); it!=customers.end(); it++)
    {
        if(new_cus.getID()==it->getID())
        {
            it->delete_cus();
        }
    }
    customers.push_back(new_cus);
    CustomersNumber++;
    cout<<"Customer updated successfully! \n";
    
}
    




Customer* Bank::SearchForCustomer(int ID)
{
    list <Customer>::iterator it;
    for (it=customers.begin(); it!=customers.end(); it++)
    {
        if (it->getID()==ID)
        return &*it;
    }
    Customer* null = new Customer;
    null->delete_cus();
    return null;
}

void Bank::deleteCustomer(int ID)
{   
    list <Customer>::iterator it;
    for (it=customers.begin(); it!=customers.end(); it++)
    {
        if (it->getID()==ID)
        //it=customers.erase(it);
        it->delete_cus();
    }    
    CustomersNumber--;
}
