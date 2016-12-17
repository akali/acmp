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
	#ifndef lcl
		freopen ("output.txt", "w", stdout);
	#endif

	string s; cin >> s;
	char MN = *min_element (s.begin(), s.end());
	char MX = *max_element (s.begin(), s.end());
	if (MN == MX) {
		cout << MN;
		return 0;
	}
	vector <int> v, t;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == MN)
			v.push_back (i);
		if (s[i] == MX)
			t.push_back (i);
	}
	int l = 0, r = s.size() - 1;
	for (int i = 0; i < v.size(); ++i) {
		int L = v[i];
		int R = *upper_bound (t.begin(), t.end(), L);
		
		if (L <= R && R - L + 1 < r - l + 1)
			l = L, r = R;
	}
	for (int i = 0; i < t.size(); ++i) {
		int L = t[i];
		int R = *upper_bound (v.begin(), v.end(), L);
		
		if (L <= R && R - L + 1 < r - l + 1)
			l = L, r = R;
	}
	// cout << l << " " << r << endl;
	cout << s.substr (l, r - l + 1);
	return 0;
}

