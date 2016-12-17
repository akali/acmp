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

long long int d[11][101][(1 << 10)]; // d[NumberOfString][NumberOfWhite][NumberOfBlack][LastMask] O (n * (2 ^ m) * (k + l))
bool c[11][101][(1 << 10)];

int n, m, w, b;

long long int f (int p, int c, int mask) {
	cout << p << " " << c << endl;
	if (p == n) {
		return !c;
	}
	if (::c[p][c][mask])
		return d[p][c][mask];
	::c[p][c][mask] = true;
	for (int i = 0; i < m; i++) {
		if (mask & (1 << i))
			continue;
		
		int newmask = mask + (1 << i);
		d[p][c][mask] += f (p + 1, c - 1, newmask);
        /*
		for (int j = 0; j < m; j++) {
			if (mask & (1 << j))
				continue;
			int newmask = mask + (1 << i); newmask += (1 << j);
			d[p][c][mask] += f (p + 1, c - 1, newmask);
		}*/
	}
	return d[p][c][mask];
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef lcl
		freopen ("output.txt", "w", stdout);
	#endif

	cin >> n >> m >> w >> b;
	cout << f (0, (w + b), 0);

	return 0;
}
