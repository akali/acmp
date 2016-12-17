#include <iostream>
using namespace std;
int main()
{
 freopen("ones.in","r",stdin);
 freopen("ones.out","w",stdout);
 int n,i,j,a[1005];
 cin>>n;
 a[1]=2;
 a[2]=4;
 a[3]=7;
 a[4]=13;
 for(i=5;i<=n;i++)
 {
  a[i]=a[i-3]+a[i-2]+a[i-1];
 }
 cout<<a[n];
 return 0;
}
