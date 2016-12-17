#include <iostream>
#include <cstdio>
#include <climits>
#include <cstring>
#include <string>
 
using namespace std;
 
const int MaxN = 5001;

int n, k;
short int dp[MaxN][MaxN];
string s;

int f (int l, int r) {
	if (r < l) return -1;
	if (l == r)	return 1;
	if (s[l] == s[r]) return f (l + 1, r - 1);
	short int &res = dp[l][r];
	if (~res) return res;
	if (f (l + 1, r - 1) + 1 <= k) return res = f (l + 1, r - 1) + 1;
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
 
	cin >> n >> k >> s;
	int res = 0;
	
	memset (dp, 255, sizeof dp);

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (f (i, j) != -1 && f (i, j) != INT_MAX / 10000)
				res++;
	
	cout << res + n;
		
	return 0;
}
