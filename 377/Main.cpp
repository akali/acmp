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
 
struct point {
    int value;
    bool isBegin;
    point(){}
    point(int _value, bool _isBegin) {
        value = _value;
        isBegin = _isBegin;
    }

    bool operator < (const point &b) const {
   	    if (value != b.value)
	        return value < b.value;
    	if (isBegin && !b.isBegin)
    	    return true;
    	return false;
    }
};

int n, L, R;
vector <point> a;

int main() {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> L >> R;
        a.push_back (point (L, true));
        a.push_back (point (R, false));
    }
    
    sort (a.begin(), a.end());
    int totalLen = 0, segmAmount = 1, prev = a[0].value;
    
    for (int i = 1; i < a.size(); i++) {
        if (segmAmount != 0)
            totalLen += a[i].value - prev;
        prev = a[i].value;
        if (a[i].isBegin)
            segmAmount++;
        else
            segmAmount--;
    }
    cout << totalLen;
    return 0;
}
