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

bool checkJava (string &s) {
	if (isupper (s[0]))
		return false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '_')
			return false;
	}
	return true;
}

bool checkCpp (string s) {
	if (s[0] == '_' || *s.rbegin() == '_')
		return false;
	for (int i = 0; i < s.size(); i++) {
		if (isupper (s[i]))
			return false;
		if (s[i] == '_' && (s[i - 1] == '_' || s[i + 1] == '_'))
			return false;
	}
	return true;
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	string s; cin >> s;
	string res;
	if (checkJava (s)) {
		for (int i = 0; i < s.size(); i++) {
			if (isupper (s[i])) {
				res += "_";
				res += char (tolower (s[i]));
			} else {
				res += char (s[i]);
			}
		}
		cout << res;
	} else {
		if (checkCpp (s)) {
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == '_') {
					res += char (toupper (s[i + 1]));
					i++;
				} else {
					res += (s[i]);
				}
			}
			cout << res;
		} else {
			cout << "Error!";
		}
	}

	return 0;
}
