#include <iostream>
#include <cstdio>
#include <set>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <string>

using namespace std;

int a[300][300];

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	int n; scanf ("%d", &n);
	
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			a[i][j] = INT_MAX / 100;
	
	for (int i = 0; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			scanf ("%d", &a[i][j]);
		}
	}

	for (int k = 0; k <= n; k++)
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				a[i][j] = min (a[i][j], a[i][k] + a[k][j]);

	printf ("%d", a[0][n]);
	return 0;
}
