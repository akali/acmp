#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

int take (int k) {
	int res = 0;
	while (k > 0) {
		res += k % 2;
		k /= 2;
	}
	return res;
}

void printMask (int nm) {
	for (int k = 1; k <= 6; k++) {
		cout << ((nm & (1 << k)) > 0);
	}
	cout << endl;
}

int give (int mask) {
	int res = 0;
	for (int i = 0; i < 32; i++) {
		if (mask & (1 << i)) {
			res += (1 << i);
		}
	}
	return res;
}

int swapBitsInMask (int mask, int i, int j) {
    printMask (mask);
	int nm = (mask ^ (1 << j));
	printMask (1 << j);
	cout << nm << endl;
	printMask (nm);
	printMask (1 << i);
	printMask (nm | (1 << i));
	nm |= (1 << i);
	return give (nm);
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	int mask; cin >> mask;
	int b = take (mask);
	cout << swapBitsInMask (mask, 4, 5);
	/*
	for (int i = 0; i < 32; i++) {
		if ((mask & (1 << i)) && !(mask & (1 << (i + 1)))) {
			cout << swapBitsInMask (mask, i, i + 1);
		}
	}*/



	return 0;
}
