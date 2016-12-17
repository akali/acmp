# include <iostream>
# include <cstring>
# include <cstdlib>
# include <cstdio>

using namespace std;

int d[1000][1000], n, m;
char w[1000];
int x, y;

void print ()
{
 for (int i = 0; i < n; i++)
 {
  for (int j = 0; j < m; j++)
  {
   cout << d[i][j];
  }
  cout << endl;
 }
}

void chk_for_end (int x, int y, int X, int Y)
{
 if (d[x][y] == 1)
 {
  cout << "CRASH!!!" << endl;
  d[x][y] = 2;
  print ();
  exit (0);
 }
 if (x == n || x == -1 || y == m || y == -1)
 {
  cout << "CRASH!!!" << endl;
  d[X][Y] = 2;
  print ();
  exit (0);
 }
}

int main ()
{
 #ifndef GOOGLE
  freopen ("g-snake.in" , "r",  stdin);
  freopen ("g-snake.out", "w", stdout);
 #endif
 cin >> n >> m >> w;
 int len = strlen (w);

 d[x][y] = 1;

 for (int i = 0; i < len; i++)
 {
  if (w[i] == 'D')
  {
   chk_for_end (x + 1, y, x, y);
   //d[x++][y] = 1;
   x++;
  }
  if (w[i] == 'U')
  {
   chk_for_end (x - 1, y, x, y);
   //d[x--][y] = 1;
   x--;
  }
  if (w[i] == 'R')
  {
   chk_for_end (x, y + 1, x, y);
   //d[x][y++] = 1;
   y++;
  }
  if (w[i] == 'L')
  {
   chk_for_end (x, y - 1, x, y);
   //d[x][y--] = 1;
   y--;
  }
  d[x][y] = 1;
 }
 d[x][y] = 2;
 print ();
 return 0;
}
