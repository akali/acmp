#include <iostream>
#include <string>

using namespace std;

string s;
int inf = 1000000000;

int main()
{
 freopen("input.txt" ,"r", stdin);
 freopen("output.txt","w",stdout);
 cin>>s;
 int a,b,c;
 char F,S;
 if(isdigit(s[0])) a = s[0] - '0'; else a = inf;
 if(isdigit(s[2])) b = s[2] - '0'; else b = inf;
 if(isdigit(s[4])) c = s[4] - '0'; else c = inf;
 F = s[1];
 if(F == '+')
 {
  if(a == inf) cout<<c - b;
  if(b == inf) cout<<c - a;
  if(c == inf) cout<<a + b;
 }
 if(F == '-')
 {
  if(a == inf) cout<<c + b;
  if(b == inf) cout<<a - c;
  if(c == inf) cout<<a - b;
 }
 return 0;
}