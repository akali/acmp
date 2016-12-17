#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

const int MaxN(1000), MaxM = (1000);
int pi[MaxN + MaxM + 10];

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	string s, t; cin >> s >> t;
	int res = 0;
	bool used[MaxN + MaxM + 10];
	//cout << s << endl << t;
	//s = t + '$' + s;
	//cout << s << endl;
	memset (used, 0, sizeof used);
	for (int k = 0; k < t.size(); ++k) {
		t = t[t.size() - 1] + t;
		t.resize (t.size() - 1);
		string q = t + '#' + s;
		for (int i = 1; i < q.size(); ++i) {
			//cout << i << " ";
			int j = pi[i - 1];
			while (j > 0 && q[i] != q[j])
				j = pi[j - 1];
			if (q[j] == q[i])
				++j;
			pi[i] = j;
			if (j == t.size() && !used[i])
				++res,
				used[i] = true;
			//cout << j << " ";
		}
		//cout << endl;
	}
	cout << res;
	return 0;
}