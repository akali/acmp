#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

char a[100][100], b[100][100], s[5];
char c[100][100];

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> b[i][j];
		}
	}

	cin >> s;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == '0' && b[i][j] == '0') {
				c[i][j] = s[0];
			}
			if (a[i][j] == '0' && b[i][j] == '1') {
				c[i][j] = s[1];
			}
			if (a[i][j] == '1' && b[i][j] == '0') {
				c[i][j] = s[2];
			}
			if (a[i][j] == '1' && b[i][j] == '1') {
				c[i][j] = s[3];
			}
			cout << c[i][j];
		}
		cout << endl;
	}

	return 0;
}
