#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <cstdio>
 
using namespace std;
 
const int len = 2; 
const char * digitFormat = "%.1d";
int osn = 10;
const int max_size = 6105;
 
struct BigInt
{
    int amount;
    int digits[max_size];
    BigInt()
    {
        memset(digits,0,sizeof(digits));
        amount = 1;
    }
    void input() 
    {
        char str[max_size*len];
        char buf[len];
 
        memset(str,0,sizeof(str));
        gets(str);
        int pos = 0; 
        int size = strlen(str);
        for (int i=size-1;i>=0;i-=len) 
        { 
            memset(buf,0,sizeof(buf));
            int start = i - len + 1; 
            if (start<0) start = 0; 
            strncpy(buf,str+start,i-start+1); 
            digits[pos++] = atoi(buf); 
        } 
        amount = pos; 
    }
    void output() 
    { 
        printf("%d",digits[amount-1]); 
        for (int i= amount-2;i>=0;i--) 
            printf(digitFormat,digits[i]); 
    }
    friend bool operator <= (const BigInt &a, const BigInt &b);
    friend BigInt operator - (const BigInt &a, const BigInt &b);
    friend BigInt operator * (const int &n, const BigInt &a);
    friend BigInt operator * (const BigInt &a, const int &n) ;
 
    void Shift(int pos, int lastDigit)
    {
        for (int i=amount -1 + pos;i>=pos;i--)
            digits[i] = digits[i-pos];
  
        amount += pos;
        if (pos == 1)
            digits[0] = lastDigit;
        if (pos == 2)
        {
            digits[0] = lastDigit%10;
            digits[1] = lastDigit/10;
        }
        while (amount>=1 && !digits[amount])
            amount--;
        amount++;
    }
    BigInt sqrt()
    {
        BigInt ost;
        BigInt curRes;
        for (int i = amount-1;i>=0;i--)
        {
            BigInt A = ost;
            A.Shift(2,digits[i]);
            int curDigit = 0;
  
            int l = 0, r = 9;
            BigInt a = 2*curRes;
            a.Shift(1,0);
            while (l<=r)
            {
                int m = (l + r)>>1;
                a.digits[0] = m;
                if (a*m <= A)
                {
                    curDigit = m;
                    l = m + 1;
                }
                else
                    r = m - 1;
            }
            curRes.Shift(1,curDigit);
            a.digits[0] = curDigit;
            ost = A - curDigit*a;
        }
        return curRes;
    }
};
BigInt operator - (const BigInt &a, const BigInt &b) 
{ 
    BigInt res = a; 
    int r = 0; 
    for (int i = 0;i<res.amount;i++) 
    { 
        res.digits[i] -= b.digits[i] + r; 
        if (res.digits[i]<0) 
        { 
            res.digits[i]+=osn; 
            r = 1; 
        }    
        else
            r = 0; 
    } 
    if (!res.digits[res.amount-1] && res.amount != 1) 
        res.amount--; 
    return res; 
}
BigInt operator * (const int &n, const BigInt &a) 
{ 
    BigInt res; 
    res.amount = a.amount; 
  
    int r = 0; 
    for (int i=0;i<res.amount | r;i++) 
    { 
        res.digits[i] = a.digits[i] * n + r; 
        r = res.digits[i]/osn; 
        res.digits[i] -= r*osn; 
    } 
    if (res.digits[res.amount]) 
        res.amount++; 
  
    return res; 
}
bool operator <= (const BigInt &a, const BigInt &b)
{
    if (a.amount != b.amount)
        return a.amount <= b.amount;
    for (int i=a.amount-1;i>=0;i--)
        if (a.digits[i] != b.digits[i])
            return a.digits[i] <= b.digits[i];
    return true;
}
BigInt operator * (const BigInt &a, const int &n) 
{ 
    BigInt res; 
    res.amount = a.amount; 
  
    int r = 0; 
    for (int i=0;i<res.amount | r;i++) 
    { 
        res.digits[i] = a.digits[i] * n + r; 
        r = res.digits[i]/osn; 
        res.digits[i] -= r*osn; 
    } 
    if (res.digits[res.amount]) 
        res.amount++; 
  
    return res; 
}
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    BigInt a;
    a.input();
    a.sqrt().output();
    return 0;
}
