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

int a[MaxN], b[MaxN];

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef lcl
		freopen ("output.txt", "w", stdout);
	#endif

	int n, m; cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i < m; ++i)
		cin >> b[i];

	sort (a, a + n);
	sort (b, b + m);

	int N = unique (a, a + n) - a;
	int M = unique (b, b + m) - b;

	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	
	for (int i = 0, j = 0; j < M && i < N; ++j, ++i) {
		if (a[i] != b[j]) {
			cout << "0";
			return 0;
		}
	}
	
	if (N == M)
		cout << 1;
	else
		cout << 0;
	
	return 0;
}
