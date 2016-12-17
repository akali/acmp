#include <iostream>
#include <cstdio>

using namespace std;

int main ()
{
 freopen ("input.txt", "r", stdin);
 freopen ("output.txt", "w", stdout);
 long long n, k;
 cin >> n >> k;
 cout << (n - 2) * (k * (k - 1) / 2) + 1 + (n - 1) * k;
 return 0;
}