#include <iostream>
using namespace std;
 int main()
{
 freopen( "input.txt",  "r" , stdin);
 freopen("output.txt",  "w" , stdout);
 long long n;
 cin>>n;
 long long a[12000];
 a[1]=1;
 a[2]=3;
 a[3]=5;
 for(int i=4;i<=1200000000;i++)
 {
  a[i]=a[i-1]+a[i-2];
 }
 for(int i=0;i<1200000000;i++)
 {
  if(a[i]==n) cout<<1<<"\n"<<a[i];
  else
  cout<<"0";
 }
 return 0;	
}
