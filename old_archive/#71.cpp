#include <iostream>
#include <cmath>
using namespace std;
main()
{
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 int n,a[20],i,b[20]={0},s=0,p=0,j,kol=0,sum=0,mini=999999;
 cin>>n;
 for(i=1;i<=n;i++){cin>>a[i];b[i]=0;}
 p=0; 
 while(true)
 {
  s=0;sum=0;kol=0; 
  for(i=1;i<=n;i++)
  {
   if(b[i]) p++;
  
   if(!b[i] && p)
   {
    for(j=i-1;j>=i-p;j--) b[j]=0; p=0;

    b[i]=1;
    goto l;
   }
  }
l:;
 for(i=1;i<=n;i++)
 {
  if(b[i]==0) sum+=a[i];
  if(b[i]==1) kol+=a[i],s++;
 }
  if(mini>abs(sum-kol))mini=abs(sum-kol);
  if(s==n){cout<<mini;return 0;}
 }
}