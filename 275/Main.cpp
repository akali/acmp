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

	int n; cin >> n;
	while (n--) {
		string s; cin >> s;
		int q = 0;
		while (s.size() % 3 > 0)
			s = '0' + s;
		while (!s.empty()) {
			q = q + (s[0] - '0') * 4 + (s[1] - '0') * 2 + s[2] - '0';
			q %= 7;
			s.erase (0, 3);
		}
		if (q % 7) {
			cout << "No";
		} else {
			cout << "Yes";
		}
		cout << endl;
	}

	return 0;
}
