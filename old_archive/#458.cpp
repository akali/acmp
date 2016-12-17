#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int n, a[200];
string s;

void rec (vector <vector <char> > &d, int x, int y) {
	if (x == n) {
		
	}
}

int main () {
    freopen ("input.txt", "r", stdin);
	cin >> n;                                        
	vector <char> d[n + 1];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> s;
	int k = s.size() / n;
	int p = 0;
	for (int i = 0; i < n; i++) {
		for (int j = p; j < p + k; j++) {
		 	d[a[i] - 1].push_back(s[j]);
		}
		p += k;
	}
	rec (d, 0, 0);
	return 0;
}                                 