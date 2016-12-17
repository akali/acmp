#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

bool a[15][15];

int ___builtin_popcount (int i) {
	int res = 0;
	while (i > 0)
		res += i % 2, i /= 2;
	return res;
}

void printMask (int mask, int n) {
	for (int i = 0; i < n; i++) {
		if (mask & (1 << i))
			cout << 1;
		else
			cout << 0;
	}
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	vector <int> masks[n];
	for (int mask = 0; mask < (1 << n); mask++) {
		if (__builtin_popcount (mask) > 5)
			continue;
		for (int i = 0; i < n; i++) {
			if (mask & (1 << i)) {
				masks[i].push_back (mask);
			}
		}
		printMask (mask, n);
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < n; cout << "/---/---/\n",i++)
		for (int j = 0; j < masks[i].size(); j++) {
			printMask (masks[i][j], n);
			cout << endl;
		}

	return 0;
}
