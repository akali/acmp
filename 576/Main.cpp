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
	#ifndef _LOCAL
		freopen ("output.txt", "w", stdout);
	#endif

	int n; cin >> n;

	int res = n;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			res -= res / i;
		}
	}

	if (n > 1)
		res -= res / n;
	
	cout << res;

	return 0;
}
