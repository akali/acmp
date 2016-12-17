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

int a[20], sz;
long long d[2][2][20][3][3][3][3][3][3][3][3][3][3];
bool calced[2][2][20][3][3][3][3][3][3][3][3][3][3];

void convert (long long n) {
	sz = 0;
	while (n > 0) {
		a[sz++] = n % 10;
		n /= 10;
	}
	reverse (a, a + sz);
	for (int i = 0; i < sz; i++)
		cout << a[i];
	cout << endl;
}

long long go (bool was, bool sp, int pos, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a0) {
	if (pos == sz) {
		return was;
	}
	cout << was << " " << sp << " " << pos << " " << a1 << " " << a2 << " " << a3 << " " << a4 << " " << a5 << " " << a6 << " " << a7 << " " << a8 << " " << a9 << " " << a0 << endl;
	if (calced[was][sp][pos][a1][a2][a3][a4][a5][a6][a7][a8][a9][a0]) {
		return d[was][sp][pos][a1][a2][a3][a4][a5][a6][a7][a8][a9][a0];
	}
	calced[was][sp][pos][a1][a2][a3][a4][a5][a6][a7][a8][a9][a0] = true;
	int A[13];
	A[1] = a1;
	A[2] = a2;
	A[3] = a3;
	A[4] = a4;
	A[5] = a5;
	A[6] = a6;
	A[7] = a7;
	A[8] = a8;
	A[9] = a9;
	A[0] = a0;

	long long res = 0;

	if (sp) {
		for (int i = 0; i <= a[pos]; i++) {
			if (A[i] == 2)
				continue;
			res += go ((was ? 1 : i), (a[pos] == i), pos + 1, a1 + (1 == i), a2 + (2 == i), a3 + (3 == i), a4 + (4 == i), a5 + (5 == i), a6 + (6 == i), a7 + (7 == i), a8 + (8 == i), a9 + (9 == i), a0 + (0 == i));
		}
	} else {
		for (int i = 0; i <= 9; i++) {
			if (A[i] == 2)
				continue;
			res += go ((was ? 1 : i), 0, pos + 1, a1 + (1 == i), a2 + (2 == i), a3 + (3 == i), a4 + (4 == i), a5 + (5 == i), a6 + (6 == i), a7 + (7 == i), a8 + (8 == i), a9 + (9 == i), a0 + (0 == i));
		}
	}
	return d[was][sp][pos][a1][a2][a3][a4][a5][a6][a7][a8][a9][a0] = res;
}

long long get (long long n) {
	memset (calced, 0, sizeof calced);
	convert (n);
/*
	if (a[0] == 1)
		return go (0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	if (a[0] == 2)
		return go (0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0);
	if (a[0] == 3)
		return go (0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);
	if (a[0] == 4)
		return go (0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
	if (a[0] == 5)
		return go (0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
	if (a[0] == 6)
		return go (0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
	if (a[0] == 7)
		return go (0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0);
	if (a[0] == 8)
		return go (0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0);
	if (a[0] == 9)
		return go (0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
	if (a[0] == 0)
		return go (0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1);
*/
	return go (0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

int main () {
	freopen ("input.txt", "r", stdin);
	// #ifndef AKALI
		freopen ("output.txt", "w", stdout);
	// #endif

	long long l, r; cin >> l >> r;
    
	long long a = get (r), b = get (l - 1);

	// cout << get (56) << endl;
	cout << a - b;

	return 0;
}
