#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <string.h>
 
using namespace std;
const int max_size = 15;
int osn = 1000;
char* format = "%.3d";
struct BigInt
{
    int amount;
    int digits[max_size];
    BigInt()
    {
        memset(digits,0,sizeof(digits));
        amount = 1;
    }
    BigInt(int n)
    {
        memset(digits,0,sizeof(digits));
        amount = 1;
        digits[0] = n;
    }
    void output()
    {
        printf("%d",digits[amount-1]);
        for (int i=amount-2;i>=0;i--)
            printf(format,digits[i]);
    }
};
BigInt operator + (const BigInt &a, const BigInt &b)
{
    BigInt res;
    res.amount = max(a.amount, b.amount);
    int r = 0;
    for (int i=0;i<res.amount || r;i++)
    {
        res.digits[i] = a.digits[i] + b.digits[i] + r;
        if (res.digits[i] >= osn)
        {
            res.digits[i] -= osn;
            r = 1;
        }
        else
            r = 0;
    }
    if (res.digits[res.amount])
        res.amount++;
    return res;
}
int n;
string str;
vector<BigInt> mas;
void input()
{
    cin>>str;
    str.insert(str.begin(),'*');
}
bool isCorrect(char a, char b)
{
    int num = 10*(a - '0') + b - '0';
    return 10<=num && num<=33;
}
void solve()
{
    mas.resize(str.size());
    mas[0] = 1;
    mas[1] = 1;
    for (size_t i=2;i<mas.size();i++)
    {
        mas[i] = mas[i] +  mas[i-1];
        if (isCorrect(str[i-1],str[i]))
            mas[i] = mas[i] + mas[i-2];
    }
    mas.back().output();
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
   
    input();
    solve();
    return 0;
}
