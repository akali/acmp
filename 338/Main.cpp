#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

bool used[100][100];
int n, m;

void dfs (int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m)
    	return;
    if (used[x][y])
    	return;
	used[x][y] = true;
	dfs (x + 1, y);
	dfs (x, y + 1);
	dfs (x - 1, y);
	dfs (x, y - 1);
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> used[i][j];
		}
	}
	int c = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!used[i][j]) {
				c++;
				dfs (i, j);
			}
		}
	}
    
    cout << c;

    return 0;
}
