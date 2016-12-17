#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;

bool equals (string a, string b) {
	if (a.size() != b.size())
		return false;
   	for (int i = 0; i < a.size(); i++) {
   		if (a[i] != b[i])
   			return false;
   	}
   	return true;
}

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
	int n; cin >> n;
	while (n--) {
		string s; cin >> s;
		string q = s;
		sort (q.begin(), q.end());
		if (!equals (q, s)) {
			cout << "NO" << endl;
			continue;
		}
		int n = 0, o = 0, t = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '0') {
				n++;
			}
			if (s[i] == '1') {
				o++;
			}
			if (s[i] == '2') {
				t++;
			}
		}
		if (n == o && o == t) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
