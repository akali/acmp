#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int a[7], b[7];

bool Check () {
	for (int i = 1; i <= 6; ++i)
		if (a[i] != b[i])
			return false;
	return true;
}

int main () {
	for (int i = 1; i <= 6; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= 6; ++i) {
		cin >> b[i];
	}
	
	return 0;
}
