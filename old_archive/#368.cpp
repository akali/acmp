#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, d[260][260];
char a[260][260];


void print()
{
 for(int i = 1; i <= n; i++)
 {
  for(int j = 1; j <= n; j++)
  {
   if(a[i][j] != '#') putchar('.');
   else putchar('#');
  }
  printf("\n");
 }
 exit(0);
}


void colorise()
{
 for(int i = 1; i <= n; i++)
  if(a[i][1] == '#')
  {
   for(int j = 1; j <= i; j++)
    a[j][1] = '#';

   print();
  }
 for(int i = 1; i <= n; i++)
  if(a[1][i] == '#')
  {
   for(int j = 1 ; j <= i; j++)
    a[1][j]='#';
   print();
  }
}

int main()
{
 
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 
 scanf("%d", &n);

 for(int i = 1;i <= n; i++)
  for(int j = 1;j <= n; j++)
  {
   char c = getchar();
   d[i][j] = c - '0';
  }

 for(int i = 2; i <= n; i++)
  d[i][1] += d[i - 1][1],
  d[1][i] += d[1][i - 1];

 for(int i = 2; i <= n; i++)
  for(int j = 2; j <= n; j++)
   d[i][j] += min(d[i - 1][j], d[i][j - 1]);

 int x = n, y = n;
 
 while(true)
 {
  a[x][y] = '#';
  if(x == 1 || y == 1) 
  {
   colorise(); 
   break;
  }

  if(d[x - 1][y] > d[x][y - 1]) y--;
  else x--;
 }
 return 0;
}

