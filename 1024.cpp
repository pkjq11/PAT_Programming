/*
科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式[+-][1-9]"."[0-9]+E[+-][0-9]+，即数字的整数部分只有1位，
小数部分至少有1位，该数字及其指数部分的正负号即使对正数也必定明确给出。

现以科学计数法的格式给出实数A，请编写程序按普通数字表示法输出A，并保证所有有效位都被保留。

输入格式：

每个输入包含1个测试用例，即一个以科学计数法表示的实数A。该数字的存储长度不超过9999字节，且其指数的绝对值不超过9999。

输出格式：

对每个测试用例，在一行中按普通数字表示法输出A，并保证所有有效位都被保留，包括末尾的0。

输入样例1：
+1.23400E-03
输出样例1：
0.00123400
输入样例2：
-1.2E+10
输出样例2：
-12000000000
*/
#include<string>
#include<iostream>
#include<sstream>

using namespace std;
int main(int argc, char *argv[])
{
    string in;
    cin>>in;
    stringstream ss1;
    string::size_type i=0,j=in.find("E");
    if(in[i]=='-')
        ss1<<in[i++];
    else i++;
    char integer = in[i];
    i = i+2;
    string decimal = in.substr(i,j-i);
    char flat = in[++j];
    int power = stoi(in.substr(++j));
    if(flat == '-')
    {
        ss1<<"0.";
        int m = 1;
        while(m<power)
        {
            ss1<<'0';
            m++;
        }

        ss1<<integer<<decimal;
    }
    else {
        if (decimal.size()<power)
        {
            ss1<<integer<<decimal;
            for(int i = 0; i<(power - decimal.size()); i++)
                ss1<<"0";
        }
        else
        {
            string sub_decimal1 = decimal.substr(0,power);
            string sub_decimal2 = decimal.substr(power);
            ss1<<integer<<sub_decimal1<<"."<<sub_decimal2;
        }
    }
    cout<<ss1.str();
    return 0;
}
