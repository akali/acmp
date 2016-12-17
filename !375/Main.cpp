#include <queue>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <fstream>
#include <climits>
#include <ctime>

using namespace std;

const int MaxN = (int)(1e6);

int get (char c) {
	if (isdigit (c))
		return c - '0';
	return 10 + c - 'A';
}

int toInt (int k, string &s) {
	int res = 0;
	for (int i = s.size() - 1; i >= 0; --i)
		res = res * k + get (s[i]);
	return res;
}

string get (int from, string &s, int to) {
	if (from == to)
		return s;

	int k = toInt (from, s);
	string res;
	while (k > 0) {
		if (k % to < 10)
			res.push_back (char (k % to + '0'));
		else
			res.push_back (char (k % to + 55));
		k /= to;
	}
	reverse (res.begin(), res.end());
	return res;
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef lcl
		freopen ("output.txt", "w", stdout);
	#endif

	int n, k; cin >> n >> k;
	string s; cin >> s;
	string N = get (n, s, 10);
	cout << get (10, N, k);

	return 0;
}
