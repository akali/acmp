#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif
	long long l, r, a[10];
	a[1] = 6;
	a[2] = 28;
	a[3] = 496;
	a[4] = 8128;
	a[5] = 33550336;
	a[6] = 8589869056;
	a[7] = 137438691328; 
	a[8] = 2305843008139952128;
	set <long long> ans;
	cin >> l >> r;
	for (int i = 0; i <= 8; i++) {
		long long q = a[i];
		if (q >= l && q <= r)
			ans.insert (q);
		if (q > r)
			break;
	}
	
	if (ans.empty())
		cout << "Absent";
	else
		for (set <long long> :: iterator i = ans.begin(); i != ans.end(); i++)
			cout << (*i) << endl;
	return 0;
}
