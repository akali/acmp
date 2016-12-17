#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 double x1,x2,y1,y2,d;
 cin>>x1>>y1>>x2>>y2;
 cout<<fixed<<setprecision(7); 
 d=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
 if(d>=0) cout<<sqrt(d);
 return 0;
}