#include <iostream>
#include <cstdio>

using namespace std;

char inverse (char q) {
	if (q == '0')
		return '1';
	if (q == '1')
		return '2';
	return '0';
}

bool check (int d) {
	for (int i = 0; i < 30; i++)
		if ((1 << i) == d)
			return true;
	return false;
}

int ___builtin_popcount (int n) {
	int res = 0;
	while (n > 0) {
		res += n % 2;
		n /= 2;
	}
	return res;
}

int main () {
	freopen ("output.txt", "w", stdout);
	freopen ("input.txt", "r", stdin);
	int n; cin >> n;
	/* string s;
	s += '0';
	while (s.size() <= 513) {
		int r = s.size();
		for (int i = 0; i < r; i++) {
			s += inverse (s[i]);
		}
	} */
	cout << ___builtin_popcount (n - 1) % 3 << endl;
	/* for (int i = 0; i < s.size(); i++) {
		cout << i + 1 << " " << s[i] << " " << __builtin_popcount (i) % 3 << endl;
		if (check (i + 1))
			cout << endl;
	} */
	// cout << s << endl;
	return 0;
}
