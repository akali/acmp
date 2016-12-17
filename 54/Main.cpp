#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

int a[150][150];

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}
	int A = -INT_MAX, B = INT_MAX;
	for (int i = 0; i < n; i++) {
		A = max (A, *min_element (a[i], a[i] + m));
	}
	for (int i = 0; i < m; i++) {
		int d = -INT_MAX;
		for (int j = 0; j < n; j++) {
			d = max (d, a[j][i]);
		}
		B = min (B, d);
	}

	cout << A << " " << B;

	return 0;
}
