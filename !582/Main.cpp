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

bool Ended;

int a[7], b[7];

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif
	
	for (int i = 0; i < 6; i++)
		cin >> a[i];
	for (int i = 0; i < 6; i++)
		cin >> b[i];
	
	do {
		bool ended = true;
		for (int i = 0; i < 6; i++)
			if (a[i] != b[i]) {
				ended = false;
				break;
			}
		if (ended && !Ended) {
			cout << "YES";
			Ended = true;
		}
	} while (next_permutation (a, a + 6));

	if (!Ended)
		cout << "NO";

	return 0;
}
