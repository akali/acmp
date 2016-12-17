#include <cstdio>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	string s; cin >> s;
	int last = 0;
	s += 'A';
	for (int i = 0; i < s.size(); i++) {
		if (isupper (s[i])) {
			if (!i)
				continue;
			if (!(i - last >= 2 && i - last <= 4)) {
				cout << "No";
				return 0;	
			}
			last = i;
		}
	}
	cout << "Yes";

	return 0;
}
