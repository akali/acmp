#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

typedef long long i64;

i64 B[20];
i64 D[20];

i64 count(i64 x, int y) {
	i64 result = 0;
	int a[20];
	int n = 0;
	if (x == 0) return 0;
	do {
		a[n++] = x % 10;
		x /= 10;
	} while (x > 0);
	int t = 0;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < a[i]; ++j) {
			if (j == y) {
				++t;
			}
			result += D[i] + t * B[i];
			if (j == y) {
				--t;
			}
		}
		if (a[i] == y) {
			++t;
		}
	}
	result += t;
	return result;
}

int main() {
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	
	i64 a, b;
	cin >> a >> b;

	assert((1 <= a) && (a <= 1000000000000LL) && (1 <= b) && (b <= 1000000000000LL) && (a <= b));
	B[0] = 1;
	for (int i = 1; i <= 12; ++i) {
		B[i] = B[i - 1] * 10;
	}
	D[0] = 0;
	D[1] = 1;
	for (int i = 2; i <= 12; ++i) {
		D[i] = D[i - 1] * 10 + B[i - 1];
	}

	i64 result = 0;
	for (int i = 1; i <= 9; ++i) {
		result += (count(b, i) - count(a - 1, i)) * i;
	}
	
	cout << result << endl;
	return 0;
}
