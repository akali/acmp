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

pair <int, int> t, p;

double distance () {
	return sqrt (double ((t.first - p.first) * (t.first - p.first) + (t.second - p.second) * (t.second - p.second)));
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef lcl
		freopen ("output.txt", "w", stdout);
	#endif

	pair <int, int> gopher, dog;
	cin >> gopher.first >> gopher.second >> dog.first >> dog.second;
	// cout << dog.first << " " << dog.second << endl;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		pair <int, int> tmp; cin >> tmp.first >> tmp.second;
		p = tmp;
		t = gopher;
		double x = distance () * 2, y;
		t = dog;
		y = distance ();
		if (x <= y) {
			cout << i + 1;
			return 0;
		}
	}

	cout << "NO";

	return 0;
}
