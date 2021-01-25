#include<iostream>
using namespace std;

int main()
{
    int n=0,i=50;
    while(i<=100)
    {
        n=i+n;
        i++;
    }
    cout<<n<<endl;
}