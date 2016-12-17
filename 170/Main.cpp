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

long long take (long long x) {
	return (x * (x + 1)) / 2;
}

long long res = 1;

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	long long n; cin >> n;
	for (long long i = 1; i <= sqrt (n * 1.0) * 30; i++) {
		if ((n - take (i - 1)) % i == 0) {
			long long a = (n - take (i - 1)) / i;
			long long b = a + (i - 1);
			if (a < 0 || b < 0)
				continue;
			// cout << a << " " << b << endl;
			res = max (b - a + 1, res);
		}
	}
	cout << res;
	return 0;
}
