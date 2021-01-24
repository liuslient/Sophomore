#include<iostream>

using namespace std;

istream & read(istream &is){
        int a;
        while(is>>a);
        is.clear(is.rdstate() & ~is.failbit & ~is.eofbit);
        return is;
}

int main()
{
        read(cin);

        return 0;
}
