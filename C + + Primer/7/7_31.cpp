#include<iostream>
#include<string>

using namespace std;
//要想定义一个对象必须知道他有哪些成员
class Y;

class X{
        Y *p;
};

class Y{
        X x;
};

int main()
{
        return 0;
}
