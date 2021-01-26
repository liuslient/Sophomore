#include<iostream>
using namespace std;

int main()
{
    int a,b;
    cout<<"请输入两个数"<<endl;
    cin>>a>>b;
    if(a>b)
    {
        while(a>=b)
        {
            cout<<b<<endl;
            b++;
        }
    }
    else
    {
        while(b>=a)
        {
            cout<<a<<endl;
            a++;
        }
    }
    
    
    return 0;
}