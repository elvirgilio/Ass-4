#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>
#include "Bank.cpp"

using namespace std;
time_t now = time(0);
char* dt = ctime(&now);

/*
 This function only displays the menu.
 */
void menu()
{
    cout << "Select one of the following:" << endl << endl;
    cout << "   1 - Withdraw" << endl;
    cout << "   2 - Deposit" << endl;
    cout << "   3 - New account" << endl;
    cout << "   4 - New customer" << endl;
    cout << "   5 - Balance" << endl;
    cout << "   6 - Account Info" << endl;
    cout << "   7 - Account Info and Account Transaction History" << endl;
    cout << "   8 - Delete Account" << endl;
    cout << "   9 - Delete Customer" << endl;
    cout << "   0 - Quit" << endl;
}
void new_acct(Bank& bank)
{
    cout<< "   Are you: \n   1 - Existing user.\n   2 - New user.\n";
    string choice;
    cout<<"Your choice:"; cin>>choice;
    while ((choice !="1") && (choice != "2")) 
    {
        cout<<"Invalid choice. Please try again.\n";
        cout<<"Your choice:";
        cin>>choice;
    }
        
    if (choice=="2")
    {
        double amount;
        string en_name;
        string ar_Name;
        string address;
        string accountType;    
        cout << "Enter English name: ";
        cin >> en_name;
        cout <<endl<< "Enter Arabic name: ";
        cin >> ar_Name;
        cout <<endl<< "Enter your address: ";
        cin>>address; 
        Customer req_cus (ar_Name,en_name,address);      
        do
        {
            cout << "Enter Account type (C - Checking, S - Saving, D - CD) : ";
            cin >> accountType;
            if (accountType == "C" || accountType == "S" || accountType == "D")
            {
                break;
            }
            else {
                cout << "Error. Invalid Account type. Please try again" << endl;
                }
        } while (true);
            
        do
        {
            cout << "Enter amount to deposit: ";
            cin >> amount;
            
            // check for validity
            if (amount>0)
            {
                break;
            }
            else {
                cout << "Error. Invalid amount, needed to entyer positiove number." << endl;
                }
        } while (true);
        Account new_acc (amount, accountType);
        req_cus.add_Account(new_acc);
        bank.addCustomer(req_cus);
        cout<<"Account created successfully.\n   Your ID is:"<<" "<<req_cus.getID()<<"\n   Your account's number is:"<<new_acc.getAccountNumber()<<endl;

    }
    else if (choice=="1")
    {
        string accountType;
        double amount; 
        cout<<"Enter your ID:";
        int ID;
        cout<<endl; cin>>ID;
        Customer* req_cus=bank.SearchForCustomer(ID);
        if (!req_cus->isDeleted()) 
        {       
            do
            {
                cout << "Enter Account type (C - Checking, S - Saving, D - CD) : ";
                cin >> accountType;
                if (accountType == "C" || accountType == "S" || accountType == "D")
                {
                    break;
                }
                else {
                    cout << "Error. Invalid Account type. Please try again" << endl;
                    }
            } while (true);
            
            do
            {
                cout << "Enter amount to deposit: ";
                cin >> amount;
                
                // check for validity
                if (amount>0)
                {
                    break;
                }
                else {
                    cout << "Error. Invalid amount, needed to enter positive number." << endl;
                    }
            } while (true);
            Account new_acc (amount, accountType);
            req_cus->add_Account(new_acc);
            cout<<"Account created successfully.\n   Your ID is:"<<" "<<req_cus->getID()<<"\n   Your account's number is:"<<new_acc.getAccountNumber()<<endl;            
        }
        else{
          cout << "Error. Customer number \"" << ID << "\" is not found." << endl;  
        }    
    }
}
/*
 This function prompts the user for the account number. If the account does not exist,
 it prints an error message. Otherwise, it asks the user for the amount of the withdrawal.
 If the account does not contain sufficient funds, an it prints an error message and does
 not perform the transaction.
 */
void withdrawal(Bank& bank)
{
    int index, requested_account, ID, card_no;
    string location;
    cout<<"Enter customer ID:";
    cin>>ID;
    Customer* req_cus =bank.SearchForCustomer(ID);
    if (!req_cus->isDeleted()) 
    {
        //prompt for account number
        cout << endl << "Enter the account number: ";
        cin >> requested_account;
        // account #0 is not valid
        if (requested_account != 0)
        {
            Account* req_acc = req_cus->getAccount(requested_account);
            if (!req_acc->isDeleted())
            {
                double amount;
                cout<<endl<<"Enter the card number:";
                cin>>card_no;
                cout<<endl<<"Enter the ATM location:";
                cin.ignore();
                getline (cin,location);
                cout<<"   ACCESS GRANTED.\n";
                cout << "Enter amount to withdraw: ";
                cin >> amount;
            
                // check is there possible to withdraw
                if (amount>0)
                {
                    // check is sufficient balance at account
                    if (req_acc->getAccountNumber()!=0)
                    {
                        Transaction wd (dt,location,"withdrawal",amount,card_no);
                        cout << "Withdraw is completed." << endl;
                        wd.withdraw(req_acc,amount);
                        cout<<"   Transaction ID is:"<<wd.getID()<<endl;
                        req_acc->addTransaction(wd);
                        cout<<"   New balance: "<<fixed << setprecision(2)<<req_acc->getBalance()<<endl;  
                    }
                    else {
                        cout << "Error. Insuffucient funds." << endl;
                    }
                }
                else {
                    cout << "Error. Invalid amount, needed to entyer positiove number." << endl;
                }
            }
            else {
                cout << "Error. Account number \"" << requested_account << "\" is not found." << endl;
            }
        }
        else {
            cout << "Error. Invalid account number." << endl;
        }
    }
    else{
        cout << "Error. Customer number \"" << ID << "\" is not found." << endl;
    }
}

/*
 This function prompts the user for the account number. If the account does not exist,
 it prints an error message. Otherwise, it asks the user for the amount of the deposit.
 */
void deposit(Bank& bank)
{
    int index, requested_account, ID, card_no;
    string location;
    cout<<"Enter customer ID:";
    cin>>ID;
    Customer* req_cus =bank.SearchForCustomer(ID);
    if (!req_cus->isDeleted()) 
    {
    // account #0 is not valid
        cout << endl << "Enter the account number: ";
        cin >> requested_account;
        if (requested_account != 0)
        {

            Account* req_acc = req_cus->getAccount(requested_account);
            if (!req_acc->isDeleted())
            {
                cout<<endl<<"Enter the card number:";
                cin>>card_no;
                cout<<endl<<"Enter the ATM location:";
                cin.ignore();
                getline (cin,location);
                cout<<"   ACCESS GRANTED.\n";
                double amount;
                cout << "Enter amount to deposit: ";
                cin >> amount;            
                // check is there possible to withdraw
                if (amount>0)
                {
                    Transaction dep (dt,location,"deposit",amount,card_no);
                    dep.deposit(req_acc,amount);      //deposit operation
                    cout << "Deposit is completed." << endl;
                    cout<<"   Transaction ID is:"<<dep.getID()<<endl;
                    req_acc->addTransaction(dep);
                    cout<<"   New balance: "<<fixed << setprecision(2)<<req_acc->getBalance()<<endl;  
                }
                else {
                    cout << "Error. Invalid amount, needed to enter positive number." << endl;
                }
            }
            else {
                cout << "Error. Account number \"" << requested_account << "\" is not found." << endl;
            }
        }
        else {
            cout << "Error. Invalid account number." << endl;
        }
    }
    else{
        cout << "Error. Customer number \"" << ID << "\" is not found." << endl;
    }   
}


/*
 This function prompts the user for an account number. If the account does not exist,
 or if the account exists but has a non-zero balance, it prints an error message.
 Otherwise, it closes and deletes the account. It returns the new number of accounts.
 */
void delete_acct(Bank& bank)
{
    int index, requested_account,ID; 
    cout<<"Enter customer ID:";
    cin>>ID;
    Customer* req_cus = bank.SearchForCustomer(ID);
    if (!req_cus->isDeleted()) 
    {
        cout << endl << "Enter the account number: ";
        cin >> requested_account;    

        if (requested_account != 0)
        {        
            if (!req_cus->getAccount(requested_account)->isDeleted())
            {   
                req_cus->deleteAccount(req_cus->getAccount(requested_account)->getAccountNumber());
                req_cus->getAccount(requested_account)->delete_acc();
            }
            else {
                cout << "Error. Account number \"" << requested_account << "\" is not found." << endl;
            }
        }
        else {
            cout << "Error. Invalid account number." << endl;    
        }
    }
    else{
        cout << "Error. Customer number \"" << ID << "\" is not found." << endl;
    }
}

/*
 This function prompts the user for an account number. If the account does not exist,
 it prints an error message. Otherwise, it prints the account balance.
 */

void balance(Bank& bank)
{
    int index, requested_account,ID;
    cout<<"Enter the customer ID:";
    cin>>ID;
    Customer* req_cus=bank.SearchForCustomer(ID);
    if (!req_cus->isDeleted()) 
    {
        cout << endl << "Enter the account number: ";
        cin >> requested_account;
        if (requested_account != 0)
        {
            Account* acc = req_cus->getAccount(requested_account);
            if (!acc->isDeleted())
            {
                cout << "Balance is: " << fixed << setprecision(2) << acc->getBalance() << endl;
            }
            else {
                cout << "Error. Account number \"" << requested_account << "\" is not found." << endl;
            }
        }
        else {
            cout << "Error. Invalid account number." << endl;
        }
    }
    else{ 
        cout<<"Error. Customer number \"" << ID << "\" is not found." << endl;
    } 
}

/*
 This function prompts the user for a social security number. If the account does not exist,
 it prints an error message. Otherwise, it prints the complete account information
 for the account requested .
 */
void account_info(Bank& bank)
{
    int index, requested_account,ID; 
    cout<<"Enter the customer ID:";
    cin>>ID;
    Customer* req_cus= bank.SearchForCustomer(ID); 
    if (!req_cus->isDeleted()) 
    {    
        cout << endl << "Enter the account number: ";
        cin >> requested_account;
        if (requested_account != 0)
        {

        
            Account* acc = req_cus->getAccount(requested_account);
        
            if ( !acc->isDeleted())
            {
                cout << " Account #" << acc->getAccountNumber() << endl;
                cout << " Customer info:" << endl;
                cout << "   English name: " << req_cus->get_enName() << endl;
                cout << "   Arabic name: " << req_cus->get_enName() << endl;
                cout << "   ID: " << req_cus->getID() << endl;
                cout << " Balance is: " << fixed << setprecision(2) << acc->getBalance() << endl;
                cout << " Type: "<<acc->getAccountType(); 
            }
            else {
                cout << "Error. Account number \"" << requested_account << "\" is not found." << endl;
            }
        }
        else {
            cout << "Error. Invalid account number." << endl;
        }
    }    
    else{
        cout << "Error. Customer number \"" << ID << "\" is not found." << endl;
    }
}

void account_info_tr(Bank& bank)
{
    int index, requested_account,ID; 
    cout<<"Enter the customer ID:";
    cin>>ID;
    Customer* req_cus= bank.SearchForCustomer(ID); 
    if (!req_cus->isDeleted()) 
    {    
        cout << endl << "Enter the account number: ";
        cin >> requested_account;
        if (requested_account != 0)
        {

        
            Account* acc = req_cus->getAccount(requested_account);
        
            if ( !acc->isDeleted())
            {
                cout << " Account #" << acc->getAccountNumber() << endl;
                cout << " Customer info:" << endl;
                cout << "   English name: " << req_cus->get_enName() << endl;
                cout << "   Arabic name: " << req_cus->get_enName() << endl;
                cout << "   ID: " << req_cus->getID() << endl;
                cout << " Balance is: " << fixed << setprecision(2) << acc->getBalance() << endl;
                cout << " Type: "<<acc->getAccountType();          
                int trCount = acc->getTransactionCount();
                cout << endl << "Transaction List:  [" << trCount << " transaction(s)]" << endl;
                acc->print_transactions();
            }
            else {
                cout << "Error. Account number \"" << requested_account << "\" is not found." << endl;
            }
        }
        else {
            cout << "Error. Invalid account number." << endl;
        }
    }    
    else{
        cout << "Error. Customer number \"" << ID << "\" is not found." << endl;
    }
}

void new_cus(Bank& bank)
{
    double amount;
    string en_name;
    string ar_Name;
    string address;
    string accountType;    
    cout << "Enter English name: ";
    cin >> en_name;
    cout <<endl<< "Enter Arabic name: ";
    cin >> ar_Name;
    cout <<endl<< "Enter your address: ";
    cin>>address; 
    Customer req_cus (ar_Name,en_name,address);
    bank.addCustomer(req_cus);     
    cout<<"Customer created successfully!\n   Your ID is:"<<req_cus.getID()<<endl;    
}

void delete_cus(Bank& bank)
{
    int ID;
    cout<<"Enter the customer ID:"; cin>>ID;
    if(!(bank.SearchForCustomer(ID)->isDeleted()))
    {
        bank.deleteCustomer (ID);
        cout<<"Customer deleted successfully! \n";
    }
    else{
        cout << "Error. Customer number \"" << ID << "\" is not found." << endl;   
    }
}

