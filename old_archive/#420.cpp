#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	string s; cin >> s;
	for (int i = 1; i < s.size(); i++)
		if (s[i] == s[i - 1]) {
			cout << "NO";
			return 0;
		}
	cout << "YES";
	
	return 0;
}
