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

bool isSlashComment (char a, char b) {
	return a == b && b == '/';
}

int commentType1 (char a, char b) {
	if (a == '(' && b == '*') return 1;
	if (a == '*' && b == ')') return -1;
	return 0;
}

int commentType2 (char a) {
	if (a == '{') return 2;
	if (a == '}') return -2;
	return 0;
}

bool checkString (char t, bool &is, int &isComment) {
	if (t == char (39) && !isComment)
		is ^= 1;
	return is;
}

int doubleComment (char a, char b, int &is) {
	if (is == -2 || is == 2)
		return 0;
	if (isSlashComment (a, b) && !is)
		return 1;
	if (!is) {
		int q = (commentType1 (a, b));
		if (q > 0) {
			is = q;
			return -1;
		}
		return 0;
	} else {
		int q = (commentType1 (a, b));
		if (q < 0)
			if (is == -q) {
				is = 0;
				return true;
			}
		return 0;
	}
	return 0;
}

bool Comment (char a, int &is) {
	if (is == 1 || is == -1)
		return false;
	int q = commentType2 (a);
	if (!q)
		return 0;
	if (!is) {
		if (q > 0)
			is = q;
		return false;
	} else {
		if (q < 0)
			if (is == -q) {
				is = 0;
				return true;
			}
	}
	return false;
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef lcl
		freopen ("output.txt", "w", stdout);                                                                             
	#endif

	string s;
	int isComment = false, res = 0;
	bool isString = false;
	
	while (getline (cin, s)) {
		for (int i = 0; i < s.size(); ++i) {
			// cout << i << " ";
			if (checkString (s[i], isString, isComment))
				continue;
			
			if (i + 1 != s.size()) {
				int k = doubleComment (s[i], s[i + 1], isComment);
				if (k > 0)
					++res;
				if (k < 0)
					i += 2;
			}
			
			res += (Comment (s[i], isComment));
		}
		// cout << endl;
	}

	cout << res;

	return 0;
}
