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

int e, f, n, p[600], w[600];
int l;

pair <int, int> g (int h) {
	if (h < 0)
		return make_pair (INT_MAX, -INT_MAX);
	if (c[h])
		return d[h];
	c[h] = true;
	pair <int, int> res = make_pair (INT_MAX, -INT_MAX);
	for (int i = 0; i < n; i++) {
		pair <int, int> t = g (h);
		res = 
	}
	return d[h] = res;
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	cin >> e >> f;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i] >> w[i];
	
	l = f - e;

	pair <int, int> g = get (l);
	if (g == make_pair (INT_MAX, -INT_MAX))
		cout << "This is impossible.";	
	else	
		cout << g.first << " " << g.second << endl;

	return 0;
}
