#include <iostream>
using namespace std;
int main()
{
 int n,a[101][101];
 cin>>n;
 bool b=0;
 for(int i=1;i<=n;i++)
 {
  for(int j=1;j<=n;j++)
  {
   cin>>a[i][j];
  }
 }
 for(int i=1;i<=n;i++)
 if(a[i][i]==1)
 b=0;
 //cout<<"NO";
 else
 {
 for(int i=1;i<=n;i++)
 {
  for(int j=1;j<=n;j++)
  {
    if(a[j][i]==a[i][j]) b=1;    
  }
 }
 }
 if(b==1){cout<<"YES"; }//return 0;}
 else
 {
 cout<<"NO";
 //return 0;
 }
 
 return 0;
}