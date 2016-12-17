#include <fstream>
#include <string>
 
using namespace std;
 
string a, b, c;
 
string D (string a, string b) {
    return (a.size() > b.size() ? a : max (a, b));
}
 
int main() {
     fstream ("input.txt") >> a >> b >> c;
    ofstream ("output.txt") << D (a, D (b, c));
}
