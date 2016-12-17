#include <queue>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <fstream>
#include <climits>
#include <ctime>

using namespace std;

const int MaxN = (int)(1e6);

int a[2000][2000];
int res = -INT_MAX;

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != 0 && i != n - 1) {
				res = max (a[i][j] + a[i - 1][j] + a[i + 1][j], res);
				if (j != 0)
					res = max (a[i][j] + a[i - 1][j] + a[i][j - 1], res);
				if (j != n - 1)
					res = max (a[i][j] + a[i - 1][j] + a[i][j + 1], res);
			}
			if (j != 0 && j != n - 1) {
				res = max (a[i][j] + a[i][j - 1] + a[i][j + 1], res);
				if (i != n - 1)
					res = max (a[i][j] + a[i][j - 1] + a[i + 1][j], res);
			}
		}
	}
	cout << res;

	return 0;
}
