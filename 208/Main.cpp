#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

string convert (int i) {
	string res;
	while (i > 0) {
		res += i % 2 + '0';
		i /= 2;
	}	
	reverse (res.begin(), res.end());
	return res;
}

int take (string s) {
	int k = 0, res = 0;
	for (int i = s.size() - 1; i >= 0; i--, k++) {
		if (s[i] == '1') {
			res += (1 << k);
		}
	}
	return res;
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	int n, ans = 0; cin >> n;
	string s = convert (n);

	for (int i = 0; i < n; i++) {
	    // cout << s << " " << take (s) << endl;
		ans = max (ans, take (s));
		s = s[s.size() - 1] + s.substr (0, s.size() - 1);
	}
	cout << ans;

	return 0;
}
