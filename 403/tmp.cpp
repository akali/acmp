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
long long d[2][2][20];
bool calced[2][2][20];

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

int num[10];

long long go (bool was, bool sp, int pos) {
	if (pos == sz) {
		return was;
	}

	if (calced[was][sp][pos]) {
		return d[was][sp][pos];
	}
	calced[was][sp][pos] = true;

	long long res = 0;

	if (sp) {
		for (int i = 0; i <= a[pos]; i++) {
		    if (num[i] == 2)
		    	continue;
		    num[i]++;
			res += go ((was ? 1 : i), (a[pos] == i), pos + 1);
			num[i]--;
		}
	} else {
		for (int i = 0; i <= 9; i++) {
			if (num[i] == 2)
				continue;
			num[i]++;
			res += go ((was ? 1 : i), 0, pos + 1);
			num[i]--;
		}
	}
	return d[was][sp][pos] = res;
}

long long get (long long n) {
	memset (calced, 0, sizeof calced);
	memset (num, 0, sizeof num);
	convert (n);
	return go (0, 1, 0);
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
