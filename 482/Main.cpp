#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

string tostr (int i) {
	string s;
	while (i > 0) {
		s += (i % 10) + '0';
		i /= 10;
	}
	reverse (s.begin(), s.end());
	return s;
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;
	string s, t = "1";
	for (int i = 2; i <= 178; i++)
		s += t,
		t += tostr (i);
	// cout << s << endl;
	cout << s[n - 1];

	return 0;
}
