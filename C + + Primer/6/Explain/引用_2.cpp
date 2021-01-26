#include<iostream>

using namespace std;

void swap(int &a,int &b)
{
    int i;
    i=a;
    a=b;
    b=i;
}

int main()
{
    int a=100,b=200;
    cout<<"a:"<<a<<" b: "<<b<<endl;
    swap(a,b);
    cout<<"a:"<<a<<" b: "<<b<<endl;
}