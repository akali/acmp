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
int a[MaxN];
bool d[MaxN];

int main() {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	d[0] = 1;
	int tmp = 0;
	for (int j = 0; j < n; j++) {
		int newtmp = tmp;
		for (int i = tmp; i >= 0; i--) {
			if (d[i]) {
				d[i + a[j]] = 1;
				newtmp = max(i + a[j], newtmp);
			}
		}
		tmp = newtmp;
	}

	int result = 0;
	for (int i = 0; i < MaxN; i++)
		if (d[i])
			result++;
	cout << result;
	return 0;
}

