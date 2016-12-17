#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

char A[20][20];
char B[100][1000];
int ans = 0;
int n, m;

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> A[i][j];

    int a, b; cin >> a >> b;
    for (int i = 0; i < a; i++)
    	for (int j = 0; j < b; j++)
    		cin >> B[i][j];

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (i + n > a || j + m > b)
				break;
			bool d = true;
			for (int x = 0; x < n; x++)
				for (int y = 0; y < m; y++)
					if (A[x][y] == '#' && B[x + i][y + j] == '.') {
						d = false;
					}
			ans += d;
		}
	}

	cout << ans;

	return 0;
}
