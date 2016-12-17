#include <iostream>
using namespace std;

int n,c;
int a[200][200], used[1001];
bool cycle = false;

void dfs(int v)
{
 used[v] = 1;
 for(int i = 0; i < n; i++)
 {
  if(a[v][i] && !used[i])
  {
   dfs(i);
  }
 }
 used[v] = 2;
}
int q;
int main()
{
 //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
 cin>>n;
 for(int i = 0; i < n; i++)
  for(int j = 0; j < n; j++)
  {
   cin>>a[i][j]; 
   if(a[i][j]) q++;
  }
 for(int i = 0; i < n; i++)
 {
  if(!used[i])
  {
   c++;
   dfs(i);
  }
 }
 if(q/2 == n + 1 || c == 1) 
  cout<<"YES";
 else
 if(c > 1)
  cout<<"NO";
 return 0;
}