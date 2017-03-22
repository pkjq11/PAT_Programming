/*
给定任一个各位数字不完全相同的4位正整数，如果我们先把4个数字按非递增排序，再按非递减排序，然后用第1个数字减第2个数字，将得到一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”之称的6174，这个神奇的数字也叫Kaprekar常数。

例如，我们从6767开始，将得到

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...

现给定任意4位正整数，请编写程序演示到达黑洞的过程。

输入格式：

输入给出一个(0, 10000)区间内的正整数N。

输出格式：

如果N的4位数字全相等，则在一行内输出“N - N = 0000”；否则将计算的每一步在一行内输出，直到6174作为差出现，输出格式见样例。注意每个数字按4位数格式输出。

输入样例1：
6767
输出样例1：
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
输入样例2：
2222
输出样例2：
2222 - 2222 = 0000

*/
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

bool up(char &x, char &y)
{
    return x<=y;
}

bool down(char &x, char &y)
{
    return x>=y;
}

int bit(int & x)
{
    if(x/10==0)
        return 3;
    else if (x/100 == 0)
        return 2;
    else if (x/1000 == 0)
        return 1;
    else return 0;
}

int main(int argc, char *argv[])
{
    string input;
    string less, greater,dif;
    cin>>input;
    less = input;
    greater = input;
    sort(less.begin(),less.end(),up);
    sort(greater.begin(),greater.end(),down);
    if(less == greater)
    {
        cout<<less<<" - "<<greater<<" = "<<"0000"<<endl;
        return 0;
    }
    stringstream ss1(greater),ss2(less),ss3("");
    int temp1,temp2,temp3;
    ss1>>temp1;
    ss2>>temp2;
    temp3 = temp1 - temp2;
    while (temp3 != 6174)
    {
        ss1.clear();
        ss2.clear();
        ss3.clear();
        ss1.str("");
        ss2.str("");
        ss3.str("");
        int x = bit(temp3);
        for(int i = 0;i<x;i++)
            ss3<<0;
        ss3<<temp3;
        dif = ss3.str();
        cout<<greater<<" - "<<less<<" = "<<dif<<endl;
        less = dif;
        greater = dif;
        sort(less.begin(),less.end(),up);
        sort(greater.begin(),greater.end(),down);
        ss1.str(greater);
        ss2.str(less);
        ss1>>temp1;
        ss2>>temp2;
        temp3 = temp1 - temp2;
    }
    cout<<greater<<" - "<<less<<" = "<<6174<<endl;
    return 0;
}
