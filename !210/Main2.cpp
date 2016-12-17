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
 
long long ModBinPow (int n, int x, int Mod) {
    if (x == 1) {
        return n;
    }
    if (x & 1) {
        long long d = n;
        return ((ModBinPow (n, x - 1, Mod) % Mod) * (d % Mod)) % Mod;
    } else {
        long long d = ModBinPow (n, x / 2, Mod);
        return d * d % Mod;
    }
}
 
int main () {
    freopen ("input.txt", "r", stdin);
    #ifndef AKALI
    	freopen ("output.txt", "w", stdout);
    #endif
     
    int a; cin >> a;
    
    for (int i = 2; i * i <= a; i++) {
    	if (a % i == 0) {
    		goto l;
    	}
    }
    
    cout << a;
    return 0;

    l:
    for (int i = 1; true; i++) {
        long long Pow = ModBinPow (i, i, a);
        if (!Pow) {
            cout << i;
            return 0;
        }
    }
 
    return 0;
}
