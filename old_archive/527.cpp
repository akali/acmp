#include <iostream>
using namespace std;
int a[1001][1001],n,i,j,m=0,b[1001][1001];
int main()
{
 cin>>n;
for(i=0;i<=n;i++)
{
for(j=0;j<=n;j++)
{
a[i][0]=-1001;
a[0][j]=-1001;
}
}
 for(i=1;i<=n;i++)
 {
     for(j=1;j<=n;j++)
 {
     cin>>a[i][j];
 }
 }
 //--------------------------
for(i=n;i>1;i--)
{
for(j=n;j>1;j--)
{
if(i==n && j==n) continue;
else
a[i][j]+=max(a[i-1][j],a[i][j-1]);
}
}
 for(i=1;i<=n;i++)
 {
     for(j=1;j<=n;j++)
 {
     cout<<a[i][j]<<" ";
 }
 cout<<endl;
 }
 cout<<endl<<a[n][n];
return 0;
}

