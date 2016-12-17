#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

int find (string &s, int pos, char f) {
	for (int i = pos + 1; i < s.size(); i++) {
		if (s[i] == f)
			return i;
	}
	return -1;
}

int main () {

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	
	string a, b;
	cin >> a >> b;
	int pos = -1;
	for (int i = 0; i < a.size(); i++) {
		int Pos = pos;
		pos = find (b, pos, a[i]);
		if (pos == -1 || Pos == pos) {
			cout << "NO";
			return 0;
		}
		// cout << pos << " ";
	}

	cout << "YES";
	
	return 0;
}