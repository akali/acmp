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

const int MaxN = (int)(1e7);

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	int n; cin >> n;
	cout << n - ((((n / 2 + n / 3) - n / 6) + ((n / 2 + n / 5) - n / 10) + ((n / 5 + n / 3) - n / 15)) - ((n / 2 + n / 3 + n / 5) - n / 30)) << endl;

	return 0;
}
