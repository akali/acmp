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
int a[MaxN];

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int res1 = 0, res2 = 0;
	int tmp1 = 0, tmp2 = 0;
	bool is = true;
	for (int i = 0; i < n; i++) {
		if (is) {
			if (a[i] > a[i - 1])
				tmp1++;
			else {
				res1 = max (res1, tmp1);
				tmp1 = 0;				
			}
			if (a[i] < a[i - 1])
				tmp2++;
			else {
				res2 = max (res2, tmp2);
				tmp2 = 0;
			}
		} else {
			if (a[i] < a[i - 1]) {
				tmp1++;
			} else {
				res1 = max (res1, tmp1);
				tmp1 = 0;
			}
			if (a[i] > a[i - 1])
				tmp2++;
			else {
				res2 = max (res2, tmp2);
				tmp2 = 0;				
			}
		}
		is ^= true;
	}

	cout << max (res1, res2);
	return 0;
}
