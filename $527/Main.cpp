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

bool gcd (long long x, long long y, long long a, long long b) {
	if (x < a || y < b)
		return 0;
	
	if (x == a && y == b)
		return 1;
	
	if ((x - a) % y == 0)
		return y == b;
	
	return (gcd (y, x % y, a, b));
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef lcl
		freopen ("output.txt", "w", stdout);
	#endif

	int t; cin >> t;
	while (t--) {
		long long a, b, c, d; scanf ("%lld%lld%lld%lld", &a, &b, &c, &d);
		if (gcd (a, b, c, d))
			puts ("YES");
		else
			puts ("NO");
	}

	return 0;
}
