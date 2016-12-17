#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
char k;
int a[1111],c,n,m;
int cnt;

bool chs(string s)
{
 bool x=false;
 vector<int> m;
 for(int i=1;i<=s.size();i++)
 {
  if(s[i]!='+')
   m[s[i]-'0']++;
 }
 for(int i=0;i<=m.size();i++)
 {
  if(m[i]==2) return false;
 }
 return true;
}

string itos(int n)
{
 string s;
 while(n>0)
 {
  s.push_back(char(n%10+'0'));
  n/=10;
 }
 if(n>0) s.push_back(n+'0');
 reverse(s.begin(),s.end());
 return s;
}

void count(string s)
{
 if(chs(s) && s.size()==m)
  cnt++;
}

void rec(int x, string s,int v)
{
 if(x==n)
 {
  count(s);
  return;
 }
 for(int i=v;i+x<=n;i++)
 {
  rec(i+x,s+'+'+itos(i),i);
 }
}

int main()
{
 freopen("input.txt" ,"r", stdin);
 freopen("output.txt","w",stdout);

 string s;
 cin>>n>>m;
 m*=2;
 rec(0,s,1);
 cout<<cnt;
 return 0;
}
