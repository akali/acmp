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

int gcd (int a, int b) {
	return (a ? gcd (b % a, a) : b);
}

struct AAA {
	double first;
	pair <int, int> second;
	bool operator < (const AAA &a) const {
		if (a.first == first) {
			if (a.second.first == second.first) 
				return a.second.second < second.second;
			return a.second.second < second.second;
		}
		return a.first < first;
	}
	AAA (pair <double, pair <int, int> > &d) {
		first = d.first;
		second = d.second;
	}
};  	

vector <AAA> X;

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (gcd (i, j) == 1) {
				pair <double, pair <int, int> > d = make_pair (double (double (i) / double (j)), make_pair (j, i));
				X.push_back (AAA (d));
			}
		}
	}
	sort (X.begin(), X.end());
	for (int i = 0; i < X.size(); i++) {
		cout << X[i].second.first << "/" << X[i].second.second << endl; 
	}
	return 0;
}
