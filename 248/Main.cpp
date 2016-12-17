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

string s;

bool isArticle (string &tmp) {
	return tmp == "a" || tmp == "A" || tmp == "an"  || tmp == "An" || tmp == "the" || tmp == "The";
}

void Articles () {
	string res;
	int pos = 0;
	while (pos < s.size()) {
		if (isalpha (s[pos])) {
			string tmp;
			while (pos < s.size() && isalpha (s[pos]))
				tmp += s[pos++];
			if (isArticle (tmp)) {
				if (pos < s.size() && s[pos] == ' ')
					pos++;
			}
			else
				res += tmp;
		}
		else
			res += s[pos++];
	}
	s = res;
}

bool isC (char c) {
	return c == 'C' || c == 'c';
}
 
void CCC () {
	string res;
	for (int i = 0; i < (int)s.size() - 1; ++i) {
		if (isC (s[i]) && (s[i + 1] == 'e' || s[i + 1] == 'i'))
			s[i] = s[i] == 'c' ? 's' : 'S';
	}
	
	for (int i = 0; i < s.size(); ++i) {
		if (i + 1 < s.size() && isC (s[i]) && s[i + 1] == 'k')
			res += s[i] == 'c' ? "k" : "K";
		else
			res += s[i];
	}
	
	s = res;
	for (int i = 0; i < s.size(); ++i) {
		if (isC (s[i]))
			s[i] = s[i] == 'c' ? 'k' : 'K';
	}
}

bool Equal (char a, char b) {
	if (isalpha (a) && isalpha (b))
		return tolower (a) == tolower (b);
	return false;
}

void Doubles () {
	bool is = true;
	while (is) {
		is = false;
		string res = "";
		for (int i = 0; i < s.size(); ++i) {
			if (i + 1 < s.size() && Equal (s[i], s[i + 1])) {
				if (s[i] == 'e') {
					res += 'i';
				} else {
					if (s[i] == 'E') {
						res += 'I';
					} else {
						if (s[i] == 'o') {
							res += 'u';
						} else {
							if (s[i] == 'O') {
								res += 'U';
							} else {
								res += s[i];
							}
						}
					}
				}
				++i;
				is = true;
			}
			else
				res += s[i];
		}
		s = res;
	}
}

void EEE () {
	string res;
	int pos = 0;
	while (pos < s.size()) {
		if (isalpha (s[pos])) {
			string tmp;
			while (pos < s.size() && isalpha (s[pos]))
				tmp += s[pos++];
			if (tmp[tmp.size() - 1] == 'e' && tmp.size() != 1)
				tmp.erase (tmp.size() - 1);
			res += tmp;
		}
		else
			res += s[pos++];
	}
	s = res;
}

string solve () {
	Articles ();
	CCC ();
	Doubles ();
	EEE ();
	return s;
}

int main() {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif
	getline (cin, s);
	cout << solve ();
	return 0;
}
