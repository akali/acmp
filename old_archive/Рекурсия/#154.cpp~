#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int n, q, sz;
int a[10];

bool rec (int k, int size)
{
 cerr << k << " " << size << endl;
 if ((k == 0 || k == 1) && size <= 8 && size >= 1)
  return true;
 if (size > 8) return false;
 for (int i = 1; i <= q; i++)
 {
  if (rec (k - (i * i * i), size + 1))
  {
   a[sz++] = i;
  }
 }
 return true;
}

int main ()
{
 cin >> n;
 q = sqrt (double (n));
 //for ()
 if (!rec(n, 0))
  cout << "IMPOSSIBLE";
 else
 {
  for (int i = 0; i < sz; i++)
   cout << a[i] << " ";
 }

 return 0;
}
