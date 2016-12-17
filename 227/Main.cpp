#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
 
 
using namespace std;
 
int func(int n) {
	if (n <= 1) return n - 1;
    int res = 0;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0){
            res += i;
            n /= i;
        }
    }
    if (n != 1)
        res += n;
    return res;
}

int sign (int a) {
    return a < 0 ? -1 : 1;
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int beg = -1, end;
    cin >> beg >> end;
    if (beg == end) {
        cout << 0;
    } else if (beg != 0 && end % beg == 0) {
        if (sign (beg) == sign (end)) {
            cout << func (end / beg);
        }
        else
            cout << -1;
    }
    else
        cout << -1;
    return 0;
}
