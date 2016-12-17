#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
  const int maxsize=102;
  vector <int> a;
  vector <int> b;
  string s1,s;
  int m,c;
  for (int i=(int)s.length(); i>0; i-=9)
	if (i < 9)
		a.push_back (atoi (s.substr (0, i).c_str()));
	else
		a.push_back (atoi (s.substr (i-9, 9).c_str()));
//----------------------------------------------------
    for (int i=(int)s1.length(); i>0; i-=9)
	if (i < 9)
		b.push_back (atoi (s1.substr (0, i).c_str()));
	else
		b.push_back (atoi (s1.substr (i-9, 9).c_str()));
while (a.size() > 1 && a.back() == 0)
	a.pop_back();
while (b.size() > 1 && b.back() == 0)
	b.pop_back();

  m=max(a[0],b[0]);

  c=0;
  for (int i=1;i<=m;i++){
    c = c+a[i]+b[i];
    a[i] = c % 10;
    c = c / 10;
  }
  if(c>0){
    m=m+1;
    a[m] = c;
  }
  a[0]=m;

  cout<<a[0];
  return 0;
}
