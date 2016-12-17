#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
  
using namespace std;
  
bool prime (__int64 n) {
    double S = sqrt (double(n));
    for (__int64 i = 2; i <= S; i ++)
        if (n % i == 0) return false;
    return true;
}
 
long long ans, res;
  
int main () {
    freopen ("output.txt", "w", stdout);
    freopen ("input.txt" , "r",  stdin);
    __int64 k, n; cin >> k >> n;
    long long deg = 1;
    while (n) {
        if (n < 10) {
            ans = ans + (n * deg);
            deg *= 10;
            break;
        }
        if (prime(n)) {
            cout << "NO";
            return 0;
        } 
        for (__int64 i = 9; i > 0; i--) {
            if (n % i == 0) {
                ans = ans + (i * deg);
                deg *= 10;
                n /= i;
                //cout << i << " " << n << endl;
                break;
            }
        }
    }
    // reverse (ans.begin(), ans.end());
    res = ans;
	// cout << res << " " << (k) << endl;
    if (res > k) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
    return 0;
}
