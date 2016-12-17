#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

int a[10000], b[10000];

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	int n; cin >> n;
	a[1] = 2; b[1] = 1;
	a[2] = 3; b[2] = 5;
	a[3] = 4; b[3] = 6;
	a[4] = 7; b[4] = 8;
	for (int i = 5; i <= n; i++) {
		a[i] = b[i - 1] + b[i - 3];
		
	}

	cout << a[n] << endl << b[n];

	return 0;
}
