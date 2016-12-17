#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

long long n,i,a[111111],k,c=1,C=0;

int main()
{
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 
 cin>>n>>k;
 
 for(i = 1;i <= n;i++){a[i] = i;}
 
 if(n == k)
 {
  for(i = 2;i <= n;i++) c *= i;
  cout<<c; 
  return 0;
 }
 
 do{
  c = 0;
  for(i = 2;i <= n;i ++) if(abs(a[i] - a[i - 1]) <= k) c ++;
  if(c == (n - 1)) C ++;
 }while(next_permutation(a + 1,a + n + 1));
 
 cout<<C;
 return 0;
}
