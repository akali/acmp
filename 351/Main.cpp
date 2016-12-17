#include <climits>
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

using namespace std;

const int MaxN = (int)(1e5);
int d[MaxN + 50];
int q[27][MaxN + 50];
int sz[27];
int start[27];

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
	// #ifndef AKALIDBG
		freopen ("output.txt", "w", stdout);
	#endif

	int n, k; cin >> n >> k;
	string s; cin >> s;
	for (int i = 0; i < s.size(); i++) {
		s[i] -= 'A';
		q[int (s[i])][sz[s[i]]] = i;
		sz[int (s[i])]++;
	}
	fill (d, d + n + 10, INT_MAX);
	d[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int a = 0; a < 26; a++) {
			int j = start[a];
			for (j = start[a]; j < sz[a]; j++) {
				int ind = q[a][j];
				if (ind <= i) continue;
				if (ind > k + i) break;
				int K = d[i];
				if (a != s[i]) {
					K++;
				}
				d[ind] = min (d[ind], K);
			}
			start[a] = j - 1;
		}
	}
	cout << d[n - 1];
	return 0;
}
