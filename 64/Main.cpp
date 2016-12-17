#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

bool Sieve[(int)(1e6)];
string s;

string tostr (int t) {
	string res;
	while (t > 0) {
		res += (t % 10) + '0';
		t /= 10;
	}
	reverse (res.begin(), res.end());
	return res;
} 

void push (int q) {
	s += tostr (q);
}

void sieve () {
	for (int i = 2; i < (int)(1e6); i++) {
		if (!Sieve[i]) {
			push (i);
			for (int j = i + i; j < (int)(1e6); j += i)
				Sieve[j] = true;
		}
	}
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	sieve();
	int m; cin >> m;
	while (m--) {
		int k; cin >> k;
		cout << s[k - 1];
	}

	return 0;
}
