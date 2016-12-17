# include <iostream>
# include <string>
# include <cstdio>

using namespace std;

int a[10];

void count (int q)
{
 a[q / 10]++;
 a[q % 10]++;
}

int main ()
{
 freopen ("input.txt" , "r",  stdin);
 freopen ("output.txt", "w", stdout);
 int hh, mm, ss, hhh, mmm, sss;
 scanf ("%d:%d:%d", &hh, &mm, &ss);
 scanf ("%d:%d:%d", &hhh, &mmm, &sss);
 count (hh), count (mm), count (ss);
 while (hh != hhh || mm != mmm || ss != sss)
 {
  ss++;
  if (ss == 60)
  {
   ss = 0;
   mm++;
  }
  if (mm == 60)
  {
   mm = 0;
   hh++;
  }
  count (hh), count (mm), count (ss);
 }
 for (int i = 0; i < 10; i++) cout << a[i] << endl;
 return 0;
}
