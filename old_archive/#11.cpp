# include <bits/stdc++.h>

using namespace std;

int d[333][333];
int k, n;

void print()
{
 for (int i = 1; i <= k; i++, cout << endl)
  for (int j = 1; j <= n; j++, cout << d[i][j] << " ");
}

void mf()
{
 for (int i = 0; i <= k; i ++)
 {
  for (int j = 4; j <= n; j ++)
  {
   int q = 0;
   for (int p = j - i - 1; p <= j; p ++)
   {
    q += d[i][p];
   }
   d[j][i] = q;
  }
 }
}

int main ()
{
 k = 5, n = 10;
 //cin >> k >> n;
 
 for (int i = 1; i <= n; i++)
 {
  d[1][i] = 1;
  d[i][2] = 1;
  d[i][3] = 2;
  d[0][i] = 1;
  d[i][0] = 1;
 }
 //d[1][2] = 1;
 
 mf();
 print();
 cout << d[k][n] << endl;
 return 0;
}
