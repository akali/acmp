# include <iostream>
# include <algorithm>

using namespace std;

int n, C[111], k, p;
int ans = 0;

int main ()
{
 freopen ("input.txt" , "r",  stdin);
 freopen ("output.txt", "w", stdout);
 cin >> n;
 for (int i = 0; i < n; i++)
  cin >> C[i];

 for (int last = -1; last < n; last++)
 {
  int k = max_element (&C[last + 1], &C[n]) - C;

  ans += C[k] * (k - last);

  last = k - 1;
 }
 cout << ans;
 return 0;
}
