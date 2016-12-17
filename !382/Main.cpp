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

int n;
char c[60][60];
bool canBe[60][60];

bool ok (int x, int y) {
	return (x >= 0 && y >= 0 && x < n && y < n);
}

void dfs (int x, int y, int color) {
	if (!ok (x, y))
		return;
	
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef lcl
		freopen ("output.txt", "w", stdout);
	#endif

	cin >> n;
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> c[i][j];
	
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= n + 1; j++) {
			if (!i || !j || i == n + 1 || j == n + 1)
				c[i][j] == '#';
		}
	}
	
	for (int i = 0; i <= n; i++)
		cout << c[i] << endl;
	
	int cnt = 0;

	/* for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (c[i][j] == '.') {
				if (!cnt) {
					dfs (i, j, 1);
				} else {
					dfs (i, j, 0);
				}
				cnt++;
			}
		}
	} */ 

	return 0;
}
