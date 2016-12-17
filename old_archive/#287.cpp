# include <iostream>
# include <string>
# include <cstdio>

using namespace std;

//#define GOOGLE

int o, n, k, ans=0;
string l[111], d;
char u, s[111];

int main()
{
 #ifndef GOOGLE
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 #endif
 cin >> n >> k;
 l[0] = "GOOGLE";
 for(int i = 1; i <= n; i++)
 {
  cin>>u;
  s[i]=u;
  if(i >= k)
  {
   d = "";
   for(int j = i; j >= i - k + 1; j--)
    d += s[j];
   l[++o]=d;
   for(int t = 0; t < o; t++)
    if(d == l[t]){goto l;}
   ans++;
   l:;
  }
 }
 cout << ans;
}

