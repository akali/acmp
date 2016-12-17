#include <iostream>
#include <cstdio>
#include <vector>
#include <fstream>

using namespace std;

const int q = 1e6;

int d [q], d1[q], d2[q], n, m, i, j, ans;
char c;
vector <int> st;


int main () {
	ifstream G ("input.txt");
	ofstream O ("output.txt");

	G >> n >> m;
	vector < vector<int> > a (n, vector<int> (m));
	L (i, n)
		for (j = 0; j < m; ++j)
			G >> c,
			a[i][j] = (c - '0');
	memset (d, 255, sizeof d);
	
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j)
			if (!a[i][j])
				d[j] = i;
		
		st.clear();
		for (j = 0; j < m; ++j) {
			while (!st.empty() && d[st.back()] <= d[j])
				st.pop_back();
			if (st.empty ())
				d1[j] = -1;
			else
				d1[j] = st.back();
			st.push_back (j);
		}
		
		st.clear();
		for (j = m - 1; j >= 0; --j) {
			while (!st.empty() && d[st.back()] <= d[j])  st.pop_back();
			if (st.empty ())
				d2[j] = m;
			else
				d2[j] = st.back();
			st.push_back (j);
		}
		for (j = 0; j < m; ++j)
			ans = max (ans, (i - d[j]) * (d2[j] - d1[j] - 1));
	}

	O << ans;

	return 0;
}
