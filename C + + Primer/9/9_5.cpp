#include<iostream>
#include<list>
#include<deque>
#include<vector>

using namespace std;

typedef vector<int >::iterator it;

it find (it begin ,it end , int n )
{
    while(begin!=end)
    {
        if(*begin==n) return begin;
        ++begin;
    }
    return end;
}

int main()
{
    vector<int> vi={1,5,4,7,6,8};
    it tmp=find(vi.begin(),vi.end(),9);
    if(tmp==vi.end()) cout<<"False";
    else cout <<*(tmp);
    
    return 0;
}