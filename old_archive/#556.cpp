#include <iostream>
#include <cstdio>

using namespace std;

int n,c,m;

int main()
{
 freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
 int n;
 double d[1001], ans = 0; 
 cin >> n;
 d[0] = 1;
 for (int i = 1; i <= n; i++) cin >> d[i], ans *= (d[i] * d[i - 1]) + ((1 - d[i]) * d[i]);

 cout << ans << endl;
 return 0;
}

