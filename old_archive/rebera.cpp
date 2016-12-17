#include <iostream>
using namespace std;
int main()
{          
 int a[101][101],n,m=0,i;
 cin>>n;
 for(i=1;i<=n;i++)
 {
  for(int j=1;j<=n;j++)
  {
   cin>>a[i][j];
   if(a[i][j]==1) m++;
  }
 }
 cout<<m/2;
 return 0;
}