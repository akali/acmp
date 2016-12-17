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

long long P[6000];

bool used[6000];

int take (long long k) {
	int del = 1;

	for (int i = 1; i * i <= k; i++)
		if (k % i == 0)
			del++;	

	return del;
}

int main () {
	freopen ("input.txt", "r", stdin);

	freopen ("precalc.out", "w", stdout);

	ofstream PreCalc ("precalc.out");

	int p = 0;

	init();

	for (long long i = 0; i <= 1000000000000001ll; i++) {		
		int d = take (i);

		if (used[d] || P[d])
			continue;
		
	    used[d] = true;
	    cout << "P[" << d << "] = " << i << ";\n";
	    cerr << "P[" << d << "] = " << i << ";\n" << p++;
		if (i % 100)
			cerr << i << endl;
	}

	return 0;
}
