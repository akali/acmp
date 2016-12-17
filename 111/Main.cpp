#include <fstream>
  
int d, k, i = 1;
  
main () {
    std :: fstream ("input.txt") >> k;
    for (d = k; ++i * i < k; )
        d = k % i ? d : std :: min (/*i > 2 ? i : */d, k / i);
    std :: ofstream ("output.txt") << (k < 3 ? 0 : d - 1);
}
