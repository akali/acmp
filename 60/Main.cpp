#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

const int MaxN = (int)(1e6);

bool s[MaxN];
int pr[MaxN], prSz = 0;
int UltraPrime[MaxN], USz;

void sieve() {
	memset (s, 1, sizeof s);
	s[0] = s[1] = false;
	pr[prSz++] = 2;
	for (int i = 2; i <= MaxN; ++i)
		if (s[i]) {
			pr[prSz++] = i;
			if (i * 1ll * i <= MaxN)
				for (int j = i * i; j <= MaxN; j += i)
					s[j] = false;
		}
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif
	sieve();
	int n; cin >> n;
	for (int i = 1; i < prSz; i++) {
		if (s[i]) {
			UltraPrime[USz++] = (pr[i]);
		}
	}
    /*
	for (int i = 0; i < 10; i++)
		cout << UltraPrime[i] << " ";
	*/
	cout << UltraPrime[n - 1];
	return 0;
}
