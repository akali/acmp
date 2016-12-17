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

int n, a[200];

int d[2][100][100];

int f (bool w, int l, int r, int h = 0) {
	if (~d[w][l][r])
		return d[w][l][r];
	
	if (l == r) {
		return d[w][l][r] = a[l];
	}

	int Left = f (w ^ 1, l + 1, r, h + 1), Right = f (w ^ 1, l, r - 1, h + 1);

	if (w) {
		return d[w][l][r] = max (Left, Right);
	} else {
		return d[w][l][r] = min (Left, Right);
	}
}

void print (bool w, int l, int r, int h = 0) {
	for (int i = 0; i < h; i++)
		cout << "  ";
	cout << w << " " << l << " " << r << " " << (f (w, l, r, h)) << endl;
	
	if (l == r) {
		return;
	}

	print (w ^ 1, l + 1, r, h + 1);
	print (w ^ 1, l, r - 1, h + 1);
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef _LOCAL
		freopen ("output.txt", "w", stdout);
	#endif

	cin >> n;

	long long q = 0;

	memset (d, 255, sizeof d);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		q += a[i];
	}

	int l = f (1, 0, n - 1), r = q - l;

	print (1, 0, n - 1);

	cout << l << " " << r << endl;

	if (l > r)
		cout << 1;
	else
		if (l < r)
			cout << 2;
		else
			cout << 0;

	return 0;
}
