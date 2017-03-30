/*
给定一个正整数数列，和正整数p，设这个数列中的最大值是M，最小值是m，如果M <= m * p，
则称这个数列是完美数列。

现在给定参数p和一些正整数，请你从中选择尽可能多的数构成一个完美数列。

输入格式：

输入第一行给出两个正整数N和p，其中N（<= 105）是输入的正整数的个数，p（<= 109）是给定的参数。
第二行给出N个正整数，每个数不超过109。

输出格式：

在一行中输出最多可以选择多少个数可以用它们组成一个完美数列。

输入样例：
10 8
2 3 20 4 5 1 6 7 8 9
输出样例：
8
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(int argc, char *argv[])
{
    int N,p;
    cin>>N>>p;
    vector<int> input(N);
    for(auto i = input.begin(); i != input.end(); i++)
        cin>>*i;
    sort(input.begin(),input.end());
    auto min_iter = input.begin();
    auto max_iter = input.begin();
    int max_count = 0;
    while(min_iter != input.end())
    {
        int count = 0;
        while(max_iter != input.end() && *max_iter <= *min_iter * p)
        {
            count++;
            max_iter++;
        }
        max_count = count>max_count?count:max_count;
        min_iter++;
    }
    cout<<max_count<<endl;
    return 0;
}
