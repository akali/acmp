#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	string s; cin >> s;
	int k; cin >> k;
	if (k > 0) {
		while (k--) {
			cout << s;
		}
	} else {
		k = -k;
		bool SOLUTION = true;
		if (s.size () % k) {
			cout << "NO SOLUTION";
		} else {
			string tmp = s.substr (0, (s.size() / k));
			for (int i = 0; i < s.size(); i += (s.size() / k)) {
				if (tmp != s.substr (i, (s.size() / k)) && SOLUTION) {
					cout << "NO SOLUTION";
					SOLUTION = false;
				}
			}
			if (SOLUTION) {
				cout << tmp;
			}
		}
	}
	return 0;
}