# include <iostream>
# include <cstdio>

using namespace std;

int d[1000500];

int main ()
{
 freopen ("input.txt", "r", stdin);
 freopen ("output.txt", "w", stdout);
 long long k, p;
 cin >> k >> p;
 if (p == 1)
 {
  cout << 0;
  return 0;
 }
 d[0] = d[1] = 0;
 d[2] = 1;
 for (unsigned int i = 3; i <= k; i++)
 {
  d[i] = (i & 1 ? d[i - 1] : d[i - 1] + d[i / 2] ) % p;
 }
 cout << d[k] % p;
 return 0;
}
