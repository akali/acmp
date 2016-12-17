#include <iostream>
using namespace std;
int main()
{
 //freopen("input.txt", "r", stdin);
 //freopen("output.txt","w",stdout);
 int n;
 int a[10000],x=3;
 cin>>n;
 a[2]=3;
 a[4]=11;
 for(int i=6;i<=n;i++)
 {
  if(n%2==1) a[i]=0;
  else
  a[i]=a[i-2]*4-a[i-4];
 }
 cout<<a[n];
 return 0;
}
