#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

string tostr (int i) {
	string res;
	while (i > 0) {
		res += (i % 10) + '0';
		i /= 10;
	}
	reverse (res.begin(), res.end());
	return res;
}

bool equals (string a, string b) {
	if (a.size() != b.size())
		return false;
   	for (int i = 0; i < a.size(); i++) {
   		if (a[i] != b[i])
   			return false;
   	}
   	return true;
}

int main () {
	freopen ("output.txt", "w", stdout);
	freopen ("input.txt", "r", stdin);
	int n; cin >> n;
	string d = (tostr (n));
	string q;
	for (int i = 1; i <= 10000; i++)
		q += tostr (i);
	for (int i = 0; i < q.size(); i++) {
		string qq = q.substr (i, d.size());
		if (equals (qq, d)) {
			cout << i + 1;
			return 0;
		}
	}
	// cout << q;
	return 0;
}
