/*
本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个“*”，要求按下列格式打印

*****
 ***
  *
 ***
*****
所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。

给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。

输入格式：

输入在一行给出1个正整数N（<=1000）和一个符号，中间以空格分隔。

输出格式：

首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。

输入样例：
19 *
输出样例：
*****
 ***
  *
 ***
*****
2
*/
#include<iostream>
#include<string>
using namespace std;

int levels(const int &num, int &used)
{
    int level = 1;
    int count = 1;
    while(count<=num)
    {
        level++;
        count = count+2*(2*level-1);
    }
    used = used+count-2*(2*level-1);
    return level-1;
}
void forward_out(const int &level, const string &symbol)
{
    int max = 2*level -1;
    for(int i = level; i != 0; i--)
    {
        for(int j = 0; j<(max - i*2 +1)/2;j++)
            cout<<" ";
        for(int j = 0; j<(i*2-1);j++)
            cout<<symbol;
        cout<<endl;
    }
}

void backward_out(const int &level, const string &symbol)
{
    int max = 2*level - 1;
    for(int i = 2; i <= level; i++)
    {
        for(int j = 0; j<(max - i*2 +1)/2;j++)
            cout<<" ";
        for(int j = 0; j<(i*2-1);j++)
            cout<<symbol;
        cout<<endl;
    }
}
int main(int argc, char *argv[])
{
    int num;
    string symbol;
    cin>>num>>symbol;
    int count = 0;
    int level = levels(num,count);
    forward_out(level,symbol);
    backward_out(level,symbol);
    cout<<num-count<<endl;
    return 0;
}
