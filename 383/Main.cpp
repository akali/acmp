#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

bool check (int n) {
	int q = 0, c = 0;
	while (n > 0) {
		q += n % 10;
		c++;
		n /= 10;
	}
	return (q % c) == 0;
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	int n; cin >> n;
	                         
	for (int i = 1; i <= 10000000; i++) {
		if (n == 0) {
			cout << i - 1;
			return 0;
		}
		if (check (i))
			n--;
	}

	return 0;
}
