#include<iostream>
#include<deque>
#include<string>

using namespace std;

int main()
{
    deque<string> str;
    string s;
    while(cin>>s)str.push_back(s);

    for(deque<string>::iterator it=str.begin();it!=str.end();++it)
    {
        cout<<*it<<endl;
    }
    return 0;
}