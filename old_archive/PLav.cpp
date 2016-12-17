#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long long d[1111][10];

int main()
{
 int n;
 cin >> n;
 d[1][0] = 0;
 for (int i = 0; i < 9; i++)
  d[1][i] = 1;

 for(int i = 2; i <= n; i++)
 {
  for(int j = 1; j <= 8; j++)
  {
   d[i][j] = d[i - 1][j] + d[i - 1][j - 1] + d[i - 1][j + 1];
   d[i][0] = d[i - 1][0] + d[i - 1][1];
   d[i][9] = d[i - 1][9] + d[i - 1][8];
  }
 }
 long long ans = 0;
 for (int i = 0; i <= 9; i++)
  ans += d[n][i];

 cout << ans;

 return 0;
}
