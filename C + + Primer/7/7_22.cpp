#include <string>
#include <iostream>

using namespace std;
struct Person
{
	friend istream &read(istream &is, Person &person);
	friend ostream &print(ostream &os, const Person &person);

public:
	Person()=default;
    Person(const string &_name,const string &_addr):
    Name(_name),Addr(_addr) {}

    string name() const { return Name;}
    string addr() const { return Addr;}

private:
	string Addr;
    string Name;

};

ostream &print(ostream &os,const Person &item){
        os<<item.name()<<" "<<item.addr();
        return os;
}
istream &read(istream &is,Person &item){
        is>>item.Name>>item.Addr;
        return is;
}

int main()
{
    return 0;
}