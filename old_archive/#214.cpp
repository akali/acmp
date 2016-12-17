#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);	
	#endif

	int n, m; cin >> n >> m;
	if ((n % 2 == 0) && (m % 2 == 0))
		cout << 2;
	else
		cout << 1;
	return 0;
}