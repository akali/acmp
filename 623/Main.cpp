#include <fstream>

int f[61], n;

main () {
    std :: ifstream ("input.txt") >> n; n %= 60;
    f[n]++;
    for (; n--;)
        f[n] = (f[n + 1] + f[n + 2]) % 10;
    std :: ofstream ("output.txt") << *f;
}
