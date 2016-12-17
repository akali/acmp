#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define foreach(it, S) for(__typeof (S.begin()) it = S.begin(); it != S.end(); it++)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define _ ios_base :: sync_with_stdio (false); cin.tie (NULL);

const double eps = 1e-9;
const int MaxN = int (1e5) + 256;
const int MOD = int (1e9) + 7;

double f (double x) {
	double q = floor (x);
	double w = x - q;
	w /= 10.0;
	return q + w;
}

int main () { // _
	#ifdef inputf
		freopen (".in", "r", stdin);
	#endif
	
	double a, p, b; cin >> a >> p >> b;
	int k = 0;
	double x = a;
	p /= 100.0;
	
	// cout << setprecision (4) << fixed << 100.1234 << " " << f (100.1234) << endl;
	
	while (a < b) {
		a += (a * p); 
		a = floor (a);
		++k;
	}
	
	cout << k;
	
	return 0;
}

