#include <fstream>
 
#define U return
#define R int
#define K d[l][r]
#define M + (a[l] + a[r]) * a[
 
R a[150], d[150][150], i;
 
R f (R l, R r) {
    if (r - l < 2 || K) U K;
    K = 9999;
    for (R k = l + 1; k < r; ) K = std :: min (K, f (l, k) + f (k, r) M k++]);
    U K;
}
 
main () {
    std :: fstream Q ("input.txt");
    for (; i <= *a;) Q >> a[i++];
    std :: ofstream ("output.txt") << f (1, *a);
}