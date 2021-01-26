#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;
int main(int argc,char *argv[])
{
    ifstream in(argv[1]);
    if(!in)
    {
        cout<<"打开文件失败"<<endl;
        exit(1);
    }
    vector<int> vi;
    int val;
    while(in>>val)
    {
        vi.push_back(val);
    }
    fill(vi.begin(),vi.end(),0);
    for (auto i = vi.begin(); i != vi.end(); i++)
    {
        cout<<*i<<" ";
    }
    
}