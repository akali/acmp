#include <iostream>
using namespace std;
int main()
{
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 int i,j,x,y,z,w,c=0;
 cin>>x>>y>>z>>w;
 for(int i=0;i<=w;i++)
 {
  for(int j=0;j<=w;j++)
  {
   if( ( w- (x*i + y*j) ) >= 0 && ( w- ( x*i + y*j ) ) % z == 0) c++;
  }
 }
cout<<c;
}