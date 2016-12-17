#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

int q[1050][1050];

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int d = i * j;
			if (d % 2 == 0) {
				q[i][j] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int d = i * j;
			if (d % 3 == 0) {
				q[i][j] = 2;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int d = i * j;
			if (d % 5 == 0) {
				q[i][j] = 3;
			}
		}
	}

	int red = 0, green = 0, blue = 0, black = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!q[i][j])
				black++;
			else {
				if (q[i][j] == 1) {
					red++;
				} else {
					if (q[i][j] == 2) {
						green++;
					} else {
						if (q[i][j] == 3) {
							blue++;
						}
					}
				}
			}
		}
	}

	cout << "RED : " << red << endl;
	cout << "GREEN : " << green << endl;
	cout << "BLUE : " << blue << endl;
	cout << "BLACK : " << black << endl;

	return 0;
}
