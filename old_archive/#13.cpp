# include <iostream>
# include <string>
# include <cstdio>

using namespace std;

int main ()
{
 freopen ("input.txt",  "r",  stdin);
 freopen ("output.txt", "w", stdout);
 string a, b;
 static int q, k;
 cin >> a >> b;

 for (int i = 0; i < 4; i++)
  if (a[i] == b[i])
   q++;
 for (int i = 0; i < 4; i++)
 {
  if (a[i] != b[i])
  {
   for (int j = 0; j < 4; j++)
   {
    if (a[i] == b[j]) k++;
   }
  }
 }
 cout << q << " " << k;
 return 0;
}
