#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, color = 1;
int d[20], q[20];
bool a[20][20];
bool used[20];

void dfs (int vertex, int color) {
	used[vertex] = true;
	if (q[color] >= 5) {
		color++;
	}
	d[vertex] = color;
	q[color]++;
	for (int i = 0; i < n; ++i) {
		if (!used[i] && a[vertex][i]) {
			dfs (i, color);
		}
	}
}

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs (i, color);
			color++;
		}
	}
	cout << *max_element (d, d + n) << endl;
	for (int i = 0; i < n; i++) {
		cout << d[i] << " ";
	}
	return 0;
}
