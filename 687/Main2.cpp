#include <bits/stdc++.h>
 
#define T int
 
T d[100][100], a[100][100], c[100][100], i, j, n, m, M = 1 << 30, X, k;
 
#define A [x][y]
 
using namespace std;
 
T G (T x, T y) {
 if (!(0 <= x && 0 <= y && x < n && y < m))
  return 1 << 30;
  
 if (y == m - 1)
  return a A;
  
 T &R = d A;
 
 if (~R)
  return R;
  
 T r = G (x, y + 1), u = G (x - 1, y + 1), w = G (x + 1, y + 1);
 k = min (r, min (u, w));
 c A = k == r ? 0 : k == u ? 2 : 3;
 return R = a A + k;
}
 
main () {
	cout << "1 << 30 = " << (1 << 30) << endl << "9 << 9 =  " << (9 << 30) << endl;
}