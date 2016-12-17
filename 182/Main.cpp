#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define foreach(it, S) for (__typeof (S.begin()) it = S.begin(); it != S.end(); it++)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define _ ios_base :: sync_with_stdio(false); cin.tie(NULL);

#ifdef inputf
	#define fname ""
#else
	#define fname ""
#endif

const double eps = 1e-9;
const int MaxN = int(2e5) + 256;
const int MOD = int(1e9) + 7;

template <typename T> inline T gcd(T a, T b) {
	return b ? gcd (b, a % b) : a;
}

inline bool Palindrome(const string& s) {
	return equal(s.begin(), s.end(), s.rbegin());
}

struct point {
	int x, y;
	point read() {
		scanf("%d%d", &x, &y);
		return *this;
	}
};

int main() { // _
	#ifdef inputf
		freopen(fname".in", "r", stdin);
		freopen(fname".out", "w", stdout);
	#endif
	
	point a = point().read(), b = point().read(), c = point().read();
	
	
	
	return 0;
}

