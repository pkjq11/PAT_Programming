/*
本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A = B * Q + R成立。

输入格式：

输入在1行中依次给出A和B，中间以1空格分隔。

输出格式：

在1行中依次输出Q和R，中间以1空格分隔。

输入样例：
123456789050987654321 7
输出样例：
17636684150141093474 3
*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int main(int argc, char *argv[])
{
    string A;
    string result;
    char B;
    cin>>A>>B;
    stringstream result_digital("");
    int A_digital = 0;
    int B_digital = B-'0';
    int temp_digital = 0;
    for(decltype(A.size()) i = 0;i < A.size(); i++ )
    {
        A_digital = A_digital*10+(A[i]-'0');
        while(A_digital>=B_digital)
        {
            A_digital -= B_digital;
            temp_digital++;
        }
        result_digital<<temp_digital;
        temp_digital = 0;
    }
    result = result_digital.str();
    decltype(result.find_first_not_of('0')) i = 0;
    if(result.size()>1)
        i = result.find_first_not_of('0');
    cout<<result.substr(i)<<" "<<A_digital;
    return 0;
}

