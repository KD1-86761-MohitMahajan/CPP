#include <iostream>
using namespace std;
class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date()
    {
        int day = '0';
        int month = '0';
        int year = '0';
    }
    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    void Setday(int day)
    {
        this->day = day;
    }
    void Setmonth(int month)
    {
        this->month = month;
    }
    void Setyear(int year)
    {
        this->year = year;
    }
    int getday(int day)
    {
        return day;
    }
    int getmonth(int month)
    {
        return month;
    }
    int getyear(int year)
    {
        return year;
    }
    void acceptDate()
    {
        cout << "Enter the day, month and year - ";
        cin >> day >> month >> year;
    }

    void displayDate()
    {
        cout << day << "/" << month << "/" << year << endl;
    }
};
class Person {
    private:
    string name;
    string address;
    Date dob;

public:
Person()
{
    string name = "";
    string address = "";
}
Person (string name, string address, int day, int month, int year):dob(day, month, year)
{
    this -> name = name;
    this -> address = address;
   

};
void acceptPerson()
    {
        cout << "Enter the name - ";
        cin >> name;
        cout << "Enter the address - ";
        cin >> address;
        cout << "Enter the Date of Birth - " << endl;
        dob.acceptDate();
    };

    void displayPerson()
    {
        cout << "Person name - " << name << endl;
        cout << "Address - " << address << endl;
        cout << "Date of Birth - ";
        dob.displayDate();
    }
};
int main()
{
    Person e1;
    e1.acceptPerson();
    e1.displayPerson();
    return 0;
}