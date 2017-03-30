/*
一个合法的身份证号码由17位地区、日期编号和顺序编号加1位校验码组成。校验码的计算规则如下：

首先对前17位数字加权求和，权重分配为：{7，9，10，5，8，4，2，1，6，3，7，9，10，5，8，4，2}；然后将计算的和对11取模得到值Z；最后按照以下关系对应Z值与校验码M的值：

Z：0 1 2 3 4 5 6 7 8 9 10
M：1 0 X 9 8 7 6 5 4 3 2

现在给定一些身份证号码，请你验证校验码的有效性，并输出有问题的号码。

输入格式：

输入第一行给出正整数N（<= 100）是输入的身份证号码的个数。随后N行，每行给出1个18位身份证号码。

输出格式：

按照输入的顺序每行输出1个有问题的身份证号码。这里并不检验前17位是否合理，只检查前17位是否全为数字且最后1位校验码计算准确。如果所有号码都正常，则输出“All passed”。

输入样例1：
4
320124198808240056
12010X198901011234
110108196711301866
37070419881216001X
输出样例1：
12010X198901011234
110108196711301866
37070419881216001X
输入样例2：
2
320124198808240056
110108196711301862
输出样例2：
All passed
*/
#include<iostream>
#include<map>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

int main(int argc, char *argv[])
{
    int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    map<int,char> Z2M = {{0,'1'},{1,'0'},{2,'X'},{3,'9'},{4,'8'},{5,'7'},{6,'6'},{7,'5'},{8,'4'},{9,'3'},{10,'2'}};
    int N;
    cin>>N;
    vector<string> badID;
    string ID;
    for(int i = 0; i < N; i++)
    {
        cin>>ID;
        int sum = 0;
        for(size_t j = 0; j < 17; j++)
        {
            if(ID[j]>='0'&&ID[j]<='9')
            {
                int temp = stoi(ID.substr(j,1));
                sum+=temp*weight[j];
            }
            else
            {
                badID.push_back(ID);
                break;
            }
        }
        int Z = sum%11;
        if(ID[17] != Z2M[Z])
            badID.push_back(ID);
    }
    if(badID.empty())
        cout<<"All passed"<<endl;
    else
        for(auto i : badID)
            cout<<i<<endl;
    return 0;
}