#include<iostream>
#include<deque>
#include<string>
#include<list>

using namespace std;

int main()
{
    list<int>num={1,2,3,4,5,6};
    deque<int> odd,even;
    for(list<int>::iterator it=num.begin();it!=num.end();++it)
    {
        if(*it%2)
        {
            odd.push_back(*it);
        }
        else
        {
            even.push_back(*it);
        }
        
        for(deque<int>::iterator it=odd.begin();it!=odd.end();++it)
        {
            cout<<*it<<" ";
        }
        for(deque<int>::iterator it=even.begin();it!=even.end();++it)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    return 0;
}