#include <iostream>
#include <cstdio>

using namespace std;

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	long long n, k, result = 0; cin >> n >> k;

	for (int i = 1; i <= k; i++) {
		result += n * i - (2 * i - 1);
	}
	cout << result + 1;

	return 0;
}
