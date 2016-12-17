#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int pi[1005000];

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	string s, t; cin >> s >> t;
	string q = t + '#' + s;
	int n = q.size();
	for (int i = 1; i < n; i++) {
		int j = pi[i - 1];
		while (j > 0 && q[i] != q[j])
			j = pi[j - 1];
		if (q[i] == q[j])
			++j;
		pi[i] = j;                                                                
	}
	if (s == t) {
		cout << 0;
	} else {
		if (!pi[n - 1])
			cout << -1;
		else
			cout << pi[n - 1];
	}
	return 0;
}
