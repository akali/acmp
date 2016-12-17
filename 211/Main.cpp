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

const int MaxN = (int)(100);

char c[MaxN][MaxN];
int D[100][100];
int dx[] = {0,  0, 1, -1};
int dy[] = {1, -1, 0,  0};
int n, m;

bool OK (int x, int y) {
	return (x >= 0 && y >= 0 && x <= n && y <= m && D[x][y] == -1);
}

int solve (int a, int b, int c, int d) {
	queue <pair <int, int> > q;
	q.push (make_pair (a, b));
   
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
	    	D[i][j] = -1;

	D[a][b] = 0;
	
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int X = x + dx[i];
			int Y = y + dy[i];
			if (OK (X, Y)) {
				if ((::c[X][Y] == 'X' && X == c && Y == d) || ::c[X][Y] != 'X') {
					q.push (make_pair (X, Y));
					D[X][Y] = D[x][y] + 1;
				}
			}
		}
	}
	return D[c][d];
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	cin >> n >> m;

	swap (n, m);
	
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= m + 1; j++)
			c[i][j] = '.';

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c[i][j];
		}
	}
	n++; m++;
	int a, b, c, d;
	while (cin >> a >> b >> c >> d) {
		if (!a && !b && !c && !d) {
			break;
		}
		swap (a, b);
		swap (c, d);
		int DDD = solve (a, b, c, d);
		if (DDD == -1) {
			cout << 0;
		} else {
			cout << DDD;
		}
		cout << endl;
	}
	return 0;
}
