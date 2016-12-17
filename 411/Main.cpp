#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

const double EPS = 1e-9;

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	int a, b, c;
	cin >> a >> b >> c;
	double delta = b * b - 4 * a * c;
	// cout << delta << endl;
	if (delta == 0) {
		cout << 1 << endl;
		printf ("%f", (-b) / (2 * a));
	} else {
		if (delta < 0) {
			cout << -1;
		} else {
			cout << 2 << endl;
			printf ("%f\n", (-b + sqrt (delta)) / (2 * a));
			printf ("%f\n", (-b - sqrt (delta)) / (2 * a));
		}
	}


	return 0;
}
