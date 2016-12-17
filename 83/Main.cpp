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

int n, m, res;
int d[50][500];

inline bool one (int mask, int i) {
	return (mask & (1 << i));
}

bool ok (int m1, int m2) {
	for (int i = 0; i < m - 1; i++)
		if (one (m1, i) == one (m2, i) && one (m1, i + 1) == one (m2, i + 1) && one (m1, i) == one (m1, i + 1))
			return false;
	return true;
}

string Mask (int k) {
	string s = "";
	for (int i = 0; i < m; i++)
		if (k & (1 << i))
			s += '1';
		else
			s += '0';
	reverse (s.begin(), s.end());
	return s;
}

int f (int p, int m1) {
	if (p == 1)
		return 1;
		
	int &t = d[p][m1];
	
	if (~t)
		return t;
	
	t = 0;

	for (int i = 0; i < (1 << m); i++)
		if (ok (m1, i))
			t += f (p - 1, i);
	
	return t;	
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	cin >> n >> m;

	if (m > n)
		swap (n, m);

	memset (d, 255, sizeof d);

	for (int i = 0; i < (1 << m); i++)
		res += f (n, i);
    
	cout << res;

	return 0;
}
