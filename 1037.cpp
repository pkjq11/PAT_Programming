/*
如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 —— 就如海格告诉哈利的：“十七个银西可(Sickle)兑一个加隆(Galleon)，二十九个纳特(Knut)兑一个西可，很容易。”现在，给定哈利应付的价钱P和他实付的钱A，你的任务是写一个程序来计算他应该被找的零钱。

输入格式：

输入在1行中分别给出P和A，格式为“Galleon.Sickle.Knut”，其间用1个空格分隔。这里Galleon是[0, 107]区间内的整数，Sickle是[0, 17)区间内的整数，Knut是[0, 29)区间内的整数。

输出格式：

在一行中用与输入同样的格式输出哈利应该被找的零钱。如果他没带够钱，那么输出的应该是负数。

输入样例1：
10.16.27 14.1.28
输出样例1：
3.2.1
输入样例2：
14.1.28 10.16.27
输出样例2：
-3.2.1
*/
#include <iostream>
#include <string>
using namespace std;

class money
{
public:
	money():galleon(0),sickle(0),knut(0),flag(true){}
	money(string &str);
	money(istream &in);
	friend money operator-(const money &payed,const money &price);
	friend ostream &operator<<(ostream &os,const money &mymoney);
	friend bool operator<(const money &money1,const money &money2);

private:
	int galleon;
	int sickle;
	int knut;
	bool flag;
	void getmoney(string &str);
};

void money::getmoney(string &str)
{
	auto i = str.find('.');
	auto j = str.rfind('.');
	galleon = stoi(str.substr(0,i));
	sickle = stoi(str.substr(i+1,j-i));
	knut = stoi(str.substr(j+1));
	flag = true;
}

money::money(string &str)
{
	getmoney(str);
}

money::money(istream &in)
{
	string price;
	in>>price;
	getmoney(price);
}

bool operator<(const money &money1,const money &money2)
{
	if (money1.galleon==money2.galleon)
	{
		if (money1.sickle == money2.sickle)
		{
			if (money1.knut < money2.knut)
				return true;
		}
		else if (money1.sickle < money2.sickle)
			return true;
	}
	else if (money1.galleon < money2.galleon)
		return  true;
	return false;
}

ostream &operator<<(ostream &os,const money &mymoney)
{
	if (mymoney.flag)
		os<<mymoney.galleon<<'.'<<mymoney.sickle<<'.'<<mymoney.knut;
	else
		os<<'-'<<mymoney.galleon<<'.'<<mymoney.sickle<<'.'<<mymoney.knut;
	return os;
}

money operator-(const money &payed,const money &price)
{
	money result;
	money temp=payed;
	if (payed < price)
	{
		result.knut = price.knut - payed.knut;
		result.sickle = price.sickle - payed.sickle;
		result.galleon = price.galleon - payed.galleon;
		result.flag = false;
		if (result.knut < 0)
		{
			result.sickle -= 1;
			result.knut += 29;
		}
		if (result.sickle < 0)
		{
			result.galleon -= 1;
			result.sickle += 17;
		}
	}
	else 
	{
		result.knut = payed.knut - price.knut;
		result.sickle = payed.sickle - price.sickle;
		result.galleon = payed.galleon - price.galleon;
		if (result.knut < 0)
		{
			result.sickle -= 1;
			result.knut += 29;
		}
		if (result.sickle < 0)
		{
			result.galleon -= 1;
			result.sickle += 17;
		}
	}
	return result;
}

int main(int argc, char const *argv[])
{
	money price(cin),payed(cin);
	money result = payed - price;
	cout<<result<<endl;
	return 0;
}