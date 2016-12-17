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

int a, b, c, k;
bool calced[150][150][150];
int d[150][150][150];

int f (int a, int b, int c) {
	if (calced[a][b][c])
		return d[a][b][c];
	calced[a][b][c] = true;
	
	int res = INT_MAX;
	static int A, B, C;
	if (a) A = (k / a) + ((k % a) > 0);
	if (b) B = (k / b) + ((k % b) > 0);
	if (c) C = (k / c) + ((k % c) > 0);
	return A + B + C;
	if (A <= 0 || B <= 0 || C <= 0)
		return 0;

	for (int i = 0; i < A; i++) {
		res = min (res, f (a - (A * i), b, c)) + 1;
	}
	for (int i = 0; i < B; i++) {
		res = min (res, f (a, b - (B * i), c)) + 1;
	}
	for (int i = 0; i < C; i++) {
		res = min (res, f (a, b, c - (C * i))) + 1;
	}
	
	return d[a][b][c] = res;
}


int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	cin >> a >> b >> c >> k;

	cout << f (a, b, c);

	return 0;
}
