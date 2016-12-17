#include <fstream>
 
#define T int
 
T S = 1 << 30, d[20][100], a[20][100], c[20][100], x, y, n, m, M = S, X, k;
 
#define A [x][y]
#define D return
#define L G (y + 1, x
 
using namespace std;
 
T G (T y, T x) {
 if (0 > x | x >= n)
  D S;
  
 if (y == m - 1)
  D a A;
  
 T &R = d A;
 
 if (~R)
  D R;
  
 T r = L ), u = L - 1), w = L + 1);
 k = min (r, min (u, w));
 c A = k == r ? 3 : k == u ? 2 : 0;
 D R = a A + k;
}
 
main () {
 fstream E ("input.txt"); E >> n >> m;
 ofstream Y ("output.txt");
 
 for (; x < n; x++)
  for (y = 0; y < m; y++)
   E >> a A, d A = -1;
  
 for (x = -1; x++ < n;)
  if (M > G (0, x))
   X = x, M = G (0, x);
 
 y = 0;
 while (y - m)
  Y << X + 1 << "\n",
  k = c[X][y++],
  !k ? X++ : k == 2 ? X-- : 0;
 
 Y << M;
}