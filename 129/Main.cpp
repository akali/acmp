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

int a[200][200], r[200][200];
int d[200][200];

int n, m;

int dx[] = {1, -1, 0,  0, 1,  1, -1, -1};
int dy[] = {0, 0,  1, -1, 1, -1,  1, -1};

int timer;

struct A {
	int x, y, h;
	A () {}
	A (int a, int b, int c) : x (a), y (b), h (c) {}
};

int bfs (int x, int y) {
	queue <A> q;

	q.push (A (x, y, 0));

	int h = 0;

	while (!q.empty ()) {
		x = q.front().x;
		y = q.front().y;
		h = q.front().h;
		if (a[x][y])
			return h;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int X = x + dx[i],
				Y =	y + dy[i];
			if (!(X < 0 || Y < 0 || X >= n || Y >= m) && r[X][Y] != timer) {
				r[X][Y] = timer;
				q.push (A (X, Y, h + 1));
			}
		}
	}
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef _LOCAL
		freopen ("output.txt", "w", stdout);
	#endif

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	
	for (int i = 0; i < n; cout << endl, i++)
		for (int j = 0; j < m; j++) {
			timer++;
			cout << bfs (i, j) << " ";
		}

	return 0;
}
