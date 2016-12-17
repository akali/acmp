#include <iostream>
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#include <cmath>
#include <cstdio>
using namespace std;
const int N = 1004;
const int INF = 1000000009;
int n, total = 0;

int num[N], num1[N], prime[N], indexPrime[N];
bool isPrime[N];

void MP()
{
 FOR(i,100,999)
 {
  int q = 1;
  FOR(j,2,i-1)
   if (i % j == 0)
    q = 0;
   if (q)
   {
    total++;
    prime[total] = i;
    num[total] = 1;
    isPrime[i] = true;
    indexPrime[i] = total;
   }
  }
 }
 void solve()
 {
  MP();
  FOR(i,4,n)
  { 
   FOR(j,1,total)
   { 
    if (num[j] != 0)
    {
     int ch = (prime[j] % 100) * 10;
     FOR(k,1,9)
       if (isPrime[ch + k])
        num1[indexPrime[ch + k]] = (num1[indexPrime[ch + k]] + num[j]) % INF;
     }
   }
   FOR(i,1,total)
   {
    num[i] = num1[i];
    num1[i] = 0;
   }
  }
  int ans = 0;
  FOR(i,1,total) 
  ans = (ans + num[i]) % INF;
  cout << ans << endl;
 }
 int main()
 {
  freopen ("input.txt", "r", stdin);
  freopen ("output.txt", "w", stdout);
  cin >> n;
  solve();
  return 0;
 }