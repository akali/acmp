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

/* Template */

#define ll long long
#define foreach(it, S) for(__typeof (S.begin()) it = S.begin(); it != S.end(); it++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MN(a, b) a = min (a, b)
#define MX(a, b) a = max (a, b)
#define endl '\n'

#define fname ""

#define nxtnt getNext <int>()
#define nxtll getNext <ll>()

template <typename T> inline T getNext () { T s = 1, x = 0, c = getc(stdin); while (c <= 32) c = getc(stdin); if (c == '-')	s = -1, c = getc(stdin); while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getc(stdin); return x * s; }
const double eps = 1e-9;

bool Equals (double x, double y) { return abs (x - y) < eps; }
bool Less (double x, double y) { return (x) < y - eps; }
bool LessOrEqual (double x, double y) { return (x) < y + eps; }

const int MaxN = int (1e5) + 256;

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	
	int n = nxtnt;
	
	int k = 0, s = 0, p = 0;
	
	k = n / 144;
	n = n % 144;
	
	if (n >= 10 * 10) {
		k++;
		n = 0;
	} else {
		s = n / 12;
		n %= 12;
	}
	
	if (n == 11 || n == 10) {
		s++;
		p = 0;
	} else {
		p = n;
	}
	
	if (s >= 10)
		s = 0, k++;
	
	cout << k << " " << s << " " << p;
	
	return 0;
}

