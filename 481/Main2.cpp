#include <bits/stdc++.h>

using namespace std;

int n;
long long s[2000];
long long d[2000][2000];
long long mod = 1000000000;

long long f (int l, int r) {
    if (r - l <= 0)
        return !(r - l);
    long long &q = d[l][r];
    if (q != -1)
        return q;
    q = ((f (l + 1, r) + f (l, r - 1)) % mod - f (l + 1, r - 1) + mod) % mod;
    q = (q + mod) % mod;
    if (s[l] == s[r])
    	q += f (l + 1, r - 1) + 1;
    return q % mod;
}

main () {
    memset (d, 255, sizeof d);
    freopen ("tshirts.in", "r", stdin);
    freopen ("tshirts.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i)
    	cin >> s[i];
    cout << f (0, n - 1);
	return 0;
}

