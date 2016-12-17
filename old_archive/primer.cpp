#include <iostream>
using namespace std;
int main()
{
int a[100],x=0,n,k,i,j;
cin>>n>>k;
a[1]=1;
for(i=2;i<=n;i++){x=0;
for(j=i-k;j<i;j++){if(j>0){x+=a[j];}a[i]=x;}}
cout<<a[n];
system("pause");
return 0;
}

