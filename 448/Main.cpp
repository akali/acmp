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

bool p[2 * MaxN];

void sieve () {
	memset (p, true, sizeof p);
	p[0] = p[1] = false;
	for (int i = 2; i <= MaxN; i++) {
		if (p[i]) {
			for (int j = i + i; j <= MaxN; j += i)
				p[j] = false;
		}
	}
}

bool used[550000];

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef lcl
		freopen ("output.txt", "w", stdout);
	#endif

	sieve();

	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		if (used[i])
			continue;
		for (int j = n - i; j >= 0; j--) {
			if (used[j])
				continue;
			if (p[i + j]) {
				used[i] = used[j] = true;
				cout << i << " " << j << endl;
				break;
			}
		}
	}

	/*for (int i = 1; i <= n; i++)
		if (!used[i])
			// cout << i << " ";*/
	
	return 0;
}
