#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

int d[100], a[100];

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	int n; cin >> n;

	d[0] = 2;   a[0] = 0;
	d[1] = 4;   a[1] = 2;
	d[2] = 10;  a[2] = 6;
	d[3] = 28;  a[3] = 18;
	
	for (int i = 4; i <= n; i++) {
		d[i] = d[i - 1] + a[i - 1] * 3;
		a[i] = a[i - 1] * 3;
	}
	cout << d[n];

	return 0;
}
