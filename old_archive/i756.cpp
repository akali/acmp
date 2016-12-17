# include <iostream>
# include <cstdio>
# include <cstdlib>

using namespace std;

#define MAXN 150000

int f[MAXN * 4 + 1], a[MAXN], n;

void build (int i, int tl, int tr)
{
 if (tl == tr) f[i] = a[tl];

 if (tl > tr) return;

 int tm = (tl + tr) >> 1;
 build (i + i, tl, tm);
 build (i + i + 1, tm + 1, tr);
 f[i] = min(f[i + i], f[i + i + 1])
}

int GetMin ()
{
 int res = 0;

 for (int i = r; i >= 0; i = (i & (i + 1)) - 1)
  res += f[i];

 return res;
}

int get (int l, int r)
{
 return get (r) - get (l - 1);
}

int main ()
{
 int k;
 cin >> n >> k;
 for (int i = 0; i < n; i++)
 {
  cin >> a[i];
  upd (i, a[i]);
  cout << "TEST " << i << " PASSED" << endl;
 }
 for (int i = 0; i + k < n; i++)
 {
  cout << get (i, i + k) << endl;
 }
}
