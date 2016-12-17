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

string s;

int m[20];
int k[1000];

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		m[s[i] - '0']++;
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int l = 0; l < 10; l++) {
				m[i]--;
				m[j]--;
				m[l]--;
				if (m[i] >= 0 && m[j] >= 0 && m[l] >= 0) {
					k[i * 100 + j * 10 + l]++;
				}
				m[i]++;
				m[j]++;
				m[l]++;
			}
		}
	}

	int res = 0;
	
	for (int i = 100; i <= 999; i++)
		if (k[i])
			res++;
	
	cout << res;


	return 0;
}
