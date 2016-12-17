#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
 
using namespace std;

long long d[2][65][65];
bool calced[2][65][65];
int a[65], sz = 0, l, r;

void ClearIt ()
{
 for (int j = 0; j < 2; j++)
  for (int k = 0; k < 65; k++)
   for (int l = 0; l < 65; l++)
    d[j][k][l] = 0, calced[j][k][l] = 0;
}

long long go (bool sp, int pos, int Sum)
{
 //cout << was << " " << sp << " " << pos << " " << Sum << endl;
 if (pos == sz) {
  return Sum;
 }
 if (calced[sp][pos][Sum])
  return d[sp][pos][Sum];
 calced[sp][pos][Sum] = true;
 long long res = 0;
 if (sp)
  for (int i = 0; i <= a[pos]; i++)
  	res += go (a[pos] == i, pos + 1, Sum + (i == 5));
 else
  for (int i = 0; i <= 9; i++)
  	res += go (0, pos + 1, Sum + (i == 5));
 return d[sp][pos][Sum] = res;
}

long long calculate (long long k) {
 ClearIt();
 sz = 0;
 while (k > 0) {
  a[sz++] = k % 10;
  k /= 10;
 }
 reverse (a, a + sz);
 return go (1, 0, 0);
}

int main () {
 freopen ("input.txt", "r", stdin);
 freopen ("output.txt", "w", stdout);
 long long l, r;
 cin >> r;
 l = 0;
 long long a = calculate (r), b = calculate (l - 1);
 if (l == 0)
 	b--;
 cout << a << endl;
 return 0;
}
