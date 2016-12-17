# include <iostream>
# include <cmath>
# include <algorithm>
# include <cstring>
# include <cstdio>
# include <cmath>
# include <cstdlib>

using namespace std;

bool prime(int x)
{
 int q = sqrt (double(x));
 for (int i = 2; i <= q; i ++)
  if ((x % i) == 0) return false;
 return true;
}

int main()
{
 #ifndef GOOGLE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
 #endif

 string s;
 //char s[1001];
 //gets(s);
 cin >> s;
 int n = (s.size());
 sort (s.begin(), s.end());
 int S = atoi (s.c_str());
 if (!prime(S)) {
  cout << "No";
  return 0;
 }
 reverse (s.begin(), s.end());
 //sort (s.begin (), s.end (), greater<char>());
 S = atoi(s.c_str());
 if (!prime(S))
 {
  cout << "No";
  return 0;
 }
 cout << "Yes";
 return 0;
}

