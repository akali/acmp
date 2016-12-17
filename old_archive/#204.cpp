# include <iostream>
# include <vector>
# include <string>

using namespace std;

vector<int> KMP (string s) {
	int n = (int) s.size();
	vector<int> pi (n);
	for (int i = 1; i < n; i++) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}

int main ()
{
 #ifndef GOOGLE
  freopen ("input.txt" , "r",  stdin);
  freopen ("output.txt", "w", stdout);
 #endif
 string a;
 cin >> a;

 vector <int> p = KMP(a);

 cout << a.size() - p.back();
 return 0;
}
