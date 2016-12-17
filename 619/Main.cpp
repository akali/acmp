#include <fstream>
  
float d[505][3003] = {1};
int n, m, i, k, j;
 
main () {
    std :: fstream ("input.txt") >> n >> m;
    for (; i++ - n; )
        for (j = 0; j++ - m; )
            for (k = (6 > j ? j : 6) + 1; --k; d[i][j] += d[i - 1][j - k] / 6);
    std :: ofstream ("output.txt") << d[n][m];
}
