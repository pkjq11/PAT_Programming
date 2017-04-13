/*
奇怪了本题要求读入N名学生的成绩，将获得某一给定分数的学生人数输出。

输入格式：

输入在第1行给出不超过105的正整数N，即学生总人数。随后1行给出N名学生的百分制整数成绩，中间以空格分隔。最后1行给出要查询的分数个数K（不超过N的正整数），随后是K个分数，中间以空格分隔。

输出格式：

在一行中按查询顺序给出得分等于指定分数的学生人数，中间以空格分隔，但行末不得有多余空格。

输入样例：
10
60 75 90 55 75 99 82 90 75 50
3 75 90 88
输出样例：
3 2 0
*/
#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main(int argc, char *argv[])
{
    map<int,int> score;
    int stu_num;
    cin>>stu_num;
    for(int i = 0;i < stu_num; i++)
    {
        int temp;
        cin>>temp;
        score[temp] += 1;
    }
    int search_num;
    cin>>search_num;
    vector<int> search_cache;
    for(int i = 0; i < search_num; i++)
    {
        int temp;
        cin>>temp;
        search_cache.push_back(temp);
    }
    for(int i = 0; i < search_num - 1; i++)
        cout<<score[search_cache[i]]<<" ";
    cout<<score[search_cache[search_num-1]];
    return 0;
}
