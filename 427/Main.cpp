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

long long a[MaxN];

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef lcl
		freopen ("output.txt", "w", stdout);
	#endif

	int n; cin >> n;
	
	long long sum = 0;
	
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	
	sort (a, a + n);
	
	long long cur = a[0];
	
	bool flag = true;
	
	for (int i = 1; i < n - 1; ++i) {
		cout << cur << " " << a[i] << endl;
		/* if (cur > a[i]) {
			flag = false;
			break;
		} */
		if (cur + 1 < a[i]) {
			cout << cur + 1;
			break;
		}
		cur += a[i];
	}
	// if (!flag)
		cout << sum + 1;
	
	return 0;
}

