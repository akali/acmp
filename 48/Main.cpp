#include <fstream>

char s[5600];

main (int n = 1) {
    std :: fstream E ("input.txt"); E >> s;
    std :: ofstream D ("output.txt");
	
    D << 1;

    while (s[n++] == '0')
        D << 0;
}
