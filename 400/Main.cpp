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

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif
	pair <int, int> M[6];
	for (int i = 0; i < 6; i++) {
		int l, r;
		cin >> l >> r;
		if (l > r)
			swap (l, r);
		M[i] = make_pair (l, r);
	}
	
	sort (M, M + 6);
	bool is = false;
	if (M[0].first  == M[1].first  && M[0].first  == M[2].first && M[0].first == M[3].first && 
		M[0].second == M[1].second && M[0].second == M[5].first && M[5].first == M[4].first &&
		M[2].second == M[3].second && M[2].second == M[4].second && M[5].second == M[2].second)
			is = true;

	if (is)
		cout << "POSSIBLE";
	else
		cout << "IMPOSSIBLE";

	return 0;
}
