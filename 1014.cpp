/*
大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。
大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中第1对相同的大写英文字母（大小写有区分）
是第4个字母'D'，代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、以及
大写字母A到N表示）；后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。现给定两对字符串，
请帮助福尔摩斯解码得到约会的时间。

输入格式：

输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。

输出格式：

在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。

输入样例：
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
输出样例：
THU 14:04
*/
#include <iostream>
#include <string>
#include <vector>
#define MAX(a,b) (a>b?a:b)

#define MIN(a,b) (a<b?a:b)

using namespace std;

int main(int argc, char const *argv[])
{
	string str1,str2,str3,str4;
	cin>>str1>>str2>>str3>>str4;
	decltype(str1.size()) length1 = MAX(str1.size(),str2.size());
	decltype(str1.size()) length2 = MAX(str3.size(),str3.size());
	string week[7]{"MON","TUE","WED","THU","FRI","SAT","SUN"};
	bool day = false;
	for (decltype(str1.size()) i = 0; i < length1; ++i)
	{
		if (str1[i] != str2[i])
			continue;
		else if(!day)
		{
            if (str1[i]<'A'||str1[i]>'G')
				continue;
			else 
				{
                    cout<<week[str1[i]-'A']<<" ";
					day = true;
				}
		}
		else
		{
			if (str1[i]>='0'&&str1[i]<='9')
			{
				cout<<'0'<<str1[i]-'0'<<":";
				break;
			}
			else if (str1[i]>='A'&&str1[i]<='N')
			{
				cout<<10+str1[i]-'A'<<":";
				break;		
			}
			else continue;
		}
	}
	for (decltype(str3.size()) i = 0; i < length2; ++i)
	{
        if ((str3[i] != str4[i])||!((str3[i]>='A'&&str3[i]<='Z')||(str3[i]>='a'&&str3[i]<='z')))
			continue;
        else
		{
			if(i<=9)
				cout<<'0'<<i<<endl;
			else cout<<i;
			break;
		}

	}


	return 0;
}
