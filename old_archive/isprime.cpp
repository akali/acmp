#include <math.h>
#include <iostream>
using namespace std;
double r;
int e,a=0,l;
long long primenums[100001];
int isprime(double r)
{
 for(int i=2;i<=sqrt(r);i++)
{
 if(int(r)%i==0){ a=1; break;}
else a=0;
}
 if(a==1) return 0;
else
return 1;
}
int primarisation(double r)
{
 for(int i=2;i<=sqrt(r);i++)
 {
  if(int(r)%i==0){primenums[]=i;}}
}
int main(){
cin>>e;
primarisation(e+1000);
if(isprime(e)==1) cout<<e;
else
for(int i=e-1000;i<=e+1000;i++)
{
 
}
return 0;
}
