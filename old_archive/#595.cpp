#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

unsigned long long deg[50000], Hash[50000], Mash[50000];
int pr = 31;

unsigned long long takeHash (int l, int r) {
	return Hash[r] - Hash[l - 1] * deg[r - l + 1];
}

unsigned long long takeMash (int l, int r) {
	return Mash[r] - Mash[l - 1] * deg[r - l + 1];
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif
	string s, t;
	cin >> s >> t;

	deg[0] = 1;
	for (int i = 1; i < 50000; i++) {
		deg[i] = deg[i - 1] * pr;
	}

	Hash[0] = 0;
	Hash[1] = s[0];
	Mash[0] = 0;
	Mash[1] = t[0];
	for (int i = 2; i < s.size(); i++) {
		Hash[i] = Hash[i - 1] * pr + (s[i - 1]);
		Mash[i] = Mash[i - 1] * pr + (t[i - 1]);
	}
	
	for (int i = 1; i <= s.size(); i++) {
		unsigned long long pH = takeHash (1, i);
		unsigned long long sH = takeHash (i, s.size());
		unsigned long long pM = takeMash (1, s.size() - i + 1);
		unsigned long long sM = takeMash (s.size() - i + 1, s.size());
		if (sH == pM && pH == sM) {
			cout << "Yes\n" << i;
			return 0;
		}
	}
	cout << "No";
	return 0;
}
/*
1234657
wpwdwpw
wdwpwpw
*/