/*
输入两个非负10进制整数A和B(<=230-1)，输出A+B的D (1 < D <= 10)进制数。

输入格式：

输入在一行中依次给出3个整数A、B和D。

输出格式：

输出A+B的D进制数。

输入样例：
123 456 8
输出样例：
1103
*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(int argc, char *argv[])
{
    unsigned int a,b,d;
    cin>>a>>b>>d;
    stack<unsigned int> result;
    unsigned int dividend = a+b;
    unsigned int remainder = 0;
    while(dividend != 0)
    {
        remainder = dividend % d;
        dividend = dividend / d;
        result.push(remainder);
    }
    while(!result.empty())
    {
        cout<<result.top();
        result.pop();
    }
    return 0;
}
