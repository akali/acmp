# include <iostream>
# include <cmath>
# include <algorithm>

using namespace std;

int n, d[1001];
int f1, f2 = 1, i1, i2;
int a1, a2;

int main ()
{
 freopen ("input.txt",  "r",  stdin);
 freopen ("output.txt", "w", stdout);
 cin >> n;
 for (int i = 0; i < n; i++)
 {
  cin >> d[i];
  if (d[i] > 0) f1 += d[i];
 }
 int i1 = min_element(&d[0], &d[n]) - d, i2 = max_element(&d[0], &d[n]) - d;
 if (i1 > i2) swap (i1, i2);
 for (int i = i1 + 1; i < i2; i++) f2 *= d[i];//, cout << d[i] << " "; cout << endl;
 //cout << i1 << " " << i2 << endl;
 cout << f1 << " " << f2;
 return 0;
}
