#include <fstream>

int q = 10, v, d[10], n, l, k, i;

main () {
    std :: fstream ("input.txt") >> n;
    for (; n;) {
        for (; i < q; d[i++] = 0);
        for (k = ++l * q; k /= q; ++d[k % q]) if (d[k % q]) goto l;
        v = l;
        n--;
        l: i = 0;
    }
    std :: ofstream ("output.txt") << v;
}
