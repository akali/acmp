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
    long long value;
    bool isBegin;
    point(){}
    point(long long _value, bool _isBegin) {
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

long long n, L, R;
vector <point> a, v;

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
   
    for (int i = 0; i < a.size(); ++i) {
    	int cur = a[i].value;
    	int amount = 0;
    	for (i; i < a.size(); ++i) {
    		if (cur != a[i].value)
    			break;
    		if (a[i].isBegin)
    			amount++;
    		else
    			amount--;
    	}
    	if (amount)
    		v.push_back (point (cur, true));
    	else
    		v.push_back (point (cur, false));
    }
    
    long long totalLen = 0, segmAmount = 0, prev = v[0].value;
    cout << v[0].isBegin << " " << v[0].value << endl;
    
    for (int i = 1; i < v.size(); i++) {
        cout << v[i].isBegin << " " << v[i].value << endl;
        if (prev != v[i].value)
        	if (segmAmount & 1)
        	    totalLen = max (v[i].value - prev, totalLen);
        prev = v[i].value;
        if (v[i].isBegin)
            segmAmount++;
        else
            segmAmount--;
    }
    if (totalLen == 0)
    	totalLen = int (1e9);
    cout << totalLen;
    return 0;
}
