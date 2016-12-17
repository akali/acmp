#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int __Gcd (int a, int b) {
	if (b)
		return __Gcd (b, a % b);
	return a;
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	int n; cin >> n;
	/* if (n % 2 == 0) {
		cout << n / 2 << " " << n / 2 << endl;
		return 0;
	} else {
		if (n % 3 == 0) {
			cout << n / 3 << " " << (n / 3) * 2 << endl;
			return 0;
		} else {
			cout << 1 << " " << n - 1 << endl;
		}
	}*/
	for (int i = n / 2; i >= 1; i--) {
		int a = n - i, b = i;
		cerr << __Gcd (a, b) << " " << a << " " << b << endl;
		if (a % b == 0) {
			cout << b << " " << a;
			return 0;
		}
	}
	return 0;
}
