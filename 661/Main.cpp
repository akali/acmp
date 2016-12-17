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

struct point {
	int l, r, c;
	point (int l = 0, int r = 0, int c = 0) : l (l), r (r), c (c) {}
	bool operator < (point t) const {
		if (l == t.l)
			if (r == t.r)
				return c < t.c;
			else
				return r < t.r;
		return (l < t.l);
	}
};

vector <point> p;
int s, e;
int d[MaxN];
int n;

bool intersect (int x, int y) {
	point a = p[x], b = p[y];
	return !(a.r < b.l || b.r < a.l);
}

int get (int v) {
	cout << v << " ";
	if (~d[v])
		return d[v];
	if (p[v].l > e)
		return 0;
	if (p[v].r > e)
		return p[v].c;
	int res = INT_MAX;
	for (int i = v + 1; i < n; ++i) {
		if (!intersect (v, i))
			break;
		res = min (res, get (i));
	}
	for (int i = v - 1; i >= 0; --i) {
		if (!intersect (v, i))
			break;
		res = min (res, get (i));
	}
	return d[v] = res + p[v].c;
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef lcl
		freopen ("output.txt", "w", stdout);
	#endif
	
	memset (d, 255, sizeof d);
	
	cin >> n;
	cin >> s >> e;
	for (int i = 0; i < n; ++i) {
		int s, e, c;
		cin >> s >> e >> c;
		p.push_back (point (s, e, c));
	}

	sort (p.begin(), p.end());
	
	int res = INT_MAX;
	
	for (int i = 0; i < n; ++i) {
		// cout << p[i].l << " " << p[i].r << endl;
		if (p[i].l > s)
			break;
		res = min (res, get (i));
	}
	
	cout << res;
	
	return 0;
}

