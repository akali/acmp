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
	vector <int> a;
	int n;
	while (cin >> n) {
		a.push_back (n);
	}
	sort (a.begin(), a.end());
	int prog = a[1] - a[0];
	for (int i = 1; i < a.size(); i++) {
		if (a[i] - a[i - 1] != prog) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}
