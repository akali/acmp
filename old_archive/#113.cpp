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
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}                        
}

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	// clock_t tClock = clock();
	long long Maxx = -(1 << 30);
	//scanf ("%d", &n);
	ios      :: sync_with_stdio (false);
	ios_base :: sync_with_stdio (false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char q; cin >> q;
			// cin >> a[i][j];                                                                      
			// scanf ("%c", &q);
			a[i][j] = bool (q - '0');
			d[i][j] = (d[i - 1][j] + d[i][j - 1]) - d[i - 1][j - 1] + a[i][j];
		}
	}
	
	// output ();
	// cout << endl << endl << endl;
	
	for (int x1 = 1; x1 <= n; x1++) {
		for (int y1 = 1; y1 <= n; y1++) {
			// int y1 = x1;
			for (int k = 0; k + min (x1, y1) <= n; k++) {
				int x2 = x1 + k, y2 = y1 + k;
				long long d = take (x1, y1, x2, y2);
				if (d == ((x2 - x1) + 1) * ((y2 - y1) + 1))
					Maxx = max (Maxx, d);
				else
					break;
				// cout << Maxx << endl;
			}
		}
		/*if (((double)(clock() - tClock) / 1000) > 0.96) {
			printf ("%lld", Maxx);
			return 0;
		}*/
	}
	// printf ("%lld", Maxx);
	cout << Maxx;
	// cout << take (1, 1, 2, 2);
	return 0;
}
