#include <iostream>
#include <deque>
using namespace std;
#define F first
#define S second
#define MP make_pair

deque< pair<int, int> > q;
int n, m, a[200][200], d[200][200], inf = 1000000000;
bool u[200][200];

int max(int a,int b, int c, int d)
{
 return max(a, max(b, max(c, d)));
}

int main()
{
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 cin>>n>>m;
 for(int i = 0; i < n; i++)
 {
  for(int j = 0; j < m; j++)
  {
   d[i][j] = inf;
   cin>>a[i][j];
  }
 }
 u[0][0] = true;
 d[0][0] = a[0][0];
 q.push_back(MP(0,0));
 while(!q.empty())
 {
  int x = q.front().F;
  int y = q.front().S;
  q.pop_front();
  int o = -1;  

  if(y + 1 < m && d[x][y + 1] > d[x][y] + a[x][y + 1]){d[x][y + 1] = (d[x][y] + a[x][y + 1]); q.push_back(MP(x, y + 1));}
  if(y - 1 > o && d[x][y - 1] > d[x][y] + a[x][y - 1]){d[x][y - 1] = (d[x][y] + a[x][y - 1]); q.push_back(MP(x, y - 1));}

  if(x + 1 < n && d[x + 1][y] > d[x][y] + a[x + 1][y]){d[x + 1][y] = (d[x][y] + a[x + 1][y]); q.push_back(MP(x + 1, y));}
  if(x - 1 > o && d[x - 1][y] > d[x][y] + a[x - 1][y]){d[x - 1][y] = (d[x][y] + a[x - 1][y]); q.push_back(MP(x - 1, y));}
 }
// for(int i = 0; i < n; i++)
// {
//  for(int j = 0; j < m; j++)
//  {
//   cout<<d[i][j]<<" ";
//  }
//  cout<<endl;
// }
 cout<<d[n - 1][m - 1];
 return 0;
}
