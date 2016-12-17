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

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	int n, k; string s;
	cin >> n >> k >> s;
	bool is = 0;
	map <string, int> M;
	for (int i = 0; i < n - k; i++) {
		string pp = s.substr (i, k);
		M[pp]++;
		if (M[pp] >= 2) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";

	return 0;
}
