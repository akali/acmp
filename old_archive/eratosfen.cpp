#include <iostream>
#include <cstdio>

using namespace std;

int n;
bool prime[1000500];

int main() 
{
 cin >> n;
 for (int i = 2;i <= n;++i)
  prime[i] = true;
  for (int i = 2;i <= n;++i)
   if (prime[i])
    for (int j = i+i;j <= n;j += i)
     prime[j] = false;
 return 0;
}
