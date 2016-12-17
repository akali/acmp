#include <fstream>
 
int d[90][90], i, j, n;
char s[90];

#define O(p, o) d[i + 1][j + p] += d[i][j] * (s[i] == 63 | s[i] == o)
                    
main() {
    std :: fstream ("input.txt") >> s;

    **d = 1;

    n = strlen (s);

    for (; i < n; i++)
        for (j = -1; j++ <= i;)
            O (1, 40),
            O (-1, 41);
    std :: ofstream ("output.txt") << *d[n];
}
