#include <fstream> 
#include <iostream> 
#include <algorithm> 
using namespace std; 
int k, a; 
bool ok () { 
	int m[4] = {a / 1000, a / 100 % 10, a / 10 % 10, a % 10}; 
	sort (m, m + 4); 
	int r2 = m[0] * 1000 + m[1] * 100 + m[2] * 10 + m[3], r1 = m[3] * 1000 + m[2] * 100 + m[1] * 10 + m[0]; 
	if (r1 - r2 != a) {
	    a = r1 - r2;
		return true;  
	}
	return false; 
}
 
int main() { 
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	cin >> a;
	int Os = 0;
	while (ok ())
		Os++;
	cout << a << endl << Os;
	return 0; 
}
