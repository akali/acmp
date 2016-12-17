#include <iostream>
#include <vector>
using namespace std;

vector<bool> u(1001);
int g[1001][1001];

int n,c,m;

void dfs(int v)
{
 c++;
 u[v] = true;
 for(int i=0;i<n;i++)
 {
  if(!u[i] && g[v][i]) dfs(i);
 }
}

int main()
{
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 int x,y;
 cin>>n>>m;
 for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)
   cin>>g[i][j];

 dfs(m-1);
 
 cout<<c-1;
 return 0;
}
