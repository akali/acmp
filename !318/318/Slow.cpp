#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
 
using namespace std;
 
int take (int k) {
    int res = 0;
    while (k > 0) {
        res += k % 2;
        k /= 2;
    }
    return res;
}
 
void printMask (int mask) {
	for (int i = 0; i < 32; i++)
		cout << ((mask & (1 << i)) > 0);
}

int main () {
    // freopen ("input.txt", "r", stdin);
    #ifndef _LOCAL
        freopen ("output.txt", "w", stdout);
    #endif
 
    int k; cin >> k;
    int b = take (k);
 
    cout << b << endl;
    printMask (k); cout << endl;

    for (int mask = k + 1; true; mask++) {
        if (take (mask) == b) {
            cout << mask;
            return 0;
        }
    }
 
 
 	return 0;
}