#include <fstream>
main(){
 int n;
 std ::  fstream ("input.txt") >> n;
 std :: ofstream ("output.txt") << n * (n + 1) / 2 + 1;
}