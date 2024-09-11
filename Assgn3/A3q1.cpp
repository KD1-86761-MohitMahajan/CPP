
#include<iostream>
using namespace std;
class Volume{
	int length;
	int width;
	int height;
	public :
    Volume()
    {
       length=2;
	   width=2;
	   height=2;  
       cout<<"Volume with default values : "<<length*width*height<<endl;
    }
    Volume(int n)
    {
       length=n;
	   width=n;
	   height=n;  
       cout<<"Volume with length,breadth and height with same value : "<<length*width*height<<endl;
    }
    Volume(int a,int b,int c)
    {
       length=a;
	   width=b;
	   height=c;  
       cout<<"Volume with different length,breadth and height values : "<<length*width*height<<endl;
    }     
};
int menu()
    {
        int choice;
        cout<<"----------------------------------------"<<endl;
        cout<<"\n\tMenu:"<<endl;
        cout<<"\n\t1. Calculate Volume with default values."<<endl;
        cout<<"\n\t2. Calculate Volume with length,breadth and height with same value."<<endl;
        cout<<"\n\t3. Calculate Volume with different length,breadth and height values. "<<endl;
        cout<<"\n\t4. Exit."<<endl;
        cout<<"\nEnter your choice : ";
        cin>>choice;
        cout<<"-----------------------------------------"<<endl;
        return choice;
    }

int main()
{
    int choice;
	while((choice=menu())!=4)
	{
	    switch(choice)
	    {
	    	case 1 :{
			        	Volume v;
			        }
	    	        break;
	        case 2 :{
			        	Volume v(3);
			        }
	    	        break;
            case 3 :{
			        	Volume v(4,4,4);
			        }
	    	        break;
	        default:cout<<"Enter a valid choice !";
		}
	}
	
}
