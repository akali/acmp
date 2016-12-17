#include <bits/stdc++.h>

using namespace std;

int main () {
	//freopen ("output.txt", "w", stdout);
	int res = 0;
	const int n = 4;
	const int m = 3, k = 2;
	int a[n];
	for (int i = 1; i <= n; i++) {
		a[i] = i;
	}
	do {
		int x = 0;
		for (int i = 1; i <= m; ++i) {
			if (a[i] == i) {
				x++;
			}
		}
		//cout << x << " ";
		if (x == k) {
			for (int i = 1; i <= n; ++i) {
				if (a[i] != i) {
					goto l;
				}
			}
			continue;
			l:
			++res;
			for (int i = 1; i <= n; ++i) {
				cout << a[i] << " ";
			} cout << endl;
		}
	} while (next_permutation (a + 1, a + n + 1));
	cout << res;
}
