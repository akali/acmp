#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MaxN = 1111;

bool a[MaxN][MaxN];
long long d[MaxN][MaxN];
int n, m;

long long take (int x1, int y1, int x2, int y2) {
	return (d[x2][y2] - (d[x2][y1 - 1] + d[x1 - 1][y2])) + d[x1 - 1][y1 - 1];
} 

void output () {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << d[i][j] << " ";
		}
		cout << endl;
	}                        
}

long long takeArea (int x1, int y1, int x2, int y2) {
	return ((x2 - x1) + 1) * ((y2 - y1) + 1);
}

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	// clock_t tClock = clock();
	long long Maxx = 0ll;
	//scanf ("%d", &n);
	ios      :: sync_with_stdio (false);
	ios_base :: sync_with_stdio (false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char q; cin >> q;
			a[i][j] = bool (q - '0');
			d[i][j] = (d[i - 1][j] + d[i][j - 1]) - d[i - 1][j - 1] + a[i][j];
		}
	}
	// output();
	// cout << endl << endl;	
	for (int x1 = 1; x1 <= n; x1++) {
		for (int y1 = 1; y1 <= m; y1++) {
			if (!a[x1][y1])
				continue;
			for (int x2 = x1; x2 <= n; x2++) {
				for (int y2 = y1; y2 <= m; y2++) {
					if (!a[x2][y2])
						break;
					if (take (x1, y1, x2, y2) == takeArea (x1, y1, x2, y2)) {
						Maxx = max (Maxx, take (x1, y1, x2, y2));
					} else {
						if (take (x1, y1, x2, y2 + 1) != takeArea (x1, y1, x2, y2 + 1)) {
							goto EndY2;
						} else {
							if (take (x1, y1, x2 + 1, y2) != takeArea (x1, y1, x2 + 1, y2)) {
								goto EndX2;
							} else {
								if (take (x1, y1 + 1, x2, y2) != takeArea (x1, y1 + 1, x2, y2)) {
									goto EndY1;
								}
							}
						}
					}
				}
				EndY2:;
			}
			EndX2:;
		}
		EndY1:;
	}
	cout << Maxx;
	return 0;
}
