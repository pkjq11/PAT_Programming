/*
给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：

A1 = 能被5整除的数字中所有偶数的和；
A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
A3 = 被5除后余2的数字的个数；
A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
A5 = 被5除后余4的数字中最大数字。
输入格式：

每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。

输出格式：

对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若其中某一类数字不存在，则在相应位置输出“N”。

输入样例1：
13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例1：
30 11 2 9.7 9
输入样例2：
8 1 2 4 5 6 7 9 16
输出样例2：
N 11 2 N 9
*/
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int a1=0,a2=0,a3=0,a5=0,num;
    double a4;
    int a2_flag=1,a4_num=0;
    for (int i =0;i<N;i++)
    {
        cin>>num;
        if(num%5==0&&num%2==0)
            a1+=num;
        if(num%5==1)
        {
            a2+=num*a2_flag;
            a2_flag = -a2_flag;
        }
        if(num%5==2)
            a3++;
        if(num%5==3)
        {
            a4+=num;
            a4_num++;
        }
        if(num%5==4&&num>a5)
            a5=num;
    }
    a1>0?cout<<a1<<" ":cout<<"N ";
    a2>0?cout<<a2<<" ":cout<<"N ";
    a3>0?cout<<a3<<" ":cout<<"N ";
    a4_num>0?cout<<setprecision(2)<<a4/a4_num<<" ":cout<<"N ";
    a5>0?cout<<a5:cout<<"N";
    return 0;
}
