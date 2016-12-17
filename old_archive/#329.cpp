#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MaxN = 1000;

int n;
int a[MaxN], d[MaxN];

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	d[0] = a[0];
	d[1] = min (a[0], a[1]);

	for (int i = 2; i < n; i++) {
		d[i] = a[i] + max (d[i - 1], d[i - 2]);
		// cout << d[i] << " ";
	}
	cout << d[n - 1] << endl;

	vector <int> path;
	path.push_back (n - 1);
	int This = n - 1;
	while (true) {
		if (This == 1) {
			if (d[This - 1] + a[This] == d[This]) {
			    path.push_back (This - 1);
				path.push_back (This);
				break;
			}
		}
		if (!This) {
			path.push_back (This);
			break;
		}
		if (d[This - 1] == d[This] + a[This]) {
		    path.push_back (This - 1);
			This--;
		} else {
			path.push_back (This - 2);
			This -= 2;
		}
	}
	reverse (path.begin(), path.end());
	for (int i = 0; i < path.size(); i++)
		cout << a[i] + 1 << " ";
	return 0;
}
