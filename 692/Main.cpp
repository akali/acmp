#include <fstream>
main (int x) {
    std :: fstream ("input.txt") >> x;
    std :: ofstream ("output.txt") << ((x & !(x & (x - 1))) ? ("YES") : ("NO"));
}
