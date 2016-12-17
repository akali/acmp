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
#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

const int MaxN = (int)(1e6);

long long res = 1000000000000001ll;
vector <int> tmp;

int psz, p[MaxN], lp[MaxN * 10];

void init () {
	for (int i = 2; i <= 5000; ++i) {
		if (!lp[i]) {
			lp[i] = i;
			p[psz++] = i;
		}
		for (int j = 0; j < psz && p[j] <= lp[i] && i * p[j] <= 5000; ++j)
			lp[i * p[j]] = p[j];
	}
}

long long binpow (long long int n, int k) {
	long long res = 1;
	long long q = n;
	while (k) {
		if (k & 1)
			res *= q;
		q *= q;
		k >>= 1;
	}
	return res;
}

void get (int d, int l) {
	// cout << k << " " << d << " " << res << endl;
	if (d == 1) {
		long long k = 1;
 		sort (tmp.begin(), tmp.end());
 		int s = 0;
 		bool canbe = true;
 		for (int i = tmp.size() - 1; i >= 0; i--) {
 			k *= binpow (p[s++], tmp[i] - 1);
 			if (k > (long long)(1e15))
 				canbe = false;
 		}
		if (canbe)
			res = min (res, k);
		return;
	}
	for (int i = l; i * i <= 5000; i++)
		if (d % i == 0) {
			tmp.push_back (i);
			get (d / i, i);
			tmp.pop_back ();
		}
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef lcl
		freopen ("output.txt", "w", stdout);
	#endif

	init ();

	int n; cin >> n;
	get (n, 2);
	cout << (res >= 1000000000000001ll ? 0 : res) << endl;
	return 0;
}
