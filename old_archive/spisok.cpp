#include <iostream>
using namespace std;
int main()
{          
 int a[101][101],n,i,j;
 cin>>n;
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   cin>>a[i][j];
  }
 }
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   if(a[i][j]==1) a[j][i]=0;
  }
 }
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   if(a[i][j]==1) cout<<i<<" "<<j<<endl;
  }              
 }
 return 0;
}