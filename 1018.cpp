/*
现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：

输入第1行给出正整数N（<=105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。

输出格式：

输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，则输出按字母序最小的解。

输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
输出样例：
5 3 2
2 3 5
B B
*/
#include <iostream>
#include <map>
using namespace std;
int judge(char &x,char &y)
{
    if(x == 'C')
        return y=='C'?0:y=='J'?1:-1;
    else if (x == 'J')
        return y=='J'?0:y=='B'?1:-1;
    else return y == 'B'?0:y=='C'?1:-1;
}

int main(int argc, char *argv[])
{
    int time;
    cin>>time;
    map<char,int> gesture;
    gesture.insert({'C',0});
    gesture.insert({'J',1});
    gesture.insert({'B',2});
    int i = 0;
    char A,B;
    int A_WIN[3]{0,0,0};
    int B_WIN[3]{0,0,0};
    while(i<time)
    {
        cin>>A>>B;
        if(judge(A,B)==1)
            A_WIN[gesture[A]]++;
        else if(judge(A,B)== -1)
                 B_WIN[gesture[B]]++;
        i++;
    }
    int A_time = A_WIN[0]+A_WIN[1]+A_WIN[2];
    int B_time = B_WIN[0]+B_WIN[1]+B_WIN[2];
    cout<<A_time<<" "<<time-A_time-B_time<<" "<<B_time<<endl;
    cout<<B_time<<" "<<time-A_time-B_time<<" "<<A_time<<endl;
    if(A_WIN[2]>=A_WIN[1]&&A_WIN[2]>=A_WIN[0])
        cout<<'B'<<" ";
    else if(A_WIN[0]>A_WIN[2]&&A_WIN[0]>=A_WIN[1])
        cout<<'C'<<" ";
    else if(A_WIN[1]>A_WIN[0]&&A_WIN[1]>A_WIN[2])
        cout<<'J'<<" ";
    if(B_WIN[2]>=B_WIN[1]&&B_WIN[2]>=B_WIN[0])
        cout<<'B'<<endl;
    else if(B_WIN[0]>B_WIN[2]&&B_WIN[0]>=B_WIN[1])
        cout<<'C'<<endl;
    else if(B_WIN[1]>B_WIN[0]&&B_WIN[1]>B_WIN[2])
        cout<<'J'<<endl;
    return 0;
}
