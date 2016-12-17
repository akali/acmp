#include <iostream>
using namespace std;
int main()
{
 freopen("input.txt", "r", stdin);
 freopen("output.txt","w",stdout);
 long long n,a[111];
 cin>>n;
 a[1]=1;
 a[2]=2;
 a[3]=4;
 a[4]=7;
 int x=4;
 for(int i=5;i<=n;i++)
 {
  a[i]=a[i-1]+a[i-2]+a[i-3]	;
 }
 cout<<a[n];
 return 0;
}
