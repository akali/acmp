#include <iostream>
using namespace std;
int main()
{
 int n,m;
 int x1,x2,x3,y1,y2,y3;
 cin>>n>>m;
 cin>>x1>>y1>>x2>>y2>>x3>>y3;
 n-=x1;
 n-=x2;
 n-=x3;
 m-=y1;
 m-=y2;
 m-=y3;
 if(x1==0 && y2==0) cout<<"YES";
 else
 cout<<"NO";
 return 0;

}