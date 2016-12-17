#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN = 111;
long long f[MAXN][MAXN], a[MAXN][MAXN];
long long q = 1 << 30;

int main()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j], q = min (q, a[i][j]);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] += a[i][j - 1];

	long long Res = -1 << 30;

	for (int i = 1; i <= n; i++)
		for (int j = i; j <= m; j++)
		{
			long long sum = 0ll;
			for (int k = 1; k <= n; k++)
			{
				sum += a[k][j] - a[k][i - 1];
				Res = max (Res, sum);
				sum = max (0ll, sum);
			}
		}
	cout << Res << endl;
	return 0;
}
