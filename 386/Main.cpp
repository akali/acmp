#include <fstream>
#include <cstdlib>

int n;
 
#define q rand()

int main () {
	std :: fstream ("input.txt") >> n;
    std :: ofstream g ("output.txt");
    g << "YES\n";
    while (n--)
        g << (q % 999) - (q & 1) << " " << (q % 999) - (q & 1) << "\n";
}
