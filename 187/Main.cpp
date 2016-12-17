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

bool calced[50][50];
bool used[50][50];
long long d[50][50];
int n;

bool ok (int x, int y) {
	return used[x][y];
}

long long f (int x, int y) {
	if (!ok (x, y)) return 0;
	if (x == 1 && y == 1) return 1;
	if (calced[x][y]) return d[x][y];
	calced[x][y] = true;
	return d[x][y] = f (x - 1, y) + f (x - 1, y - 1) + f (x, y - 1);
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	cin >> n;
	for (int k = 1; k <= n; k++)
		for (int i = k; i < n + k; i++) {
			for (int j = k; j < n + k; j++) {
				used[i][j] = 1;
			}
		}

	/* for (int i = 1; i <= n + n; ++i) {
		for (int j = 1; j <= n + n; ++j)
			cout << int (used[i][j]) << " ";
		cout << endl;
	} */
	
	cout << f (2 * n - 1, 2 * n - 1);

	return 0;
}
