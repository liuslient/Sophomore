#include<iostream>
#include<string>

using namespace std;

struct Person
{
        string name() const { return Name;}
        string addr() const { return Addr;}
        string Name;
        string Addr;
};

int main()
{
        return 0;
}  