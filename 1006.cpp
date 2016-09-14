/*
让我们用字母B来表示“百”、字母S表示“十”，用“12...n”来表示个位数字n（<10），换个格式来输出任一个不超过3位的正整数。例如234应该被输出为BBSSS1234，因为它有2个“百”、3个“十”、以及个位的4。

输入格式：每个测试输入包含1个测试用例，给出正整数n（<1000）。

输出格式：每个测试用例的输出占一行，用规定的格式输出n。
输入样例1：234

输出样例1：BBSSS1234

输入样例2：23

输出样例2：SS123

*/

#include <string>
#include <sstream>
#include <iostream>

int main()
{
    int n;
    int num[3]={0,0,0};
    std::cin>>n;
    int temp = n;
    std::stringstream stream;
    for(int i = 0;i < 3;i++)
    {
        num[i] = temp%10;
        temp = temp/10;
    }
    while(num[2]!=0)
    {
        stream<<'B';
        num[2]--;
    }

    while(num[1]!=0)
    {
        stream<<'S';
        num[1]--;
    }
    int x=1;
    while(num[0]!=0)
    {
        stream<<x;
        num[0]--;
        x++;
    }
    std::string str = stream.str();
    std::cout<<str<<std::endl;
    return 0;
}
