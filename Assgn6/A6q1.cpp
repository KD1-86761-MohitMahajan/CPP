include <iostream>
using namespace std;
class Date{
	int day;
	int month;
	int year;
	public :
		Date()
		{
			day=0;
			month=0;
			year=0;
		}
		Date(int day,int month,int year)
		{
			this->day=day;
			this->month=month;
			this->year=year;
		}
		void setDay(int day)
		{
			this->day=day;
		}
		void setMonth(int month)
		{
			this->month=month;
		}
		void setYear(int year)
		{
			this->year=year;
		}
		int getDay()
		{
			return day;
		}
		int getMonth()
		{
			return month;
		}
		int getYear()
		{
			return year;
		}
		void acceptDate()
		{
          cout<<"\tDay    : ";
          cin>>day;
          setDay(day);
          cout<<"\tMonth  : ";
          cin>>month;
          setMonth(month);
          cout<<"\tYear   : ";
          cin>>year;
          setYear(year);
		}
		void PrintDate()
		{
			cout<<day<<"/"<<month<<"/"<<year;
		}
};
class Person
{
	string name;
	string address;
    Date d;
    public :
    	Person()
    	{
    		this->name="";
    		this->address="";
		}
		Person(string name,string address,int day,int month,int year)
		{
			this->name=name;
			this->address=address;
			this->d.setDay(day);
			this->d.setMonth(month);
			this->d.setYear(year);
		}
		void setName(string name)
		{
		    this->name=name;
		}
		void setAddress(string address)
		{
		    this->address=address;
		}
		string getName()
		{
			return name;
		}
		string getAddress()
		{
			return address;
		}
		void acceptPerson()
		{
          cout<<"\tName     : ";
          getline(cin,name);
          setName(name);
          cout<<"\tAddress  : ";
          getline(cin,address);
          setAddress(address);
          cout<<"\tBirthdate: "<<endl;
          d.acceptDate();
		}
		void printPerson()
		{
          cout<<"\tName      : "<<getName()<<endl;
          cout<<"\tAddress   : "<<getAddress()<<endl;
          cout<<"\tBirthdate : ";
		  d.PrintDate();
		}
};
class Employee:public Person{
	int id;
	double sal;
	string dept;
	Date doj;
	public :
		Employee()
		{
			this->id=0;
			this->sal=0;
			this->dept="";
		}
		Employee(int id,double sal,string dept,int day,int month,int year):doj(day,month,year)
		{
			this->id=id;
			this->sal=sal;
			this->dept=dept;
		}
		void setId(int id)
		{
			this->id=id;
		}
		void setSal(double sal)
		{
			this->sal=sal;
		}
		void setDept(string dept)
		{
			this->dept=dept;
		}
		int getId()
		{
			return id;
		}
		double getSal()
		{
			return sal;
		}
		string getDept()
		{
			return dept;
		}
		void acceptEmployee()
		{
		  int id;
		  double sal;
		  string dept;
		  cout<<"------------------------------\n";
          cout<<"Enter Employee Details :"<<endl;
          acceptPerson();
          cout<<"\tId        : ";
          cin>>id;
          setId(id);
          cout<<"\tSalary    : ";
          cin>>sal;
          setSal(sal);
          getchar();
          cout<<"\tDepartment: ";
          getline(cin,dept);
          setDept(dept);
          cout<<"\tJoin date : "<<endl;
          doj.acceptDate();
		}
		void printEmployee()
		{
		  cout<<"------------------------------\n";
          cout<<"Employee Details :"<<endl;
          printPerson();
          cout<<"\n\tId        : "<<getId()<<endl;
          cout<<"\tSalary    : "<<getSal()<<endl;
          cout<<"\tDepartment: "<<getDept()<<endl;
          cout<<"\tJoin date : ";
		  doj.PrintDate();
          cout<<"\n------------------------------\n";
		}
};
int main()
{
	Employee e;
	e.acceptEmployee();
	e.printEmployee();
	return 0;
}
