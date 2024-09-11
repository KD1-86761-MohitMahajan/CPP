#include<iostream>
using namespace std;
class Date{
	int day;
	int month;
	int year;
    public :
    void initDate()
    {
        day=1;
        month=1;
        year=1900;
    }
    void acceptDateFromConsole()
    {
	      cout<<"------------------------------\n";
          cout<<"Enter Date :"<<endl;
          cout<<"Day   : ";
          cin>>day;
          cout<<"Month : ";
          cin>>month;
          cout<<"Year  : ";
          cin>>year;
    }

    void printDateOnConsole()
    {
        cout<<"------------------------------\n";
        cout<<"Current Date : "<<day<<"/"<<month<<"/"<<year<<endl;
    }
    int menu()
    {
        int choice;
        cout<<"------------------------------";
        cout<<"\n\tMenu:\n\t1.Set Time\n\t2.Display Time\n\t3.Is a leap ?\n\t4.Exit\nEnter Choice : ";
        cin>>choice;
        return choice;
    }
    bool isLeapYear()
    {
        if(year%4==0)
          return true;
        else
          return false;
    }
};
int main()
{
	Date d;
    int choice;
    d.initDate();
	while((choice=d.menu())!=4)
	{
	    switch(choice)
	    {
	    	case 1 :d.acceptDateFromConsole();
	    	        break;
	        case 2 :d.printDateOnConsole();
	                break;
            case 3 :cout<<"------------------------------\n";
                    if(d.isLeapYear())
                      cout<<"leaf Year"<<endl;
                    else
                      cout<<"Not a Leaf Year"<<endl;
	                break;
	        default:cout<<"Enter a valid choice !";
		}
	}
	
}
