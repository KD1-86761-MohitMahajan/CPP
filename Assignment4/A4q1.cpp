#include <iostream>
using namespace std;
class Time
{
private: // declaration of data members in class
    int h;
    int m;
    int s;

public:
    Time()      // parameterless constructor 
    {
        int h = 0;
        int m = 0;
        int s = 0;
    }
    Time(int h, int m, int s) // parameterized constructor
    {
        this->h = h;
        this->m = m;
        this->s = s;
    }
    void SetHr(int h) // Setter for Hr
    {
        this->h = h;
    }
    void SetMin(int m) // Setter for Min
    {
        this->m = m;
    }
    void SetSec(int s) // Setter for Sec
    {
        this->s = s;
    }
    int GetHr(int h) // Getter for Hr
    {
        return h;
    }
    int GetMin(int m) // Getter for Min
    {
        return m;
    }
    int GetSec(int s) // Getter for Sec
    {
        return s;
    }
    void acceptTime() // Function to accept the user data
    {
        cout << "Please enter the time below: " << endl;
        cout << "Hours: " << endl;
        cin >> h;
        SetHr(h);  //Implement Setter
        cout << "Minutes: " << endl;
        cin >> m;
        SetMin(m);   //Implement Setter
        cout << "Seconds: " << endl;
        cin >> s;
        SetSec(s);   //Implement Setter
        cout<< "--------------------------------------------------" << endl;
    }
    void displayTime() // Function to display the output
    {
        cout << "The time is: " << h << " hours " << m << " mins " << s << " secs." << endl;
        cout<< "--------------------------------------------------" << endl;
    }
};
int main()  
{
    Time **ptr = new Time *[5]; // One dimension array with pointer(hence we are using "this pointer" object hota to .)
    for (int i = 0; i < 5; i++) // for loop for dynamic memory allocation
        ptr[i] = new Time;
    for (int i = 0; i < 5; i++) // for loop for user input
        ptr[i]->acceptTime();
    for (int i = 0; i < 5; i++)
        ptr[i]->displayTime(); // for loop for the output
    for (int i = 0; i < 5; i++)
    {
        delete ptr[i]; // deallocate memory assigned to each member
        ptr[i] = NULL; // assign null value to avoid dangling ptr.
    }
    delete ptr; // deallocste memory assigned to array
    ptr = NULL; // assign Null value to avoid dangling
    return 0;
}