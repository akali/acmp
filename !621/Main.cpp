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

int a[250][250];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int l[250][250];
int n, timer;
int used[250][250];
pair <int, int> p[250][250];

int len (int a, int b, int c, int d) {
	return abs (a - c) + abs (b - d);
}

bool ok (int x, int y) {
	return (x >= 0 && y >= 0 && x < n && y < n);
}

int get (int x, int y) {
	if (a[x][y])
		return a[x][y];
	timer++;
	int length = l[x][y], ans = p[x][y];
	int rX = x, rY = y;
	queue <pair <int, int> > q;
	q.push (make_pair (x, y));
	while (!q.empty()) {
		pair <int, int> v = q.front(); q.pop();
		int X = v.first, Y = v.second;
		if (a[X][Y]) {
			if (len (x, y, X, Y) < length) {
				length = len (x, y, X, Y);
				ans = a[X][Y];
				continue;
			}
			if (len (x, y, X, Y) == length)
				return 0;
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int XX = X + dx[i], YY = Y + dy[i];
			if (ok (XX, YY) && used[XX][YY] != timer) {
				q.push (make_pair (XX, YY));
				used[XX][YY] = timer;
			}
		}
	}
	return ans;
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef lcl
		freopen ("output.txt", "w", stdout);
	#endif

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			l[i][j] = 250 * 250,
			p[i][j] = make_pair (n, n), 
			scanf ("%d", a[i] + j);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf ("%d ", get (i, j));
		}
		puts ("");
	}
	
	return 0;
}
