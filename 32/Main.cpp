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

	string a, b; cin >> a >> b;

	if (a[0] != '-') {
		sort (a.begin(), a.end(), greater <char>());
	} else {
		sort (a.begin(), a.end());
		do {
			if (a[1] != '0')
				break;
		} while (next_permutation (a.begin() + 1, a.end()));
	}

	if (b[0] != '-') {
		sort (b.begin(), b.end());
		do {
			if (b[0] != '0')
				break;
		} while (next_permutation (b.begin(), b.end()));
	} else {
		sort (b.begin() + 1, b.end(), greater <char>());
	}
	cout << atoi (a.c_str()) - atoi (b.c_str());
	return 0;
}
