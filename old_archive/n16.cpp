#include <iostream>
#include <cmath>
using namespace std;
int main()
{
 int n,a[101],b[101];
 cin>>n;
 for(int i=1;i<=sqrt(n);i++)
 {
  if(i*i==n)
  a[i]=i;
  else
  if(n%i==0){a[i]=i;b[i]=n/i;}
 }
 for(int i=1;i<=sqrt(n);i++)
 {
  cout<<a[i]<<" ";//<<b[i]<<"\n";
 }
 return 0;
}