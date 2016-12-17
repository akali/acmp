#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string>

using namespace std;

string a,b,m,s;

string low(string q)
{
 for (int i = 0; i < q.size(); i++)
  q[i] = tolower(q[i]);
 return q;
}

void search(string a, string b)
{
 for (int i = a.size(); i >= 0; i--)
 {
  s = a.substr(0, i) + b;
  if (((m.size()) > (s.size()) ||
  (m.size()) == (s.size()) && m > s) &&
  low(a) == low((s.substr(0, a.size()))))
   m = s;
 }
}

bool chk (string a, string b)
{
 if (a == b)
 {
  m = a;
  return true;
 }
 if (b > a)
  swap (a, b);
 int B = b.size();
 for (int i = 0; i < a.size() - B; i++)
 {
  if (a.substr(i, i + B) == b)
  {
   a[i] = toupper(a[i]);
   m = a;
   return true;
  }
 }
 return false;
}

int main ()
{
 freopen ("input.txt", "r", stdin);
 freopen ("output.txt", "w", stdout);

 cin >> a >> b;
 if (chk(a, b))
 {
  cout << m;
  return 0;
 }
 m = a + b;

 search(a, b);
 search(b, a);

 cout << m;

 return 0;
}
