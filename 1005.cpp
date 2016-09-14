/*
卡拉兹(Callatz)猜想已经在1001中给出了描述。在这个题目里，情况稍微有些复杂。

当我们验证卡拉兹猜想的时候，为了避免重复计算，可以记录下递推过程中遇到的每一个数。例如对n=3进行验证的时候，我们需要计算3、5、8、4、2、1，
则当我们对n=5、8、4、2进行验证的时候，就可以直接判定卡拉兹猜想的真伪，而不需要重复计算，因为这4个数已经在验证3的时候遇到过了，我们称5、8、4、2
是被3“覆盖”的数。我们称一个数列中的某个数n为“关键数”，如果n不能被数列中的其他数字所覆盖。

现在给定一系列待验证的数字，我们只需要验证其中的几个关键数，就可以不必再重复验证余下的数字。你的任务就是找出这些关键数字，并按从大到小的顺序输出它们。

输入格式：每个测试输入包含1个测试用例，第1行给出一个正整数K(<100)，第2行给出K个互不相同的待验证的正整数n(1<n<=100)的值，数字间用空格隔开。

输出格式：每个测试用例的输出占一行，按从大到小的顺序输出关键数字。数字间用1个空格隔开，但一行中最后一个数字后没有空格。
输入样例：6
3 5 6 7 8 11

输出样例：7 6

*/
#include <QCoreApplication>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
void Callatz(int& x, std::set<int>& m_cov,std::set<int>& m_key)
{
    while (x != 1)
    {
        if (x % 2 == 0)
            x = x / 2;
        else x = (3 * x + 1) / 2;
        if (m_cov.find(x) == m_cov.end())
        {
            m_cov.insert(x);
            m_key.erase(x);
        }
        else
            break;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int N;
    std::cin >> N;
    int *num = new int[N];
    for (int i = 0;i < N;i++)
        std::cin >> num[i];
    std::set<int> cover;
    std::set<int> key;
    for (int i = 0;i < N;i++)
    {
        if (cover.find(num[i]) == cover.end())
        {
            key.insert(num[i]);
            Callatz(num[i], cover,key);
        }
        else
            continue;
    }
    for (std::set<int>::iterator it = --key.end();it != key.begin();--it)
    {
        std::cout << *it << " ";
    }
    std::cout << *key.begin() << std::endl;
    system("pause");
    return a.exec();
}
