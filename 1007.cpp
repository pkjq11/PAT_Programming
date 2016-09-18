/*让我们定义 dn 为：dn = pn+1 - pn，其中 pi 是第i个素数。显然有 d1=1 且对于n>1有 dn 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N (< 105)，请计算不超过N的满足猜想的素数对的个数。

输入格式：每个测试输入包含1个测试用例，给出正整数N。

输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。
输入样例：20

输出样例：4
*/
#include <iostream>
#include <math.h>
//理解错了，此处的N指常数N，而不是要找前20个素数对
//int main()
//{
//    int N;
//    std::cin>>N;
//    int *prime = new int[N];
//    prime[0]=2;
//    int pc = 1;
//    int num = 3;
//    int count = 0;
//    while(pc <= N)
//    {
//        int i = 2;
//        for(;i<= (int)sqrt(num);i++)
//        {
//            if(num%i==0)
//                break;
//        }
//        if(i>sqrt(num))
//            prime[pc++]=num;
//        num+=2;
//    }
//    for(int i = 1;i<=N;i++)
//        if(prime[i]-prime[i-1]==2)
//            count++;
//    std::cout<<count<<std::endl;
//    return 0;
//}
int main()
{
    int N;
    std::cin>>N;
    int count = 0;
    int pptr;
    int nptr = 2;
    for(pptr = 3;pptr<=N;pptr+=2)
    {
        int i = 2;
        for(;i<= (int)sqrt(pptr);i++)
        {
            if(pptr%i==0)
             break;
        }
        if(i>sqrt(pptr))
        {
            if(pptr-nptr==2)
                count++;
            nptr=pptr;
        }

    }
    std::cout<<count<<std::endl;
    return 0;
}
