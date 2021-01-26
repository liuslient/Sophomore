#include<iostream>
#include<fstream>
#include<vector>
#include<list>
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
    list<string> vi;
    string val;
    while(in>>val)
    {
        vi.push_back(val);
    }
    cout<<"请输入要搜索的数字:";
    cin>>val;
    cout<<"序列中包括"<<count(vi.begin(),vi.end(),val)
    <<"个"<<val;
}