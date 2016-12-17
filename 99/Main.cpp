#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

char c[50][50][50];
int h, m, n;

struct Trio {
	int x, y, z;
	Trio (int _x, int _y, int _z) {
		x = _x;
		y = _y;
		z = _z;
	}
	bool operator == (const Trio &a) const {
		return a.x == x && a.y == y && a.z == z;
	}
} start, end;

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	cin >> h >> n >> m;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> c[i][j][k];
				if (c[i][j][k] == '1') {
					start = Trio (i, j, k);
				}
				if (c[i][j][k] == '2') {
					end = Trio (i, j, k);
				}
			}
		}
	}

	queue <pair <Trio, int> > q;
	q.push (make_pair (start, 0));
	while (!q.empty ()) {
		Trio This = q.front().first;
		int k = q.front().second;
		if (This == end) {
			cout << 5 * k;
			return 0;
		}
		if (This.x != h && This.y == n) {
			if (c[This.x + 1][0][This.z] != 'o')
				q.push (make_pair (Trio (This.x + 1, 0, This.z), k + 1));
		    else {
		    	if (c[This.x + 1][1][This.z] != 'o')
		    		q.push (make_pair (Trio (This.x + 1, 1, This.z), k + 1));
		    	else
		    		continue;
		    }
		}
		if (c[This.x][This.y + 1][This])
	}

	return 0;
}
