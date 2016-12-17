#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
long long l, r, d[77];
long long b[77], cur[77], k = 0;

long long sum (long long n, int num) {
	k = 0;
	int t = 0;
	long long res = 0;
	memset (cur, 0, sizeof cur);
	while (n) cur[++k] = n % 10, n /= 10;
	reverse (cur + 1, cur + 1 + k);
	for (int i = 1; i <= k; ++ i) {
		for (int j = 0; j < cur[i]; j ++ ) {
			if (j == num) t++;
			res += d[k - i] + t * b[k - i];
			if (j == num) t--;
		}
		if (cur[i] == num) ++t;
	}
	return res + t;
}

int main()
{

cin >> l >> r;
b[0] = 1;
d[1] = 1;
for (int i = 1; i <= 14; i ++ ) b[i] = b[i - 1] * 10;
for (int i = 1; i <= 14; i ++ ) b[i] = b[i - 1] * 10;
for (int i = 2; i <= 14; i ++ ) d[i] = d[i - 1] * 10 + b[i - 1];
long long ans = 0;
//for (int i = 1; i <= 9; i ++ ) ans += i * (sum(r, i) - sum(l - 1, i));

cout << sum(l, 1);
 return 0;
}