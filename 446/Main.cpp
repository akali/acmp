#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

char c[100][100];

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif
	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int k; cin >> k;
			if (c[i][j] == 'B') {
				if (k != 1 && k != 3 && k != 5 && k != 7) {
					cout << "NO";
					return 0;
				}
			}
			if (c[i][j] == 'G') {
				if (k != 2 && k != 3 && k != 6 && k != 7) {
					cout << "NO";
					return 0;
				}
			}
			if (c[i][j] == 'R') {
				if (k < 4) {
					cout << "NO";
					return 0;
				}
			}
		}
	}
	cout << "YES";

	return 0;
}
