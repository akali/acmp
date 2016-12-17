#include <iostream>
using namespace std;
int main()
{
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 int a,b,c,d,x,counter=0;
 cin>>x;
 for(a=1;a<=x;a++){
 for(b=a;b<=x-a;b++){
 for(c=b;c<=x-b;c++){
 if(x-a-b-c>=c)
 counter++;
}}}
 cout<<counter;
 return 0;
}
