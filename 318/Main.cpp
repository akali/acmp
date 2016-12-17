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

void printMask (int mask) {
	for (int i = 5; i >= 0; --i) {
		cout << ((mask & (1 << i)) > 0);
	}
	cout << endl;
}

int get (vector <bool> &x) {
	int res = 0;
	int cur = 1;
	for (int i = 0; i < x.size(); ++i)
		cout << x[i];
	cout << endl;
	for (int i = x.size() - 1; i >= 0; --i) {
		res += x[i] * cur;
		cur += cur;
	}
	return res;
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef lcl
		freopen ("output.txt", "w", stdout);
	#endif

	for (int i = 0; i <= 32; ++i) {
		cout << i << " "; printMask (i);
	}

	int n; cin >> n;

	vector <bool> v;

	for (int i = 0; i < 30; ++i) {
		if ((1 << i) > n)
			break;
		v.push_back ((n & (1 << i)) > 0);
	}
	v.push_back (0);
	
	reverse (v.begin(), v.end());

	int was = -1;
	
	for (int i = 0; i < v.size(); ++i) {
		if (v[i]) {
        	if (was == -1)
	        	was = i;
        	continue;
        }
        if (was) {
     		swap (v[was], v[i]);   	
			break;
		}
	}

	cout << was << endl;

	cout << get (v);

	return 0;
}
