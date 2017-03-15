/*
令Pi表示第i个素数。现任给两个正整数M <= N <= 10^4，请输出PM到PN的所有素数。

输入格式：

输入在一行中给出M和N，其间以空格分隔。

输出格式：

输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/
#include<iostream>
#include<memory.h>
#include<math.h>
#include<vector>
using namespace std;

int main()
{
    bool flag[10000];
    memset(flag,true,sizeof(flag));
    flag[0] = false;
    flag[1] = false;
    vector<int> prime;
    for(int i = 4;i<=10000;i=i+2)
        flag[i] = false;
    for(int i =3;i<=10000;i=i+2)
    {
        if(flag[i])
            continue;
        double sqrt_i = sqrt(i);
        int j;
        for(j = 2;j<sqrt_i;j++)
            if(i%j==0) break;
        if(j<sqrt_i)
        {
            int k = 2;
            while(k*i<10000)
            {
                flag[k*i] = true;
                k++;
            }
        }
        else flag[i] = true;
    }
    for(int i = 1;i<=10000;i++)
        if(flag[i])
            prime.push_back(i);
    for(auto it = prime.begin();it != prime.end();it++)
        cout<<*it<<endl;
}
