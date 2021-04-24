#include "functions.cpp"
int main()
{
    cout<<"Welcome to our Banking system\n";
    string choice;
    Bank bank;
    int accountsNumber = 0;
    bool stop = false;

    do
    {
        cout << endl;
        menu();
        cout << "Your choice: ";
        cin >> choice;
        
        if (choice == "0")
        {
            stop = true;
        }
        else if (choice == "1")
        {
            withdrawal(bank);
        }
        else if (choice == "2")
        {
            deposit(bank);
        }
        else if (choice == "3")
        {
            new_acct(bank);
        }
        else if (choice == "5")
        {
            balance(bank);
        }
        else if (choice == "6")
        {
            account_info(bank);
        }
        else if (choice == "7")
        {
            account_info_tr(bank);
        }
        else if (choice == "8")
        {
            delete_acct(bank);
        }
        else if (choice == "4")
        {
            new_cus(bank);
        }
        else if (choice == "9")
        {
            delete_cus(bank);
        }
        else
        {
            cout << "Invalid choice, please try again." << endl;
        }
    } while (!stop);
    cout<<"Thanks for using our system.\n";
    system("pause");
    
    return 0;
}