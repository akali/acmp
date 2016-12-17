#include <iostream>
#include <fstream>
using namespace std;
  
int n, m, k;
long long d[20][(1<<11)], ans;
char a[20][20];

void rec (int i, int mask, int j)
{
 //cout << i << " " << mask << " " << j << endl;
 if (i < n)
 {
  if (mask - 1 < (1 << m))
  {
   d[i + 1][mask] += d[i][mask];
   if (j < m)
   {
    int p = 1 << (j - 1);
    if (!(mask & p) && a[i][j] == 'Y') 
     d[i][mask + p] += d[i - 1][mask]; 
    rec (i, mask, j + 1);
   }
   else
    rec (i, mask + 1, 1);
  }
  else
   rec (i + 1, 0, 1);
 }
 else
  return;
}

void get (int mask)
{
 cout << d[n][mask] << " ";
 if (mask == (1 << m))
  return;
 if (__builtin_popcount(mask) == k)
  ans += d[n][mask];
 get (mask + 1);
}

int main ()
{
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    cin >> n >> m >> k;
    for (int i = 1; i < n; i ++ )
        for (int j = 1; j < m; j ++ )
            cin >> a[i][j];
    d[0][0] = d[1][0] = 1;
    rec (1, 1, 0);
    get(0);
    cout << ans;
    return 0;
} 
