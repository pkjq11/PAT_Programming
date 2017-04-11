/*
为了用事实说明挖掘机技术到底哪家强，PAT组织了一场挖掘机技能大赛。现请你根据比赛结果统计出技术最强的那个学校。

输入格式：

输入在第1行给出不超过105的正整数N，即参赛人数。随后N行，每行给出一位参赛者的信息和成绩，包括其所代表的学校的编号（从1开始连续编号）、及其比赛成绩（百分制），中间以空格分隔。

输出格式：

在一行中给出总得分最高的学校的编号、及其总分，中间以空格分隔。题目保证答案唯一，没有并列。

输入样例：
6
3 65
2 80
1 100
2 70
3 40
3 0
输出样例：
2 150
*/
#include<iostream>
#include<set>
#include<map>
using namespace std;

int main(int argc, char *argv[])
{
    set<string> schoolNO;
    multimap<string,int> NO_result;
    pair<string,int> MAX_result = {"",0};
    int N;
    string NO;
    int result;
    cin>>N;
    for(int i = 0 ; i < N ; i++)
    {
        cin>>NO>>result;
        NO_result.insert({NO,result});
        schoolNO.insert(NO);
    }
    for(auto i : schoolNO)
    {
        int count = 0;
        for(auto pos = NO_result.equal_range(i); pos.first != pos.second; ++pos.first)
            count += pos.first->second;
        if(count > MAX_result.second)
        {
            MAX_result.first = i;
            MAX_result.second = count;
        }
    }
    cout<<MAX_result.first<<" "<<MAX_result.second<<endl;
    return 0;
}
