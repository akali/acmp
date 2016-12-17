#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

int last (int n) {
    const int MOD = 100000;
	int This = 1;
	for (int i = 2; i <= n; i++) {
		This *= i;
		This %= MOD;
	}
	while (This % 10 == 0)
		This /= 10;
	return This % 10;
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;
	if (n == 0) {
		cout << 1;
		return 0;
	}

	cout << last (n);

	return 0;
}
