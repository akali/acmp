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

const int MaxN = (int)(1e6) + 256;

int d[MaxN];
int n, k;
string s; 

int Get (int l, int r) {
	set <char> S;
	while (l <= r)
		S.insert (s[l++]);
	return S.size();
}

int f (int p) {
	if (p == 0)
		return 1;
	
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef lcl
		freopen ("output.txt", "w", stdout);
	#endif

	cin >> n >> k;
	cin >> s;

	cout << f (n);
	
	return 0;
}
