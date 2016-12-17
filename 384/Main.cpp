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

long long f[MaxN];

int gcd (int a, int b) {
	if (b)
		return gcd (b, a % b);
	return a;
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	int n, m; cin >> n >> m;

	f[1] = 1;
	f[2] = 1;

	for (int i = 3; i <= MaxN; i++) {
		f[i] = (f[i - 1] + f[i - 2]) % (int)(1e9);
	}
	cout << f[gcd (n, m)];

	return 0;
}
