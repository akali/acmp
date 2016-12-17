# include <cstdio>
# include <iostream>

using namespace std;

double d[1001], p[1001], q[1001];

int main ()
{
 freopen ("input.txt" , "r",  stdin);
 freopen ("output.txt", "w", stdout);
 int n;
 cin >> n;

 for (int i = 0; i < n; i++)
 {
  double x, y;
  cin >> x >> y;
  if (i != 0)
  {
   d[i] = max(max(p[i - 1] * x, q[i - 1] * y), d[i - 1]);
   p[i] = max(d[i - 1] / x, p[i - 1]);
   q[i] = max(d[i - 1] / y, q[i - 1]);
  }
  else
  {
   d[i] = 100;
   p[i] = max(d[i] / x);//, d[i] / y);
   q[i] = max(d[i] / y);//, d[i] / x);//d[0] / y;
  }
 }
 printf("%.2f", d[n - 1]);
 return 0;
}
