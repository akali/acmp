#include <bits/stdc++.h>

using namespace std;

int main ()
{
 int a = 140, b = 15;
 cout << ((a | b) << 1) << endl
      << (a ^ b) << endl 
      << (a & b) << endl << endl
      << (b | a) << endl
      << (b ^ a) << endl
      << (b & a) << endl;
}
