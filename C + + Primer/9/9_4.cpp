#include<iostream>
#include<list>
#include<deque>
#include<vector>

using namespace std;

typedef vector<int >::iterator it;

bool find (it begin ,it end , int n )
{
    while(begin!=end)
    {
        if(*begin==n) return true;
        ++begin;
    }
    return false;
}

int main()
{
    vector<int> vi={1,5,4,7,6,8};
    cout<<find(vi.begin(),vi.end(),7);
    
    return 0;
}