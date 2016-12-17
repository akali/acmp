# include <iostream>

using namespace std;

int main ()
{
 freopen ("input.txt",  "r",  stdin);
 freopen ("output.txt", "w", stdout);
 int n;
 cin >> n;
 int i = 0;
 while (n - i >= 0)
 {
  n -= i;
  i++;
 }
 cout << i - 1;
 return 0;
}
