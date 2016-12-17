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
long long d[2][2][20][20][2];
bool calced[2][2][20][20][2];

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

int num[10][20];

long long go (bool was, bool sp, int pos, int last, bool rptd) {
	if (pos == sz) {
		return was;
	}

	if (calced[was][sp][pos][last][rptd]) {
		return d[was][sp][pos][last][rptd];
	}
	calced[was][sp][pos][last][rptd] = true;

	long long res = 0;

	if (sp) {
		for (int i = 0; i <= a[pos]; i++) {
			// if (last == i && rptd)
			//	continue;
			if (!rptd)
				res += go ((was ? 1 : i), (a[pos] == i), pos + 1, i, last == i);
			else
				if (last != i)
					res += go ((was ? 1 : i), (a[pos] == i), pos + 1, i, 0);
		}
	} else {
		for (int i = 0; i <= 9; i++) {
			// if (last == i && rptd)
			//	continue;
			if (!rptd)
				res += go ((was ? 1 : i), 0, pos + 1, i, last == i);
			else
				if (last != i)
					res += go ((was ? 1 : i), 0, pos + 1, i, 0);	
		}
	}
	return d[was][sp][pos][last][rptd] = res;
}

long long get (long long n) {
	memset (calced, 0, sizeof calced);
	convert (n);
	return go (0, 1, 0, a[0], 0);
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	long long l, r; cin >> l >> r;
    
	long long a = get (r), b = get (l - 1);

	cout << get (56) << endl;
	cout << a - b;

	return 0;
}
