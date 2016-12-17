#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> l, r;
int R, x, y, n;
 
int main(){
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		l.push_back (x);
		r.push_back (y);
	}
	
	sort (l.begin(), l.end());
	sort (r.begin(), r.end());
	
	R = r[0] - l[0];
	
	for (int i = 1; i < n; i++)
		R += ((l[i] <= r[i - 1]) ? (r[i] - r[i - 1]) : (l[i - 1] <= r[i - 1] && r[i - 1] < l[i] && l[i] <= r[i]) ? (r[i] - l[i]) : 0);
	cout << R;
}
