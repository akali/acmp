#include <climits>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

int plusMinusSum (string &s) {
	bool Plus = true;
	int res = 0;
	for (int i = 0; i < s.size(); i++) {
		if (Plus)
			res += s[i] - '0';
		else
			res -= s[i] - '0';
		Plus ^= 1;
	}
	return res;
}

void insert (string &s, int i, char c) {
	s = s.substr (0, i) + c + s.substr (i, s.size() - i + 1);
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	string s;
	cin >> s;
	int ans = -INT_MAX;
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		s.erase (i, 1);
		ans = max (ans, plusMinusSum (s));
		insert (s, i, c);
		// cout << s << endl;
	}
	cout << ans;
	return 0;
}
