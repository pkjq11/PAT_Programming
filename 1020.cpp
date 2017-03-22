/*
月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。现给定所有种类月饼的库存量、总售价、以及市场的最大需求量，请你计算可以获得的最大收益是多少。

注意：销售时允许取出一部分库存。样例给出的情形是这样的：假如我们有3种月饼，其库存量分别为18、15、10万吨，总售价分别为75、72、45亿元。如果市场的最大需求量只有20万吨，那么我们最大收益策略应该是卖出全部15万吨第2种月饼、以及5万吨第3种月饼，获得 72 + 45/2 = 94.5（亿元）。

输入格式：

每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N表示月饼的种类数、以及不超过500（以万吨为单位）的正整数D表示市场最大需求量。随后一行给出N个正数表示每种月饼的库存量（以万吨为单位）；最后一行给出N个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。

输出格式：

对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后2位。

输入样例：
3 20
18 15 10
75 72 45
输出样例：
94.50
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

struct mooncake
{
  int count=0;
  int price=0;
};

bool costly(const mooncake &cake1,const mooncake &cake2)
{
    if(cake1.count == 0)
        return false;
    else if (cake2.count == 0)
        return true;
    else return ((double)cake1.price/cake1.count)>((double)cake2.price/cake2.count)?true:false;
}

int main(int argc, char *argv[])
{
    int N;
    int M_demand;//demand 会是0么？
    int Now_supply=0;
    double total=0;
    cin>>N>>M_demand;
    vector<mooncake> cake_list(N);
    for(auto i = cake_list.begin(); i != cake_list.end(); i++)
        cin>>i->count;
    for(auto i = cake_list.begin(); i != cake_list.end(); i++)
        cin>>i->price;
    sort(cake_list.begin(),cake_list.end(),costly);
    for(auto i = cake_list.begin(); i != cake_list.end()&&Now_supply<M_demand; i++ )
    {
        if (i->count == 0)
            break;
        else if((i->count+Now_supply)>=M_demand)
        {
            total+=(double)(i->price)/(i->count)*(M_demand-Now_supply);
            Now_supply+=M_demand;
        }
        else
        {
            total += i->price;
            Now_supply += i->count;
        }
    }
    cout.setf(ios::fixed);
    cout<<fixed<<setprecision(2)<<total;
    return 0;
}
