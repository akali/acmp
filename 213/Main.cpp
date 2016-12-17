#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

int c[100];

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> c[i];
    int Full; cin >> Full;
    int penalty = 0;
    int res = 0;
    int q; cin >> q;
    while (q--) {
    	int co = 0;
    	bool full = true;
    	for (int i = 0; i < n; i++) {
    		bool d; cin >> d;
    		if (d) {
    			co += c[i];
    		} else {
    			full = false;
    		}
		}
		if (full) {
			co += Full;
		}
		res = max (res, co - penalty);
		penalty += 2;
    	cout << res << endl;
    }

	return 0;
}
