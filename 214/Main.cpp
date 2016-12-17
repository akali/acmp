#include <fstream>

int a, b;

main () {
 std :: fstream ("input.txt") >> a >> b;
 std :: ofstream ("output.txt") << a % 2 + b % 2 ? 1 : 2;
}
