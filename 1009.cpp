/*
给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。
输入格式：测试输入包含一个测试用例，在一行内给出总长度不超过80的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用1个空格分开，输入保证句子末尾没有多余的空格。
输出格式：每个测试用例的输出占一行，输出倒序后的句子。
输入样例：
Hello World Here I Come
输出样例：
Come I Here World Hello
*/
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
int main()
{
    std::string in_str,temp;
    getline(std::cin,in_str);
    std::vector<std::string> out_str;
    std::stringstream str(in_str);
    while(str>>temp)
        out_str.push_back(temp);
    for(auto t = out_str.end()-1;t != out_str.begin();t--)
        std::cout<<*t<<" ";
    std::cout<<out_str.at(0);
    return 0;
}
