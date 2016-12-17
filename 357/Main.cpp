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
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	string s; cin >> s;
	static int a, b;	
	for (int i = 0; i < s.size(); i++) {
		if (i % 2 == 0)
			a += s[i] - '0';
		else
			b += s[i] - '0';
	}

	if (abs (a - b) % 11 == 0)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
