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

const int MaxN = 1000 + 256;

map <string, int> M;
map <string, int> Rating;

string s[MaxN], song[MaxN];
int Next[MaxN];

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef lcl
		freopen ("output.txt", "w", stdout);
	#endif

	int n; cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> song[i];
		cin >> M[song[i]];
	}

	int m, k; cin >> m >> k;

	for (int i = 0; i < m; ++i) {
		cin >> s[i];
	}

	for (int i = 0; i < k; ++i) {
		cin >> Next[i];
	}
	
	int cur = 0, nx = 0;

	for (int i = 0; i < m; ++i) {
		int end = cur + M[s[i]];
		if (nx < k && cur <= Next[nx] && Next[nx] < end) {
			cur = Next[nx];
			Rating[s[i]]--;
			nx++;
			continue;
		}
		Rating[s[i]]++;
		cur = end;
	}

	for (int i = 0; i < n; ++i) {
		cout << Rating[song[i]] << " ";
	}
	
	return 0;
}
