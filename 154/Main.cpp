#include <fstream>
#include <cstdlib>

long long n, A[9];

std :: ofstream Q ("output.txt");

void f (int d, long long S, int p) {
    if (p > 8) return;
    if (S == n) {
        for (int i = 0; i < p; ++i)
            Q << i << " ";
        exit (0);
    }
    for (; d >= 1; --d)
        if (S + d * d * d <= n)
            A[p] = d,
            f (d, S + d * d * d, p + 1);
}

main () {
    std :: fstream ("input.txt") >> n;
    f (2000, 0, 0);
    Q << "IMPOSSIBLE";
}
