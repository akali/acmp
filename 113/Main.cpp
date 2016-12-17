#include <fstream>
 
long long d[1111][1111], n, R = -(1 << 30), i, j, I, J, D, k;
char q;
 
main () {
    std :: fstream Q ("input.txt");
    Q >> n;
    for (; ++i <= n; )
        for (j = 0; ++j <= n; )
            Q >> q, d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + q - 48;

    for (i = 0; ++i <= n;)
        for (j = 0; ++j <= n;)
            for (k = 0; ++k <= n - std :: min (i, j);) {
                I = i + k, J = j + k;
                D = d[I][J] - (d[I][j - 1] + d[i - 1][J]) + d[i - 1][j - 1];
                if (D - (I - i + 1) * (J - j + 1))
                    break;
                R = std :: max (R, D);
            }
    
    std :: ofstream ("output.txt") << R;
}