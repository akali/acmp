#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

int main () {
	
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);	
	#endif
	
	string s;
	bool type2 = 0, type3 = 0;
	int ans = 0;
		while (getline (cin, s)) {
		bool ap = false;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == char (39)) {
				ap ^= 1;
			}
			if (!ap) {
				if (s[i] == '/' && s[i + 1] == '/') {
					// cout << s << endl;
					if (!type3 && !type2) {
						ans++;
						break;
                    }
				}
				if (type2) {
					if (s[i] == '}') {
						ans++;
						type2 = false;
						continue;
					}	
				}
				if (type3) {
					if ((s[i] == '*' && s[i + 1] == ')') || (s[i] == ')' && s[i - 1] == '*')) {
						ans++;
						type3 = false;
						continue;
					}
				}
				if (!type2 && !type3) {
					if (s[i] == '{') {
						bool is = false;
						bool Ap = false;
						for (int j = i + 1; j < s.size(); j++) {
							if (s[j] == char (39))
								Ap ^= 1;
							if (s[j] == '}' && !Ap) {
								ans++;
								i = j;
								is = true;
								break;
							}
						}
						if (!is) {
							type2 = true;
							break;
						}
						continue;
					}
					if (s[i] == '(' && s[i + 1] == '*') {
						bool is = false;
						bool Ap = false;
						for (int j = i + 1; j < s.size(); j++) {
							if (s[j] == ')')
								Ap ^= 1;
							if (!Ap && s[j - 1] == '*' && s[j] == ')') {
								ans++;                
								i = j;
							is = true;
								break;
								}
						}
						if (!is) {
							type3 = true;
							break;
						}
						continue;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
