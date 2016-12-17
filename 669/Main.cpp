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

	int n; cin >> n;
	int N = n;

	vector <int> v;
	vector <int> l (n + 2, 0);
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			while (n % i == 0) {
				v.push_back (i);
				l[i]++;
				n /= i;
			}
		}
	} if (n != 1) l[n]++, v.push_back (n);

	if (v.size() == 1) {
		cout << "-1 -1";
		return 0;
	}

	for (int i = 2; i <= min (4, N); i++) {
		// cout << i;
		while (l[i] > 1) {
			l[i] -= 2;
			l[i + i]++;
		}
	}

	vector <int> k;
	for (int i = N; i >= 2; --i)
		if (l[i])
			k.push_back (i);
	
	int last = k.back(), li = k.size() - 1;
	for (int i = k.size() - 2; i >= 1; --i) {
		if (k[i] * k[li] < 10) {
			li = i;
			k[i] *= k[li];
			k[li] = -1;
		}
	}
	
	for (int i = 0; i < k.size(); ++i)
		if (k[i] != -1)
			cout << k[i];

	cout << endl;
	
	/* for (int i = v.size() - 1; i >= 0; --i)
		cout << v[i]; */

	return 0;
}
