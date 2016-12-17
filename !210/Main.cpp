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

bool prime (int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

long long BinPow (int n, int x) {
    if (!x)
    	return 1ll;
    if (x == 1) {
        return n;
    }
    if (x & 1) {
        long long d = n;
        return ((BinPow (n, x - 1)) * (d));
    } else {
        long long d = BinPow (n, x / 2);
        return (d * d);
    }
}

map <long long, long long> A;
set <long long> q;

int main () {
	#ifdef AKALI
		system ("cls");
	#endif
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif
	
	int a; cin >> a;
	if (prime (a)) {
		cout << a;
		return 0;
	}
	
	// cout << a << endl;
	
	long long int ddd = a;
	long long res = 1;
	long long int tmp = 2;
	
	while (ddd > 1) {
		if (ddd % 2 == 1)
			goto l;
		ddd /= 2;
		// cout << ddd << endl;
	}

	// for (tmp = 2; tmp * tmp <= a; tmp++);
    // a = tmp;
    // cout << a << endl;
   	
   	if (a == 4)
   		cout << 2;

   	if (8 <= a && a <= 256)
   		cout << 4;
   	
   	if (512 <= a && a <= 16777216)
   		cout << 8;
   	
   	if (16777216 < a)
   		cout << 16;
   	
	return 0;

	l:;
	
	ddd = a;
	for (long long int i = 2; i * i <= ddd; i++) {
		if (ddd % i == 0) {
			A[i]++;
			q.insert (i);
			ddd /= i;
			i--;
		}
	}

	A[ddd]++;
	q.insert (ddd);

	long long int b = 1ll;

	for (set <long long> :: reverse_iterator i = q.rbegin(); i != q.rend(); i++) {
		#ifdef AKALI
			cout << *i << " " << A[*i] << endl;
		#endif
		// for (int d = 0; d < A[*i]; d++)
			
		b *= BinPow (*i, int (sqrt (sqrt (1.0 * ((A[*i] + 1) / (2))))));
	}
	
	#ifdef AKALI
		cout << endl;
	#endif

	cout << b;
	return 0;
}
