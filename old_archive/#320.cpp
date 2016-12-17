#include <iostream>
#include <cstdio>

using namespace std;

int d[100], n, m;

int main ()
{
 cin >> n >> m;
 for (int i = 1; i <= n; i++)
 {
  d [i] = (i >= m ? d[i - 1] + d[i - m] : 1);
 }
 cout << d[n];
 return 0;
}