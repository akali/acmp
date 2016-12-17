#include <iostream>
#include <string>
using namespace std;
int main()
{
 string s,b;
 getline (cin,s);
 int n=s.length();
 for(int i=0;i<=n;i++)
 {
  if(s[i]!='@') b+=s[i];
 }
 cout<<b;
 return 0;
}
