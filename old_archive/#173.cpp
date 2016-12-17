#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

bool equals (string a, string b) {
	if (a.size() != b.size())
		return false;
   	for (int i = 0; i < a.size(); i++) {
   		if (a[i] != b[i])
   			return false;
   	}
   	return true;
}

bool palindrome (string s) {
	string q = s;
	reverse (q.begin(), q.end());
	return equals (q, s);
}

string take (int num, int base) {
	string result;
	while (num > 0) {
		int d = num % base;
		if (d < 10) {
			result.push_back ((d) + '0');
		} else {
        	result.push_back ((d % 10) + 'A');
        }
        // num %= base;
        num /= base;
	}
	return result;
}

bool isPalindrome (int number, int base) {
	string NewNumber = take (number, base);
	// cout << NewNumber << endl;
	return palindrome (NewNumber);
}

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	
	int n; cin >> n;
	vector <int> ans;
	// cout << take (n, 36) << endl;
	for (int i = 2; i <= 36; i++) {
		if (isPalindrome (n, i))
			ans.push_back (i);
	}

	if (ans.empty ()) {
		cout << "none";
	} else {
		if (ans.size() == 1) {
			cout << "unique" << endl;
		} else {
			cout << "multiple" << endl;
		}
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
	}
	return 0;
}
