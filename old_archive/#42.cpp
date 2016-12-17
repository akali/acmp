#include <iostream>
using namespace std;
long long n,c=1;
int main() 
{
 freopen ("input.txt","r",stdin);
 freopen ("output.txt","w",stdout);
 cin>>n;
 if(n==1){cout<<"1";return 0;}
 while(n>0)
 {
  if (n%3==0)
   c *= 3,n-=3;
  else 
   if(n%2==0)
    c *= 2,n-=2;
   else n-=3, c *= 3;
 }
 
 cout<<c;
 return 0;
}