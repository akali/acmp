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

int n, m[10000], r[2], t;

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> m[i];
	int l = 0, r = n - 1;
	while (l <= r) {
		if(m[r] > m[l])
			::r[t] += m[r--];
		else
			::r[t] += m[l++];
		t ^= 1;
	}
	cout << ::r[0] << ':' << ::r[1];
	return 0;
}
