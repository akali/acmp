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

const int MaxN = (int)(1e5);

string s, t;

int SA[MaxN], NSA[MaxN], c[MaxN], nc[MaxN], head[MaxN], cnt;

bool cmp (int i, int j) {
	return s[i] < s[j];
}

bool check (int p) {
	for (int i = SA[p], j = 0; j < t.size() && i < s.size(); j++, i++)
		if (s[i] != s[j])
			return false;
	return true;
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef lcl
		freopen ("output.txt", "w", stdout);
	#endif

	cin >> s >> t;
	
	s += '$'; int n = s.size();

	for (int i = 0; i < n; ++i)
		SA[i] = i;

	sort (SA, SA + n, cmp);

	for (int i = 0; i < n; ++i) {
		int t = SA[i], p = SA[i - 1];
		if (!i || s[t] != s[p]) {
			c[t] = cnt++;
			head[c[t]] = i;
		} else {
			c[t] = c[p];
		}
	}

	for (int len = 1; len < n; len += len) {
		for (int j = 0; j < n; ++j) {
			int i = SA[j] - len; if (i < 0) i += n;
			NSA[head[c[i]]++] = i;
		} cnt = 0;
		for (int i = 0; i < n; ++i) {
		    SA[i] = NSA[i];
		    int t = SA[i], p = SA[i - 1];
			if (!i || c[t] != c[p] || c[(t + len) % n] != c[(p + len) % n])
				nc[t] = cnt++, head[nc[t]] = i;
			else
				nc[t] = nc[p];
		}
		memcpy (c, nc, n * sizeof (int));
	}
	
	int l = 1, r = n;
	while (r - l > 1) {
		int m = (l + r) >> 1;
		cout << l << " " << r << endl;
		if (check (m))
			r = m;
		else
			l = m;
	}
    
	// while (check (l) && l) if (!l) break;
	// while (check (r)) if (r == n - 1) break;

	for (int i = l; i < r; i++)
		cout <<  << " ";
	
	return 0;
}
