#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	int n; cin >> n;
	int S = int (sqrt (double (n)));
	for (int i = 2; i <= S; i++) {
		if (n % i == 0) {
			cout << n / i << " " << n - (n / i);
			return 0;
		}
	}
	cout << 1 << " " << n - 1 << endl;
	return 0;
}
