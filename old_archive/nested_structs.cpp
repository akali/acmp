#include <iostream>
using namespace std;
struct school
{
    string cla;
    string desk;
    int ci;
    int di;
};

struct cab
{
    string pu;
    school te;
} a,b;

int main()
{
    cab *aschool=&b;
    return 0;
}
