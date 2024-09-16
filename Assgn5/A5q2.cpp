#include <iostream>
using namespace std;
static int count = 10;
int choice = 0;

enum MENU
{
    createStudObject = 1,
    displayStudentsDetails,
    displayStudentsPercentage,
    searchStudent,
};

class Student
{
    int rollNo;
    string sname;
    char gender;
    int marks[3];

public:
    Student() : rollNo(++count), sname(" "), gender(' ')
    {
        for (int i = 0; i < 3; i++)
            marks[i] = 0;
    }

    Student(string nm, char g, int s1, int s2, int s3)
    {
        rollNo = ++count;
        sname = nm;
        gender = g;

        marks[0] = s1;
        marks[1] = s2;
        marks[2] = s3;
    }

    // getters

    int getRollNo(){
        return rollNo;
    }

    // accepts student records
    void acceptStudentDetails()
    {
        cout << "Enter student name : ";
        cin >> sname;

        cout << "Enter student gender(M/F) : ";
        cin >> gender;

        for (int i = 0; i < 3; i++)
        {
            cout << "Enter " << i + 1 << " subject marks : ";
            cin >> marks[i];
        }
    }

    // display student records
    void displayStudRec()
    {
        cout << "student roll no : " << rollNo << endl;
        cout << "student name : " << sname << endl;
        cout << "student gender : " << gender << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "Student " << i + 1 << " subject marks = " << marks[i] << endl;
        }
        cout << "\n-----------------------------------\n";
    }

    // show students percentages
    void showPercentage()
    {
        int sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum = sum + marks[i];
        }

        cout << "\nTotal marks = " << sum;
        cout << "\nPercentage = " << (sum / 3) << "%.";
        cout << "\n-----------------------------------\n";
    }
};

// search student by using roll no
int searchStudentByRollNo(Student **arr, int size, int rollNumber)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i]->getRollNo() == rollNumber)
        {
            arr[i]->displayStudRec();
            return i;
        }
    }
    return -1; // Student not found
}

void showMenu()
{
    cout << "\nStudent Management Menu:\n";
    cout << "1. Accept Student Details\n";
    cout << "2. Print Students details\n";
    cout << "3. Print Students percentages\n";
    cout << "4. Search Student by Roll Number\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
}

int main()
{
    Student *str[5];
    int studentCount = 0;
    do
    {
        showMenu();

        switch (MENU(choice))
        {
            // creating new student object
        case createStudObject:
        {
            if (studentCount < 5)
            {
                str[studentCount] = new Student(); // Create new student
                str[studentCount]->acceptStudentDetails();
                studentCount++;
            }
            else
            {
                cout << "Student list is full!\n";
            }
            break;
        }

        // display students details
        case displayStudentsDetails:
        {
            for (int i = 0; i < studentCount; i++)
            {
                if (str[i] != NULL)
                {
                    str[i]->displayStudRec();
                }
            }
            break;
        }

        // display students percentages
        case displayStudentsPercentage:
        {
            for (int i = 0; i < studentCount; i++)
            {
                if (str[i] != NULL)
                {
                    str[i]->showPercentage();
                }
            }
            break;
        }

        // search student using student roll no
        case searchStudent:
        {
            int rollNumber;
            cout << "Enter roll number to search: ";
            cin >> rollNumber;

            int index = searchStudentByRollNo(str, studentCount, rollNumber);
            if (index != -1)
            {
                cout << "\nStudent found at index = " << index << ".\n";
            }
            else
            {
                cout << "Student with roll number " << rollNumber << " not found.\n";
            }
            break;
        }

        default:
            cout << "Invalid choice..";
            break;
        }
    } while (choice != 5);

    // deallocated memory
    for (int i = 0; i < studentCount; i++)
    {
        delete str[i];
    }

    return 0;
}