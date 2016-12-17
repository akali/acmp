#include <bits/stdc++.h>

using namespace std;

long long q (int i) {
	for ()
}

long long take (int d) {
	for (long long i = 1; true; i++) {
		if (q (i) == d) {
			return i;
		}
	}
}

int main () {
	freopen ("precalc.out", "w", stdout);
	for (int i = 1; i <= 5000; i++) {
		long long d = take (i);
		cout << "a[" << i << "] = " << d << endl;
	}
}