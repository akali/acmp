#include <iostream>
#include <vector>
using namespace std;
#define foio freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
vector<int> g[1001],time_in(1001),time_out(1001);
vector<bool> u(1001);
int n,m,x,y,t;
void input()
{
 cin>>n>>m;
 for(int i=0;i<n;i++)
 {
  cin>>x>>y; x--,y--;
  g[x].push_back(y);
  g[y].push_back(x);
 }
}

void dfs(int v)
{
 time_in[v] = t++;
 u[v] = true;
 for(int i=0; i<g[v].size();i++)
 {
  int to=g[v][i];
  if(!u[to]) dfs(to);
 }
 time_out[v] = t++;
}
 
bool check(int x, int y)
{   
 dfs(0);
 if(time_in[x] < time_in[y] && time_out[x] > time_out[y])
 return true;
 else
 return false;
}

int main()
{
 foio
 input();
 cin>>x>>y; x--,y--;
 cout<<(check(x,y) ? "Yex" : "No")<<endl;

// cout<<time_in[x]<<" "<<time_out[x]<<endl;
// cout<<time_in[y]<<" "<<time_out[y]<<endl;
 return 0;
}
