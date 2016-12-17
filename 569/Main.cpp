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

priority_queue <pair <int, int>, vector <pair <int, int> >, less 	<pair <int, int> > > p;
priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > q;

pair <int, int> res[MaxN];

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef lcl
		freopen ("output.txt", "w", stdout);
	#endif

	int n, d; cin >> n >> d;
	for (int i = 0; i < n; ++i) {
		int x; scanf ("%d", &x);
		if (x == d)
			continue;
		if (x > d)
			p.push (make_pair (x, i));
		else
			q.push (make_pair (x, i));
	}
	
	while (!p.empty ()) {
		pair <int, int> Min = q.top(); q.pop();
		pair <int, int> Max = p.top(); p.pop();

		int k = d - Min.first;
		
		res[Min.second] = make_pair (Max.second, k);
		
		Max.first -= k;

		if (Max.first == d)
			continue;
		
		if (Max.first > d)
			p.push (Max);
		else
			q.push (Max);
	}

	for (int i = 0; i < n; ++i) {
		if (!res[i].first && !res[i].second)
			cout << "0 0\n";
		else
			cout << res[i].first + 1 << " " << res[i].second << endl;
	}

	return 0;
}
