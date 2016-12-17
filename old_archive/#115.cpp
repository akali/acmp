#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int MaxN = 111;

int a[MaxN][MaxN];
long long d[MaxN][MaxN];
int n, m;

long long take (int x1, int y1, int x2, int y2) {
	return (d[x2][y2] - (d[x2][y1 - 1] + d[x1 - 1][y2])) + d[x1 - 1][y1 - 1];
} 

void output () {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			cout << d[i][j] << " ";
		}
		cout << endl;
	}                        
}

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	long long Maxx = -(1 << 30);
	scanf ("%d%d", &n, &m);
	// cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf ("%d", &a[i][j]);
			// cin >> a[i][j];
			long long p = a[i][j];
			Maxx = max (p, Maxx);
			d[i][j] = (d[i - 1][j] + d[i][j - 1]) - d[i - 1][j - 1] + a[i][j];
		}
	}
	
	// output ();
	// cout << endl << endl << endl;
	
	for (int x1 = 1; x1 <= n; x1++) {
		for (int y1 = 1; y1 <= m; y1++) {
	        for (int x2 = x1; x2 <= n; x2++) {
				for (int y2 = y1; y2 <= m; y2++) {
					Maxx = max (Maxx, take (x1, y1, x2, y2));
					// cout << take (x1, y1, x2, y2) << " " << Maxx << endl;
				}
			}
		}
	}

	printf ("%lld", Maxx);
	// cout << Maxx;
	// cout << take (1, 1, 2, 2);
	return 0;
}
