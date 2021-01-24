#include<iostream>
#include<string>

using namespace std;

struct Person{
        string name() const { return Name;}
        string addr() const { return Addr;}
        string Name;
        string Addr;
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