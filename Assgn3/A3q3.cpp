
#include<iostream>
using namespace std;
class Address{
    private:
    string building;
    string street;
    string city;
    int pin;
    public:
    Address()
    {
        building="";
        street="";
        city="";
        pin=0;
    }
    void set_building(string building)
    {
        this->building=building;
    }
    void set_street(string street)
    {
        this->street=street;
    }
    void set_city(string city)
    {
        this->city=city;
    }
    void set_pin(int pin)
    {
         this->pin=pin;
    }
    int get_pin()
    {
        return pin;
    }
    string get_city()
    {
        return city;
    }
    string get_street()
    {
        return street;
    }
    string get_building()
    {
        return building;
    }
    void accept()
    {
        cout<<"----------------------------------------"<<endl;
        cout<<"\n\tEnter Details : "<<endl;
        cout<<"\tBuilding :";
        getline(cin,building);
        set_building(building);
        cout<<"\tStreet   :";
        getline(cin,street);
        set_street(street);
        cout<<"\tCity     :";
        getline(cin,city);
        set_city(city);
        cout<<"\tPin      :";
        cin>>pin;
        set_pin(pin);
        cout<<"-----------------------------------------"<<endl;
    }
    void diaplay()
    {
        cout<<"----------------------------------------"<<endl;
        cout<<"\n\tDetails : "<<endl;
        cout<<"\tBuilding :"<<get_building()<<endl;
        cout<<"\tStreet   :"<<get_street()<<endl;
        cout<<"\tCity     :"<<get_city()<<endl;
        cout<<"\tPin      :"<<get_pin()<<endl;
        cin>>pin;
        set_pin(pin);
        cout<<"-----------------------------------------"<<endl;
    }
};

int main()
{
    Address a;
    a.accept();
    a.diaplay();
}