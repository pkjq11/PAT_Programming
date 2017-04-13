/*
小红想买些珠子做一串自己喜欢的珠串。卖珠子的摊主有很多串五颜六色的珠串，但是不肯把任何一串拆散了卖。于是小红要你帮忙判断一下，某串珠子里是否包含了全部自己想要的珠子？如果是，那么告诉她有多少多余的珠子；如果不是，那么告诉她缺了多少珠子。

为方便起见，我们用[0-9]、[a-z]、[A-Z]范围内的字符来表示颜色。例如在图1中，第3串是小红想做的珠串；那么第1串可以买，因为包含了全部她想要的珠子，还多了8颗不需要的珠子；第2串不能买，因为没有黑色珠子，并且少了一颗红色的珠子
输入格式：

每个输入包含1个测试用例。每个测试用例分别在2行中先后给出摊主的珠串和小红想做的珠串，两串都不超过1000个珠子。

输出格式：

如果可以买，则在一行中输出“Yes”以及有多少多余的珠子；如果不可以买，则在一行中输出“No”以及缺了多少珠子。其间以1个空格分隔。

输入样例1：
ppRYYGrrYBR2258
YrR8RrY
输出样例1：
Yes 8
输入样例2：
ppRYYGrrYB225
YrR8RrY
输出样例2：
No 2
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(int argc, char const *argv[])
{
	string haved;
	string need;
	cin>>haved>>need;
	map<char, int> haved_element;
	map<char, int> need_element;
	for (auto i : haved)
		haved_element[i] += 1;
	for (auto i : need)
		need_element[i] += 1;
	auto need_it = need_element.cbegin();
	auto need_end = need_element.cend();
	int need_num = 0;
	for (; need_it != need_end; ++need_it)
		if (haved_element[need_it->first] < need_it->second)
			need_num += need_it->second - haved_element[need_it->first];
	if(need_num != 0)
		cout<<"No "<<need_num<<endl;
	else cout<<"Yes "<<haved.size()-need.size()<<endl;
	return 0;
}