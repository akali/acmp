#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

long long d[1000000], a[1000000];

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	int n; cin >> n;
	d[1] = 1;  a[1] = 1;
	d[2] = 2;  a[2] = 3;
	d[3] = 5;  a[3] = 3;
	d[4] = 8;  a[4] = 6;
	d[5] = 14; a[5] = 5;
	// d[6] = 19; a[6] = 9;

	for (int i = 6; i <= n; i++) {
		if (i & 1) {
			a[i] = a[i - 2] + 2;
		} else {
			a[i] = a[i - 2] + 3;
		}
		d[i] = d[i - 1] + a[i - 1];
	}

	cout << d[n];

	return 0;
}
