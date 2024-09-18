#include <bits/stdc++.h>
using namespace std;
#include <typeinfo>
class Employee
{
    int id;
    double sal;

public:
    Employee()
    {
        this->id = 0;
        this->sal = 0;
    }
    Employee(int id, double sal)
    {
        this->id = id;
        this->sal = sal;
    }
    void setId(int id)
    {
        this->id = id;
    }
    void setSal(double sal)
    {
        this->sal = sal;
    }
    int getId()
    {
        return id;
    }
    double getSal()
    {
        return sal;
    }
    virtual void accept()
    {
        int id;
        double sal;
        cout << "\tId         : ";
        cin >> id;
        setId(id);
        cout << "\tSalary     : ";
        cin >> sal;
        setSal(sal);
    }
    virtual void display()
    {
        cout << "\tId         : " << getId() << endl;
        cout << "\tSalary     : " << getSal() << endl;
    }
    virtual ~Employee()
    {
    }
};
class Manager : virtual public Employee
{
protected:
    double bonus;

public:
    Manager()
    {
        bonus = 0;
    }
    Manager(int id, double sal, double bonus) : Employee(id, sal)
    {
        this->bonus = bonus;
    }
    void setBonus(double bonus)
    {
        this->bonus = bonus;
    }
    double getBonus()
    {
        return bonus;
    }
    void acceptManager()
    {
        double bonus;
        cout << "\tBonus      : ";
        cin >> bonus;
        setBonus(bonus);
    }
    void displayManager()
    {
        cout << "\tBonus      : " << getBonus() << endl;
    }
    void accept()
    {
        cout << "Enter Manager Details      : " << endl;
        Employee::accept();
        acceptManager();
    }
    void display()
    {
        Employee::display();
        displayManager();
    }
};
class Salesman : virtual public Employee
{
protected:
    double commission;

public:
    Salesman()
    {
        commission = 0;
    }
    Salesman(int id, double sal, double commission) : Employee(id, sal)
    {
        this->commission = commission;
    }
    void setcommission(double commission)
    {
        this->commission = commission;
    }
    double getcommission()
    {
        return commission;
    }
    void acceptSalesman()
    {
        double commission;
        cout << "\tCommission : ";
        cin >> commission;
        setcommission(commission);
    }
    void displaySalesman()
    {
        cout << "\tCommission : " << getcommission() << endl;
    }
    void accept()
    {
        cout << "Enter Salesman Details     : " << endl;
        Employee::accept();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displaySalesman();
    }
};
class SalesManager : public Manager, public Salesman
{
public:
    SalesManager()
    {
    }
    SalesManager(int id, double sal, double bonus, double commission) : Employee(id, sal)
    {
    }
    void accept()
    {
        cout << "Enter SalesManager Details : " << endl;
        Employee::accept();
        acceptManager();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displayManager();
        displaySalesman();
    }
};
enum emenu
{
    Exit,
    Accept,
    Count,
    Managers,
    Salesmans,
    SalesManagers
};
enum emps
{
    Exit1,
    manager,
    salesman,
    salesmanager
};
int menu()
{
    int choice;
    cout << "********************************" << endl;
    cout << "What would you like do....? " << endl;
    cout << "\t0. EXIT" << endl;
    cout << "\t1. Accept Employees" << endl;
    cout << "\t2. View Count of Employees" << endl;
    cout << "\t3. View Mangers" << endl;
    cout << "\t4. View Salesmans" << endl;
    cout << "\t5. View SalesManagers" << endl;
    cout << "Enter your choice - ";
    cin >> choice;
    cout << "********************************" << endl;

    return choice;
}
int accept_menu()
{
    int choice;
    cout << "********************************" << endl;
    cout << "Registration for....? " << endl;
    cout << "\t0. EXIT" << endl;
    cout << "\t1. Manager" << endl;
    cout << "\t2. Salesman" << endl;
    cout << "\t3. SalesManager" << endl;
    cout << "Enter your choice - ";
    cin >> choice;
    cout << "********************************" << endl;

    return choice;
}
int main()
{
    Employee *e[5];
    int index = 0, n = 1;
    int choice, choice1;
    while ((choice = menu()) != Exit)
    {
        switch (emenu(choice))
        {
        case Accept:
            while ((choice1 = accept_menu()) != Exit1)
            {
                switch (emps(choice1))
                {
                case manager:
                    if (index < 5)
                    {
                        e[index] = new Manager;
                        e[index]->accept();
                        index++;
                    }
                    else
                        cout << "Registration full!" << endl;
                    break;
                case salesman:
                    if (index < 5)
                    {
                        e[index] = new Salesman;
                        e[index]->accept();
                        index++;
                    }
                    else
                        cout << "Registration full!" << endl;
                    break;
                case salesmanager:
                    if (index < 5)
                    {
                        e[index] = new SalesManager;
                        e[index]->accept();
                        index++;
                    }
                    else
                        cout << "Registration full!" << endl;
                    break;
                default:
                    cout << "Invalid choice ! " << endl;
                    break;
                }
            }
            break;
        case Count:
            cout << "List of Employees : " << endl;
            cout << "--------------------------------" << endl;
            for (int i = 0; i < index; i++)
            {
                if (typeid(*e[i]) == typeid(Manager))
                {
                    cout << "Manager      : " << endl;
                    e[i]->display();
                }
                else if (typeid(*e[i]) == typeid(Salesman))
                {
                    cout << "Salesmen     : " << endl;
                    e[i]->display();
                }
                else
                {
                    cout << "SalesManager : " << endl;
                    e[i]->display();
                }
            }
            cout << "--------------------------------" << endl;
            break;
        case Managers:
            n = 1;
            cout << "List of Managers : " << endl;
            cout << "--------------------------------" << endl;
            for (int i = 0; i < index; i++)
            {
                if (typeid(*e[i]) == typeid(Manager))
                {
                    cout << "Manager " << n << " : " << endl;
                    e[i]->display();
                    n++;
                }
            }
            cout << "--------------------------------" << endl;
            break;
            break;
        case Salesmans:
            n = 1;
            cout << "List of Salesman : " << endl;
            cout << "--------------------------------" << endl;
            for (int i = 0; i < index; i++)
            {
                if (typeid(*e[i]) == typeid(Salesman))
                {
                    cout << "Salesman " << n << " : " << endl;
                    e[i]->display();
                    n++;
                }
            }
            cout << "--------------------------------" << endl;
            break;
            break;
        case SalesManagers:
            n = 1;
            cout << "List of SalesManager : " << endl;
            cout << "--------------------------------" << endl;
            for (int i = 0; i < index; i++)
            {
                if (typeid(*e[i]) == typeid(SalesManager))
                {
                    cout << "SalesManager " << n << " : " << endl;
                    e[i]->display();
                    n++;
                }
            }
            cout << "--------------------------------" << endl;
            break;
            break;
        default:
            cout << "Invalid choice ! " << endl;
            break;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        delete e[i];
        e[i] = NULL;
    }
}
