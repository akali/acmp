#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

bool check (string &s) {
	int l = 0, r = s.size() - 1;
	while (l < r) {
		if (s[l++] != s[r--])
			return false;
	}
	return true;
}

int main () {
	
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	string s; cin >> s;
	
	if (!check (s)) {
		cout << s;
	} else {
		string q = s;
		bool d = true;
		for (int i = 1; i < s.size(); i++) {
			if (s[i] != s[i - 1]) {
			    d = false;
				break;
			}
		}
		if (d) {
			cout << "NO SOLUTION";
			return 0;
		}
		while (check (q)) {
			if (q.empty()) {
				cout << "NO SOLUTION";
				return 0;
			}
			q.erase (0, 1);
			if (q.empty()) {
				cout << "NO SOLUTION";
				return 0;
			}
		}
		cout << q;
		// string w = s;
		/* while (check (w)) {
			if (w.empty()) {
				cout << "NO SOLUTION";
				return 0;
			}
			w.erase (w.size() - 1, 1);
		}
		if (q.size() > w.size())
			cout << w;
		else
			cout << q; */
	}
	

	return 0;
}
