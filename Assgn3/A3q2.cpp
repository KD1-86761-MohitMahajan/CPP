
#include<iostream>
using namespace std;
class  tollbooth{
	 unsigned int n_cars;
	 double t_amt;
    public :
    tollbooth()
    {
       n_cars=0;
	   t_amt=0;
    }   
    void payingCar()
    {
        ++n_cars;
        t_amt=t_amt+0.50;
    }
    void nopayCar()
    {
        ++n_cars;
    }
    void printOnConsole()
    {
        cout<<"----------------------------------------"<<endl;
        cout<<"\n\tDetails : "<<endl;
        cout<<"\n\tNumber of cars passed : "<<n_cars<<endl;
        cout<<"\n\tTotal amount of money : "<<t_amt<<" cents"<<endl;
        cout<<"-----------------------------------------"<<endl;
    }
    int menu()
    {
        int choice;
        cout<<"----------------------------------------"<<endl;
        cout<<"\n\tMenu:"<<endl;
        cout<<"\n\t1. Paying Car"<<endl;
        cout<<"\n\t2. Non Paying Car"<<endl;
        cout<<"\n\t3. Get Details"<<endl;
        cout<<"\n\t4. Exit."<<endl;
        cout<<"\nEnter your choice : ";
        cin>>choice;
        cout<<"-----------------------------------------"<<endl;
        return choice;
    }
};

int main()
{
    tollbooth t;
    int choice;
	while((choice=t.menu())!=4)
	{
	    switch(choice)
	    {
	    	case 1 :t.payingCar();
	    	        break;
	        case 2 :t.nopayCar();
	    	        break;
            case 3 :t.printOnConsole();
	    	        break;
	        default:cout<<"Enter a valid choice !";
		}
	}
	
}
