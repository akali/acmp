#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void change (string &s, bool is) {
	for (int i = 0; i < s.size(); i++) {
	    if (is) {
		    if (s[i] == 'Z')
		    	s[i] = 'A';
		   	else
		   		s[i]++;
		} else {
			if (s[i] == 'A')
				s[i] = 'Z';
			else
				s[i]--;
		}
	}
}

int p[100];

bool check (string a, string &b) {
	memset (p, 0, sizeof p);
	a = b + '#' + a;
	for (int i = 1; i < a.size(); i++) {
		int j = p[i - 1];
		while (a[i] != a[j] && j > 0)
			j = p[j - 1];
		if (a[i] == a[j])
			++j;
		p[i] = j;
		if (j == b.size())
			return true;
	}
	return false;
}

int main () {

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	string a, b; cin >> a >> b;
	string cA = a;
	for (int i = 0; i <= 27; i++) {
        /* 
		if (check (a, b)) {
			cout << a;
			return 0;
		}*/

		if (check (cA, b)) {
			cout << cA;
			return 0;
		}
		// change (a, 1);
		change (cA, 0);
	}
	cout << "IMPOSSIBLE";

	return 0;
}
