#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
freopen("turtle.in","r",stdin);
freopen("turtle.out","w",stdout);

 int n,m,q=0,u=0,i,j;
 long long a[1011][1011];
 long long b[1011][1011];
 
 cin>>n>>m;
 
 for(int i=0;i<n;i++){
 for(int j=0;j<m;j++){
 cin>>a[i][j];
 }
 }
 b[0][0]=a[0][0];
 for(int i=1;i<n;i++)
 b[i][0]=b[i-1][0]+a[i][0];
 
 for(int j=1;j<m;j++){	 
 b[0][j]=b[0][j-1]+a[0][j];
 }
 for(i=1;i<n;i++){
 for(j=1;j<m;j++)
 {
 b[i][j]=min(b[i-1][j]+a[i][j],b[i][j-1]+a[i][j]);
 }
  
 }                               
 cout<<b[n-1][m-1];
 return 0;
}
