#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

string tostr (int n) {
	string res;
	while (n > 0) {
		res += (n % 10) + '0';
		n /= 10;
	}
	reverse (res.begin(), res.end());
	return res;
}

int root (string n) {
	int d = 0;
	for (int i = 0; i < n.size(); i++)
		d += n[i] - '0';
	if (d > 9)
		return root (tostr (d));
   	else
   		return d;
}

int main () {
	
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	
	string s;
	while (cin >> s) {
	    for (int i = 0; i < s.size(); i++) {
	    	int a = root (s.substr (0, i));
			// cout << s.substr (0, i) << " " << s.substr (i, s.size() - i + 1) << endl;
	    	int b = root (s.substr (i, s.size() - i + 1));
	    	if (a == b) {
	    		cout << "YES";
	    		goto l;
	    	}
	    }
	    cout << "NO";
	    l:
		cout << endl;
	}
	return 0;
}

/*
  Mediana
	 |
	 V
 001 5 420
 012 3 456 Size = 7
 7 / 2 = 3;

*/