#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string res[111];
int c[111];

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> c[i], res[i] = "no";
    int k; cin >> k;
    while (k--) {
    	int t; cin >> t;
    	c[t - 1]--;
    	if (c[t - 1] <= -1) {
    		res[t - 1] = "yes";
    	}
    }
    for (int i = 0; i < n; i++)
    	cout << res[i] << endl;
}
