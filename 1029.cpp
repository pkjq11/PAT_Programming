/*
旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及实际被输入的文字，请你列出肯定坏掉的那些键。

输入格式：

输入在2行中分别给出应该输入的文字、以及实际被输入的文字。每段文字是不超过80个字符的串，由字母A-Z（包括大、小写）、数字0-9、以及下划线“_”（代表空格）组成。题目保证2个字符串均非空。

输出格式：

按照发现顺序，在一行中输出坏掉的键。其中英文字母只输出大写，每个坏键只输出一次。题目保证至少有1个坏键。

输入样例：
7_This_is_a_test
_hs_s_a_es
输出样例：
7TI
*/
#include<iostream>
#include<string>
#include<set>
using namespace std;

int main(int argc, char *argv[])
{
    string text,input;
    getline(cin,text);
    getline(cin,input);
    string bad_key="";
    auto text_ptr = text.begin();
    auto input_ptr = input.begin();
    auto text_end = text.end();
    auto input_end = input.end();
    while(text_ptr != text_end)
    {
        if(*input_ptr != *text_ptr)
        {
            char temp = toupper(*text_ptr);
            if(bad_key.find(temp) == string::npos)
                bad_key+=temp;
            text_ptr++;
        }
        else
        {
            text_ptr++;
            input_ptr++;
        }
    }
    for(auto i : bad_key)
        cout<<i;
    return 0;
}
