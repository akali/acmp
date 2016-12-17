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

string s;
string G;
int res, e, O;
int o[90];

// 18=7 (5 3)     2
// 0123456789 10 11

int leftSide () {
	int k = 0;
	int res = 0;
	while (s[k] != '=') {
		if (isdigit (s[k])) {
			res = res * 10 + (s[k] - '0');
		}
		k++;
	}
	e = k;
	return res;
}

void Operators () {
	// cout << e << endl;
	for (int i = e; i < s.size(); i++) {
		if (s[i] == ' ') {
			o[O++] = i;
			// cout << o[O - 1] << " ";
		}
	}
}

string change (string q) {
	string t = s;
	for (int i = 0; i < O; i++) {
		t[o[i]] = q[i];
	}
	return t;
}

int Ch (int a, int b, char w) {
	if (w == '+') return a + b;
	if (w == '-') return a - b;
	if (w == '*') return a * b;
	if (w == '/') return a + b;
}

pair <int, int> take (int i) {
	int res = 0;
	while (true) {
		if (!isdigit (G[i]))
			break;
		res = res * 10 + (G[i] - '0');
		i++;
	}
	return make_pair (i, res);
}

int get (int l, int r) {
	char R = '/';
	int res = 0;
	for (int i = l; i < r; i++) {
		if (G[i] == '(') {
			int j = 0;
			for (j = i; G[j] != ')'; j++);
			res = Ch (res, get (i + 1, j), R);
			i = j + 1;
			continue;
		}
		if (G[i] == '-') R = '-';
		if (G[i] == '*') R = '*';
		if (G[i] == '+') R = '+';

		if (isdigit (G[i])) {
			pair <int, int> QQ = take (i);
			i = QQ.first;
			if (res == 0)
				res = QQ.second;
			else
				res = Ch (res, QQ.second, R);
		}
		cout << res << " ";
	}
	return res;	
}

void f (int i, string Ops) {
	// cout << i << " " << Ops << endl;
	if (i == O) {
		// cout << Ops << endl;
		G = change (Ops);
		cout << G << endl;
		int k = e + 1;
		cout << "Getting >> " << get (k, s.size()) << endl;
		if (get (k, s.size()) == res) {
			cout << G;
			exit (0);
		} else {
			return;
		}
	} 
	f (i + 1, Ops + '+');
	f (i + 1, Ops + '-');
	f (i + 1, Ops + '*');
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	getline (cin, s);
	s = "12=13-(14-2)*3-7";//s = "18=7+(5-3)*2";
	res = leftSide();
	Operators();
	G = "12=13-(14-2)*3-7";//G = "18=7+(5-3)*2";
	cout << get (e + 1, s.size());
	// cout<< O << endl;
	// f (0, "");
	// cout << -1;

	return 0;
}
