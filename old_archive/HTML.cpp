#include <iostream>
using namespace std;
int main()
{
 int i,n,m,k,j,g=0;
 int a[1005][1005];
 cin>>n>>m;
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=m;j++)
  {
   for(k=1;k<=n;k++)
   {
    	if(a[i-3][j-1]<=n && a[i-3][j-1]<=m && a[i-3][j-1]>0) g++;
    	else
	if(a[i-1][j-3]<=n && a[i-1][j-3]<=m && a[i-1][j-3]>0) g++;
	else                   
	if(a[i-3][j+1]<=n && a[i-3][j+1]<=m && a[i-3][j+1]>0) g++;
	else                              
	if(a[i-1][j+3]<=n && a[i-1][j+3]<=m && a[i-1][j+3]>0) g++;
	else            
	if(a[i-1][j-3]<=n && a[i-1][j+3]<=m && a[i-1][j-3]>0) g++;
	else
	if(a[i+1][j-3]<=n && a[i+1][j-3]<=m && a[i+1][j-3]>0) g++;
	else                   
	if(a[i+3][j-1]<=n && a[i+3][j-1]<=m && a[i+3][j-1]>0) g++; 
	else                   
	if(a[i+3][j+1]<=n && a[i+3][j+1]<=m && a[i+3][j+1]>0) g++; 
   }
  }
 }
cout<<g;
return 0;
}
