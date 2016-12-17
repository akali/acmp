#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

bool check (int i) {
	int t[10];
	memset (t, 0, sizeof t);
	int ans = 0;
	while (i > 0) {
		t[i % 10]++;
		if (t[i % 10] == 1)
			ans++;
		i /= 10;
	}
	return ans <= 2;
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	int s; cin >> s;
	if (check (s)) {
		cout << s;
		return 0;
	}
	int a, b;
	int A, B;
	for (int i = s, j = 0; true; i++, j++) {
		if (check (i)) {
			a = i;
			A = j;
			break;
		}
	}
	for (int i = s, j = 0; true; i--, j++) {
		if (check (i)) {
			b = i;
			B = j;
			break;
		}
	}

	if (A < B)
		cout << a;
	else
		cout << b;
	
	return 0;
}
