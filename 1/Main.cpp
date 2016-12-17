#include <fstream>

main () {
    int a, b;
    std ::  fstream ("input.txt") >> a >> b;
    std :: ofstream ("output.txt") << a + b;
}
