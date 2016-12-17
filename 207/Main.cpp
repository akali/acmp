#include <iomanip>
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

const int MaxN = (int)(1e6);

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef _LOCAL
		freopen ("output.txt", "w", stdout);
	#endif

	int n; cin >> n;

	double x, y;

	double d = 0.70710678118654752440084436210485;

	while (n--) {
		int a, b; cin >> a >> b;

		if (a == 1) {
			x += b;
		} else {
			if (a == 2) {
				x += d * b;
				y += d * b;
			} else {
				if (a == 3) {
					y += b;
				} else {
					if (a == 4) {
						x -= d * b;
						y += d * b;
					} else {
						if (a == 5) {
							x -= b;
						} else {
							if (a == 6) {
								x -= d * b;
								y -= d * b;
							} else {
								if (a == 7) {
									y -= b;
								} else {
									x += d * b;
									y -= d * b;
								}
							}
						}
					}
				}
			}
		}
	}

	cout << setprecision (4) << fixed << y << " " << x << endl;

	return 0;
}
