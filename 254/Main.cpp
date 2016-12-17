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

int a[MaxN];
bool used[MaxN];

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int m; cin >> m;
	while (m--) {
		int x, y; cin >> x >> y;
		for (int i = 0; i < n; i++)
			if (a[i] == x && !used[i]) {
				a[i] = y;
				used[i] = true;
			}
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	return 0;
}
