#include <iostream>
#include <string>
#include <cstdio>
#include <climits>

using namespace std;
 
const int MaxN = 100;
int d[MaxN][MaxN], n;
 
int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
    #endif 
	string s; cin >> s;
 
	n = s.size();   
 
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			d[i][j] = INT_MAX;
 
	for (int i = 0; i < n; i++)
		d[i][i] = 1;
     
	for (int i = 2; i <= n; i++){
		for (int l = 0; l <= n - i; l++){
			int r = l + i - 1;  

			if (s[l] == '}' || s[l] == ']' || s[l] == ')')
				d[l][r] = d[l + 1][r] + 1;
			else {
				for (int k = l; k < r; k++)
					d[l][r] = min (d[l][r], d[l][k] + d[k + 1][r]);
				for (int k = l + 1; k <= r; k++)
					if ((s[l] == '[' && s[k] == ']') || (s[l] == '(' && s[k] == ')') || (s[l] == '{' && s[k] == '}'))
						d[l][r] = min (d[l][r], d[l + 1][k - 1] + d[k + 1][r]);
			}
		}
	}
     
	cout << d[0][n - 1];
    return 0;
}
