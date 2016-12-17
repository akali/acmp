#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;
 
long long c[19], sum1 = 1, sum2 = 1;
  
int main () {
	freopen ("input.txt", "r", stdin);
 
	string s;
 
	cin >> s;
	sort (s.begin(), s.end());
 
    int k = 1;

	for (int i = 1; i < s.length(); i++) {
		if (s[i] == s[i - 1]) c[k]++;
		if (s[i] != s[i - 1]) c[k++]++;
	}
	c[k]++;
	for (int i = 1; i <= 15; i++)
		if (c[i])
  			for (int j = 1; j <= c[i]; j++)
				sum1 *= j;
 
	for (int i = 1; i <= s.length(); i++)
		sum2 *= i;
 
	cout << sum2 / sum1;
	return 0;
}