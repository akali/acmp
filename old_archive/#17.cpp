# include <iostream>
# include <vector>

using namespace std;

vector<int> KMP (vector<int> s)
{
	int n = (int) s.size();
	vector<int> pi (n);
	for (int i = 1; i < n; i++)
	{
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
 vector <int> a;
 int n, p;
 bool isone = true;
 cin >> n >> p;
 a.push_back(p);
 for (int i = 1; i < n; i++)
 {
  cin >> p;
  if (a.back() != p) isone = false;
  a.push_back(p);
 }
 a.pop_back();
 if (isone)
 {
  cout << 1;

 }
 vector <int> p = KMP(a);
 for (int i = 0; i < p.size(); i++) cout << p[i] << " " ;
 return 0;
}
