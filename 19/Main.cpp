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

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef lcl
		freopen ("output.txt", "w", stdout);
	#endif

	char tmp;
	int f1, l1, k1, f2, l2, k2;

	cin >> tmp >> f2; f1 = tmp; f1 -= 'A'; f1++; // swap (f1, f2);
	cin >> tmp >> l2; l1 = tmp; l1 -= 'A'; l1++; // swap (l1, l2);
	cin >> tmp >> k2; k1 = tmp; k1 -= 'A'; k1++; // swap (k1, k2);

	int dx[] = {1,  1, 2,  2, -1, -1, -2, -2};
	int dy[] = {2, -2, 1, -1,  2, -2,  1, -1};

	int res = 0;

	char kmp[9][9];
	memset (kmp, '.', sizeof kmp);
	
	for (int i = 0; i < 8; ++i) {
		int x = dx[i] + k1;
		int y = dy[i] + k2;
		kmp[x][y] = 'k';
	}

	for (int i = 1; i <= 8; ++i) {
		for (int j = 1; j <= 8; ++j) {
			if (j == l1 || j == f1)
				continue;
			if (i == l2 || j == f2)
				continue;
			if (i == k2 && j == k1)
				continue;
			if (i - f2 == j - f2 || (i + f2) == (j + f1)) {
				// cout << i << " " << j << endl;
				continue;
			}
			++res;
			kmp[i][j] = 'x';
		}
	}

	for (int i = 1; i <= 8; ++i, cout << endl)
		for (int j = 1; j <= 8; cout << kmp[i][j], ++j);

	cout << res;

	return 0;
}
