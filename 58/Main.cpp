#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

int a[100][100];

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	int t; cin >> t;
	while (t--)  {
		int n, m; cin >> n >> m;
		bool is = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				if (i >= 1 && j >= 1) {
					if (a[i][j] == a[i][j - 1] && a[i][j] == a[i - 1][j] && a[i][j] == a[i - 1][j - 1])
						is = false;
				}
			}
		}
		if (is)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
