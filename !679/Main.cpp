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
	vector <pair <int, int> > q;
	for (int j = 2; j * j <= n; ++j) {
		pair <pair <long long, int>, pair <int, int> > Best = make_pair (make_pair (0, 0), make_pair (0, 0));
		for (int i = j; i * i <= n; ++i) {
			int tmp = n;
			long long Ans = 1;
			pair <int, int> Div = make_pair (0, 0);
			while (tmp % i == 0) {
				Div.first++;
				Div.second = i;
				Ans *= 1ll * i;
				tmp /= i;
			}
			cout << Div.first << " " << Div.second << endl;
			Best = max (Best, make_pair (make_pair (Ans, tmp), Div));
		}
		cout << endl;
		n = Best.first.second;
		q.push_back (Best.second);
	}
	for (int i = 0; i < q.size(); ++i)
		cout << q[i].second << " " << q[i].first << " ";
	return 0;
}
