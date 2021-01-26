#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

inline void print(vector<string> &words)
{
    for (auto i = words.begin(); i != words.end(); i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
}

void elimDups(vector<string>&words)
{
    print(words);
    sort(words.begin(),words.end());
    print(words);
    auto end_unique=unique(words.begin(),words.end());
    print(words);
    words.erase(end_unique,words.end());
    print(words);
}

int main(int argc,char *argv[])
{
    ifstream in(argv[1]);
    if(!in)
    {
        cout<<"打开文件失败"<<endl;
        exit(1);
    }
    vector<string> words;
    string word;
    while(in>>word)
    {
        words.push_back(word);
    }
    elimDups(words);
    return 0;
}