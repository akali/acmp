#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;

int w[1001];

void generate (int l)
{
 w[0] = 0;
 for (int i = 1; i < l; i++)
  w[i] = rand() % 10;
}

int power (int a, int n)
{
 int res = 1;
 while (n)
 {
  if (n & 1)
   res *= a;
  a *= a;
  n >>= 1;
 }
 return res;
}

bool chk (int x, int m, int l, int v)
{
 int q = 0;
 for (int i = 0; i < l; i++)
 {
  q = q + (w[i] * power(x, i));
 }
 q %= m;
 if (q == v) return true;
 return false;
}

void print(int l)
{
 for (int i = 0; i < l; i++)
  cout << w[i];
}

int main ()
{
 freopen ("input.txt", "r", stdin);
 freopen ("output.txt", "w", stdout);
 int x, m, L, v;

 cin >> x >> m >> L >> v;
 for (int i = 0; i < 99999; i++)
 {
  generate(L);
  if (chk (x, m, L, v))
  {
   print(L);
   return 0;
  }
 }
 cout << "NO SOLUTION";
 return 0;
}
