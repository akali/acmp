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

int n, a[MaxN];
int d[MaxN];

int f (int p) {
	if (p == n - 1)
		return (a[p]);
	if (~d[p])
		return d[p];
	if (p >= n)
		return -INT_MAX;
	return d[p] = max (f (p + 1), f (p + 2)) + (a[p]);
}

set <int> v;

bool restore (int p) {
	if (p >= n)
		return false;
	v.insert (p);
	if (p == n - 1)
		return true;
	for (int i = 2; i >= 1; --i) {
		// cout << f (p + i) + a[p] << " " << f (p) << endl;
		if (f (p + i) + (a[p]) == f (p) && restore (p + i)) {
			v.insert (p + i);
			break;
		}
	}
	return true;
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef lcl
		freopen ("output.txt", "w", stdout);
	#endif

	cin >> n;

	memset (d, 255, sizeof d);

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int k = max (f (0), f (1));
	
	cout << k << endl;
	
	restore (0);
	v.insert (0);

	for (set <int> :: iterator it = v.begin(); it != v.end(); ++it)
		cout << *it + 1 << " ";

	return 0;
}
