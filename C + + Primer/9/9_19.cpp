#include<iostream>
#include<string>
#include<list>

using namespace std;

int main()
{
    list<string> str;
    string s;
    while(cin>>s)str.push_back(s);

    for(list<string>::iterator it=str.begin();it!=str.end();++it)
    {
        cout<<*it<<endl;
    }
    return 0;
}