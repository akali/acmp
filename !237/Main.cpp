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

char c[20][20];
int o[20][20];
bool u[20][20];
pair <int, int> p[20][20];
int n, m;

int timer;

int dx[] = {1, -1, 0,  0};
int dy[] = {0,  0, 1, -1};

int x, y;

bool dfs (int x, int y, string &s, int p = 0) {
	if (x < 0 || y < 0 || x >= n || y >= n)
		return false;

	if (o[x][y])
		return false;

	if (c[x][y] != s[p])
		return false;

	if (p == s.size() - 1)
		return true;	

	if (p >= s.size())
		return false;
		
	if (u[x][y])
		return false;
	
	u[x][y] = true;
	
	for (int i = 0; i < 4; i++) {
		int X = x + dx[i], Y = y + dy[i];

		if (dfs (X, Y, s, p + 1)) {
			::p[x][y] = make_pair (X, Y);
			return true;
		}
	}
	
	return false;
}

void rdfs (int x, int y) {
	if (x == -1 && y == -1)
		return;
	
	o[x][y] = timer;

	rdfs (p[x][y].first, p[x][y].second);
}

void out (string &s) {
	/* for (int l = 0; l < n; l++)
		for (int k = 0; k < n; k++)	
			p[l][k] = make_pair (-1, -1),
			u[l][k] = false;*/

	for (int p = 0; p < s.size(); p++) { 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (c[i][j] == s[p] && !o[i][j]) {
					o[i][j] = timer;
					goto l;
				}
			}
		}
		l:;
	}
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef _LOCAL
		freopen ("output.txt", "w", stdout);
	#endif

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> c[i][j];	
	
	string s[111];
	
	for (int i = 0; i < m; i++)
		cin >> s[i];

	// sort (s, s + m);

	// reverse (s, s + m);

	for (int i = 0; i < m; i++) {
		timer++;
		out (s[i]);
		/* cout << s[i] << endl;
		for (int i = 0; i < n; cout << endl, i++)
			for (int j = 0; j < n; j++)
				cout << o[i][j];*/
	}

	s[0] = "";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!o[i][j])
				s[0] += c[i][j];
		}
	}

	sort (s[0].begin(), s[0].end());

	cout << s[0];

	return 0;
}
