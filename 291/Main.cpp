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

int M[256];
string s[1500];
string d;

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	} cin >> d;
	for (int i = 0; i < d.size(); i++)
		M[d[i]]++;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int p[256];
		for (int j = 0; j < 256; j++)
			p[j] = M[j];
		for (int j = 0; j < s[i].size(); j++) {
			if (!p[s[i][j]]) {
				goto l;
			}
			p[s[i][j]]--;
		}
		ans++;
		l:;
	}
	cout << ans;

	return 0;
}
