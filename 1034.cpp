/*
本题要求编写程序，计算2个有理数的和、差、积、商。

输入格式：

输入在一行中按照“a1/b1 a2/b2”的格式给出两个分数形式的有理数，其中分子和分母全是整型范围内的整数，负号只可能出现在分子前，分母不为0。

输出格式：

分别在4行中按照“有理数1 运算符 有理数2 = 结果”的格式顺序输出2个有理数的和、差、积、商。注意输出的每个有理数必须是该有理数的最简形式“k a/b”，其中k是整数部分，a/b是最简分数部分；若为负数，则须加括号；若除法分母为0，则输出“Inf”。题目保证正确的输出中没有超过整型范围的整数。

输入样例1：
2/3 -4/2
输出样例1：
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
输入样例2：
5/3 0/6
输出样例2：
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
*/
#include<iostream>
#include<string>
using namespace std;

//求最大公约数，使用时确保num1和num2都不为0
int GCD(const int &num1, const int &num2)
{
    int m = abs(num1);
    int n = abs(num2);
    int temp;
    if(m<n)
    {
        temp = m;
        m = n;
        n = temp;
    }
    while(n!=0)
    {
        int remainer = m % n;
        m = n;
        n = remainer;
    }
    return m;
}
//求最小公倍数
int LCM(const int &num1,const int &num2)
{
    int gcd = GCD(num1,num2);
    int lcm = num1*num2/gcd;
    return lcm;
}

struct simplest
{
    simplest():integer(0),numerator(0),denominator(0){}
    simplest(const string &num)
    {
        getFromStr(num);
    }
    simplest(istream & in)
    {
        string num;
        in>>num;
        getFromStr(num);
    }
    bool iszero(){return integer==0 && numerator == 0;}
    friend ostream &operator<<(ostream &os,const simplest & num);
    friend simplest operator+(const simplest &num1,const simplest &num2);
    friend simplest operator-(const simplest &num1,const simplest &num2);
    friend simplest operator*(const simplest &num1,const simplest &num2);
    friend simplest operator/(const simplest &num1,const simplest &num2);
private:
    void getFromStr(const string &num);
    void tosimple();
    void tounsimple();
    int integer;
    int numerator;
    int denominator;
};

ostream &operator<<(ostream &os,const simplest & num)
{
    if(num.integer < 0)
    {
        cout<<"("<<num.integer;
        if(num.numerator != 0)
            cout<<" "<<num.numerator<<"/"<<num.denominator<<")";
        else cout<<")";
    }
    else if(num.integer > 0)
    {
        cout<<num.integer;
        if(num.numerator != 0)
            cout<<" "<<num.numerator<<"/"<<num.denominator;
    }
    else
    {
        if(num.numerator <0)
            cout<<"("<<num.numerator<<"/"<<num.denominator<<")";
        else if(num.numerator > 0)
            cout<<num.numerator<<"/"<<num.denominator;
        else cout<<0;
    }
    return os;
}
simplest operator+(const simplest &num1,const simplest &num2)
{
    simplest result,num1_temp = num1,num2_temp = num2;
    if(num1_temp.iszero())
        return num2_temp;
    else if(num2_temp.iszero())
        return num1_temp;
    num1_temp.tounsimple();
    num2_temp.tounsimple();
    int lcm = LCM(num1_temp.denominator,num2_temp.denominator);
    int factor1 = lcm/num1_temp.denominator;
    int factor2 = lcm/num2_temp.denominator;
    result.denominator = num1_temp.denominator = num2_temp.denominator = lcm;
    num1_temp.numerator = num1_temp.numerator * factor1;
    num2_temp.numerator = num2_temp.numerator * factor2;
    result.numerator = num1_temp.numerator + num2_temp.numerator;
    result.tosimple();
    return result;
}
simplest operator-(const simplest &num1,const simplest &num2)
{
    simplest result,num1_temp = num1,num2_temp = num2;
    if(num1_temp.iszero())
    {
        if(num2_temp.iszero())
            return num1_temp;
        else if(num2_temp.integer != 0)
        {
            num2_temp.integer = 0 - num2_temp.integer;
            return num2_temp;
        }
        else{
            num2_temp.numerator = 0 - num2_temp.numerator;
            return num2_temp;
        }
    }
    else if(num2_temp.iszero())
        return num1_temp;
    num1_temp.tounsimple();
    num2_temp.tounsimple();
    int lcm = LCM(num1_temp.denominator,num2_temp.denominator);
    int factor1 = lcm/num1_temp.denominator;
    int factor2 = lcm/num2_temp.denominator;
    result.denominator = num1_temp.denominator = num2_temp.denominator = lcm;
    num1_temp.numerator = num1_temp.numerator * factor1;
    num2_temp.numerator = num2_temp.numerator * factor2;
    result.numerator = num1_temp.numerator - num2_temp.numerator;
    result.tosimple();
    return result;
}
simplest operator*(const simplest &num1,const simplest &num2)
{
    simplest result,num1_temp = num1,num2_temp = num2;
    if(num1_temp.iszero())
        return num1_temp;
    else if(num2_temp.iszero())
        return num2_temp;
    num1_temp.tounsimple();
    num2_temp.tounsimple();
    result.denominator = num1_temp.denominator*num2_temp.denominator;
    result.numerator = num1_temp.numerator*num2_temp.numerator;
    result.tosimple();
    return result;
}
simplest operator/(const simplest &num1,const simplest &num2)
{
    simplest result,num1_temp = num1,num2_temp = num2;
    if(num1_temp.iszero())
        return num1_temp;
    num1_temp.tounsimple();
    num2_temp.tounsimple();
    result.denominator = num1_temp.denominator*num2_temp.numerator;
    result.numerator = num1_temp.numerator*num2_temp.denominator;
    if(result.denominator < 0)
    {
        result.denominator = 0-result.denominator;
        result.numerator = 0-result.numerator;
    }
    result.tosimple();
    return result;
}

void simplest::getFromStr(const string &num)
{
    auto i = num.find('/');
    numerator = stoi(num.substr(0,i));
    denominator = stoi(num.substr(i+1));
    integer = 0;
    if(iszero())
        return;
    int gcd = GCD(numerator,denominator);
    numerator /= gcd;
    denominator /= gcd;
    if(abs(numerator) >= denominator)
    {
        integer = numerator / denominator;
        numerator = abs(numerator) == denominator? 0 : abs(numerator)%denominator;
    }
}
void simplest::tosimple()
{
    if(iszero())
        return;
    int gcd = GCD(numerator,denominator);
    numerator /= gcd;
    denominator /= gcd;
    if(abs(numerator) >= denominator)
    {
        integer = numerator / denominator;
        numerator = abs(numerator) == denominator? 0 : abs(numerator)%denominator;
        if(numerator == 0) denominator = 0;
    }
}
void simplest::tounsimple()
{
    if(integer > 0)
    {
        numerator = numerator == 0 ? integer*denominator:(integer*denominator+numerator);
        integer = 0 ;
    }

    else if(integer < 0)
    {
        numerator = numerator == 0 ? integer*denominator:(integer*denominator-numerator);
        integer = 0;
    }

}


int main(int argc, char *argv[])
{
    simplest num1(cin),num2(cin);
    simplest addresult = num1 + num2;
    cout<<num1<<" + "<<num2<<" = "<<addresult<<endl;
    simplest subresult = num1 - num2;
    cout<<num1<<" - "<<num2<<" = "<<subresult<<endl;
    simplest mulresult = num1 * num2;
    cout<<num1<<" * "<<num2<<" = "<<mulresult<<endl;
    if(num2.iszero())
        cout<<num1<<" / "<<num2<<" = Inf"<<endl;
    else
    {
        simplest divresult = num1/num2;
        cout<<num1<<" / "<<num2<<" = "<<divresult<<endl;
    }

    return 0;
}
