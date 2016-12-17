# include <iostream>
# include <set>
# include <vector>
# include <string>
# include <cstdio>
# include <cstdlib>

using namespace std;

set <char> A, B, C, ans;
vector <char> V;

int main ()
{
 freopen ("input.txt", "r", stdin);
 freopen ("output.txt", "w", stdout);

 string a, b, c;

 cin >> a >> b >> c;
 for (int i = 0; i < a.size(); i++) A.insert (a[i]);
 for (int i = 0; i < b.size(); i++) B.insert (b[i]);
 for (int i = 0; i < c.size(); i++) C.insert (c[i]);
 
 for (set<char>::iterator it = A.begin(); it != A.end(); it++)
 {
  char x = *it;
  if (B.find(x) != B.end() && C.find(x) != C.end())
  {
   ans.insert (x);
  }
 }

 for (set<char>::iterator it = B.begin(); it != B.end(); it++)
 {
  char x = *it;
  if (A.find(x) != A.end() && C.find(x) != C.end())
  {
   ans.insert (x);
  }
 }

 for (set<char>::iterator it = C.begin(); it != C.end(); it++)
 {
  char x = *it;
  if (B.find(x) != B.end() && A.find(x) != A.end())
  {
   ans.insert (x);
  }
 }
 cout << ans.size() << endl;
 for (set<char>::iterator it = ans.begin(); it != ans.end(); it++)
 {
  char x = *it;
  cout << x << " ";
 }

 return 0;
}
