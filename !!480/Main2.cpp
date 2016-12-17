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

int d[2][200][80];
int k, n;
int a[200];
int s[200];

int take (int l, int r) {
	return s[r] - s[l - 1];
}

int f (char who, int pos, int K, int h = 0) {
	int &res = d[who][pos][K];
	
	if (~res) {
		return d[who][pos][K];
	}
	
	res = 0;

	for (int j = 1; j <= K; j++) {
		if (pos + j > n)
			break;
		if (who) {
			res = max (res, f (!who, pos + j, j, h + 1) + take (pos, pos + j - 1));
		} else {
			res = max (res, f (!who, pos + j, j, h + 1));
		}
	}
	return res;
}

int res;

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	memset (d, 255, sizeof d);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	
	cin >> k;

	/* for (int i = k; i >= 1; i--) {
		res = max (res, f (1, 1, i, 0));
	} */

	cout << f (1, 1, k) << endl;
	
	for (int i = 0; i < 2; i++) {
		for (int pos = 1; pos <= n; pos++)
			for (int K = 1; K <= k; K++)
				cout << i << " " << pos << " " << K << " -> " << f (i, pos, K, 0) << endl;
	}

	return 0;
}
