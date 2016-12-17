#include <fstream>
 
#define p return
#define t f (l + 1, r - 1)
 
char s[30];
int d[30][30];
 
int f (int l, int r = strlen (s) - 1) {
    if (r - l <= 0)
        p !(r - l);
    int &q = d[l][r];
    if (q)
        p q;
    q = f (l + 1, r) + f (l, r - 1);
    p q = s[l] == s[r] ? q + t + 1 : q;
}
 
main () {
    std :: fstream l ("input.txt");
    l >> s;
    std :: ofstream ("output.txt") << f (0);
}
