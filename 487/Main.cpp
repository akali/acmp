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
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	int n, k, p; cin >> n >> k >> p;

	while (p--) {
		int x; cin >> x;
		int q = n - x;
		if (q % (k + 1) == 0) {
			cout << "T\n";
		} else {
			cout << "F\n";
		}
	}

	return 0;
}
