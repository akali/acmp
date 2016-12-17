#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int n, S , T, inf = 1000000;

int a[1001][1001];

long long d[1000000];

int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  cin >> n;

  for(int i = 1; i <= n; i++)
   for(int j = 1; j <= n; j++)
    cin>>a[i][j];

  cin >> S >> T;
  if(S == T)
  {
   cout<<0; return 0;
  }
  fill(d + 1, d + 1 + n, -1);
  d[S] = 0;
  queue<int> q;
  q.push(S);
  while(!q.empty())
  {
   int v = q.back();
   q.pop();
   for(int i = 1; i <= n; i++)
    if(a[v][i] && d[i] == -1)
    {
     d[i]=d[v]+1;
     q.push(i);
    }
  }
 if(d[T] != -1)
  cout<<d[T];
 else
  cout<<-1;
 return 0;
}#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int n, S , T, inf = 1000000;

int a[1001][1001];

long long d[1000000];

int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  cin >> n;

  for(int i = 1; i <= n; i++)
   for(int j = 1; j <= n; j++)
    cin>>a[i][j];

  cin >> S >> T;
  if(S == T)
  {
   cout<<0; return 0;
  }
  fill(d + 1, d + 1 + n, -1);
  d[S] = 0;
  queue<int> q;
  q.push(S);
  while(!q.empty())
  {
   int v = q.back();
   q.pop();
   for(int i = 1; i <= n; i++)
    if(a[v][i] && d[i] == -1)
    {
     d[i]=d[v]+1;
     q.push(i);
    }
  }
 if(d[T] != -1)
  cout<<d[T];
 else
  cout<<-1;
 return 0;
}