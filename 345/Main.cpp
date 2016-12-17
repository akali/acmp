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

map <string, vector <string> > M;
map <string, bool> U;
map <string, int> K;
bool ans[111];
string p;
bool FirstTime = false;

bool dfs (string &q) {
	FirstTime = true;
	U[q] = true;
	bool res = 0;
	for (int i = 0; i < M[q].size(); i++) {
		if (!U[M[q][i]]) {
			res |= dfs (M[q][i]);
		} else {
			if (M[q][i] == p)
				return true;
		}
	}
	return res;
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	int n; cin >> n;
	int i = 0;
	while (n--) {
		string k; cin >> k;
		K[k] = i++;
		int q; cin >> q;
		while (q--) {
			string p; cin >> p;
			M[k].push_back (p); 
		}
		string pp; cin >> pp;
	}

	for (map <string, vector <string> > :: iterator it = M.begin(); it != M.end(); it++) {
		p = it -> first;
		FirstTime = false;
		ans[K[p]] = dfs (p);
	}
	for (int j = 0; j < i; j++) {
		if (ans[i])
			puts ("YES");
	    else
	    	puts ("NO");
	}
	return 0;
}
