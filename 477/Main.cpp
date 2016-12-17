#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	string s; cin >> s;
	int q = 0;
	for (int i = 0; i < s.size(); i++)
		q += s[i] - '0';
	if (q % 3 == 0)
		cout << 2;
	else
		cout << 1 << endl << q % 3;

	return 0;
}
