#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<bool> prime(110000, true);
vector<int> iprime(110000),xpos;
int a[600][600],b[600][600];
void make_prime()
{
 prime[0] = prime[1] = false;
  for (int i=2; i*i<=110000; ++i)
   if (prime[i])
     for (int j=i*2; j<=110000; j+=i)
      prime[j] = false;
}

int s(int n)
{
 int r = 0;
 while(n>0)
  r+=n%10,
  n/=10;
 return r;
}

int sdr(int n)
{
 if(prime[n]) return n;
 else
 if(n%10==n) return 0;
 else
 return sdr(s(n));
}

int main()
{
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 int n,m;
 cin>>n;
 make_prime();
 cout<<sdr(n);
 return 0;
}