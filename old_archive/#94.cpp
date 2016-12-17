# include <iostream>
# include <cstdio>

using namespace std;

int main ()
{
 freopen ("input.txt",  "r",  stdin);
 freopen ("output.txt", "w", stdout);

 int n, m, k;

 cin >> n >> m >> k;

 if (n >= m) cout << 1;
 else
 if (n <= k) cout << "NO";
 else
 cout << (m - n - 1) / (n - k) + 2;

 return 0;
}
