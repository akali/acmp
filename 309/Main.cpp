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

bool used[MaxN];

int rev (int k) {
	int res = 0;
	while (k > 0) {
		res = res * 10 + k % 10;
		k /= 10;		
	}
	return res;
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	int n; cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int d = rev (i);
		if (d + i == n) {
			res++;
			used[d] = true;
		}
	}
	cout << res;
	return 0;
}
