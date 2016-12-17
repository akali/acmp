#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

int take (int k) {
	int res = 1;
	while (k > 0) {
		res *= k % 10;
		k /= 10;
	}
	return res;
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	int l, r;
	cin >> l >> r;
	int res = 0;
	for (int i = l; i <= r; i++) {
		int q = take (i);
		if (!q)
			continue;
		if (i % q == 0) {
			res++;
		}
	}
	cout << res;


	return 0;
}
