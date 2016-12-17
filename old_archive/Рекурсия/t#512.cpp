#include <iostream>
#include <fstream>
using namespace std;
  
int n,m,k,i,j,mask,ans,len,x;
long long d[20][(1<<11)];
char a[20][20];
  
int main ()
{
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
  
    cin >> n >> m >> k;
  
    for (i = 1; i <= n; i ++ )
        for (j = 1; j <= m; j ++ )
            cin >> a[i][j];
      
  
    d[0][0] = d[1][0] = 1;
  
    for (i = 1; i <= n; i ++ ) {
            for (mask = 0; mask < (1 << m); mask ++ ) {
                d[i + 1][mask] += d[i][mask];
                for (j = 1; j <= m; j ++ )
                {
		    cout << i << " " << mask << " " << j << endl;
                    int p = 1 << (j - 1);
                    if (!(mask & p) && a[i][j] == 'Y') 
                     d[i][mask + p] += d[i - 1][mask];
                }
            }
    }
  
    for (mask = 0; mask < (1 << m); mask ++ ) {
        len = 0 ; x = mask;
		len = __builtin_popcount(x);
        if (len == k) ans += d[n][mask];
    }
  
    cout << ans;
  
    return 0;
} 
