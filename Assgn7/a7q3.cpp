#include <iostream>
using namespace std;
const int size = 5;

class InSufficientFundsException
{
    string msg;

public:
    InSufficientFundsException()
    {
        msg = "some exception occured.";
    }
    InSufficientFundsException(string msg)
    {
        this->msg = msg;
    }

    void display()
    {
        cout << "Exception : InSufficientFundsException" << endl;
        cout << "Message : " << msg<<endl;
    }
};

enum EAccountType
{
    Saving = 1,
    Current,
    Dmat,
    Exit
};

class Account
{
    int accNo;
    EAccountType e;
    double balance;

public:
    Account()
    {
        this->accNo = 101;
        this->balance = 00;
    }

    Account(int accNo, EAccountType etype, double bal)
    {
        this->accNo = accNo;
        this->e = etype;
        this->balance = bal;
    }

    void accept()
    {
        int choice;
        cout << "Enter account no : ";
        cin >> accNo;
        cout << "Choose Account type : " << endl;
        cout << "1.Saving" << endl;
        cout << "2.Current" << endl;
        cout << "3.Dmat" << endl;
        cin >> choice;
        e = EAccountType(choice); // it will
        cout << "Enter balance : ";
        cin >> balance;
    }

    void display()
    {
        cout << "\nAccount no = " << accNo << endl;
        cout << "Account balance = " << balance << endl;
        switch (e)
        {
        case Saving:
            cout << "Account type - Savings " << endl;
            break;
        case Current:
            cout << "Account type - Current " << endl;
            break;
        case Dmat:
            cout << "Account type - Dmat " << endl;
            break;
        }
    }

    void deposite(int amt)
    {
        if (amt < 0)
            throw InSufficientFundsException("You can't enter negative number..");
        else
        {
            balance = balance + amt;
            cout << "New balance = " << balance;
        }
    }

    void withdraw(int amt)
    {
        if (amt > balance)
            throw InSufficientFundsException("Your amount is greater than your balance. You can't withdraw.");
        else
        {
            balance = balance - amt;
            cout << "New balance = " << balance<<endl;
        }
    }
};

int getDepositeAmount()
{
    int amt;
    cout << "\nEnter amount to deposite : ";
    cin >> amt;
    return amt;
}

int getWithdrawAmount()
{
    int amt;
    cout << "\nEnter amount to withdraw : ";
    cin >> amt;
    return amt;
}

int main()
{
    Account *acc[size];
    int index = 0;

    while (index != 5)
    {
        if (index < size)
        {
            acc[index] = new Account;
            acc[index]->accept();
            acc[index]->display();

            try
            {
                acc[index]->deposite(getDepositeAmount());
            }
            catch (InSufficientFundsException e)
            {
                e.display();
            }

            try
            {

                acc[index]->withdraw(getWithdrawAmount());
            }
            catch (InSufficientFundsException e)
            {
                e.display();
            }
            index++;
        }
        else
            cout << "Account Array is full..";
    }

    return 0;
}