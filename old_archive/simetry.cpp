#include <iostream>
using namespace std;
int x1,x2,y1,y2,a,b;
int main ()
{
freopen ("input.txt","r",stdin);
freopen ("output.txt","w",stdout);
cin>>x1>>y1>>x2>>y2>>a>>b;

if(y1==y2) {
 if(b<=y2)
 {cout<<a<<" "<<y2+(y2-b);
  goto l;}
 if(b>=y2){
  cout<<a<<" "<<y2-(b-y2);
  goto l; }}

if(x1==x2) {
 if(a<=x2){
  cout<<x2+(x2-a)<<" "<<b;
  goto l; }
 if(a>=x2){
  cout<<x2-(a-x2)<<" "<<b;
  goto l; }}
l:
     
return 0;
}