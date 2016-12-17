/*
|d|          |p|   |x|
 1   - 1/2  - 4  - |
                    4
 5   - 2/3  - 8  - |
                    6
 13  - 3/4  - 14 - |
                    7
 27  - 4/5  - 21 - |
                    9
 48  - 5/6  - 30 - |
                    10
 78  - 6/7  - 40 - |
                    12
 118 - 7/8  - 52 - |
                    13
 170 - 8/9  - 65 - |
                    15
 315 - 9/10 - 80 - |
*/
#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int n;
unsigned long long d[(int)(1e5) + 10], p[(int)(1e5) + 10], x[(int)(1e5) + 10];

int main()
{
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);

 scanf("%d", &n);
 
 d[1] = 1; p[1] = 4; x[1] = 4;
 d[2] = 5; p[2] = 8; x[2] = 6;
 
 for(int i = 3; i <= n; i++)
 {
  if(i & 1)
   x[i] = x[i - 1] + 1;
  else
   x[i] = x[i - 1] + 2;

  p[i] = p[i - 1] + x[i - 1];
  d[i] = d[i - 1] + p[i - 1];
 } 
 
 printf("%I64d", d[n]);
 return 0;
}

