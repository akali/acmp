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

struct container {
	int A, B, C;
	container (int a = 0, int b = 0, int c = 0) {
		A = a;
		B = b;
		C = c;
	}
	bool operator <(container t) const {
		if (t.A == A) {
			if (t.B == B) {
 				return t.C > C;
 			}
 			return t.B > B;
		}                  
		return t.A > A;
	}
};

// map <container, bool> used;

container x;
int A, B, C;

void remake () {
	A = x.A;
	B = x.B;
	C = x.C;
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef lcl
		freopen ("output.txt", "w", stdout);
	#endif

	int a, b, c, t;
	cin >> a >> b >> c >> t;
	
	queue <container> q;
	q.push (container (a, 0, 0));
	// used[container (a)] = true;

	vector <vector <vector <long long> > > d;
	d.resize (a + 1);
	for (int i = 0; i <= a; ++i) {
		d[i].resize (b + 1);
		for (int j = 0; j <= b; ++j) {
			d[i][j].resize (c + 1);
			fill (d[i][j].begin(), d[i][j].end(), INT_MAX * 1ll);
		}
	}
	d[a][0][0] = 0;
	while (!q.empty ()) {
		x = q.front(); q.pop();
		remake ();
		long long T = d[A][B][C];
		// cout << A << " " << B << " " << C << endl;
		// A -> B
		B = min (b, B + A);
		A = max (A - B, 0);
		if (d[A][B][C] >= T + 1) {
			d[A][B][C] = T + 1;
			q.push (container (A, B, C));
		}
		remake ();
		// B ->= A
		A = min (a, B + A);
		B = max (B - A, 0);
		if (d[A][B][C] >= T + 1) {
			d[A][B][C] = T + 1;
			q.push (container (A, B, C));
		}
		remake ();
		
		C = min (c, C + A);
		A = max (A - C, 0);
		if (d[A][B][C] >= T + 1) {
			d[A][B][C] = T + 1;
			q.push (container (A, B, C));
		}
		remake ();
		A = min (a, C + A);
		C = max (C - A, 0);
		if (d[A][B][C] >= T + 1) {
			d[A][B][C] = T + 1;
			q.push (container (A, B, C));
		}
		remake ();
		C = min (c, B + C);
		B = max (B - C, 0);
		if (d[A][B][C] >= T + 1) {
			d[A][B][C] = T + 1;
			q.push (container (A, B, C));
		}
		remake ();
		B = min (b, B + C);
		C = max (C - B, 0);
		if (d[A][B][C] >= T + 1) {
			d[A][B][C] = T + 1;
			q.push (container (A, B, C));
		}
		// remake ();
	}

	long long w = INT_MAX;
	
	for (int i = 0; i <= b; i++) {
		for (int j = 0; j <= c; j++) {
			w = min (w, d[t][i][j]);
			// cout << d[t][i][j] << " ";
		}
		// cout << endl;
	}
	
	if (w == INT_MAX)
		cout << "IMPOSSIBLE";
	else
		cout << w;

	return 0;
}

/**
 A -> B // B = min (b, B + A), A = max (A - B, 0);
 B -> A // A = min (a, B + A);
 A -> C C -> A
 B -> C C -> B
*/
