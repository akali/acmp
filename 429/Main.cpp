#include <vector>
#include <fstream>
 
#define S std ::
#define K g[x]
 
int n, d[1100], x, i;
 
S vector <int> g[1100];
 
int P (int L, int x = 1) {
    if (!K.size()) return d[x];
    int H, a = 0;
    for (H = L ? 1 : -1; a < K.size(); a++)
        H = L ? S min (H, P (!L, K [a])) : S max (H, P (!L, K [a]));
    return H;
}
 
main () {
    S fstream f ("input.txt");
 
    f >> n;
 
    for (i = 2; i <= n; i++) {
        char T;
        f >> T >> x;
        K.push_back (i);
        if (T != 'N')
            f >> x, d[i] = x;
    }
 
    S ofstream k ("output.txt");
    k << (!P (0) ? "0" : P (0) == 1 ? "+1" : "-1");
}
