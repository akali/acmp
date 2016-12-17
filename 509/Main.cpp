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
#include <queue>
#include <fstream>
#include <climits>
#include <ctime>

using namespace std;

const int MaxN = (int)(1e6);

string x, y;
int res = INT_MAX;

typedef unsigned long long ull;

struct A {
	string a, b;
	int k;
	A (const string &A, const string &B, const int &q) {
		a = A;
		b = B;
		k = q;
	}
};

set <pair <ull, ull> > S;

const int pr1 = 997;

ull take (string &s) {
	ull h1 = 0;
	for (int j = 0; j < s.size(); j++)
         h1 = h1 * pr1 + (s[j] - 'A');
    return h1;
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	string a, b;
	cin >> a >> b;
	cin >> x >> y;
	queue <A> q;
	q.push (A (a, b, 0));
	while (!q.empty ()) {
		a = q.front().a;
		b = q.front().b;
		int k = q.front().k;
		q.pop();
		if (!S.insert (make_pair (take (a), take (b))).second) {
			continue;
		}
		if (a == x && b == y) {
			cout << k;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			if (a[i] == '#') {
				swap (a[i], b[i]);
				q.push (A (a, b, k + 1));
				swap (a[i], b[i]);
				if (i == 0 || i == 2 || i == 1) {
					swap (a[i], a[i + 1]);
					q.push (A (a, b, k + 1));
					swap (a[i], a[i + 1]); 	
				}
				if (i == 3 || i == 2 || i == 1) {
					swap (a[i], a[i - 1]);
					q.push (A (a, b, k + 1));
					swap (a[i], a[i - 1]);
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			if (b[i] == '#') {
				swap (a[i], b[i]);
				q.push (A (a, b, k + 1));
				swap (a[i], b[i]);
				if (i == 0 || i == 2 || i == 1) {
					swap (b[i], b[i + 1]);
					q.push (A (a, b, k + 1));
					swap (b[i], b[i + 1]); 	
				}
				if (i == 3 || i == 2 || i == 1) {
					swap (b[i], b[i - 1]);
					q.push (A (a, b, k + 1));
					swap (b[i], b[i - 1]);
				}
			}
		}
	}
	cout << -1;
	return 0;
}
