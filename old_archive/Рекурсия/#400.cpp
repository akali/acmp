#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

//pair <int, int> d[7];
int d[7];
bool used[11500];

int main ()
{
 freopen ("input.txt", "r", stdin);
 freopen ("output.txt", "w", stdout);

 for (int i = 0; i < 12; i++)
 {
  int x, y;
  //cin >> x;// >> y;
  //d[i] = make_pair (min (x, y), max(y, x));
  cin >> d[i];
  used[d[i]] = true;
 }
 //sort (d, d + 6);
 int c = 0;
 for (int i = 0; i <= 10000; i++)
 {
  if (used[i])
   c++;
 }
 //if (d[0] == d[1] && d[2] == d[3] && d[4] == d[5])
 if (c == 3)
  cout << "POSSIBLE";
 else
  cout << "IMPOSSIBLE";
}
