#include<iostream>
#include<string>
using namespace std;
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
          cout<<"Roll NO : ";
          cin>>roll_no;
          cout<<"Name    : ";
          cin>>name;
          cout<<"marks   : ";
          cin>>marks;
    }

    void printStudentOnConsole()
    {
        cout<<"------------------------------\n";
        cout<<"Student Details : "<<endl;
        cout<<"Roll No :"<<roll_no<<endl;
        cout<<"Name    :"<<name<<endl;
        cout<<"marks   :"<<marks<<endl;
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
int main()
{
	Students d;
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
