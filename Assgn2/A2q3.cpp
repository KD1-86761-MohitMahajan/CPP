
#include<iostream>
#include<string>
using namespace std;
namespace Nstudents{
    class Students{
	int roll_no;
	string name;
	int marks;
    public :
    void initDate()
    {
        roll_no=0;
        name="";
        marks=0;
    }
    void acceptStudentFromConsole()
    {
	      cout<<"------------------------------\n";
          cout<<"Enter Details :"<<endl;
          cout<<"\tRoll NO : ";
          cin>>roll_no;
          cout<<"\tName    : ";
          cin>>name;
          cout<<"\tmarks   : ";
          cin>>marks;
    }

    void printStudentOnConsole()
    {
        cout<<"------------------------------\n";
        cout<<"Student Details : "<<endl;
        cout<<"\tRoll No :"<<roll_no<<endl;
        cout<<"\tName    :"<<name<<endl;
        cout<<"\tmarks   :"<<marks<<endl;
    }
    int menu()
    {
        int choice;
        cout<<"------------------------------";
        cout<<"\n\tMenu:\n\t1.Set Details\n\t2.Display Details\n\t3.Exit\nEnter Choice : ";
        cin>>choice;
        return choice;
    }
};
}
int main()
{
	Nstudents :: Students d;
    int choice;
    d.initDate();
	while((choice=d.menu())!=3)
	{
	    switch(choice)
	    {
	    	case 1 :d.acceptStudentFromConsole();
	    	        break;
	        case 2 :d.printStudentOnConsole();
	                break;
	        default:cout<<"Enter a valid choice !";
		}
	}
	
}
